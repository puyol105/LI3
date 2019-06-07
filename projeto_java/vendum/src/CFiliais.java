import org.omg.CORBA.MARSHAL;

import java.util.*;

public class CFiliais implements java.io.Serializable{
    private List<List<Map<String,ProdsCliente>>> cfiliais;
    private  int nrclientes;
    private int nrvendas;

    /**
     * Construtor vazio.
     */
    public CFiliais(){
        this.nrclientes = 0;
        this.nrvendas = 0;
        this.cfiliais = new ArrayList<>(Globais.NRMESES);
        List<Map<String,ProdsCliente>> l;
        Map<String,ProdsCliente> h;

        for(int i = 0; i < Globais.NRMESES; i++) {
            l = new ArrayList<>(Globais.NRFILIAIS);
            this.cfiliais.add(i, l);
            for(int j = 0; j < Globais.NRFILIAIS; j++){
                h = new HashMap<>();
                this.cfiliais.get(i).add(j, h);
            }
        }
    }

    /**
     * Método que, dado uma venda, insere essa mesma venda na classe CFiliais.
     * @param venda
    */
    public void insereEmCFiliais(Venda venda){
        Map<String,ProdsCliente> m = this.cfiliais.get(venda.getMes()-1).get(venda.getFilial()-1);
        ProdsCliente pc = m.get(venda.getCliente());

        this.nrvendas++;

        /* isto gasta tempo e não está a ser necessário (guarda o número de clientes em cfiliais)
        if(!existe_cliente_cfiliais(venda))
            this.nrclientes++;*/

        if(pc != null){
            pc.insere_em_prodscliente(venda);
        }
        else{
            ProdsCliente prodscliente = new ProdsCliente();
            prodscliente.insere_em_prodscliente(venda);
            m.put(venda.getCliente(), prodscliente);
        }
    }

    /**
     * Método que, dado um objecto que é um cliente, verifica a sua exitência na classe CFiliais.
     * @return true or false
     * @param object
    */
    public boolean existe_cliente_cfiliais(Object object){
        Map<String,ProdsCliente> m;
        ProdsCliente pc;
        String string = null;

        if(object instanceof String)
            string = (String) object;
        else if(object instanceof Venda)
            string = (String) ((Venda) object).getCliente();

        for(int i = 0; i < Globais.NRMESES; i++)
            for(int j = 0; j < Globais.NRFILIAIS; j++) {
                m = this.cfiliais.get(i).get(j);
                pc = m.get(string);
                if(pc != null)
                    return true;
            }

        return false;
    }

    /**
     * Método que, dado um cliente, um mês e uma filial, retorna o número total de compras.
     * @return
     * @param cliente
     * @param mes
     * @param filial
    */
    public int compras_mes_filial_cliente_cfiliais(String cliente, int mes, int filial){
        ProdsCliente pc = this.cfiliais.get(mes).get(filial).get(cliente);

        if(pc != null)
            return pc.vprodutos_size_prodscliente();
        else
            return 0;
    }

    /**
     * Método que, dado um cliente, um mes e uma filial, devolve o número de produtos COMPRADOS??? 
     * @return
     * @param cliente
     * @param mes
     * @param filial
    */
    public int nrprodutos_mes_filial_cliente_cfiliais(String cliente, int mes, int filial){
        ProdsCliente pc = this.cfiliais.get(mes).get(filial).get(cliente);

        if(pc != null)
            return pc.prodscliente_size();
        else
            return 0;
    }

    /**
     * Método que, dado um cliente e um mês, devolve o número de produtos comprados para cada filial.
     * @return
    */
    public int nrprodutos_mes_cliente_cfiliais(String cliente, int mes){
        Set<String> produtos = new HashSet<>();
        ProdsCliente pc = null;

        for(int i = 0; i < Globais.NRFILIAIS; i++)
            if((pc = this.cfiliais.get(mes).get(i).get(cliente)) != null)
                pc.produtos_prodscliente(produtos);

        return produtos.size();
    }

    /**
     * Método que, dado um mês, apresenta o total de vendas nesse mês em todas as filiais.
     * @param mes
     * @return
     */
    public int total_vendas_mes_cfiliais(int mes){
        Map<String,ProdsCliente> m = null;
        int total = 0;
        for(int i = 0; i < Globais.NRFILIAIS; i++){
            m = this.cfiliais.get(mes).get(i);
            if(m != null)
                for(ProdsCliente value : m.values()){
                    total += value.vprodutos_size_prodscliente();
                }
        }

        return total;
    }

    /**
     * Método que, dado uma filial, determina o total de vendas nessa filial.
     * @param filial
     * @return
     */
    public int total_vendas_filial_cfiliais(int filial){
        Map<String,ProdsCliente> m = null;
        int total = 0;
        for(int i = 0; i < Globais.NRMESES; i++){
            m = this.cfiliais.get(i).get(filial);
            if(m != null)
                for(ProdsCliente value : m.values()){
                    total += value.vprodutos_size_prodscliente();
                }
        }

        return total;
    }

    /**
     * Método que, dado um mês, calcula o número de clientes que fizeram compras nesse mês.
     * @param mes
     * @return
     */
    public int nrclientes_mes_cfiliais(int mes) {
        Map<String, ProdsCliente> m = null;
        Set<String> set = new HashSet<>();

        for (int i = 0; i < Globais.NRFILIAIS; i++){
            m = this.cfiliais.get(mes).get(i);
            if(m != null)
                set.addAll(m.keySet());
        }

        return set.size();
    }

    /**
     * Método que, dado uma filial, calcula o número de clientes que fizeram compras nessa filal.
     * @param filial
     * @return
     */
    public int nrclientes_filial_cfiliais(int filial) {
        Map<String, ProdsCliente> m = null;
        Set<String> set = new HashSet<>();

        for (int i = 0; i < Globais.NRMESES; i++){
            m = this.cfiliais.get(i).get(filial);
            if(m != null)
                set.addAll(m.keySet());
        }

        return set.size();
    }

    /**
     * Método que determina o total faturado na classe CFiliais.
     * @return
     */
    public double total_faturado_cfiliais(){
        double total = 0.0;
        Map<String,ProdsCliente> m;

        for(int i = 0; i < Globais.NRMESES; i++)
            for(int j = 0; j < Globais.NRFILIAIS; j++) {
                m = this.cfiliais.get(i).get(j);
                for (ProdsCliente pc : m.values()) {
                    total += pc.total_faturado_prodscliente();
                }
            }

        return total;
    }

    /**
     * Método que, dado um cliente, mês e filial, 
     * @param cliente
     * @param mes
     * @param filial
     * @return
     */
    public double fatprod_mes_filial_cliente_cfiliais(String cliente, int mes, int filial){
        ProdsCliente pc = this.cfiliais.get(mes).get(filial).get(cliente);

        if(pc != null)
            return pc.fatprod_cliente_prodscliente();
        else
            return 0;
    }

    /**
     * Método que, dado um produto e um array, preenche uma matriz 
     * @param produto
     * @param array
     */
    public void quantidade_nrclientes_totfaturado_produto_cfiliais(String produto, double[][] array){
        Map<String,ProdsCliente> m = null;
        Set<String> s = null;
        VProdutos vprodutos = null;

        for(int i = 0; i < array.length; i++){
            s = new HashSet<>();

            for(int k = 0; k < Globais.NRFILIAIS; k++){
                m = this.cfiliais.get(i).get(k);
                for(Map.Entry<String,ProdsCliente> entry: m.entrySet()){
                    if(null != (vprodutos = entry.getValue().busca_produto_vprodutos(produto))){
                        array[i][0] += vprodutos.get_total_quantidade();
                        s.add(entry.getKey());
                        array[i][2] += vprodutos.total_faturado_vprodutos();
                    }
                }
            }

            array[i][1] = s.size();
        }
    }

    /**
     * Método que cria um Map onde se vai colocar por ordem decrescente os produtos mais comprados por um determinado cliente. 
     * @param cliente
     * @return
     */
    public MaxHeapInt produtos_mais_comprados_cliente(String cliente){
        Map<String,Integer> produtos_quantidades = new HashMap<>();
        MaxHeapInt heap = new MaxHeapInt();
        ProdsCliente pc = null;

        for(int i = 0; i < this.cfiliais.size(); i++){
            for(int j = 0; j < this.cfiliais.get(i).size(); j++){
                pc = this.cfiliais.get(i).get(j).get(cliente);
                if(pc != null){
                    pc.preenche_produtos_quantidades(produtos_quantidades);

                }
            }
        }

        return heap.to_maxheap(produtos_quantidades);
    }

    /**
     * Método que cria um Map onde se vai colocar por ondem decrescente os clientes mais compradores de um determinado produto.
     * @param produto
     * @return
     */
    public MaxHeapInt clientes_mais_compradores_produto(String produto){
        Map<String,InfoCliente> map = new HashMap<>();
        MaxHeapInt heap = new MaxHeapInt();
        ProdsCliente pc = null;
        VProdutos vp = null;
        InfoCliente ic = null;
        String auxiliar = null;

        for(int i = 0; i < this.cfiliais.size(); i++){
            for(int j = 0; j < this.cfiliais.get(i).size(); j++){
                for(Map.Entry<String,ProdsCliente> entry: this.cfiliais.get(i).get(j).entrySet()){
                    vp = entry.getValue().busca_produto_vprodutos(produto);
                    if(vp != null){
                        ic = map.get(entry.getKey());
                        if(ic != null){
                            ic.setQuantidade(ic.getQuantidade() + vp.get_total_quantidade());
                            ic.setPreco(ic.getPreco() + vp.total_faturado_vprodutos());
                        }
                        else{
                            ic = new InfoCliente(vp.get_total_quantidade(), vp.total_faturado_vprodutos());
                            map.put(entry.getKey(), ic);
                        }
                    }
                }

            }
        }


        for(Map.Entry<String,InfoCliente> entry: map.entrySet()){
            auxiliar = "Cliente: " + entry.getKey() + "   Gastos: " + entry.getValue().getPreco() + "   Quantidade: " + entry.getValue().getQuantidade();
            heap.put_add_maxheap(entry.getValue().getQuantidade(), auxiliar);
        }

        return heap;
    }

    /**
     * Método que cria um Map onde se vai colocar por ondem decrescente os clientes que mais compraram produtos diferentes. 
     * @return
     */
    public MaxHeapInt clientes_mais_variadores(){
        MaxHeapInt heap = new MaxHeapInt();
        Map<String,Set<String>> produtos_cliente = new HashMap<>();
        Map<String,Integer> nr_produtos_cliente = new HashMap<>();
        Set<String> s = null;

        for(int i = 0; i < this.cfiliais.size(); i++){
            for (int j = 0; j < this.cfiliais.get(i).size(); j++){
                for(Map.Entry<String,ProdsCliente> entry: this.cfiliais.get(i).get(j).entrySet()){
                    s = produtos_cliente.get(entry.getKey());
                    if(s != null){
                        s.addAll(entry.getValue().getProdsclienteKeyset());
                    }
                    else{
                        s = new TreeSet<>();
                        s.addAll(entry.getValue().getProdsclienteKeyset());
                        produtos_cliente.put(entry.getKey(), s);
                    }
                }
            }
        }

        for(Map.Entry<String,Set<String>> entry: produtos_cliente.entrySet())
            nr_produtos_cliente.put(entry.getKey(), entry.getValue().size());

        heap.to_maxheap(nr_produtos_cliente);

        return heap;
    }

    /**
     * Método que cria um Map onde se vai colocar, por ordem decrescente, os clientes que mais gastaram numa determinada filial.
     * @param f
     * @return
     */
    public MaxHeapDouble clientes_mais_compradores_filial(int f){
        f--;
        MaxHeapDouble heap = new MaxHeapDouble();
        Map<String,Double> gastos_cliente = new HashMap<>();


        for(int i = 0; i < this.cfiliais.size(); i++){
            for(Map.Entry<String,ProdsCliente> entry: cfiliais.get(i).get(f).entrySet()){
                if(gastos_cliente.containsKey(entry.getKey())){
                    gastos_cliente.put(entry.getKey(), gastos_cliente.get(entry.getKey()) + entry.getValue().total_faturado_prodscliente());
                }
                else{
                    gastos_cliente.put(entry.getKey(), entry.getValue().total_faturado_prodscliente());
                }
            }
        }

        return heap.to_maxheap(gastos_cliente);
    }

    /**
     * Método que cria um Map onde se vai colocar, por ordem decrescente, os produtos mais vendidos.
     * @return
     */
    public MaxHeapInt produtos_mais_vendidos(){
        MaxHeapInt heap = new MaxHeapInt();
        Map<String,ClisProd> prods_mais_vendidos = new HashMap<>();
        Map<String,Integer> pdv = new HashMap<>();
        String auxiliar = null;

        for(int i = 0; i < this.cfiliais.size(); i++){
            for(int j = 0; j < this.cfiliais.get(i).size(); j++){
                for(Map.Entry<String,ProdsCliente> entry: this.cfiliais.get(i).get(j).entrySet()){
                    entry.getValue().preenche_produtos_mais_vendidos(prods_mais_vendidos, entry.getKey());
                }
            }
        }

        for(Map.Entry<String,ClisProd> entry: prods_mais_vendidos.entrySet()){
            auxiliar = "Produto: " + entry.getKey() + "   Nº clientes: " + entry.getValue().getClientes().size() + "   Quantidade: " + entry.getValue().getQtd();
            heap.put_add_maxheap(entry.getValue().getQtd(), auxiliar);
        }

        return heap;
    }

    /**
     * 
     * @param array
     */
    public void nr_clientes_distintos_mes_filial(int[][] array){
        for(int i = 0; i < this.cfiliais.size(); i++){
            for(int j = 0; j < this.cfiliais.get(i).size(); j++){
                array[i][j] = this.cfiliais.get(i).get(j).size();
            }
        }
    }

    /**
     * Método que devolve o número de clientes.
     * @return
     */
    public int getNrclientes() {
        return nrclientes;
    }

    /**
     * Método que define o número de clientes.
     * @param nrclientes
     */
    public void setNrclientes(int nrclientes) {
        this.nrclientes = nrclientes;
    }

    /**
     * Método que devolve o número de vendas.
     * @return
     */
    public int getNrvendas() {
        return nrvendas;
    }

    /**
     * Método que define o número de vendas.
     * @param nrvendas
     */
    public void setNrvendas(int nrvendas) {
        this.nrvendas = nrvendas;
    }
}

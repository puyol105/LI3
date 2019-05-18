import java.util.*;

public class CFiliais {
    private List<List<Map<String,ProdsCliente>>> cfiliais;
    private  int nrclientes;
    private int nrvendas;

    public CFiliais(){
        this.nrclientes = 0;
        this.nrvendas = 0;
        this.cfiliais = new ArrayList<>(Globais.NRMESES);
        List<Map<String,ProdsCliente>> l;
        HashMap<String,ProdsCliente> h;

        for(int i = 0; i < Globais.NRMESES; i++) {
            l = new ArrayList<>(Globais.NRFILIAIS);
            this.cfiliais.add(i, l);
            for(int j = 0; j < Globais.NRFILIAIS; j++){
                h = new HashMap<>();
                this.cfiliais.get(i).add(j, h);
            }
        }
    }

    public void insereEmCFiliais(Venda venda){
        Map<String,ProdsCliente> m = this.cfiliais.get(venda.getMes()-1).get(venda.getFilial()-1);
        ProdsCliente pc = m.get(venda.getCliente());

        this.nrvendas++;

        if(!existe_cliente_cfiliais(venda))
            this.nrclientes++;

        if(pc != null){
            pc.insere_em_prodscliente(venda);
        }
        else{
            ProdsCliente prodscliente = new ProdsCliente();
            prodscliente.insere_em_prodscliente(venda);
            m.put(venda.getCliente(), prodscliente);
        }
    }

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

    public int compras_mes_filial_cliente_cfiliais(String cliente, int mes, int filial){
        ProdsCliente pc = this.cfiliais.get(mes).get(filial).get(cliente);

        if(pc != null)
            return pc.vprodutos_size_prodscliente();
        else
            return 0;
    }

    public int nrprodutos_mes_filial_cliente_cfiliais(String cliente, int mes, int filial){
        ProdsCliente pc = this.cfiliais.get(mes).get(filial).get(cliente);

        if(pc != null)
            return pc.prodscliente_size();
        else
            return 0;
    }

    public int nrprodutos_mes_cliente_cfiliais(String cliente, int mes){
        Set<String> produtos = new HashSet<>();
        ProdsCliente pc = null;

        for(int i = 0; i < Globais.NRFILIAIS; i++)
            if((pc = this.cfiliais.get(mes).get(i).get(cliente)) != null)
                pc.produtos_prodscliente(produtos);

        return produtos.size();
    }

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

    public double fatprod_mes_filial_cliente_cfiliais(String cliente, int mes, int filial){
        ProdsCliente pc = this.cfiliais.get(mes).get(filial).get(cliente);

        if(pc != null)
            return pc.fatprod_cliente_prodscliente();
        else
            return 0;
    }

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

    public int getNrclientes() {
        return nrclientes;
    }

    public void setNrclientes(int nrclientes) {
        this.nrclientes = nrclientes;
    }

    public int getNrvendas() {
        return nrvendas;
    }

    public void setNrvendas(int nrvendas) {
        this.nrvendas = nrvendas;
    }
}

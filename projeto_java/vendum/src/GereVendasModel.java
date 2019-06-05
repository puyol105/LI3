import java.util.ArrayList;
import java.util.List;
import java.util.Set;

public class GereVendasModel implements java.io.Serializable{

    private CProdutos cprodutos;
    private CClientes cclientes;
    private CFiliais cfiliais;
    private CFaturacao cfaturacao;
    private int nrvendasErradas;

    public GereVendasModel(){
        this.cprodutos = new CProdutos();
        this.cclientes = new CClientes();
        this.cfiliais = new CFiliais();
        this.cfaturacao = new CFaturacao();
        this.nrvendasErradas = 0;
    }

    public boolean carregaCClientes(String caminho){
        int i = 0;

        Leitor leitor = new Leitor();
        List<String> linhas = leitor.leFicheiro(caminho);

        while(i != linhas.size())
            if(valida_cliente(linhas.get(i)))
                cclientes.registaCliente(linhas.get(i++));

        //cclientes.imprimeClientes();
        System.out.println("Nº de clientes catalogados: " + cclientes.getNrclientes());

        return true;
    }

    public boolean carregaCProdutos(String caminho){
        int i = 0;

        Leitor leitor = new Leitor();
        List<String> linhas = leitor.leFicheiro(caminho);

        while(i != linhas.size())
            if(valida_produto(linhas.get(i)))
                this.cprodutos.registaProduto(linhas.get(i++));

        //cprodutos.imprimeProdutos();
        System.out.println("Nº de produtos catalogados: " + cprodutos.getNrprodutos());

        return true;
    }

    public boolean carregaCFiliaisCFaturacao(String caminho){
        int i = 0;
        Venda venda = null;

        Leitor leitor = new Leitor();
        List<String> linhas = leitor.leFicheiro(caminho);

        for(i = 0; i < linhas.size(); i++){
            if (null != (venda = venda_valida(cclientes, cprodutos, linhas.get(i)))) {

                this.cfaturacao.insereEmCFaturacao(venda);
                this.cfiliais.insereEmCFiliais(venda);
            }
            else{
                this.nrvendasErradas++;
            }
        }

        System.out.println("Nº de vendas inseridas: " + cfaturacao.getNrvendas());

        return true;
    }

    public MaxHeapInt clientes_mais_variadores(){
        return this.cfiliais.clientes_mais_variadores();
    }

    public MaxHeapDouble clientes_mais_compradores_filial(int f){
        return this.cfiliais.clientes_mais_compradores_filial(f);
    }

    public MaxHeapInt produtos_mais_vendidos(){
        return this.cfiliais.produtos_mais_vendidos();
    }

    public Venda venda_valida(CClientes cclientes, CProdutos cprodutos, String linha){
        String[] campos = linha.split(" ");


        if(campos.length != Globais.NRCAMPOS)
            return null;

        if(!valida_produto_venda(campos[0], cprodutos))
            return null;

        if(!valida_preco_venda(campos[1]))
            return null;

        if(!valida_quantidade_venda(campos[2]))
            return null;

        if(!valida_promo_venda(campos[3]))
            return null;

        if(!valida_cliente_venda(campos[4], cclientes))
            return null;

        if(!valida_mes_venda(campos[5]))
            return null;

        if(!valida_filial_venda(campos[6]))
            return null;

        Venda venda = new Venda(campos[0], Double.parseDouble(campos[1]), Integer.parseInt(campos[2]), campos[3].charAt(0), campos[4], Integer.parseInt(campos[5]), Integer.parseInt(campos[6]));

        return venda;
    }

    public boolean valida_filial_venda(String string){
        int i;
        for(i = 0; i < string.length(); i++)
            if(!Character.isDigit(string.charAt(i)))
                return false;
        if (Integer.parseInt(string) < 1 || Integer.parseInt(string) > 3)
            return false;
        return true;
    }

    public boolean valida_mes_venda(String string){
        int i;
        for(i = 0; i < string.length(); i++)
            if(!Character.isDigit(string.charAt(i)))
                return false;
        if (Integer.parseInt(string) < 1 || Integer.parseInt(string) > 12)
            return false;
        return true;
    }

    private boolean valida_cliente_venda(String string, CClientes clientes){
        if(!valida_cliente(string))
            return false;
        if(!clientes.existe_cliente(string))
            return false;
        return true;
    }

    private boolean valida_cliente(String codigo){
        if(!Character.isUpperCase(codigo.charAt(0)))
            return false;
        if(codigo.length() != 5)
            return false;
        if(Integer.parseInt(codigo.substring(1)) < 1000 || Integer.parseInt(codigo.substring(1)) > 5000)
            return false;
        return true;
    }

    private boolean valida_promo_venda(String string){
        if(string.equals("N") || string.equals("P"))
            return true;
        return false;
    }

    private boolean valida_quantidade_venda(String string){
        int i;
        for(i = 0; i < string.length(); i++)
            if(!Character.isDigit(string.charAt(i)))
                return false;
        if(Integer.parseInt(string) < 1 || Integer.parseInt(string) > 200)
            return false;
        return true;
    }

    private boolean valida_preco_venda(String string){
        int i;
        for(i = 0; i < string.length() && string.charAt(i)!='.'; i++)
            if(!Character.isDigit(string.charAt(i)))
                return false;
        for(i=i+1; i < string.length(); i++)
            if(!Character.isDigit(string.charAt(i)))
                return false;
        if(Double.parseDouble(string) > 9999.99 || Double.parseDouble(string) < 0 )
            return false;
        return true;
    }

    private boolean valida_produto_venda(String produto, CProdutos cprodutos){
        if(!valida_produto(produto))
            return false;
        if(!cprodutos.existe_produto(produto))
            return false;
        return true;
    }

    private boolean valida_produto(String codigo){
        if(!Character.isUpperCase(codigo.charAt(0)) || !Character.isUpperCase(codigo.charAt(1)))
            return false;
        if(codigo.length() != 6)
            return false;
        if(Integer.parseInt(codigo.substring(2)) < 1000 || Integer.parseInt(codigo.substring(2)) > 9999)
            return false;
        return true;
    }

    public void prods_nao_comprados(LStrings lStrings){
        cprodutos.prods_nao_comprados(lStrings, this.cfaturacao);
    }

    public boolean existe_produto_model_cfaturacao(String string){
        return this.cfaturacao.existe_produto_cfaturacao(string);
    }

    public boolean existe_cliente_model_cfiliais(String string){
        return this.cfiliais.existe_cliente_cfiliais(string);
    }

    public boolean tudo_carregado(){
        return (cprodutos.getNrprodutos() > 0 &&
                cclientes.getNrclientes() > 0 &&
                cfiliais.getNrvendas() > 0 &&
                cfaturacao.getNrvendas() > 0);
    }

    public double[][] faturacao_meses_filiais_model(String string){
        return this.cfaturacao.faturacao_meses_filiais(string);
    }

    public int compras_mes_filial_cliente_model(String cliente, int mes, int filial){
        return this.cfiliais.compras_mes_filial_cliente_cfiliais(cliente, mes, filial);
    }

    public int nrprodutos_mes_filial_cliente_model(String cliente, int mes, int filial){
        return this.cfiliais.nrprodutos_mes_filial_cliente_cfiliais(cliente, mes, filial);
    }

    public int nrprodutos_mes_cliente_model(String cliente, int mes){
        return this.cfiliais.nrprodutos_mes_cliente_cfiliais(cliente, mes);
    }

    public double fatprod_mes_filial_cliente_model(String cliente, int mes, int filial){
        return this.cfiliais.fatprod_mes_filial_cliente_cfiliais(cliente, mes, filial);
    }

    public double getFaturacaoTotal(){
        return this.cfaturacao.total_faturado_cfaturacao();
    }

    public int getVendasValorZero(){
        return this.cfaturacao.getVendasValorZero();
    }

    public int total_vendas_mes_model(int mes){
        return this.cfiliais.total_vendas_mes_cfiliais(mes);
    }

    public int total_vendas_filial_model(int filial){
        return this.cfiliais.total_vendas_filial_cfiliais(filial);
    }

    public int nrclientes_mes_model(int mes){
        return this.cfiliais.nrclientes_mes_cfiliais(mes);
    }

    public int nrclientes_filial_model(int filial){
        return this.cfiliais.nrclientes_filial_cfiliais(filial);
    }

    public int getNrclientesCompradores(){
        int nr = 0;
        List<Set<String>> clientes = this.cclientes.shallowCloneClientes();

        for(int i = 0; i < clientes.size(); i++)
            for(String s: clientes.get(i))
                if(this.cfiliais.existe_cliente_cfiliais(s))
                    nr++;

        return nr;
    }

    public int getNrprodutosComprados(){
        int nr = 0;
        List<List<Set<String>>> produtos = this.cprodutos.shallowCloneProdutos();

        for(int i = 0; i < produtos.size(); i++)
            for(int j = 0; j < produtos.get(i).size(); j++)
                for(String s: produtos.get(i).get(j))
                    if(this.cfaturacao.existe_produto_cfaturacao(s))
                        nr++;

        return nr;
    }

    public void quantidade_nrclientes_totfaturado_produto_model(String produto, double[][] array){
        this.cfiliais.quantidade_nrclientes_totfaturado_produto_cfiliais(produto, array);
    }

    public CFiliais getCFiliais(){
        return this.cfiliais;
    }

    public int getNrclientes(){
        return this.cclientes.getNrclientes();
    }

    public int getNrprodutos(){
        return this.cprodutos.getNrprodutos();
    }

    public int getNrvendas(){
        return this.cfaturacao.getNrvendas();
    }

    public int getNrvendasErradas(){
        return this.nrvendasErradas;
    }

    public void nr_compras_mes(int[] nrcomprasmes){
        this.cfaturacao.nr_compras_mes(nrcomprasmes);
    }

    public void fat_mes_filial(double[][] array){
        this.cfaturacao.fat_mes_filial(array);
    }

    public void nr_clientes_distintos_mes_filial(int[][] array){
        this.cfiliais.nr_clientes_distintos_mes_filial(array);
    }
}

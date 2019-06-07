import java.io.Serializable;

public class Venda implements Serializable{
    private String produto;
    private double preco;
    private int quantidade;
    private char promo;
    private String cliente;
    private int mes;
    private int filial;

    /**
     * Construtor vazio.
     */
    public Venda(){
        this.produto = null;
        this.preco = 0;
        this.quantidade = 0;
        this.promo = '0';
        this.cliente = null;
        this.mes = 0;
        this.filial = 0;
    }

    /**
     * Construtor parametrizado.
     * @param produto
     * @param preco
     * @param quantidade
     * @param promo
     * @param cliente
     * @param mes
     * @param filial
     */
    public Venda(String produto, double preco, int quantidade, char promo, String cliente, int mes, int filial) {
        this.produto = produto;
        this.preco = preco;
        this.quantidade = quantidade;
        this.promo = promo;
        this.cliente = cliente;
        this.mes = mes;
        this.filial = filial;
    }

    public String getProduto() {
        return produto;
    }

    public void setProduto(String produto) {
        this.produto = produto;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public char getPromo() {
        return promo;
    }

    public void setPromo(char promo) {
        this.promo = promo;
    }

    public String getCliente() {
        return cliente;
    }

    public void setCliente(String cliente) {
        this.cliente = cliente;
    }

    public int getMes() {
        return mes;
    }

    public void setMes(int mes) {
        this.mes = mes;
    }

    public int getFilial() {
        return filial;
    }

    public void setFilial(int filial) {
        this.filial = filial;
    }

    public double getValor(){
        return preco*quantidade;
    }

    /**
     * Método que faz o parsing e que valida uma venda.
     * @param cclientes
     * @param cprodutos
     * @param linha
     * @return null se a venda em questão for inválida ou uma instância de venda se esta for válida.
     */
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
        if(!clientes.valida_cliente(string))
            return false;
        if(!clientes.existe_cliente(string))
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

    private boolean valida_produto_venda(String produto, CProdutos produtos){
        if(!produtos.valida_produto(produto))
            return false;
        if(!produtos.existe_produto(produto))
            return false;
        return true;
    }
}

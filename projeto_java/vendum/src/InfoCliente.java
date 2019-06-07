public class InfoCliente {

    private int quantidade;
    private double preco;

    /**
     * Construtor vazio.
     */
    public InfoCliente(){
        this.quantidade = 0;
        this.preco = 0.0;
    }

    /**
     * Construtor parametrizado.
     * @param quantidade
     * @param preco
     */
    public InfoCliente(int quantidade, double preco){
        this.quantidade = quantidade;
        this.preco = preco;
    }

    /**
     * Método que devolve a quantidade
     * @return
     */
    public int getQuantidade() {
        return quantidade;
    }

    /**
     * Método que define a quantidade
     * @param quantidade
     */
    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    /**
     * Método que devolve o
     * @return
     */
    public double getPreco() {
        return preco;
    }

    /**
     * Método que define 
     * @param preco
     */
    public void setPreco(double preco) {
        this.preco = preco;
    }

    /**
     * Método que calcula 
     * @return
     */
    public double total_infocliente(){
        return ((double) this.quantidade*this.preco);
    }
}

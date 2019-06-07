import javax.sound.sampled.Line;

public class InfoVenda implements java.io.Serializable{

    private int quantidade;
    private double preco;

    /**
     * Construtor vazio.
     */
    public InfoVenda(){
        this.quantidade = 0;
        this.preco = 0.0;
    }

    /**
     * Construtor parametrizado.
     * @param quantidade
     * @param preco
     */
    public InfoVenda(int quantidade, double preco){
        this.quantidade = quantidade;
        this.preco = preco;
    }

    /**
     * Método que devolve a quantidade de uma venda.
     * @return Quantidade de uma venda.
     */
    public int getQuantidade() {
        return quantidade;
    }

    /**
     * Método que define a quantidade de uma venda.
     * @param quantidade
     */
    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    /**
     * Método que devolve o preço de uma venda.
     * @return Preço de uma venda.
     */
    public double getPreco() {
        return preco;
    }

    /**
     * Método que define o preço de uma venda.
     * @param preco
     */
    public void setPreco(double preco) {
        this.preco = preco;
    }

    /**
     * Método que calcula o total faturado multiplicando o preço pela quantidade.
     * @return Total faturado.
     */
    public double total_infovenda(){
        return ((double) this.quantidade*this.preco);
    }
}

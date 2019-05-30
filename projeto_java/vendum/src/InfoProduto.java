import javax.sound.sampled.Line;

public class InfoProduto implements java.io.Serializable{

    private int quantidade;
    private double preco;

    public InfoProduto(){
        this.quantidade = 0;
        this.preco = 0.0;
    }

    public InfoProduto(int quantidade, double preco){
        this.quantidade = quantidade;
        this.preco = preco;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public double total_infoproduto(){
        return ((double) this.quantidade*this.preco);
    }
}

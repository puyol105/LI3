import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class Venda implements IVenda, Serializable{
    private String produto;
    private double preco;
    private int quantidade;
    private char promo;
    private String cliente;
    private int mes;
    private int filial;

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

    //+equals toString, +clone, +hashcode*/
}

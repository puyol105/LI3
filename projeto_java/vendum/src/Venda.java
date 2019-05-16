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


    public Venda venda_valida(CClientes cclientes, CProdutos cprodutos, String linha){
        String[] campos = linha.split(" ");

        if(campos.length != Globais.NRCAMPOS)
            return null;

        if(true != valida_produto_venda(campos[0], cprodutos))
            return null;

        if(true != valida_preco_venda(campos[1]))
            return null;

        if(true != valida_quantidade_venda(campos[2]))
            return null;

        if(true != valida_promo_venda(campos[3]))
            return null;

        if(true != valida_cliente_venda(campos[4], cclientes))
            return null;

        if(true != valida_mes_venda(campos[5]))
            return null;

        if(true != valida_filial_venda(campos[6]))
            return null;

        return VENDINHA;
    }

    public boolean valida_filial_venda(String string){
        int i;
        for(i = 0; i < string.length(); i++)
            if(true != Character.isDigit(string.charAt(i)))
                return false;
        if (Integer.parseInt(string) < 1 || Integer.parseInt(string) > 3)
            return false;
        return true;
    }

    public boolean valida_mes_venda(String string){
        int i;
        for(i = 0; i < string.length(); i++)
            if(true != Character.isDigit(string.charAt(i)))
                return false;
        if (Integer.parseInt(string) < 1 || Integer.parseInt(string) > 12)
            return false;
        return true;
    }


    private boolean valida_cliente_venda(String string, CClientes clientes){
        if(valida_cliente(string) == false)
            return false;
        if(clientes.existe_cliente(string) == false)
            return false;
        return true;
    }

    private boolean valida_cliente(String codigo){
        if(Character.isUpperCase(codigo.charAt(0)) == false)
            return false;
        if(codigo.length() != 6)
            return false;
        if(Integer.parseInt(codigo.substring(1)) < 1000 || Integer.parseInt(codigo.substring(1)) > 5000)
            return false;
        return true;
    }

    private boolean valida_promo_venda(String string){
        if(string.equals("N") == true || string.equals("P") == true)
            return true;
        return false;
    }

    private boolean valida_quantidade_venda(String string){
        int i;
        for(i = 0; i < string.length(); i++)
            if(true != Character.isDigit(string.charAt(i)))
                return false;
        if(Integer.parseInt(string) < 1 || Integer.parseInt(string) > 200)
            return false;
        return true;
    }

    private boolean valida_preco_venda(String string){
        int i;
        for(i = 0; i < string.length() && string.charAt(i)!='.'; i++)
            if(true != Character.isDigit(string.charAt(i)))
                return false;
        for(i=i+1; i < string.length(); i++)
            if(true != Character.isDigit(string.charAt(i)))
                return false;
        if(Double.parseDouble(string) > 9999.99 || Double.parseDouble(string) < 0 )
            return false;
        return true;
    }

    private boolean valida_produto_venda(String produto, CProdutos cprodutos){
        if(valida_produto(produto) == false)
            return false;
        if(cprodutos.existe_produto(produto) == false)
            return false;
        return true;
    }

    private boolean valida_produto(String codigo){
        if(Character.isUpperCase(codigo.charAt(0)) == false || Character.isUpperCase(codigo.charAt(1)) == false)
            return false;
        if(codigo.length() != 6)
            return false;
        if(Integer.parseInt(codigo.substring(2)) < 1000 || Integer.parseInt(codigo.substring(2)) > 9999)
            return false;
        return true;
    }



    public double getValor(){
        return preco*quantidade;
    }

    //+equals toString, +clone, +hashcode*/
}

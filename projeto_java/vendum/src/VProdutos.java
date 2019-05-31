import java.util.ArrayList;
import java.util.List;

public class VProdutos implements java.io.Serializable{
    List<InfoVenda> vprodutos;

    public VProdutos(){
        vprodutos = new ArrayList<>();
    }

    public void insereEmVProdutos(int quantidade, double preco){
        InfoVenda infoVenda = new InfoVenda(quantidade, preco);
        this.vprodutos.add(infoVenda);
    }

    public double total_faturado_vprodutos(){
        double total = 0.0;

        for (InfoVenda ip : this.vprodutos)
            total += ip.total_infovenda();

        return total;
    }

    public int get_total_quantidade(){
        int total = 0;

        for(InfoVenda ip: this.vprodutos)
            total += ip.getQuantidade();

        return total;
    }

    public int getVendasValorZero(){
        int nr = 0;

        for(InfoVenda ip : this.vprodutos)
            if(ip.getPreco() == 0.0)
                nr++;

        return nr;
    }

    public int vprodutos_size(){
        return this.vprodutos.size();
    }
}

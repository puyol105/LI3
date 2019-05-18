import javax.sound.sampled.Line;
import java.util.ArrayList;
import java.util.List;

public class VProdutos {
    List<InfoProduto> vprodutos;

    public VProdutos(){
        vprodutos = new ArrayList<>();
    }

    public void insereEmVProdutos(int quantidade, double preco){
        InfoProduto infoProduto = new InfoProduto(quantidade, preco);
        this.vprodutos.add(infoProduto);
    }

    public double total_faturado_vprodutos(){
        double total = 0.0;

        for (InfoProduto ip : vprodutos)
            total += ip.total_infoproduto();

        return total;
    }

    public int get_total_quantidade(){
        int total = 0;

        for(InfoProduto ip: vprodutos)
            total += ip.getQuantidade();

        return total;
    }

    public int vprodutos_size(){
        return this.vprodutos.size();
    }
}
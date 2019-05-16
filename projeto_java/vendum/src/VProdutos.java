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
}

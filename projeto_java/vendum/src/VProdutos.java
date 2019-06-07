import java.util.ArrayList;
import java.util.List;

public class VProdutos implements java.io.Serializable{
    List<InfoVenda> vprodutos;

    /**
     * Construtor vazio.
     */
    public VProdutos(){
        vprodutos = new ArrayList<>();
    }

    /**
     * Insere no List vprodutos uma instância da classe InfoVenda.
     * @param quantidade
     * @param preco
     */
    public void insereEmVProdutos(int quantidade, double preco){
        InfoVenda infoVenda = new InfoVenda(quantidade, preco);
        this.vprodutos.add(infoVenda);
    }

    /**
     * Método que retorna o total faturado em relação às vendas presentes no map vprodutos.
     * @return Total faturado.
     */
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

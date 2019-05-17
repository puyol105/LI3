import java.util.HashMap;
import java.util.Map;

public class ProdsCliente {
    private Map<String,VProdutos> prodscliente;

    public ProdsCliente(){
        this.prodscliente = new HashMap<>();
    }

    public void insere_em_prodscliente(Venda venda){
        VProdutos vp = this.prodscliente.get(venda.getProduto());

        if(vp != null){
            vp.insereEmVProdutos(venda.getQuantidade(), venda.getPreco());
        }
        else{
            VProdutos vprodutos = new VProdutos();
            vprodutos.insereEmVProdutos(venda.getQuantidade(), venda.getPreco());
            this.prodscliente.put(venda.getProduto(), vprodutos);
        }
    }

    public double total_faturado_prodscliente(){
        double total = 0;

        for (VProdutos vp : this.prodscliente.values()) {
            total += vp.total_faturado_vprodutos();
        }

        return total;
    }
}

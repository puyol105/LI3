import java.util.HashMap;
import java.util.Map;
import java.util.Set;

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

    public int vprodutos_size_prodscliente(){
        int size = 0;

        for(VProdutos value : this.prodscliente.values()){
            size += value.vprodutos_size();
        }

        return size;
    }

    public double fatprod_cliente_prodscliente(){
        double res = 0;
        for(VProdutos vp: this.prodscliente.values())
            res += vp.total_faturado_vprodutos();
        return res;
    }

    public int prodscliente_size(){
        return this.prodscliente.size();
    }

    public void produtos_prodscliente(Set<String> set){
         Set<String> produtos = this.prodscliente.keySet();

         //set.addAll(produtos);

         for(String str : produtos)
             set.add(str);
    }

    public double total_faturado_prodscliente(){
        double total = 0;

        for (VProdutos vp : this.prodscliente.values()) {
            total += vp.total_faturado_vprodutos();
        }

        return total;
    }

    public VProdutos busca_produto_vprodutos(String produto){
        return this.prodscliente.get(produto);
    }
}

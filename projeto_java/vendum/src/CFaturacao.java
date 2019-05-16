import javax.xml.bind.annotation.XmlElementDecl;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class CFaturacao {

    private List<List<HashMap<String,VProdutos>>> cfaturacao;
    private int nrprodutos;

    public CFaturacao(){
        this.nrprodutos = 0;
        this.cfaturacao = new ArrayList<>(Globais.NRMESES);
        List<HashMap<String,VProdutos>> l;
        HashMap<String,VProdutos> h;

        for(int i = 0; i < Globais.NRMESES; i++){
            l = new ArrayList<>(Globais.NRFILIAIS);
            this.cfaturacao.add(i, l);
            for(int j = 0; j < Globais.NRFILIAIS; j++){
                h = new HashMap<>();
                this.cfaturacao.get(i).add(j, h);
            }

        }
    }

    public void insereEmCFaturacao(Venda venda){
        HashMap<String,VProdutos> m = this.cfaturacao.get(venda.getMes()-1).get(venda.getFilial()-1);
        VProdutos vp = m.get(venda.getProduto());



        if(vp != null){
            vp.insereEmVProdutos(venda.getQuantidade(), venda.getPreco());
        }
        else{
            VProdutos vprodutos = new VProdutos();
            vprodutos.insereEmVProdutos(venda.getQuantidade(), venda.getPreco());
            m.put(venda.getProduto(), vprodutos);
        }
    }


}



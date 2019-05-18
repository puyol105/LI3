import javax.xml.bind.annotation.XmlElementDecl;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class CFaturacao {

    private List<List<HashMap<String,VProdutos>>> cfaturacao;
    private int nrprodutos;
    private int nrvendas;

    public int getNrvendas() {
        return nrvendas;
    }

    public void setNrvendas(int nrvendas) {
        this.nrvendas = nrvendas;
    }

    public int getNrprodutos() {
        return nrprodutos;
    }

    public void setNrprodutos(int nrprodutos) {
        this.nrprodutos = nrprodutos;
    }

    public CFaturacao(){
        this.nrprodutos = 0;
        this.nrvendas = 0;
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
        Map<String,VProdutos> m = this.cfaturacao.get(venda.getMes()-1).get(venda.getFilial()-1);
        VProdutos vp = m.get(venda.getProduto());

        this.nrvendas++;

        /*há cenas que não são precisas, foram feitas inicialmente só para verificar se estava tudo bem, este é o caso, eliminar depois*/
        if(false == existe_produto_cfaturacao(venda))
            this.nrprodutos++;

        if(vp != null){
            vp.insereEmVProdutos(venda.getQuantidade(), venda.getPreco());
        }
        else{
            VProdutos vprodutos = new VProdutos();
            vprodutos.insereEmVProdutos(venda.getQuantidade(), venda.getPreco());
            m.put(venda.getProduto(), vprodutos);
        }

    }

    public boolean existe_produto_cfaturacao(Object object){
        String string = null;
        if(object instanceof String)
            string = (String) object;
        else if(object instanceof Venda)
            string = (String) ((Venda) object).getProduto();

        HashMap<String,VProdutos> m;
        VProdutos vp;

        for(int i = 0; i < Globais.NRMESES; i++)
            for(int j = 0; j < Globais.NRFILIAIS; j++) {
                m = this.cfaturacao.get(i).get(j);
                vp = m.get(string);
                if(vp != null)
                    return true;
            }

        return false;
    }

    public double total_faturado_cfaturacao(){
        double total = 0.0;
        Map<String,VProdutos> m;

        for(int i = 0; i < Globais.NRMESES; i++)
            for(int j = 0; j < Globais.NRFILIAIS; j++) {
                m = this.cfaturacao.get(i).get(j);
                for (VProdutos vp : m.values()) {
                    total += vp.total_faturado_vprodutos();
                }
            }

        return total;
    }

    public double[][] faturacao_meses_filiais(String produto){
        double[][] array = new double[Globais.NRMESES][Globais.NRFILIAIS];
        for(int i= 0; i < array.length; i++)
            for(int j = 0; j < array[i].length; j++)
                array[i][j] = faturacao_produto_mes_filial(produto, i, j);

        return array;
    }

    public double faturacao_produto_mes_filial(String produto, int mes, int filial){
        double faturado = 0.0;
        VProdutos vp = this.cfaturacao.get(mes).get(filial).get(produto);
        if(vp != null)
            faturado = vp.total_faturado_vprodutos();
        return faturado;
    }

}



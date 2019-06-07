import javax.xml.bind.annotation.XmlElementDecl;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class CFaturacao implements java.io.Serializable{

    private List<List<Map<String,VProdutos>>> cfaturacao;
    private int nrprodutos;
    private int nrvendas;

    /**
     * Construtor vazio.
     */
    public CFaturacao(){
        this.nrprodutos = 0;
        this.nrvendas = 0;
        this.cfaturacao = new ArrayList<>(Globais.NRMESES);
        List<Map<String,VProdutos>> l;
        Map<String,VProdutos> h;

        for(int i = 0; i < Globais.NRMESES; i++){
            l = new ArrayList<>(Globais.NRFILIAIS);
            this.cfaturacao.add(i, l);
            for(int j = 0; j < Globais.NRFILIAIS; j++){
                h = new HashMap<>();
                this.cfaturacao.get(i).add(j, h);
            }

        }
    }

    /**
     * Método que, dado uma venda, regista essa mesma venda na classe CFaturacao.
     * @param venda
    */
    public void insereEmCFaturacao(Venda venda){
        Map<String,VProdutos> m = this.cfaturacao.get(venda.getMes()-1).get(venda.getFilial()-1);
        VProdutos vp = m.get(venda.getProduto());

        this.nrvendas++;

        /*Isto gasta tempo e não está a ser necessário (guarda o número de produtos em cfiliais).
        if(false == existe_produto_cfaturacao(venda))
            this.nrprodutos++;*/

        if(vp != null){
            vp.insereEmVProdutos(venda.getQuantidade(), venda.getPreco());
        }
        else{
            VProdutos vprodutos = new VProdutos();
            vprodutos.insereEmVProdutos(venda.getQuantidade(), venda.getPreco());
            m.put(venda.getProduto(), vprodutos);
        }

    }

    /**
     * Método que, dado um determinado objecto que é um produto, verifica a sua existência na classe CFaturacao
     * @return true or false
     * @param object
    */
    public boolean existe_produto_cfaturacao(Object object){
        String string = null;
        if(object instanceof String)
            string = (String) object;
        else if(object instanceof Venda)
            string = (String) ((Venda) object).getProduto();

        Map<String,VProdutos> m;
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

    /**
     * Método que calcula o total faturado de todas as vendas.
     * @return
    */
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

    /**
     * Método que, dado um determinado produto, apresenta uma matriz com o total faturado
     * desse mesmo produto em cada mês e filial.
     * @return
     * @param produto
    */
    public double[][] faturacao_meses_filiais(String produto){
        double[][] array = new double[Globais.NRMESES][Globais.NRFILIAIS];
        for(int i= 0; i < array.length; i++)
            for(int j = 0; j < array[i].length; j++)
                array[i][j] = faturacao_produto_mes_filial(produto, i, j);

        return array;
    }

    /**
     * Método que, dado um produto, mês e filial, apresenta o total faturado desse mesmo produto
     * num específico mês e filial.
     * @return
     * @param produto
     * @param mes
     * @param filial
    */
    public double faturacao_produto_mes_filial(String produto, int mes, int filial){
        double faturado = 0.0;
        VProdutos vp = this.cfaturacao.get(mes).get(filial).get(produto);
        if(vp != null)
            faturado = vp.total_faturado_vprodutos();
        return faturado;
    }

    /**
     * Método devolve o número de vendas  
     * @return
    */
    public int getVendasValorZero(){
        int nr = 0;

        for(int i = 0; i < this.cfaturacao.size(); i++){
            for(int j = 0; j < this.cfaturacao.get(i).size(); j++){
                for(VProdutos vp : this.cfaturacao.get(i).get(j).values()){
                    nr += vp.getVendasValorZero();
                }
            }
        }

        return nr;
    }

    /**
     * Método que, dado um array de 
     * @param nrcomprasmes
    */
    public void nr_compras_mes(int[] nrcomprasmes){
        for(int i = 0; i < this.cfaturacao.size(); i++){
            for(int j = 0; j < this.cfaturacao.get(i).size(); j++){
                for(VProdutos vp : this.cfaturacao.get(i).get(j).values()){
                    nrcomprasmes[i] += vp.vprodutos_size();
                }
            }
        }
    }

    /**
     * Método
     * @param fatmesfilial
    */
    public void fat_mes_filial(double[][] fatmesfilial){
        for(int i = 0; i < this.cfaturacao.size(); i++){
            for(int j = 0; j < this.cfaturacao.get(i).size(); j++){
                for(VProdutos vp : this.cfaturacao.get(i).get(j).values()){
                    fatmesfilial[i][j] += vp.total_faturado_vprodutos();
                }
            }
        }
    }

    /**
     * Método que devolve o número de vendas.
     * @return
    */
    public int getNrvendas() {
        return nrvendas;
    }

    /**
     * Método que define o número de vendas da classe CFaturacao.
     * @param nrvendas
    */    
    public void setNrvendas(int nrvendas) {
        this.nrvendas = nrvendas;
    }

    /**
     * Método que devolve o numero de produtos da classe CFaturacao.
     * @return
    */
    public int getNrprodutos() {
        return nrprodutos;
    }

    /**
     * Método que define o número de produtos da classe CFaturacao.
     * @param nrprodutos
    */
    public void setNrprodutos(int nrprodutos) {
        this.nrprodutos = nrprodutos;
    }

}



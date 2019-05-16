import java.util.ArrayList;
import java.util.List;

public class GereVendasModel {

    private CProdutos cprodutos;
    private CClientes cclientes;
    private CFiliais cfiliais;
    private CFaturacao cfaturacao;

    public GereVendasModel(){
        this.cprodutos = new CProdutos();
        this.cclientes = new CClientes();
        this.cfiliais = new CFiliais();
        this.cfaturacao = new CFaturacao();
    }

    public boolean carregaCClientes(String caminho){
        int i = 0;

        Leitor leitor = new Leitor();
        List<String> linhas = leitor.leFicheiro(caminho);

        while(i != linhas.size())
            cclientes.registaCliente(linhas.get(i++));

        //cclientes.imprimeClientes();

        return true;
    }

    public boolean carregaCProdutos(String caminho){
        int i = 0;

        Leitor leitor = new Leitor();
        List<String> linhas = leitor.leFicheiro(caminho);

        while(i != linhas.size())
            cprodutos.registaProduto(linhas.get(i++));

        //cprodutos.imprimeProdutos();

        return true;
    }

    public boolean carregaCFiliaisCFaturacao(String caminho){

        return true;
    }


}

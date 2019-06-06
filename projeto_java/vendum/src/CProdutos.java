import java.util.*;

public class CProdutos implements java.io.Serializable{

    private List<List<Set<String>>> produtos;
    private int nrprodutos;

    /**
     * Contrutor vazio
     */
    public CProdutos(){
        this.nrprodutos = 0;
        this.produtos = new ArrayList<>(Globais.NRLETRAS);
        List<Set<String>> l;
        Set<String> s;
        for(int i = 0; i < Globais.NRLETRAS; i++){
            l = new ArrayList<>(Globais.NRLETRAS);
            this.produtos.add(i, l);

            for(int j = 0; j < Globais.NRLETRAS; j++){
                s = new HashSet<>();
                this.produtos.get(i).add(j, s);
            }
        }

    }

    /**
     * Construtor parametrizado
     */
    public CProdutos(Collection <String> collection){
        this.nrprodutos = 0;
        this.produtos = new ArrayList<>(Globais.NRLETRAS);
        List<Set<String>> l;
        Set<String> s;

        for(int i = 0; i < Globais.NRLETRAS; i++){
            l = new ArrayList<>();
            this.produtos.add(i, l);

            for(int j = 0; j < Globais.NRLETRAS; j++){
                s = new HashSet<>();
                this.produtos.get(i).add(j, s);
            }
        }

        for(String produto: collection){
            if(this.registaProduto(produto))
                this.nrprodutos++;
        }
    }

    /**
     * Contrutor de cópia
     */
    public CProdutos(CProdutos c){
        this.produtos = new ArrayList<>(Globais.NRLETRAS);
        List<Set<String>> l;
        Set<String> s;

        for(int i = 0; i < Globais.NRLETRAS; i++){
            l = new ArrayList<>();
            this.produtos.add(i, l);

            for(int j = 0; j < Globais.NRLETRAS; j++){
                s = new HashSet<>();
                this.produtos.get(i).add(j, s);
            }
        }

        for(int i = 0; i < c.getProdutos().size(); i++)
            for(int j = 0; j < c.getProdutos().get(i).size(); j++)
                for(String produto: c.getProdutos().get(i).get(j)){
                    if(this.registaProduto(produto))
                        this.nrprodutos++;
                }
    }


    public List<List<Set<String>>> getProdutos(){//retornar um clone??
        return this.produtos;
    }

    public boolean registaProduto(String produto){
        int i = calculaIndice(produto.charAt(0));
        int j = calculaIndice(produto.charAt(1));
        if(produtos.get(i).get(j).add(produto)) {
            this.nrprodutos++;
            return true;
        }

        return false;
    }


    public void imprimeProdutos(){
        for(int i = 0; i < Globais.NRLETRAS; i++)
            for(int j = 0; j < Globais.NRLETRAS; j++)
                System.out.println("cprodutos pos "+ "["+i+"] "+ "["+ j+"]+ " +": \n" + produtos.get(i).get(j));

        System.out.println("Número de produtos: " + this.nrprodutos);
    }

    public boolean existe_produto(String string){
        int i = calculaIndice(string.charAt(0));
        int j = calculaIndice(string.charAt(1));

        return this.produtos.get(i).get(j).contains(string);
    }

    private static int calculaIndice(char letra){
        letra = Character.toUpperCase(letra);
        return letra - 'A';
    }

    public int getNrprodutos() {
        return nrprodutos;
    }

    public void setNrprodutos(int nrprodutos) {
        this.nrprodutos = nrprodutos;
    }

    public void prods_nao_comprados(LStrings lStrings, CFaturacao cfaturacao){
        for(int i = 0; i < this.produtos.size(); i++)
            for(int j = 0; j < this.produtos.get(i).size(); j++)
                for(String produto: this.produtos.get(i).get(j))
                    if(!cfaturacao.existe_produto_cfaturacao(produto))
                        lStrings.regista_entrada(produto);
    }

    public List<List<Set<String>>> shallowCloneProdutos() {
        List<List<Set<String>>> produtos = new ArrayList<>(this.produtos.size());
        produtos = this.produtos;
        return produtos;
    }

    public boolean valida_produto(String codigo){
        if(!Character.isUpperCase(codigo.charAt(0)) || !Character.isUpperCase(codigo.charAt(1)))
            return false;
        if(codigo.length() != 6)
            return false;
        if(Integer.parseInt(codigo.substring(2)) < 1000 || Integer.parseInt(codigo.substring(2)) > 9999)
            return false;
        return true;
    }
}

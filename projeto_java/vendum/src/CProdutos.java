import java.util.*;

public class CProdutos {

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
            l = new ArrayList<>();
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
        produtos.get(i).get(j).add(produto);
        this.nrprodutos++;
        return true;
    }


    public void imprimeProdutos(){

        for(int i = 0; i < Globais.NRLETRAS; i++)
            for(int j = 0; j < Globais.NRLETRAS; j++)
                System.out.println("cprodutos pos "+ "["+i+"] "+ "["+ j+"]+ " +": \n" + produtos.get(i).get(j));

        System.out.println("Número de produtos: " + this.nrprodutos);
    }

    private static int calculaIndice(char letra){
        letra = Character.toUpperCase(letra);
        return letra - 'A';
    }

}

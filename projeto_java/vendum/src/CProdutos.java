import java.util.*;

public class CProdutos implements java.io.Serializable{

    private List<List<Set<String>>> produtos;
    private int nrprodutos;

    /**
     * Contrutor vazio.
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
     * Construtor parametrizado.
     * @param collection
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
     * Contrutor de cópia.
     * @param c
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

    /**
     * Método que devolve a estrutura com os códigos de produtos.
     * @return List de Lists com os códigos de produtos.
     */
    public List<List<Set<String>>> getProdutos(){//retornar um clone??
        return this.produtos;
    }

    /**
     * Método que regista um produto.
     * Devolve true se foi adicionado ou false caso esse produto já exista nos registos dos produtos.
     * @param produto
     * @return Verdadeiro ou falso.
     */
    public boolean registaProduto(String produto){
        int i = calculaIndice(produto.charAt(0));
        int j = calculaIndice(produto.charAt(1));
        if(produtos.get(i).get(j).add(produto)) {
            this.nrprodutos++;
            return true;
        }

        return false;
    }

    /**
     * Método que imprime todos os produtos e o número total de produtos registados.
     */
    public void imprimeProdutos(){
        for(int i = 0; i < Globais.NRLETRAS; i++)
            for(int j = 0; j < Globais.NRLETRAS; j++)
                System.out.println("cprodutos pos "+ "["+i+"] "+ "["+ j+"]+ " +": \n" + produtos.get(i).get(j));

        System.out.println("Número de produtos: " + this.nrprodutos);
    }

    /**
     * Método que verifica se um determinado produto já está registado.
     * @param string
     * @return Verdadeiro ou falso.
     */
    public boolean existe_produto(String string){
        int i = calculaIndice(string.charAt(0));
        int j = calculaIndice(string.charAt(1));

        return this.produtos.get(i).get(j).contains(string);
    }

    /**
     * Método que, dado uma letra, calcula o índice na List associada a essa mesma letra.
     * @param letra
     * @return Índice da letra.
     */
    private static int calculaIndice(char letra){
        letra = Character.toUpperCase(letra);
        return letra - 'A';
    }

    /**
     * Método que devolve o número de produtos.
     * @return Número de produtos.
     */
    public int getNrprodutos() {
        return nrprodutos;
    }

    /**
     * Método que define o número de produtos.
     * @param nrprodutos
     */
    public void setNrprodutos(int nrprodutos) {
        this.nrprodutos = nrprodutos;
    }

    /**
     * Método que regista numa List, os produtos não comprados.
     * @param lStrings
     * @param cfaturacao
     */
    public void prods_nao_comprados(LStrings lStrings, CFaturacao cfaturacao){
        for(int i = 0; i < this.produtos.size(); i++)
            for(int j = 0; j < this.produtos.get(i).size(); j++)
                for(String produto: this.produtos.get(i).get(j))
                    if(!cfaturacao.existe_produto_cfaturacao(produto))
                        lStrings.regista_entrada(produto);
    }

    /**
     * Método que cria uma nova estrutura com uma referência diferente da original.
     * Contudo as referências que apontam para as instâncias são exatamente iguais as da original.
     * @return Nova estrutura com referência diferente, excepto as subestruturas que mantêm as mesmas referências.
     */
    public List<List<Set<String>>> shallowCloneProdutos() {
        List<List<Set<String>>> produtos = new ArrayList<>(this.produtos.size());
        produtos = this.produtos;
        return produtos;
    }

    /**
     * Método que verifica se um determinado código de produto apresenta todos os critérios
     * associados a um código de produto.
     * @return Verdadeiro ou falso.
     * @param codigo
     */
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

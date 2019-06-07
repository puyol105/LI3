import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class LStrings {
    private List<String> lstrings;
    private int nrstrings;
    private int nrlinhas;

    /**
     * Contrutor vazio.
     */
    public LStrings(){
        this.lstrings = new ArrayList<>();
        this.nrstrings = 0;
        this.nrlinhas = 20;
    }

    /**
     * Método que coloca numa lista de strings todas as strings que existem na estrutura recebida nos parâmetros.
     * @param heap
     */
    public void maxheapint_to_lstrings(MaxHeapInt heap){
        Map<Integer,Set<String>> map = heap.getMaxheap();
        for(Map.Entry<Integer,Set<String>> entry: map.entrySet()){
            for(String s : entry.getValue()){
                if(this.lstrings.add("Produto: " + s + "   Quantidade: " + entry.getKey()))
                    this.nrstrings++;
            }
        }
    }

    /**
     * Método que coloca numa lista de strings todas as strings que existem na estrutura recebida nos parâmetros.
     * @param heap
     */
    public void maxheapint_to_lstrings_netneilc(MaxHeapInt heap){
        Map<Integer,Set<String>> map = heap.getMaxheap();
        for(Map.Entry<Integer,Set<String>> entry: map.entrySet()){
            for(String s : entry.getValue()){
                if(this.lstrings.add("Cliente: " + s + "   Quantidade: " + entry.getKey()))
                    this.nrstrings++;
            }
        }
    }

    /**
     * Método que coloca numa lista de strings todas as strings que existem na estrutura recebida nos parâmetros.
     * @param heap
     */
    public void maxheapint_to_lstrings_etneilc(MaxHeapInt heap){
        Map<Integer,Set<String>> map = heap.getMaxheap();
        for(Map.Entry<Integer,Set<String>> entry: map.entrySet()){
            for(String s : entry.getValue()){
                if(this.lstrings.add(s))
                    this.nrstrings++;
            }
        }
    }

    /**
     * Método que coloca numa lista de strings todas as strings que existem na estrutura recebida nos parâmetros.
     * @param heap
     */
    public void maxheapdouble_to_lstrings(MaxHeapDouble heap){
        Map<Double,Set<String>> map = heap.getMaxheap();
        for(Map.Entry<Double,Set<String>> entry: map.entrySet()){
            for(String s : entry.getValue()){
                if(this.lstrings.add("Cliente: " + s + "   Total gasto: " + entry.getKey()))
                    this.nrstrings++;
            }
        }
    }

    /**
     * Método que adiciona uma string à lista de strings.
     * @param string
     */
    public boolean regista_entrada(String string){
        if(true == this.lstrings.add(string)){
            this.nrstrings++;
            return true;
        }

        return false;
    }

    /**
     * Método que define o número de linhas nas páginas da lista de strings.
     * @param nrlinhas
     * @return Verdadeiro se o número dado é válido ou falso caso contrário.
     */
    public boolean define_nrlinhas(int nrlinhas){
        if(nrlinhas >=5) {
            this.nrlinhas = nrlinhas;
            return true;
        }

        return false;
    }

    /**
     * Método que imprime a lista de strings.
     */
    public void imprime_lstrings(){
        GereVendasView view = new GereVendasView();
        Input input = new Input();

        int indice = 0;
        int pagatual = 0;
        int totpag = 0;
        int opcao = -1;

        if((this.nrstrings % this.nrlinhas) == 0)
            totpag = this.nrstrings/this.nrlinhas;
        else
            totpag = this.nrstrings/nrlinhas + 1;

        while(opcao != 0) {

            for(indice = pagatual*this.nrlinhas; indice < (pagatual*this.nrlinhas + this.nrlinhas) && indice < nrstrings; indice ++)
                System.out.println(this.lstrings.get(indice));

            System.out.println("\n[1]PRÓXIMA   [2]ANTERIOR   [3]ÚLTIMA   [4]PRIMEIRA  [0]SAIR");
            System.out.println("Página " + pagatual + " de " + (totpag-1) + ".");
            System.out.println(this.nrstrings + " resultados.");

            opcao = input.lerInt();

            switch(opcao){
                case 1:
                    if(pagatual < totpag - 1)
                        pagatual++;
                    break;
                case 2:
                    if(pagatual > 0)
                        pagatual--;
                    break;
                case 3:
                    pagatual = totpag - 1;
                    break;
                case 4:
                    pagatual = 0;
                    break;
                case 0:
                    opcao = 0;
                    break;
                default:
                    System.out.println("Inseriu uma opção errada.");
                    break;
            }

            //view.enterParaContinuar();
        }

    }

    /**
     * Método que retorna a string de uma determinada posição.
     * @param i
     * @return String naquela posição.
     */
    public String getPosicaoLstrings(int i){
        return this.lstrings.get(i);
    }

    /**
     * Método que define o número de strings.
     * @param nrstrings
     */
    public void setNrstrings(int nrstrings){
        this.nrstrings = nrstrings;
    }

    /**
     * Método que devolve o número de strings.
     * @return Número de strings.
     */
    public int getNrstrings(){
        return this.nrstrings;
    }

}

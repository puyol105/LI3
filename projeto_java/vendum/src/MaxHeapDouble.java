import java.util.*;

public class MaxHeapDouble {

    private Map<Double, Set<String>> maxheap = null;
    private int nrelementos;

    /**
     * Construtor vazio.
     */
    public MaxHeapDouble(){
        this.maxheap = new TreeMap<Double,Set<String>>(Collections.reverseOrder());
        this.nrelementos = 0;
    }

    /**
     * Método que converte o map recebido (em que as chaves são strings e os valores são números que lhes estão associados)
     * num treemap (em que as chaves são os valores do map anterior e os valores as chaves) ordenado por ordem descrescente.
     * @param map
     * @return MaxHeapDouble
     */
    public MaxHeapDouble to_maxheap(Map<String, Double> map){

        for(Map.Entry<String,Double> entry: map.entrySet()){
            Set<String> s = this.maxheap.get(entry.getValue());

            if(s != null){
                s.add(entry.getKey());
                this.nrelementos++;
            }
            else{
                s = new TreeSet<>();
                s.add(entry.getKey());
                this.maxheap.put(entry.getValue(), s);
                this.nrelementos++;
            }

        }

        return this;
    }

    public Map<Double, Set<String>> getMaxheap(){
        return this.maxheap;
    }
}
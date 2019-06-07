import java.util.*;

public class MaxHeapInt {

    private Map<Integer, Set<String>> maxheap = null;
    private int nrelementos;

    /**
     * Construtor vazio.
     */
    public MaxHeapInt(){
        this.maxheap = new TreeMap<Integer,Set<String>>(Collections.reverseOrder());
        this.nrelementos = 0;
    }

    /**
     * Método que converte o map recebido (em que as chaves são strings e os valores são números que lhes estão associados)
     * num treemap (em que as chaves são os valores do map anterior e os valores as chaves) ordenado por ordem descrescente.
     * @param map
     * @return MaxHeapInt
     */
    public MaxHeapInt to_maxheap(Map<String, Integer> map){

        for(Map.Entry<String,Integer> entry: map.entrySet()){
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


    public void put_add_maxheap(Integer inteiro, String string){
        Set<String> set = null;
        set = this.maxheap.get(inteiro);

        if(set != null){
            set.add(string);
            this.nrelementos++;
        }
        else{
            set = new TreeSet<>();
            set.add(string);
            this.maxheap.put(inteiro, set);
            this.nrelementos++;
        }
    }

    public Map<Integer, Set<String>> getMaxheap(){
        return this.maxheap;
    }

    public int getNrelementos(){
        return this.nrelementos;
    }
}

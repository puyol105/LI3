import java.util.*;

public class MaxHeapDouble {

    private Map<Double, Set<String>> maxheap = null;
    private int nrelementos;

    public MaxHeapDouble(){
        this.maxheap = new TreeMap<Double,Set<String>>(Collections.reverseOrder());
        this.nrelementos = 0;
    }

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
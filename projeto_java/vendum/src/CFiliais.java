import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class CFiliais {
    private List<List<HashMap<String,ProdsCliente>>> cfiliais;
    private  int nrclientes;
    private int nrvendas;

    public CFiliais(){
        this.nrclientes = 0;
        this.nrvendas = 0;
        this.cfiliais = new ArrayList<>(Globais.NRMESES);
        List<HashMap<String,ProdsCliente>> l;
        HashMap<String,ProdsCliente> h;

        for(int i = 0; i < Globais.NRMESES; i++) {
            l = new ArrayList<>(Globais.NRFILIAIS);
            this.cfiliais.add(i, l);
            for(int j = 0; j < Globais.NRFILIAIS; j++){
                h = new HashMap<>();
                this.cfiliais.get(i).add(j, h);
            }
        }
    }

    public void insereEmCFiliais(Venda venda){
        Map<String,ProdsCliente> m = this.cfiliais.get(venda.getMes()-1).get(venda.getFilial()-1);
        ProdsCliente pc = m.get(venda.getCliente());

        this.nrvendas++;

        if(!existe_cliente_cfiliais(venda))
            this.nrclientes++;

        if(pc != null){
            pc.insere_em_prodscliente(venda);
        }
        else{
            ProdsCliente prodscliente = new ProdsCliente();
            prodscliente.insere_em_prodscliente(venda);
            m.put(venda.getCliente(), prodscliente);
        }
    }

    private boolean existe_cliente_cfiliais(Venda venda){
        Map<String,ProdsCliente> m;
        ProdsCliente pc;

        for(int i = 0; i < Globais.NRMESES; i++)
            for(int j = 0; j < Globais.NRFILIAIS; j++) {
                m = this.cfiliais.get(i).get(j);
                pc = m.get(venda.getCliente());
                if(pc != null)
                    return true;
            }

        return false;
    }

    public double total_faturado_cfiliais(){
        double total = 0.0;
        Map<String,ProdsCliente> m;

        for(int i = 0; i < Globais.NRMESES; i++)
            for(int j = 0; j < Globais.NRFILIAIS; j++) {
                m = this.cfiliais.get(i).get(j);
                for (ProdsCliente pc : m.values()) {
                    total += pc.total_faturado_prodscliente();
                }
            }

        return total;
    }

    public int getNrclientes() {
        return nrclientes;
    }

    public void setNrclientes(int nrclientes) {
        this.nrclientes = nrclientes;
    }

    public int getNrvendas() {
        return nrvendas;
    }

    public void setNrvendas(int nrvendas) {
        this.nrvendas = nrvendas;
    }
}

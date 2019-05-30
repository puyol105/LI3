import java.util.Set;
import java.util.TreeSet;

public class ClisProd {

    private int qtd;
    private Set<String> clientes;

    public ClisProd(int qtd, Set<String> clientes) {
        this.qtd = qtd;
        this.clientes = clientes;
    }

    public ClisProd(){
        this.qtd = 0;
        this.clientes = new TreeSet<>();
    }

    public int getQtd() {
        return qtd;
    }

    public void setQtd(int qtd) {
        this.qtd = qtd;
    }

    public Set<String> getClientes() {
        return clientes;
    }

    public void setClientes(Set<String> clientes) {
        this.clientes = clientes;
    }

    public void addToClientes(String string){
        this.clientes.add(string);
    }

}

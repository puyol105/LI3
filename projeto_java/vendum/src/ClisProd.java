import java.util.Set;
import java.util.TreeSet;

public class ClisProd {

    private int qtd;
    private Set<String> clientes;

    /**
     * Construtor parametrizado
     * @param qtd
     * @param clientes
     */
    public ClisProd(int qtd, Set<String> clientes) {
        this.qtd = qtd;
        this.clientes = clientes;
    }

    /**
     * Construtor vazio.
     */
    public ClisProd(){
        this.qtd = 0;
        this.clientes = new TreeSet<>();
    }

    /**
     * Método que devolve a quantidade ???
     * @return
     */
    public int getQtd() {
        return qtd;
    }

    /**
     * Método que defina a quantidade ???
     * @param qtd
     */
    public void setQtd(int qtd) {
        this.qtd = qtd;
    }

    /**
     * Método que devolve um Set de clientes que compraram um determinado produto.
     * @return
     */
    public Set<String> getClientes() {
        return clientes;
    }

    /**
     * Método que define um Set de clientes
     * @param clientes
     */
    public void setClientes(Set<String> clientes) {
        this.clientes = clientes;
    }

    /**
     * Método que adiciona um determinado cliente ao Set de clientes que compraram um determinado produto.
     * @param string
     */
    public void addToClientes(String string){
        this.clientes.add(string);
    }

}

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
     * Método que devolve a quantidade de produto comprada pelos clientes.
     * @return Quantidade comprada.
     */
    public int getQtd() {
        return qtd;
    }

    /**
     * Método que define a quantidade de produto comprada pelos clientes.
     * @param qtd
     */
    public void setQtd(int qtd) {
        this.qtd = qtd;
    }

    /**
     * Método que devolve o conjunto de clientes que compraram um determinado produto.
     * @return Conjunto de clientes
     */
    public Set<String> getClientes() {
        return clientes;
    }

    /**
     * Método que define o conjunto de clientes que compraram um determinado produto.
     * @param clientes
     */
    public void setClientes(Set<String> clientes) {
        this.clientes = clientes;
    }

    /**
     * Método que adiciona um determinado cliente ao conjunto de clientes que compraram um determinado produto.
     * @param string
     */
    public void addToClientes(String string){
        this.clientes.add(string);
    }

}

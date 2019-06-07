import java.util.*;


public class CClientes implements java.io.Serializable{

    private List<Set<String>> clientes;
    private int nrclientes;

    /**
     * Contrutor vazio
     */
    public CClientes(){
        this.nrclientes = 0;
        this.clientes = new ArrayList<>(Globais.NRLETRAS);
        Set<String> s;
        for(int i = 0; i < Globais.NRLETRAS; i++){
            s = new HashSet<>();
            this.clientes.add(i, s);
        }
    }

    /**
     * Construtor parametrizado
     */
    public CClientes(Collection <String> collection){
        this.nrclientes = 0;
        this.clientes = new ArrayList<>(Globais.NRLETRAS);
        Set<String> s;

        for(int i = 0; i < Globais.NRLETRAS; i++){
            s = new HashSet<>();
            this.clientes.add(i, s);
        }

        for(String cliente: collection) {
            if(this.registaCliente(cliente))
                this.nrclientes++;
        }
    }

    /**
     * Contrutor de cópia
     */
    public CClientes(CClientes c){
        this.clientes = new ArrayList<>(Globais.NRLETRAS);
        Set<String> s;

        for(int i = 0; i < Globais.NRLETRAS; i++){
            s = new HashSet<>();
            this.clientes.add(i, s);
        }

        for(int i = 0; i < c.getClientes().size(); i++)
            for(String cliente: c.getClientes().get(i)){
                if(this.registaCliente(cliente))
                    nrclientes++;
            }
    }

    /**
     * Método que devolve todos os clientes
    */ 
    public List<Set<String>> getClientes(){//retornar um clone??
        return this.clientes;
    }

    /**
     * Método que devolve to total de clientes existente
    */ 
    public int getNrclientes(){
        return this.nrclientes;
    }

    /**
     * Método que, dado um código de cliente, regista esse mesmo cliente na List na posição associada à letra
    */ 
    public boolean registaCliente(String cliente){
        int i = calculaIndice(cliente.charAt(0));
        if(clientes.get(i).add(cliente)) {
            this.nrclientes++;
            return true;
        }

        return false;
    }

    /**
     * Método que imprime TODOS??? os clientes por ORDEM ALFABETICA???
    */ 
    public void imprimeClientes(){

        for(int i = 0; i < Globais.NRLETRAS; i++)
            System.out.println("cclientes pos "+ i +": \n" + clientes.get(i));

        System.out.println("Número de clientes: " + this.nrclientes);
    }

    /**
     * Método que, dado um código de cliente, verifica se esse mesmo cliente já está registado no sistema
    */ 
    public boolean existe_cliente(String string){
        int i = calculaIndice(string.charAt(0));

        return this.clientes.get(i).contains(string);
    }

    /**
     * Método que, dado uma letra, determina o índice da posição da List associada a essa mesma letra
    */ 
    private static int calculaIndice(char letra){
        letra = Character.toUpperCase(letra);
        return letra - 'A';
    }

    public List<Set<String>> deepCloneClientes(){
        List<Set<String>> clientes = new ArrayList<>(this.clientes.size());
        Set<String> s;

        for(int i = 0; i < this.clientes.size(); i++){
            s = new HashSet<>();
            clientes.get(i).addAll(this.clientes.get(i));
        }

        return clientes;
    }

    public List<Set<String>> shallowCloneClientes(){
        List<Set<String>> clientes = new ArrayList<>(this.clientes.size());
        clientes = this.clientes;
        return clientes;
    }

    /**
     * Método que, dado um codigo de cliente, testa se todos os critérios associados a um código de clientes se se aplica no código em 
     * questão
    */ 
    public boolean valida_cliente(String codigo){
        if(!Character.isUpperCase(codigo.charAt(0)))
            return false;
        if(codigo.length() != 5)
            return false;
        if(Integer.parseInt(codigo.substring(1)) < 1000 || Integer.parseInt(codigo.substring(1)) > 5000)
            return false;
        return true;
    }
}

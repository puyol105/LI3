import java.util.*;


public class CClientes{

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


    public List<Set<String>> getClientes(){//retornar um clone??
        return this.clientes;
    }

    public int getNrclientes(){
        return this.nrclientes;
    }

    public boolean registaCliente(String cliente){
        int i = calculaIndice(cliente.charAt(0));
        clientes.get(i).add(cliente);
        this.nrclientes++;
        return true;
    }

    public void imprimeClientes(){

        for(int i = 0; i < Globais.NRLETRAS; i++)
            System.out.println("cclientes pos "+ i +": \n" + clientes.get(i));

        System.out.println("Número de clientes: " + this.nrclientes);
    }

    private static int calculaIndice(char letra){
        letra = Character.toUpperCase(letra);
        return letra - 'A';
    }
}
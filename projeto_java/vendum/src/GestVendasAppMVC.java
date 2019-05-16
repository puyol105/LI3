import com.sun.glass.ui.SystemClipboard;

import java.io.IOException;
import java.nio.file.Files;
import java.util.*;
import java.io.*;
import java.lang.*;
import java.nio.file.*;





public class GestVendasAppMVC{





    public static void main(String [] args){

        GereVendasModel model = new GereVendasModel(); //model

        if(model==null){
            System.out.println("Error in model layer!");
            System.exit(-1);
        }

        GereVendasView view = new GereVendasView(); //view

        if(view==null){
            System.out.println("Error in view layer!");
            System.exit(-1);
        }

        GereVendasController control = new GereVendasController(); //controller

        if(control==null){
            System.out.println("Error in control layer!");
            System.exit(-1);
        }

        control.setModel(model);
        control.setView(view);
        control.startController();

        System.exit(0);
    }















































    /*GestVendas gestVendas;


    public static void main(String[] args){

        GestVendasAppMVC app = new GestVendasAppMVC();

        app.executa();
    }










    public static List<String> readLinesWithBR(String fich){
        List<String> linhas = new ArrayList<>();
        BufferedReader inFile = null;
        String linha = null;
        try{
            inFile = new BufferedReader(new FileReader (fich));
            while((linha = inFile.readLine()) != null)
                linhas.add(linha);
        }
        catch(IOException e){
            System.out.println(e);
        }
        return linhas;
    }

    public static List<String> ler_With_Files(String fichtxt) {
        List<String> linhas = new ArrayList<>();

        try {
            linhas = Files.readAllLines(Paths.get(fichtxt));
        } catch (IOException exc) {
            System.out.println(exc);
        }

        return linhas;
    }

    public static IVenda linhaToVenda(String linha){
        Venda compra = null;
        int quant;
        double preco; = 0.0;
        int mes = 0;
        int filial = 0;
        String codProd, codCli, tipo;
        String [] campos = linha,split(" ");


        codProd = campos[0];
        para inteiros Integer.parseInteger(....);
        para

        try{
            preco = Double.parseDouble(campos[1]);
        }
        catch (InputMismatchException e | NumberFormatException e){return null;}
    }


    public static void main(String[] args){
        int i = 0;
        List<String> linhas = new ArrayList<>();
        List<String> produtos = new ArrayList<>();
        List<String> clientes = new ArrayList<>();
        Crono crono = new Crono();

        crono.start();


        linhas = readLinesWithBR("../intocaveis/Vendas_1M.txt");
        System.out.println(linhas.size());

        linhas = ler_With_Files("../intocaveis/Vendas_5M.txt");
        System.out.println(linhas.size());

        linhas = ler_With_Files("../intocaveis/Produtos.txt");
        System.out.println(linhas.size());

        linhas = ler_With_Files("../intocaveis/Clientes.txt");
        System.out.println(linhas.size());

        while(i != linhas.size())
           System.out.println(linhas.get(i++));

        crono.stop();
        System.out.println(crono.print());


    }*/
}

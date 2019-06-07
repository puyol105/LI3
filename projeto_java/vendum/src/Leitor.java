import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class Leitor {

    /**
     * Método que lê um ficheiro utilizando a classe Files.
     * @return List com as linhas lidas.
     */
    public static List<String> leFicheiro(String fichtxt) {
        List<String> linhas = new ArrayList<>();

        try {
            linhas = Files.readAllLines(Paths.get(fichtxt));
        } catch (IOException exc) {
            System.out.println(exc);
        }

        return linhas;
    }

    /**
     * Método que lê um ficheiro utilizando a classe BufferedReader.
     * @return List com as linhas lidas.
     */
    public static List<String> readLinesWithBR(String fich){
        List<String> linhas = new ArrayList<>();
        BufferedReader inFile = null;
        String linha = null;
        try{
            inFile = new BufferedReader(new FileReader(fich));
            while((linha = inFile.readLine()) != null)
                linhas.add(linha);
        }
        catch(IOException e){
            System.out.println(e);
        }
        return linhas;
    }
}

/**
 * Classe que abstrai a utilização da classe Scanner, escondendo todos os
 * problemas relacionados com excepções, e que oferece métodos simples e
 * robustos para a leitura de valores de tipos simples e String.
 *
 * É uma classe de serviços, como Math e outras de Java, pelo que devem ser
 * usados os métodos de classe implementados.
 *
 * Utilizável em BlueJ, NetBeans, CodeBlocks ou Eclipse.
 *
 * Utilização típica:  int x = Input.lerInt();
 *                     String nome = Input.lerString();
 *
 * @author F. Mário Martins
 * @version 1.0 (6/2006)
 */
import static java.lang.System.out;
import static java.lang.System.in;
import java.util.Scanner;
import java.util.InputMismatchException;

public class Input {

    /**
     * Método que lê uma string do STDIN.
     * @return String lida.
     */
    public static String lerString() {
        Scanner input = new Scanner(in);
        boolean ok = false;
        String txt = "";
        while(!ok) {
            try {
                txt = input.nextLine();
                ok = true;
            }
            catch(InputMismatchException e)
            { out.println("Texto Invalido");
                out.print("Novo valor: ");
                input.nextLine();
            }
        }
        //input.close();
        return txt;
    }

    /**
     * Método que lê um inteiro do STDIN.
     * @return Inteiro lido.
     */
    public static int lerInt() {
        Scanner input = new Scanner(in);
        boolean ok = false;
        int i = 0;
        while(!ok) {
            try {
                i = input.nextInt();
                ok = true;
            }
            catch(InputMismatchException e)
            { out.println("Inteiro Invalido");
                out.print("Novo valor: ");
                input.nextLine();
            }
        }
        //input.close();
        return i;
    }

    /**
     * Método que lê um double do STDIN.
     * @return Double lido.
     */
    public static double lerDouble() {
        Scanner input = new Scanner(in);
        boolean ok = false;
        double d = 0.0;
        while(!ok) {
            try {
                d = input.nextDouble();
                ok = true;
            }
            catch(InputMismatchException e)
            { out.println("Valor real Invalido");
                out.print("Novo valor: ");
                input.nextLine();
            }
        }
        //input.close();
        return d;
    }

    /**
     * Método que lê um float do STDIN.
     * @return Float lido.
     */
    public static float lerFloat() {
        Scanner input = new Scanner(in);
        boolean ok = false;
        float f = 0.0f;
        while(!ok) {
            try {
                f = input.nextFloat();
                ok = true;
            }
            catch(InputMismatchException e)
            { out.println("Valor real Invalido");
                out.print("Novo valor: ");
                input.nextLine();
            }
        }
        //input.close();
        return f;
    }

    /**
     * Método que lê um boleano do STDIN.
     * @return Boleano lido.
     */
    public static boolean lerBoolean() {
        Scanner input = new Scanner(in);
        boolean ok = false;
        boolean b = false;
        while(!ok) {
            try {
                b = input.nextBoolean();
                ok = true;
            }
            catch(InputMismatchException e)
            { out.println("Booleano Invalido");
                out.print("Novo valor: ");
                input.nextLine();
            }
        }
        //input.close();
        return b;
    }

    /**
     * Método que lê um short do STDIN.
     * @return Short lido.
     */
    public static short lerShort() {
        Scanner input = new Scanner(in);
        boolean ok = false;
        short s = 0;
        while(!ok) {
            try {
                s = input.nextShort();
                ok = true;
            }
            catch(InputMismatchException e)
            { out.println("Short Invalido");
                out.print("Novo valor: ");
                input.nextLine();
            }
        }
        //input.close();
        return s;
    }
}

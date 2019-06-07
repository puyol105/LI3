/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author asus
 */
/**
 * Crono = mede um tempo entre start() e stop()
 * O tempo e medido em nanosegundos e convertido para
 *  um double que representa os segs na sua parte inteira.
 *
 * @author FMM
 * @version (a version number or a date)
 */
import static java.lang.System.nanoTime;


public class Crono {

    private static long inicio = 0L;
    private static long fim = 0L;

    /**
     * Método que começa a medição do tempo.
     */
    public static void start() {
        fim = 0L; inicio = nanoTime();
    }

    /**
     * Método que começa a contagem do tempo.
     * @return Tempo medido.
     */
    public static double stop() {
        fim = nanoTime();
        long elapsedTime = fim - inicio;
        // segundos
        return elapsedTime / 1.0E09;
    }

    /**
     * Método que começa a contagem do tempo.
     * @return String a informar o tempo medido.
     */
    public static String print() {
        return "Tempo: " + stop();
    }
}
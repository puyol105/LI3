
public class GereVendasView {

    private Input input = new Input();

    public int imprimeMenuPrincipal(){
        int i;

        imprimeMsgInfo("1. .");
        imprimeMsgInfo("2. Produtos nunca comprados.");
        imprimeMsgInfo("3. Nº total de vendas e de clientes de um/uma mês/filial.");
        imprimeMsgInfo("4. Nº compras, nº produtos comprados e gastos mensais de um cliente.");
        imprimeMsgInfo("5. Quantidade comprada, nº clientes diferentes e total faturado de um produto.");
        imprimeMsgInfo("6. .");
        imprimeMsgInfo("7. .");
        imprimeMsgInfo("8. .");
        imprimeMsgInfo("9. .");
        imprimeMsgInfo("10. .");
        imprimeMsgInfo("11. Faturação mensal e por filial de um produto.");
        imprimeMsgInfo("0. Encerrar aplicação.");

        imprimePedidoOpcao();

        i = input.lerInt();

        return i;
    }

    public int imprimeMenuQuery1(){
        int i;

        imprimeMsgInfo("1. Carregar ficheiros padrão.");
        imprimeMsgInfo("2. Carregar ficheiros específicos.");
        imprimeMsgInfo("3. Carregar modelo.");
        imprimeMsgInfo("0. Sair.");

        imprimePedidoOpcao();

        i = input.lerInt();

        return i;
    }

    public int imprime_menu_query2(){
        int i;

        imprimeMsgInfo("Insira o número de códigos por página: ");

        i = input.lerInt();

        return i;
    }

    public void imprimePedidoOpcao(){
        quebraDeLinha();
        imprimeMsgInfo("Usando os nᵒˢ, insira uma opção:");
    }

    public void imprimeMsgErro(String string){
        System.out.println(string);
    }

    public void imprimeMsgInfo(String string){
        System.out.println(string);
    }

    public void quebraDeLinha(){
        System.out.println();
    }

    public void limparEcra(){
        System.out.println("\f");
    }

    public void enterParaContinuar() {
        System.out.println("Prima ENTER para continuar... ");
        input.lerString();
        limparEcra();
    }

    public void imprime_tabela_faturacao(double[][] array){

        System.out.println("--------------------------------------------------------");
        System.out.println("|  Meses  |   Filial 1   |   Filial 2   |   Filial 3   |");
        System.out.println("--------------------------------------------------------");
        for(int i = 0; i < array.length; i++) {
            System.out.print(String.format("|%1$8s |", i+1));
            for (int j = 0; j < array[i].length; j++) {
                System.out.print(String.format("  %1$10s  |", array[i][j]));
            }
            System.out.println("\n--------------------------------------------------------");
        }



    }

    public void imprime_tabela_query4(double[][] array){
        double a = 0.0, b = 0.0, c = 0.0;

        System.out.println("--------------------------------------------------------");
        System.out.println("|  Meses  |  Nº compras  |  Nº produtos |  Total gasto |");
        System.out.println("--------------------------------------------------------");
        for(int i = 0; i < array.length; i++) {
            System.out.print(String.format("|%1$8s |", i+1));
            System.out.print(String.format("  %1$10s  |", (int) array[i][0]));
            System.out.print(String.format("  %1$10s  |", (int) array[i][1]));
            System.out.print(String.format("  %1$10s  |", (Math.round(array[i][2]*100)/100D)));
            System.out.println("\n--------------------------------------------------------");
        }

        for(int i = 0; i < Globais.NRMESES; i++){
            a += array[i][0];
            b += array[i][1];
            c += array[i][2];
        }


        System.out.print("|  TOTAL  |");
        System.out.print(String.format("  %1$10s  |", (int) a));
        System.out.print(String.format("  %1$10s  |", (int) b));
        System.out.print(String.format("  %1$10s  |", (Math.round(c*100)/100D)));
        System.out.println("\n--------------------------------------------------------");
    }

    public void imprime_tabela_query5(double[][] array){
        double a = 0.0, b = 0.0, c = 0.0;

        System.out.println("--------------------------------------------------------");
        System.out.println("|  Meses  | Qtd comprada |  Nº clientes | Tot faturado |");
        System.out.println("--------------------------------------------------------");
        for(int i = 0; i < array.length; i++) {
            System.out.print(String.format("|%1$8s |", i+1));
            System.out.print(String.format("  %1$10s  |", (int) array[i][0]));
            System.out.print(String.format("  %1$10s  |", (int) array[i][1]));
            System.out.print(String.format("  %1$10s  |", (Math.round(array[i][2]*100)/100D)));
            System.out.println("\n--------------------------------------------------------");
        }

        for(int i = 0; i < Globais.NRMESES; i++){
            a += array[i][0];
            b += array[i][1];
            c += array[i][2];
        }


        System.out.print("|  TOTAL  |");
        System.out.print(String.format("  %1$10s  |", (int) a));
        System.out.print(String.format("  %1$10s  |", (int) b));
        System.out.print(String.format("  %1$10s  |", (Math.round(c*100)/100D)));
        System.out.println("\n--------------------------------------------------------");
    }

}

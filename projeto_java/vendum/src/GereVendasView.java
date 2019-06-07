
public class GereVendasView {

    private Input input = new Input();

    /**
     * Método que imprime o logo inicial.
     */
    public void imprime_logo(){
        System.out.println(" ____   ____  ________  ____  _____  ______   _____  _____  ____    ____ ");
        System.out.println("|_  _| |_  _||_   __  ||_   \\|_   _||_   _ `.|_   _||_   _||_   \\  /   _|");
        System.out.println("  \\ \\   / /    | |_ \\_|  |   \\ | |    | | `. \\ | |    | |    |   \\/   |  ");
        System.out.println("   \\ \\ / /     |  _| _   | |\\ \\| |    | |  | | | '    ' |    | |\\  /| |  ");
        System.out.println("    \\ ' /     _| |__/ | _| |_\\   |_  _| |_.' /  \\ \\__/ /    _| |_\\/_| |_ ");
        System.out.println("     \\_/     |________||_____|\\____||______.'    `.__.'    |_____||_____|");
        System.out.print("\n");
        System.out.println("                         Sistema de Gestão de Vendas");
        System.out.print("\n\n\n");
    }

    /**
     * Método que imprime o menu principal e retorna a opção introduzida pelo utilizador.
     * @return Número da opção escolhida.
     */
    public int imprimeMenuPrincipal(){
        int i;

        imprimeMsgInfo("1. Carregar dados.");
        imprimeMsgInfo("-----------------------------------------------------------------------------------------");
        imprimeMsgInfo("2. Produtos nunca comprados.");
        imprimeMsgInfo("3. Nº total de vendas e de clientes de um/uma mês/filial.");
        imprimeMsgInfo("4. Nº compras, nº produtos comprados e gastos mensais de um cliente.");
        imprimeMsgInfo("5. Quantidade comprada, nº clientes e total faturado de um produto.");
        imprimeMsgInfo("6. Produtos mais comprados por um cliente.");
        imprimeMsgInfo("7. Os N produtos mais vendidos em todo o ano.(VERIFICAR COM OUTROS)");
        imprimeMsgInfo("8. Os três melhores clientes de uma filial. (VERIFICAR COM OUTROS).");
        imprimeMsgInfo("9. Os N clientes que compraram mais produtos diferentes. (VERIFICAR COM OUTROS)");
        imprimeMsgInfo("10. Os N clientes (e o valor gasto) que mais compraram um produto. (VERIFICAR COM OUTROS)");
        imprimeMsgInfo("11. Faturação mensal e por filial de um produto.");
        imprimeMsgInfo("-----------------------------------------------------------------------------------------");
        imprimeMsgInfo("12. Estatísticas do último ficheiro de vendas carregado.");
        imprimeMsgErro("13. Estatísticas atuais.");
        imprimeMsgInfo("14. Guardar dados em memória e encerrar aplicação.");
        imprimeMsgInfo("0. Encerrar aplicação.");

        imprimePedidoOpcao();

        i = input.lerInt();

        return i;
    }

    public int imprimeMenuQuery1(){
        int i;

        imprimeMsgInfo("1. Carregar ficheiros padrão.");
        imprimeMsgInfo("2. Carregar ficheiros específicos.");
        imprimeMsgInfo("3. Carregar dados em memória.");
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

    public int imprimeMenuQuery13(){
        int i;

        imprimeMsgInfo("1. Nº de compras mensais.");
        imprimeMsgInfo("2. Faturação total, mensal e por filial.");
        imprimeMsgInfo("3. Nº de clientes (distintos) por mês e por filial.");
        imprimeMsgInfo("0. Sair.");

        imprimePedidoOpcao();

        i = input.lerInt();

        return i;
    }

    public int linhas_por_pagina(){
        int i;

        imprimeMsgInfo("Insira o número de linhas por página: ");

        i = input.lerInt();

        return i;
    }

    public int nr_clientes(){
        int i;

        imprimeMsgInfo("Insira um nº N para ver os N clientes que mais variaram:");

        i = input.lerInt();

        return i;
    }

    public int nr_produtos(){
        int i;

        imprimeMsgInfo("Insira um nº N para ver os N produtos mais vendidos:");

        i = input.lerInt();

        return i;
    }

    public int nr_filial(){
        int i;

        imprimeMsgInfo("Insira uma filial:");

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

    public void imprime_array_inteiros_mensal(int[] array){

        System.out.println("-----------------------");
        System.out.println("|  Meses  |   TOTAL   |");
        System.out.println("-----------------------");
        for(int i = 0; i < array.length; i++) {
            System.out.print(String.format("|%1$8s |", i+1));
            System.out.print(String.format("  %1$7s  |", array[i]));
            System.out.println("\n-----------------------");
        }
    }

    public void imprime_tabela_inteiros(int[][] array){

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

    public void imprime_tabela_faturacao_total(double[][] array){
        double[] totalmeses = new double[Globais.NRMESES];
        double[] totalfiliais = new double[Globais.NRFILIAIS];

        System.out.println("-----------------------------------------------------------------------------------------------------------------------");
        System.out.println("|  Meses  |         Filial 1         |         Filial 2         |         Filial 3         |          TOTAL           |");
        System.out.println("-----------------------------------------------------------------------------------------------------------------------");
        for(int i = 0; i < array.length; i++) {
            System.out.print(String.format("|%1$8s |", i+1));
            for (int j = 0; j < array[i].length; j++) {
                totalmeses[i] += array[i][j];
                totalfiliais[j] += array[i][j];
                System.out.print(String.format("  %1$22s  |", array[i][j]));
            }
            System.out.print(String.format("  %1$22s  |", totalmeses[i]));
            System.out.println("\n-----------------------------------------------------------------------------------------------------------------------");
        }


        System.out.print("|  TOTAL  |");
        System.out.print(String.format("  %1$22s  |", totalfiliais[0]));
        System.out.print(String.format("  %1$22s  |", totalfiliais[1]));
        System.out.print(String.format("  %1$22s  |", totalfiliais[2]));
        System.out.print(String.format("  %1$22s  |", totalfiliais[0] + totalfiliais[1] + totalfiliais[2]));


        System.out.println("\n-----------------------------------------------------------------------------------------------------------------------");
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

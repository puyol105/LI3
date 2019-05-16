public class GereVendasView {

    private Input input = new Input();

    public int imprimeMenuPrincipal(){
        int i;

        imprimeMsgInfo("1. .");
        imprimeMsgInfo("2. .");
        imprimeMsgInfo("3. .");
        imprimeMsgInfo("4. .");
        imprimeMsgInfo("5. .");
        imprimeMsgInfo("6. .");
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
}

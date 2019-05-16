public class GereVendasController {

    GereVendasModel model;

    GereVendasView view;


    public void setModel(GereVendasModel model){
        this.model = model;
    }

    public void setView(GereVendasView view){
        this.view = view;
    }

    public void startController() {

        boolean dados = false;
        int r = -1;


        while (r != 0) {

            r = view.imprimeMenuPrincipal();


            switch (r) {
                case 1:
                    dados = query1();
                    view.enterParaContinuar();
                    break;
                case 2:
                    //if app populada
                    view.enterParaContinuar();
                    break;
                case 0:
                    view.quebraDeLinha();
                    view.imprimeMsgInfo("VendUM encerrada!");
                    break;
                default:
                    view.imprimeMsgErro("Opção inválida.");
                    view.enterParaContinuar();
                    break;
            }
        }
    }

    private boolean query1(){
        int r = -1;

        boolean dados = false;

        r = view.imprimeMenuQuery1();

        switch(r){
            case 1:
                model.carregaCClientes("../intocaveis/Clientes.txt");
                model.carregaCProdutos("../intocaveis/Produtos.txt");
                model.carregaCFiliaisCFaturacao("../intocaveis/Vendas_1M.txt");
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                view.imprimeMsgInfo("Sairá do menu de carregamento de dados.");
                break;
            default:
                view.imprimeMsgErro("Opção inválida.");
                view.enterParaContinuar();
                break;
        }

        return dados;
    }
}

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
                    if(dados == true)
                        query2();
                    view.enterParaContinuar();
                    break;
                case 3:
                    //if app populada
                    view.enterParaContinuar();
                    break;
                case 4:
                    //if app populada
                    view.enterParaContinuar();
                    break;
                case 5:
                    //if app populada
                    view.enterParaContinuar();
                    break;
                case 6:
                    //if app populada
                    view.enterParaContinuar();
                    break;
                case 7:
                    //if app populada
                    view.enterParaContinuar();
                    break;
                case 8:
                    //if app populada
                    view.enterParaContinuar();
                    break;
                case 9:
                    //if app populada
                    view.enterParaContinuar();
                    break;
                case 10:
                    //if app populada
                    view.enterParaContinuar();
                    break;
                case 11:
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
                dados = model.tudo_carregado();
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

    private void query2(){
        LStrings lStrings = new LStrings();
        int r;
        boolean next = false;

        while(!next) {
            r = view.imprime_menu_query2();
            next = lStrings.define_nrlinhas(r);
            if(!next)
                view.imprimeMsgErro("Inseriu um número pequeno (>= a 5): ");
            else{
                model.prods_nao_comprados(lStrings);
                lStrings.imprime_lstrings();
            }
        }






    }


}

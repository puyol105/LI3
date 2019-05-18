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
                    if(!dados)
                        dados = query1();
                    else
                        this.view.imprimeMsgErro("Dados já carregados.");
                    view.enterParaContinuar();
                    break;
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                    if(dados == true) {
                        switch(r){
                            case 2:
                                query2();
                                break;
                            case 3:
                                query3();
                                break;
                            case 4:
                                query4();
                                break;
                            case 5:
                                query5();
                                break;
                            case 6:
                                break;
                            case 7:
                                break;
                            case 8:
                                break;
                            case 9:
                                break;
                            case 10:
                                break;
                            case 11:
                                query11();
                                break;
                        }
                    }
                    else
                        view.imprimeMsgErro("Dados não carregados.");
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

    private void query3(){
        Input input = new Input();
        int mesfilal = -1;
        int nr = -1;
        int opcao = -1;
        boolean next = false;

        while(!next){
            this.view.imprimeMsgInfo("Pretende resultado mensal ou de uma filial?");
            this.view.imprimeMsgInfo("[1]MENSAL   [2]FILIAL   [0]SAIR");
            mesfilal = input.lerInt();

            if(mesfilal == 0)
                return;

            if(mesfilal == 1 || mesfilal == 2)
                break;
            else{
                this.view.imprimeMsgErro("A opção não é correta.");
                this.view.enterParaContinuar();
            }
        }

        next = false;

        while(!next){
            if(mesfilal == 1)
                this.view.imprimeMsgInfo("Introduza um mês válido: ");
            else if(mesfilal == 2)
                this.view.imprimeMsgInfo("Introduza uma filial válida: ");

            nr = input.lerInt();

            if(mesfilal == 1 && nr >= 1 && nr <=12)
                next = true;
            else if(mesfilal == 2 && nr >= 1 && nr <=3)
                next = true;

            if(!next) {
                if (mesfilal == 1) {
                    this.view.imprimeMsgErro("Mês inválido.");
                    this.view.imprimeMsgInfo("[1]INTRODUZIR MÊS VÁLIDO   [0]SAIR");
                }
                else if (mesfilal == 2){
                    this.view.imprimeMsgErro("Filial inválida.");
                    this.view.imprimeMsgInfo("[1]INTRODUZIR FILIAL VÁLIDA   [0]SAIR");
                }

                opcao = input.lerInt();
            }

            if(opcao == 0) {
                return;
            }

            this.view.enterParaContinuar();
        }

        if(mesfilal == 1){
            System.out.println("Total de vendas no mês " + nr + ": " + this.model.total_vendas_mes_model(nr-1) + ".");
            System.out.println("Nº de clientes no mês " + nr + ": " + this.model.nrclientes_mes_model(nr-1) + ".");
        }
        else if(mesfilal == 2){
            System.out.println("Total de vendas da filial " + nr + ": " + this.model.total_vendas_filial_model(nr-1) + ".");
            System.out.println("Nº de clientes da filial " + nr + ": " + this.model.nrclientes_filial_model(nr-1) + ".");
        }


    }

    private void query4(){
        Input input = new Input();
        String cliente = null;
        int opcao = -1;
        boolean next = false;
        double[][] array = new double[Globais.NRMESES][3];

        while(!next){
            this.view.imprimeMsgInfo("Introduza um cliente válido: ");

            cliente = input.lerString();
            next = model.existe_cliente_model_cfiliais(cliente);

            if(!next){
                this.view.imprimeMsgErro("O cliente não fez compras.");
                this.view.imprimeMsgInfo("[1]INTRODUZIR NOVO CLIENTE   [0]SAIR");
                opcao = input.lerInt();
            }

            if(opcao == 0) {
                return;
            }

            this.view.enterParaContinuar();
        }

        for(int i = 0; i < Globais.NRMESES; i++) {
            array[i][0] = 0;
            array[i][0] += this.model.compras_mes_filial_cliente_model(cliente, i, 0);
            array[i][0] += this.model.compras_mes_filial_cliente_model(cliente, i, 1);
            array[i][0] += this.model.compras_mes_filial_cliente_model(cliente, i, 2);

            array[i][1] = 0;
            array[i][1] = this.model.nrprodutos_mes_cliente_model(cliente, i);

            array[i][2] = 0;
            array[i][2] += this.model.fatprod_mes_filial_cliente_model(cliente, i, 0);
            array[i][2] += this.model.fatprod_mes_filial_cliente_model(cliente, i, 1);
            array[i][2] += this.model.fatprod_mes_filial_cliente_model(cliente, i, 2);
        }

        this.view.imprime_tabela_query4(array);

    }

    private void query5(){
        Input input = new Input();
        String produto = null;
        int opcao = -1;
        double [][] array = new double[Globais.NRMESES][3];
        boolean next = false;

        while(!next){
            this.view.imprimeMsgInfo("Introduza um produto válido: ");

            produto = input.lerString();
            next = model.existe_produto_model_cfaturacao(produto);

            if(!next) {
                this.view.imprimeMsgErro("O produto não foi comprado.");
                this.view.imprimeMsgInfo("[1]INTRODUZIR NOVO PRODUTO   [0]SAIR");
                opcao = input.lerInt();
            }

            if(opcao == 0) {
                return;
            }

            this.view.enterParaContinuar();
        }

        this.model.quantidade_nrclientes_totfaturado_produto_model(produto, array);

        this.view.imprime_tabela_query5(array);
    }

    private void query11(){
        Input input = new Input();
        double[][] array = null;
        String produto = null;
        int opcao = -1;
        boolean next = false;

        while(!next){
            this.view.imprimeMsgInfo("Introduza um produto válido: ");

            produto = input.lerString();
            next = model.existe_produto_model_cfaturacao(produto);

            if(!next) {
                this.view.imprimeMsgErro("O produto não foi comprado.");
                this.view.imprimeMsgInfo("[1]INTRODUZIR NOVO PRODUTO   [0]SAIR");
                opcao = input.lerInt();
            }

            if(opcao == 0) {
                return;
            }

            this.view.enterParaContinuar();
        }

        array = this.model.faturacao_meses_filiais_model(produto);

        this.view.imprime_tabela_faturacao(array);



    }


}

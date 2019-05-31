import javax.management.QueryEval;
import java.io.*;
import java.util.Map;
import java.util.Set;

public class GereVendasController {

    private GereVendasModel model;
    private GereVendasView view;

    public void startController() {

        StringBuilder filevendas = new StringBuilder();
        boolean dados = false;
        int r = -1;

        this.view.imprime_logo();
        this.view.enterParaContinuar();

        while (!(r == 0 || r == 14 )) {

            r = view.imprimeMenuPrincipal();


            switch (r) {
                case 1:
                    if(!dados)
                        dados = query1(filevendas);
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
                case 12:
                case 13:
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
                                query6();
                                break;
                            case 7:
                                query7();
                                break;
                            case 8:
                                query8();
                                break;
                            case 9:
                                query9();
                                break;
                            case 10:
                                query10();
                                break;
                            case 11:
                                query11();
                                break;
                            case 12:
                                query12(filevendas);
                                break;
                            case 13:
                                query13();
                                break;
                        }
                    }
                    else
                        view.imprimeMsgErro("Dados não carregados.");
                    view.enterParaContinuar();
                    break;
                case 14:
                    view.quebraDeLinha();
                    if(dados == true)
                        this.serialize_model();
                    else
                        this.view.imprimeMsgErro("Os dados não foram carregados.");
                    view.imprimeMsgInfo("VendUM encerrada!");
                    break;
                case 0:
                    this.view.quebraDeLinha();
                    view.imprimeMsgInfo("VendUM encerrada!");
                    break;
                default:
                    view.imprimeMsgErro("Opção inválida.");
                    view.enterParaContinuar();
                    break;
            }
        }
    }

    private boolean query1(StringBuilder filevendas){
        Input input = new Input();
        String tempo = null;
        String c = null;
        String p = null;
        String v = null;
        File clientes = null;
        File produtos = null;
        File vendas = null;

        int r = -1;

        boolean dados = false;

        r = view.imprimeMenuQuery1();

        switch(r){
            case 1:
                c = "../intocaveis/Clientes.txt";
                p = "../intocaveis/Produtos.txt";
                v = "../intocaveis/Vendas_5M.txt";
                clientes = new File(c);
                produtos = new File(p);
                vendas = new File(v);

                if(clientes.exists() || produtos.exists() || vendas.exists()) {
                    Crono.start();
                    model.carregaCClientes(c);
                    Crono.stop();
                    this.view.imprimeMsgInfo(Crono.print());
                    Crono.start();
                    model.carregaCProdutos(p);
                    Crono.stop();
                    this.view.imprimeMsgInfo(Crono.print());
                    Crono.start();
                    model.carregaCFiliaisCFaturacao(v);
                    Crono.stop();
                    this.view.imprimeMsgInfo(Crono.print());

                    filevendas.append(v);
                    dados = model.tudo_carregado();
                }

                break;
            case 2:
                this.carrega_ficheiros_caminho(c, p, v, clientes, produtos, vendas, filevendas);
                dados = this.model.tudo_carregado();
                break;
            case 3:
                Crono.start();
                this.deserialize_model();
                Crono.stop();
                tempo = Crono.print();
                this.view.imprimeMsgInfo(tempo);

                if(dados = this.model.tudo_carregado()){
                    this.view.imprimeMsgInfo("Nº de clientes catalogados: " + this.model.getNrclientes());
                    this.view.imprimeMsgInfo("Nº de produtos catalogados: " + this.model.getNrprodutos());
                    this.view.imprimeMsgInfo("Nº de vendas inseridas: " + this.model.getNrvendas());
                    filevendas.append("Dados.txt");
                }
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
        String tempo = null;
        int r;
        boolean next = false;

        while(!next) {
            r = this.view.imprime_menu_query2();
            next = lStrings.define_nrlinhas(r);
            if(!next)
                this.view.imprimeMsgErro("Inseriu um número pequeno (>= a 5): ");
            else{
                Crono.start();
                this.model.prods_nao_comprados(lStrings);
                Crono.stop();
                tempo = Crono.print();
                lStrings.imprime_lstrings();
                this.view.imprimeMsgInfo(tempo);
            }
        }
    }

    private void query3(){
        Input input = new Input();
        String tempo = null;
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
                    this.view.enterParaContinuar();
                }
                else if (mesfilal == 2){
                    this.view.imprimeMsgErro("Filial inválida.");
                    this.view.imprimeMsgInfo("[1]INTRODUZIR FILIAL VÁLIDA   [0]SAIR");
                    this.view.enterParaContinuar();
                }

                opcao = input.lerInt();
            }

            if(opcao == 0) {
                return;
            }

        }
        Crono.start();
        if(mesfilal == 1){
            System.out.println("Total de vendas no mês " + nr + ": " + this.model.total_vendas_mes_model(nr-1) + ".");
            System.out.println("Nº de clientes no mês " + nr + ": " + this.model.nrclientes_mes_model(nr-1) + ".");
        }
        else if(mesfilal == 2){
            System.out.println("Total de vendas da filial " + nr + ": " + this.model.total_vendas_filial_model(nr-1) + ".");
            System.out.println("Nº de clientes da filial " + nr + ": " + this.model.nrclientes_filial_model(nr-1) + ".");
        }
        Crono.stop();
        this.view.imprimeMsgInfo(Crono.print());


    }

    private void query4(){
        Input input = new Input();
        String cliente = null;
        String tempo = null;
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
                this.view.enterParaContinuar();
            }

            if(opcao == 0) {
                return;
            }


        }

        Crono.start();
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
        Crono.stop();
        tempo = Crono.print();

        this.view.imprime_tabela_query4(array);

        this.view.imprimeMsgInfo(tempo);
    }

    private void query5(){
        Input input = new Input();
        String produto = null;
        String tempo = null;
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
                this.view.enterParaContinuar();
            }

            if(opcao == 0) {
                return;
            }


        }

        Crono.start();
        this.model.quantidade_nrclientes_totfaturado_produto_model(produto, array);
        Crono.stop();
        tempo = Crono.print();

        this.view.imprime_tabela_query5(array);

        this.view.imprimeMsgInfo(tempo);
    }

    private void query6(){
        LStrings ls = new LStrings();
        MaxHeapInt heap = null;
        Input input = new Input();
        String cliente = null;
        String tempo = null;
        int opcao = -1;
        int r = 0;
        boolean next = false;

        while(!next){
            this.view.imprimeMsgInfo("Introduza um cliente válido: ");

            cliente = input.lerString();
            next = this.model.existe_cliente_model_cfiliais(cliente);

            if(!next){
                this.view.imprimeMsgErro("O cliente não fez compras.");
                this.view.imprimeMsgInfo("[1]INTRODUZIR NOVO CLIENTE   [0]SAIR");
                opcao = input.lerInt();
                this.view.enterParaContinuar();
            }

            if(opcao == 0) {
                return;
            }

        }
        Crono.start();
        heap = this.model.getCFiliais().produtos_mais_comprados_cliente(cliente);
        Crono.stop();
        tempo = Crono.print();
        next = false;

        while(!next) {
            r = this.view.linhas_por_pagina();
            next = ls.define_nrlinhas(r);
            if(!next)
                this.view.imprimeMsgErro("Inseriu um número pequeno (>= a 5)!");
            else{
                ls.maxheapint_to_lstrings(heap);
                ls.imprime_lstrings();
                this.view.imprimeMsgInfo(tempo);
            }
        }

    }

    private void query7(){
        String tempo = null;
        Crono.start();
        Crono.stop();
        tempo = Crono.print();
        this.view.imprimeMsgInfo(tempo);
    }

    private void query8(){
        MaxHeapDouble heap = null;
        LStrings ls = new LStrings();
        String tempo = null;
        boolean next = false;
        int r = 0;
        int l = 0;

        while(!next) {
            r = this.view.nr_filial();
            if(r == 1 || r == 2 || r == 3)
                break;
            else
                next = false;

            if(!next)
                this.view.imprimeMsgErro("Inseriu uma filial inválida! ");
        }

        Crono.start();
        heap = this.model.clientes_mais_compradores_filial(r);
        Crono.stop();
        tempo = Crono.print();

        ls.maxheapdouble_to_lstrings(heap);
        
        System.out.println(ls.getPosicaoLstrings(0));
        System.out.println(ls.getPosicaoLstrings(1));
        System.out.println(ls.getPosicaoLstrings(2));

        this.view.imprimeMsgInfo(tempo);
    }

    private void query9(){
        MaxHeapInt heap = null;
        LStrings ls = new LStrings();
        String tempo = null;
        int r = 0;
        int l = 0;
        boolean next = false;

        while(!next) {
            r = this.view.nr_clientes();
            if(r <= 0)
                next = false;
            else
                break;
            if(!next)
                this.view.imprimeMsgErro("Inseriu um número inválido!");
        }

        next = false;

        while(!next) {
            l = this.view.linhas_por_pagina();
            next = ls.define_nrlinhas(l);
            if(!next)
                this.view.imprimeMsgErro("Inseriu um número pequeno (>= a 5)!");
        }

        Crono.start();
        heap = this.model.clientes_mais_variadores();
        Crono.stop();
        tempo = Crono.print();

        ls.maxheapint_to_lstrings_netneilc(heap);
        if(ls.getNrstrings() < r){
            this.view.imprimeMsgErro("Número de elementos do TOP demasiado elevado.");
            return;
        }

        ls.setNrstrings(r);
        ls.imprime_lstrings();

        this.view.imprimeMsgInfo(tempo);
    }

    private void query10(){
        Input input = new Input();
        String produto = null;
        String tempo = null;
        MaxHeapInt heap = null;
        LStrings ls = new LStrings();
        int opcao = -1;
        int r = 0;
        boolean next = false;

        while(!next){
            this.view.imprimeMsgInfo("Introduza um produto válido: ");

            produto = input.lerString();
            next = model.existe_produto_model_cfaturacao(produto);

            if(!next) {
                this.view.imprimeMsgErro("O produto não foi comprado.");
                this.view.imprimeMsgInfo("[1]INTRODUZIR NOVO PRODUTO   [0]SAIR");
                opcao = input.lerInt();
                this.view.enterParaContinuar();
            }

            if(opcao == 0) {
                return;
            }
        }

        Crono.start();
        heap = this.model.getCFiliais().clientes_mais_compradores_produto(produto);
        Crono.stop();
        tempo = Crono.print();

        next = false;

        while(!next) {
            r = this.view.linhas_por_pagina();
            next = ls.define_nrlinhas(r);
            if(!next)
                this.view.imprimeMsgErro("Inseriu um número pequeno (>= a 5): ");
            else{
                ls.maxheapint_to_lstrings_etneilc(heap);
                ls.imprime_lstrings();
                this.view.imprimeMsgInfo(tempo);
            }
        }

    }

    private void query11(){
        Input input = new Input();
        double[][] array = null;
        String produto = null;
        String tempo = null;
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

        Crono.start();
        array = this.model.faturacao_meses_filiais_model(produto);
        Crono.stop();
        tempo = Crono.print();

        this.view.imprime_tabela_faturacao(array);

        this.view.imprimeMsgInfo(tempo);
    }

    private void query12(StringBuilder filevendas){
        this.constroi_apresenta_estatisticas_anteriores(filevendas);
    }

    private void query13(){
        Input input = new Input();

        int r = -1;

        r = view.imprimeMenuQuery13();

        switch(r){
            case 1:
                this.constroi_apresenta_estatisticas_atuais1();
                break;
            case 2:
                this.constroi_apresenta_estatisticas_atuais2();
                break;
            case 3:
                this.constroi_apresenta_estatisticas_atuais3();
                break;
            case 0:
                view.imprimeMsgInfo("Sairá do menu de estatísticas atuais.");
                break;
            default:
                view.imprimeMsgErro("Opção inválida.");
                view.enterParaContinuar();
                break;
        }
    }

    public void setModel(GereVendasModel model){
        this.model = model;
    }

    public void setView(GereVendasView view){
        this.view = view;
    }

    private boolean carrega_ficheiros_caminho(String c, String p, String v, File clientes, File produtos, File vendas, StringBuilder filevendas){
        Input input = new Input();

        while(true) {
            this.view.imprimeMsgInfo("\nInsira caminho do ficheiro \"clientes\":");
            c = input.lerString();
            clientes = new File(c);
            if (clientes.exists()) {
                Crono.start();
                model.carregaCClientes(c);
                Crono.stop();
                this.view.imprimeMsgInfo(Crono.print());
                break;
            }
            else {
                this.view.imprimeMsgErro("Inseriu caminho errado!");
                this.view.imprimeMsgErro("[1]INTRODUZIR NOVO CAMINHO   [0]SAIR");
                switch (input.lerInt()){
                    case 1:
                        break;
                    default:
                        return false;
                }
            }
        }


        while(true) {
            this.view.imprimeMsgInfo("\nInsira caminho do ficheiro \"produtos\":");
            p = input.lerString();
            produtos = new File(p);
            if (produtos.exists()) {
                Crono.start();
                model.carregaCProdutos(p);
                Crono.stop();
                this.view.imprimeMsgInfo(Crono.print());
                break;
            }
            else {
                this.view.imprimeMsgErro("Inseriu caminho errado!");
                this.view.imprimeMsgErro("[1]INTRODUZIR NOVO CAMINHO   [0]SAIR");
                switch (input.lerInt()){
                    case 1:
                        break;
                    default:
                        return false;
                }
            }
        }

        while(true) {
            this.view.imprimeMsgInfo("\nInsira caminho do ficheiro \"vendas\":");
            v = input.lerString();
            vendas = new File(v);
            if (vendas.exists()) {
                Crono.start();
                model.carregaCFiliaisCFaturacao(v);
                Crono.stop();
                this.view.imprimeMsgInfo(Crono.print());
                filevendas.append(v);
                break;
            }
            else {
                this.view.imprimeMsgErro("Inseriu caminho errado!");
                this.view.imprimeMsgErro("[1]INTRODUZIR NOVO CAMINHO   [0]SAIR");
                switch (input.lerInt()){
                    case 1:
                        break;
                    default:
                        return false;
                }
            }
        }

        return true;
    }

    public void deserialize_model(){
        String filename = "../Objects/Dados.txt";
        try{
            FileInputStream file = new FileInputStream(filename);
            ObjectInputStream in = new ObjectInputStream(file);

            this.model = (GereVendasModel) in.readObject();

            in.close();
            file.close();
            System.out.println("Os dados foram carregados da memória.");

        }
        catch (IOException ex){System.out.println("Não existem dados em memória.");}
        catch (ClassNotFoundException ex){System.out.println("Classe não encontrada");}
    }

    public void serialize_model(){
        String filename = "../Objects/Dados.txt";
        try{
            FileOutputStream file = new FileOutputStream(filename);
            ObjectOutputStream out = new ObjectOutputStream(file);

            out.writeObject(this.model);

            out.close();
            file.close();
            System.out.println("Os dados foram guardados em memória.");

        }catch (IOException ex){System.out.println("Não foi possível guardar dados em memória.");}

        this.model = null;
    }

    private void constroi_apresenta_estatisticas_anteriores(StringBuilder filevendas){
        int registosvenda = this.model.getNrvendasErradas();
        int nprods = this.model.getNrprodutos();
        int nprodscompr = this.model.getNrprodutosComprados();
        int nprodsncompr = nprods - nprodscompr;
        int nclis = this.model.getNrclientes();
        int ncliscompr = this.model.getNrclientesCompradores();
        int nclisncompr = nclis - ncliscompr;

        this.view.imprimeMsgInfo("Ficheiro de dados das vendas: " + filevendas);
        this.view.imprimeMsgInfo("Nº de registos de venda errados: " + registosvenda + "\n");
        this.view.imprimeMsgInfo("Nº de produtos: " + nprods);
        this.view.imprimeMsgInfo("Nº de produtos (distintos) comprados: " + nprodscompr);
        this.view.imprimeMsgInfo("Nº de produtos não comprados: " + nprodsncompr + "\n");
        this.view.imprimeMsgInfo("Nº de clientes: " + this.model.getNrclientes());
        this.view.imprimeMsgInfo("Nº de clientes (distintos) que compraram produtos: " + ncliscompr);
        this.view.imprimeMsgInfo("Nº de cliente que não compraram produtos: " + nclisncompr + "\n");
        this.view.imprimeMsgInfo("Nº de compras de valor 0.0: " + this.model.getVendasValorZero());
        this.view.imprimeMsgInfo("Faturação total: " + this.model.getFaturacaoTotal());
    }

    private void constroi_apresenta_estatisticas_atuais1(){
        int[] nrcomprasmes = new int[Globais.NRMESES];
        this.model.nr_compras_mes(nrcomprasmes);
        this.view.imprime_array_inteiros_mensal(nrcomprasmes);
    }

    private void constroi_apresenta_estatisticas_atuais2(){
        double[][] array = new double[Globais.NRMESES][Globais.NRFILIAIS];
        this.model.fat_mes_filial(array);
        this.view.imprime_tabela_faturacao_total(array);
    }

    private void constroi_apresenta_estatisticas_atuais3(){
        int[][] nrclientesmesfilial = new int[Globais.NRMESES][Globais.NRFILIAIS];
        this.model.nr_clientes_distintos_mes_filial(nrclientesmesfilial);
        this.view.imprime_tabela_inteiros(nrclientesmesfilial);
    }
}

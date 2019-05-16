public interface IVenda {
    /*String getCodigo();
    int getQuant();
    double getPreco();
    double getValor();*/
    Venda venda_valida(CClientes cclientes, CProdutos cprodutos, String linha);

}

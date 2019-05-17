import java.util.ArrayList;
import java.util.List;

public class LStrings {
    private List<String> lstrings;
    private int nrstrings;
    private int nrlinhas;

    public LStrings(){
        this.lstrings = new ArrayList<>();
        this.nrstrings = 0;
        this.nrlinhas = 20;
    }

    public boolean regista_entrada(String string){
        if(true == this.lstrings.add(string)){
            this.nrstrings++;
            return true;
        }

        return false;
    }

    public boolean define_nrlinhas(int nrlinhas){
        if(nrlinhas >=5) {
            this.nrlinhas = nrlinhas;
            return true;
        }

        return false;
    }

    public void imprime_lstrings(){
        GereVendasView view = new GereVendasView();
        Input input = new Input();

        int indice = 0;
        int pagatual = 0;
        int totpag = 0;
        int opcao = -1;

        if((this.nrstrings % this.nrlinhas) == 0)
            totpag = this.nrstrings/this.nrlinhas;
        else
            totpag = this.nrstrings/nrlinhas + 1;

        while(opcao != 0) {

            for(indice = pagatual*this.nrlinhas; indice < (pagatual*this.nrlinhas + 10) && indice < nrstrings; indice ++)
                System.out.println(this.lstrings.get(indice));

            System.out.println("\n[1]PRÓXIMA   [2]ANTERIOR   [3]ÚLTIMA   [4]PRIMEIRA   [0]SAIR");
            System.out.println("Página " + pagatual + " de " + (totpag-1) + ".");
            System.out.println(lstrings.size() + " resultados.");

            opcao = input.lerInt();

            switch(opcao){
                case 1:
                    if(pagatual < totpag - 1)
                        pagatual++;
                    break;
                case 2:
                    if(pagatual > 0)
                        pagatual--;
                    break;
                case 3:
                    pagatual = totpag - 1;
                    break;
                case 4:
                    pagatual = 0;
                    break;
                case 0:
                    opcao = 0;
                    break;
                default:
                    System.out.println("Inseriu uma opção errada.");
                    break;
            }

            //view.enterParaContinuar();
        }

    }



}

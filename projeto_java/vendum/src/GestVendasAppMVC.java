import com.sun.glass.ui.SystemClipboard;

import java.io.IOException;
import java.nio.file.Files;
import java.util.*;
import java.io.*;
import java.lang.*;
import java.nio.file.*;





public class GestVendasAppMVC{
    public static void main(String [] args){

        GereVendasModel model = new GereVendasModel(); //model

        if(model==null){
            System.out.println("Error in model layer!");
            System.exit(-1);
        }

        GereVendasView view = new GereVendasView(); //view

        if(view==null){
            System.out.println("Error in view layer!");
            System.exit(-1);
        }

        GereVendasController control = new GereVendasController(); //controller

        if(control==null){
            System.out.println("Error in control layer!");
            System.exit(-1);
        }

        control.setModel(model);
        control.setView(view);
        control.startController();

        System.exit(0);
    }
}

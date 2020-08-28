import java.util.Scanner;
import java.util.TreeMap;
 
 
public class P1746 {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        TreeMap<String,Long> datos =new TreeMap<String,Long>();
        while(in.hasNext()) {
            //System.out.println(datos);
            String comando=in.next();
            long numero=0,value=0,menosuno=-1, x=0;
            if (comando.equals("END")) {
                System.out.println(datos);
                datos.clear();
                }
 
            if (comando.equals("R")) {
                String nombre=in.next();
                value=(in.nextLong());
                if(datos.containsKey(nombre)) {
                    x=datos.get(nombre);
                    value+=x;   
                }
                datos.put(nombre, value);
            }
            if (comando.equals("G")) {
                String nombre=in.next();
                value=in.nextLong()*menosuno;
                if(datos.containsKey(nombre)) {
                    x=datos.get(nombre);
                    value+=x;   
                }
                datos.put(nombre, value);
            }
            if (comando.equals("P")) {
                String nombre=in.next();
                value=in.nextLong();
                String nombre2=in.next();
        //System.out.println("P "+nombre+" "+value+" "+nombre2);
 
                if(datos.containsKey(nombre)) {
                    x=datos.get(nombre);
                    value=x-value;
                    datos.put(nombre, value);
                } else {
                datos.put(nombre, value*menosuno);
                }
                if(datos.containsKey(nombre2)) {
                    x=datos.get(nombre2);
                    value+=x;   
                }
                datos.put(nombre2, value);
            }
        }
    }
}

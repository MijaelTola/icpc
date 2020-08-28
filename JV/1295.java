import java.util.Scanner;
public class Main
{
    public static void main(String[] args) 
    {
        Scanner leer=new Scanner(System.in);
        char abecedario[]=new char[27];
        for (int j = 0; j <26; j++) 
        {
            abecedario[j]=(char) ((char)j+97);
        }
        abecedario[26]=' ';
        int c=1;
        while(leer.hasNext())
        {           
            if(c!=1)
            {
            System.out.println();   
            //System.out.println();
            }           
            int codigo[]=new int[26];
            String cad = leer.nextLine();
            for (int j = 0; j <cad.length(); j++) 
            {
                codigo[j]=cad.charAt(j);
            }
            String n=leer.nextLine();
            int N=Integer.parseInt(n);
            for (int j = 1; j <= N; j++) 
            {
                String cadena = leer.nextLine();
                int linea[]=new int[cadena.length()];
                int posicion[]=new int[cadena.length()];
                for (int i = 0; i <cadena.length(); i++) 
                {
                    linea[i]=cadena.charAt(i);
                }
                for (int k = 0; k <cadena.length(); k++) 
                {
                    for (int l = 0; l <26; l++) 
                    {
                        if(linea[k]==codigo[l]||linea[k]==32)
                        {
                            if(linea[k]==codigo[l])
                            {
                                posicion[k]=l;
                            }
                            if(linea[k]==32)
                            {
                                posicion[k]=26;
                            }
                        }
                    }
                }
                for (int k = 0; k <cadena.length(); k++) 
                {
                    System.out.print(abecedario[posicion[k]]);
                }
                c++;
                //if(j!=N)
                //{
              //  System.out.println();   
                //}
            }
        }   
    }
}

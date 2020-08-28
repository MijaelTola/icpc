import java.util.Scanner;

public class P1540{
    

    // PROCEDIMIENTO 
    // FUNCIONES

    static int x1,y1,x2,y2,x3,y3;
    static Scanner in = new Scanner(System.in);   

    public static void leer() {
        x1 = in.nextInt();
        y1 = in.nextInt();
        x2 = in.nextInt();
        y2 = in.nextInt();
        x3 = in.nextInt();
        y3 = in.nextInt();
    }
    
    public static int restaDeVectores(int ax, int bx) {
        return ax - bx;
    }

public static int Cruz(int vABx, int vABy, int vCBx, int vCBy) {
    return vABx * vCBy - vABy * vCBx;
}
    public static void main(String [] args) {
        leer();
        //vector ab
        int abx = restaDeVectores(x1,x2);//ab.x
        int aby = restaDeVectores(y1,y2);//ab.y
        
        //vector cb
        int cbx = restaDeVectores(x3,x2);//ab.x
        int cby = restaDeVectores(y3,y2);//ab.y
        
        int productoCruz = Cruz(abx,aby,cbx,cby);
        double AreaT = (double)(productoCruz) / 2.0;
        AreaT = Math.abs(AreaT);
        System.out.printf("%.1f\n",AreaT);
        //Vector ab = A - B
        //Vector cb = C - B
    }
}
// A - B = A.x - B.x, A.y, B.y
//  A.x * B.y - A.y * B.x

import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception{
        int n,m;
        Scanner sc = new Scanner(System.in);
        String num = sc.nextLine();
        String splitArr[] = num.split(" ");
        n = Integer.parseInt(splitArr[0]);
        m = Integer.parseInt(splitArr[1]);
        if (m==1 || m==2){
            System.out.println("NEWBIE!");
        }
        else if(m>2 && m<=n){
            System.out.println("OLDBIE!");
        }
        else{
            System.out.println("TLE!");
        }
    }
}

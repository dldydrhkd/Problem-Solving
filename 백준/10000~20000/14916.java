import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] arr) {
        Scanner sc = new Scanner(System.in);
        String[] input = sc.nextLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);

        Queue<Integer> q = new LinkedList<>();

        for (int i=1; i<=n; i++){
            q.offer(i);
        }
        System.out.print('<');
        while(!q.isEmpty()){
            for(int i=0; i<k-1; i++){
                if(!q.isEmpty()){
                    int tmp = q.peek();
                    q.poll();
                    q.offer(tmp);
                }
            }
            if(q.size()==1){
                System.out.print(q.peek());
                System.out.print('>');
            }
            else{
                System.out.print(q.peek());
                System.out.print(", ");
            }
            q.poll();
        }
    }
}



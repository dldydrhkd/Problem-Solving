import java.util.Scanner;

public class Main{
    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        long mod = 1000000007;
        long[][] arr = new long[1001][1001];
        for(int i=1; i<1001; i++){
            arr[1][i] = 1;
            arr[i][1] = 1;
        }
        int n = sc.nextInt();
        int m = sc.nextInt();
        for(int i=2; i<=n; i++) {
            for(int j=2; j<=m; j++){
                long tmp = (arr[i-1][j] + arr[i][j-1]) % mod;
                tmp = (tmp + arr[i-1][j-1]) % mod;
                arr[i][j] = tmp;
            }
        }
        System.out.println(arr[n][m]);
    }
}
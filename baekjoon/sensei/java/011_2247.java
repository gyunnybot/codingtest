import java.io.*;

public class Main {
    static int n, ret; // 1 ≤ n ≤ 200,000,000

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        n = Integer.parseInt(br.readLine());

        for (int i = 2; i <= n; i++) { // 1 제외
            int cnt = n / i; // n!에서 i를 약수로 가지는 수의 개수

            ret += (cnt - 1) * i; // i 본인을 제외한 i를 약수로 가지는 개수 x 가중치 i
            ret %= 1000000;
        }

        System.out.println(ret);
    }
}

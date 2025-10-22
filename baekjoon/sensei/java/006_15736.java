import java.io.*;

public class Main {
    static int n, ret;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        /*
        백색 깃발이 위로 보이려면 깃발이 바뀌는 횟수가 홀수여야 한다
        어떤 수의 제곱근이 정수라면 그 수는 반드시 홀수 횟수를 가지며, 이는 모든 경우의 수를 포함한다
         */
        
        for (int i = 1; i * i <= n; i++) {
            ret++;
        }

        System.out.println(ret);
    }
}

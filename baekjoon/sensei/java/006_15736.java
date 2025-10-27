import java.io.*;

public class Main {
    static int n, ret;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        /*
        백색 깃발이 위로 보이려면 깃발이 바뀌는 횟수가 홀수여야 한다
        어떤 수 n의 제곱근이 정수로 나누어떨어진다면, n은 해당 조건을 만족한다

        n 이하의 수 중 제곱근이 정수인 수의 개수를 찾는다
         */
        
        for (int i = 1; i * i <= n; i++) {
            ret++;
        }

        System.out.println(ret);
    }
}

import java.io.*;

public class Main {
    static int n;
    static StringBuilder ret;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        int temp = n;
       
        ret = new StringBuilder();

        for (int i = 2; i * i <= n; i++) {
            while (temp % i == 0) {
                ret.append(i).append('\n');
                temp /= i;
            }
        }

        if (temp != 1) { // 유일하게 제곱근 n보다 큰 소인수가 존재한다면 출력
            ret.append(temp);
        }

        /*
        n = p * q를 만족하면서 p > sqrt(n) && q > sqrt(n)인 소수쌍 (p, q)는 존재하지 않는다
        (p, q 모두 제곱근보다 큰 소인수라면 p * q > n 이 되므로 n = p * q에 모순)
        
        즉, 임의의 p > sqrt(n)라면 나머지 소인수 q는 반드시 q < sqrt(n)이어야 한다. 또는 p = q = sqrt(n)
        
        제곱근보다 큰 소인수는 많아봐야 최대 한 개이다
        */
       
        System.out.println(ret);
    }
}

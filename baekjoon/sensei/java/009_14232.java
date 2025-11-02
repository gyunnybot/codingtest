import java.io.*;

public class Main {
    static long n, cnt;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Long.parseLong(br.readLine());

        long temp = n;
        
        StringBuilder ret = new StringBuilder();

        for (long i = 2; i * i <= n; i++) {
            while (temp % i == 0) {
                ret.append(i).append(' ');
                temp /= i;

                cnt++;
            }
        }

        if (temp != 1) {
            ret.append(temp);
            cnt++;
        }

        System.out.println(cnt + "\n" + ret);
    }
}

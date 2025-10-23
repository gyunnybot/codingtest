import java.io.*;
import java.util.*;

public class Main {
    static long n, ret;
    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Long.parseLong(br.readLine());

        long temp = n;
        sb = new StringBuilder();

        for (long i = 2; i * i <= n; i++) {
            while (temp % i == 0) {
                sb.append(i).append(' ');
                temp /= i;

                ret++;
            }
        }

        if (temp != 1) {
            sb.append(temp);
            ret++;
        }

        System.out.println(ret + "\n" + sb);
    }
}

import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        int temp = n;
        sb = new StringBuilder();

        for (int i = 2; i * i <= n; i++) {
            while (temp % i == 0) {
                sb.append(i).append('\n');
                temp /= i;
            }
        }

        if (temp != 1) {
            sb.append(temp);
        }

        System.out.println(sb);
    }
}

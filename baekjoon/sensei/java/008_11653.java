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

        if (temp != 1) {
            ret.append(temp);
        }

        System.out.println(ret);
    }
}

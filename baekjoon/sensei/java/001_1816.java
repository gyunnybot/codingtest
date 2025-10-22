import java.io.*;

public class Main {
    static int n;
    static long s;
    static boolean flag;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            flag = true;

            s = Long.parseLong(br.readLine()); // 10^12 ~ 10^18

            for (long l = 2; l <= 1000000; l++) {
                if (s % l == 0) {
                    flag = false; // 적절하지 못한 암호 키
                    break;
                }
            }

            if (flag) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}

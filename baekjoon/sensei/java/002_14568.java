import java.io.*;

public class Main {
    static int n, ret;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        n = Integer.parseInt(br.readLine());

        for (int a = 1; a <= n; a++) { // 태희
            for (int b = 1; b <= n; b++) { // 영훈
                for (int c = 1; c <= n; c++) { // 남규
                    if (a % 2 == 1) continue;

                    if (c >= b + 2 && a + b + c == n) {
                        ret++;
                    }
                }
            }
        }

        System.out.println(ret);
    }
}

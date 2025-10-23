import java.io.*;
import java.util.*;

public class Main {
    static int n, ret;
    static boolean[] chae = new boolean[1001];
    static StringTokenizer inputNumbers;

    // 에라토스테네스의 체
    static void era(int num) {
        chae[0] = false;
        chae[1] = false;

        for (int i = 2; i <= num; i++) {
            chae[i] = true;
        }

        for (int i = 2; i <= num; i++) {
            if (!chae[i]) continue;

            for (int j = i + i; j <= num; j += i) {
                chae[j] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        era(1000);

        inputNumbers = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            if (chae[Integer.parseInt(inputNumbers.nextToken())]) {
                ret++;
            }
        }

        System.out.println(ret);
    }
}

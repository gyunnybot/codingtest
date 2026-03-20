/**
 * 시간복잡도 O(N + 1000*log(log1000)(에라토스테네스의 체))
 */

import java.util.*;
import java.io.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static int n, ret;
    static boolean[] chae = new boolean[1001];

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();

        era(1000);

        for (int i = 0; i < n; i++) {
            int num = cs.nextInt();

            if (chae[num]) {
                ret++;
            }
        }

        System.out.println(ret);
    }

    // 에라토스테네스의 체
    static void era(int num) {
        chae[0] = false;
        chae[1] = false;

        for (int i = 2; i <= num; i++) {
            chae[i] = true;
        }

        for (int i = 2; i <= num; i++) {
            if (!chae[i]) {
                continue;
            }

            for (int j = i + i; j <= num; j += i) {
                chae[j] = false;
            }
        }
    }

    static class CustomScanner {
        private final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        private StringTokenizer st;

        String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                String line = br.readLine();

                if (line.isEmpty()) {
                    continue;
                }

                st = new StringTokenizer(line);
            }

            return st.nextToken();
        }

        int nextInt() throws IOException {
            String s = next();

            return Integer.parseInt(s);
        }

        long nextLong() throws IOException {
            String s = next();

            return Long.parseLong(s);
        }
    }
}

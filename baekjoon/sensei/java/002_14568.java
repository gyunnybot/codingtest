/**
 * 시간복잡도 O(N^3)
 */

import java.io.*;
import java.util.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static int n, ret;

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();

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

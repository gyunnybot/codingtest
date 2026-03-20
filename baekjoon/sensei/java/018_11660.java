/**
 * 시간복잡도 O((10^3)^2 + 10^5)
 */

import java.io.*;
import java.util.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static StringBuilder ret = new StringBuilder();
    static int n, m, a1, a2, b1, b2;
    static int[][] a = new int[1025][1025];
    static int[][] s = new int[1025][1025];

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();
        m = cs.nextInt();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = cs.nextInt();
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            a1 = cs.nextInt();
            b1 = cs.nextInt();
            a2 = cs.nextInt();
            b2 = cs.nextInt();

            ret.append(s[a2][b2] - s[a1 - 1][b2] - s[a2][b1 - 1] + s[a1 - 1][b1 - 1]).append("\n");
        }

        System.out.println(ret.toString());
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

        Integer nextInt() throws IOException {
            String s = next();

            return Integer.parseInt(s);
        }

        Long nextLong() throws IOException {
            String s = next();

            return Long.parseLong(s);
        }
    }
}

/**
 * 시간복잡도 O(N)
 */

import java.util.*;
import java.io.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static int n, k;
    static int ret = -10000001;
    static int[] a = new int[100001];
    static int[] s = new int[100001];

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();
        k = cs.nextInt();

        for (int i = 1; i <= n; i++) {
            a[i] = cs.nextInt();
            s[i] = s[i - 1] + a[i]; // 무지성 누적합
        }

        for (int i = k; i <= n; i++) {
            ret = Math.max(ret, s[i] - s[i - k]);
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

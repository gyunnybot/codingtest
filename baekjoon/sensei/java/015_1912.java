/**
 * 시간복잡도 O(N)
 */

import java.util.*;
import java.io.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static int n;
    static int ret = -1001;
    static int[] a = new int[100001];
    static int[] s = new int[100001];

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();

        for (int i = 1; i <= n; i++) {
            a[i] = cs.nextInt();
            s[i] = s[i - 1] + a[i];

            s[i] = Math.max(s[i], a[i]); // 그 순간에 최대 누적합을 저장
        }

        for (int i = 1; i <= n; i++) {
            ret = Math.max(ret, s[i]);
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

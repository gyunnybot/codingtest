/**
 * 시간복잡도 O(N * 10^6)
 */

import java.io.*;
import java.util.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static StringBuilder ret = new StringBuilder();
    static int n;
    static long s;
    static boolean flag;

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();

        for (int i = 0; i < n; i++) {
            flag = true;

            s = cs.nextLong();

            for (long j = 2; j <= 1000000; j++) {
                if (s % j == 0) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                ret.append("YES\n");
            } else {
                ret.append("NO\n");
            }
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

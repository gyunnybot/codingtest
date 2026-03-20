/**
 * 시간복잡도 O(2000^2)
 */

import java.io.*;
import java.util.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static int a, b, c, d, e, f;

    public static void main(String[] args) throws IOException {
        a = cs.nextInt();
        b = cs.nextInt();
        c = cs.nextInt();
        d = cs.nextInt();
        e = cs.nextInt();
        f = cs.nextInt();

        for (int x = -999; x <= 999; x++) {
            for (int y = -999; y <= 999; y++) {
                if (a * x + b * y == c && d * x + e * y == f) {
                    System.out.println(x + " " + y);
                    break;
                }
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

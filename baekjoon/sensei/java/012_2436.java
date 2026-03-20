/**
 * 시간복잡도 O(sqrt(N)*logN)
 */

import java.util.*;
import java.io.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static int gcd, lcm, retA, retB;

    public static void main(String[] args) throws IOException {
        gcd = cs.nextInt();
        lcm = cs.nextInt();

        int product = lcm / gcd;

        for (int i = 1; i * i <= product; i++) {
            if (product % i == 0) {
                int a = i;
                int b = product / i;

                if (getGcd(a, b) == 1) {
                    retA = a * gcd;
                    retB = b * gcd;
                }
            }
        }
        
        System.out.println(retA + " " + retB);
    }

    static int getGcd(int a, int b) {
        if (a == 0) {
            return b;
        }

        return getGcd(b % a, a);
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

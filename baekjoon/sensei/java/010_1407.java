/**
 * 시간복잡도 O(logN)
 */

import java.util.*;
import java.io.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static long a, b, ret;

    public static void main(String[] args) throws IOException {
        a = cs.nextLong();
        b = cs.nextLong();

        System.out.println(calculate(b) - calculate(a - 1));
    }

    static long calculate(long n) {
        long temp = n; // 모든 수는 1을 약수로 가지고 있다

        for (long i = 2; i <= n; i *= 2) {
            temp += (n / i) * (i / 2); // 1~n에서 i를 약수로 가지는 수의 개수 * 가중치
        }

        return temp;
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

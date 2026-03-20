/**
 * 제곱근 이하의 수는 항상 제곱근 이상의 수와 곱해져 num이 된다
 * 따라서 제곱근까지만 조사해도 전체 경우의 수를 탐색하게 된다
 *
 * 시간복잡도 O(N * sqrt(N))
 */

import java.util.*;
import java.io.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static int n, ret;

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();

        for (int i = 0; i < n; i++) {
            int num = cs.nextInt();

            if (check(num)) {
                ret++;
            }
        }

        System.out.println(ret);
    }

    static boolean check(int num) {
        if (num <= 1) {
            return false;
        }

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
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

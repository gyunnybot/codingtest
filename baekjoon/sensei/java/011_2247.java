/**
 * 시간복잡도 O(N)
 */

import java.util.*;
import java.io.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static int n, ret;

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();

        for (int i = 2; i <= n; i++) { // 1 제외
            int cnt = n / i; // 1~n에서 i를 약수로 가지는 수의 개수

            ret += (cnt - 1) * i; // 본인 제외 * 약수 가중치
            ret %= 1000000; // mod
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

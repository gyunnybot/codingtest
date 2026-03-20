/**
 * 시간복잡도 O(sqrt(N)(for) + logN(while))
 */

import java.util.*;
import java.io.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static StringBuilder ret = new StringBuilder();
    static int n, cnt;

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();

        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                ret.append(i).append(" ");

                n /= i;

                cnt++;
            }
        }

        if (n > 1) { // 유일하게 제곱근 n보다 큰 소인수가 존재한다면 출력
            ret.append(n);

            cnt++;
        }

        System.out.println(cnt + "\n" + ret);
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

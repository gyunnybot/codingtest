/**
 * 시간복잡도 O(N)
 */

import java.util.*;
import java.io.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static int n, l, h, maxVal, maxPos, ret;
    static int[] a = new int[1001];

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();

        for (int i = 0; i < n; i++) {
            l = cs.nextInt();
            h = cs.nextInt();

            a[l] = h;

            if (maxVal <= h) {
                maxVal = h;
                maxPos = l;
            }
        }

        // pos는 1부터 1000까지
        for (int i = 2; i < maxPos; i++) {
            if (a[i - 1] > a[i]) {
                a[i] = a[i - 1];
            }
        }

        for (int i = 999; i > maxPos; i--) {
            if (a[i + 1] > a[i]) {
                a[i] = a[i + 1];
            }
        }

        for (int i = 1; i <= 1000; i++) {
            ret += a[i];
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

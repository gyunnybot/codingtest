/**
 * 시간복잡도 O(N)
 */

import java.util.*;
import java.io.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static int[] a = new int[501];
    static int h, w, maxVal, maxPos, ret;

    public static void main(String[] args) throws IOException {
        h = cs.nextInt();
        w = cs.nextInt();

        for (int i = 0; i < w; i++) {
            a[i] = cs.nextInt();

            if (maxVal <= a[i]) {
                maxVal= a[i];
                maxPos = i;
            }
        }

        for (int i = 1; i < maxPos; i++) {
            if (a[i - 1] > a[i]) {
                ret += a[i - 1] - a[i];
                a[i] = a[i - 1];
            }
        }

        for (int i = w - 1; i > maxPos; i--) {
            if (a[i] > a[i - 1]) {
                ret += a[i] - a[i - 1];
                a[i - 1] = a[i];
            }
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

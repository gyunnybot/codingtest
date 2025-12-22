import java.io.*;
import java.util.*;

public class Main {
    static CustomScanner cs = new CustomScanner();

    static int n, h, ret;

    static int[] a = new int[500001];
    static int[] s = new int[500001];

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();
        h = cs.nextInt();

        for (int i = 0; i < n; i++) {
            int temp = cs.nextInt();

            if (i % 2 == 0) {
                a[1]++;
                a[temp + 1]--;
            } else {
                a[h - temp + 1]++;
            }
        }

        for (int i = 1; i <= h; i++) {
            s[i] = s[i - 1] + a[i];
        }

        int minVal = 200001;

        for (int i = 1; i <= h; i++) {
            minVal = Math.min(minVal, s[i]);
        }

        for (int i = 1; i <= h; i++) {
            if (s[i] == minVal) {
                ret++;
            }
        }

        System.out.println(minVal + " " + ret);
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

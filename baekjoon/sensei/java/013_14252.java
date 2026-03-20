/**
 * 시간복잡도 O(N * 10^5 * log(10^5))
 */

import java.util.*;
import java.io.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static int n, ret;

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = cs.nextInt();
        }

        Arrays.sort(arr);

        for (int i = 0; i < n - 1; i++) {
            if (getGcd(arr[i], arr[i + 1]) == 1) {
                continue;
            }

            for (int j = arr[i] + 1; j < arr[i + 1]; j++) {
                if (getGcd(arr[i], j) == 1) {
                    if (getGcd(j, arr[i + 1]) == 1) {
                        ret++;
                        break;
                    }
                }

                if (j == arr[i + 1] - 1) {
                    ret += 2; // https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity
                }
            }
        }

        System.out.println(ret);
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

import java.io.*;
import java.util.*;

public class Main {
    static CustomScanner cs = new CustomScanner();

    static int n, ret;

    static int[] a_x = new int[1000001];
    static int[] a_y = new int[1000001];
    static int[] s_x = new int[1000001];
    static int[] s_y = new int[1000001];
    static Pos[] poses = new Pos[100001];

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();

        for (int i = 0; i < n; i++) {
            int x = cs.nextInt();
            int y = cs.nextInt();

            x += 500000;
            y += 500000;

            poses[i] = new Pos(x, y);
        }

        for (int i = 0; i < n; i++) {
            int x = poses[i].x;
            int y = poses[i].y;
            
            int nx = poses[(i + 1) % n].x; // n-1 -> 0
            int ny = poses[(i + 1) % n].y;

            if (x == nx) {
                int max_y = Math.max(y, ny);
                int min_y = Math.min(y, ny);

                a_y[max_y]--;
                a_y[min_y]++;
            } else {
                int max_x = Math.max(x, nx);
                int min_x = Math.min(x, nx);

                a_x[max_x]--;
                a_x[min_x]++;
            }
        }

        for (int i = 1; i < 1000001; i++) {
            s_x[i] = s_x[i - 1] + a_x[i - 1];
            s_y[i] = s_y[i - 1] + a_y[i - 1];
        }

        for (int i = 1; i < 1000001; i++) {
            ret = Math.max(ret, Math.max(s_x[i], s_y[i]));
        }

        System.out.println(ret);
    }

    static class Pos {
        int x, y;

        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
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

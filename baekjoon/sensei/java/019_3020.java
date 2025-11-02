import java.io.*;
import java.util.*; // StringTokenizer

public class Main {
    static int n, h, ret;
    static int[] a = new int[500001];
    static int[] s = new int[500001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer inputNH = new StringTokenizer(br.readLine());
        n = Integer.parseInt(inputNH.nextToken());
        h = Integer.parseInt(inputNH.nextToken());

        for (int i = 0; i < n; i++) {
            int temp = Integer.parseInt(br.readLine());

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
}


import java.io.*;
import java.util.*;

public class Main {
    static int l, h, maxVal, maxPos;
    static int[] a = new int[1001];
    static int[] s = new int[1001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            StringTokenizer inputLH = new StringTokenizer(br.readLine());

            l = Integer.parseInt(inputLH.nextToken());
            h = Integer.parseInt(inputLH.nextToken());

            a[l] = h;

            if (h >= maxVal) {
                maxVal = h;
                maxPos = l;
            }
        }

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
            s[i] = s[i - 1] + a[i];
        }

        System.out.println(s[1000]);
    }
}

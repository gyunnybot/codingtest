
import java.io.*;
import java.util.*;

public class Main {
    static int h, w, maxVal, maxPos;
    static int[] a = new int[501];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer inputHW = new StringTokenizer(br.readLine());

        h = Integer.parseInt(inputHW.nextToken());
        w = Integer.parseInt(inputHW.nextToken());

        StringTokenizer inputValues = new StringTokenizer(br.readLine());

        for (int i = 0; i < w; i++) {
            a[i] = Integer.parseInt(inputValues.nextToken());

            if (maxVal <= a[i]) {
                maxVal = a[i];
                maxPos = i;
            }
        }

        int sum = 0;

        for (int i = 1; i < maxPos; i++) {
            if (a[i - 1] > a[i]) {
                sum += (a[i - 1] - a[i]);
                a[i] = a[i - 1];
            }
        }

        for (int i = w - 1; i > maxPos; i--) {
            if (a[i] > a[i - 1]) {
                sum += (a[i] - a[i - 1]);
                a[i - 1] = a[i];
            }
        }

        System.out.println(sum);
    }
}

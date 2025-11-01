import java.io.*;
import java.util.*;

public class Main {
    static int n, ret;
    static int[] arr = new int[100001];
    static int[] sum = new int[100001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        StringTokenizer inputArrElements = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(inputArrElements.nextToken());
            sum[i] = sum[i - 1] + arr[i];

            sum[i] = Math.max(sum[i], arr[i]);
        }

        ret = sum[1];

        for (int i = 2; i <= n; i++) {
            ret = Math.max(ret, sum[i]);
        }

        System.out.println(ret);
    }
}

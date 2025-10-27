import java.io.*;
import java.util.*;

public class Main {
    static int n, k;
    static int ret = -100000001;
    static int[] arr = new int[100001];
    static int[] sum = new int[100001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer inputNK = new StringTokenizer(br.readLine());
        n = Integer.parseInt(inputNK.nextToken());
        k = Integer.parseInt(inputNK.nextToken());

        StringTokenizer inputArrElements = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(inputArrElements.nextToken());
            sum[i] = sum[i - 1] + arr[i];
        }

        for (int i = k; i <= n; i++) {
            ret = Math.max(ret, sum[i] - sum[i - k]);
        }

        System.out.println(ret);
    }
}

import java.io.*;
import java.util.*;

public class Main {
    static int n, ret;
    static int[] arr = new int[51];

    static int getGcd(int a, int b) {
        if (a == 0) return b;

        return getGcd(b % a, a);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // input
        n = Integer.parseInt(br.readLine());
        StringTokenizer inputNumbers = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(inputNumbers.nextToken());
        }

        Arrays.sort(arr, 0, n); // static 으로 선언한 배열은 0으로 초기화된다. 정렬 범위 지정 필수!

        for (int i = 0; i < n - 1; i++) {
            if (getGcd(arr[i], arr[i + 1]) == 1) continue;

            for (int j = arr[i] + 1; j < arr[i + 1]; j++) {
                if (getGcd(arr[i], j) == 1) {
                    if (getGcd(j, arr[i + 1]) == 1) {
                        ret++;
                        break;
                    }
                }

                if (j == arr[i + 1] - 1) {
                    ret += 2; // https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity
                    break;
                }
            }
        }

        System.out.println(ret);
    }
}

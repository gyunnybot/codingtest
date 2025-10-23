import java.io.*;
import java.util.*;

public class Main {
    static int n, ret;
    static StringTokenizer inputNumbers;

    static boolean check(int num) {
        if (num <= 1) return false;

        /*
        소수를 찾는 과정에서 제곱근 이하의 수는 항상 제곱근 이상의 수와 곱해져 num이 된다
	    따라서 제곱근까지만 조사해도 전체 경우의 수를 탐색하게 된다
         */

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        inputNumbers = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            if (check(Integer.parseInt(inputNumbers.nextToken()))) {
                ret++;
            }
        }

        System.out.println(ret);
    }
}

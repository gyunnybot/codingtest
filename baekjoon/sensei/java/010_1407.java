import java.io.*;
import java.util.*; // StringTokenizer

public class Main {
    static long a, b, ret; // 1 ≤ A ≤ B ≤ 10^15
    static StringTokenizer inputAB;

    static long func(long num) {
        long temp = num;

        for (long i = 2; i <= num; i *= 2) {
            temp += (num / i) * (i / 2);
        }

        return temp;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        inputAB = new StringTokenizer(br.readLine());

        a = Long.parseLong(inputAB.nextToken());
        b = Long.parseLong(inputAB.nextToken());

        System.out.println(func(b) - func(a - 1));
    }
}

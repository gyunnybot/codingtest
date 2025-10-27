import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int gcd, lcm, retA, retB;

    static int getGcd(int a, int b) {
        if (a == 0) return b;

        return getGcd(b % a, a);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer inputGcdLcm = new StringTokenizer(br.readLine());
        gcd = Integer.parseInt(inputGcdLcm.nextToken());
        lcm = Integer.parseInt(inputGcdLcm.nextToken());

        int productAB = lcm / gcd;

        for (int i = 1; i * i <= productAB; i++) {
            if (productAB % i == 0) { // a * b = productAB
                int a = i;
                int b = productAB / i;

                if (getGcd(a, b) == 1) {
                    retA = a * gcd;
                    retB = b * gcd;
                }
            }
        }

        System.out.println(retA + " " + retB);
    }
}

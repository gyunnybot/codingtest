import java.io.*;
import java.util.*;

public class Main {
    static int a, b, c, d, e, f;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer inputNumbers = new StringTokenizer(br.readLine());

        a = Integer.parseInt(inputNumbers.nextToken());
        b = Integer.parseInt(inputNumbers.nextToken());
        c = Integer.parseInt(inputNumbers.nextToken());
        d = Integer.parseInt(inputNumbers.nextToken());
        e = Integer.parseInt(inputNumbers.nextToken());
        f = Integer.parseInt(inputNumbers.nextToken());

        for (int x = -999; x <= 999; x++) {
            for (int y = -999; y <= 999; y++) {
                if (a * x + b * y == c && d * x + e * y == f) {
                    StringBuilder ret = new StringBuilder();

                    ret.append(x).append(' ').append(y);
                    
                    System.out.println(ret);

                    break;
                }
            }
        }
    }
}

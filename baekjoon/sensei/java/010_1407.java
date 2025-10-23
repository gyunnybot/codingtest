import java.io.*;
import java.util.*;

public class Main {
    static long a, b, ret;
    static StringTokenizer st;

    static long run(long num) {
        long ret = num;

        for (long i = 2; i <= num; i *= 2) {
            ret += (num / i) * (i / 2);
        }

        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        st = new StringTokenizer(br.readLine());

        a = Long.parseLong(st.nextToken());
        b = Long.parseLong(st.nextToken());

        System.out.println(run(b) - run(a - 1));
    }
}

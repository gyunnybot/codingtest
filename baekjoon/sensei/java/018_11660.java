import java.io.*;
import java.util.*;

public class Main {
    static int n, m, a1, a2, b1, b2;
    static int[][] a = new int[1025][1025];
    static int[][] s = new int[1025][1025];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer inputNM = new StringTokenizer(br.readLine());

        n = Integer.parseInt(inputNM.nextToken());
        m = Integer.parseInt(inputNM.nextToken());

        for (int i = 1; i <= n; i++) {
            StringTokenizer lines = new StringTokenizer(br.readLine());

            for (int j = 1; j <= n; j++) {
                a[i][j] = Integer.parseInt(lines.nextToken());
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            StringTokenizer lines = new StringTokenizer(br.readLine());
            a1 = Integer.parseInt(lines.nextToken());
            b1 = Integer.parseInt(lines.nextToken());
            a2 = Integer.parseInt(lines.nextToken());
            b2 = Integer.parseInt(lines.nextToken());

            System.out.println(s[a2][b2] - s[a1 - 1][b2] - s[a2][b1 - 1] + s[a1 - 1][b1 - 1]);
        }
    }
}

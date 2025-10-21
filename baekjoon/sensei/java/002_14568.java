import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int ret = 0;
        int n = scanner.nextInt();

        for (int a = 1; a <= n; a++) { // 태희
            for (int b = 1; b <= n; b++) { // 영훈
                for (int c = 1; c <= n; c++) { // 남규
                    if (a % 2 == 1) continue;

                    if (c >= b + 2 && a + b + c == n) {
                        ret++;
                    }
                }
            }
        }

        System.out.println(ret);
    }
}

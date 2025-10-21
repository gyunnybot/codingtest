import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            boolean flag = true;

            long s = scanner.nextLong(); // 10^12 ~ 10^18

            for (long l = 2; l <= 1000000; l++) {
                if (s % l == 0) {
                    flag = false; // 적절하지 못한 암호 키
                    break;
                }
            }

            if (flag) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}

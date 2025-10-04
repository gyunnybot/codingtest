import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] a = new int[9];
        int sum = 0;

        for (int i = 0; i < 9; i++) {
            a[i] = sc.nextInt();
            sum += a[i];
        }

        // 오름차순 정렬
        Arrays.sort(a);

        // 9명 중 2명을 제외해서 합이 100이 되는 경우 찾기
        int exclude1 = -1, exclude2 = -1;

        for (int i = 0; i < 9; i++) {
            for (int j = i + 1; j < 9; j++) {
                if (sum - a[i] - a[j] == 100) {
                    exclude1 = i;
                    exclude2 = j;
                    break;
                }
            }
        }

        // 제외된 두 명을 빼고 출력
        for (int i = 0; i < 9; i++) {
            if (i == exclude1 || i == exclude2) continue;

            System.out.println(a[i]);
        }
    }
}

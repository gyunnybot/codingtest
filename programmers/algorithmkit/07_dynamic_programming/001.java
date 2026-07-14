import java.util.*;

class Solution {
    Set<Integer>[] dp = new HashSet[9];

    public int solution(int N, int number) {
        if (N == number) {
            return 1;
        }

        for (int i = 1; i <= 8; i++) { // 최솟값이 8보다 크면 -1을 return 합니다.
            dp[i] = new HashSet<>();
        }

        for (int i = 1; i <= 8; i++) {
            StringBuilder sb = new StringBuilder();

            for (int j = 0; j < i; j++) {
                sb.append(N); // append : 타입 상관없이 닥치는대로 붙여서 StringBuilder 타입으로 변경
            }

            dp[i].add(Integer.parseInt(sb.toString()));

            for (int j = 1; j < i; j++) {
                for (int a : dp[j]) {
                    for (int b : dp[i - j]) {
                        dp[i].add(a + b);
                        dp[i].add(a - b);
                        dp[i].add(a * b);

                        if (b != 0) {
                            dp[i].add(a / b);
                        }
                    }
                }
            }

            if (dp[i].contains(number)) {
                return i;
            }
        }

        return -1;
    }
}

import java.util.*;

class Solution {
    public int solution(int N, int number) {
        if (N == number) {
            return 1;
        }

        Set<Integer>[] dp = new HashSet[9]; // dp[i]: N을 i번 사용해서 만들 수 있는 문자열 집합

        // init
        for (int i = 1; i <= 8; i++) { // 최솟값이 8보다 크면 -1을 return 합니다.
            dp[i] = new HashSet<>();
        }

        for (int i = 1; i <= 8; i++) {
            StringBuilder sb = new StringBuilder();

            for (int j = 0; j < i; j++) {
                sb.append(N); // append(value) : 타입 상관없이 닥치는대로 붙이고 StringBuilder 타입으로 변경
            }

            // 단순 이어붙여서 만들 수 있는 수 먼저 저장
            // parseXXX 계열은 파라미터로 String을 받는다. StringBuilder는 다른 구현체
            dp[i].add(Integer.parseInt(sb.toString()));

            // 사칙연산을 통해 만들 수 있는 수를 추가로 저장
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

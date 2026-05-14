# 다이나믹 프로그래밍
dp는 재귀 방식의 구현에서 시간복잡도가 걸릴 때, 배열에 이전 상태의 값을 저장해서 중복되는 연산없이 O(1)로 이전 값을 가져오는 발상을 옮긴 것이다. 따라서, 아래 순서대로 생각하는 것이 자연스럽다.
1. 일단 recur로 작성
2. 복잡도 통과 불가능? recur에서 dp[] 배열을 통해 값 저장해야겠다!
3. 어려운 dp의 경우 2번 과정 사이에 탑다운 / 바텀업 방식을 선택 후 진행한다.

### 쉬운 dp
1. 문제를 분석해서 점화식을 도출하자. 경험 상 dp[1], dp[2], dp[3]을 노가다로 구한 후 이들 간의 관계를 살펴보면 규칙을 발견하게 되고, 이를 점화식으로 표현하면 된다.
2. 점화식을 기반으로 dp 테이블 내 값을 채운다. 특정 n에 대한 dp를 물어보면, 반환하면 끝

### 어려운 dp
탑다운 or 바텀업을 선택하는 과정이 필요하다. 문제를 읽고 기준을 정해야 구현이 쉬움

- BOJ 14501 퇴사 : 날짜가 인덱스를 결정한다. 탑다운 방식으로 접근한다면 0일부터 n일이 될 때까지의 최대 수익을 dp[0]이라고 정의하면, dp[0]은 dp[1~n-1]까지의 결과가 필요할 것이다. 바텀업 방식을 적용하면 dp[n-1]부터 시작해서 dp[n-1~0]이 계속 갱신되는 형태로 구현할 수 있다.<br><br>
    
    
    순수 recursive
    ```java
    import java.util.*;
    import java.io.*;

    public class Main {
        static int n;
        static int[] t = new int[16];
        static int[] p = new int[16];
        static int ret = Integer.MIN_VALUE;

        public static void main(String[] args) throws IOException {
            CustomScanner sc = new CustomScanner();

            n = sc.nextInt();

            for (int i = 0; i < n; i++) {
                t[i] = sc.nextInt();
                p[i] = sc.nextInt();
            }

            recur(0, 0);

            System.out.println(ret);
        }

        static void recur(int day, int pay) {
            if (day > n) {
                return;
            }

            if (day == n) {
                ret = Math.max(ret, pay);
                return;
            }

            recur(day + t[day], pay + p[day]);
            recur(day + 1, pay);
        }

        static class CustomScanner {
            private final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            private StringTokenizer st;

            String next() throws IOException {
                while (st == null || !st.hasMoreTokens()) {
                    String line = br.readLine();

                    if (line.isEmpty()) {
                        continue;
                    }

                    st = new StringTokenizer(line);
                }

                return st.nextToken();
            }

            Integer nextInt() throws IOException {
                String s = next();

                return Integer.parseInt(s);
            }

            Long nextLong() throws IOException {
                String s = next();

                return Long.parseLong(s);
            }
        }
    }
    ```

    recur + dp 배열에 값 저장 (탑다운 방식)
    ```java
    import java.util.*;
    import java.io.*;

    public class Main {
        static int n;
        static int[] t = new int[16];
        static int[] p = new int[16];
        static int[] dp = new int[16];

        public static void main(String[] args) throws IOException {
            CustomScanner sc = new CustomScanner();

            n = sc.nextInt();

            for (int i = 0; i < n; i++) {
                t[i] = sc.nextInt();
                p[i] = sc.nextInt();
            }

            // 상담이 무보수라면 방문해도 0이다. 구별을 위해 DP 배열을 -1로 초기화
            Arrays.fill(dp, -1);

            System.out.println(recur(0));
        }

        static int recur(int day) {
            // 퇴사일을 넘어가면 선택 불가능하므로 매우 작은 값 반환
            if (day > n) {
                return Integer.MIN_VALUE;
            }

            if (day == n) {
                return 0;
            }

            // 이미 계산된 값이 있다면 결과 반환 (메모이제이션)
            if (dp[day] != -1) {
                return dp[day];
            }

            // 1. 현재 날짜 상담 선택: recur(day + t[day]) + p[day]
            // 2. 현재 날짜 상담 건너뜀: recur(day + 1)
            dp[day] = Math.max(recur(day + t[day]) + p[day], recur(day + 1));

            return dp[day];
        }

        static class CustomScanner {
            private final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            private StringTokenizer st;

            String next() throws IOException {
                while (st == null || !st.hasMoreTokens()) {
                    String line = br.readLine();

                    if (line.isEmpty()) {
                        continue;
                    }

                    st = new StringTokenizer(line);
                }

                return st.nextToken();
            }

            Integer nextInt() throws IOException {
                String s = next();

                return Integer.parseInt(s);
            }

            Long nextLong() throws IOException {
                String s = next();

                return Long.parseLong(s);
            }
        }
    }
    ```

    순수 dp. 바텀업 방식 적용
    ```java
    import java.util.*;
    import java.io.*;

    public class Main {
        static int n;
        static int[] t = new int[16];
        static int[] p = new int[16];
        static int[] dp = new int[16];

        public static void main(String[] args) throws IOException {
            CustomScanner sc = new CustomScanner();

            n = sc.nextInt();
            
            for (int i = 0; i < n; i++) {
                t[i] = sc.nextInt();
                p[i] = sc.nextInt();
            }

            for (int idx = n - 1; idx >= 0; idx--) {
                // 해당 날짜에 상담을 하지 않는 경우: 다음날(idx + 1)의 최댓값을 가져옴
                dp[idx] = Math.max(dp[idx], dp[idx + 1]);

                // 해당 날짜에 상담을 하는 경우: 상담이 끝나는 날(idx + t[idx])의 수익 + 현재 수익
                if (idx + t[idx] <= n) {
                    dp[idx] = Math.max(dp[idx], dp[idx + t[idx]] + p[idx]);
                }
            }

            System.out.println(dp[0]);
        }

        static class CustomScanner {
            private final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            private StringTokenizer st;

            String next() throws IOException {
                while (st == null || !st.hasMoreTokens()) {
                    String line = br.readLine();

                    if (line.isEmpty()) {
                        continue;
                    }

                    st = new StringTokenizer(line);
                }

                return st.nextToken();
            }

            Integer nextInt() throws IOException {
                String s = next();

                return Integer.parseInt(s);
            }

            Long nextLong() throws IOException {
                String s = next();

                return Long.parseLong(s);
            }
        }
    }
    ```

- BOJ 12865 평범한 배낭 : 변수가 3갠데, DP가 신경 쓸 변수는 2개. 걷어내야 할 변수를 생각 잘해야 함. 탑다운, 바텀업 둘 다 이상하진 않음. 그래서 어렵다.<br><br>

    recursive + dp 탑다운 방식. 순수 recursive는 시간복잡도 초과
    ```java
    import java.util.*;
    import java.io.*;

    public class Main {
        static int n, k;
        static int[] w = new int[101];
        static int[] v = new int[101];
        static int[][] dp = new int[101][100001];
        static int ret = Integer.MIN_VALUE;

        public static void main(String[] args) throws IOException {
            CustomScanner sc = new CustomScanner();

            n = sc.nextInt();
            k = sc.nextInt();

            for (int i = 0; i < n; i++) {
                w[i] = sc.nextInt();
                v[i] = sc.nextInt();
            }

            for (int i = 0; i < 101; i++) {
                Arrays.fill(dp[i], -1); // 가치가 0일 수 있음. 구별을 위해 -1로 초기화
            }

            System.out.println(recur(0, 0));
        }

        static int recur(int idx, int weight) {
            if (weight > k) {
                return Integer.MIN_VALUE;
            }

            if (idx == n) {
                return 0;
            }

            if (dp[idx][weight] != -1) {
                return dp[idx][weight];
            }

            dp[idx][weight] = Math.max(recur(idx + 1, weight + w[idx]) + v[idx], recur(idx + 1, weight));

            return dp[idx][weight];
        }

        /* 시간 초과 발생 코드: 순수 재귀
        static void recur(int idx, int weight, int value) {
            if (weight > k) return;

            if (idx == n) {
                ret = Math.max(ret, value);
                return;
            }

            recur(idx + 1, weight + w[idx], value + v[idx]); // 현재 물건을 넣는 경우
            recur(idx + 1, weight, value); // 현재 물건을 넣지 않는 경우
        }
        */

        static class CustomScanner {
            private final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            private StringTokenizer st;

            String next() throws IOException {
                while (st == null || !st.hasMoreTokens()) {
                    String line = br.readLine();

                    if (line.isEmpty()) {
                        continue;
                    }

                    st = new StringTokenizer(line);
                }

                return st.nextToken();
            }

            Integer nextInt() throws IOException {
                String s = next();

                return Integer.parseInt(s);
            }

            Long nextLong() throws IOException {
                String s = next();

                return Long.parseLong(s);
            }
        }
    }
    ```

    바텀업
    ```java
    import java.util.*;
    import java.io.*;

    public class Main {
        static int n, k;
        static int[] w = new int[101];
        static int[] v = new int[101];
        static int[][] dp = new int[101][100001];

        public static void main(String[] args) throws IOException {
            CustomScanner sc = new CustomScanner();

            n = sc.nextInt();
            k = sc.nextInt();

            for (int i = 0; i < n; i++) {
                w[i] = sc.nextInt();
                v[i] = sc.nextInt();
            }

            for (int idx = n - 1; idx >= 0; idx--) {
                for (int weight = k; weight >= 0; weight--) {
                    dp[idx][weight] = Math.max(dp[idx][weight], dp[idx + 1][weight]);

                    if (weight + w[idx] <= k) {
                        dp[idx][weight] = Math.max(dp[idx][weight], dp[idx + 1][weight + w[idx]] + v[idx]);
                    }
                }
            }

            System.out.println(dp[0][0]);
        }

        static class CustomScanner {
            private final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            private StringTokenizer st;

            String next() throws IOException {
                while (st == null || !st.hasMoreTokens()) {
                    String line = br.readLine();

                    if (line.isEmpty()) {
                        continue;
                    }

                    st = new StringTokenizer(line);
                }

                return st.nextToken();
            }

            Integer nextInt() throws IOException {
                String s = next();

                return Integer.parseInt(s);
            }

            Long nextLong() throws IOException {
                String s = next();

                return Long.parseLong(s);
            }
        }
    }
    ```

- BOJ 2240 자두나무 : boolean까지 생각하는 3차원 DP. 논리는 탑다운이 자연스럽다. recursive하게 구현하면 된다.
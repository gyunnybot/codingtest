# 다이나믹 프로그래밍
dp는 재귀 방식의 구현에서 시간복잡도가 걸릴 때, 배열에 이전 상태의 값을 저장해서 중복되는 연산없이 O(1)로 이전 값을 가져오는 발상을 옮긴 것이다. 아래 순서대로 생각하는 것이 자연스럽다.
1. 일단 recur로 작성
2. 복잡도 통과 불가능? recur에서 dp[] 배열을 통해 값 저장해야겠다!
3. 어려운 dp의 경우 2번 과정 사이에 탑다운 / 바텀업 방식을 선택 후 진행한다.

### 쉬운 dp
1. 문제를 분석해서 점화식을 도출하자. 경험 상 dp[1], dp[2], dp[3]을 노가다로 구한 후 이들 간의 관계를 살펴보면 규칙을 발견하게 되고, 이를 점화식으로 표현하면 된다.
2. 점화식을 기반으로 dp 테이블 내 값을 채운다. 특정 n에 대한 dp를 물어보면, 반환하면 끝

### 어려운 dp
탑다운 or 바텀업을 선택하는 과정이 필요하다. 문제를 읽고 기준을 정해야 구현이 쉬움

- BOJ 14501 퇴사 : 2차원 DP임을 알 수 있다. 하지만 그 전에 앞날부터 계산하는 것이 생각 논리 상 맞는 흐름인지는 사람마다 다른 것 같다. 나는 뒷날부터 계산했는데, 그 이유는 뒷날에 Integer.MAX_VALUE가 나오면 얘는 무조건 먹어야 하지 않나? 근데 그 논리면, 첫날에 max가 뜨면? ㄱ-
    
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

            // N 입력 받기
            n = sc.nextInt();

            // T와 P 배열 입력 받기
            for (int i = 0; i < n; i++) {
                t[i] = sc.nextInt();
                p[i] = sc.nextInt();
            }

            // 재귀 탐색 시작
            recur(0, 0);

            // 결과 출력
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

            // 1. 해당 날짜의 상담을 수행한다
            recur(day + t[day], pay + p[day]);
            
            // 2. 해당 날짜를 건너뛴다
            recur(day + 1, pay);
        }

        // 작성하신 커스텀 스캐너 클래스
        static class CustomScanner {
            private final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            private StringTokenizer st;

            String next() throws IOException {
                while (st == null || !st.hasMoreTokens()) {
                    String line = br.readLine();
                    
                    // readLine()이 null을 반환할 경우(EOF) 처리
                    if (line == null) return null;

                    if (line.isEmpty()) {
                        continue;
                    }

                    st = new StringTokenizer(line);
                }
                return st.nextToken();
            }

            int nextInt() throws IOException {
                return Integer.parseInt(next());
            }

            long nextLong() throws IOException {
                return Long.parseLong(next());
            }
        }
    }
    ```

    recur + dp 배열에 값 저장
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

            // DP 배열을 -1로 초기화 (방문하지 않은 상태 표시)
            Arrays.fill(dp, -1);

            System.out.println(recur(0));
        }

        static int recur(int day) {
            // 퇴사일을 넘어가면 선택 불가능하므로 매우 작은 값 반환
            if (day > n) {
                return Integer.MIN_VALUE / 2; // 오버플로우 방지를 위해 2로 나눔
            }

            // 퇴사일 당일에 딱 도착한 경우
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
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                return st.nextToken();
            }

            int nextInt() throws IOException {
                return Integer.parseInt(next());
            }
        }
    }
    ```
    순수 dp. 탑다운 방식 적용
    ```java
    import java.util.*;
    import java.io.*;

    public class Main {
        static int n;
        static int[] t = new int[16];
        static int[] p = new int[16];
        static int[] dp = new int[17]; // idx + 1 또는 idx + t[idx] 접근을 위해 여유 있게 선언

        public static void main(String[] args) throws IOException {
            CustomScanner sc = new CustomScanner();

            // 1. 입력 받기
            n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                t[i] = sc.nextInt();
                p[i] = sc.nextInt();
            }

            // 2. Bottom-Up DP 진행 (뒤에서부터 거꾸로)
            for (int idx = n - 1; idx >= 0; idx--) {
                // 해당 날짜에 상담을 하지 않는 경우: 다음날(idx + 1)의 최댓값을 가져옴
                dp[idx] = Math.max(dp[idx], dp[idx + 1]);

                // 해당 날짜에 상담을 하는 경우: 상담이 끝나는 날(idx + t[idx])의 수익 + 현재 수익
                if (idx + t[idx] <= n) {
                    dp[idx] = Math.max(dp[idx], dp[idx + t[idx]] + p[idx]);
                }
            }

            // 3. 0일부터 시작했을 때의 최대 수익 출력
            System.out.println(dp[0]);
        }

        // 커스텀 스캐너 클래스
        static class CustomScanner {
            private final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            private StringTokenizer st;

            String next() throws IOException {
                while (st == null || !st.hasMoreTokens()) {
                    String line = br.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                return st.nextToken();
            }

            int nextInt() throws IOException {
                return Integer.parseInt(next());
            }
        }
    }
    ```

- BOJ 12865 평범한 배낭 : 변수가 3갠데, DP가 신경 쓸 변수는 2개인데, 걷어내야 하는 변수를 생각 잘해야 함. 탑다운, 바텀업 둘 다 이상하진 않음. 그래서 어렵다.

    recursive + dp[]. 순수 recursive는 시간복잡도 초과
    ```java
    import java.util.*;
    import java.io.*;

    public class Main {
        static int n, k;
        static int[] w = new int[101];
        static int[] v = new int[101];
        static int[][] dp = new int[101][100001];
        static int ret = Integer.MIN_VALUE; // 단순 재귀용 전역 변수

        public static void main(String[] args) throws IOException {
            CustomScanner sc = new CustomScanner();

            n = sc.nextInt();
            k = sc.nextInt();

            for (int i = 0; i < n; i++) {
                w[i] = sc.nextInt();
                v[i] = sc.nextInt();
            }

            // 1. 메모이제이션 적용 버전 (Top-Down DP)
            for (int i = 0; i < 101; i++) Arrays.fill(dp[i], -1);
            System.out.println("DP 결과: " + recurDP(0, 0));

            // 2. 단순 재귀 버전 호출 (주석 해제하여 테스트 가능)
            /*
            recurSimple(0, 0, 0);
            System.out.println("순수 재귀 결과: " + ret);
            */
        }

        // [메모이제이션 적용 버전] - 효율적임
        static int recurDP(int idx, int weight) {
            if (weight > k) return Integer.MIN_VALUE / 2;
            if (idx == n) return 0;
            if (dp[idx][weight] != -1) return dp[idx][weight];

            dp[idx][weight] = Math.max(recurDP(idx + 1, weight + w[idx]) + v[idx], 
                                    recurDP(idx + 1, weight));
            return dp[idx][weight];
        }

        /* [시간 초과 발생 코드: 순수 재귀]
        static void recurSimple(int idx, int weight, int value) {
            if (weight > k) return;

            if (idx == n) {
                ret = Math.max(ret, value);
                return;
            }

            // 현재 물건을 넣는 경우
            recurSimple(idx + 1, weight + w[idx], value + v[idx]);
            // 현재 물건을 넣지 않는 경우
            recurSimple(idx + 1, weight, value);
        }
        */

        static class CustomScanner {
            private final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            private StringTokenizer st;

            String next() throws IOException {
                while (st == null || !st.hasMoreTokens()) {
                    String line = br.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                return st.nextToken();
            }

            int nextInt() throws IOException {
                return Integer.parseInt(next());
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
        // idx+1 참조를 위해 102, weight 범위 대응을 위해 100001
        static int[][] dp = new int[102][100001];

        public static void main(String[] args) throws IOException {
            CustomScanner sc = new CustomScanner();

            // 1. 입력 받기
            n = sc.nextInt();
            k = sc.nextInt();

            for (int i = 0; i < n; i++) {
                w[i] = sc.nextInt();
                v[i] = sc.nextInt();
            }

            // 2. Bottom-Up DP 진행 (뒤에서부터 거꾸로)
            for (int idx = n - 1; idx >= 0; idx--) {
                for (int weight = k; weight >= 0; weight--) {
                    // 현재 물건을 선택하지 않는 경우 (다음 인덱스의 같은 무게 값을 가져옴)
                    dp[idx][weight] = Math.max(dp[idx][weight], dp[idx + 1][weight]);

                    // 현재 물건을 선택하는 경우 (무게가 허용 범위 내일 때)
                    if (weight + w[idx] <= k) {
                        dp[idx][weight] = Math.max(dp[idx][weight], dp[idx + 1][weight + w[idx]] + v[idx]);
                    }
                }
            }

            // 3. 0번 인덱스부터 무게 0인 상태에서의 최대 가치 출력
            System.out.println(dp[0][0]);
        }

        // 커스텀 스캐너 클래스
        static class CustomScanner {
            private final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            private StringTokenizer st;

            String next() throws IOException {
                while (st == null || !st.hasMoreTokens()) {
                    String line = br.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                return st.nextToken();
            }

            int nextInt() throws IOException {
                return Integer.parseInt(next());
            }
        }
    }
    ```

- BOJ 2240 자두나무 : boolean까지 생각하는 DP라 가져옴. 논리는 무조건 바텀업이 자연스럽다. recursive하게 구현하면 되는 문제임을 알 수 있다.
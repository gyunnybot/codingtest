class Solution {
    public int solution(int n, int[][] results) {
        int answer = 0;

        int[][] adj = new int[n + 1][n + 1];

        for (int[] result : results) {
            adj[result[0]][result[1]] = 1;
            adj[result[1]][result[0]] = -1;
        }

        // 플로이드 워셜
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (adj[i][k] == 1 && adj[k][j] == 1) {
                        adj[i][j] = 1;
                        adj[j][i] = -1;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            int cnt = 0;

            for (int j = 1; j <= n; j++) {
                if (adj[i][j] != 0) {
                    cnt++;
                }
            }

            if (cnt == n - 1) { // i가 모든 j에 대해 결과가 정해지는 경우
                answer++;
            }
        }

        return answer;
    }
}

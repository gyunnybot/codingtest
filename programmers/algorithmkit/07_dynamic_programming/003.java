import java.util.*;

class Solution {
    int[] dy = {1, 0};
    int[] dx = {0, 1};
    int[][] a = new int[101][101];
    int[][] dp = new int[101][101];

    int recur(int n, int m, int y, int x) {
        if (y == n - 1 && x == m - 1) {
            return 1;
        }

        if (dp[y][x] != -1) {
            return dp[y][x];
        }

        int cnt = 0;

        for (int i = 0; i < 2; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                continue;
            }
            if (a[ny][nx] == -1) {
                continue;
            }

            cnt = (cnt + recur(n, m, ny, nx)) % 1000000007;
        }

        dp[y][x] = cnt;

        return dp[y][x];
    }

    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;

        for (int[] p : puddles) {
            a[p[1] - 1][p[0] - 1] = -1;
        }

        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        answer = recur(n, m, 0, 0);

        return answer;
    }
}

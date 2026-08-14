import java.util.*;

class Solution {
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, 1, 0, -1};

    public int solution(int[][] maps) {
        int answer = bfs(maps);

        return answer;
    }

    int bfs(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length; // bfs(n, m)으로 빼는 것이 정석이지만.. maps가 매개변수로 되어 있어서 그냥 가져왔다.

        int[][] visited = new int[n][m];

        visited[0][0] = 1;

        Queue<Pos> q = new ArrayDeque<>();
        q.offer(new Pos(0, 0));

        while (!q.isEmpty()) {
            Pos cur = q.poll();

            for (int i = 0; i < 4; i++) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                    continue;
                }

                // maps가 전역변수였다면 bfs(n, m) 원래 하던 방식으로 정의했을 것
                if (maps[ny][nx] == 1 && visited[ny][nx] == 0) {
                    visited[ny][nx] = visited[cur.y][cur.x] + 1;
                    q.offer(new Pos(ny, nx));
                }
            }
        }

        if (visited[n - 1][m - 1] == 0) {
            return -1;
        } else {
            return visited[n - 1][m - 1];
        }
    }

    // Pos, Pair, Info ...
    class Pos {
        int y;
        int x;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}

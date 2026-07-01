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
        int m = maps[0].length;

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

    class Pos {
        int y;
        int x;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}

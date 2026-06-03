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

        Queue<Node> q = new ArrayDeque<>();
        q.offer(new Node(0, 0));

        while (!q.isEmpty()) {
            Node cur = q.poll();

            for (int i = 0; i < 4; i++) {
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                    continue;
                }

                if (maps[ny][nx] == 1 && visited[ny][nx] == 0) {
                    visited[ny][nx] = visited[cur.first][cur.second] + 1;
                    q.offer(new Node(ny, nx));
                }
            }
        }

        if (visited[n - 1][m - 1] == 0) {
            return -1;
        } else {
            return visited[n - 1][m - 1];
        }
    }

    class Node {
        int first;
        int second;

        public Node(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}

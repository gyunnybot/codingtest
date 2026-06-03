import java.util.*;

class Solution {
    int maxDist;
    int[] visited = new int[20001];
    List<Integer>[] adj = new ArrayList[20001];

    public int solution(int n, int[][] edge) {
        int answer = 0;

        // init
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int[] e : edge) {
            adj[e[0]].add(e[1]);
            adj[e[1]].add(e[0]);
        }

        bfs(1);

        for (int i = 1; i <= n; i++) {
            if (visited[i] == maxDist) {
                answer++;
            }
        }

        return answer;
    }

    void bfs(int start) {
        visited[start] = 1;
        maxDist = visited[start];

        Queue<Integer> q = new ArrayDeque<>();
        q.offer(start);

        while (!q.isEmpty()) {
            int cur = q.poll();

            for (int next : adj[cur]) {
                if (visited[next] == 0) {
                    visited[next] = visited[cur] + 1;
                    q.offer(next);

                    maxDist = Math.max(maxDist, visited[next]);
                }
            }
        }
    }
}

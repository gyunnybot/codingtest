import java.util.List;
import java.util.ArrayList;
import java.util.Queue;
import java.util.ArrayDeque;

class Solution {
    private int maxDist;
    private int[] visited = new int[20001];
    private List<Integer>[] adj = new ArrayList[20001];
    
    private void bfs(int here) {
        visited[here] = 1;
        maxDist = 1;
        
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(here);
        
        while(!q.isEmpty()) {
            int cur = q.poll();
            
            for(int next : adj[cur]) {
                if(visited[next] == 0) {
                    visited[next] = visited[cur] + 1;
                    q.offer(next);
                    
                    maxDist = Math.max(maxDist, visited[next]);
                }
            }
        }
    }
    
    public int solution(int n, int[][] edge) {
        int answer = 0;
        
        for(int i = 1; i <= n; i++) { // init
            adj[i] = new ArrayList<>();
        }
        
        for(int[] pair : edge) {
            adj[pair[0]].add(pair[1]);
            adj[pair[1]].add(pair[0]);
        }
        
        bfs(1);
        
        for (int v : visited) {
            if (v == maxDist) {
                answer++;
            }
        }
        
        return answer;
    }
}

// Math는 내장 라이브러리라 import 필요 없음
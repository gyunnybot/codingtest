import java.util.*;

class Solution {
    List<Integer>[] adj = new ArrayList[201];
    boolean[] visited = new boolean[201];
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        for(int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(computers[i][j] == 1) {
                    adj[i + 1].add(j + 1);
                    adj[j + 1].add(i + 1);
                }
            }
        }
        
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                dfs(i);
                answer++;
            }
        }
        
        return answer;
    }
    
    void dfs(int here) {
        visited[here] = true;
        
        for(int there : adj[here]) {
            if(!visited[there]) {
                dfs(there);
            }
        }
        
        return;
    }
}

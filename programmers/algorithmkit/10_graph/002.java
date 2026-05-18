class Solution {
    public int solution(int n, int[][] results) {
        int answer = 0;
        int[][] graph = new int[n + 1][n + 1];
        
        for(int[] result : results) {
            int winner = result[0];
            int loser = result[1];
            
            graph[winner][loser] = 1;
            graph[loser][winner] = -1;
        }
        
        // 플로이드 워셜
        for(int k = 1; k <= n; k++) { // 중간
            for(int i = 1; i <= n; i++) { // winner(from)
                for(int j = 1; j <= n; j++) { // loser(to)
                    if(graph[i][k] == 1 && graph[k][j] == 1) {
                        graph[i][j] = 1;
                        graph[j][i] = -1;
                    }
                }
            }
        }
        
        for(int i = 1; i <= n; i++) {
            int cnt = 0;
            
            for(int j = 1; j <= n; j++) {
                if(graph[i][j] != 0) { // 특정 j에 대해 순위가 정해진 경우
                    cnt++;
                }
            }
            
            if(cnt == n - 1) { // i가 모든 j에 대해 결과가 정해지는 경우
                answer++;
            }
        }
        
        return answer;
    }
}
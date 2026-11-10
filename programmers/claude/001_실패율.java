import java.util.*;

class Solution {
    public List<Integer> solution(int N, int[] stages) {
        Map<Integer, Double> mp = new HashMap<>();
        
        for (int i = 1; i <= N; i++) {
            int a = 0; // 분자
            int b = 0; // 분모
            
            for (int stage : stages) {
                if (stage >= i) {
                    b++;
                }
                
                if (stage == i) {
                    a++;
                }
            }
            
            if (a == 0 || b == 0) {
                mp.put(i, 0.0);
            } else {
                mp.put(i, (double) a / (double) b);
            }
        }
        
        List<Integer> answer = new ArrayList<>(mp.keySet());
        
        answer.sort((a,b) -> Double.compare(mp.get(b), mp.get(a)));
        
        return answer;
    }
}

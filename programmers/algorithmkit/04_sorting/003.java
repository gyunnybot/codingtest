import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        
        Arrays.sort(citations);
        
        for(int i = 0; i < citations.length / 2; i++) {
            int temp = citations[i];
            citations[i] = citations[citations.length - i - 1];
            citations[citations.length - i - 1] = temp;
        }
        
        if(citations[0] == 0) {
            answer = 0;
        } else {
            for(int i = 0; i < citations.length; i++) {
                if(citations[i] >= i + 1) {
                    answer++;
                } else {
                    break;
                }
            }
        }
        
        return answer;
    }
}

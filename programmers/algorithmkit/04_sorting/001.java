import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        
        for(int cnt = 0; cnt < commands.length; cnt++) {
            int i = commands[cnt][0];
            int j = commands[cnt][1];
            int k = commands[cnt][2];
            
            List<Integer> temp = new ArrayList<>();
            
            for(int range = i - 1; range < j; range++) {
                temp.add(array[range]);
            }
            
            Collections.sort(temp);
            
            answer[cnt] = temp.get(k - 1);
        }
        
        return answer;
    }
}

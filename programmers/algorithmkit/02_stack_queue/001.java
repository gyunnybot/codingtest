import java.util.*;

public class Solution {
    public List<Integer> solution(int []arr) {
        List<Integer> temp = new ArrayList<>();
        int val = -1; // arr 내 숫자는 0 ~ 9
        
        for(int i : arr) {
            if(val != i) {
                temp.add(i);
                val = i;
            }
        }
        
        return temp;
    }
}

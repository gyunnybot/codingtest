import java.util.*;

public class Solution {
    public List<Integer> solution(int[] arr) {
        List<Integer> temp = new ArrayList<>();
        
        int val = -1; // 배열 arr의 각 원소는 숫자 0부터 9까지로 이루어져 있습니다.
        
        for(int i : arr) {
            if(i != val) {
                temp.add(i);
                val = i;
            }
        }
        
        return temp;
    }
}

/**
 * 반환형 까다로우면 바꿔도 된다!
 */
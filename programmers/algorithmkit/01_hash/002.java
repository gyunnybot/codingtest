import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = nums.length / 2; // []로 선언된 모든 기본 배열은 length를 사용한다
        
        HashSet<Integer> hs = new HashSet<>();
        
        for(int i : nums) {
            hs.add(i);
        }
        
        answer = Math.min(answer, hs.size());
        
        return answer;
    }
}

/**
 * 기본 배열 [] : .length
 * 문자열 String : .length()
 * 컬렉션 List, Set, Map : size()
 */
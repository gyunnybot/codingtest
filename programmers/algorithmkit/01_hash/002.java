import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        
        Set<Integer> st = new HashSet<>();
        
        for(int i : nums) {
            st.add(i);
        }
        
        answer = Math.min(st.size(), nums.length / 2);
        
        return answer;
    }
}

/**
 * Set : add
 * set은 hash 기반 + key-value가 아니라 get이 없다. 대신 .contains(value)
 * 
 * 길이 반환
 * 기본 배열 [] : .length
 * 문자열 String : .length()
 * 컬렉션 List, Set, Map : size()
 * 
 * 비어있는지 확인할 때
 * 기본 배열 [] : .length == 0
 * 문자열, 컬랙션 : .isEmpty(), .size() == 0
 */
import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;

        Set<Integer> st = new HashSet<>();

        for (int num : nums) {
            st.add(num);
        }

        answer = Math.min(st.size(), nums.length / 2);

        return answer;
    }
}

/**
 * set : add(value), contains(value)
 * 
 * 크기 반환 정리 >
 * 기본 배열 [] : .length
 * 문자열 String : .length()
 * 컬렉션 List, Set, Map 등 : size()
 * 
 * 
 * 컬랙션 자료구조 내 공백 체크 >
 * if (!Collection.isEmpty()) {
 *   // 비어있지 않을 때 로직 수행
 * }
 */
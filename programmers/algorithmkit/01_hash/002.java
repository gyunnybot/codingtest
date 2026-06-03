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
 * Set : add
 * set의 경우 해시 기반이라 get이 없다. 대신 .contains(value) 사용
 * 
 * 크기 반환 :
 * 기본 배열 [] : .length
 * 문자열 String : .length()
 * 컬렉션 List, Set, Map : size()
 * 
 * 정석적인 컬랙션 공백 체크 :
 * if (collection != null && !collection.isEmpty()) {
 *   // 컬렉션이 null이 아니고 비어있지 않을 때 로직 수행
 * }
 */
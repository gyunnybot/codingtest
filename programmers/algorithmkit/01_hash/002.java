import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = nums.length / 2;

        Set<Integer> st = new HashSet<>();

        for (int num : nums) {
            st.add(num);
        }

        answer = answer > st.size() ? st.size() : answer;

        return answer;
    }
}

/*
set : add(value), contains(value), remove(value)

크기 반환 정리:
기본 배열 [] -> .length
문자열 String -> .length()
컬렉션 List, Set, Map 등 -> size()

컬랙션 자료구조 내 공백 체크:
if (!Collection.isEmpty()) {
    // logic...
}
*/
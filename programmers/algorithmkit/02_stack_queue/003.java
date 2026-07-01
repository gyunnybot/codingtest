import java.util.*;

class Solution {
    boolean solution(String s) {
        Deque<Character> st = new ArrayDeque<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == '(') {
                st.push(c);
            } else { // c == ')'
                if (st.isEmpty()) {
                    return false;
                }

                st.poll();
            }
        }

        return st.isEmpty();
    }
}

/**
 * String 타입은 향상된 반복문 for(char c : s) 불가능
 * 
 * 일반 for 문 + length()로 접근
 *
 * for(int i = 0; i < s.length(); i++) {
 *  char c = s.charAt(i);
 * }
 * 
 */
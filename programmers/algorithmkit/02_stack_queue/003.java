import java.util.*;

class Solution {
    boolean solution(String s) {
        Deque<Character> st = new ArrayDeque<>();
        
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if(c == '(') {
                st.push(c);
            } else { // c == ')'
                if(st.isEmpty()) {
                    return false;
                }
                
                st.poll();
            }
        }

        return st.isEmpty();
    }
}

/**
 * String 문자열은 향상된 반복문 for(char c : s) 불가능
 * 
 * for(int i = 0; i < s.length(); i++) {
 *  char c = s.charAt(i);
 * }
 * 
 * s[i] X , s.charAt(i) O
 */
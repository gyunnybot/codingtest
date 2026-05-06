import java.util.*;

class Solution {
    boolean solution(String s) {
        Deque<Character> st = new ArrayDeque<>();
        
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i); // s[i] X , s.charAt(i) O
            
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

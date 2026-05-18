import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        Set<String> st = new HashSet<>();
        
        for(String s : phone_book) {
            st.add(s);
        }
        
        for(String s : phone_book) {
            for(int i = 1; i < s.length(); i++) {
                if(st.contains(s.substring(0, i))) {
                    return false;
                }
            }
        }
        
        return answer;
    }
}

/**
 * set : contains(value);
 * + map에서 key가 있는지 확인 : map.containsKey(key);
 * 
 * String.substring(st_idx, ed_idx); : st_idx부터 ed_idx - 1까지 문자열 부분 추출
 */
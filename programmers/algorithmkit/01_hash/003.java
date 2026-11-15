import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        Set<String> st = new HashSet<>();

        for (String number : phone_book) {
            st.add(number);
        }

        for (String number : phone_book) {
            for (int i = 1; i < number.length(); i++) {
                if (st.contains(number.substring(0, i))) {
                    return false;
                }
            }
        }
        
        return true;
    }
}

// set : contains(value);
// map : containsKey(key);

// String.substring(st_idx, ed_idx); : st_idx부터 ed_idx - 1까지의 문자열만 추출
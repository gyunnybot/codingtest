import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;

        Set<String> st = new HashSet<>();

        for (String number : phone_book) {
            st.add(number);
        }

        for (String number : phone_book) {
            for (int i = 1; i < number.length(); i++) { // n - 1
                if (st.contains(number.substring(0, i))) { // n - 2
                    return false;
                }
            }
        }

        return answer;
    }
}

/**
 * set : contains(value);
 * map : map.containsKey(key);
 * 
 * String.substring(st_idx, ed_idx); : st_idx부터 ed_idx - 1까지의 문자열 부분 추출
 */
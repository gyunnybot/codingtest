import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        Map<String, Integer> mp = new HashMap<>();
        
        for(String s : phone_book) {
            mp.put(s, 1); // 같은 전화번호가 중복해서 들어있지 않습니다.
        }
        
        for(String s : phone_book) {
            for(int i = 1; i < s.length(); i++) {
                if(mp.containsKey(s.substring(0, i))) {
                    return false;
                }
            }
        }
        
        return true;
    }
}

/**
 * map에서 key가 있는지 확인 : map.containsKey(key);
 */
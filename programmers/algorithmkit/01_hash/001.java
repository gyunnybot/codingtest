import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        
        Map<String, Integer> mp = new HashMap<>();
        
        for(String s : participant) { // mp.put(s, 1)은 안되나요? 참가자 중에는 동명이인이 있을 수 있습니다.
            mp.put(s, mp.getOrDefault(s, 0) + 1);
        }
        
        for(String s : completion) {
            mp.put(s, mp.get(s) - 1);
        }
        
        for(String s : participant) {
            if(mp.get(s) != 0) {
                answer = s;
                break;
            }
        }
        
        return answer;
    }
}

/**
 * Map : put, get(getOrDefault)
 */
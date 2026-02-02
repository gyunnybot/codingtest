import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";

        HashMap<String, Integer> hm = new HashMap<>();
        
        for(String p : participant) {
            hm.put(p, hm.getOrDefault(p, 0) + 1); // 처음 등록된 key의 value는 null이므로 반드시 getOrDefault 사용
        }
        
        for(String c : completion) {
            hm.put(c, hm.get(c) - 1);
        }
        
        for(String p : participant) {
            if(hm.get(p) != 0) {
                answer = p;
                break;
            }
        }
        
        return answer;
    }
}

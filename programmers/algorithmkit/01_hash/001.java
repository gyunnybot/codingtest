import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";

        Map<String, Integer> hm = new HashMap<>();
        
        for(String p : participant) { // 참가자 중에는 동명이인이 있을 수 있습니다.
            hm.put(p, hm.getOrDefault(p, 0) + 1); // 처음 등록된 key의 value는 null이므로 반드시 getOrDefault 필수
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

/**
 * hm.put(p, 1)이 아닌 hm.put(p, hm.getOrDefault(p, 0) + 1);인 이유? 동명이인 가능성
 */
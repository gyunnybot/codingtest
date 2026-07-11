import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";

        Map<String, Integer> mp = new HashMap<>();

        for (String p : participant) {
            mp.put(p, mp.getOrDefault(p, 0) + 1); // 참가자 중에는 동명이인이 있을 수 있습니다.
        }

        for (String c : completion) {
            mp.put(c, mp.get(c) - 1);
        }

        for (String p : participant) {
            if (mp.get(p) != 0) { // java는 boolean, int 타입을 구별한다. if에 명확한 boolean 전달
                answer = p;
                break;
            }
        }

        return answer;
    }
}

// map : put(key, value), get(key), getOrDefault(key, default value);
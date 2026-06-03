import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";

        Map<String, Integer> mp = new HashMap<>();

        for (String p : participant) {
            mp.put(p, mp.getOrDefault(p, 0) + 1); // 동명이인을 고려하면 mp.put(p, 1) 불가
        }

        for (String c : completion) {
            mp.put(c, mp.get(c) - 1);
        }

        for (String p : participant) {
            if (mp.get(p) != 0) {
                answer = p;
                break;
            }
        }

        return answer;
    }
}

// map : put(key, value), get(key), getOrDefault(key, default value);
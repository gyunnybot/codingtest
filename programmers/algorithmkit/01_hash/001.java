import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";

        Map<String, Integer> mp = new HashMap<>();

        // init
        for (String p : participant) {
            mp.put(p, 0);
        }

        for (String p : participant) {
            mp.put(p, mp.get(p) + 1);
        }

        for (String c : completion) {
            mp.put(c, mp.get(c) - 1);
        }

        for (Map.Entry<String, Integer> entry : mp.entrySet()) {
            if (entry.getValue() != 0) {
                answer = entry.getKey();

                break;
            }
        }

        return answer;
    }
}

// map : put(key, value), get(key), getOrDefault(key, default value), containsKey(key), remove(key)
import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";

        Map<String, Integer> mp = new HashMap<>();

        // for (String p : participant) {
        //     mp.put(p, mp.getOrDefault(p, 0) + 1); // getOrDefault(key, default value) 알아두면 좋을 듯?
        // }

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

        for (String p : participant) {
            if (mp.get(p) != 0) { // java는 boolean, int 타입을 구별한다. 조건절에 명확한 boolean 전달 필요
                answer = p;
                break;
            }
        }

        return answer;
    }
}

// map : put(key, value), get(key), getOrDefault(key, default value), containsKey(key), remove(key)
import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;

        Map<String, Integer> mp = new HashMap<>();

        for (String[] c : clothes) {
            mp.put(c[1], mp.getOrDefault(c[1], 0) + 1);
        }

        for (Integer val : mp.values()) {
            answer *= (val + 1);
        }

        answer -= 1;

        return answer;
    }
}

/**
 * key-value 모두 필요할 때 >
 * map : entrySet() -> Map.Entry 반환
 * entry : getKey(), getValue()
 * 
 * for (Map.Entry<String, Integer> entry : map.entrySet()) {
 *  System.out.println("Key: " + entry.getKey() + ", Value: " + entry.getValue());
 * }
 * 
 * 
 * key만 필요할 때 >
 * map : keySet()
 * 
 * value만 필요할 때 >
 * map : values()
 */
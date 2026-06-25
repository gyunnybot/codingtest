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
 *  key-value 모두 필요할 때 : Map : entrySet / Entry : getKey, getValue

    for (Map.Entry<String, Integer> entry : map.entrySet()) {
        System.out.println("Key: " + entry.getKey() + ", Value: " + entry.getValue());
    }


    key만 필요하거나, key를 활용할 때 : Map : keySet

    for (String key : map.keySet()) {
        System.out.println("Key: " + key);
    }


    value만 필요할 때 : Map : values
    
    for (Integer value : map.values()) {
        System.out.println("Value: " + value);
    }
 */
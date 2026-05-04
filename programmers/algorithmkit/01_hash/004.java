import java.util.Map;
import java.util.HashMap;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        
        Map<String, Integer> hm = new HashMap<>();
        
        for(String[] c : clothes) {
            hm.put(c[1], hm.getOrDefault(c[1], 0) + 1);
        }
        
        for(Integer val : hm.values()) {
            answer *= (val + 1);
        }
        
        answer -= 1;
        
        return answer;
    }
}

/**
 *  key-value 모두 필요할 때 :

    for (Map.Entry<String, Integer> entry : map.entrySet()) {
        System.out.println("Key: " + entry.getKey() + ", Value: " + entry.getValue());
    }


    람다식 :
    
    map.forEach((key, value) -> {
        System.out.println("Key: " + key + ", Value: " + value);
    });


    key만 필요하거나, key를 활용할 때 :

    for (String key : map.keySet()) {
        System.out.println("Key: " + key + ", Value: " + map.get(key));
    }


    value만 필요할 때 :
    
    for (Integer value : map.values()) {
        System.out.println("Value: " + value);
    }
 */
import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1; // 곱셈 연산을 위해 1로 초기화

        Map<String, Integer> mp = new HashMap<>();

        // init
        for (String[] c : clothes) {
            mp.put(c[1], 0);
        }

        for (String[] c : clothes) {
            mp.put(c[1], mp.get(c[1]) + 1);
        }

        for (Integer i : mp.values()) {
            answer *= (i + 1);
        }

        return answer - 1;
    }
}

/*
key-value 모두 필요할 때:
map -> entrySet(): Map.Entry 반환
entry -> getKey(), getValue(): 각각 key, value 반환

for (Map.Entry<String, Integer> entry : map.entrySet()) {
    System.out.println("Key: " + entry.getKey() + ", Value: " + entry.getValue());
}

key만 필요할 때:
map -> keySet()

for (String s : map.keySet()) {
}

value만 필요할 때:
map -> values()

for (Integer i : map.values()) {
}
 */
import java.util.*;

public class Solution {
    public List<Integer> solution(int[] arr) {
        List<Integer> answer = new ArrayList<>();

        int val = -1; // 배열 arr의 각 원소는 숫자 0부터 9까지로 이루어져 있습니다.

        for (int i : arr) {
            if (i != val) {
                answer.add(i);
                val = i;
            }
        }

        return answer;
    }
}

// Solution의 return type은 바꿔도 된다. auto-boxing 처리가 되는 듯? 출력만 잘 되면 가능
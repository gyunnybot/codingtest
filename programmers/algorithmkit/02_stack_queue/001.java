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

/**
 * 반환형이 맘에 안들면 바꿔도 된다. 출력만 잘 된다면 가능
 */
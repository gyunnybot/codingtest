import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];

        for (int cnt = 0; cnt < commands.length; cnt++) {
            int i = commands[cnt][0];
            int j = commands[cnt][1];
            int k = commands[cnt][2];

            List<Integer> temp = new ArrayList<>();

            for (int range = i - 1; range < j; range++) {
                temp.add(array[range]);
            }

            Collections.sort(temp);

            answer[cnt] = temp.get(k - 1);
        }

        return answer;
    }
}

/**
 * 문제에 길이가 인자로 주어진 경우에는 일반 배열 []의 길이를 고정해줘도 좋은 것 같다.
 * 껄끄러운 경우에는 그냥 List 새로 파서 add로 진행
 */
import java.util.*;

class Solution {
    public List<Integer> solution(int[] answers) {
        int[] score = new int[3];

        List<Integer>[] arr = new ArrayList[3];

        arr[0] = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5));
        arr[1] = new ArrayList<>(Arrays.asList(2, 1, 2, 3, 2, 4, 2, 5));
        arr[2] = new ArrayList<>(Arrays.asList(3, 3, 1, 1, 2, 2, 4, 4, 5, 5));

        for (int i = 0; i < answers.length; i++) {
            if (answers[i] == arr[0].get(i % arr[0].size())) {
                score[0]++;
            }
            if (answers[i] == arr[1].get(i % arr[1].size())) {
                score[1]++;
            }
            if (answers[i] == arr[2].get(i % arr[2].size())) {
                score[2]++;
            }
        }

        int max_val = -1;

        for (int s : score) {
            max_val = Math.max(max_val, s);
        }

        List<Integer> answer = new ArrayList<>();

        for (int i = 0; i < 3; i++) {
            if (max_val == score[i]) {
                answer.add(i + 1);
            }
        }

        return answer;
    }
}

/**
 * 미리 값이 입력되고 변경되지 않으면 [] 배열로 접근하는 것이 자연스러운 듯?
 * 
 * int[][] arr = {
 *  {1, 2, 3, 4, 5},
 *  {2, 1, 2, 3, 2, 4, 2, 5},
 *  {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
 * };
 * 
 * 
 * 추후 배열에 원소가 추가될 가능성이 있다면 ArrayList로 정의하기
 * 
 * new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5));
 */
import java.util.*;

class Solution {
    public List<Integer> solution(int[] answers) {
        int[] score = new int[3];
        
        int[][] arr = {
            {1, 2, 3, 4, 5},
            {2, 1, 2, 3, 2, 4, 2, 5},
            {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
        };
        
        for(int i = 0; i < answers.length; i++) {
            if(answers[i] == arr[0][i % arr[0].length]) score[0]++;
            if(answers[i] == arr[1][i % arr[1].length]) score[1]++;
            if(answers[i] == arr[2][i % arr[2].length]) score[2]++;
        }
               
        int max_val = -1;

        for(int s : score) {
            max_val = Math.max(max_val, s);
        }
               
        List<Integer> answer = new ArrayList<>(); // 조건에 따라 값이 추가되는 상황 = List, add
               
        for(int i = 0; i < 3; i++) {
            if(max_val == score[i]) {
               answer.add(i + 1);
            }
        }

        return answer;
    }
}

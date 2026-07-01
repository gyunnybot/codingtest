import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;

        int[] temp = new int[n];

        Arrays.fill(temp, 1);

        for (int i : lost) {
            temp[i - 1]--;
        }

        for (int i : reserve) {
            temp[i - 1]++;
        }

        for (int i = 0; i < n; i++) {
            if (temp[i] == 0) {
                if (i > 0 && temp[i - 1] == 2) {
                    temp[i - 1]--;
                    temp[i]++;
                } else if (i < n - 1 && temp[i + 1] == 2) {
                    temp[i + 1]--;
                    temp[i]++;
                }
            }
        }

        for (int i : temp) {
            if (i > 0) {
                answer++;
            }
        }
        
        return answer;
    }
}

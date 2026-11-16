import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;

        int[] temp = new int[n + 1]; // 0 ~ n

        Arrays.fill(temp, 1);

        for (int i : lost) {
            temp[i]--;
        }

        for (int i : reserve) {
            temp[i]++;
        }

        for (int i = 1; i <= n; i++) {
            if (temp[i] == 0) {
                if (i > 1 && temp[i - 1] > 1) {
                    temp[i - 1]--;
                    temp[i]++;
                } else if (i < n && temp[i + 1] > 1) {
                    temp[i + 1]--;
                    temp[i]++;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (temp[i] > 0) {
                answer++;
            }
        }
        return answer;
    }
}

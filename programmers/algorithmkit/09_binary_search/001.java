import java.util.*;

class Solution {
    public long solution(int n, int[] times) {
        long answer = 0;

        Arrays.sort(times);

        long left = 0;
        long right = (long) times[times.length - 1] * n; // 타입 변환 신경쓰기

        while (left <= right) {
            long mid = (left + right) / 2;
            long cnt = 0;

            for (int i = 0; i < times.length; i++) {
                cnt += mid / times[i];
            }

            if (cnt < n) {
                left = mid + 1;
            } else {
                right = mid - 1;
                answer = mid;
            }
        }
        
        return answer;
    }
}

// 입력받는 수의 범위가 크다. O(logN)이 아니면 감당이 안됨 + 적정한 수를 좁혀가면서 찾아야 함 = 이분탐색 생각하기
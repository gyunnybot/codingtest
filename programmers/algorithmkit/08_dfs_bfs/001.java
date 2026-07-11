class Solution {
    int answer = 0;

    void recur(int[] numbers, int target, int idx, int cnt) {
        if (idx == numbers.length) {
            if (cnt == target) {
                answer++;
            }

            return;
        }

        recur(numbers, target, idx + 1, cnt + numbers[idx]);
        recur(numbers, target, idx + 1, cnt - numbers[idx]);
    }

    public int solution(int[] numbers, int target) {
        recur(numbers, target, 0, 0);

        return answer;
    }
}

/**
 * 재귀적 방식. n <= 20, O(2^20) ~= O(10^6)
 */
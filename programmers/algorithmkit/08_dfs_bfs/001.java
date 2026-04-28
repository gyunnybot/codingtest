class Solution {
    static int answer = 0;
    
    static void recur(int[] numbers, int target, int idx, int cnt) {
        if(idx == numbers.length) {
            if(cnt == target) {
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
 * n <= 20, 2^20 by 재귀 ~= O(10^6)
 */
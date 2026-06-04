import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];

        Deque<Integer> stk = new ArrayDeque<>();

        for (int i = 0; i < prices.length; i++) {
            while (!stk.isEmpty() && prices[stk.peek()] > prices[i]) {
                answer[stk.peek()] = i - stk.peek();
                stk.poll();
            }

            stk.push(i);
        }

        while (!stk.isEmpty()) {
            answer[stk.peek()] = prices.length - 1 - stk.peek();
            stk.poll();
        }

        return answer;
    }
}

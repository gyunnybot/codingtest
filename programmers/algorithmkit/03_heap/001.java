import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int i = 0; i < scoville.length; i++) {
            pq.offer(scoville[i]);
        }

        while (!pq.isEmpty() && pq.peek() < K) {
            if (pq.size() >= 2) {
                int first = pq.poll();
                int second = pq.poll();

                pq.offer(first + second * 2);

                answer++;
            } else {
                answer = -1;
                break;
            }
        }

        return answer;
    }
}

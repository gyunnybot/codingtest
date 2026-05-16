import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int i = 0; i < scoville.length; i++) {
            pq.offer(scoville[i]);
        }
        
        while(!pq.isEmpty() && pq.peek() < K) { // pq, q, st .isEmpty()
            if(pq.size() >= 2) { // pq, q, st .size()
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

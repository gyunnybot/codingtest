import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;

        int w = 0;

        Queue<Integer> q = new ArrayDeque<>();
        
        for (int i = 0; i < truck_weights.length; i++) {
            while (true) {
                if (q.size() == bridge_length) {
                    w -= q.poll();
                }

                if (w + truck_weights[i] <= weight) {
                    break;
                } else {
                    q.offer(0);
                    answer++;
                }
            }

            w += truck_weights[i];

            q.offer(truck_weights[i]);
            answer++;
        }

        return answer + bridge_length;
    }
}

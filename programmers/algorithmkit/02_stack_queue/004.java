import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        
        Deque<Pair> q = new ArrayDeque<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        for(int i = 0; i < priorities.length; i++) {
            q.offer(new Pair(priorities[i], i));
            pq.offer(priorities[i]);
        }
        
        while(!q.isEmpty()) {
            Pair cur = q.poll();
            
            if(cur.priority == pq.peek()) {
                answer++;
                
                pq.poll();
                
                if(cur.index == location) {
                    break;
                }
            } else {
                q.offer(cur);
            }
        }
        
        return answer;
    }
    
    class Pair {
        int priority;
        int index;
        
        public Pair(int priority, int index) {
            this.priority = priority;
            this.index = index;
        }
    }
}

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

/**
 * 중첩 클래스 그냥 Solution 내부에 생성한다.
 * 
 * 생성자는 public class_name{}
 * 
 * 정렬 방식 필요하면 : implements Comparable<Pair> 추가 후 compareTo 재정의
 * 
 * 커스텀 정렬 Comparator 인자 추가 : new Comparator<Pair>() { @Override compare..}
 * 커스텀 정렬 람다식 : Arrays.sort(arr, (p1, p2) -> Integer.compare(p1.x, p2.x));
 */
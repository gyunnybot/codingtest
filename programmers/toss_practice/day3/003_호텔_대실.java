import java.util.*;

class Solution {
    public int solution(String[][] book_time) {
        int[][] times = new int[book_time.length][2];

        for (int i = 0; i < book_time.length; i++) {
            times[i][0] = toMin(book_time[i][0]);
            times[i][1] = toMin(book_time[i][1]) + 10; // 청소 시간 추가
        }

        Arrays.sort(times, (a, b) -> Integer.compare(a[0], b[0]));

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int[] t : times) {
            if (!pq.isEmpty() && pq.peek() <= t[0]) {
                pq.poll();
            }

            pq.offer(t[1]);
        }

        return pq.size();
    }

    private int toMin(String s) {
        String[] p = s.split(":");
        
        return Integer.parseInt(p[0]) * 60 + Integer.parseInt(p[1]);
    }
}

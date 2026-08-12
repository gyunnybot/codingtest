import java.util.*;

class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;

        Arrays.sort(jobs, (j1, j2) -> Integer.compare(j1[0], j2[0]));

        int t = 0;
        int idx = 0;

        PriorityQueue<Info> pq = new PriorityQueue<>();

        while (idx < jobs.length || !pq.isEmpty()) {
            while (idx < jobs.length && jobs[idx][0] <= t) {
                pq.offer(new Info(jobs[idx][0], jobs[idx][1]));
                idx++;
            }

            if (!pq.isEmpty()) {
                Info cur = pq.poll();

                t += cur.time;
                answer += t - cur.start;
            } else {
                t = jobs[idx][0];
            }
        }

        return answer / jobs.length;
    }

    class Info implements Comparable<Info> {
        int start;
        int time;

        public Info(int start, int time) {
            this.start = start;
            this.time = time;
        }

        @Override
        public int compareTo(Info other) {
            if (this.time == other.time) {
                return Integer.compare(this.start, other.start);
            }

            return Integer.compare(this.time, other.time);
        }
    }
}

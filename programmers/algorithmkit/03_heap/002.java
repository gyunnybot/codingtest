import java.util.*;

class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;

        Arrays.sort(jobs, (a, b) -> Integer.compare(a[0], b[0])); // 요쳥 시각 순으로 정렬

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> {
            if (a.timeTakes == b.timeTakes) {
                return Integer.compare(a.startTime, b.startTime);
            }

            return Integer.compare(a.timeTakes, b.timeTakes);
        });

        int cutline = 0; // s는 작업이 요청되는 시점이며 0 ≤ s ≤ 1,000입니다.
        int idx = 0;

        // 1. jobs에 있는 작업들 누락없이 pq에 넣기
        // 2. pq 비우기
        while (idx < jobs.length || !pq.isEmpty()) {
            // idx >= jobs.length에서 jobs[idx][0] 접근 시 NPE
            while (idx < jobs.length && jobs[idx][0] <= cutline) {
                pq.offer(new Pair(jobs[idx][0], jobs[idx][1]));
                idx++;
            }

            if (!pq.isEmpty()) {
                Pair cur = pq.poll();

                cutline = cutline + cur.timeTakes;
                answer = answer + (cutline - cur.startTime); // 갱신된 cutline에서부터 반환 시간 계산
            } else {
                cutline = jobs[idx][0]; // 과거 cutline 기준 pq 내 작업이 없다면, idx 번째 job으로 cutline 점프
            }
        }

        return answer / jobs.length;
    }

    class Pair {
        int startTime;
        int timeTakes;

        public Pair(int startTime, int timeTakes) {
            this.startTime = startTime;
            this.timeTakes = timeTakes;
        }
    }
}

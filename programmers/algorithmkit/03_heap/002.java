import java.util.*;

class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;

        Arrays.sort(jobs, (j1, j2) -> Integer.compare(j1[0], j2[0])); // jobs에 저장된 애들이 요청받은 순서대로 주어지지 않을 수 있다

        int t = 0;
        int idx = 0;

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) ->
                a.time == b.time ?
                        Integer.compare(a.start, b.start) :
                        Integer.compare(a.time, b.time)
        );

        while (idx < jobs.length || !pq.isEmpty()) { // jobs에서 안 빼낸 작업이 있거나, 아직 pq에 처리할 작업이 있다면 계속 돈다
            while (idx < jobs.length && jobs[idx][0] <= t) { // idx 2번 검사? idx = jobs.length인 경우 예외 발생 방지
                pq.offer(new Pair(jobs[idx][0], jobs[idx][1]));
                idx++;
            }

            if (!pq.isEmpty()) {
                Pair cur = pq.poll();

                t += cur.time;
                answer += t - cur.start;
            } else { // 작업 사이에 빈 구간이 생긴다면 해당 idx 번째 job의 시간으로 점프
                t = jobs[idx][0];
            }
        }

        return answer / jobs.length;
    }

    class Pair {
        int start;
        int time;

        public Pair(int start, int time) {
            this.start = start;
            this.time = time;
        }
    }
}

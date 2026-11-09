import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;

        if (cacheSize == 0) {
            return cities.length * 5;
        }

        Queue<String> q = new ArrayDeque<>();

        for (int i = 0; i < cities.length; i++) {
            String city = cities[i].toLowerCase();

            if (q.remove(city)) { // 큐에 도시가 있다면 +1
                q.offer(city);
                answer += 1;
            } else { // 큐에 도시가 없다면 +5
                if (q.size() == cacheSize) {
                    q.poll();
                    q.offer(city);
                } else {
                    q.offer(city);
                }

                answer += 5;
            }
        }

        return answer;
    }
}

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

            if (q.remove(city)) {
                q.offer(city);
                answer += 1;
            } else {
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

import java.util.*;

class Solution {
    public List<Integer> solution(int[] progresses, int[] speeds) {
        List<Integer> answer = new ArrayList<>();
        List<Integer> days = new ArrayList<>();

        for (int i = 0; i < progresses.length; i++) {
            int remain = 100 - progresses[i];
            int day = remain / speeds[i];

            if (remain % speeds[i] != 0) {
                day++;
            }

            days.add(day);
        }

        int deploy_day = days.get(0);
        int cnt = 1;

        for (int i = 1; i < days.size(); i++) {
            if (deploy_day < days.get(i)) {
                answer.add(cnt);

                deploy_day = days.get(i);
                cnt = 1;
            } else {
                cnt++;
            }
        }

        answer.add(cnt);

        return answer;
    }
}

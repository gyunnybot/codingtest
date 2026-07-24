import java.util.*;

class Solution {
    public List<Integer> solution(int[] progresses, int[] speeds) {
        List<Integer> answer = new ArrayList<>();
        List<Integer> days = new ArrayList<>();

        for (int i = 0; i < progresses.length; i++) {
            int remaining_work = 100 - progresses[i];
            int remaining_days = remaining_work / speeds[i];

            if (remaining_work % speeds[i] != 0) {
                remaining_days++;
            }

            days.add(remaining_days);
        }

        // 첫 원소부터 반복문에 넣어야 한다는 강박 버리기
        int deploy_day = days.get(0);
        int cnt = 1;

        for (int i = 1; i < days.size(); i++) {
            int temp = days.get(i);

            if (deploy_day < temp) {
                answer.add(cnt);

                deploy_day = temp;
                cnt = 1;
            } else {
                cnt++;
            }
        }

        answer.add(cnt);

        return answer;
    }
}

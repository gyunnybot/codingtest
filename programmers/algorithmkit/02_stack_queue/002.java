import java.util.*;

class Solution {
    public List<Integer> solution(int[] progresses, int[] speeds) {
        List<Integer> answer = new ArrayList<>();
        List<Integer> days = new ArrayList<>();
        
        for(int i = 0; i < progresses.length; i++) {
            int remain = 100 - progresses[i];
            int day = remain / speeds[i];
            
            if(remain % speeds[i] != 0) {
                day++;
            }
            
            days.add(day);
        }
        
        int deploy_day = days.get(0);
        int cnt = 1;
        
        for(int i = 1; i < days.size(); i++) {
            if(days.get(i) <= deploy_day) {
                cnt++;
            } else {
                answer.add(cnt);
                
                deploy_day = days.get(i);
                cnt = 1;
            }
        }
        
        answer.add(cnt);
        
        return answer;
    }
}

/**
 * if 조건 작성 시, 숫자를 반환한다면 확실하게 비교 연산자(==, !=)를 사용해야 함
 * 컬랙션 배열 인덱스 접근은 list.get(idx)를 사용한다.
 */
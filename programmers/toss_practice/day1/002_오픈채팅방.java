import java.util.*;

class Solution {
    public List<String> solution(String[] record) {
        List<String> answer = new ArrayList<>();
        Map<String, String> uidAndNickname = new HashMap<>();

        for (String s : record) {
            String action = s.split(" ")[0];
            String uid = s.split(" ")[1];

            if (action.equals("Enter") || action.equals("Change")) {
                String nickname = s.split(" ")[2];
                uidAndNickname.put(uid, nickname);
            }
        }

        for (int i = 0; i < record.length; i++) {
            String action = record[i].split(" ")[0];
            String uid = record[i].split(" ")[1];
            String nickname = uidAndNickname.get(uid);

            if (action.equals("Enter")) {
                answer.add(nickname + "님이 들어왔습니다.");
            } else if (action.equals("Leave")) {
                answer.add(nickname + "님이 나갔습니다.");
            }
        }

        return answer;
    }
}

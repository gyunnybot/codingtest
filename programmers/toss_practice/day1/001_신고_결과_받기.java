import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];

        Map<String, Set<String>> reportedAndReporters = new HashMap<>(); // 문제가 제공하는 관념에서의 탈피
        Map<String, Integer> reporterAndMailCount = new HashMap<>(); // 얘는 보통 생각대로 자료구조 정의

        // init
        for (String s : id_list) {
            reportedAndReporters.put(s, new HashSet<>());
            reporterAndMailCount.put(s, 0);
        }

        for (String s : report) {
            String reporter = s.split(" ")[0];
            String reported = s.split(" ")[1];

            reportedAndReporters.get(reported).add(reporter); // 중복 카운트 방지 -> 해시 셋
            // report.stream().distinct().toList()? 어처피 해시 셋으로 distinct 걸러냄
        }

        for (String reported : reportedAndReporters.keySet()) {
            Set<String> reporters = reportedAndReporters.get(reported);

            if (reporters.size() >= k) {
                for (String reporter : reporters) {
                    reporterAndMailCount.put(reporter, reporterAndMailCount.get(reporter) + 1);
                }
            }
        }

        for (int i = 0; i < id_list.length; i++) {
            answer[i] = reporterAndMailCount.get(id_list[i]);
        }

        return answer;
    }
}

import java.util.*;

class Solution {
    public List<Integer> solution(String s) {
        List<Integer> answer = new ArrayList<>();

        String inner = s.substring(2, s.length() - 2);

        String[] splitResult = inner.split("\\},\\{");

        // 원소 개수 기준으로 오름차순 정렬
        Arrays.sort(splitResult, (a, b) -> Integer.compare(a.split(",").length, b.split(",").length));

        // 삽입 순서 유지, 중복 제거: LinkedHashSet
        Set<Integer> st = new LinkedHashSet<>();

        for (String sp : splitResult) {
            for (String num : sp.split(",")) {
                st.add(Integer.parseInt(num));
            }
        }

        for (Integer i : st) {
            answer.add(i);
        }

        return answer;
    }
}

import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";

        List<String> string_numbers = new ArrayList<>();

        for (int i = 0; i < numbers.length; i++) {
            string_numbers.add(String.valueOf(numbers[i])); // String.valueOf(Object value) : 객체를 문자열로 변경
        }

        Collections.sort(string_numbers, (s1, s2) -> (s2 + s1).compareTo(s1 + s2)); // 문자대로 붙인 결과가 크도록 정렬

        if (string_numbers.get(0).equals("0")) {
            answer = "0";
        } else {
            StringBuilder sb = new StringBuilder();

            for (String s : string_numbers) {
                sb.append(s);
            }

            answer = sb.toString();
        }

        return answer;
    }
}

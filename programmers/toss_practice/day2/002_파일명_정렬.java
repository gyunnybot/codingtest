import java.util.*;

class Solution {
    public List<String> solution(String[] files) {
        List<String> answer = new ArrayList<>();

        Arrays.sort(files, (a, b) -> {
            String[] spa = split(a);
            String[] spb = split(b);

            // 파일명의 HEAD 부분이 대소문자 차이 외에는 같을 경우, NUMBER의 숫자 순으로 정렬
            if (spa[0].toLowerCase().equals(spb[0].toLowerCase())) {
                return Integer.compare(Integer.parseInt(spa[1]), Integer.parseInt(spb[1])); // 앞의 00은 java가 처리
            }

            // HEAD 기준 정렬
            return spa[0].toLowerCase().compareTo(spb[0].toLowerCase());
        });

        for (String file : files) {
            answer.add(file);
        }

        return answer;
    }

    // HEAD, NUMBER 반환
    String[] split(String file) {
        int start = 0;

        // Character.isDigit(c): boolean
        while (!Character.isDigit(file.charAt(start))) {
            start++;
        }

        int end = start;

        // && end - start < 5? NUMBER는 한 글자에서 최대 다섯 글자 사이의 연속된 숫자
        while (end < file.length() && end - start < 5 && Character.isDigit(file.charAt(end))) {
            end++;
        }

        String[] splitResult = new String[2];

        splitResult[0] = file.substring(0, start);
        splitResult[1] = file.substring(start, end);

        return splitResult;
    }
}

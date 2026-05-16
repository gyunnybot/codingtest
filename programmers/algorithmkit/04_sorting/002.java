import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        
        List<String> string_numbers = new ArrayList<>();
        
        for(int i = 0; i < numbers.length; i++) {
            string_numbers.add(Integer.toString(numbers[i])); // Collections.toString(Primitive) : 문자열로 변경
        }
        
        Collections.sort(string_numbers, (a, b) -> (b + a).compareTo(a + b)); // a.compareTo(b) : a, b는 문자열 또는 컬랙션
        
        if(string_numbers.get(0).equals("0")) {
            answer = "0";
        } else {
            StringBuilder sb = new StringBuilder();
            
            for(String s : string_numbers) {
                sb.append(s);
            }
            
            answer = sb.toString();
        }
        
        return answer;
    }
}

/**
 * 백준에서는 public class, class 나눠져있어서 Comparator 클래스를 커스텀 생성했는데,
 * 프로그래머스는 class로 한정됨. 람다를 사용해서 정렬 기준을 적용
 */
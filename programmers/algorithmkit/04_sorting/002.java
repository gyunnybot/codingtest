import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";

        List<String> string_numbers = new ArrayList<>();

        for (int i = 0; i < numbers.length; i++) {
            string_numbers.add(Integer.toString(numbers[i])); // Object.toString(value) : 객체를 문자열로 변경
        }

        // sort(list, comparator)에서, comparator 내 compare를 람다식으로 구현
        Collections.sort(string_numbers, (s1, s2) -> (s2 + s1).compareTo(s1 + s2)); // a.compareTo(b) : a, b는 문자열 또는 컬랙션 자료형

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

/* Comparator를 직접 정의하는 방식

import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        List<String> string_numbers = new ArrayList<>();
        
        for(int i = 0; i < numbers.length; i++) {
            string_numbers.add(Integer.toString(numbers[i]));
        }

        Collections.sort(string_numbers, new CustomComparator());
        
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
    
    class CustomComparator implements Comparator<String> {
        @Override
        public int compare(String s1, String s2) {
            return (s2 + s1).compareTo(s1 + s2);
        }
    }
}
*/
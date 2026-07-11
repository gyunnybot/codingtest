import java.util.*;

class Solution {
    Set<Integer> st = new HashSet<>();

    public int solution(String numbers) {
        int answer = 0;

        // 1. numbers로 만들 수 있는 수 조합을 st에 저장한다
        recur("", numbers);

        // 2. st를 순회하면서 소수를 판별한다. 개수를 센 후 answer로 반환한다
        for (int i : st) {
            if (isPrime(i)) {
                answer++;
            }
        }

        return answer;
    }

    void recur(String ret, String numbers) {
        if (!ret.equals("")) {
            st.add(Integer.parseInt(ret));
        }

        // 탈출 조건
        if (numbers.length() == 0) {
            return;
        }

        for (int i = 0; i < numbers.length(); i++) {
            recur(ret + numbers.charAt(i), numbers.substring(0, i) + numbers.substring(i + 1));
        }
    }

    boolean isPrime(int n) {
        if (n <= 1) {
            return false;
        }

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }
}

// 보수적으로 O(7^7)의 시간복잡도?
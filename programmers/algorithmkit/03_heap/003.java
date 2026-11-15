import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        PriorityQueue<Integer> minPq = new PriorityQueue<>();
        PriorityQueue<Integer> maxPq = new PriorityQueue<>(Collections.reverseOrder());

        for (String operation : operations) {
            String[] parts = operation.split(" ");
            String oper = parts[0];
            int number = Integer.parseInt(parts[1]);

            if (oper.equals("I")) {
                minPq.offer(number);
                maxPq.offer(number);
            } else {
                if (minPq.isEmpty()) continue;

                if (number == 1) {
                    minPq.remove(maxPq.poll()); // 반대쪽 큐에서도 제거
                } else {
                    maxPq.remove(minPq.poll()); // 반대쪽 큐에서도 제거
                }
            }
        }

        if (minPq.isEmpty()) {
            return new int[]{0, 0};
        }

        return new int[]{maxPq.peek(), minPq.peek()};
    }
}

// pq.remove(value): 직접 값을 명시해서 제거하는 것도 가능. 대부분의 자료구조에 도입되어 있다.
// ArrayList의 경우는 주의가 필요함. 기본은 remove(idx) / remove(Integer.valueOf(value)) 구분하기
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
                // 빈 큐에 데이터를 삭제하라는 연산이 주어질 경우, 해당 연산은 무시합니다.
                if (minPq.isEmpty()) {
                    continue;
                }

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

// pq.remove(value): 직접 값을 명시해서 바로 제거하는 것도 가능. 대부분의 자료구조에 구현된 메서드
// 다만 ArrayList의 경우는 주의가 필요함. 기본은 remove(idx)이고, remove(Integer.valueOf(value))와 구분하기
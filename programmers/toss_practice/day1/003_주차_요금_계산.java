import java.util.*;

class Solution {
    public List<Integer> solution(int[] fees, String[] records) {
        List<Integer> answer = new ArrayList<>();

        Map<String, Integer> carAndTimeNow = new HashMap<>();
        Map<String, Integer> carAndTimeDiff = new TreeMap<>(); // 차량 번호가 작은 자동차부터. 오름차순 보장

        for (String s : records) {
            String[] parts = s.split(" ");
            String[] time = parts[0].split(":");
            String car = parts[1];
            String status = parts[2];

            int totalMinutes = Integer.parseInt(time[0]) * 60 + Integer.parseInt(time[1]);

            if (status.equals("IN")) {
                carAndTimeNow.put(car, totalMinutes);
            } else {
                int timeDiff = totalMinutes - carAndTimeNow.get(car);

                carAndTimeDiff.put(car, carAndTimeDiff.getOrDefault(car, 0) + timeDiff);
                carAndTimeNow.remove(car);
            }
        }

        // 출차 기록이 없는 차량은 23:59에 출차한 것으로 처리
        int minuteBeforeMidnight = 1439;

        for (Map.Entry<String, Integer> entry : carAndTimeNow.entrySet()) {
            int timeDiff = minuteBeforeMidnight - entry.getValue();

            carAndTimeDiff.put(entry.getKey(), carAndTimeDiff.getOrDefault(entry.getKey(), 0) + timeDiff);
        }

        for (int total : carAndTimeDiff.values()) {
            int fee = fees[1];

            if (total > fees[0]) {
                int extra = total - fees[0];
                int units = extra / fees[2];

                if (extra % fees[2] != 0) {
                    units++; // 나머지가 있으면 올림
                }

                fee += units * fees[3];
            }

            answer.add(fee);
        }

        return answer;
    }
}

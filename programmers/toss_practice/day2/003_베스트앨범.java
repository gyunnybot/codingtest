import java.util.*;

class Solution {
    public List<Integer> solution(String[] genres, int[] plays) {
        Map<String, Integer> genresPlays = new HashMap<>();
        Map<String, Map<Integer, Integer>> genresIdxPlays = new HashMap<>();

        for (int i = 0; i < genres.length; i++) {
            genresPlays.put(genres[i], genresPlays.getOrDefault(genres[i], 0) + plays[i]); // 장르별 총 재생 횟수 저장

            Map<Integer, Integer> map = genresIdxPlays.get(genres[i]);

            if (map == null) {
                map = new TreeMap<>();  // 번호 오름차순 자동 정렬을 위해 TreeMap
                genresIdxPlays.put(genres[i], map); // 장르별로 노래 번호별 재생 횟수 저장을 위한 map 생성
            }

            map.put(i, plays[i]);
        }

        List<Integer> answer = new ArrayList<>();

        while (!genresPlays.isEmpty()) {
            String genre = "";
            int play = 0;

            // 가장 많이 재생된 장르 찾기
            for (Map.Entry<String, Integer> entry : genresPlays.entrySet()) {
                if (play < entry.getValue()) {
                    genre = entry.getKey();
                    play = entry.getValue();
                }
            }

            // 해당 장르에서 최대 2곡 선택
            for (int i = 0; i < 2; i++) {
                int maxIdx = -1;
                int maxPlay = 0;

                // 해당 장르에서 가장 많이 재생된 노래 찾기
                for (Map.Entry<Integer, Integer> entry : genresIdxPlays.get(genre).entrySet()) {
                    if (maxPlay < entry.getValue()) { // 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
                        maxIdx = entry.getKey();
                        maxPlay = entry.getValue();
                    }
                }

                // 장르 내 노래가 없다면 종료
                if (maxIdx == -1) {
                    break;
                }

                answer.add(maxIdx);

                // 선택한 노래 삭제
                genresIdxPlays.get(genre).remove(maxIdx);
            }

            // 처리한 장르 삭제
            genresPlays.remove(genre);
        }

        return answer;
    }
}

// map.get(key), map.remove(key), map.containsKey(key) : idx가 아닌 key를 통해 연산 진행
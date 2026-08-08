import java.util.*;

class Solution {
    public List<Integer> solution(String[] genres, int[] plays) {
        Map<String, Integer> genresPlays = new HashMap<>();
        Map<String, Map<Integer, Integer>> genresIdxPlays = new TreeMap<>(); // 번호 낮은 순 정렬을 위해

        for (int i = 0; i < genres.length; i++) {
            genresPlays.put(genres[i], genresPlays.getOrDefault(genres[i], 0) + plays[i]); // 장르별 총 재생 횟수 저장

            Map<Integer, Integer> map = genresIdxPlays.get(genres[i]);

            if (map == null) {
                map = new TreeMap<>();
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
                    play = entry.getValue();
                    genre = entry.getKey();
                }
            }

            // 해당 장르에서 최대 2곡 선택
            for (int i = 0; i < 2; i++) {
                int maxPlay = 0;
                int maxIdx = -1;

                // 해당 장르에서 가장 많이 재생된 노래 찾기
                for (Map.Entry<Integer, Integer> entry : genresIdxPlays.get(genre).entrySet()) {
                    if (maxPlay < entry.getValue()) {
                        maxPlay = entry.getValue();
                        maxIdx = entry.getKey();
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

// map.get(key), map.remove(key), map.contains(key) : idx가 아닌 key를 통해 value를 찾는다
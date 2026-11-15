import java.util.*;

class Solution {
    public List<Integer> solution(String[] genres, int[] plays) {
        List<Integer> answer = new ArrayList<>();

        // 장르 - 장르별 재생 횟수 총 합
        Map<String, Integer> genres_totalPlayCnt = new HashMap<>();

        // 장르 - (인덱스 - 인덱스별 재생 횟수)
        Map<String, Map<Integer, Integer>> genres_idx_playCnt = new HashMap<>();

        // init
        for (int i = 0; i < genres.length; i++) {
            genres_totalPlayCnt.put(genres[i], 0);
        }

        for (int i = 0; i < genres.length; i++) {
            genres_totalPlayCnt.put(genres[i], genres_totalPlayCnt.get(genres[i]) + plays[i]);

            if (genres_idx_playCnt.get(genres[i]) == null) {
                Map<Integer, Integer> idx_playCnt = new TreeMap<>(); // 재생 횟수, 인덱스 낮은 순
                genres_idx_playCnt.put(genres[i], idx_playCnt);
            }

            genres_idx_playCnt.get(genres[i]).put(i, plays[i]);
        }

        while (!genres_totalPlayCnt.isEmpty()) {
            String max_genre = "";
            int max_play_count = -1;

            for (Map.Entry<String, Integer> entry : genres_totalPlayCnt.entrySet()) {
                if (max_play_count < entry.getValue()) {
                    max_genre = entry.getKey();
                    max_play_count = entry.getValue();
                }
            }

            for (int i = 0; i < 2; i++) {
                int max_idx = -1;
                int max_play = -1;

                // 고유 번호가 낮은 노래를 먼저 수록합니다. -> TreeSet이므로 key(index) 기준 오름차순 정렬 집합 받기
                for (Map.Entry<Integer, Integer> entry : genres_idx_playCnt.get(max_genre).entrySet()) {
                    if (max_play < entry.getValue()) { // <=로 작성할 시 고유 번호가 높은 노래를 먼저 수록하게 됨
                        max_idx = entry.getKey();
                        max_play = entry.getValue();
                    }
                }

                if (max_idx == -1) break;

                answer.add(max_idx);

                genres_idx_playCnt.get(max_genre).remove(max_idx);
            }

            genres_totalPlayCnt.remove(max_genre);
        }

        return answer;
    }
}

// map.get(key), map.remove(key), map.containsKey(key): map은 key가 필요해
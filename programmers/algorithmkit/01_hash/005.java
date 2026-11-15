import java.util.*;

class Solution {
    public List<Integer> solution(String[] genres, int[] plays) {
        List<Integer> answer = new ArrayList<>();

        // 장르 - 장르별 재생 횟수 총 합
        Map<String, Integer> genres_total = new HashMap<>();

        // 장르 - (인덱스 - 인덱스별 재생 횟수)
        Map<String, Map<Integer, Integer>> genres_idx_cnt = new HashMap<>();

        // init
        for (int i = 0; i < genres.length; i++) {
            genres_total.put(genres[i], 0);
        }

        for (int i = 0; i < genres.length; i++) {
            genres_total.put(genres[i], genres_total.get(genres[i]) + plays[i]);

            Map<Integer, Integer> temp = genres_idx_cnt.get(genres[i]);

            if (temp == null) {
                temp = new TreeMap<>(); // 재생 횟수, 인덱스 낮은 순
                genres_idx_cnt.put(genres[i], temp);
            }

            temp.put(i, plays[i]);
        }

        while (!genres_total.isEmpty()) {
            String max_genre = "";
            int max_total = -1;

            for (Map.Entry<String, Integer> entry : genres_total.entrySet()) {
                if (max_total < entry.getValue()) {
                    max_genre = entry.getKey();
                    max_total = entry.getValue();
                }
            }

            for (int i = 0; i < 2; i++) {
                int max_idx = -1;
                int max_cnt = -1;

                // 고유 번호가 낮은 노래를 먼저 수록합니다. -> TreeMap: key(index) 기준 오름차순 정렬된 k-v 쌍 보장
                for (Map.Entry<Integer, Integer> entry : genres_idx_cnt.get(max_genre).entrySet()) {
                    if (max_cnt < entry.getValue()) { // <=로 작성하면 고유 번호가 높은 노래가 반환되어 오류
                        max_idx = entry.getKey();
                        max_cnt = entry.getValue();
                    }
                }

                if (max_idx == -1) break; // 노래가 없으면 두 곡이 아니어도 바로 탈출

                answer.add(max_idx);

                genres_idx_cnt.get(max_genre).remove(max_idx);
            }

            genres_total.remove(max_genre);
        }

        return answer;
    }
}

// map.get(key), map.remove(key), map.containsKey(key): map은 key가 필요해
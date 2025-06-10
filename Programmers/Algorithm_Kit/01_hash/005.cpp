#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> answer;
    
    map<string, int> genres_plays; //장르별 재생 횟수
    map<string, map<int, int>> genres_idx_plays; //장르, 노래 번호별 재생 횟수

    for (int i = 0; i < genres.size(); i++) {
        genres_plays[genres[i]] += plays[i]; //장르별 재생 횟수
        genres_idx_plays[genres[i]][i] = plays[i]; //장르, 노래 번호별 재생 횟수
    }

    while (genres_plays.size() > 0) {
        string genre = ""; //최대 재생 횟수를 가진 장르
        int max = 0; //장르별 최대 재생 횟수

        for (pair<string, int> pi : genres_plays) {
            if (max < pi.second) {
                max = pi.second;
                genre = pi.first;
            }
        }

        for (int i = 0; i < 2; i++) {
            int play_cnt = 0; //노래 번호별 재생 횟수의 최댓값
            int idx = -1; //노래 번호

            for (pair<int, int> pi: genres_idx_plays[genre]) {
                if (play_cnt < pi.second) {
                    play_cnt = pi.second;
                    idx = pi.first;
                }
            }

            if (idx == -1) {
                break;
            }

            answer.push_back(idx);
            genres_idx_plays[genre].erase(idx); //연주된 노래 번호 제외
        }

        genres_plays.erase(genre); //두 곡이 연주된 장르 제외
    }

    return answer;
}

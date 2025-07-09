#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> answer;

    map<string, int> genres_plays; //장르(key) - 재생 횟수(value)
    map<string, map<int, int>> genres_idx_plays; //장르(key1) - 노래 번호(key2) - 재생 횟수(value)

    for (int i = 0; i < genres.size(); i++) {
        genres_plays[genres[i]] += plays[i]; //장르별 재생 횟수 저장
        genres_idx_plays[genres[i]][i] = plays[i]; //장르, 노래 번호별 재생 횟수 저장
    }

    while (genres_plays.size() > 0) {
        string genre = ""; //최대 재생 횟수를 가지는 장르
        int plays = 0; //해당 장르의 재생 횟수

        for (pair<string, int> pi : genres_plays) {
            if (plays < pi.second) {
                plays = pi.second;
                genre = pi.first;
            }
        }

        for (int i = 0; i < 2; i++) { //장르별로 2곡씩 선정
            int play_cnt = 0; //동일 장르 내 노래 번호별 최대 재생 횟수
            int idx = -1; //해당 재생 횟수를 가지는 노래 번호

            for (pair<int, int> pi : genres_idx_plays[genre]) {
                if (play_cnt < pi.second) {
                    play_cnt = pi.second;
                    idx = pi.first;
                }
            }

            if (idx == -1) {
                break;  
            }

            answer.push_back(idx); //노래 번호 저장
            genres_idx_plays[genre].erase(idx); //저장된 노래 번호는 genres_idx_plays에서 삭제
        }

        genres_plays.erase(genre); //저장된 장르는 genres_plays에서 삭제
    }

    return answer;
}

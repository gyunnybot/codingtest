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
    map<string, map<int, int>> genres_idx_plays; //장르(key) - {노래 번호(key') - 재생 횟수(value')}(value)

    for (int i = 0; i < genres.size(); i++) {
        genres_plays[genres[i]] += plays[i]; //장르별 재생 횟수 저장
        genres_idx_plays[genres[i]][i] = plays[i]; //장르, 노래 번호별 재생 횟수 저장
    }

    while (genres_plays.size() > 0) {
        string genre = ""; //최대 재생 횟수를 가지는 장르
        int play = 0; //재생 횟수

        //plays를 통해 장르 찾기
        for (pair<string, int> pi : genres_plays) {
            if (play < pi.second) {
                play = pi.second;
                genre = pi.first;
            }
        }

        //결정된 장르 내 2곡씩 선정
        for (int i = 0; i < 2; i++) {
            int max_play = 0; //동일 장르 노래들 중 최대 재생 횟수
            int max_idx = -1; //해당 재생 횟수를 가지는 노래 번호

            //max_play를 통해 노래 번호 찾기
            for (pair<int, int> pi : genres_idx_plays[genre]) {
                if (max_play < pi.second) {
                    max_play = pi.second;
                    max_idx = pi.first;
                }
            }

            //장르 내 노래가 없다면 break
            if (max_idx == -1) {
                break;
            }

            answer.push_back(max_idx); //노래 번호 저장
            genres_idx_plays[genre].erase(max_idx); //저장된 노래 번호는 genres_idx_plays에서 삭제
        }

        genres_plays.erase(genre); //저장된 장르는 genres_plays에서 삭제
    }

    return answer;
}

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> ump;

bool solution(vector<string> phone_book) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (string s : phone_book) {
        ump[s]++;
    }

    bool answer = true;
    bool flag = false;

    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = 1; j < phone_book[i].size(); j++) { //목록 내 같은 전화번호는 없으므로 size - 1까지 조사
            string temp = phone_book[i].substr(0, j);

            if (ump[temp]) {
                answer = false;
                flag = true;
                break;
            }
        }

        if (flag) break;
    }

    return answer;
}

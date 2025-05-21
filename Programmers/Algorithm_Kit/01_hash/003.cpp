#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> ump;

bool solution(vector<string> phone_book) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < phone_book.size(); i++) {
        ump[phone_book[i]]++;
    }

    bool answer = true;
    bool flag = false;

    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = 1; j < phone_book[i].size(); j++) { //같은 전화번호가 중복해서 들어있지 않습니다
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

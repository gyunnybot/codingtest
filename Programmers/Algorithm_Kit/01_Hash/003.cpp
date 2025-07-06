#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> ump;

bool solution(vector<string> phone_book) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    bool answer = true;

    for (string s : phone_book) {
        ump[s]++;
    }

    for (string s : phone_book) {
        for (int i = 1; i < s.size(); i++) {
            if (ump[s.substr(0, i)]) {
                answer = false;
                break;
            }
        }

        if (!answer) break;

    }

    return answer;
}

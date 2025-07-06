#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> ump;

string solution(vector<string> participant, vector<string> completion) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string answer = "";

    for (string s : participant) {
        ump[s]++;
    }

    for (string s : completion) {
        ump[s]--;
    }

    for (pair<string, int> pi : ump) {
        if (pi.second == 1) {
            answer = pi.first;
        }
    }

    return answer;
}

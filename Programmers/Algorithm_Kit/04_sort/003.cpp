#include <string>
#include <vector>
#include <iostream>
#include <algorithm> //sort
using namespace std;

int solution(vector<int> citations) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int answer = 0;

    sort(citations.begin(), citations.end(), greater<int>());

    if (citations[0] == 0) {
        answer = 0;
    }
    else {
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= i + 1) { //i + 1을 h로 가정 후 h-index 도출
                answer++;
            }
            else {
                break;
            }
        }
    }

    return answer;
}

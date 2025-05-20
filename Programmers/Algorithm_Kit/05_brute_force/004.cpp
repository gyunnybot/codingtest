#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> answer;
    
    int sum = brown + yellow;

    for (int i = 1; i <= sum; i++) {
        if (sum % i == 0) {
            int b = sum / i;
            int y = i;

            // 조건에 맞는 경우 찾기
            if ((b - 2) * (y - 2) == yellow) {
                answer.push_back(b);
                answer.push_back(y);
                break;
            }
        }
    }

    return answer;
}

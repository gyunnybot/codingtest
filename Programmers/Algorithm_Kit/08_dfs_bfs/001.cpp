#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer;

void recur(vector<int> numbers, int target, int idx, int cnt) {
    if (idx == numbers.size()) {
        if (cnt == target) {
            answer++;
        }

        return;
    }

    recur(numbers, target, idx + 1, cnt + numbers[idx]);
    recur(numbers, target, idx + 1, cnt - numbers[idx]);
}

int solution(vector<int> numbers, int target) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    recur(numbers, target, 0, 0);

    return answer;
}

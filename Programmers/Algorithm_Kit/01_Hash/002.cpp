#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> ust;

int solution(vector<int> nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int answer = nums.size() / 2;

    for (int i : nums) {
        ust.insert(i);
    }

    answer = min(answer, (int)ust.size());

    return answer;
}

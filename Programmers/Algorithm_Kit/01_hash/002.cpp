#include <vector>
#include <iostream>
#include <unordered_set>
#include <climits> //INT_MAX
using namespace std;

unordered_set<int> ust;

int solution(vector<int> nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int answer = nums.size() / 2;

    for (int num : nums) {
        ust.insert(num);
    }
    
    int temp = ust.size();

    answer = min(answer, (temp <= INT_MAX) ? temp : INT_MAX);

    return answer;
}

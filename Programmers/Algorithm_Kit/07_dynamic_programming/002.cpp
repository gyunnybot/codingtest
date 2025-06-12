#include <string>
#include <vector>
#include <iostream>
#include <algorithm> //max_element
using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int answer = 0;

    dp[1][1] = triangle[0][0];

    int n = triangle.size();

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i - 1][j - 1];
        }
    }

    answer = *(max_element(dp[n] + 1, dp[n] + n + 1));

    return answer;
}

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int row, col;

int solution(vector<vector<int>> sizes) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(vector<int> sz : sizes) {
        if (sz[0] < sz[1]) {
            swap(sz[0], sz[1]);
        }
        
        row = max(row, sz[0]);
        col = max(col, sz[1]);
    }
    
    int answer = row * col;
    
    return answer;
}

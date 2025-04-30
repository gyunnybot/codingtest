#include <string>
#include <vector>
#include <iostream>
#include <algorithm> //sort
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> answer;
    
    for(vector<int> cmd : commands) {
        vector<int> temp = array;
            
        sort(temp.begin() + (cmd[0] - 1), temp.begin() + (cmd[1]));
        
        answer.push_back(temp[(cmd[0] - 1) + (cmd[2] - 1)]);
    }
    
    return answer;
}

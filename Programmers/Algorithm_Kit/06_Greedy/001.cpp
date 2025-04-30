#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> ret(n, 1);
    
    for(int i : lost) {
        ret[i - 1]--;
    }
    
    for(int i : reserve) {
        ret[i - 1]++;
    }
    
    for(int i = 0; i < n; i++) {
        if(!ret[i]){
            if(i > 0 && ret[i - 1] == 2) {
                ret[i - 1]--;
                ret[i]++;
            }
            else if(i < n - 1 && ret[i + 1] == 2) {
                ret[i + 1]--;
                ret[i]++;
            }
        }
    }
    
    int answer = 0;
    
    for(int i : ret){
        if(i) {
            answer++;
        }
    }
    
    return answer;
}

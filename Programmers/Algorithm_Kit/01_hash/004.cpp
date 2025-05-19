#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> ump;

int solution(vector<vector<string>> clothes) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int answer = 1;
    
    for (vector<string> cloth : clothes) {
        ump[cloth[1]]++;
    }
    
    for (pair<string, int> pi : ump) {
        answer *= (pi.second + 1);
    }
    
    return answer - 1;
}

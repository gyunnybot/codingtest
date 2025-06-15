#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> ump;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(string s : participant) {
        ump[s]++;
    }
    
    for(string s : completion) {
        ump[s]--;
    }
    
    for(string s : participant) {
        if(ump[s]) {
            answer = s;
            break;
        }
    }
    
    return answer;
}

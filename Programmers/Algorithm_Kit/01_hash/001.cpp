#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string,int> ump;

string solution(vector<string> participant, vector<string> completion) {
    for(string s : participant) {
        ump[s]++;
    }

    for(string s : completion) {
        ump[s]--;
    }
    
    string answer = "";
    
    for(pair<string, int> pi : ump) {
        if(pi.second){
            answer = pi.first;
        }
    }
    
    return answer;
}

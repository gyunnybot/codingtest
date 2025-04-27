#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int> mp;

string solution(vector<string> participant, vector<string> completion) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(string s : participant) {
        mp[s]++;
    }
    
    for(string s : completion) {
        mp[s]--;
    }
    
    string answer = "";
    
    for(pair<string, int> pi : mp) {
        if(pi.second) {
            answer += pi.first;
        }
    }
    
    return answer;
}

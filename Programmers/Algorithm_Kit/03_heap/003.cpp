#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

multiset<int> mst;

vector<int> solution(vector<string> operations) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> answer;
    
    for(string s : operations) {
        if(s[0] == 'I') {
            mst.insert(atoi(s.substr(2).c_str()));
        }
        else {
            if(mst.empty()) continue;
            
            if(atoi(s.substr(2).c_str()) == 1) {
                mst.erase(prev(mst.end()));
            }
            else {
                mst.erase(mst.begin());
            }
        }
    }
    
    if(mst.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(*prev(mst.end()));
        answer.push_back(*mst.begin());
    }
    
    return answer;
}

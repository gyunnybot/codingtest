#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> ump;

bool solution(vector<string> phone_book) {
    for(int i=0; i < phone_book.size(); i++) {
           ump[phone_book[i]]++;
    }
    
    bool answer = true;
    bool flag = false;

    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = 0; j < phone_book[i].size() - 1; j++) {
            string temp = phone_book[i].substr(0, j + 1);

            if (ump[temp]){
                answer = false;
                flag = true;
                break;
            }
        }

        if(flag) break;
    }
    
    return answer;
}

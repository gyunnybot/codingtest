#include <string>
#include <vector>
#include <algorithm> //next_permutation
#include <set>
#include <iostream>
using namespace std;

set<int> st;
string temp;

bool check(int num) {
    if (num <= 1) return false;
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    
    return true;
}

void fix_num(string temp) {
    while (true) {
        if (temp[0] == '0') {
            temp.erase(0, 1);
        }
        else {
            break;
        }
    }
    
    return;
}

int solution(string numbers) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int answer = 0;
    
    sort(numbers.begin(), numbers.end());
    
    do {        
        for(int i = 0; i < numbers.size(); i++) {
            temp += numbers[i];
            
            fix_num(temp);
            
            if (check(atoi(temp.c_str()))) {
                st.insert(atoi(temp.c_str()));
            }
        }
        
        temp="";
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    answer = st.size();
    
    return answer;
}

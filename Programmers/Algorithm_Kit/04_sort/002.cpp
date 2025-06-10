#include <string>
#include <vector>
#include <iostream>
#include <algorithm> //sort
using namespace std;

vector<string> str_num;

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string answer = "";

    for (int i : numbers) {
        str_num.push_back(to_string(i));
    }

    sort(str_num.begin(), str_num.end(), cmp); //붙인 결과가 내림차순이 되도록 정렬

    if (str_num[0] == "0") { //가장 앞의 원소가 0이라면
        answer = "0";
    }
    else {
        for (string s : str_num) {
            answer += s;
        }
    }

    return answer;
}

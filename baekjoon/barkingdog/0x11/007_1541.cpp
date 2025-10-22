#include<iostream>
#include<vector>
using namespace std;

string s, num;
bool flag;
int ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;

    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '-' || s[i] == '+' || i == s.size()) {
            if (flag) {
                ret -= atoi(num.c_str()); //atoi(s.c_str()) : 문자열을 정수로 변환, 문자열일 시 0 반환
                num = "";
            }
            else {
                ret += atoi(num.c_str());
                num = "";
            }
        }
        else {
            num += s[i];
        }

        if (s[i] == '-') {
            flag = true;
        }
    }

    cout << ret;

    return 0;
}

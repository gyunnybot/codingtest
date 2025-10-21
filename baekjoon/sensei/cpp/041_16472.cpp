#include<iostream>
#include<unordered_map>
using namespace std;

int n, ret;
string s;
unordered_map<char, int> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> s;

    //컨테이너의 연결성(길이)이 중요할 때 사용되는 투 포인터 반복문 형식
    int st = 0;

    for (int ed = 0; ed < s.size(); ed++) {
        cnt[s[ed]]++; //오른쪽으로 이동하면서 문자 추가

        while (cnt.size() > n) {
            cnt[s[st]]--; //왼쪽 문자부터 지우기

            if (cnt[s[st]] == 0) { //value가 0이라면
                cnt.erase(s[st]); //map 내 원소 삭제
            }

            st++; //오른쪽으로 이동
        }

        ret = max(ret, ed - st + 1);
    }

    cout << ret;

    return 0;
}

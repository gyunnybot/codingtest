#include<iostream>
#include<map>
using namespace std;

int n, ret;
string s;
map<char, int> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> s;

    //컨테이너의 연결성(길이)이 중요할 때 사용되는 투 포인터 반복문 형식
    int st = 0;

    for (int ed = 0; ed < s.size(); ed++) {
        cnt[s[ed]]++; //오른쪽으로 이동하면서 문자 추가

        while (cnt.size() > n) {
            cnt[s[st]]--; //왼쪽 문자 지우기

            if (cnt[s[st]] == 0) {
                cnt.erase(s[st]); //value가 0이라면 map 원소 삭제
            }

            st++; //st 오른쪽으로 이동
        }

        ret = max(ret, ed - st + 1);
    }

    cout << ret;

    return 0;
}

#include<iostream>
#include<map>
using namespace std;

map<string, int> mp;
string s, e, q, t, name;
int ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s >> e >> q;

    while (cin >> t >> name) {
        if (t <= s) {
            mp[name] = 1;
        }
        else if (e <= t && t <= q) {
            if (mp[name] == 1) {
                ret++;
                mp[name] = 2; //시간 내 중복 채팅일 경우를 방지하기 위해
            }
        }
    }

    cout << ret;

    return 0;
}

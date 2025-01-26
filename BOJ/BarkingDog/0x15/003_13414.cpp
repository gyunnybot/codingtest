#include<iostream>
#include<map>
#include<vector>
#include<algorithm> //sort
using namespace std;

int k, L;
string pid;
map<string, int> mp;
vector<pair<string, int>> ret;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k >> L;

    for (int i = 0; i < L; i++) {
        cin >> pid;
        mp[pid] = i + 1; //값 - 순서
    }

    for (pair<string, int> pi : mp) {
        ret.push_back(pi);
    }

    sort(ret.begin(), ret.end(), cmp);

    //pid가 중복되어 k보다 ret의 갯수가 작아질 수 있다
    //min 비교를 위해 size_t 자료형인 ret을 int 자료형으로 변환
    for (int i = 0; i < min(k, (int)ret.size()); i++) {
        cout << ret[i].first << '\n';
    }

    return 0;
}

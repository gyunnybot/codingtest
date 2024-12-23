#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

int n, s, e, t, ret;
vector<pair<int, int>> debate;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second <= b.second;
    }
    else {
        return a.first < b.first;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        debate.push_back({ e,s });
    }

    sort(debate.begin(), debate.end(), cmp);

    for (int i = 0; i < n; i++) {
        if (t > debate[i].second) continue;

        t = debate[i].first;
        ret++;
    }

    cout << ret;

    return 0;
}

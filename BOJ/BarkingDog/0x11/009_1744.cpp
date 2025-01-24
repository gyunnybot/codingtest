#include<iostream>
#include<algorithm> //sort
#include<vector>
using namespace std;
typedef long long ll;

int n, m, t;
ll ret;
vector<int> minu, plu;

void oper(vector<int>& v) {
    while (1 < v.size()) {
        ret += (*(v.end() - 1)) * (*(v.end() - 2));
        v.pop_back();
        v.pop_back();
    }

    if (!v.empty()) {
        ret += v[0];
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t;

        if (t == 1) {
            ret++;
        }
        else if (0 < t) {
            plu.push_back(t);
        }
        else {
            minu.push_back(t);
        }
    }

    sort(plu.begin(), plu.end());
    sort(minu.begin(), minu.end(), greater<>());
    
    oper(plu);
    oper(minu);

    cout << ret;

    return 0;
}

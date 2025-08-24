#include<iostream>
#include<string>
#include<vector>
using namespace std;

int n, k, ret;
bool visited[26];
string word, s[51];

int count() {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        bool flag = true;

        for (char c : s[i]) {
            if (!visited[c - 'a']) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cnt++;
        }
    }

    return cnt;
}

void dfs(int idx, int cnt) {
    if (cnt == k) {
        ret = max(ret, count());

        return;
    }

    for (int i = idx; i < 26; i++) {
        if (!visited[i]) {
            visited[i] = true;

            dfs(i + 1, cnt + 1);

            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    if (k < 5) {
        cout << 0;
        return 0;
    }

    if (k == 26) {
        cout << n;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> word;

        s[i] = word.substr(4, word.size() - 8); //anta, tica 자르기
    }

    visited['a' - 'a'] = true;
    visited['n' - 'a'] = true;
    visited['t' - 'a'] = true;
    visited['i' - 'a'] = true;
    visited['c' - 'a'] = true;

    dfs(0, 5);

    cout << ret;

    return 0;
}

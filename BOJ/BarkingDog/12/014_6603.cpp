#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

int n, m, a[10001];
vector<int> v;
vector<bool> visited(10001, false);

void print(vector<int>& v) {
    for (int i : v) {
        cout << i << ' ';
    }

    cout << '\n';

    return;
}

void combi(int start, vector<int>& v, vector<bool>& visited) {
    if (v.size() == 6) { //back tracking
        print(v);
        return;
    }

    for (int i = start + 1; i < n; i++) {
        if (visited[i]) continue;

        v.push_back(a[i]);
        visited[i] = true;        

        combi(i - 1, v, visited);

        v.pop_back();
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        combi(-1, v, visited);

        cout << '\n';
    }

    return 0;
}

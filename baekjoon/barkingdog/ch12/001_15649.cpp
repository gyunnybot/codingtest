#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<int> v;
vector<bool> visited(10, false);

void print(vector<int>& v) {
    for (int i : v) {
        cout << i << ' ';
    }

    cout << '\n';

    return;
}

void combi(int start, vector<int>& v, vector<bool>& visited) {
    if (v.size() == m) { //back tracking
        print(v);
        return;
    }

    for (int i = start + 1; i <= n; i++) {
        if (visited[i]) continue;

        v.push_back(i);
        visited[i] = true;

        combi(start, v, visited);

        v.pop_back();
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    combi(0, v, visited);

    return 0;
}

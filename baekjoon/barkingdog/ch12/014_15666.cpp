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
    if (v.size() == m) { //back tracking
        print(v);
        return;
    }    

    int pre = 0; //입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다

    for (int i = start + 1; i < n; i++) {
        //if (visited[i]) continue;
        if (a[i] == pre) continue;

        pre = a[i];

        v.push_back(a[i]);
        //visited[i] = true;        

        combi(i - 1, v, visited);

        v.pop_back();
        //visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    combi(-1, v, visited);

    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

int L, c;
char a[16];
vector<char> v;
vector<bool> visited(26, false);

void print(vector<char>& v) {
    for (char c : v) {
        cout << c;
    }

    cout << '\n';

    return;
}

bool check(vector<char>& v) {
    int vowel = 0;
    int consonant = 0;

    for (char c : v) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowel++;
        }
        else {
            consonant++;
        }
    }

    if (vowel < 1 || consonant < 2) {
        return false;
    }

    return true;    
}

void combi(int start, vector<char>& v, vector<bool>& visited) {
    if (v.size() == L) { //back tracking
        if (check(v)) {
            print(v);
        }

        return;
    }

    for (int i = start + 1; i < c; i++) {
        if (visited[a[i] - 'a']) continue;

        v.push_back(a[i]);
        visited[a[i] - 'a'] = true;

        combi(i, v, visited);

        v.pop_back();
        visited[a[i] - 'a'] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> L >> c;

    for (int i = 0; i < c; i++) {
        cin >> a[i];
    }

    sort(a, a + c);

    combi(-1, v, visited);

    return 0;
}

#include<iostream>
using namespace std;

int n;
char node, L, R;
pair<char, char> adj[26];

void pre_order(char here) {
    if (here == '.') return;

    cout << here;
    pre_order(adj[here - 'A'].first);
    pre_order(adj[here - 'A'].second);
}

void in_order(char here) {
    if (here == '.') return;

    in_order(adj[here - 'A'].first);
    cout << here;
    in_order(adj[here - 'A'].second);
}

void post_order(char here) {
    if (here == '.') return;

    post_order(adj[here - 'A'].first);
    post_order(adj[here - 'A'].second);
    cout << here;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> node >> L >> R;

        adj[node-'A'].first = L;
        adj[node - 'A'].second = R;
    }

    pre_order('A'); cout << '\n';
    in_order('A'); cout << '\n';
    post_order('A');
    
    return 0;
}

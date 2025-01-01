#include<iostream>
#include<queue> //priority_queue
using namespace std;

class cmp {
public:
    bool operator() (int a, int b) {
        if (abs(a) != abs(b)) {
            return abs(a) > abs(b);
        }
        else {
            return a > 0 && b < 0;
        }
    }
};

priority_queue<int, vector<int>, cmp> pq;
int n, x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    while (n--) {
        cin >> x;

        if (x == 0) {
            if (pq.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }

    return 0;
}

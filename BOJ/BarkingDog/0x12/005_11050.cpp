#include <iostream>
using namespace std;

int n, k;

//무식하게 이항 계수 (n,k) 구현
int facto(int n, int k) {
    int ret1 = 1;

    for (int i = 0; i < k; i++) {
        ret1 *= n;
        n--;
    }

    int ret2 = 1;

    for (int i = 0; i < k; i++) {
        ret2 *= (i + 1);
    }

    return ret1 / ret2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    
    cout << facto(n, k);

    return 0;
}
#include<iostream>
#include<algorithm> //reverse
using namespace std;

string a, b, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int n = max(a.size(), b.size());
    int carry = 0;

    for (int i = 0; i < n; i++) {
        int digit_a = (i < a.size() ? a[i] - '0' : 0);
        int digit_b = (i < b.size() ? b[i] - '0' : 0);

        int sum = digit_a + digit_b + carry;

        ret.push_back(sum % 10 + '0');

        carry = sum / 10;
    }

    if (carry) {
        ret.push_back(carry + '0');
    }

    reverse(ret.begin(), ret.end());

    cout << ret;

    return 0;
}

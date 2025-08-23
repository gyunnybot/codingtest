#include<iostream>
#include<algorithm> //sort
using namespace std;

int a[9], sum;
pair<int, int> not_dwarf;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a + 9); //일곱 난쟁이의 키를 오름차순으로 출력한다

    bool flag = false;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < i; j++) {
            if (sum - a[i] - a[j] == 100) {
                not_dwarf = { i,j };

                flag = true;

                break;
            }
        }

        if (flag) break;
    }

    for (int i = 0; i < 9; i++) {
        if (i == not_dwarf.first || i == not_dwarf.second) continue;

        cout << a[i] << '\n';
    }

    return 0;
}

#include<iostream>
#include<algorithm> //sort, next_permutation
using namespace std;

int a[9];
pair<int, int> not_dwarf;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        cin >> a[i];
    }

    sort(a, a + 9); //일곱 난쟁이의 키를 오름차순으로 출력한다. 또한 next_permutation은 정렬이 선행되어야 한다

    do {
        int sum = 0;

        for (int i = 0; i < 7; i++) {
            sum += a[i];
        }

        if (sum == 100) break;
    } while (next_permutation(a, a + 9));

    for (int i = 0; i < 7; i++) {
        cout << a[i] << '\n';
    }

    return 0;
}

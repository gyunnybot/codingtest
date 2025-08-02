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

    sort(a, a + 9); //먼저 정렬하지 않으면 7개의 원소를 담는 순서 벡터를 다시 정의해야 한다

    bool flag = false;
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < i; j++) {
            if (sum - a[i] - a[j] == 100) {                
                not_dwarf = { i,j };

                flag = true;

                break;
            }
        }

        if(flag) break;
    }

    for (int i = 0; i < 9; i++) {
        if (i == not_dwarf.first || i == not_dwarf.second) continue;
        cout << a[i] << '\n';
    }

    return 0;
}

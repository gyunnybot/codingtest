#include<iostream>
#include<algorithm> //sort
using namespace std;
typedef long long ll;

int n, ret;
ll a[100001], x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int st = 0;
    int ed = n - 1;
    int temp = 0;

    //단독으로 x가 되는 용기 제외
    while (ed >= 0 && a[ed] >= x) {
        ret++;
        ed--;
    }

    while (st <= ed) {
        if (st == ed) { //하나의 용기만 남은 경우
            temp++;
            break;
        }
        else {
            if (a[st] + a[ed] >= (x + 1) / 2) { //두 개의 용기를 교환해 x를 만들 수 있는 경우
                ret++;
                st++;
                ed--;
            }
            else {
                temp++; //현재 a[ed]와 결합해도 (x + 1) / 2가 되지 않는 a[st]의 개수
                st++;
            }
        }        
    }

    /**
     * 1. temp 2개로 x / 2 이상 x 미만의 용기 생성
     * 2. temp 1개를 추가로 사용해 x가 되는 용기 완성
     */
    cout << ret + temp / 3;

    return 0;
}

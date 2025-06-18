#include<iostream>
using namespace std;

const int NOT_VISITED = 0;
const int VISITED = 1;
const int IN_CYCLE = 2;
const int NOT_IN_CYCLE = 3;
int t, n, a[100001], state[100001];

void set_state(int here) {
    int cur = here;

    while (true) {
        state[cur] = VISITED;
        cur = a[cur];

        //돌고돌아 cur를 재방문했는데 cur = here인 경우, here는 사이클에 속해있다
        if (state[cur] == VISITED && cur == here) {
            while (state[cur] != IN_CYCLE) { //생성된 사이클을 전부 돌 때까지
                state[cur] = IN_CYCLE; //사이클에 속하는 state를 IN_CYCLE으로 변경
                cur = a[cur];
            }

            return;
        }

        //돌고돌아 cur를 재방문했지만 cur != here인 경우, here는 사이클에 속하지 않는다
        if (state[cur] == VISITED && cur != here) {
            while (state[cur] != IN_CYCLE) { //생성된 사이클을 전부 돌 때까지
                state[cur] = IN_CYCLE; //사이클에 속하는 state를 IN_CYCLE으로 변경
                cur = a[cur];
            }

            cur = here; //here에서 다시 시작

            while (state[cur] != IN_CYCLE) { //IN_CYCLE인 cur를 만날 때까지
                state[cur] = NOT_IN_CYCLE; //here부터 현재 state를 visited에서 NOT_IN_CYCLE으로 변경
                cur = a[cur];
            }

            return;
        }

        //cur가 이미 사이클인지 아닌지 판별났을 때
        if (state[cur] == IN_CYCLE || state[cur] == NOT_IN_CYCLE) {
            cur = here; //here부터 다시 시작

            //전부 NOT_IN_CYCLE으로 변경
            while (state[cur] == VISITED) {
                state[cur] = NOT_IN_CYCLE;
                cur = a[cur];
            }

            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n;

        fill(&state[0], &state[0] + 100001, NOT_VISITED);

        int ret = 0;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++) {
            if (state[i] == NOT_VISITED) {
                set_state(i);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (state[i] == NOT_IN_CYCLE) {
                ret++;
            }
        }

        cout << ret << '\n';
    }

    return 0;
}

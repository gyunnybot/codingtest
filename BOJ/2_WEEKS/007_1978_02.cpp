#include<iostream>
using namespace std;

int n, num, ret;
bool chae[1001]; //수는 1,000 이하의 자연수이다

//에라토스테네스의 체
void era(int num) {
	chae[0] = false;
	chae[1] = false;

	for (int i = 2; i <= num; i++) {
		chae[i] = true;
	}

	for (int i = 2; i <= num; i++) {
		if (!chae[i]) continue;

		for (int j = i + i; j <= num; j += i) {
			chae[j] = false;
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	era(1000); //수는 1,000 이하의 자연수이다

    cin >> n;
    
	for (int i = 0; i < n; i++) {
		cin >> num;

		if (chae[num]){
             ret++;
        }
	}

	cout << ret;

	return 0;
}

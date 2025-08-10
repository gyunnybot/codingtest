#include<iostream>
using namespace std;

int x, ret;
int sticks[] = { 64,32,16,8,4,2,1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x;

	for (int i : sticks) {
		if (i > x) {
			continue;
		}
		else {
			x -= i;
			ret++;
		}
	}

	cout << ret;

	return 0;
}

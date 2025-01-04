#include<iostream>
#include<algorithm> //sort
using namespace std;

int n;
string a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> a >> b;

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		if (a == b) {
			cout << "Possible\n";
		}
		else {
			cout << "Impossible\n";
		}
	}

	return 0;
}

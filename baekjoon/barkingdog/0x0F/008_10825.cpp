#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

struct info {
	string name;
	int kor, eng, math;
};
vector<info> v;

int n, kor, eng, math;
string name;

bool cmp(info a, info b) {
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.math == b.math) {
				return a.name < b.name;
			}
			else {
				return a.math > b.math;
			}
		}
		else {
			return a.eng < b.eng;
		}
	}
	else {
		return a.kor > b.kor;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> name >> kor >> eng >> math;
		v.push_back({ name,kor,eng,math });
	}

	sort(v.begin(), v.end(), cmp);

	for (info i : v) {
		cout << i.name << '\n';
	}

	return 0;
}

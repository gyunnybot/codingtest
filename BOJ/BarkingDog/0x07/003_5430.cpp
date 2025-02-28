#include<iostream>
#include<deque>
#include<algorithm> //reverse
using namespace std;

int t, n;
string p, x;

deque<string> split(string input, string delimiter) {
	deque<string> result;

	int start = 0;
	int end = input.find(delimiter);

	while (end != string::npos) {
		result.push_back(input.substr(start, end - start)); //string.substr(시작 인덱스 번호, 범위)

		start = end + delimiter.size();
		end = input.find(delimiter, start); //string.find(찾을 문자열, 시작 인덱스 번호)
	}

	result.push_back(input.substr(start));

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> p >> n >> x;

		string test_str = "";
		deque<string> ret_str;

		bool flag = false;
		bool reversed = false;

		for (int i = 1; i < x.size() - 1; i++) { //괄호 제거 후 test_str에 저장
			test_str += x[i];
		}

		if (!test_str.empty()) {
			ret_str = split(test_str, ","); //","를 기준으로 문자열 split 후 ret_str에 저장
		}

		for (char c : p) {
			if (c == 'R') {
				reversed = !reversed; //reverse 상태 변경
			}
			else if (c == 'D') {
				if (ret_str.empty()) {
					flag = true; //배열이 비었는데 D가 호출될 경우 error
					break;
				}
				else { //비어있지 않은 경우 반전 상태에 따라 pop의 위치 결정
					if (reversed) {
						ret_str.pop_back();
					}
					else {
						ret_str.pop_front();
					}
				}
			}
		}

		if (reversed) {
			reverse(ret_str.begin(), ret_str.end()); //최종 출력을 위한 reverse 연산
		}

		if (flag) { //배열에 값이 없는데 D가 호출되었던 경우
			cout << "error" << '\n';
		}
		else {
			if (ret_str.empty()) { //배열에 값이 없는데 R이 호출된 경우
				cout << "[]" << '\n';
			}
			else { //배열의 값이 남아있을 때 D, R 연산 결과 출력
				cout << '[';

				cout << ret_str.front();
				ret_str.pop_front();

				while (!ret_str.empty()) {
					cout << ',' << ret_str.front();
					ret_str.pop_front();
				}

				cout << ']' << '\n';
			}
		}
	}

	return 0;
}

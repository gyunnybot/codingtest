#include<iostream>
using namespace std;

int arr[5] = { 1,5,2,4,3 }; //10 이하의 자연수 5개로 이루어진 배열이라고 가정
int temp[5], cnt[11];
const int n = sizeof(arr) / sizeof(int);

void print(int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}

	cout << '\n';

	return;
}

void merge(int st, int ed) {
	int mid = (st + ed) / 2;
	int left_idx = st;
	int right_idx = mid;

	for (int i = st; i < ed; i++) {
		if (right_idx == ed) {
			temp[i] = arr[left_idx];
			left_idx++;
		}
		else if (left_idx == mid) {
			temp[i] = arr[right_idx];
			right_idx++;
		}
		else if (arr[left_idx] <= arr[right_idx]) {
			temp[i] = arr[left_idx];
			left_idx++;
		}
		else {
			temp[i] = arr[right_idx];
			right_idx++;
		}
	}

	for (int i = st; i < ed; i++) {
		arr[i] = temp[i];
	}

	return;
}

void merge_sort(int st, int ed) {
	if (st + 1 == ed) {
		return;
	}

	int mid = (st + ed) / 2;

	merge_sort(st, mid);
	merge_sort(mid, ed);

	merge(st, ed);
}

void quick_sort(int st, int ed) {
	if (st + 1 >= ed) {
		return;
	}

	int pivot = arr[st];
	int left_idx = st + 1;
	int right_idx = ed - 1;

	while (true) {
		while (left_idx <= right_idx && arr[left_idx] <= pivot) {
			left_idx++;
		}

		while (left_idx <= right_idx && arr[right_idx] >= pivot) {
			right_idx--;
		}

		if (left_idx > right_idx) {
			break;
		}

		swap(arr[left_idx], arr[right_idx]);
	}

	swap(arr[st], arr[right_idx]);

	quick_sort(st, right_idx);
	quick_sort(right_idx + 1, ed);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//select sort. O(N ^ 2)
	for (int i = n - 1; i > 0; i--) {
		swap(*max_element(arr, arr + i + 1), arr[i]); //swap : call by reference. O(1)
	}

	//bubble sort. O(N ^ 2)
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]); //swap : call by reference. O(1)
			}
		}
	}
	
	//merge sort. O(NlogN)
	merge_sort(0, n);
	
	//quick sort. O(NlogN ~ N ^ 2)
	quick_sort(0, n);

	print(n);

	/*----------------------------------------------------*/

	//counting sort. O(수의 범위 N + 입력된 수의 갯수 K)
	for (int i = 0; i < n; i++) {
		cnt[arr[i]]++;
	}

	for (int i = 1; i <= 10; i++) { //10 이하의 자연수 5개로 이루어진 배열 arr
		while (cnt[i]--) {
			cout << i << ' ';
		}
	}

	return 0;
}

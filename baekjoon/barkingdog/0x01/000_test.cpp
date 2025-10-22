#include<iostream>
using namespace std;

//O(N)
int func1(int N) {
    int ret = 0;

    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            ret += i;
        }
    }

    return ret;
}

//O(1)
int func1_1(int N) {
    int ret = (3 * (N / 3) * ((N / 3) + 1) / 2) + (5 * (N / 5) * ((N / 5) + 1) / 2)
        - (15 * (N / 15) * ((N / 15) + 1) / 2);

    return ret;
}

//O(N ^ 2)
int func2(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] + arr[j] == 100) {
                return 1;
            }
        }
    }

    return 0;
}

//O(N)
int func2_1(int arr[], int N) {
    int cnt[101] = {};

    for (int i = 0; i < N; i++) {
        cnt[arr[i]]++;

        if (cnt[100 - arr[i]] && arr[i] != 50) {
            return 1;
        }
    }

    return 0;
}

//O(sqrt(N))
int func3(int N) {
    for (int i = 1; i * i <= N; i++) {
        if (i * i == N) {
            return 1;
        }
    }

    return 0;
}

//O(logN)
int func3_1(int N) {
    int left = 1;
    int right = N;

    while (left <= right) {
        int mid = (left + right) / 2;
        long long ret = 1LL * mid * mid; //casting
        
        if (ret == N) {
            return 1;
        }
        else if (ret < N) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return 0;
}

//O(logN)
int func4(int N) {
    int val = 1;

    while (2 * val <= N) {
        val *= 2;
    }

    return val;
}

void test1() {
    cout << "****** func1 test ******\n";
    int n[3] = { 16, 34567, 27639 };
    int ans[3] = { 60, 278812814, 178254968 };
    for (int i = 0; i < 3; i++) {
        int result = func1(n[i]);
        //int result = func1_1(n[i]);
        cout << "TC #" << i << '\n';
        cout << "expected : " << ans[i] << " result : " << result;
        if (ans[i] == result) cout << " ... Correct!\n";
        else cout << " ... Wrong!\n";
    }
    cout << "*************************\n\n";
}

void test2() {
    cout << "****** func2 test ******\n";
    int arr[3][4] = { {1,52,48}, {50,42}, {4,13,63,87} };
    int n[3] = { 3, 2, 4 };
    int ans[3] = { 1, 0, 1 };
    for (int i = 0; i < 3; i++) {
        int result = func2(arr[i], n[i]);
        //int result = func2_1(arr[i], n[i]);
        cout << "TC #" << i << '\n';
        cout << "expected : " << ans[i] << " result : " << result;
        if (ans[i] == result) cout << " ... Correct!\n";
        else cout << " ... Wrong!\n";
    }
    cout << "*************************\n\n";
}

void test3() {
    cout << "****** func3 test ******\n";
    int n[3] = { 9, 693953651, 756580036 };
    int ans[3] = { 1, 0, 1 };
    for (int i = 0; i < 3; i++) {
        int result = func3_1(n[i]);
        cout << "TC #" << i << '\n';
        cout << "expected : " << ans[i] << " result : " << result;
        if (ans[i] == result) cout << " ... Correct!\n";
        else cout << " ... Wrong!\n";
    }
    cout << "*************************\n\n";
}

void test4() {
    cout << "****** func4 test ******\n";
    int n[3] = { 5, 97615282, 1024 };
    int ans[3] = { 4, 67108864, 1024 };
    for (int i = 0; i < 3; i++) {
        int result = func4(n[i]);
        cout << "TC #" << i << '\n';
        cout << "expected : " << ans[i] << " result : " << result;
        if (ans[i] == result) cout << " ... Correct!\n";
        else cout << " ... Wrong!\n";
    }
    cout << "*************************\n\n";
}

int main(void) {
    test1();
    test2();
    test3();
    test4();
}

# 정렬
코테에서는 그냥 sort쓰면 된다.

일반 배열 []에서 new int[100001];처럼 미리 하드코딩된 배열에 값 입력 후 정렬 시, sort(arr, 0, n)으로 **범위 지정 필수!**

양수만 받는 경우, 다 짜놓고 결과가 0 0 0 0 0... 이렇게 나온다. 반드시 범위 지정 필수

<br>

### 범위를 정해서 진행하는 정렬

일반 [] 배열 : Arrays.sort(arr, 0, n);

List 컬랙션 배열 : **Collections.sort(arr.subList(0, n));**

<br>

### reverseOrder()
일반 [] 배열도 **래퍼(Integer 등) 타입으로 정의되었다면**,
Collections.reverseOrder()를 두 번째 인자(범위 정렬이 있을 시 네 번째 인자)로 추가해서 역정렬을 진행할 수 있다.
그러나 원시 타입은 사용할 수 없다.

```java
public static void main(String[] args) throws IOException {
    Integer[] arr = new Integer[11]; // 일반 [] 배열이지만 래퍼형

    arr[0] = 1;
    arr[1] = 4;
    arr[2] = 3;
    arr[3] = 2;

    Arrays.sort(arr, 0, 4, Collections.reverseOrder());

    for (int i = 0; i < 4; i++) {
        System.out.println(arr[i]);
    } // 4 3 2 1
}
```

<br>

### pair(객체) 정렬
java에서는 pair 없다. 클래스를 따로 정의해줘야 하고, 기본 정렬 기준이 필요하다면 Comparable 인터페이스를 구현한다.

보통 y, x 좌표나 시작과 끝 등을 저장할 때 만든다.

```java
class Pair implements Comparable<Pair> {
    int start;
    int end;

    public Pair(int start, int end) {
        this.start = start;
        this.end = end;
    }

    @Override
    public int compareTo(Pair other) {
        if(this.end == other.end) { // 끝나는 시각이 같다면
            return Integer.compare(this.start, other.start); // 시작 시각이 빠른 순
        }

        return Integer.compare(this.end, other.end); // 오름차순 정렬
    }
}
```

<br>

Comparable, Comparator 차이 :

	Comparable은 클래스의 기본 정렬 설정이다. compareTo를 재정의한다. Comparator는 sort 메서드에 인자로 들어가는 클래스다. compare 메서드를 재정의한다.

실전에서는 람다 표현식으로 Comparator가 들어가는 두 번째 파라미터에서 직접 구현하는 것을 기본으로 한다.

<br>

### 정렬 알고리즘 정리

<br>

선택 정렬 : O(N^2)

```java
for (int i = 0; i < n; i++) {
	int minIdx = i;
	
	for(int j = i + 1; j < n; j++) {
		if (a[j] < a[minIdx]) { // 현재 값이 minIdx의 것보다 작다면 현재 idx가 minIdx
			minIdx = j;
		}
	}
	
	int temp = a[minIdx];
	a[minIdx] = a[i];
	a[i] = temp;
}
```

<br>

삽입 정렬 : O(N^2)

```java
for (int i = 1; i < n; i++) {
    int key = a[i]; // 현재 삽입될 숫자를 key 변수에 복사
    int j = i - 1;

    // 현재 선택된 key가 이전 원소보다 작다면, 이전 원소를 뒤로 한 칸 이동
    while (j >= 0 && a[j] > key) {
        a[j + 1] = a[j];
        j--;
    }

    // j가 멈춘 지점 바로 뒤에 key를 삽입
    a[j + 1] = key;
}
```

<br>

버블 정렬 : O(N^2)

```java
for (int i = 0; i < n ; i++) {
	for (int j = 0 ; j < n - i - 1; j++) {
		if (a[j] > a[j + 1]) { // 현재 것이 다음 것보다 크다면 swap
			int temp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = temp;
		}
	}
}
```

<br>

병합 정렬 : O(NlogN)

```java
int[] temp = new int[4]; // 전체 저장 임시 테이블 필요

void merge_sort(int st, int ed) { // 4개의 원소 정렬? merge_sort(0, 4);
	if (st + 1 >= ed) {
		return;
	}
	
	int mid = (st + ed) / 2;
	
	merge_sort(st, mid);
	merge_sort(mid, ed);
	merge(st, ed);
}

void merge(int st, int ed) {
	int mid = (st + ed) / 2;
	int l = st;
	int r = mid;
	
	for (int i = st; i < ed ; i++) {
		if (r == ed) {
			temp[i] = a[l++];
		} else if (l == mid) {
			temp[i] = a[r++];
		} else if (a[l] <= a[r]) {
			temp[i] = a[l++];
		} else {
			temp[i] = a[r++];
		}
	}
	
	for (int i = st; i < ed; i++) {
		a[i] = temp[i];
	}
}
```

<br>

퀵 정렬 : O(NlogN~N^2)

```java
void quick_sort(int st, int ed) { // 4개의 원소 정렬? quick_sort(0, 4)
	if (st + 1 >= ed) {
		return;
	}
	
	int pivot = arr[st];
	int l = st + 1;
	int r = ed - 1;
	
	while (true) {
		while (l <= r && arr[l] <= pivot) l++; // pivot보다 arr[l]이 크지 않으면 l 증가
		while (l <= r && arr[r] >= pivot) r--;
		
		if(l > r) break;
		
		// a[left] - a[right] 교환
		int temp = arr[l];
		arr[l] = arr[r];
		arr[r] = temp;
	}
	
	// a[st] - a[right] 교환
	int temp = arr[st];
	arr[st] = arr[r];
	arr[r] = temp;
	
	quick_sort(st, r); // st ~ r
	quick_sort(r + 1, ed); // r+1 ~ ed
}
```

<br>

카운팅 정렬 : O(N + K) (N = 수의 개수, K = 수의 범위)

```java
// 입력되는 수는 자연수이고 K 이하라고 가정

for (int i = 0; i < n; i++) {
	cnt[arr[i]]++;
}

for (int i = 1; i <= k; i++) {
	while (cnt[i]--) {
		System.out.println(i);
	}
}
```
# 백트래킹

현재 상태에서 가능한 모든 후보군 전체를 따라 들어가 실행하는 알고리즘

일반적으로 중복 방지와 원상 복구를 위해 원본 배열에 추가로 visited 배열이 필요하다. 안쓰는 사람도 있던데, 나는 쓰는게 마음 편하다.

### 값 조합
n 이하의 자연수 중 중복 없이 m개의 숫자 뽑기. 호출은 combination(0)으로 고정

```java
static void combination(int start) {
    if (arrayList.size() == m) {
        for (int num : arrayList) {
            sb.append(num).append(" ");
        }

        sb.append("\n");

        return;
    }

    for (int i = start + 1; i <= n; i++) { // 1 <= i <= n
        if (visited[i]) { // visited는 값을 통제한다
            continue;
        }

        arrayList.add(i);
        visited[i] = true;

        combination(i);

        arrayList.remove(arrayList.size() - 1);
        visited[i] = false;
    }
}
```

지금은 for 문에 의해 중복되는 경우는 포함되지 않아 visited가 필요없지만, 습관을 이렇게 들이는게 속 편함. **for 문에서의 i 시작점, combination(value)에서 value에 들어가는 값**에 따라 다양한 조합을 생성할 수 있는데, visited가 필요할 때가 분명 있음

### 인덱스 조합
n개의 숫자 중 중복 없이 m개의 숫자 뽑기. 호출은 combinationIdx(-1)으로 고정

```java
static void combinationIdx(int start) {
    if (arrayList.size() == m) {
        for (int num : arrayList) {
            sb.append(num).append(" ");
        }

        sb.append("\n");

        return;
    }

    for (int i = start + 1; i < n; i++) { // 0 <= i < n
        if (visited[i]) { // visited는 인덱스를 통제한다
            continue;
        }

        arrayList.add(arr[i]);
        visited[i] = true;

        combinationIdx(i);

        arrayList.remove(arrayList.size() - 1);
        visited[i] = false;
    }
}
```

정렬된 결과를 보여주고 싶다면 우선 arr을 정렬 후 combination을 진행하면 된다

### 은근 많이 나오는 재귀 전체 탐색
쭉 탐색하면서 이 값을 포함하냐? 안하냐? O(2^N)로 시간복잡도 높지만, 직관적이다.

```java
void recur(int idx, int sum) {
    if (idx == n) {
        if (sum == s) {
            ret++;        
        }

        return;
    }

    recur(idx + 1, sum + a[idx]);
    recur(idx + 1, sum);
}
```

### n-Queen 문제로 보는 백트래킹 예시

```java
public static void main(String[] args) throws IOException {
    n = cs.nextInt();

    queen(0); // 0행부터 시작해보자

    System.out.println(ret);
}

static void queen(int r) {
    if (r == n) { // 모든 행을 채우고 n에 도달했다면
        ret++;

        return;
    }

    for (int c = 0; c < n; c++) {
        col[r] = c; // r행의 열(column)은 c다

        if (check(r)) { // r행 괜찮은지 체크
            queen(r + 1); // 체크 통과하면 다음 queen으로
        }
    }
}

static boolean check(int r) {
    for (int i = 0; i < r; i++) { // 이전 행들에 대해 검사
        if (col[i] == col[r] || Math.abs(r - i) == Math.abs(col[r] - col[i])) { // 같은 열이거나 대각선
            return false;
        }
    }
    
    return true;
}
```
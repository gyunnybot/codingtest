# 유니온 파인드

뭔가, 컴포넌트끼리 합치려고 할 때 떠올리면 좋을 알고리즘이다.

<br>

### BOJ 1717 : 집합의 표현
```
// 입출력 예시

7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1

NO
NO
YES
```

```java
import java.io.*;
import java.util.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static int n, m, q, a, b;
    static int[] parent = new int[1000001];
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        Arrays.fill(parent, -1);

        n = cs.nextInt();
        m = cs.nextInt();

        for (int i = 0; i < m; i++) {
            q = cs.nextInt();
            a = cs.nextInt();
            b = cs.nextInt();

            if (q == 0) {
                uni(a, b);
            } else {
                if (find(a) == find(b)) {
                    sb.append("YES\n");
                } else {
                    sb.append("NO\n");
                }
            }
        }

        System.out.println(sb.toString());
    }
    
    static int find(int x) {
        if (parent[x] < 0) {
            return x;
        }

        return find(parent[x]);
    }

    static boolean uni(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) {
            return false;
        }

        if (parent[u] > parent[v]) {
            int temp = u;
            u = v;
            v = temp;
        }

        if (parent[u] == parent[v]) {
            parent[u]--;
        }

        parent[v] = u;

        return true;
    }

    static class CustomScanner {
        private final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        private StringTokenizer st;

        String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                String line = br.readLine();

                if (line.isEmpty()) {
                    continue;
                }

                st = new StringTokenizer(line);
            }

            return st.nextToken();
        }

        Integer nextInt() throws IOException {
            String s = next();

            return Integer.parseInt(s);
        }
    }
}

```

<br>

### Arrays.fill, Collections.fill 정리
일반 배열 [], 컬랙션 모두 사용 가능하다.
```java
// 1차원 배열의 경우
int[] parent = new int[5];

Arrays.fill(parent, -1);

// 2차원 배열의 경우
int[][] parent = new int[5][5];

for (int[] row : parent) {
    Arrays.fill(row, -1);
}
```
```java
List<String> list = new ArrayList<>();
list.add("A");
list.add("B");
list.add("C");

// 모든 요소를 "X"로 채우기
Collections.fill(list, "X");

System.out.println(list); // 출력: [X, X, X]
```
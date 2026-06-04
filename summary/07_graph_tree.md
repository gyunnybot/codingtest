# 그래프, 트리
### 그래프에서 쓰이는 자료구조 정리
```
우선순위 큐 : PriorityQueue<Integer> pq = new PriorityQueue<>();

pq.offer(x); // 우선순위 큐에 x 삽입
pq.poll(); // 맨 위 요소 반환 후 삭제
pq.peek(); // 맨 위 요소 조회만


큐 : Queue<Integer> q = new ArrayDeque<>();

q.offer(x) // 큐에 x 삽입
q.poll(); // 맨 앞 요소 반환 후 삭제
q.peek(); // 맨 앞 요소 조회만


스택 : Deque<Integer> st = new ArrayDeque<>();

st.push(x); // 스택에 x 삽입
st.poll(); // 맨 위 요소 반환 후 삭제
st.peek(); // 맨 위 요소 조회만


배열 연결리스트 : List<Integer>[] adj = new ArrayList[n];

adj[i].add(x); // i 번째 연결리스트(노드)에 x와의 연결 관계 추가
adj[i].remove(adj[i].size() - 1); // 가장 마지막 원소 제거
```

<br>

### BOJ 11724 : 연결 요소의 개수
```java
public class Main {
    static CustomScanner cs = new CustomScanner();
    static int n, m, ret;
    static List<Integer>[] adj = new ArrayList[1001];
    static boolean[] visited = new boolean[1001];

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();
        m = cs.nextInt();

        // 1 ~ n까지의 인접 리스트 초기화
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            int a = cs.nextInt();
            int b = cs.nextInt();

            adj[a].add(b);
            adj[b].add(a);
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                bfs(i);
                ret++;
            }
        }

        System.out.println(ret);
    }

    static void bfs(int start) {
        Queue<Integer> q = new ArrayDeque<>();

        q.offer(start);
        visited[start] = true;

        while (!q.isEmpty()) {
            int cur = q.poll();

            for (int next : adj[cur]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.offer(next);
                }
            }
        }
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

        int nextInt() throws IOException {
            String s = next();

            return Integer.parseInt(s);
        }

        long nextLong() throws IOException {
            String s = next();

            return Long.parseLong(s);
        }
    }
}
```

<br>

### BOJ 1260 : DFS와 BFS
```java
import java.io.*;
import java.util.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static int n, m, st;
    static ArrayList<Integer>[] adj = new ArrayList[1001];
    static boolean[] visited = new boolean[1001];
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();
        m = cs.nextInt();
        st = cs.nextInt();

        // 1 ~ n까지의 인접 리스트 초기화
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            int a = cs.nextInt();
            int b = cs.nextInt();

            adj[a].add(b);
            adj[b].add(a);
        }

        // 문제 조건 : 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문
        for (int i = 1; i <= n; i++) {
            Collections.sort(adj[i]);
        }

        dfs(st);
        System.out.println(sb);

        init();

        bfs(st);
        System.out.println(sb);
    }

    static void init() {
        sb = new StringBuilder();

        for (int i = 1; i <= n; i++) {
            visited[i] = false;
        }
    }

    static void dfs(int cur) {
        sb.append(cur).append(" ");
        visited[start] = true;

        for (int next : adj[cur]) {
            if (!visited[next]) {
                dfs(next);
            }
        }
    }

    static void bfs(int start) {
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(start);
        visited[start] = true;

        while (!q.isEmpty()) {
            int cur = q.poll();
            sb.append(cur).append(" ");

            for (int next : adj[cur]) {
                if (!visited[next]) {
                    q.offer(next);
                    visited[next] = true;
                }
            }
        }
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

        int nextInt() throws IOException {
            String s = next();

            return Integer.parseInt(s);
        }

        long nextLong() throws IOException {
            String s = next();

            return Long.parseLong(s);
        }
    }
}
```

<br>

### BOJ 11725 : 트리의 부모 찾기
```java
import java.io.*;
import java.util.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static int n;
    static ArrayList<Integer>[] adj = new ArrayList[100001];
    static boolean[] visited = new boolean[100001];
    static int[] parent = new int[100001];

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();

        // 1 ~ n까지의 인접 리스트 초기화
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int i = 0; i < n - 1; i++) {
            int a = cs.nextInt();
            int b = cs.nextInt();

            adj[a].add(b);
            adj[b].add(a);
        }

        dfs(1);

        for (int i = 2; i <= n; i++) {
            System.out.println(parent[i]);
        }
    }

    static void dfs(int cur) {
        visited[cur] = true;

        for (int next : adj[cur]) {
            if (!visited[next]) {
                parent[next] = cur;
                dfs(next);
            }
        }
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

        int nextInt() throws IOException {
            String s = next();

            return Integer.parseInt(s);
        }

        long nextLong() throws IOException {
            String s = next();

            return Long.parseLong(s);
        }
    }
}
```

<br>

### BOJ 1991 : 트리 순회
```java
import java.io.*;
import java.util.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static int n;
    static char[][] adj = new char[28][2];

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();

        for (int i = 0; i < n; i++) {
            char node = cs.next().charAt(0);
            char left = cs.next().charAt(0);
            char right = cs.next().charAt(0);

            adj[node - 'A'][0] = left;
            adj[node - 'A'][1] = right;
        }

        print_all_order();
    }

    static void print_all_order() {
        pre_order('A');
        System.out.println();

        in_order('A');
        System.out.println();

        post_order('A');
    }

    static void pre_order(char here) {
        if (here == '.') return;

        System.out.print(here);
        pre_order(adj[here - 'A'][0]);
        pre_order(adj[here - 'A'][1]);
    }

    static void in_order(char here) {
        if (here == '.') return;

        in_order(adj[here - 'A'][0]);
        System.out.print(here);
        in_order(adj[here - 'A'][1]);
    }

    static void post_order(char here) {
        if (here == '.') return;

        post_order(adj[here - 'A'][0]);
        post_order(adj[here - 'A'][1]);
        System.out.print(here);
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

        Long nextLong() throws IOException {
            String s = next();

            return Long.parseLong(s);
        }
    }
}
```
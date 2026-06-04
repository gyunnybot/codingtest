# 다익스트라
### BOJ : 1753 : 최단 경로
```java
// 입력
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6

// 출력
0
2
3
7
INF
```

```java
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main {
    static CustomScanner sc = new CustomScanner();
    static int vertex, edge, start;
    static int[] d;
    static List<Node>[] adj;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        vertex = sc.nextInt(); // 정점의 개수
        edge = sc.nextInt(); // 간선의 개수
        start = sc.nextInt(); // 시작 노드 번호

        // 인접 리스트 배열 초기화
        adj = new ArrayList[vertex + 1];
        for (int i = 1; i <= vertex; i++) {
            adj[i] = new ArrayList<>();
        }

        // 거리 배열 초기화
        d = new int[vertex + 1];
        Arrays.fill(d, 1, vertex + 1, Integer.MAX_VALUE);

        // 간선 정보 입력
        for (int i = 0; i < edge; i++) {
            int from = sc.nextInt();
            int to = sc.nextInt();
            int weight = sc.nextInt();

            adj[from].add(new Node(to, weight));
        }

        // 다익스트라 알고리즘 시작
        PriorityQueue<Node> pq = new PriorityQueue<>();

        d[start] = 0;
        pq.add(new Node(start, d[start]));

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            // 이미 더 짧은 경로로 d가 처리되었다면
            if (d[cur.to] < cur.weight) {
                continue;
            }

            for (Node next : adj[cur.to]) {
                // next 노드가 cur 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
                if (d[next.to] > d[cur.to] + next.weight) {
                    d[next.to] = d[cur.to] + next.weight;
                    pq.add(new Node(next.to, d[next.to]));
                }
            }
        }

        // 결과 출력
        for (int i = 1; i <= vertex; i++) {
            if (d[i] == Integer.MAX_VALUE) {
                sb.append("INF\n");
            } else {
                sb.append(d[i]).append("\n");
            }
        }

        System.out.println(sb.toString());
    }

    static class Node implements Comparable<Node> {
        int to, weight;

        public Node(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }

        // weight를 기준으로 오름차순
        @Override
        public int compareTo(Node other) {
            return Integer.compare(this.weight, other.weight);
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

pq는 기본적으로 최소 힙(작은 것이 가장 맨 위)으로 정의된다. Collections.reverseOrder()를 사용해 최대 힙으로 변경 가능하다.
import java.util.*;

class Solution {
    boolean[] visited = new boolean[51];
    int answer = 0;

    public int solution(String begin, String target, String[] words) {

        boolean flag = false;

        for (String w : words) {
            if (w.equals(target)) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            return 0;
        }

        bfs(new Node(begin, 0), target, words);

        return answer;
    }

    void bfs(Node node, String target, String[] words) {
        Queue<Node> q = new ArrayDeque<>();
        q.offer(node);

        while (!q.isEmpty()) {
            Node cur = q.poll();

            if (cur.word.equals(target)) {
                answer = cur.cnt;
                return;
            }

            for (int i = 0; i < words.length; i++) {
                if (!visited[i] && canConvert(cur.word, words[i])) {
                    visited[i] = true;
                    q.offer(new Node(words[i], cur.cnt + 1));
                }
            }
        }
    }

    boolean canConvert(String a, String b) {
        int diff = 0;

        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                diff++;
            }
        }

        if (diff > 1) {
            return false;
        }

        return true;
    }

    class Node {
        String word;
        int cnt;

        public Node(String word, int cnt) {
            this.word = word;
            this.cnt = cnt;
        }
    }
}

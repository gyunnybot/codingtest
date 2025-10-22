import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static StringTokenizer st;
    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        Pos[] posList = new Pos[n];
        int[] xPosList = new int[n];
        int[] yPosList = new int[n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            xPosList[i] = x;
            yPosList[i] = y;
            posList[i] = new Pos(x, y);
        }

        int[] ret = new int[n]; // 결과 저장을 위한 배열 ret
        Arrays.fill(ret, -1); // 배열 원소 초기화

        int[] dist = new int[n]; // 최소 거리 계산을 위한 배열 dist

        for (int x : xPosList) {
            for (int y : yPosList) {
                for (int i = 0; i < n; i++) {
                    dist[i] = Math.abs(posList[i].x - x) + Math.abs(posList[i].y - y);
                }

                Arrays.sort(dist); // 오름차순 정렬

                int temp = 0;

                for (int i = 0; i < n; i++) {
                    temp += dist[i];

                    if (ret[i] == -1) {
                        ret[i] = temp;
                    } else {
                        ret[i] = Math.min(ret[i], temp);
                    }
                }
            }
        }

        sb = new StringBuilder();

        for (int val : ret) {
            sb.append(val).append(' ');
        }

        System.out.println(sb);
    }

    static class Pos {
        int x, y;

        Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}

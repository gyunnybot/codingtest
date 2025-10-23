import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static StringTokenizer inputPositionXY;
    static StringBuilder ret;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        Pos[] posList = new Pos[n];
        int[] xPosList = new int[n];
        int[] yPosList = new int[n];

        for (int i = 0; i < n; i++) {
            inputPositionXY = new StringTokenizer(br.readLine());

            int x = Integer.parseInt(inputPositionXY.nextToken());
            int y = Integer.parseInt(inputPositionXY.nextToken());

            xPosList[i] = x;
            yPosList[i] = y;
            posList[i] = new Pos(x, y);
        }

        int[] retArr = new int[n]; // 결과 저장을 위한 배열 ret
        Arrays.fill(retArr, -1); // 배열 원소 초기화

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

                    if (retArr[i] == -1) {
                        retArr[i] = temp;
                    } else {
                        retArr[i] = Math.min(retArr[i], temp);
                    }
                }
            }
        }

        ret = new StringBuilder();

        for (int val : retArr) {
            ret.append(val).append(' ');
        }

        System.out.println(ret);
    }

    static class Pos {
        int x, y;

        Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}

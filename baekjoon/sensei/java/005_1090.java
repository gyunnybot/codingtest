/**
 * 시간복잡도 O(N^3)
 */

import java.io.*;
import java.util.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static StringBuilder ret = new StringBuilder();
    static int n;

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();

        int[] xList = new int[n];
        int[] yList = new int[n];
        Pos[] posList = new Pos[n];

        for (int i = 0; i < n; i++) {
            int x = cs.nextInt();
            int y = cs.nextInt();

            xList[i] = x;
            yList[i] = y;
            posList[i] = new Pos(x, y);
        }

        int[] retArr = new int[n];
        Arrays.fill(retArr, -1); // Arrays.fill(기본 배열, value)
        // 왜 -1로 초기화? 이동 결과가 0인 경우랑 구분 목적

        int[] dist = new int[n];

        for (int x : xList) {
            for (int y : yList) {
                for (int i = 0; i < n; i++) {
                    dist[i] = Math.abs(posList[i].x - x) + Math.abs(posList[i].y - y);
                }

                Arrays.sort(dist);

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

        for (int i : retArr) {
            ret.append(i).append(" ");
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

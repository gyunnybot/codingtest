/**
 * 시간복잡도 O(10^3 * N)
 */

import java.io.*;
import java.util.*;

public class Main {
    static CustomScanner cs = new CustomScanner();
    static int n, ret;

    public static void main(String[] args) throws IOException {
        n = cs.nextInt();

        BaseballInfo[] baseballInfos = new BaseballInfo[n];

        for (int i = 0; i < n; i++) {
            String number = cs.next();
            int strike = cs.nextInt();
            int ball = cs.nextInt();

            baseballInfos[i] = new BaseballInfo(number, strike, ball);
        }

        for (int i = 100; i < 1000; i++) {
            String temp = String.valueOf(i); // String.valueOf(i): 다른 타입의 i를 String으로 변환

            if (temp.charAt(0) == '0' || temp.charAt(1) == '0' || temp.charAt(2) == '0') {
                continue;
            }

            if (temp.charAt(0) == temp.charAt(1)
                    || temp.charAt(0) == temp.charAt(2)
                    || temp.charAt(1) == temp.charAt(2)) {
                continue;
            }

            int cnt = 0;

            for (int j = 0; j < n; j++) {
                int strikeCnt = 0;
                int ballCnt = 0;

                if (baseballInfos[j].number.charAt(0) == temp.charAt(0)) strikeCnt++;
                if (baseballInfos[j].number.charAt(1) == temp.charAt(1)) strikeCnt++;
                if (baseballInfos[j].number.charAt(2) == temp.charAt(2)) strikeCnt++;

                if (baseballInfos[j].number.charAt(0) == temp.charAt(1)
                        || baseballInfos[j].number.charAt(0) == temp.charAt(2)) ballCnt++;
                if (baseballInfos[j].number.charAt(1) == temp.charAt(0)
                        || baseballInfos[j].number.charAt(1) == temp.charAt(2)) ballCnt++;
                if (baseballInfos[j].number.charAt(2) == temp.charAt(0)
                        || baseballInfos[j].number.charAt(2) == temp.charAt(1)) ballCnt++;

                if (baseballInfos[j].strikeCnt == strikeCnt
                        && baseballInfos[j].ballCnt == ballCnt) cnt++;
            }

            if (cnt == n) ret++;
        }

        System.out.println(ret);
    }

    static class BaseballInfo {
        String number;
        int strikeCnt;
        int ballCnt;

        public BaseballInfo(String number, int strikeCnt, int ballCnt) {
            this.number = number;
            this.strikeCnt = strikeCnt;
            this.ballCnt = ballCnt;
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

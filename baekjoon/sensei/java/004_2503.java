import java.io.*;
import java.util.*;

public class Main {
    static int n, ret;
    static StringTokenizer inputNumberStrikeBall;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        Info[] infos = new Info[n];

        for (int i = 0; i < n; i++) { // n <= 100
            inputNumberStrikeBall = new StringTokenizer(br.readLine());

            String number = inputNumberStrikeBall.nextToken();
            int strike = Integer.parseInt(inputNumberStrikeBall.nextToken());
            int ball = Integer.parseInt(inputNumberStrikeBall.nextToken());

            infos[i] = new Info(number, strike, ball);
        }

        for (int i = 100; i <= 999; i++) {
            String temp = String.valueOf(i);

            if (temp.charAt(0) == '0' || temp.charAt(1) == '0' || temp.charAt(2) == '0') continue;
            if (temp.charAt(0) == temp.charAt(1)
                    || temp.charAt(0) == temp.charAt(2)
                    || temp.charAt(1) == temp.charAt(2)) continue;

            int cnt = 0;

            for (int j = 0; j < n; j++) {
                int strikeCnt = 0;
                int ballCnt = 0;

                if (infos[j].number.charAt(0) == temp.charAt(0)) strikeCnt++;
                if (infos[j].number.charAt(1) == temp.charAt(1)) strikeCnt++;
                if (infos[j].number.charAt(2) == temp.charAt(2)) strikeCnt++;

                if (infos[j].number.charAt(0) == temp.charAt(1)
                        || infos[j].number.charAt(0) == temp.charAt(2)) ballCnt++;
                if (infos[j].number.charAt(1) == temp.charAt(0)
                        || infos[j].number.charAt(1) == temp.charAt(2)) ballCnt++;
                if (infos[j].number.charAt(2) == temp.charAt(0)
                        || infos[j].number.charAt(2) == temp.charAt(1)) ballCnt++;

                if (infos[j].strike == strikeCnt && infos[j].ball == ballCnt) cnt++;
            }

            if (cnt == n) ret++;
        }

        System.out.println(ret);
    }

    static class Info {
        String number;
        int strike;
        int ball;

        public Info(String number, int strike, int ball) {
            this.number = number;
            this.strike = strike;
            this.ball = ball;
        }
    }
}

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        List<Info> infoList = new ArrayList<>();

        for (int i = 0; i < n; i++) { // n <= 100
            String number = scanner.next();
            int strike = scanner.nextInt();
            int ball = scanner.nextInt();

            infoList.add(new Info(number, strike, ball));
        }

        int ret = 0;

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

                if (infoList.get(j).number.charAt(0) == temp.charAt(0)) strikeCnt++;
                if (infoList.get(j).number.charAt(1) == temp.charAt(1)) strikeCnt++;
                if (infoList.get(j).number.charAt(2) == temp.charAt(2)) strikeCnt++;

                if (infoList.get(j).number.charAt(0) == temp.charAt(1)
                        || infoList.get(j).number.charAt(0) == temp.charAt(2)) ballCnt++;
                if (infoList.get(j).number.charAt(1) == temp.charAt(0)
                        || infoList.get(j).number.charAt(1) == temp.charAt(2)) ballCnt++;
                if (infoList.get(j).number.charAt(2) == temp.charAt(0)
                        || infoList.get(j).number.charAt(2) == temp.charAt(1)) ballCnt++;

                if (infoList.get(j).strike == strikeCnt && infoList.get(j).ball == ballCnt) cnt++;
            }

            if (cnt == n) ret++;
        }

        System.out.println(ret);
    }
}

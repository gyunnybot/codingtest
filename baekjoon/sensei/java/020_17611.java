import java.io.*;
import java.util.*;

public class Main {
    static int n, xPos, yPos, ret;
    static int[] a_x = new int[1000001];
    static int[] a_y = new int[1000001];
    static int[] s_x = new int[1000001];
    static int[] s_y = new int[1000001];
    static List<Map.Entry<Integer, Integer>> posList = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            StringTokenizer inputXY = new StringTokenizer(br.readLine());

            xPos = Integer.parseInt(inputXY.nextToken());
            yPos = Integer.parseInt(inputXY.nextToken());

            xPos += 500000;
            yPos += 500000;

            posList.add(new AbstractMap.SimpleEntry<>(xPos, yPos)); // vector<pair<int,int>> v : v.push_back (C++)
        }

        for (int i = 0; i < n; i++) {
            int x = posList.get(i).getKey();
            int y = posList.get(i).getValue();
            int nx = posList.get((i + 1) % n).getKey();
            int ny = posList.get((i + 1) % n).getValue();

            if (x == nx) {
                int max_y = Math.max(y, ny);
                int min_y = Math.min(y, ny);

                a_y[max_y]--;
                a_y[min_y]++;
            } else {
                int max_x = Math.max(x, nx);
                int min_x = Math.min(x, nx);

                a_x[max_x]--;
                a_x[min_x]++;
            }
        }

        for (int i = 1; i < 1000001; i++) {
            s_x[i] = s_x[i - 1] + a_x[i - 1];
            s_y[i] = s_y[i - 1] + a_y[i - 1];
        }

        for (int i = 1; i < 1000001; i++) {
            ret = Math.max(ret, Math.max(s_x[i], s_y[i]));
        }

        System.out.println(ret);
    }
}

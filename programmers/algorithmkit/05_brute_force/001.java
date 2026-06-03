class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;

        int row_max = -1;
        int col_max = -1;

        for (int[] s : sizes) {
            if (s[0] < s[1]) {
                int temp = s[0];
                s[0] = s[1];
                s[1] = temp;
            }

            row_max = Math.max(row_max, s[0]);
            col_max = Math.max(col_max, s[1]);
        }

        answer = row_max * col_max;

        return answer;
    }
}

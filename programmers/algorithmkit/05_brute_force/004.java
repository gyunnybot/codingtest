class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];

        int temp = brown + yellow;

        for (int i = temp / 3; i >= 3; i--) {
            int width = i;
            int height = temp / i;

            int y = (width - 2) * (height - 2);
            int b = temp - y;

            if (b == brown && y == yellow) {
                answer[0] = width;
                answer[1] = height;

                break;
            }
        }

        return answer;
    }
}

// 탈출 로직이 필수 요소인 문제. break를 사용하지 않으면 가로, 세로가 변경될 수 있다
class Solution {
	public int[] solution(int[] lottos, int[] win_nums) {
		int[] answer = {};
		int zeroCount = 0;
		int correctCount = 0;

		
        for (int i = 0; i < win_nums.length; i++) {
            for (int j = 0; j < lottos.length; j++) {
				int lotto = lottos[i];

				if (lotto == 0) {
					zeroCount++;
                    break;
				} else {
					if (lotto == win_nums[j]) {
						correctCount++;
					}
				}
			}
		}

		answer = getLotto(correctCount, zeroCount);

		return answer;
	}

	public int[] getLotto(int correctCount, int zeroCount) {
		int[] answer = new int[2];

		if (correctCount == 2) {
			answer[1] = 5;
		} else if (correctCount == 3) {
			answer[1] = 4;
		} else if (correctCount == 4) {
			answer[1] = 3;
		} else if (correctCount == 5) {
			answer[1] = 2;
		} else if (correctCount == 6) {
			answer[1] = 1;
		} else if (correctCount == 0) {
            answer[1] = 6;
        } else if (correctCount == 1) {
            answer[1] = 6;
        }
		answer[0] = answer[1] - zeroCount;
        if(zeroCount == 6){
            answer[0] = 1;
        }

		return answer;
	}
}
import java.util.HashMap;

class Solution {
    private HashMap<String, String> hashMap = new HashMap<>();
	private HashMap<String, Integer> money = new HashMap<>();

	public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
		int[] answer = new int[enroll.length];
		
		money.put("center", 0);
		for (int i = 0; i < enroll.length; i++) {
			String refer = referral[i];
			if (refer.equals("-")) {
				refer = "center";
			}
			hashMap.put(enroll[i], refer);
			money.put(enroll[i], 0);
		}

		for (int i = 0; i < seller.length; i++) {
			String temp = seller[i];
			int tempMoney = amount[i] * 100;

			while (hashMap.containsKey(temp)) {
				int myMoney = money.get(temp);
				int nowMoney = tempMoney - (tempMoney / 10);
				money.put(temp, myMoney + nowMoney);

				temp = hashMap.get(temp);
				tempMoney = tempMoney / 10;
			}
		}

		for (int i = 0; i < enroll.length; i++) {
			answer[i] = money.get(enroll[i]);
		}

		return answer;
	}
}

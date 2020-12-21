    class Solution {
        public int[] twoSum(int[] nums, int target) {
            Map<Integer, Integer> map = new HashMap<>();

            for (int i = 0; i < nums.length; i++) {
                int numA = target - nums[i];
                if(map.containsKey(numA)){
                    return new int[] {map.get(numA), i};
                }
                map.put(numA, i);
            }

            throw new IllegalArgumentException("No Answer");
        }
    }
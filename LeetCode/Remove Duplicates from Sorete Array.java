    class Solution {
        public int removeDuplicates(int[] nums) {
            if (nums.length == 0) {
                return 0;
            }

            int numberCount = 0;

            for (int index = 0; index < nums.length; index++) {
                if (nums[index] != nums[numberCount]) {
                    numberCount++;
                    nums[numberCount] = nums[index];
                }
            }

            return numberCount + 1;
        }
    }
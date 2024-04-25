import java.util.Arrays;

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int result = nums[0] + nums[1] + nums[nums.length-1];
        Arrays.sort(nums);
        
        for(int i = 0 ; i < nums.length-2 ; i++)
        {
            int j = i+1;
            int k = nums.length-1;

            while(j < k)
            {
                int curr_sum = nums[i] + nums[j] + nums[k];
                if(curr_sum < target)
                {
                    j++;
                }
                else
                {
                    k--;
                }

                if(Math.abs(curr_sum - target) < Math.abs(result - target))
                {
                    result = curr_sum;
                }
            }
        }
        return result;
    }
}
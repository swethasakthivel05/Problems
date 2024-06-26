#include <vector>
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        vector<unordered_map<int, int>> arrMap(nums.size());
        int ans = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                long diff = (long)nums[j] - nums[i];
                if (diff >= INT_MAX || diff <= INT_MIN)
                {
                    continue;
                }
                else
                {
                    diff = (int)diff;
                }
                if (arrMap[j].count(diff))
                {
                    int prev = arrMap[j][diff];
                    int curr = arrMap[i][diff];

                    ans += prev;
                    arrMap[i][diff] = prev + curr + 1;
                }
                else
                {
                    arrMap[i][diff]++;
                }
            }
        }
        return ans;
    }
};
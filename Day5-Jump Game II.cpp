class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, maxReachable = 0 , lastJumpedPos = 0;
        int i = 0;
        while (lastJumpedPos < n - 1) {
            maxReachable = max(maxReachable, nums[i] + i);

            if (i == lastJumpedPos) {
                jumps++;
                lastJumpedPos = maxReachable;
            }

            i++;
        }
        return jumps;
    }
};
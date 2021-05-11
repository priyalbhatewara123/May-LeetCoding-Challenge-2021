class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int modifications = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                if (modifications == 1)
                    return false;

                modifications++;

                //now modify
                if (i < 2 or nums[i - 2] <= nums[i]) {
                    nums[i - 1] = nums[i];
                }
                else {
                    nums[i] = nums[i - 1];
                }

            }
        }
        return true;
    }

};
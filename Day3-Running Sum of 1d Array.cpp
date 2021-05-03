class Solution {
public:
	vector<int> runningSum(vector<int>& nums) {
		for (int i = 1; i < nums.size(); i++) {
			nums[i] += nums[i - 1];
		}
		return nums;
	}
};

//Here we didn't use any extra array to store result. We have modified the input array for output.
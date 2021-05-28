//Solution 1 - Usind Two Pointers and Set

class Solution {
public:
	int maximumUniqueSubarray(vector<int>& nums) {
		int currentSum = 0 , maxSum = 0, l = 0, r = 0;
		unordered_set<int> s;
		int n = size(nums);

		while (r < n) {
			while (s.find(nums[r]) != s.end())
				currentSum -= nums[l], s.erase(nums[l++]);
			currentSum += nums[r] , s.insert(nums[r++]);
			maxSum = max(maxSum , currentSum);
		}
		return maxSum;
	}
};


//Solution 2- Using two pointers and maintaining a frequency array

class Solution {
public:
	int maximumUniqueSubarray(vector<int>& nums) {
		int n = size(nums) , l = 0 , r = 0 , currentSum = 0 , maxSum = 0;
		bool freq[100001] {false};

		while (r < n) {
			while (freq[nums[r]])
				currentSum -= nums[l] , freq[nums[l++]] = false;
			currentSum += nums[r] , freq[nums[r++]] = true;
			maxSum = max(maxSum , currentSum);
		}
		return maxSum;
	}
};
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());  //O(nlogn)

        int mid = n / 2;
        int midElement = nums[mid];
        int ans = 0;
        for (int i = 0; i < n; i++) {  //O(n)
            ans += abs(nums[i] - midElement);
        }

        return ans;
    }
};

/*
Complexity Analysis
Time Complexity - O(nlogn)
Space Complexity - O(1)
*/
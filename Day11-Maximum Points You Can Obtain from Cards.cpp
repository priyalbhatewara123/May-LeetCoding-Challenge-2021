//Slinding Window approach

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0); //sum of all elements of vector

        int subArrSum = accumulate(cardPoints.begin(), cardPoints.end() - k, 0); //sum of first subarray from left
        int ans = totalSum - subArrSum;

        //traverse over remaining subarrays
        for (int r = cardPoints.size() - k, l = 0; r < cardPoints.size(); r++, l++) {
            subArrSum = subArrSum - cardPoints[l] + cardPoints[r];
            ans = max(ans , totalSum - subArrSum );
        }

        return ans;
    }
};
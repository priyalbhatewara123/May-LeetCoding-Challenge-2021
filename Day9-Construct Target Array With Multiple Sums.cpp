class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long int totalSum = accumulate(target.begin(), target.end(), (long long)0);
        priority_queue <int> pq(target.begin(), target.end());

        int a;
        while (true) {
            a = pq.top(); //highest element
            pq.pop();
            totalSum -= a;
            if (a == 1 || totalSum == 1 )
                return true;

            if (a < totalSum || totalSum == 0 || a % totalSum == 0)
                return false;

            a = a % totalSum;
            totalSum += a;
            pq.push(a);
        }
    }
};
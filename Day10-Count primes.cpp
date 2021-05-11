class Solution {
public:
    int countPrimes(int n) {

        //edge case
        if (n <= 2) {
            return 0;
        }

        vector<int> p(n, 0);

        //first mark all odd numbers as prime
        for (long long int i = 3; i < n; i += 2) {
            p[i] = 1;
        }

        for (long long int i = 3; i < n; i += 2) {
            if (p[i] == 1) {

                //mark multiples of i as non prime
                for (long long int j = i * i; j < n; j += i) {
                    p[j] = 0;
                }
            }
        }

        p[0] = p[1] = 0;
        p[2] = 1;

        long long int count = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] == 1)
                count++;
        }
        return count;
    }
};
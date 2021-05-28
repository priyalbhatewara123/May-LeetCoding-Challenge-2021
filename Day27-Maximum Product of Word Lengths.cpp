//Solution 1 - using bitset

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0 , n = size(words);
        vector<bitset<26>> chars(n);

        for (int i = 0; i < n; i++) {
            for (auto& ch : words[i])
                chars[i][ch - 'a'] = 1;

            for (int j = 0; j < i; j++) {
                if (!checkCommon(chars[i], chars[j]))
                    ans = max(ans, int(size(words[i]) * size(words[j])));
            }
        }
        return ans;
    }

    bool checkCommon(bitset<26>& a , bitset<26>& b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] && b[i])
                return true;
        }
        return false;
    }
};

//Solution 2 - Using Bitmasks

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = size(words) , ans = 0;
        vector<int> mask(n);

        for (int i = 0; i < n; i++) {
            for (auto& ch : words[i]) {
                mask[i] |= 1 << (ch - 'a');
            }
            for (int j = 0; j < i; j++) {
                if ((mask[i] & mask[j]) == 0)
                    ans = max(ans , int(size(words[i]) * size(words[j])));
            }
        }
        return ans;
    }
};
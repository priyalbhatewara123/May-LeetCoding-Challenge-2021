class Solution {
public:

    string normalise(string w) {
        unordered_map<char, char> mp;
        char c = 'a';
        for (auto ch : w) {
            if (!mp.count(ch))
                mp[ch] = c++;
        }
        for (auto& ch : w)
            ch = mp[ch];

        return w;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        string p = normalise(pattern);
        for (auto& w : words) {
            if (normalise(w) == p)
                ans.push_back(w);
        }

        return ans;
    }
};

/*
Time Complexity - O(N*L) N is number of words and L is length of each word
Space Complexity - O(N*L)
*/
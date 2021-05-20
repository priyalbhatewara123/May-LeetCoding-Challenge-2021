/*
Top Down Dynamic Programming - Recursion + Memoization
Time complexity - O(L ^ 2 * N)
Space complexity: O(N)
N be the number of words in the list and L be the maximum possible length of a word.
*/

class Solution {
private:
    int dfs(unordered_set<string> &wordsPresent , unordered_map<string, int> &memo , string currentWord) {

        //word is encountered previously
        if (memo.find(currentWord) != memo.end()) {
            return memo[currentWord];
        }

        int maxLength = 1;
        for (int i = 0; i < currentWord.length(); i++) {
            string newWord = currentWord.substr(0, i) + currentWord.substr(i + 1);
            if (wordsPresent.find(newWord) != wordsPresent.end()) {
                int currentLength = 1 + dfs(wordsPresent , memo, newWord);
                maxLength = max(maxLength, currentLength);
            }
        }
        memo[currentWord] = maxLength;

        return maxLength;
    }


public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> memo;
        unordered_set<string> wordsPresent;

        for (auto w : words) {
            wordsPresent.insert(w);
        }
        int ans = 0;
        for (auto w : words) {
            ans = max(ans , dfs(wordsPresent, memo, w));
        }

        return ans;
    }
};


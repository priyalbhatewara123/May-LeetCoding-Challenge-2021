class Solution {

    //helper function
    vector<string> f(string s) {
        int n = s.size();

        //corner cases

        if (n == 0 || (n > 1 && s[0] == '0' && s[n - 1] == '0'))
            return {};

        if (n > 1 && s[0] == '0')
            return {"0." + s.substr(1)};

        if (n == 1 || s[n - 1] == '0')
            return {s};

        vector<string> ans = {s};
        for (int i = 1; i < n; i++) {
            ans.push_back(s.substr(0, i) + '.' + s.substr(i));
        }

        return ans;
    }

public:
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size();
        vector<string> ans;

        //breaking the string into 2 coordinates
        for (int i = 1; i < n - 2; i++) {
            vector<string> A = f(s.substr(1, i));
            vector<string> B = f(s.substr(i + 1, n - 2 - i));

            //Cross multiplication
            for (auto a : A) {
                for (auto b : B) {
                    ans.push_back("(" + a + ", " + b + ")");
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> files;

        for (auto path : paths) {
            stringstream ss(path);

            string root;
            string s;
            getline(ss, root, ' ');
            while (getline(ss, s, ' ')) {
                string filename = root + '/' + s.substr(0, s.find('('));
                string fileContent = s.substr(s.find('(') + 1 , s.find(')') - s.find('(') - 1);

                files[fileContent].push_back(filename);
            }
        }

        for (auto file : files) {
            if (file.second.size() > 1)
                result.push_back(file.second);
        }

        return result;
    }
};

/*
Complexity Analysis
Time complexity : O(n*x). n strings of average length x is parsed.
Space complexity : O(n*x). map and res size grows upto n*x.

*/
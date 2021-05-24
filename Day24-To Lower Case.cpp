//Solution - 1 (Without using library function)
class Solution {
public:
	string toLowerCase(string s) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'A' and s[i] <= 'Z')
				s[i] += 32 ;
		}
		return s;
	}
};

//Solution - 2 (using Library function)
class Solution {
public:
	string toLowerCase(string s) {
		// for(auto& str : s)
		//     str = tolower(char(str));

		for (int i = 0; i < s.length(); i++)
			s[i] = tolower(s[i]);

		return s;
	}
};

//Time complexity - O(N)
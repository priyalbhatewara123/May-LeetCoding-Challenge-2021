class Solution {
public:
	int minPartitions(string n) {
		char maxx = '0';
		for (auto c : n)
			if (c > maxx) maxx = c;

		return maxx - '0';
	}
};

/*
Time complexity - O(l) ,where l is length of string n
*/
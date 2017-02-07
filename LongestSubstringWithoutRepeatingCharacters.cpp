#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int strl = s.length();
		if (strl == 0)
			return 0;
		int leftP = 0;
		int rightP = 0;
		int max = 0;
		bool found = false;
		while (rightP < strl) {
			for (int j = leftP; j < rightP; j++) {
				if (s[j] == s[rightP]) {
					leftP = j + 1;
					found = true;
					break;
				}
			}
			if (!found) {
				rightP++;
				max = max >(rightP - leftP) ? max : (rightP - leftP);
			}
			found = false;
		}
		return max;
	}
};

void testLengthOfLongestSubstring() {
	//beat 78.65%

	Solution s;
	cout << s.lengthOfLongestSubstring("pwwkew");
	system("pause");
}

int main() {
	testLengthOfLongestSubstring();
}
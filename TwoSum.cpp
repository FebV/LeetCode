#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
using namespace stdext;

void printV(vector<int> v) {
	int l = v.size();
	for (int i = 0; i < l; i++) {
		cout << v[i] << endl;
	}
}

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hm;
		int len = nums.size();

		for (int i = 0; i < len; i++) {
			unordered_map<int, int>::iterator it;
			it = hm.find(target - nums[i]);

			if (it != hm.end()) {
				vector<int> v = { it->second, i };
				return v;
			}

			hm[nums[i]] = i;
		}
	}
};



void test() {
	Solution s;
	vector<int> v = { 3,2,4 };
	vector<int> r = s.twoSum(v, 6);
	int len = r.size();
	for (int i = 0; i < len; i++)
		cout << r[i];

	//2017-01-26
	//beat 90.27%
	//hi
}
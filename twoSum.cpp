#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> map;

        for(int i = 0; i < nums.size(); ++i) {
        	map[nums[i]] = i;
        }

        for(int i = 0; i < nums.size() ;++i) {
        	int other = target - nums[i];
        	if(map.find(other)!=map.end() && map[other]!=i) {
        		result.push_back(i+1);
        		result.push_back(map[other]+1);
        		return result;
        	}
        }

        return result;
        
    }
};

int main() {
	int test[] = {2,7,11,15};
	vector<int> testV(test,test+4);
	Solution s;
	vector<int> result = s.twoSum(testV,9);
	cout << result[0]<<" "<<result[1]<<endl;

	return 0;
}

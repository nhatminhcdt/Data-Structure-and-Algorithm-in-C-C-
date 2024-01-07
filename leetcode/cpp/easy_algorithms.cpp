/**
 * @file easy_algorithms.cpp
 * @brief easy_algorithms implementation.
 */

#include "easy_algorithms.h"

namespace easy_algorithms {

/**
 * Constructor
 */
EasyAlgorithms::EasyAlgorithms() {}

/**
 * Destructor
 */
EasyAlgorithms::~EasyAlgorithms() {}

/**
 * Initialize
 */
bool EasyAlgorithms::init() {
	return true;
}

/**
 * Solution for the problem 1 Two_Sum. * 
 */
vector<int> EasyAlgorithms::TwoSumS1(vector<int>& nums, int target) {
	unordered_map<int, int> hash_tbl;
	vector<int> result;

	for (unsigned int i = 0; i < nums.size(); ++i) {
		int complement = target - nums[i];
		auto it = hash_tbl.find(complement);
		if (it != hash_tbl.end()) {
			result.push_back(i);
			result.push_back(it->second);
			return result;
		} else {
			hash_tbl[nums[i]] = i;
		}
	}

	// No solution
	return result;
}

/**
 * Solution for the problem 2235 Add_Two_Integers.
*/
int EasyAlgorithms::AddTwoIntegersS2235(int num1, int num2) {
	return num1 + num2;
}

}  // namespace easy
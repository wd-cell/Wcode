#pragma once
#include<iostream>
#include<vector>
#include<map>
using namespace std;

//class Solution {
//public:
//	vector<int> twoSum(vector<int>& nums, int target) {
//		vector<int> indicies;
//		for (auto it = nums.begin(); it != nums.end();++it) {
//			if (*it > target) {}
//			else {
//				for (auto it2=it+1; it2 != nums.end(); ++it2) {
//					if(*it2>target){}
//					else {
//						if (*it + *it2 == target) {
//							indicies.push_back(it-nums.begin());
//							indicies.push_back(it2-nums.begin());
//							break;
//						}
//					}
//				}
//			}
//		}
//		return indicies;
//	}
//};


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		map<int, int> mii;
		for (int i = 0; i < nums.size(); i++) {
			if (mii.count(nums[i]) != 0) {
				res.push_back(mii.at(nums[i]));
				res.push_back(i);
				return res;
			}
			mii.insert(std::pair<int, int>(target - nums[i], i));
		}
		return res;
	}
};
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 2.倒序链表数字相加
class A { //熟悉类
public:
	int n;
	A(int m) :n(m) {};
	A() { n = 1; };
	~A() {};
};
struct ListNode {
	int val;
	ListNode* next;
	ListNode() { val = 0, next = nullptr; }
	ListNode(int x) :val(x), next(nullptr) {}
};
//int main() {
//	A a(1);
//	A b;
//	cout << b.n << endl;
//	//cout << b->n << endl;
//
//	ListNode c(1), d(2);
//	c.next = &d;
//	while (c.next) {
//		cout << c.val;
//	}
//
//	int x(1), y=2; //不同定义方式共存
//	//y = 2;
//	cout << x << y << endl;
//}



//3.最长无重复子串
class Solution3 {
public:
	int lengthOfLongestSubstring(string s) { // 算法优
		vector<int> dict(256, -1);
		int maxLen = 0, start = -1;
		for (int i = 0; i != s.length(); i++) {
			if (dict[s[i]] > start)
				start = dict[s[i]];
			dict[s[i]] = i;
			maxLen = max(maxLen, i - start); // start-i , 末位减初位
		}
		return maxLen;
	}
};



//4.两个数组的中位数
class Solution4 {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size() + nums2.size();
		vector<int> nums3;
		int i = 0, j = 0;
		for (int x = 0; x < n; ++x) {
			if (i >= nums1.size()) {
				nums3.insert(nums3.end(), nums2.begin() + j, nums2.end());
				break;
			}
			if (j >= nums2.size()) {
				nums3.insert(nums3.end(), nums1.begin() + j, nums1.end());
				break;
			}
			if (nums1[i] <= nums2[j]) {
				nums3.push_back(nums1[i]);
				++i;
			}
			else {
				nums3.push_back(nums2[j]);
				++j;
			}
		}
		for (int p : nums3)
			cout << p;
		if (n % 2 == 0) return (nums3[n / 2] + nums3[(n / 2) - 1]) / 2.0;
		else return nums3[n / 2];
	}
};
//int main() {
//	Solution4 A;
//	vector<int> nums1 = { 3 };
//	vector<int> nums2 = { -2,-1 };
//	cout << endl << A.findMedianSortedArrays(nums1, nums2) << endl;
//}



//5.最长回文子串
class Solution5 {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		if (n < 2) return s;

		int l, r, mark = 0; //未用到的值一定要初始化
		int maxlen = 1;
		for (int i = 0; i < n - 1; ++i) {
			l = r = i;
			for (; r + 1 < n && s[r + 1] == s[r]; r++);
			for (; l - 1 >= 0 && r + 1 < n && s[l - 1] == s[r + 1]; l--, r++);
			if (r - l + 1 > maxlen) {
				maxlen = r - l + 1;
				mark = l;
			}
		}
		cout << mark << maxlen << endl;
		return s.substr(mark, maxlen);
	}
};
//int main() {
//	string s = "ac";
//	Solution5 A;
//	A.longestPalindrome(s);
//}



//6.Z字型输出字符串
class Solution6 {
public:
	string convert(string s, int numRows) {
		if (numRows == 1 || s.empty() == true) return s;

		vector<string> help(min(numRows, int(s.size()))); //一定注意类型转换，size返回的是string::size_type
		bool turnover = false;
		int line = 0;
		for (char c : s) {
			help[line] += c;
			if (line == numRows - 1 || line == 0) turnover = !turnover;
			line += turnover ? 1 : -1;
		}

		string ret;
		for (string p : help)
			ret += p;
		return ret;
	}
};



//8.带极值的atoi
class Solution8 {
public:
	int myAtoi(string str) {
		if (str.empty()) return 0;
		int i = 0, sign = 0;
		while (i + 1 < str.size() && isspace(str[i])) ++i;
		if (i + 1 == str.size() && !isdigit(str[i])) return 0;
		return 123;
	}
};
//int main() {
//	Solution8 A;
//	string s = "  -";
//	A.myAtoi(s);
//
//	char* str;   //char* 的初始化
//	char str2[] = "abc";
//	str = str2;
//	char* str3 = str2;
//	char* p = new char;
//	p = str2;
//	p = str;
//	cout << *(str + 1) << *(str3 + 1) << *(p + 1) << endl;
//
//	char* q = new char[10];
//	q = str;
//	char* p2 = new(nothrow) char;
//}



//20.是否为合理的括号
#include<stack>
class Solution {
public:
	bool isValid(string s) {
		int Len = s.size();
		if (Len % 2 == 1) return false;
		stack<char> temp;
		temp.push('a');
		for (int i = 0; i < Len; ++i) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				temp.push(s[i]);
			else {
				switch (temp.top()) {
				case '(': if (s[i] != ')') return false; break;
				case '[': if (s[i] != ']') return false; break;
				case '{': if (s[i] != '}') return false; break;
				default: return false;
				}
				temp.pop();
			}
		}
		return temp.top() == 'a' ? true : false;
	}
};



//26.删掉重复数后 的向量长度
class Solution26 {
public:
	int removeDuplicates(vector<int>& nums) {
		auto end_unique = unique(nums.begin(), nums.end());
		return end_unique - nums.begin();
	}
};



//44.通配符匹配
class Solution44 {
public:
	bool isMatch(string s, string p) {
		int m = s.length(), n = p.length();
		int i = 0, j = 0, asterisk = -1, match = 0;
		while (i < m) {
			if (j < n && p[j] == '*') {
				match = i;
				asterisk = j++;
			}
			else if (j < n && (s[i] == p[j] || p[j] == '?')) {
				i++;
				j++;
			}
			else if (asterisk >= 0) {
				i = ++match;
				j = asterisk + 1;
			}
			else return false;
		}
		while (j < n && p[j] == '*') j++;
		return j == n;
	}
};
//int main() {
//	Solution44 T;
//	bool flag = T.isMatch("abcde", "*");
//}



//45.Jump Game II  贪心算法
class Solution45 {
public:
	int jump(vector<int>& nums) {
		int size = nums.size();
		if (size < 2)
			return 0;
		int Current = 0, Preivous = -1, jumps = 0; //previous: pre of current
		int i;
		for (i = 0; i < size; ++i) {
			if (Current >= size - 1)
				return jumps;
			if (i > Preivous) { //当i大于前一跳的范围时
				++jumps;
				Preivous = Current;
			}
			Current = max(Current, i + nums[i]);
		}
		return -1;//The program should not reach here.
				  //"return -1" here for suppress compiler warnings.
	}
};
int main() {
	vector<int> v = { 2,3,1,1,4,1 };
	Solution45 T;
	int ans = T.jump(v);
}
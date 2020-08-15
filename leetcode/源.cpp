//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//
//using namespace std;

//#include"towsum.h"
//int main(int argc, char* argv[]) {
//	vector<int> nums,nums2;
//	int a;
//	while (cin >> a) {
//		nums.push_back(a);
//	}
//	Solution answer;
//	nums2=answer.twoSum(nums, 8);
//	for (auto r : nums2)
//		cout << r << " ";
//}



//#include"Add Two Numbers.h"   //No.2
//int main() {
//	string s;
//	getline(cin, s);
//	int i;
//	cin >> i;
//	char c = s.at(i);
//	cout << "char类型：" << c;
//}



//int main() {         //INT_MAX问题
//	cout << INT_MAX;
//	int a;
//	cin >> a;
//	if (a > INT_MAX) a=0;
//	cout << a;
//}



//int main() {            //取反
//	int x;
//	cin >> x;
//	if (x < 0) return false;
//	else if (x == 0) return true;
//	else {
//		int s=0, j=0, t = x;
//		while (t != 0) {
//			j = t % 10;
//			t = t / 10;
//			s = s * 10 + j;
//		}
//		if (s == x) return true;
//		else return false;
//	}
//}



//int main() {              //string.end()是尾后迭代器，并不指向最后一个元素
//	string s = "abcdefgh";
//	auto it = s.end();
//	cout << *(it-1);
//}



//int main() {              //vector<string> 的迭代器的使用
//	vector<string> strs = { "abcde","fghij","klmno" };
//	auto it = strs.begin();
//	for (auto r : strs)
//		cout << r << endl;
//	cout << (*it)[2] << endl;
//	cout << (*(it + 1))[1] << endl;
//}



//int main() {                    //对于数组的三重遍历 编译出错，未解决
//	vector<int> nums = { -1,0,1,2,-1,4};
//	vector<vector<int>> ans;
//	ans = threeSum(nums);
//	for (auto r : ans) {
//		for (auto i : r)
//			cout << i << " ";
//		cout << endl;
//	}
//	return 0;
//}
//vector<vector<int>> threeSum(vector<int>& nums) {
//	vector<vector<int>> ans;
//	if (nums.empty()) return ans;
//	int y = 0;
//	for (int i = 0; i < nums.size(); i++)
//		for (int j = i + 1; j < nums.size(); j++)
//			for (int p = j + 1; p < nums.size(); p++) {
//				if (nums[i] + nums[j] + nums[p] == 0) {
//					ans[y].push_back(nums[i]);
//					ans[y].push_back(nums[j]);
//					ans[y].push_back(nums[p]);
//					y++;
//				}
//			}
//	return ans;
//};



//#include<algorithm>                  //foursum遍历方法
//vector<vector<int>> fourSum(vector<int>& nums, int target) {
//	vector<vector<int>> ans;
//	int sum = 0;
//	sort(nums.begin(), nums.end());
//	for (int i = 0; i < nums.size() - 3; ++i) {
//		for (int j = i + 1; j < nums.size() - 2; ++j) {
//			int front = j + 1, back = nums.size() - 1;
//			while (front < back) {
//				sum = nums[i] + nums[j] + nums[front] + nums[back];
//				if (sum == target) {
//					vector<int> ans2;
//					ans2.push_back(nums[i]); ans2.push_back(nums[j]);
//					ans2.push_back(nums[front]); ans2.push_back(nums[back]);
//					ans.push_back(ans2);
//					front++;
//				}
//				if (sum > target) back--;
//				if (sum < target) front++;
//			}
//		}
//	}
//	return ans;
//}
//int main() {
//	vector<int> nums = { 1,0,-1,0,-2,2 };
//	vector<vector<int>> ans = fourSum(nums, 0);
//	for (auto r : ans) {
//		for (auto k : r) {
//			cout << k << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}



//#include<stack>      //stack操作
//int main() {
//	string s;
//	//string s = "abcd";
//	int n = s.size();
//	cout << n;
//	stack<int> a;
//	a.push(1);
//	a.pop() ;
//
//
//	//string s = "()";
//	//int n = s.size();
//	//if (n % 2 == 1 || n == 0) return false;
//
//	//stack<char> a;
//	//for (int i = 0; i < n; ++i) {
//	//	if (s[i] == '(' || s[i] == '[' || s[i] == '{') a.push(s[i]);
//	//	else {
//	//		switch (a.top()) {
//	//		case '(': if (s[i] != ')') return false;
//	//		case '[': if (s[i] != ']') return false;
//	//		case '{': if (s[i] != '}') return false;
//	//		}
//	//		a.pop();
//	//	}
//	//}
//	//
//	//return true;
//}



//int main() {
//	int a = 1;
//	while (a = 2) {         //while内放执行语句
//		cout << a;
//	}
//}



//#include<algorithm>       //leetcode
//vector<int> searchRange(vector<int>& nums, int target);
//int main() {
//	vector<int> nums{ 5,6,6,8,8,10 };
//	int target = 8;
//	vector<int> ans = searchRange(nums, target);
//	for (auto r : ans)
//		cout << r << " ";
//}
//vector<int> searchRange(vector<int>& nums, int target) {
//	vector<int> ans, mid;
//	int a=0, b=0;
//	for (int i = 0; i < nums.size(); ++i) {
//		if (nums[i] == target) {
//			mid.push_back(i);
//		}
//		//a = *max_element(mid.begin(), mid.end());
//		//b = *min_element(mid.begin(), mid.end());
//		//ans.push_back(b);
//		//ans.push_back(a);
//		//for (auto y : mid)
//		//	cout << y << endl;
//		//return ans;
//	}
//	if (mid.empty()) {
//		ans.push_back(-1);
//		ans.push_back(-1);
//		return ans;
//	}
//	else {
//		a = *max_element(mid.begin(), mid.end());
//		b = *min_element(mid.begin(), mid.end());
//		ans.push_back(b);
//		ans.push_back(a);
//		return ans;
//	}
//}



//void rotate(vector<vector<int>>& num) {
//	if (num.empty()) return;
//	int n = num.size();
//	for (int i = 0; i < n; ++i)
//		for (int j = 0; j < n; ++j) {
//			if (j > i) swap(num[i][j], num[j][i]);
//		}
//	int l = 0;
//	//while (l < n) {
//	//	for (int i = 0; i < n; ++i)
//	//		swap(num[i][l], num[i][n]);
//	//	++l;
//	//	--n;
//	//}
//}
//int main() {      //矩阵转置
//	vector<vector<int>> a = { {1,2,3},{4,5,6},{7,8,9} };
//	int n = a.size();
//	//for (int i = 0; i < n; ++i)
//	//	for (int j = 0; j < n; ++j) 
//	//		if (j > i) swap(a[i][j], a[j][i]);
//	rotate(a);
//	for (auto r : a) {
//		for (auto p : r)
//			cout << p << " ";
//		cout << endl;
//	}
//}



//double myPow(double x, int n) {   //数的精度问题
//	double a = 1;
//	for (int i = 0; i < n; ++i)
//		a = a * x;
//	if (n < 0) {
//		a = 1.0000 / a;
//		return a;
//	}
//	return a;
//}
//int main() {
//	cout << (1.0000 / 4.0000) << endl;
//	double x = 2.0000;
//	int n = -2;
//	cout << myPow(x, n) << endl;
//	cout << (-2 % 2) << endl;
//	cout << (-3 % 2) << endl;
//}



//void backtrack(vector<vector<string>>& ans, vector<string>& a, int n, int c);   51.N-Queens回溯（提交）
//vector<vector<string>> solveNQueens(int n) {
//	vector<vector<string>> ans;
//	string s;
//	vector<string> a;
//	for (int i = 0; i < n; ++i)
//		s = s + '.';
//	for (int i = 0; i < n; ++i)
//		a.push_back(s);
//	//vector<int> count;
//	backtrack(ans, a, n, 0);
//	return ans;
//}
//void backtrack(vector<vector<string>>& ans, vector<string>& a, int n, int c) {
//	for (int i = 0; i < n; ++i) {
//		a[c][i] == 'Q';
//		//count.push_back(1);   //operation
//
//		for (int j = 0; j < c; ++j)
//			if (a[j][i] == 'Q') return;
//		for (int row = i - 1, col = c - 1; row >= 0 && col >= 0;) {
//			if (a[row][col] == 'Q') return;
//			--row; --col;
//		}
//		for (int row = i - 1, col = c + 1; row >= 0 && col < n;) {
//			if (a[row][col] == 'Q') return;
//			--row; ++col;
//		}   //返回条件
//
//		if (c == n) ans.push_back(a);   //成功条件
//
//		backtrack(ans, a, n, c + 1);   //回溯点
//
//		a[c][i] = '.';   //逆operation
//	}
//}
//int main() {
//	vector<vector<string>> ans = solveNQueens(4);
//	for (auto r : ans) {
//		for (auto p : r)
//			cout << p << " ";
//		cout << endl;
//	}
//}



//#include<algorithm>   //vector<vector<int>>类型的sort
//int main() {
//	vector<vector<int>> a = { {20,18},{2,6},{8,10},{1,3} };
//	sort(a.begin(), a.end());
//	for (auto i : a)
//		for (auto j : i)
//			cout << j << " ";
//
//}



//int lengthOfLastWord(string s) {   //注意非主函数中变量的初始化
//	if (s.empty()) return 0;
//	if (s.find(' ') == s.npos) return s.size();
//	int ans=0;
//	for (int i = s.size() - 1; i >= 0; --i) {
//		if (s[i] == ' ') return ans;
//		ans++;
//	}
//	return -1;
//}
//int main() {
//	string s = "hello world";
//	int a = lengthOfLastWord(s);
//	cout << a << endl;
//	int n = 3;
//	vector<int> b(n, 0);
//	vector<int> ans(n, vector<int>(n, 0));
//	vector<vector<int>> c(n, n, 0);
//}




//int factorial(int n);         //60. Permutation Sequence
//string getPermutation(int n, int k) {
//	if (n == 1) return to_string(1);
//	if (n == 2) {
//		if (k == 1) return to_string(12);
//		if (k == 2) return to_string(21);
//	}
//
//	string ans;
//	int remainder = k % factorial(n - 1);
//	int quotient = k / factorial(n - 1);
//	//特殊情况，加快速度
//	if (remainder == 0) {
//		ans = ans + to_string(quotient);
//		for (int i = n; i > 0; --i) {
//			if (i == quotient) continue;
//			ans = ans + to_string(i);
//		}
//		return ans;
//	}
//	if (remainder == 1) {
//		ans = ans + to_string(quotient + 1);
//		for (int i = 1; i <= n; ++i) {
//			if (i == quotient + 1) continue;
//			ans = ans + to_string(i);
//		}
//		return ans;
//	}
//
//	//一般情况
//	string s = "12";
//	for (int i = 3; i <= n; ++i)
//		s = s + to_string(i);
//	while (1) {
//		if (remainder == 0) {
//			ans += s[quotient - 1];
//			s.erase(s.begin() + (quotient-1));
//			reverse(s.begin(), s.end());
//			ans += s;
//			return ans;
//		}
//		else {
//			ans += s[quotient];
//			s.erase(s.begin() + quotient);
//		}
//		k %= factorial(n - 1);
//		n--;
//		//if (s.size() == 2) {
//		//	if (quotient == 1) {
//		//		ans += s[0];
//		//		ans += s[1];
//		//	}
//		//	else {
//		//		ans = ans + s[1] + s[0];
//		//	}
//		//}
//		if (s.size() == 1) {
//			ans += s[0];
//			return ans;
//		}
//		remainder = k % factorial(n - 1);
//		quotient = k / factorial(n - 1) ;
//	}
//	return ans;
//}
//
//int factorial(int n) {
//	if (n == 1) return 1;
//	return n * factorial(n - 1);
//}
//#include<math.h>
//int main() {
//	for (int i = 1; i <= 24; ++i) {
//		cout << getPermutation(5, i) << endl;
//	}
//	//cout << getPermutation(4, 8) << endl;
//
//	//string s = "123456";
//	//s.erase('4');   //错误的用法！
//	//cout << s;
//}



//#include<algorithm>
//int main() {
//	//string s (6, 'a');
//	//s.pop_back();
//	//cout << s;
//	int a = sqrt(8);
//	cout << a;
//}



//#include<stack>   //71.Simplify Path
//int main() {
//	string path = "/home//foo///";
//	string ans;
//	stack<string> a;
//	for (int i = 1; i < path.size(); ++i) {
//		if (path[i] == '/') continue;
//		if (path[i] == '.') {
//			if (path[i - 1] == '.') {
//				a.pop();
//				continue;
//			}
//			else continue;
//		}
//		//for(int j=i;j<path.size();++j){}
//		int j = i;
//		cout << "j=" << j << endl;
//		while (path[i] != '/')
//			i++;
//		i--;
//		cout << i << endl;
//		string s = path.substr(j, i-j+1);
//		cout << s << endl;
//		a.push(s);
//	}
//	cout << a.top() << endl;
//	while (a.empty() == 0) {
//		ans = a.top() + '/' + ans;
//		a.pop();
//	}
//	ans.erase(ans.end() - 1);
//	ans = '/' + ans;
//	cout << ans << endl;
//}



//void setZeroes(vector<vector<int>>& matrix) {   //	73		Set Matrix Zeroes
//	if (matrix.empty()) return;
//	int m = matrix.size(), n = matrix[0].size();
//	vector<int> row(m, 1), col(n, 1);
//	for (int i = 0; i < m; ++i)
//		for (int j = 0; j < n; ++j)
//			if (matrix[i][j] == 0) {
//				row[i] = 0;
//				col[j] = 0;
//			}
//	//for (int i : row)
//	//	if (row[i] == 0)
//	//		matrix[i].assign(n, 0);
//	//for (int i : col) {
//	//	if (col[i] == 0)
//	//		for (int j = 0; j < m; ++j)
//	//			matrix[j][i] = 0;
//	//}
//
//	for (int i = 0; i < m; ++i) {
//		if (row[i] == 0)
//			matrix[i].assign(n, 0);
//	}
//	for (int i = 0; i < n; ++i) {
//		if(col[i]==0)
//			for (int j = 0; j < m; ++j)
//				matrix[j][i] = 0;
//	}
//
//	return;
//}
//int main() {
//	vector<vector<int>> a = { {0,1,2,0},{3,4,5,2},{1,3,1,5} };
//	setZeroes(a);
//	for (auto i : a) {
//		for (auto j : i)
//			cout << j << " ";
//		cout << endl;
//	}
//}



//#include<cstdio>   //remove,erase要包含algorithm
//#include<algorithm>
//string minWindow(string s, string t) {   //	76.Minimum Window Substring
//	if (s.empty() || t.empty()) return "";
//	if (t.size() == 1) {
//		if (s.find(t) != s.npos) {
//			return t;
//		}
//		return "";
//	}
//
//	int start = 0, end = s.size() - 1;
//	int n = t.size() - 1, mins = s.size();
//	for (int i = 0; i < s.size()-t.size()+1; ++i) {
//		//auto it2 = find(t.begin(), t.end(), 'c');
//		if (find(t.begin(), t.end(), s[i]) == t.end()) continue;
//		for (int j = i; j < s.size(); ++j) {
//			if (n == -1) {
//				if (j - 1 - i < mins) {
//					start = i;
//					end = j ;
//					n = t.size() - 1;
//					break;
//				}
//			}
//			if (find(t.begin(), t.begin() + n+1, s[j]) == t.begin()+ n+1) continue;
//			auto it = remove(t.begin(), t.begin() + n, s[j]);
//			n--;
//		}
//	}
//	cout << start << " " << end << endl;
//	t.assign(s.begin() + start, s.begin() + end + 1);
//	return t;
//}
//int main() {
//	//string s = "abcdefg";
//	//s.erase(remove(s.begin(), s.end(), 'c'), s.end());
//	//auto it=remove(s.begin(), s.end(), "c");
//	//auto it2=s.find('c');
//	//vector<char> a;
//	//remove(a.begin(), a.end(), 'c');
//
//
//	string s = "ADOBECODEBANC", t = "ABC";
//	cout << minWindow(s, t) << endl;
//	t.assign(s.begin(), s.begin()+12);
//	cout << s << endl;
//	cout << t << endl;
//	cout << s[s.size()] << endl;
//	cout << s[s.size()-1] << endl;
//	if (find(t.begin(), t.begin() + 1, 'A') == t.begin() + 1) {
//		cout << 6 << endl;
//	}
//}



//int main() {
//	//vector<vector<int>> subs = { {} };
//	//cout << subs.size() << endl;
//	vector<int> a = { 0,1,2,3,4,5,6,7,8,9 };   //观察vector.erase(begin,end);
//	a.erase(a.begin() + 2, a.begin() + 5);
//	for (auto i : a) {
//		cout << i << " ";
//	}
//	string s = "bdbaoebwf avhdv";
//	s.erase(0, 1);
//}



//int removeDuplicates(vector<int>& nums) {   //80.Remove Duplicates from Sorted Array II
//	int n = nums.size();
//	if (n <= 2) return n;
//	int subtractor = 0;
//
//	nums.push_back(-1);
//	int i = 2, j = n + 1;
//	while (i < j) {
//		if (nums[i- subtractor] == nums[i - subtractor - 2]) {
//			for (int p = i; p < j; p++) {
//				if (nums[p- subtractor] != nums[i- subtractor]) {
//					
//					n = n - p + i;
//					nums.erase(nums.begin() + i- subtractor, nums.begin() + p- subtractor);
//					subtractor = p - i;
//					i = p-1;
//					break;
//				}
//			}
//		}
//		i++;
//	}
//	cout << i << endl;
//	return n;
//}
//int main() {
//	vector<int> nums = { 0,0,1,1,2,2,3,3,3,3,3,3,3,3 };
//	int a=removeDuplicates(nums);
//	cout << a << endl;
//	for (auto i : nums) {
//		cout << i << " ";
//	}
//}



//#include<algorithm>   //84.Largest Rectangle in Histogram  
//int largestRectangleArea(vector<int>& heights) {
//	if (heights.empty()) return 0;
//	int n = heights.size();
//	if (n == 1) return heights[0];
//	int maxarea = 0;
//	for (int i = 0; i < n; ++i) {
//		for (int j = i; j < n; ++j) {
//			int p = *min_element(heights.begin() + i, heights.begin() + j);
//			int x = (j - i + 1)*p;
//			//int x = (j - i + 1)*(*min_element(heights.begin() + i, heights.begin() + j));
//			//maxarea = max(maxarea, x);
//			if (x > maxarea) {
//				maxarea = x;
//				cout << i << "  " << j << "  " << maxarea << "  " << p << endl;
//			}
//		}
//	}
//	return maxarea;
//}
//int main() {
//	vector<int> heights = { 0,1,2,3,4,5 };
//	int b = *min_element(heights.begin() + 0, heights.begin() + 1);
//	cout << b << endl;
//
//	cout << largestRectangleArea(heights) << endl;
//}



//#include<algorithm>   //85.Maximal Rectangle
//int subsearch(vector<vector<char>> matrix, int i, int j) {
//	int right = j, bottom = i;
//	for (; bottom < matrix.size(); ++bottom)
//		if (matrix[bottom][j] == 0) break;
//	for (; bottom < matrix[0].size(); ++right)
//		if (matrix[i][right] == 0) break;
//	int ret = max(bottom - i, right - j);
//	if (bottom == i + 1) return ret;   //若matrix[i+1][j]=0,直接返回；
//	for (int p = i + 1; p < bottom; ++p) {
//		for (int q = j; q < right; ++q) {
//			if (matrix[p][q] == 0) {
//				int x = (p - i + 1)*(q - j + 1);
//				ret = max(ret, x);
//			}
//		}
//	}
//	return ret;
//}
//int main() {
//	vector<vector<char>> a = { {1,0,1,0,0},{1,0,1,1,0},{1,1,1,1,0},{1,0,0,1,0} };
//	cout << subsearch(a, 1, 2) << endl;
//}



//int main() {   //快速把vector插入到另一个vector之后
//	vector<int> a = { 1,2,3 }, b = { 4,5,6 };
//	//a = a + b;   错误
//
//	//for (auto i : b)
//	//	a.push_back(i);
//	//for (auto i : a)
//	//	cout << i << " ";
//
//	a.insert(a.end(), b.begin(), b.end());
//	for (auto i : a)
//		cout << i << " ";
//}



//vector<vector<int>> subsetsWithDup(vector<int>& nums) {   //90. Subsets II
//	vector<vector<int>> ans;
//	if (nums.empty()) return ans;
//
//	int n = nums.size();
//	vector<int> a;
//	ans.push_back(a);
//	a.push_back(nums[0]);
//	ans.push_back(a);
//	cout << ans.size() << endl;
//
//	if (n == 1)
//		return ans;
//
//	for (int i = 1; i < n; i++) {
//		int x = ans.size();
//		for (int j = 0; j < x; ++j) {
//			vector<int> b = ans[j];
//			b.push_back(nums[i]);
//			for (auto i : b)
//				cout << i << " ";
//			cout << endl;
//			if (find(ans.begin(), ans.end(), b) == ans.end())
//			    ans.push_back(b);
//		}
//	}
//	return ans;
//}
//int main() {
//	vector<int> a = { 1,2 };
//	//if (find(a.begin(), a.end(), 1) == a.end()) return 1;
//	//return -1;
//
//	vector<vector<int>> exm = subsetsWithDup(a);
//	for (auto i : exm) {
//		for (auto j : i) {
//			cout << j << " ";
//		}
//		cout << endl;
//	}
//}



//struct TreeNode {   //100.Same Tree
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//class Solution {
//public:
//	bool isSameTree(TreeNode* p, TreeNode* q) {
//		if (p->val != q->val) return false;
//		vector<TreeNode*> a, b;
//		front(p, a);
//		front(q, b);
//		if (a.size() != b.size()) return false;
//		cout << a.size() << "   " << b.size() << endl;
//		for (int i = 0; i < a.size(); ++i) {
//			//if (compareTN(a[i], b[i]) == false) return false;
//			cout << compareTN(a[i], b[i]) << endl;
//		}
//		return true;
//	}
//private:
//	void front(TreeNode* root, vector<TreeNode*>& a) {
//		if (root == NULL) return;
//		front(root->left, a);
//		a.push_back(root);
//		front(root->right, a);
//	}
//	bool compareTN(TreeNode* p, TreeNode* q) {
//		if (p == NULL && q == NULL) return true;
//		bool flag = (p->val == q->val) && compareTN(p->left, q->left) && compareTN(p->right, q->right);
//		return flag;
//	}
//};
//int main() {
//	TreeNode a1(1), a2(2), a3(3);
//	TreeNode b1(1), b2(2), b3(3);
//	a1.left = &a2;
//	a1.right = &a3;
//	b1.left = &b2;
//	b1.right = &b3;
//	TreeNode *a = &a1;
//	TreeNode *b = &b1;
//	TreeNode *c = &a1;
//	Solution same;
//	cout << same.isSameTree(a,b) << endl;
//}



//struct ListNode {   //55.链表中环的入口结点
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//		val(x), next(NULL) {
//	}
//};
//ListNode* EntryNodeOfLoop(ListNode* head) {
//	if (!head) return NULL;
//	ListNode* f = head;
//	ListNode* s = head;
//	int count = 0;
//	bool flag = false;
//	while (f && f->next) {
//		s = s->next;
//		f = f->next->next;
//		count++;
//		if (f == s) {
//			flag = true;
//			break;
//		}
//	}
//	if (flag == false) return NULL;
//	f = head;
//	s = head;
//	while (count--)
//		f = f->next;
//	while (f != s) {
//		f = f->next;
//		s = s->next;
//	}
//	return f;
//}
//ListNode* deleteDuplication(ListNode* head)
//{
//	if (!head) return NULL;
//	if (!(head->next)) return head;
//	ListNode *f = head;
//	ListNode* s = new ListNode(0);
//	s->next = head;
//	ListNode* ss = s;
//	while (f->next) {
//		if (f->val == f->next->val) {
//			int tmp = f->val;
//			while (f->val == tmp) {
//				if(f->next==NULL)
//				f = f->next;
//			}
//			s->next = f;
//		}
//		else {
//			s = s->next;
//			f = f->next;
//		}
//	}
//	if (!(ss->next)) return NULL;   //全重复链表
//	//delete s;   //不能释放s和ss，原因？
//	//delete ss;
//	return head;
//}

//ListNode* deleteDuplication(ListNode* pHead)   //答案，感觉有问题
//{
//	if (pHead == NULL || pHead->next == NULL) { return pHead; }
//	ListNode *Head = new ListNode(0);
//	Head->next = pHead;
//	ListNode* pre = Head;
//	ListNode* last = Head->next;
//	while (last != NULL) {
//		if (last->next != NULL && last->val == last->next->val) {
//			// 找到最后的一个相同节点
//			while (last->next != NULL && last->val == last->next->val) {
//				last = last->next;
//			}
//			pre->next = last->next;
//			last = last->next;
//		}
//		else {
//			pre = pre->next;
//			last = last->next;
//		}
//	}
//	return Head->next;
//}
//int main() {
//	//ListNode* p1 = new ListNode(1);
//	//ListNode* p2 = new ListNode(2);
//	//ListNode* p3 = new ListNode(3);
//	//ListNode* p4 = new ListNode(4);
//	//ListNode* p5 = new ListNode(5);
//	//ListNode* p6 = new ListNode(6);
//	//ListNode* p7 = new ListNode(7);
//	//ListNode* p8 = new ListNode(8);
//	//p1->next = p2;
//	//p2->next = p3;
//	//p3->next = p4;
//	//p4->next = p5;
//	//p5->next = p6;
//	//p6->next = p7;
//	//p7->next = p8;
//	//p8->next = p4;
//	//ListNode* p = EntryNodeOfLoop(p1);
//	//cout << p->val << endl;
//
//	
//	ListNode* p1 = new ListNode(2);
//	ListNode* p2 = new ListNode(2);
//	//ListNode* p3 = new ListNode(3);
//	//ListNode* p4 = new ListNode(3);
//	//ListNode* p5 = new ListNode(4);
//	//ListNode* p6 = new ListNode(4);
//	//ListNode* p7 = new ListNode(5);
//	p1->next = p2;
//	//p2->next = p3;
//	//p3->next = p4;
//	//p4->next = p5;
//	//p5->next = p6;
//	//p6->next = p7;
//	p2->next = NULL;
//	ListNode* p = deleteDuplication(p1);
//	while (p) {
//		cout << p->val << "  ";
//		p = p->next;
//	}
//}



#include<iostream>   //网易
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//int main() {
//	int t;
//	cin >> t;
//	vector<bool> ans(t, true);
//	int n;
//	while (cin >> n) {
//		vector<int> v(n);
//		for (int i = 0; i < v.size(); ++i)
//			cin >> v[i];
//		
//		t--;
//		for (int i = 1; i < v.size() - 1; ++i) {
//			if (v[i] > v[i - 1] + v[i + 1])
//				ans[t] = false;
//		}
//		if (v[0] > v[1] + v[n - 1])
//			ans[t] = false;
//		if (v[n - 1] > v[n - 2] + v[0])
//			ans[t] = false;
//	}
//	for (int i = ans.size() - 1; i >= 0; --i) {
//		if (ans[i])
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//}



//int main() {
//	int n, q;
//	cin >> n >> q;
//	vector<int> v(n);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i];
//	sort(v.begin(), v.end());
//
//	vector<int> v2(q);
//	for (int i = 0; i < q; ++i)
//		cin >> v2[i];
//
//	vector<int> ans(q ,0);
//	for (int i = 0; i < q; ++i) {
//		for (int j = 0; j < n; ++j) {
//			if (v[j] >= v2[i]) {
//				v[j]--;
//				ans[i]++;
//			}
//		}
//	}
//
//	for (int i = 0; i < q; ++i)
//		cout << ans[i] << endl;
//}
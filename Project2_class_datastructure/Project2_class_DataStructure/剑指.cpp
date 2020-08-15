//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<cstdlib>
//#include<iomanip>
//#include<cstring>
//#include<string>
//#include<string>
//#include<ctime>
//#include<vector>
////#include"LinkList.h"
//#include<stack>
//using namespace std;


//int half(vector<int> v, int t) {   //剑指1.二维数组找数
//	int n = v.size();
//	int left = 0, right = n - 1;
//
//	while (left <= right) {
//		int mid = (left + right) / 2;
//		if (v[mid] > t)
//			right = mid - 1;
//		else if (v[mid] < t)
//			left = mid + 1;
//		else
//			return mid;
//	}
//	return right;
//}
//bool Find(int target, vector<vector<int> > array) {
//	int row = array.size(), col = array[0].size();
//	if (row == 0) return false;
//	int r = half(array[0], target);
//	cout << "r:" << r << endl;
//	if (r < 0) return false;
//	if (array[0][r] == target) return true;
//	vector<int> v;
//	for (int i = 0; i < row; ++i)
//		v.push_back(array[i][r]);
//	for (auto p : v)
//		cout << p << " ";
//	cout << endl;
//	int c = half(v, target);
//	cout << "c:" << c << endl;
//	if (c < 0) return false;
//	if (array[c][r] == target) return true;
//	return false;
//}
//int main() {
//	vector<int> v = { 2,4,7,8 };
//	vector<int> v2 = { 1,2,8,9 };
//	vector<vector<int> > array = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
//	//int t = 6;
//	cout << half(v, 7) << endl;
//	cout << half(v2, 7) << endl;
//	cout << Find(7, array) << endl;
//}




//class Solution {   //6.旋转数组的最小数字
//public:
//	int minNumberInRotateArray(vector<int> rotateArray) {
//		int size = rotateArray.size();
//		if (size == 0) {
//			return 0;
//		}//if
//		int left = 0, right = size - 1;
//		int mid = 0;
//		// rotateArray[left] >= rotateArray[right] 确保旋转
//		while (rotateArray[left] >= rotateArray[right]) {
//			// 分界点
//			if (right - left == 1) {
//				mid = right;
//				break;
//			}//if
//			mid = left + (right - left) / 2;
//			// rotateArray[left] rotateArray[right] rotateArray[mid]三者相等
//			// 无法确定中间元素是属于前面还是后面的递增子数组
//			// 只能顺序查找
//			if (rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid]) {
//				return MinOrder(rotateArray, left, right);
//			}//if
//			// 中间元素位于前面的递增子数组
//			// 此时最小元素位于中间元素的后面
//			if (rotateArray[mid] >= rotateArray[left]) {
//				left = mid;
//			}//if
//			// 中间元素位于后面的递增子数组
//			// 此时最小元素位于中间元素的前面
//			else {
//				right = mid;
//			}//else
//		}//while
//		return rotateArray[mid];
//	}
//private:
//	// 顺序寻找最小值
//	int MinOrder(vector<int> &num, int left, int right) {
//		int result = num[left];
//		for (int i = left + 1; i < right; ++i) {
//			if (num[i] < result) {
//				result = num[i];
//			}//if
//		}//for
//		return result;
//	}
//};
//
//int main() {
//	Solution s;
//	//vector<int> num = {0,1,2,3,4,5};
//	//vector<int> num = {4,5,6,7,1,2,3};
//	vector<int> num = { 2,2,2,2,1,2 };
//	int result = s.minNumberInRotateArray(num);
//	// 输出
//	cout << result << endl;
//	return 0;
//}



//int Fibonacci(int n) {   //7.斐波那契数列，递归法（最好不要用，花费太大）
//	if (n == 0) return 0;
//	if (n < 3) return 1;
//	return Fibonacci(n - 1) + Fibonacci(n - 2);
//}
//int  NumberOf1(int n) {   
//	int count = 0;
//	while (n) {
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//int main() {
//	cout << Fibonacci(6) << endl;
//	if (-1)   //非0为真
//		cout << -1 << endl;
//	cout << NumberOf1(15) << endl;
//}



//double Power(double base, int exponent) {   //12.数值的整数次方，快速幂
//	double ans = 1, fast = base;
//	int n;
//	if (exponent > 0)
//		n = exponent;
//	else if (exponent < 0) {
//		n = -exponent;
//	}
//	else
//		return 1;
//	while (n) {
//		if ((n&1) == 1)
//			ans *= fast;
//		fast *= fast;
//		n >>= 1;
//	}
//	return exponent >= 0 ? ans : (1 / ans);
//}
//int main() {
//	cout << Power(2, 3) << endl;
//}



//int Half(vector<int> v,int target) {   //折半返回区间左值
//	int n = v.size();
//	if (n == 0) return -1;
//	if (n == 1) return target == v[0] ? 0 : -1;
//
//	int left = 0, right = n - 1;
//	while (left <= right) {
//		int mid = (left + right) / 2;
//		if (v[mid] < target)
//			left = mid+1;
//		else if (v[mid] > target)
//			right = mid-1;
//		else
//			return mid;
//	}
//	return right;   //right对应左值，left对应右值
//}
//int main() {
//	vector<int> v = { 1,3,5,7,9 };
//	cout << Half(v, 1) << endl;
//	cout << Half(v, 3) << endl;
//	cout << Half(v, 5) << endl;
//	cout << Half(v, 9) << endl;
//	cout << Half(v, 2) << endl;
//	cout << Half(v, 6) << endl;
//
//	Node *p = new Node;
//	p->date = 2;
//	p->date = 3;
//
//	cout << v.front() << endl;
//	v.back() = 6;
//	cout << v[3] << " " << v[4] << endl;
//}
//vector<int> vec() {
//	return vector<int>();
//}



//bool IsPopOrder(vector<int> pushV, vector<int> popV) {   //21.栈的压入弹出顺序
//	if (pushV.empty()) return 0;
//	stack<int> s;
//	int j = 0;
//	for (int i = 0; i < pushV.size(); ++i) {
//		s.push(pushV[i]);
//		while (s.empty()==false && popV[j] == s.top()) {
//			s.pop();
//			j++;
//		}
//	}
//	return s.empty();
//}
//int main() {
//	vector<int> v1 = { 1,2,3,4,5 };
//	vector<int> v2 = { 4,5,3,2,1 };
//	cout << IsPopOrder(v1, v2) << endl;
//}



//#include"SORT.h"      //排序
//int main() {
//	int h[10] = { 9,1,5,8,3,7,4,6,2,12};
//	MergeSort(h, 0,9);
//	for (int i = 0; i < 10; ++i)
//		cout << h[i] << " ";
//}



//#include<map>
//#include<unordered_map>
//int FirstNotRepeatingChar(string str) {   //34.第一个只出现一次的数
//	if (str.empty()) return -1;
//	if (str.size() == 1) return 0;
//	unordered_map<char, int> count;
//	for (int i = 0; i < str.size(); ++i)
//		count[str[i]]++;
//	for (auto it = count.begin(); it != count.end(); ++it)
//		if (it->second == 1)
//			return it - count.begin();
//	return -1;
//}
//int main() {
//	map<int, int> m;
//	m[2]++;
//	m[2]++;
//	cout << m[2] << endl;
//	string s1 = "32";
//	string s2 = "321";
//	cout << (s1<s2) << endl;
//}



//class Solution {   //35.数组中的逆序对
//public:
//	long long ans=0;
//	int InversePairs(vector<int> data) {
//		if (data.size() <= 1) return 0;
//		int l = 0, r = data.size() - 1;
//		MergeSort(data, l, r);
//		for (int i = 0; i < data.size(); ++i) {
//			cout << data[i] << "  ";
//		}
//		cout << endl;
//		return ans % 1000000007;
//	}
//	void MergeSort(vector<int>& data, int l, int r) {
//		if (l >= r) return;
//		int m = (l + r) / 2;
//		MergeSort(data, l, m);
//		MergeSort(data, m + 1, r);
//		Merge(data, l, m, r);
//	}
//	void Merge(vector<int>& arr, int l, int q, int r) {
//		int n = r - l + 1;//临时数组存合并后的有序序列
//		int* tmp = new int[n];
//		int i = 0;
//		int left = l;
//		int right = q + 1;
//		while (left <= q && right <= r) {
//			if (arr[left] < arr[right])
//				tmp[i++] = arr[left++];
//			else {
//				tmp[i++] = arr[right++];
//				ans += q - left + 1;
//				cout << "q=" << q << "   left=" << left << endl;
//				cout << ans << endl;
//			}
//		}
//		while (left <= q)
//			tmp[i++] = arr[left++];
//		while (right <= r)
//			tmp[i++] = arr[right++];
//		for (int j = 0; j < n; ++j)
//			arr[l + j] = tmp[j];
//		delete[] tmp;//删掉堆区的内存
//	}
//};
//int main() {
//	Solution A;
//	vector<int> v = { 1,2,3,4,5,0 };
//	cout << A.InversePairs(v) << endl;
//	for (int i = 0; i < v.size(); ++i) {
//		cout << v[i] << "  ";
//	}
//}




//int main() {   //37.数字在排序数组中出现的次数，检验返回区间的左端
//	vector<int> v = { 1,2,3,3,3,3};
//	int k = 3;
//	int l = 0, r = v.size() - 1;
//	int m;
//	while (l < r) {
//		m = (l + r) / 2;
//		if (v[m] >= k)
//			r = m;
//		else
//			l = m + 1;
//	}
//	cout << m << endl;
//	int count=0;
//	for (int i = m; i < v.size(); ++i) {
//		if (v[i] != k)
//			break;
//		count++;
//	}
//	cout << count << endl;
//}



//#include<list>
//int StrToInt(string str) {   //49.字符串转化成整数
//	if (str.empty()) return 0;
//	if ((str[0]<'0' || str[0]>'9'))
//		if (str[0] != '+' && str[0] != '-')
//			return 0;
//
//	//int multiple = 1;
//	int ans = 0;
//	if (str[0] == '+' || str[0] == '-') {
//		for (int i = 1; i < str.size(); ++i) {
//			if (str[i]<'0' || str[i]>'9')
//				return 0;
//			ans = ans * 10 + (str[i] - '0');
//		}
//		return str[0] == '+' ? ans : -ans;
//	}
//	else {
//		for (int i = 0; i < str.size(); ++i) {
//			if (str[i]<'0' || str[i]>'9')
//				return 0;
//			ans = ans * 10 + (str[i] - '0');
//			cout << ans << endl;
//		}
//		return ans;
//	}
//}
//int main() {
//	//cout << StrToInt("2") << endl;
//	//cout << StrToInt("12") << endl;
//	cout << StrToInt("123") << endl;
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
//ListNode* deleteDuplication(ListNode* head)   //56.删除链表中重复的结点
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

//ListNode* deleteDuplication(ListNode* pHead)   //答案，感觉有问题（没问题，自己想复杂了）
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
	//ListNode* p1 = new ListNode(1);
	//ListNode* p2 = new ListNode(2);
	//ListNode* p3 = new ListNode(3);
	//ListNode* p4 = new ListNode(4);
	//ListNode* p5 = new ListNode(5);
	//ListNode* p6 = new ListNode(6);
	//ListNode* p7 = new ListNode(7);
	//ListNode* p8 = new ListNode(8);
	//p1->next = p2;
	//p2->next = p3;
	//p3->next = p4;
	//p4->next = p5;
	//p5->next = p6;
	//p6->next = p7;
	//p7->next = p8;
	//p8->next = p4;
	//ListNode* p = EntryNodeOfLoop(p1);
	//cout << p->val << endl;


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




//class Solution {
//public:
//	bool hasPath(char* matrix, int rows, int cols, char* str) {
//		if (matrix == NULL) return false;
//		vector<int> map(rows*cols, 0);
//		for (int i = 0; i < rows; ++i)
//			for (int j = 0; j < cols; ++j)
//				if (backtrack(matrix, i, j, rows, cols, str, map))
//					return true;
//		return false;
//	}
//private:
//	bool backtrack(char* matrix, int i, int j, int rows, int cols, char* str, vector<int>& map) {
//		int index = i * cols + j;
//		if (i < 0 || j < 0 || i >= rows || j >= cols || map[index] == 1 || matrix[index] != *str)
//			return false;
//		if (*(str + 1) == 0) return true;
//		else str++;
//		map[index] = 1;
//		if (backtrack(matrix, i - 1, j, rows, cols, str, map) ||
//			backtrack(matrix, i + 1, j, rows, cols, str, map) ||
//			backtrack(matrix, i, j - 1, rows, cols, str, map) ||
//			backtrack(matrix, i, j + 1, rows, cols, str, map))
//			return true;
//		map[index] = 0;
//		return false;
//	}
//};


//class Solution {   //66.机器人的运动范围
//public:
	//int movingCount(int threshold, int rows, int cols)
	//{
	//	int mp[rows*cols];
	//	bool map[rows*cols];
	//	return backtrack(threshold, 0, 0, rows, cols, map);
	//}
//private:
//	int backtrack(int threshold, int i, int j, int rows, int cols, bool[] map) {
//		int index = cols * i + j;
//		if (i < 0 || j < 0 || i >= rows || j >= cols || map[index] == true ||
//			!(enterable(threshold, rows, cols)))
//			return 0;
//		map[index] = true;
//		return 1 + backtrack(threshold, i - 1, j, rows, cols,map) + \
//			backtrack(threshold, i + 1, j, rows, cols,map) + \
//			backtrack(threshold, i, j - 1, rows, cols,map) + \
//			backtrack(threshold, i, j + 1, rows, cols,map);
//	}
//	bool enterable(int threshold, int row, int col) {
//		int n = 0;
//		while (row) {
//			n += (row % 10);
//			row /= 10;
//		}
//		while (col) {
//			n += (col % 10);
//			col /= 10;
//		}
//		return n <= threshold;
//	}
//};

//class Solution {   //66.机器人的运动范围
//public:
//	int movingCount(int threshold, int rows, int cols)
//	{
//		vector<bool> mp(rows*cols, false);
//		return backtrack(threshold, 0, 0, rows, cols, mp);
//	}
//private:
//	int backtrack(int threshold, int i, int j, int rows, int cols, vector<bool>& mp) {
//		int index = cols * i + j;
//		if (i < 0 || j < 0 || i >= rows || j >= cols || mp[index] == true || enterable(threshold, i, j) == false)
//			return 0;
//		mp[index] = true;
//		return 1 + backtrack(threshold, i - 1, j, rows, cols, mp) + \
//			backtrack(threshold, i + 1, j, rows, cols, mp) + \
//			backtrack(threshold, i, j - 1, rows, cols, mp) + \
//			backtrack(threshold, i, j + 1, rows, cols, mp);
//	}
//	bool enterable(int threshold, int row, int col) {
//		int n = 0;
//		while (row) {
//			n += (row % 10);
//			row /= 10;
//		}
//		while (col) {
//			n += (col % 10);
//			col /= 10;
//		}
//		return n <= threshold;
//	}
//};
//class Solution2 {   //答案
//public:
//	int movingCount(int threshold, int rows, int cols)
//	{
//		vector<vector<bool>> map(rows + 1);
//		for (int i = 0; i < rows + 1; i++)
//			map[i].resize(cols + 1, 0);
//		return GetCount(threshold, 0, 0, rows, cols, map);
//	}
//	int GetCount(int key, int x, int y, int rows, int cols, vector<vector<bool>>& map)
//	{
//		if (x < 0 || x >= rows || y<0 || y >= cols || AddSum(x) + AddSum(y)>key || map[x][y] == 1)
//			return 0;
//		map[x][y] = 1;
//		return 1 + \
//			GetCount(key, x - 1, y, rows, cols, map) + \
//			GetCount(key, x + 1, y, rows, cols, map) + \
//			GetCount(key, x, y - 1, rows, cols, map) + \
//			GetCount(key, x, y + 1, rows, cols, map);
//	}
//	int AddSum(int x)
//	{
//		int sum = 0;
//		while (x)
//		{
//			sum += x % 10;
//			x = x / 10;
//		}
//		return sum;
//	}
//};
//
//int main() {
//	Solution A;
//	Solution2 B;
//	cout << A.movingCount(5, 4, 4) << endl;
//	cout << B.movingCount(5, 4, 4) << endl;
//}



//#include<string>
//int main() {
//	string s = "123";
//	int n = atoi(s.c_str());
//}
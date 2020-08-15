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
//#include"LinkList.h"
//#include<stack>
//#include<algorithm>
//using namespace std;

//int main() {
//	string str = { "ABcdE123" };
//	transform(str.begin(), str.end(), str.begin(), ::tolower);
//	cout << str;
//
//	cout << endl;
//	vector<int> v = { 1,2,1,2,3 };
//	sort(v.begin(), v.end());
//	v.erase(unique(v.begin(), v.end()), v.end());
//	for (int i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//}
//int main() {   //华为机试3.随机数
//	string s;
//	s.clear();
//	s = "abcdefgh";
//	s = s.substr(3);
//	cout << s << endl;
//	vector<int> v = { 1,2,1,2,3 };
//	int n;
//	cin >> n;
//	int N;
//	while (cin >> N)
//		v.push_back(N);
//	sort(v.begin(), v.end());
//	v.erase(unique(v.begin(), v.end()), v.end());
//	for (int i = 0; i < v.size(); ++i)
//		cout << v[i] << endl;
//	return 0;
//}



//int main() {   //华为机试5.进制转换
//	string s;
//	while (cin >> s) {
//		int n = 0;
//		for (int i = 2; i < s.size(); ++i) {
//			if (s[i] >= '0' && s[i] <= '9') {
//				n = n + (s[i] - '0') * 16;
//			}
//			else
//				n = n + (s[i] - 55) * 16;
//		}
//		cout << to_string(n) << endl;
//	}
//}



//int main() {
//	float f = 5.5;
//	int a = int(f);
//	cout << a << endl;
//}



//int main() {   //9.提取不重复的数
//	//int n;
//	//while (cin >> n) {
//	//	string s = to_string(n);
//	//	sort(s.begin(), s.end());
//	//	s.erase(unique(s.begin(), s.end()), s.end());
//	//	reverse(s.begin(), s.end());
//	//	cout << s << endl;
//	//}
//
//	vector<int> v = { 1,2,3,4,5 };
//	v.push_back(6);
//	v.pop_back();
//	cout << v[5] << endl;
//}



//void helper(string s, int& x, int& y) {   //华为机试17.坐标移动
//	if (s.empty()) return;
//	if (s.size() > 3 || s.size() < 2) return;
//	if (s[0] != 'A'&&s[0] != 'S'&&s[0] != 'D'&&s[0] != 'W') return;
//	int n = 0;
//	if (s[1]<'0' || s[1]>'9') return;
//	n = (s[1] - '0') ;
//	if (s.size() == 3) {
//		if (s[2]<'0' || s[2]>'9') return;
//		n =n*10+ (s[2] - '0');
//	}
//	char c = s[0];
//	switch (c) {
//	case 'A': {x -= n; cout << "x:" << x << "  y:" << y << endl;  break; }
//	case 'S': {y -= n; cout << "x:" << x << "  y:" << y << endl;  break; }
//	case 'D': {x += n; cout << "x:" << x << "  y:" << y << endl;  break; }
//	case 'W': {y += n; cout << "x:" << x << "  y:" << y << endl;  break; }
//	}
//}
//void daan(string s)
//{
//	string str=s;
//	//while (cin >> str) {
//		pair<int, int> point(0, 0);               //point.first point.second
//		size_t found = str.find_first_of(';');  //找到第一个';'的位置
//		int start = 0;
//
//		while (found != string::npos) {
//			string s1 = str.substr(start, found - start);
//			//cout << s1 << endl;
//			start = found + 1;
//			found = str.find_first_of(';', found + 1);
//
//			if (s1.size() > 1 && s1.size() <= 3) {    //合法的字符个数：2或3
//				char c = s1[0];
//				int n = 0;
//				int invalid = 0;    //数字为是否非法
//				for (int i = 1; i < s1.size(); ++i) { //数字位判断与提取，A1A
//					if (s1[i] >= '0'&&s1[i] <= '9')
//						n = n * 10 + (s1[i] - '0');
//					else {
//						invalid = 1;
//						break;
//					}
//				}
//				if (invalid == 0) {
//					switch (c)
//					{
//					case 'A': {point.first -= n; break; }
//					case 'D': {point.first += n; break; }
//					case 'W': {point.second += n; break; }
//					case 'S': {point.second -= n; break; }
//					}
//				}
//
//			}
//		}
//		cout << point.first << ',' << point.second << endl;
//	
//}
//int main() {
//	int x = 0, y = 0;
//	//string s = { "A37; S1; S72; S41; W21; W32; A45; A98; D97; D69; W57; W11; S41; S0; S24; S83; A75; W77; S32; D18; A24; D20; A65; D95; S18; W56; A84; W30; S3; S50; D64; S84; D82; A86; A36; S85; S94; W64; W62; A12; W12; S84; W29; A52; A73; W55; W71; D43; D76; D49; W19; S56; W63; W56; A68; D68; D40; A48; W5; A12; S84; A2; S44; A93; D51; D64; S4; W32; W27; W15; W70; A47; S77; S88; A25; D51; D8; A34; A71; A5; D83; S36; S72; A34; D46; S29; S5; W57; W16; S42; A23; A30; D43; S0; W62; A34; D60; D31; W89; W91; S87; A15; S15; S18; W83; S82; W87; W73; D42; A92; D48; A65; D36; A11; W50; W38; W2; A0; D65; W29; D56; S64; D31; W8; A56; A45; A56; W54; A97; D97; A90; S72; A95; A89; S78; A35; A31; W68; W42; A73; S73; A24; S28; D69; W53; S54; D80; D27; W24; S86; A17; A36; A41; A1; D19; S53; S96; A31; A52; A63; A18; S54; A35; A82; W95; D8; W48; S75; W11; S9; W60; D68; A92; A96; W32; S30; D26; W61; S0; D10; S89; W31; D4; W37; S49; D79; S56; A87; S61; A61; D96; W86; S81; D50; S91; A68; A82; A36; A16; S6; W25; D76; D94; A20; A37; D91; S58; A54; S77; S27; A35; S6; A88; A14; S72; D12; A95; W93; W1; A73; A55; A13; S55; W43; W6; D37; W19; W79; W56; S26; A36; W85; A6; W94; A54; A12; S0; A13; D18; W14; A52; W44; D83; W17; W73; A72; D56; A63; S14; A64; A84; S54; D67; A92; D46; A51; D99; W42; W2;" };
//	//while (cin >> s) {
//	//	int l = 0, r = 0;
//	//	for (int i = 0; i < s.size(); ++i) {
//	//		if (s[i] == ';') {
//	//			r = i;
//	//			helper(s.substr(l, r - l), x, y);
//	//			l = r + 1;
//	//		}
//	//	};
//	//	cout << x << "," << y << endl;
//	//}
//
//	string s = { "W20;S68;D59;S48;A18;S0;W24;S48;W75;A39;W29;S28;W76;W78;D94;A57;A5;D51;S61;A39;W77;S70;A2;D8;S58;D51;S86;W30;A27;S62;D56;A51;D0;S58;W34;S39;A64;A68;A96;D37;S91;S16;A17;D35;A85;W88;S57;S61;A28;D12;A87;S39;A85;W22;D65;D72;A5;A78;A59;D75;D57;S66;A55;D84;D72;W87;S46;W64;D49;S46;W34;D60;S39;A30;W86;D20;W93;D25;W44;W86;A16;D4;A86;S86;S27;W7;W89;W93;S17;S39;W66;W72;D81;W93;A88;D46;S57;W45;S84;S57;D27;A11;D54;S8;W15;A50;A69;A4;D19;D69;A3;A28;D47;W18;A39;D47;W14;D77;W59;S84;A32;D56;S16;D99;A33;A51;A24;D65;W37;D98;A13;W6;D94;D28;A12;S18;W40;S23;W76;D6;S40;D26;W97;W7;W90;W75;S12;A89;S46;S36;D96;A49;A73;S53;D84;A87;D75;D48;W84;S14;W65;W79;W51;S9;S77;D51;S76;W16;W77;A90;S96;D78;S7;W71;D17;W10;W4;D96;S58;A88;S89;D41;W47;W13;S75;S85;W63;W87;S19;S80;W92;W95;W73;D43;D35;W60;S31;D72;A73;W90;S51;A55;S82;W81;S56;W83;W41;A77;S37;D63;A72;D44;W81;S26;S53;W32;A24;S90;S83;W34;D10;S53;D69;A87;W84;S32;D72;S63;D97;W27;D23;D25;D18;W86;D74;D42;A31;S1;D98;D76;S46;D67;W94;S6;S97;S40;W71;W12;D62;W57;A92;W59;W59;D15;A16;D21;S33;S45;S83;D89;W77;A93;S60;S6;W24;S93;D69;D79;S13;S8;W63;D99;S36;D35;W53;S5;S44;S19;D76;S14;A86;A86;W43;W65;D20;S19;W66;A54;A98;A17;D2;W98;W2;D77;A90;S8;S55;S67;W88;W19;S59;D9;S75;S56;W75;W54;A61;W47;S19;D67;S39;D55;S6;A89;A5;W58;W7;W88;W92;D85;S32;S32;A27;S42;D52;A55;S26;D27;W40;D76;A55;D38;W13;A71;D79;W59;A76;A33;A12;D1;D63;W63;W62;D7;W48;A84;D27;A80;D42;D27;D49;D4;D71;W90;W39;D24;W71;D16;S1;W88;W88;D25;D66;S39;S43;A99;A92;W19;W20;A90;A31;A6;A79;D4;D80;A77;D71;D36;S64; " };
//	int l = 0, r = 0;
//	for (int i = 0; i < s.size(); ++i) {
//		if (s[i] == ';') {
//			r = i;
//			helper(s.substr(l, r - l), x, y);
//			l = r + 1;
//		}
//	};
//	cout << x << "," << y << endl;
//	daan(s);
//}



//int main() {
//	int a[3] = { 1 };
//	for (int i = 0; i < 3; ++i) {
//		cout << a[i] << " ";
//	}
//	string s1 = "abcde";
//	string s2 = "bc";
//	if (s1.find(s2) != s1.end())
//		cout << 6 << endl;
//}



//bool match(int r, int i) {   //25.数据分类处理
//	string sr = to_string(r);
//	string si = to_string(i);
//	if (si.find(sr) != si.npos) return true;
//	else return false;
//}
//int main() {
//	int m, n;
//	while (cin >> m) {
//		vector<int> I, R;
//		int temp = 0;
//		while (cin >> temp)
//			I.push_back(temp);
//		cin >> n;
//		while (cin >> temp)
//			R.push_back(temp);
//
//		//按步骤生成ans
//		sort(R.begin(), R.end());
//		R.erase(unique(R.begin(), R.end()), R.end());
//		vector<vector<int>> ans;
//		for (int i = 0; i < R.size(); ++i) {
//			vector<int> v;
//			v.push_back(R[i]);
//			v.push_back(0);
//			for (int j = 0; j < I.size(); ++j) {
//				if (match(R[i], I[j])) {
//					v[1]++;
//					v.push_back(j);
//					v.push_back(I[j]);
//				}
//			}
//			if (v.size() == 2) continue;
//			ans.push_back(v);
//		}
//
//		//输出
//		int count = 0;
//		for (int i = 0; i < ans.size(); ++i) {
//			count = count + 1 + 2 * (ans[i][1]);
//		}
//		cout << count;
//		for (int i = 0; i < ans.size(); ++i)
//			for (int j = 0; j < ans[i].size(); ++j)
//				cout << ',' << ans[i][j];
//	}
//}



//#include<map>   //30.字符串合并处理
//const string ss = "abcedfABCEDF0123456789";
//const string sa = "5D37BF5D37BF084C2A6E19";
//int main() {
//	string s1, s2;
//	while (cin >> s1 >> s2) {
//		//cin>>s2;
//		//排序
//		s1 += s2;
//		string ss1, ss2;
//		for (int i = 0; i < s1.size(); ++i) {
//			if (i % 2 == 0)
//				ss1 += s1[i];
//			else
//				ss2 += s1[i];
//		}
//		sort(ss1.begin(), ss1.end());
//		sort(ss2.begin(), ss2.end());
//		cout << ss1 << endl << ss2 << endl;
//		for (int i = 0, j = 0, k = 0; i < s1.size(); ++i) {
//			if (i % 2 == 0) {
//				s1[i] = ss1[j];
//				cout << "j:" << j << "  " << ss1[j] << endl;
//				j++;
//			}
//			else {
//				s1[i] == ss2[k];
//				cout << "k:" << k << "  " << ss2[k] << endl;
//				k++;
//			}
//		}
//		cout << s1 << endl;
//
//		//转换
//		map<char, char> m;
//		for (int i = 0; i < ss.size(); ++i)
//			m[ss[i]] = sa[i];
//		for (int i = 0; i < s1.size(); ++i) {
//			if (m.find(s1[i]) != m.end())
//				s1[i] = m[s1[i]];
//		}
//		cout << s1 << endl;
//	}
//}



//int main() {   //31.中级单词倒排
//	string s;
//	while (getline(cin, s)) {
//		string t;
//		for (int i = 0; i < s.size(); ++i) {
//			if (!isalpha(s[i])) {
//				s[i] = ' ';
//				t += s[i];
//				while (i < s.size() - 1 && !isalpha(s[i + 1]))
//					i++;
//			}
//			else
//				t += s[i];
//		}
//		cout << t << endl;
//
//		reverse(t.begin(), t.end());
//		int l = 0, r = 0;
//		for (int i = 0; i < t.size(); ++i) {
//			if (t[i] == ' ') {
//				r = i;
//				reverse(t.begin() + l, t.begin() + r);
//				l = r + 1;
//			}
//		}
//		cout << t << endl;
//	}
//}



//void helper(char* str) {
//	string s = "abc";
//	str = &s[0];
//}
//int main() {
//	char* str;
//	string s = "def";
//	str = &s[0];
//	helper(str);
//	cout << *str << endl;
//
//	string s[2];
//}



//int main() {   //33.整数与IP地址间转换
//	string ip = "234.237.37.104";
//	unsigned int n[5] = { 0 };
//	unsigned int count = 0;
//	//cout << ip[0] - '0' << endl;
//	for (int i = 0; i < ip.size(); ++i) {
//		if (ip[i] == '.')
//			count++;
//		else
//			n[count] = n[count] * 10 + (ip[i] - '0');
//	}
//	for (int i = 0; i < 5; ++i)
//		cout << n[i] << " ";
//	n[4] = (n[0] << 24) + (n[1] << 16) + (n[2] << 8) + n[3];
//	cout << n[4] << endl;
//}



//int main() {   //35.蛇形矩阵
//	int n;
//	while (cin >> n) {
//		vector<vector<int>> ans(n, { 0 });
//		ans[0][0] = 1;
//
//		//生成第一列
//		int addnum = 1;
//		for (int i = 1; i < n; ++i) {
//			ans[i][0] = ans[i - 1][0] + addnum;
//			addnum++;
//		}
//
//		//生成剩余数字
//		addnum = 2;
//		int count = n;
//		for (int i = 0; i < n; ++i) {
//			int temp = addnum;
//			//count--;
//			for (int j = 1; j < count; ++j) {
//				ans[i].push_back(ans[i][j - 1] + addnum);
//				addnum++;
//			}
//			addnum = temp+1;
//			count--;
//		}
//
//		for (int i = 0; i < ans.size(); ++i) {
//			for (int j = 0; j < ans[i].size(); ++j) {
//				cout << ans[i][j] << ' ';
//			}
//			cout << endl;
//		}
//	}
//}



//#include<map>
//int main() {   //36.字符串加密
//	string s;
//	while (cin >> s) {
//		string t;
//		cin >> t;
//		string p = "abcdefghijklmnopqrstuvwxyz";
//		string q;
//		string s1 = s;
//		for (int i = 0; i < s1.size(); ++i) {
//			s1[i] = tolower(s1[i]);
//			if (q.find(s1[i]) == s1.npos)
//				q += s1[i];
//		}
//		for (int i = 0; i < p.size(); ++i) {
//			if (q.find(p[i]) == p.npos)
//				q += p[i];
//		}
//		cout << q << endl;
//
//		map<char, char> m;
//		for (int i = 0; i < p.size(); ++i)
//			m[p[i]] = q[i];
//
//		//加密
//		string ans;
//		for (int i = 0; i < t.size(); ++i) {
//			if (t[i] >= 'A'&&t[i] <= 'Z') {
//				char c = tolower(t[i]);
//				ans += m[c];
//			}
//			else
//				ans += m[t[i]];
//		}
//		cout << ans << endl;
//	}
//}



//int main() {   //45.名字的漂亮度
//	//int n;
//	//cin >> n;
//
//	int n = 2;
//	vector<string> vv(n);
//	vector<int> ans(n, 0);
//	//for (int i = 0; i < vv.size(); ++i)
//	//	cin >> vv[i];
//	vv[0] = "lcfynwnkcttqmmuicxjofgqnsdyymktpvmgevfspnnjlcphdgmzizzubhfmqnnsmbfvvspmhhukxlfmsrolfmobyfdbhdgzvktjvptjhxchntcdmumxyqalhnelsspnwayszauakstpgkbjjiospjszahxyixvkmtukqgrsrufirtslysjbhjzreverdfggnlniojtndpyoflqgsnsihjqrlwxbqsziurivumalolhsisdvkphpsctcntiuvzcrzuxeenbizwhqhlzqindrtlraqslytozoeloavgidtofshyzchgtqxsmcpoqvyvzaunapgfkqusldlgugyqfckrjzdrhqabdwrihbmfszcwgtjpldwmclivucigrpsatnmnjbruivgderdsmvqxmackqapoogzeuecwgyrvqmdyuscugwhvtrewnvxqjstvhldwgauteggfqmhnbubladbltfppxefjhcckfepybsetmrfokovuqolqrfjlpwpzizbacraprigcwlsgavbroggxyqlgzcejeftosizozwxtppjtzakqoyfxsgvlmcnkinvgntmuxdoujmtjnqoaxqzhmpvjuborilapgmcgkbunshbbqpjnoescmwoyeyhdaishaqlgvceytmdbkdwpjsonswkwkgecwcdmlsfgipxutkgmktboqbluffkbqfkhqbqadhsaeilfyvbiumkekivesdrpradoeoodgvmwjtqthswngopyvsdhmkybpkxcwsfwjsxcqijvyzhzdglswjbxyuhxrkciurkpsriljgzmemhzzkjpdtkpdndrcrqlxalnxsmwxuijxnkphmvgqgodfcfapqercwmfzeiublwjbhvakumwxiowomslmskthndblpcysufdmxrwktfjseiubkydmnweszodezmwokwalfmpgemnsxrpimomzectpqtketkojtxsavuhjmihwijuepjpytatybkzvnmkyakvkityrjbbjipnlhsdfvzhjhavsupvrdkdchrjvudjhtcedgzvtphabitivwzroakwxprfjjszidyzhnryfxjiuolwxyjkkmrajdcutvxofnpuxefsigsrdieaqdnyhebpsuwmgpfkhjxkcczbdticpdxxezmtpygklgruenftcdjnodzeayajhtusbmafrfethglzqzgwtwevaqdsxydcfvnfweqtrdkwweeyvtruxnihulyvqjgnurmbnseepobowaeywhktiomctuugjvykmmjjxdbydxwjjedwttxbzttxqhmkeuiqiwgahsegrxlmjagaekdqfpjxjjatwsfgcpqgjbpuiilvmgedevaasjvecqxhrqvwzfsrhrekdwcpgbqbfpdkueaopwmkxojkktsddbvnkzhsmppmzjbrrohqtvfsvatlybqgufgajcronrobiwkgrrzavkhhuqpdfeyorloqfragubpqtyodztnbzikqzqjwcrptsrmqizymkaxmmedsfzxxhbchhjkysvhfjjhensslbfezdbezwdlgrzjdqlmnnqlpafhqllvhjoecuklvndxmxmrwgezflzfegirwhxlvzafjvjzwpicpemqzjcxtydaxsjszykzdwgiwixruhcjpfaielqfcmtfrklzridtcdgqegtvohubqqjmjshdvdbcixbgzwxlrclnjahqwqciqtgkecbpaehwyjyphcyekikgu ";
//	vv[1] = "wqieoyctanxxubqajvuuylggeozeihdvuzpkmimizpmhxuvrivhjxktvzqkzhrazgzddbtyadzsmeztgssbvvbcjntoovwgppgefinjvtozmmgfgytaoqeixqaxnsrkfdskztoaqapqucjfuseighwecxdbhfeggeztblcufyjqtelxlmzhvvhlnwmtftaltfzbwmssjthaturgkzjqucapimlrpynxaziiyluqcghblgpfuifglztlxpypcfrockkpwfhbuegprvqdyeuefvjyksvrclgdjoxsojedwbkpmkidnsvtytlmavutbetujpbvsxyqffucgmetsunbarbmtfqzakblimdmqhjfstertnlgkqyxqfdshjitptvlkryuppjbanrcfwisquogjowjdakgtswoubvmbrychjlbwoeepyadhtrkadungtzgijbpbkjqcdartpuqproecbzziqvtahqisbfuoyhdtefbsopmsinmcdnswrugcloayjudayjldysxnqpgqrwvimiiojsbhlfyuerthujqiuvgejseklfjbbfhzyzexulwhzmpdyplkophfhscakdccvrvcrwkwhtrhapyigqyjcamwmgomoeoblpceupzcinbiclzivvlbdtvunxyjqzmvcmfagfnqngjbuwfgbqzdmwowdnttfgyseouxtinbgfzjsjrzpgxdhhnffuervkkylahzoibsanreovnxwvuzcarnetoxbwawxvjbxroytcanfzdnwoblmtdbpugaglipzfgvbccewnyluhstgiejdkuifksaoxtylbscsbqtoriaizxciwxtzznragbmntgmptbitsldqybgckkopdituvhlwgfmbjqfmjmtbwrkruukniuwkauinlejeeoqlxzjfvxiwqrmzkbzocjhgxnfbkhxjcirsyjvwclxqhrskvwpahhgjwnjlkpzozdxupzgbymxsfuspblaskerisrcjoqwjoscrcuervpdrqggnhxctjvmvcmhlnhayjsycxsbnnxqxarsqeefnehcfkxghiggspjwnseprulhqggxyibmdrovkqftummwierdfliturxxwveulxfudbrvfuiqtvnxuiceplcynmnvtfwosarbdrdnfpsysnqnhgzfamxtiozdsgntiuomxmmltqxjsxrgdqjmgqzofnuuxxjffvcfmzvdcwjbatxksbwbcgoxdyxsxeqguayyhwiqcqgwzmwbmzazxwedbohsbhryvcgdeqfmcbrpyzzcjmapdranonkknaozwcgqzcihcqbmifnpthkcxnflyfqnvwitcrfustxebobmayorvwudxidybirhghoiqvlrsaluvkcygdqdlqbdappljojetwtqsvwdxgofquflbklxznglaxhlbzshupkohnekngowwsdtlwtmwvptoznceuqvmpjlyxlamidjfsmhhyrwqyvvkowrwduocemgxwtemqkjsbuovogqqxrobbryerrxgfppbguyismaxhaurkqfasyokvcfysjmidpwmagvhrnthslzmzpqqfbcybexpebgyfwlecbdmsgkoweyguknibgkmxdflphtnafyvqprvpcxzcytjsbxurowrmzejunrhdubgprmpcbszvxrnnlpdhddplpnnqklysdqkgtpdaqxbrukarmpgnoadlywbsrvsdpjojirctsmklmgqjtaoaxuwpxibnvlqmcqeohmdsuinbhkntykqlxltdvduxeryrdrzexqqliklgulvzheacmspuugxpomagimaqnrsoqwomgvmbgvavdxzbzensgyvihupo";
//
//	int p = 0;
//	for (string i : vv) {
//		transform(i.begin(), i.end(), i.begin(), ::tolower);
//		int count[26] = { 0 };
//		for (char j : i)
//			count[j - 'a']++;
//		vector<int> v;
//		for (int j = 0; j < 26; ++j)
//			if (count[j] > 0)
//				v.push_back(count[j]);
//		sort(v.begin(), v.end());
//		reverse(v.begin(), v.end());
//
//		int num = 26;
//		for (auto j : v) {
//			ans[p] += num * j;
//			num--;
//		}
//		p++;
//	}
//	for (auto i : ans)
//		cout << i << endl;
//}
//int main() {   //45.名字的漂亮度
//	int n;
//	cin >> n;
//	vector<string> vv(n);
//	vector<int> ans(n, 0);
//	for (auto& i : vv)
//		cin >> i;
//
//	int p = 0;
//	for (string i : vv) {
//		transform(i.begin(), i.end(), i.begin(), ::tolower);
//		int count[26] = { 0 };
//		for (char j : i)
//			count[j - 'a']++;
//		vector<int> v;
//		for (int j = 0; j < 26; ++j)
//			if (count[j] > 0)
//				v.push_back(count[j]);
//		sort(v.begin(), v.end());
//		reverse(v.begin(), v.end());
//
//		int num = 26;
//		for (auto j : v) {
//			ans[p] += num * j;
//			num--;
//		}
//		p++;
//	}
//	for (auto i : ans)
//		cout << i << endl;
//}



//#include<iostream>   //49.多线程
//#include<mutex>
//#include<condition_variable>
//#include<string>
//#include<thread>
//using namespace std;
//string res("");
//mutex mtx;
//bool done = false;
//condition_variable A, B, C, D;
//void fun_A(int times) {
//	while (times--) {
//		unique_lock<mutex> locker(mtx);
//		A.wait(locker);
//		res += 'A';
//		B.notify_one();
//	}
//	done = true;
//}
//void fun_B() {
//	while (!done) {
//		unique_lock<mutex> locker(mtx);
//		B.wait(locker);
//		res += 'B';
//		C.notify_one();
//	}
//}
//void fun_C() {
//	while (!done) {
//		unique_lock<mutex> locker(mtx);
//		C.wait(locker);
//		res += 'C';
//		D.notify_one();
//	}
//}
//void fun_D() {
//	while (!done) {
//		unique_lock<mutex> locker(mtx);
//		D.wait(locker);
//		res += 'D';
//		A.notify_one();
//	}
//}
//int main() {
//	int num;
//	while (cin >> num) {
//		res = "";
//		thread t1(fun_A, num);
//		thread t2(fun_B);
//		thread t3(fun_C);
//		thread t4(fun_D);
//		A.notify_one();
//		t1.join();
//		t2.join();
//		t3.join();
//		t4.join();
//		cout << res << endl;
//		done = false;
//	}
//	return 0;
//}



//#include<iostream>   //52
//#include<string>
//using namespace std;
//
//int main() {
//	string s1;
//	while (cin >> s1) {
//		string s2;
//		cin >> s2;
//		string sh, lo;
//		if (s1.size() <= s2.size()) {
//			sh = s1;
//			lo = s2;
//		}
//		else {
//			sh = s2;
//			lo = s1;
//		}
//
//		int l = 0, r = 0;
//		int maxlen = 1;
//		int count = sh.size() - maxlen;
//		for (int i = 0; i < count; ++i) {
//			for (int j = i + 1; j < sh.size(); ++j) {
//				if (lo.find(sh.substr(i, j - i + 1)) != lo.npos)
//					if (j - i + 1 > maxlen)
//						maxlen = j - i + 1;
//			}
//			count = sh.size() - maxlen;
//		}
//
//		int ans = lo.size() - sh.size();
//		ans = ans + sh.size() - maxlen;
//		cout << ans << endl;
//	}
//}



//#include<iostream>   //57
//#include<string>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	string s1, s2;
//	while (cin >> s1 >> s2) {
//		string ans;
//		int carry = 0;
//		int i = s1.size() - 1, j = s2.size() - 1;
//		for (; i >= 0 && j >= 0; --i, --j) {
//			int m = (s1[i] - '0') + (s2[j] - '0') + carry;
//			carry = m / 10;
//			ans += to_string(m);
//		}
//		cout << i << "   " << j << endl;
//
//		while (i >= 0) {
//			ans += to_string(s1[i] - '0' + carry);
//			i--;
//			carry = 0;
//		}
//
//		while (j >= 0) {
//			ans += to_string(s2[j] - '0' + carry);
//			j--;
//			carry = 0;
//		}
//		reverse(ans.begin(), ans.end());
//		cout << ans << endl;
//	}
//}



//class Solution {
//public:
//	string multiply(string num1, string num2) {
//		if (num1.size() == 1)
//			if (num1[0] == '0')
//				return "0";
//		if (num2.size() == 1)
//			if (num2[0] == '0')
//				return "0";
//
//		int m = num1.size(), n = num2.size();
//		vector<int> pos(m + n, 0);
//
//		for (int i = m - 1; i >= 0; i--)
//			for (int j = n - 1; j >= 0; j--) {
//				int mul = (num1[i] - '0')*(num2[j] - '0');
//				int p1 = i + j, p2 = i + j + 1;
//				int sum = mul + pos[p2];
//
//				pos[p1] += (sum / 10);
//				pos[p2] = sum % 10;
//			}
//
//		bool flag = false;
//		string ans;
//		for (int& i : pos) {
//			if (i != 0 || flag == true) {
//				cout << flag << endl;
//				ans += to_string(i);
//				flag == true;
//				
//			}
//		}
//
//		// for(int i=0;i<m+n;i++){
//		//     if(pos[i]!=0 || flag==true){
//		//         ans+=to_string(pos[i]);
//		//         flag=true;
//		//     }
//		// }
//
//		return ans;
//	}
//};
//int main() {
//	Solution A;
//	string a = "123", b = "456";
//	cout << A.multiply(a, b) << endl;
//}



//class A {
//	A();
//	~A();
//public:
//	int a;
//protected:
//	int b;
//private:
//	int c;
//};
//class B :public A {
//public:
//	void fun1() {
//		b = 3;
//		a = 1;
//		
//	}
//};



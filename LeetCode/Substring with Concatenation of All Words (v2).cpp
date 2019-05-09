#include<iostream>
#include<memory>
#include<string>
#include <vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

template <typename T>
ostream& operator<<(ostream &os, const vector<T> &vec) {
	for (auto ele : vec)
		os << ele << " ";
	return os;
}

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> rst;
		unordered_map<string, int> wordCount;
		for (auto word : words)
			++wordCount[word];
		if (words.empty())
			return rst;
		int lenStr = s.size(), lenWord = words[0].size(), num_words = words.size();
		for (int i = 0; i < lenStr - lenWord*num_words+1; ++i) {
			unordered_map<string, int> wordSeen;
			int j = 0;
			while (j < num_words) {
				string w = s.substr(i + lenWord * j, lenWord);
				++wordSeen[w];
				if (wordSeen[w] > wordCount[w])
					break;
				++j;
			}
			if (j == num_words)
				rst.push_back(i);
		}

		return rst;
	}
};

int main(void)
{
	Solution solu;
	string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
	vector<string> words({ "fooo", "barr", "wing", "ding", "wing" });
	vector<int> rst;
	cout << s << endl << words << endl;
	rst = solu.findSubstring(s, words);
	for (auto ele : rst)
		cout << ele << " ";
	cout << endl;

	system("pause");
	return 0;
}

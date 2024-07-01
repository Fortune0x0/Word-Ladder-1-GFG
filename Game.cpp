#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <fstream>
#include <string>
#include <set>'
#include <unordered_set>
using namespace std;

class Solution {
public:
	int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
		map<string, int> graph;

		queue<string>q;
		q.push(startWord );
		int vec_size = wordList.size();

		map<string, bool> vis;


		

		for (int i = 0; i < vec_size; ++i) {
			vis[wordList[i]] = false;
			graph[wordList[i]] = 1e9;
		}
		graph[startWord] = 1, vis[startWord] = false;
		graph[targetWord] = 1e9, vis[targetWord] = false;
		
		while (!q.empty()) {
			string word = q.front();
			int u_dist = graph[word];

			vis[word] = true;
			q.pop();
			for (auto a : wordList) {
				if (!vis[a]) {
					int counter = 0;
					for (char& b : a) {
						int index = &b - &a[0];
						if (word[index] != b) {
							counter++;
						}
					}
					if (counter == 1) {
						int v_dist = graph[a];
						if (a == targetWord) {
							return u_dist + 1;
						}
						if (u_dist + 1 < v_dist) {
							graph[a] = u_dist + 1;
							q.push(a);

						}


					}
				}
				
			}

		}
		
		return 0;
	}
};


int main() {
	Solution solu;
	vector<string> wordList_2 = { "soon", "poon", "plee", "same", "poie", "plea", "plie", "poin"};
	vector<string> wordList = { "poon", "plee", "same", "poie","plea","plie","poin" };
	int ans = solu.wordLadderLength("toon", "plea", wordList_2);
	cout << ans << endl;
	
	
	
}
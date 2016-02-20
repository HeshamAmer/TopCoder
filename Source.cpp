//https://www.hackerrank.com/challenges/even-tree 
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <bitset>
#include <numeric>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include<stdio.h>

typedef long long ll;
using namespace std;
vector<vector<int>> G(101);
vector<int> parentNode(101);
vector<int> childCounter(101);

bool visited[101];

int findForest(int x){
//	cout << x << endl;
	if (visited[x])
		return 0;
	for (int i = 0; i < G[x].size(); i++){
		
		childCounter[x] += findForest(G[x][i]);
		visited[G[x][i]] = true;
	}
	return childCounter[x];
}
int main(){
	ifstream cin("in.txt");
	int N, M,x,y,res=0;
	
	cin >> N >> M;
	fill(childCounter.begin(), childCounter.end(), 1);
	for (int i = 0; i < N; i++){
		cin >> x >> y;
//		G[x].push_back(y);
		G[y].push_back(x);
		parentNode[x] = y;
	}
	findForest(1);
	for (int i = 0; i < childCounter.size(); i++)
		if (childCounter[i] % 2 == 0)
			res++;
	cout << res-1<<endl;
	return 0;

}
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

using namespace std;
#define MAX 100000000
int H,W;
vector<string> Map;
int dp[101][101][101];
int DP(int i,int j,int x){
	int val=0;
	int y=i+j-x;
	if (i<0||j<0||x<0||y<0) return -MAX;
	if(dp[i][j][x]!=-1) {
		return dp[i][j][x];
	}
	if (i==0&&j==0){//base case
		if (Map[i][j]=='#') {
			dp[i][j][x]=-MAX;
			return dp[i][j][x];
		}
		else if (Map[i][j]=='*') return 1;
		else return 0;
	}

	if (Map[i][j]=='*') val++;
	if (Map[x][y]=='*') val++;	
	if (i==x&&j==y&& Map[i][j]=='*') val=1;
	if (Map[i][j]=='#' || Map[x][y]=='#') {
		dp[i][j][x]= -MAX; return dp[i][j][x];	
	}

	
	dp[i][j][x]=max(max(max(DP(i-1,j,x-1),DP(i,j-1,x)),max(DP(i-1,j,x),DP(i,j-1,x-1)))+val,dp[i][j][x]);
	return dp[i][j][x];
	
}

int main(){
	ifstream cin ("in.txt");
	int N;
	string x;
	cin>>N;
	for (int id=0;id<N;id++){
		cin>>W>>H;
		memset(dp,-1,sizeof(dp));
		Map.clear();	
		for (int i=0;i<H;i++){
			if (i==0)
				getline(cin,x);
			getline(cin,x);
			Map.push_back(x);
		}
		cout<<DP(H-1,W-1,H-1)<<endl;
	}
	return 0;
}


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
using namespace std;
#define MAX 999999;
vector<int> V;
int Sum(int i,int j){
	int rs=0;
	
	for (;i<=j;i++){
		rs=(rs+V[i])%100;
//		printf("Rs=%d\n",rs);
	}
	return rs;
}
int res=MAX;
int dp[101][101];
int DP(int i,int j){
	 
	int x,y,z,t;
	if (j==i) return 0;
	if (dp[i][j]!=-1)return dp[i][j];
	dp[i][j]=MAX;
	for (int k=i;k<j;k++){
		x=DP(i,k);
		y=DP(k+1,j);
		z=Sum(i,k);
		t=Sum(k+1,j);
		dp[i][j]=min((x+y)+(z*t),dp[i][j]);
		//printf("x=%d,y=%d,z=%d,t=%d,res=%d\n",x,y,z,t,dp[i][j]);
	}
	return dp[i][j];
}

int main(){

	
//	ifstream cin ("in.txt");
	int N,x;
	while (cin>>N){
		for (int i=0;i<101;i++) 
			for (int j=0;j<101;j++)
				dp[i][j]=-1;
		for (int i=0;i<N;i++){
			cin>>x;
			V.push_back(x);
			
		}
		res=MAX;
		cout<<DP(0,N-1)<<endl;
		V.clear();
	}

	return 0;
}


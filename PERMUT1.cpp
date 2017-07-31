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
typedef long long ll;
using namespace std;


int n,K,res;
int dp[13][100];

int perms(int x,int k){

	//F(N,K) +=FN(n-1,k-r) for all r from 0 to n-1;
	if (dp[x][k]!=-1) return dp[x][k];
	if (x<=0) 
	{
		if (k==0)
			return 1;
		else return 0;
	}
	if (k<0) return 0;
	dp[x][k]=0;
	for (int r=0;r<x;r++)
	{
		printf("calling %d-1,k=%d,r=%d,k-r=%d\n",x,k,r,k-r);
		dp[x][k]+= perms(x-1,k-r);
	}
	return dp[x][k];

}
int main(){
	ifstream cin ("in.txt");
	int d;
	cin>>d;
	for (int i=0;i<d;i++){		
		memset(dp,0,sizeof(dp));
		cin>>n>>K;	
		dp[0][0]=1;
	//	dp[0][K]=1;
		for (int x=0;x<=n;x++){		
			for (int k=0;k<=K;k++){
				for (int r=0;r<x;r++)
				{				
					if (k-r>=0 && x>0)
					{
					//	printf("x-1=%d,k-r=%d\n",x-1,k-r);
						dp[x][k]+=dp[x-1][k-r];
				//		printf("dp[%d][%d]=%d\n",x,k,dp[x][k]);
					}
				}
			}
		}
		cout<<dp[n][K]<<endl;
	//	memset(dp,-1,sizeof(dp));
	//	cout<<perms(n,K);
		}
	return 0;
}


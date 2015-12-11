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
#define MAX 30001	
const int COINS=11;
int coins[COINS]={5,10,20,50,100,200,500,1000,2000,5000,10000};
long long dp[41][41];
vector<int> V;
int KS(int brks,int idx){
	if (idx<0 ||brks<0) return 0;
	if (dp[brks][idx]!=-1) 
		return dp[brks][idx];
	dp[brks][idx]=0;
	if (idx<=0 && brks==0)
		{
			return 1;
	}
	if (idx<=0 ||brks<0) return 0;

	if (count(V.begin(),V.end(),idx)==0)
		dp[brks][idx] += KS(brks-1,idx-1) + KS(brks+1,idx-1);
	else 
		dp[brks][idx] += KS(brks-1,idx-1);

	return dp[brks][idx];
}


int main(){
	ifstream cin ("in.txt");
	int d,n,k,x;
	
	cin>>d;
	for (int i=0;i<d;i++){
		cin>>n>>k;
		V.clear();
		memset(dp,-1,sizeof(dp));
		for (int j=0;j<k;j++){
			cin>>x;
			V.push_back(x);
		}
		if (count(V.begin(),V.end(),2*n)!=0)
			cout<<0<<endl;
		else 
			cout<<KS(0,2*n)<<endl;
	}

	
	return 0;
}


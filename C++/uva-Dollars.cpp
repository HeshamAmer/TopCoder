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
#define ll long long
using namespace std;
#define MAX 30001
const int COINS=11;
int coins[COINS]={5,10,20,50,100,200,500,1000,2000,5000,10000};
long long dp[MAX][COINS];
ll KS(ll Sum,int idx){
	if (dp[Sum][idx]!=-1) return dp[Sum][idx];
		dp[Sum][idx]=0;
	if (Sum==0) return 1;
	if (idx==COINS	|| Sum <coins[idx] ) 	return 0;
	if (Sum-coins[idx]>=0){
		dp[Sum][idx]+=KS(Sum-coins[idx],idx);	
	}
	dp[Sum][idx]+=KS(Sum,idx +1 );
	return dp[Sum][idx];
}
int main(){
	//ifstream cin ("in.txt");
	string y;
	while(cin>>y){
		int x;
		string z="";
		for (int i=0;i<y.length();i++){
			if (y[i]!='.')
				z+=y[i];
		}
		x=atoi(z.c_str());
		if (x==0) return 0;
		memset(dp,-1,sizeof(dp));
	
		for (int j=0;j<6-y.size();j++){
			cout<<" ";
		}
		cout<<y;
		ll res=KS(x,0);
		string t=to_string(res);
	
		for (int j=0;j<17-t.size();j++){
			cout<<" ";
		}
		cout<<t<<endl;
		//cout<<y<<"  "<<res<<endl;
		
	}
	
	return 0;
}


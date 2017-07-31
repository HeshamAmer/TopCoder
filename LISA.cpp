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
#define MAX 999999
vector<long long> V;
vector<char> oper;
long long dp[101][101];
long long tp[101][101];


int STI ( string Text )//Text not by const reference so that the function can be used with a 
{                               //character array as argument
	stringstream ss(Text);
	int result;
	return ss >> result ? result : 0;
}
string x;

long long LastOper(long long i,long long j,long long k){
	//printf("doing %d and %d with operator idx=%d\n",i,j,k);
	if (oper[k]=='*')
		return i*j;
	else return i+j;
}

long long DP(long long i,long long j){

	if (j<=i) return V[i];
	if (dp[i][j]!=-1){ //printf("got Memoized %d %d\n",i,j);
		return dp[i][j];
	}
	dp[i][j]=0;
	for (int k=i;k<j;k++){
		dp[i][j]=max(LastOper(DP(i,k),DP(k+1,j),k) ,dp[i][j]);
		//printf("Dp[%d][%d] returned\n",i,j);
	}
	return dp[i][j];
}


long long TP(long long i,long long j){

	if (j<=i) return V[i];
	if (tp[i][j]!=MAX){ 
		//printf("TP got Memoized %d %d\n",i,j);
		return tp[i][j];
	}
	tp[i][j]=MAX;
	for (int k=i;k<j;k++){
		tp[i][j]=min(LastOper(TP(i,k),TP(k+1,j),k) ,tp[i][j]);
		//printf("tp[%d][%d] returned\n",i,j);
	}
	return tp[i][j];
}

int main(){


	ifstream cin ("in.txt");
	int N;
	cin>>N;
	getline(cin,x);
		for (int i=0;i<N;i++){
			for (int i=0;i<101;i++){
				for (int j=0;j<101;j++){
					dp[i][j]=-1;
					tp[i][j]=MAX;
				}
			}
			getline(cin,x);
			int j=0;
			for(int k=0;k<x.length();){
				string S="";
				if (x[k]=='*' || x[k]=='+' )
				{
					oper.push_back(x[k++]);
				}
				else 
				{
					while (k<x.length()&&x[k]!='*'&&x[k]!='+')
						S+=x[k++];
					V.push_back(atoi(S.c_str()));
				}
			}
			cout<<DP(0,V.size()-1)<<" "<<TP(0,V.size()-1)<<endl;
			V.clear();
			oper.clear();
		}
	return 0;
}


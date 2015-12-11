#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
vector <int> V;
vector <int> W;
int N,S;
//This is a top-down approach
int memo[2001][2001];
int KnapSack(int idx,int w){
	//printf("I = %d, J=%d\n",i,j);
	if (idx==N)
		return 0;
	if (memo[idx][w]!=0){
		return memo[idx][w];
	}
    int choice1=0;
    if (W[idx]<=w){
        choice1=KnapSack(idx+1,w-W[idx])+V[idx];
	}
    int choice2=KnapSack(idx+1,w);
	memo[idx][w]=max(choice1,choice2);    
	return memo[idx][w];
}

int main(){
	int a,b;
//ifstream cin ("in.txt");
	cin>>S>>N;
	for (int i=0;i<N;i++){
		cin>>a>>b;
		W.push_back(a);
		V.push_back(b);
	}
	int res=KnapSack(0,S);
	cout<<res<<endl;
	return 0;
}


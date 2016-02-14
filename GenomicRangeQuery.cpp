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
 

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++11
	vector<int> genom;
	vector<int> V;
	vector<int> A,C,G,T;
	for (int i=0;i<S.size();i++){
		switch (S[i]){
		case 'A':
			genom.push_back(1);
			break;
		case 'C':
			genom.push_back(2);
			break;
		case 'G':
			genom.push_back(3);
			break;
		case 'T':
			genom.push_back(4);
			break;
		}

	}
	A.push_back(0);
	C.push_back(0);
	G.push_back(0);
	T.push_back(0);
	for (int i=0;i<genom.size();i++){
		int a=0,c=0,g=0,t=0;
		if (genom[i]==1)
			a=1;			
		if (genom[i]==2)
			c=1;			
		if (genom[i]==3)
			g=1;
		if (genom[i]==4)
			t=1;
		A.push_back(A[i]+a);
		C.push_back(C[i]+c);
		G.push_back(G[i]+g);
		T.push_back(T[i]+t);
		
	}
		for (int i=0;i<P.size();i++){
			if (A[Q[i]+1]-A[P[i]]>0)
				V.push_back(1);
			else if (C[Q[i]+1]-C[P[i]]>0)
				V.push_back(2);
			else if (G[Q[i]+1]-G[P[i]]>0)
				V.push_back(3);
			else 
				V.push_back(4);
		}

	return V;
}
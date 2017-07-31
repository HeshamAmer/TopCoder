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
//max (0.3x, (1 - m/250)x - 50w);

int solution(vector<int> &A) {
	// write your code in C++11
	vector<int> V;
	ll res = 0;
	for (int i = 0; i < A.size(); i++){
		for (int j = i+1; j < A.size(); j++){
			ll x = j - i - A[i] - A[j];
			if (x<=0){
				res++;
		}
	}
		


	}
	return res;
}

int main(){
	//	ifstream cin("in.txt");
	int a[] = { 1,5,2,1,4,0};
	vector<int> V(begin(a), end(a));
	solution(V);

	return 0;
}

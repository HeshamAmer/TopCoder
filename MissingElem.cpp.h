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
	map <ll, ll> M;
	ll res = 0;
	M[0] = 1;
	for (int i = 0; i < A.size(); i++){
		M[A[i]] = 1;
	}
	for (int i = 0; i < M.size(); i++){
		if (!M.count(i)){
			res = i;
			break;
		}
	}
	if (res == 0){
		res = M.size();
	}
	cout << res;
	return res;
}

int main(){
	//	ifstream cin("in.txt");
	//int a[] = { 1,3,6,4,1,2 };
	ll a[] = { -2147483648LL };
	vector<int> V(begin(a), end(a));
	solution(V);

	return 0;
}

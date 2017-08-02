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
	sort(A.begin(), A.end());
	int res = 0;
	for (int i = 2; i < A.size(); i++){
		ll T = A[i - 1] + A[i - 2];
		ll K = A[i];
		if (K < T)
			res = 1;

	}
	return res;
}

int main(){
	//	ifstream cin("in.txt");
	int a[] = { 0,1,0,1,1,1,0,1};
	vector<int> V(begin(a), end(a));
	solution(V);

	return 0;
}

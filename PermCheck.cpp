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
	vector<int> V(A.size()+10);
	map<ll, ll> M;
	ll target = 0, tmp=0,res = 0;
	for (int i = 1; i <= A.size(); i++) {
		target += i;
	}
	for (int i = 0; i < A.size(); i++){
		if (!M.count(A[i])){
			M[A[i]] = 1;
			tmp += A[i];
			if (tmp == target)
				res = 1;
		}

	}
	cout << res;
	return res;

}

int main(){
	//	ifstream cin("in.txt");
	int a[] = { 1,2 };
	vector<int> V(begin(a), end(a));
	solution(V);

	return 0;
}

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
	ll arrSum = 0;
	ll begin = 0;
	ll res = -1;
	int sum = 0;
	vector<ll> V;
	V.push_back(0);

	for (int i =1; i <= A.size(); i++) {
		arrSum += A[i-1];
		sum += A[i - 1];
		V.push_back(sum);
	}
	arrSum -= A[0];
	for (int i = 1; i < A.size(); i++){
		arrSum -= A[i];
		if (V[i] == arrSum){
			res = i;
			break;
		}
			
	}

	cout << res << endl;
	return res;

}

int main(){
//	ifstream cin("in.txt");
	int a[] = { -1, 3, -4, 5, 1, -6, 2, 1 };
	vector<int> V(begin(a),end(a));
	solution(V);

	return 0;
}

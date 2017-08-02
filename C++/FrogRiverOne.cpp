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

int solution(int X,vector<int> &A) {
	// write your code in C++11
	set <int> S;
	int tmp=-1,res = 0,target=0;

	vector<int> V(A.size());
	for (int i = 1; i <= X; i++){ target += i; }
	for (int i = 0; i < A.size(); i++){
		if (V[A[i]] == 0){
			res += A[i];
			V[A[i]] = 1;
			if (res == target)
				tmp = i;
		}

	}
	cout << tmp;
	return tmp;

}

int main(){
	//	ifstream cin("in.txt");
	int a[] = { 1};
	vector<int> V(begin(a), end(a));
	solution(5,V);

	return 0;
}

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
#include<stdio.h>

typedef long long ll;
using namespace std;
int main(){
	ifstream cin("in.txt");
	ll N,S,P,Q;
	cin >> N >> S >> P >> Q;
	vector<ll> V(N);
	set<ll> mySet;
	V[0] = S % 2147483648;
	mySet.insert(V[0]);
	for (int i = 1; i < N; i++){
		V[i] = (V[i - 1] * P + Q) % 2147483648;
		mySet.insert(V[i]);
	}
	cout << mySet.size() << endl;
	return 0;

}
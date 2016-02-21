//https://www.hackerrank.com/contests/booking-hack-a-holiday/challenges/happiness-score
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
vector<vector<int>> G(101);
vector<int> parentNode(101);
vector<int> childCounter(101);

bool visited[101];


bool isPrime(int number){

	if (number < 2) return false;
	if (number == 2) return true;
	if (number % 2 == 0) return false;
	for (int i = 3; (i*i) <= number; i += 2){
		if (number % i == 0) return false;
	}
	return true;

}
vector<int>V;
set<int> S;
int genCombinations(int num,int idx) {
	
	for (int i =idx; i < V.size(); i++){
		S.insert(genCombinations(num + V[i], i + 1));
		S.insert(genCombinations(num, i + 1));

	}
	return num;
}

int main(){
	ifstream cin("in.txt");
	int N, M, x, y, res = 0;
	bool primeArr[100001];
	memset(primeArr, 0, sizeof(primeArr));
	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> x;
		V.push_back(x);
	}
	genCombinations(0, 0);
	for (std::set<int>::iterator it = S.begin(); it != S.end(); ++it){
		if (isPrime(*it)){
			res++;
		}
	}
	cout << res << endl;
	return 0;
}
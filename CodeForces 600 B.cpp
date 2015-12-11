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


bool isnum(string S){
	for (int i = 0; i < S.size(); i++){
		if (!isdigit(S[i])){ 
			return false;
		}
	}
	return true;
}
/*
BinarySearch(A[0..N - 1], value, low, high) {
	// invariants: value > A[i] for all i < low
	value < A[i] for all i > high
		if (high < low)
			return not_found // value would be inserted at index "low"
			mid = (low + high) / 2
			if (A[mid] > value)
				return BinarySearch(A, value, low, mid - 1)
			else if (A[mid] < value)
			return BinarySearch(A, value, mid + 1, high)
			else
			return mid
}
*/
vector<int> V;
int val;
int bin_search(int low,int high){
	if (high < low)
	{
		return low;
	}
	int mid = (low + high) / 2;
	if (V[mid] > val){
		return (bin_search( low, mid - 1));
	}
	else if (V[mid] < val)
		return bin_search( mid + 1, high);
	else
	{
		int x = V[mid];
		while (mid!=V.size() && V[mid] == x)
			mid++;
		return mid;	
	}

}
int main(){
	//ifstream cin("in.txt");
	int n, m,x;
	cin >> n >> m;
	vector<int> A, B;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		A.push_back(x);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		B.push_back(x);
	}
	sort(A.begin(), A.end());
	V = A;
	for (int i = 0; i < B.size(); i++){
		val = B[i];
		cout<<bin_search( 0, A.size()-1 )<<endl;
	//	cout << upper_bound(A.begin(), A.end(), B[i])-A.begin() <<" ";
	}
	cout << endl;
	
	return 0;
}
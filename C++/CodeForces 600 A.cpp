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

int main(){
//	ifstream cin("in.txt");
	string word, a="" , b;
	cin >> word;
	vector<string> A,B;
	for (int i = 0; i < word.size(); i++){
		
		if (word[i] == ';' || word[i] == ','){
			if (a.size()==0 ||(a[0] == '0' && a.size()!=1)|| !isnum(a)){
				B.push_back(a);
				a = "";
			}
			else
			{
				A.push_back(a);
				a = "";
			}
		}
		else {
			a += word[i];
		}
	}
	if (a.size() == 0 || (a[0] == '0' && a.size() != 1) || !isnum(a)){
		B.push_back(a);
		a = "";
	}
	else
	{
		A.push_back(a);
		a = "";
	}

	if (A.size() != 0){
		cout << "\"";
		for (int i = 0; i < A.size()-1; i++)
			cout << A[i] << ",";
		cout << A[A.size()-1]<<"\"\n";
	}
	else cout << "-" << endl;
	
	if (B.size() != 0){
		cout << "\"";
		for (int i = 0; i < B.size()-1; i++)
			cout << B[i] << ",";
		cout << B[B.size()-1]<<"\"\n";
	}
	else cout << "-" << endl;
	return 0;
}
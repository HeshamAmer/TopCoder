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
#include <bitset>
typedef long long ll;
using namespace std;



int main(){
	
	int y;
	cin >> y;
	bitset<32> x(y);
	bitset <32> T;
	for (int i = 31; i >=0 ; i--){
		if (x[i] == 1){ //start point
			T[i] = 0;
			for (; i >=0; i--){
				if (x[i] == 1)
					T[i] = 0;
				else T[i] = 1;
			}
			break;
		}
		
	}
	cout << T.to_ulong();

	return 0;
}
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


int maxDiff(vector<int> arr)
{
	int n = arr.size();
	int maxDiff = -1; // Initialize Result

	int maxRight = arr[n - 1]; // Initialize max element from right side

	for (int i = n - 2; i >= 0; i--)
	{
		if (arr[i] > maxRight)
			maxRight = arr[i];
		else
		{
			int diff = maxRight - arr[i];
			if (diff > maxDiff)
			{
				maxDiff = diff;
			}
		}
	}
	return maxDiff;
}
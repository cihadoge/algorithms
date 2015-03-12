#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define MAXN 51

using namespace std;


class NoRightTurnDiv2 {
public:
	int N;
	vector<int> corx, cory;

	int ccw(int a, int b, int c) {
		int x1 = corx[a], y1 = cory[a];
		int x2 = corx[b], y2 = cory[b];
		int x3 = corx[c], y3 = cory[c];
		
		int t1 = (x1 * y2 + x2 * y3 + x3 * y1);
		int t2 = (y1 * x2 + y2 * x3 + y3 * x1);
		return t1 - t2;
	}
	
	vector<int> startFrom(int a, int b) {
		vector<int> result;
		bool used[MAXN] = {0};
		used[a] = used[b] = true;
		result.push_back(a);
		result.push_back(b);

		int count = 2;
		while(count < N) {
			int temp = -1;
			double rightMost;
			for(int i = 0; i < N; i++) {
				if (!used[i] && ccw(result[count-2], result[count-1], i) > 0) {
					double ccwVal = ccw(result[count-2], result[count-1], i);
					if (temp== -1 || rightMost < ccwVal) {
						temp = i;
						rightMost = ccwVal;
					}
				}
			}
			if (temp == -1)
				break;
			result.push_back(temp);
			used[temp] = true;
			count++;
		}
		
		if(count == N)
			return result;
		// couldn't find solution
		result.clear();
		return result;
	}
	vector <int> findPath(vector <int> x, vector <int> y) {
		vector<int> result;
		corx = x;
		cory = y;
		N = x.size();
		for (int i=0;i<N;i++)
			for(int j=0;j<N;j++) 
				if( i != j)
				{
					result = startFrom(i, j);
					if(result.size() > 0)
						return result;
				}
		
		return result;
	}
};


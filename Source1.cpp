#include <iostream>
#include <exception>
#include <cstddef>
#include <stack>
#include <queue>
#include <vector>
#include "Class.h"
#include<set>
#include <algorithm>
using namespace std;
static vector<queue<int>>A;
int check(int ver)
{
	stack<int>opens;
	opens.push(ver);
	int ht = 0, hm = 0;
	while (!opens.empty())
	{
		if (A[opens.top()].empty())
		{
			if (ht > hm)hm = ht;
			opens.pop();
			ht--;
		}
		else
		{
			int v(A[opens.top()].front());
			A[opens.top()].pop();
			opens.push(v);
			ht++;
		}
	}
	return hm;
}

int main()
{
	vector<int>A1 = { -1,0,0,0,2,2,3,6,4,8 };
	A.resize(A1.size());
	for (int i=0;i<A1.size();i++)
	{
		if (A1[i] != -1)
		{
			A[A1[i]].push(i);
		}
		else
		{
			A.push_back(queue<int>());
			A.back().push(i);
		}
	}
	cout << check(A.back().front());
}
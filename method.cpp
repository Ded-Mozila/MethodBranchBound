#include "method.h"
BranchBound::BranchBound()
{}
BranchBound::BranchBound(vector<vector<int> > A)
{
	a = A;
	n= a.size();
	Smin = 0;
}
BranchBound::~BranchBound()
{}
vector<int> BranchBound::MinRow()	// массив минимальных элементов по строкам
{
	vector<int> min;
	for (int i = 0; i < n; ++i)
	{

		int minEl = (a[i][0]!=-1)? a[i][0]:a[i][1];
		for (int j = 0; j < n; ++j)
			if (a[i][j] != -1)
				if(minEl > a[i][j])
					minEl = a[i][j];

		min.push_back(minEl);
	}
	return min;
}
vector<int> BranchBound::MinColumn()// массив минимальных элементов по столбцам
{
	vector<int> min;
	for (int i = 0; i < n; ++i)
	{
		int minEl = (a[i][0]!=-1)? a[0][i]:a[1][i];
		for (int j = 0; j < n; ++j)
			if (a[j][i] != -1)
				if(minEl > a[j][i])
					minEl = a[j][i];

		min.push_back(minEl);
	}
	return min;
}
int  BranchBound::Sum(vector<int> arr)
{
	int sum;
	for (int i = 0; i < n; ++i)
		sum += arr[i];
	return sum;
}
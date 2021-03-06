#include "method.h"
int main(int argc, char const *argv[])
{
	freopen("input.txt","r+",stdin);
	int n;
	cin >> n;
	vector<vector<int> > arr;
	for (int i = 0; i < n; ++i)
	{
		vector<int> row;
		for (int j = 0; j < n; ++j)
		{
			int a;
			cin >> a;
			row.push_back(a);
		}
		arr.push_back(row);
	}
	fclose(stdin);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	BranchBound met(arr);
	met.Minimization();
	return 0;
}
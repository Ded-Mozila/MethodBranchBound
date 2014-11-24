#include "method.h"
int main(int argc, char const *argv[])
{
	freopen("input.txt","r+",stdin);
	int n;
	cin >> n;
	map<int ,map <int ,int> > arr;
	for (int i = 0; i < n; ++i)
	{
		vector<int> row;
		for (int j = 0; j < n; ++j)
		{
			int a;
			cin >> a;
			row.push_back(a);
		}
		arr[i] =row;
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
	vector<int> row = met.MinRow();
	for (int i = 0; i < n; ++i)
	{
		cout << row[i] << endl;
	}
	cout << endl;
	vector<int> column = met.MinColumn();
	for (int i = 0; i < n; ++i)
	{
		cout << column[i] << endl;
	}
	return 0;
}
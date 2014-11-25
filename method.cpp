#include "method.h"

BranchBound::BranchBound()
{}
BranchBound::BranchBound(vector<vector<int> > A)
{
	a = A;
	n= a.size();
	for (int i = 1; i < n+1; ++i)
	{
		row.push_back(i);
		column.push_back(i);
	}
	Smin = 0;
}
BranchBound::~BranchBound()
{}
vector<int> BranchBound::MinRow(const vector<vector<int> > arr)	// массив минимальных элементов по строкам
{
	vector<int> min;
	for (int i = 0; i < arr.size(); ++i)
	{

		int minEl = (arr[i][0]!=-1)? arr[i][0]:arr[i][1];
		for (int j = 0; j < arr[i].size(); ++j)
			if (arr[i][j] != -1)
				if(minEl > arr[i][j])
					minEl = arr[i][j];

		min.push_back(minEl);
	}
	return min;
}
vector<int> BranchBound::MinColumn(const vector<vector<int> > arr)// массив минимальных элементов по столбцам
{
	vector<int> min;
	for (int i = 0; i < arr.size(); ++i)
	{
		int minEl = (arr[0][i]!=-1)? arr[0][i]:arr[1][i];
		for (int j = 0; j < arr[0].size(); ++j)
			if (arr[j][i] != -1)
				if(minEl > arr[j][i])
					minEl = arr[j][i];

		min.push_back(minEl);
	}
	return min;
}
int  BranchBound::Sum(vector<int> arr)
{
	int sum=0;
	for (int i = 0; i < arr.size(); ++i)
		sum += arr[i];
	return sum;
}

vector<vector<int> > BranchBound::SubtractRow(vector<vector<int> > arr, vector<int> rowEl)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		for (int j = 0; j < arr[i].size(); ++j)
			if (arr[i][j] != -1)
					arr[i][j] -= rowEl[i];
	}
	return arr;
}

vector<vector<int> > BranchBound::SubtractColumn(vector<vector<int> > arr, vector<int> columnEl)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		for (int j = 0; j < arr[0].size(); ++j)
			if (arr[j][i] != -1)
				arr[j][i] -= columnEl[i];
	}
	return arr;
}

void BranchBound::WriteMatrix(const vector<vector<int> > arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		for (int j = 0; j < arr[i].size(); ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
void BranchBound::WriteArr(const vector<int> arr)
{
	for (int j = 0; j < arr.size(); ++j)
			cout << arr[j] << endl;
}

pair<int,int> BranchBound::MinArc(vector<vector<int> > arr)
{
	int c=0,r=0;
	int maxEl = 0;
	for (int i = 0; i < arr.size(); ++i)
		for (int j = 0; j < arr[i].size(); ++j)
			if (arr[i][j] == 0)
			{
				arr[i][j] = -1;
				vector<int> minRow =MinRow(arr);
				vector<int> minColumn =MinColumn(arr);
				if(maxEl < (minRow[i] + minColumn[j]))
				{
					maxEl = minRow[i] + minColumn[j];
					r = i;
					c = j;
				}
				arr[i][j] = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
			}
	return make_pair( r,c );
}
vector<vector<int > > BranchBound::DeleteNode(vector<vector<int> > arr, pair<int,int> x)
{
	arr[x.first][x.second] = -1;
	return arr;
}
vector<vector<int > > BranchBound::DeleteArc(vector<vector<int> > arr, pair<int,int> x)
{
	arr[x.second][x.first] = -1;
	// удаление строки

	arr.erase(arr.begin()+x.first);
	// удаления столбца
	for (int i = 0; i < arr.size(); ++i)
	{
		vector<int>::iterator ii = arr[i].begin();
		for (int j = 0; j < arr[j].size(); ++j,++ii)
		{
			if(j == x.second)
			{
				arr[i].erase(ii);
				break;
			}
		}

	}
	return arr;
}
int BranchBound::Minumum(vector<vector<int> > arr, int min)
{
	if (arr.size() != 2 && (*arr.begin()).size() != 2)
	{	
		freopen("output.txt","a+",stdout);
		cout << min<< endl;
		vector<int> r = MinRow(arr);
		arr = SubtractRow(arr,r);
		min +=Sum(r);
		vector<int> c = MinColumn(arr);
		arr = SubtractColumn(arr,c);
		min +=Sum(c);
		pair<int,int> minZero = MinArc(arr);
		cout << minZero.first << " " << minZero.second<< '\n';
		int k;
		cin >> k;
		fclose(stdout);
		int minArc = Minumum(DeleteArc(arr,minZero),min);
		int minNode = Minumum(DeleteNode(arr,minZero),min);
		min = minArc < minNode? minArc : minNode;

	}
	return min;
}
int BranchBound::Minimization()
{
	freopen("output.txt","w+",stdout);
	int min = 0;
	int k =0;// итерация

	//строка
	vector<int> r = MinRow(a);
	Smin +=Sum(r);
	a = SubtractRow(a,r);
	
	//столбцы
	vector<int> c = MinColumn(a);
	a = SubtractColumn(a,c);
	Smin +=Sum(c);
	WriteMatrix(a);
	pair<int,int> tt = MinArc(a);
	fclose(stdout);
	Smin = Minumum(DeleteNode(a,tt),Smin);

	cout << Smin << endl;
	return min;
}
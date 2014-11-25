#include "method.h"

BranchBound::BranchBound()
{}
BranchBound::BranchBound(vector<vector<int> > A)
{
	a = A;
	n= a.size();
	for (int i = 0; i < n; ++i)
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
			cout << arr[j] << " ";
		cout << endl;
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
pair<int,int> BranchBound::Transporn(pair<int,int> x)
{
	pair<int,int> pp;
	int  k = 0;
	for (int i = 0; i <  row.size(); ++i)
	{
		row[i] -= k;
		if (i == x.first)
		{
			pp.first = row[i];
		//	k =1;
		}
		
	}
	int e=0;
	for (int i = 0; i < column.size(); ++i)
	{
		column[i] -= e;
		if(i == x.second)
		{
			pp.second = column[i];
			//e =1;
		}
		
	}
	if (pp.first >= row.size())
	{
		pp.first = row.size()-1;
	}
	if (pp.second >= column.size())
	{
		pp.second = column.size()-1;
	}
	return pp;
}
vector<vector<int > > BranchBound::DeleteArc(vector<vector<int> > arr, pair<int,int> x)
{
	vector<vector<int> > arrE = arr;
	pair<int,int> xx = Transporn(x);
	cout << endl;
	cout << x.first << " " << x.second << endl;
	WriteArr(column);
	WriteArr(row);
	cout << xx.first << " " << xx.second << endl;
		// удаление строки
	arrE[xx.second][xx.first] = -1;
	arrE.erase(arrE.begin()+x.first);
	// удаления столбца
	for (int i = 0; i < arrE.size(); ++i)
	{
		// vector<int>::iterator ii = arrE[i].begin();
		// for (int j = 0; j < arrE[j].size(); ++j, ++ii)
		// {
		// 	if(j == x.second)
		// 	{
				arrE[i].erase(arrE[i].begin()+x.second);
		// 	}
		// }

	}
	return arrE;
}
int BranchBound::Minumum(vector<vector<int> > arr, int ArrMin ,pair<int,int> tt)
{
	freopen("output.txt","w",stdout);
	WriteArr(column);
	WriteArr(row);
	cout << endl;
	do
	{	
		cout << endl;
		int min1 = ArrMin,min2 = ArrMin;
		vector<vector<int> > arrArc  = DeleteArc(arr,tt);
		vector<int> r1 = MinRow(arrArc);
		arrArc = SubtractRow(arrArc,r1);
		min1 +=Sum(r1);
		vector<int> c1 = MinColumn(arrArc);
		arrArc = SubtractColumn(arrArc,c1);
		min1 +=Sum(c1);
	
		vector<vector<int> > arrNode = DeleteNode(arr,tt);
		vector<int> r2 = MinRow(arrNode);
		arrNode = SubtractRow(arrNode,r2);
		min2 +=Sum(r2);
		vector<int> c2 = MinColumn(arrNode);
		arrNode = SubtractColumn(arrNode,c2);
		min2 +=Sum(c2);
		arr.clear();
		if (min1 < min2)
		{
			arr =arrArc;
			ArrMin = min1;
			DelElement(tt);
		}
		else
		{
			arr =arrNode;
			ArrMin = min2;

		}
		WriteMatrix(arr);
		cout << ArrMin << endl;
		// int minArc = Minumum(DeleteArc(arr,minZero),min);
		// int minNode = Minumum(DeleteNode(arr,minZero),min);
		// min = minArc < minNode? minArc : minNode;

	}while(arr.size() > 2 && (*arr.begin()).size() > 2);
		fclose(stdout);
	return ArrMin;
}
void BranchBound::DelElement(pair<int,int> x)
{
	vector<int>::iterator elrow = row.begin();
	vector<int>::iterator elcolumn = column.begin();
	for (int i = 0; i < row.size(); ++i,++elrow)
		if (i == x.first)
		{
			row.erase(elrow);
			break;
		}
	for (int i = 0; i < column.size(); ++i, ++elcolumn)
		if(i == x.second)
		{
			column.erase(elcolumn);
			break;
		}

}
int BranchBound::Minimization()
{
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
	pair<int,int> tt   = MinArc(a);
	cout << Smin << endl;
	Smin = Minumum(a, Smin, tt);
	cout << Smin << endl;
	return min;
}
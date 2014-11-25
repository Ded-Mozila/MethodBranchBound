#ifndef METHOD_H
#define METHOD_H
#include "header.h"

class BranchBound
{
public:
	vector<vector<int> > a; // исходная матрица
	vector<pair<int,int> > path;
	int Smin; 	
	int n;			// минимальная сумма
	BranchBound();
	BranchBound(vector<vector<int> > A);
	~BranchBound();
	vector<int> row;			// какие столбцы существуют
	vector<int> column;			// какие солбцы существуют
	vector<int> MinRow(const vector<vector<int> > arr);		// массив минимальных элементов по строкам
	vector<int> MinColumn(const vector<vector<int> > arr);	// массив минимальных элементов по столбцам
	int Sum(vector<int> arr);	// сложения масссива элементов Smin!
	int Minimization();			// функция алгоритма 
	vector<vector<int> > SubtractRow( vector<vector<int> > arr, vector<int> rowEl);
	vector<vector<int> > SubtractColumn(vector<vector<int> > arr, vector<int> columnEl);
	void WriteMatrix(const vector<vector<int> > arr);
	void WriteArr(const vector<int> arr);
	pair<int,int> MinArc(vector<vector<int> > arr);//Поиск минимального узла или дуги
	vector<vector<int > > DeleteNode(vector<vector<int> > arr, pair<int,int> x);
	vector<vector<int > > DeleteArc(vector<vector<int> > arr, pair<int,int> x);
	int Minumum(vector<vector<int> > arr, int min);
};
#endif
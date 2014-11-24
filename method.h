#ifndef METHOD_H
#define METHOD_H
#include "header.h"

class BranchBound
{
public:
	vector<vector<int> > a; // исходная матрица
	int Smin; 	
	int n;			// минимальная сумма
	BranchBound();
	BranchBound(vector<vector<int> > A);
	~BranchBound();
	vector<int> MinRow();		// массив минимальных элементов по строкам
	vector<int> MinColumn();	// массив минимальных элементов по столбцам
	int Sum(vector<int> arr);	// сложения масссива элементов Smin!

};
#endif
#pragma once CYBER_DASH_SPARSE_MATRIX_H
#define CYBER_DASH_SPARSE_MATRIX_H

#include <iostream>
#include <cstdlib>//它定义了一系列函数和宏，以实现跨团队、跨平台的高效且具有卓越表现的标准化 C++ 代码。
using namespace std;


//稀疏矩阵三元组结构体
template<class T>
struct TriTuple {
	int row;
	int col;
	T value;

/*
* 赋值运算符重载函数
* tri_tuple 系数函数三元组数据
* return 当前对象本身
*/
TriTuple<T>& operator=(TriTuple<T>& tri_tuple) {
	row = tri_tuple.row;
	col = tri_tuple.col;
	value = tri_tuple.value;

	return *this;
}
};

//稀疏矩阵模板类
template<class T>
class SparseMatrix {
public:
	//构造函数(参数为稀疏矩阵最大元素个数)
	SparseMatrix(int max_size=100);

	//复制构造函数(参数为稀疏矩阵)
	SparseMatrix(SparseMatrix<T>& sparse_matrix);

	//析构函数
	virtual ~SparseMatrix() { delete[] sparse_matrix_array_; }

	//获取行数
	int Rows() { return this->rows_; }
	//设置行数
	void setRows(int rows) { return this->rows_ = rows; }

	//获取列数
	int Cols() { return this->cols_; }
	//设置列数
	void setCols(int cols) { this->cols_ = cols; }

	//获取元素数
	int Terms() { return this->terms_; }
	//设置元素数
	void setTerms(int terms) { this->terms_ = terms; }

	//获取最大元素数
	int maxTerms() { return this->max_terms_; }
	//设置最大元素数
	void setmaxTerms(int maxTerms) { this->max_terms_ = maxTerms; }

	//获取元素
	bool getElement(int row,int col,T& value);
	//添加(替换)元素
	bool addorreplaceElement(int row,int col,T value);

	//获取元素数组起始地址
	TriTuple<T>* SparseMatrixArray() { return this->sparse_matrix_array_; }

	//赋值运算符重载
	SparseMatrix<T>& operator=(SparseMatrix<T>& sparse_matrix);

	//转置运算
	SparseMatrix<T>* Transpose();
	//快速转置运算
	SparseMatrix<T>* FastTranspose();
private:
	int rows_;
	int cols_;
	int terms_;
	int max_terms_;
	TriTuple<T>* sparse_matrix_array_;
};
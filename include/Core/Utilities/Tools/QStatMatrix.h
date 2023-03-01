/*
Copyright (c) 2017-2023 Origin Quantum Computing. All Right Reserved.
Licensed under the Apache License 2.0

QstatMatrix.h
Author: Wangjing
Created in 2018-8-31

Classes for get the shortes path of graph

*/

#ifndef QSTATMATRIX_H
#define QSTATMATRIX_H
#include "Core/Utilities/QPandaNamespace.h"
#include <iostream>
#include <complex>
#include <vector>
#include "ThirdParty/Eigen/Eigen"
#include "Core/Utilities/Tools/QMatrixDef.h"

QPANDA_BEGIN

#define MAX_COMPARE_PRECISION 1e-10

typedef struct _matrix_block
{
	_matrix_block()
		:m_row_index(0), m_column_index(0)
	{}

	int m_row_index;
	int m_column_index;
	QMatrixXcd m_mat;
}matrixBlock_t;

typedef struct _blocked_matrix
{
	_blocked_matrix()
		:m_block_rows(0), m_block_columns(0)
	{}

	int m_block_rows;
	int m_block_columns;
	std::vector<matrixBlock_t> m_vec_block;
}blockedMatrix_t;

bool isPerfectSquare(int number);
QStat operator+(const QStat &matrix_left, const QStat &matrix_right);
QStat operator+(const QStat &matrix_left, const qcomplex_t value);
QStat operator+(const qcomplex_t value, const QStat &matrix_right);

QStat operator-(const QStat &matrix_left, const QStat &matrix_right);
QStat operator-(const QStat &matrix_left, const qcomplex_t &value);
QStat operator-(const qcomplex_t &value, const QStat &matrix_right);

QStat operator*(const QStat &matrix_left, const QStat &matrix_right);
QStat operator*(const QStat &matrix_left, const qcomplex_t &value);
QStat operator*(const qcomplex_t &value, const QStat &matrix_right);
std::ostream& operator<<(std::ostream &out, QStat mat);

/**
* @brief  partition matrix by the input partitionRowNum and partitionColumnNum
* @ingroup Utilities
* @param[in] srcMatrix  the source matrix
* @param[in] partitionRowNum Specify how many blocks to separated horizontally
* @param[in] partitionColumnNum Specify how many blocks to separated in the vertical direction
* @param[out] blockedMat The separated matrix
* @return Execution successfully returns 0, otherwise returns to other.
*/
int partition(QMatrixXcd& srcMatrix, int partitionRowNum, int partitionColumnNum, blockedMatrix_t& blockedMat);

/**
* @brief  Block Multiplication of Matrix
* @ingroup Utilities
* @param[in] leftMatrix  the left input matrix
* @param[in] blockedMat The matrix blocks
* @param[out] resultMatrix The result of Block Multiplication
* @return Execution successfully returns 0, otherwise returns to other.
*/
int blockMultip(QMatrixXcd& leftMatrix, const blockedMatrix_t& blockedMat, QMatrixXcd& resultMatrix);

/**
* @brief Getting the Inverted Conjugate Matrix of the target Matrix
* @ingroup Utilities
* @param[in,out] srcMat  the target matrix
* @return
*/
void dagger(QStat &src_mat);
QStat dagger_c(const QStat &src_mat);

/**
* @brief Tensor Multiplication
* @ingroup Utilities
* @param[in] leftMatrix  the left input matrix
* @param[in] rightMatrix the right input matrix
* @return Tensor Product of input Left Matrix and Right Matrix.
*/
QStat tensor(const QStat& leftMatrix, const QStat& rightMatrix);

/**
* @brief  transform matrix to string
* @ingroup Utilities
* @param[in] the target matrix
* @param[in] const int: precision
* @return the matrix string
*/
std::string matrix_to_string(const QStat& mat, const int precision = 15);

/**
* @brief Compare the two matrices to determine whether they are equal
* @ingroup Utilities
* @param[in] "const QStat&" the first matrix
* @param[in] "const QStat&" the second matrix
* @param[in] double Comparative accuracy
* @return if the two input matrices are equal return 0, or else return others
*/
int mat_compare(const QStat& mat1, const QStat& mat2, const double precision = MAX_COMPARE_PRECISION);
bool operator==(const QStat &matrix_left, const QStat &matrix_right);
bool operator!=(const QStat &matrix_left, const QStat &matrix_right);

/**
* @brief Convert QStat to Eigen data type
* @ingroup Utilities
* @param[in] "const QStat&" the input matrix
* @return Eigen matrix data
*/
QMatrixXcd QStat_to_Eigen(const QStat& mat);

/**
* @brief Convert Eigen data type to QStat
* @ingroup Utilities
* @param[in] QMatrixXcd the input Eigen matrix
* @return Corresponding QStat
*/
QStat Eigen_to_QStat(const QMatrixXcd& mat);

/**
* @brief Convert a QStat unitary_matrix
* @ingroup Utilities
* @param[in] matrix rows or cols
* @return Corresponding QStat
*/
QStat qstat_zero_matrix(size_t rows);
QStat qstat_unitary_matrix(size_t rows);


/**
* @brief Convert a QMatrixXcd unitary_matrix
* @ingroup Utilities
* @param[in] matrix rows or cols
* @return Corresponding QMatrixXcd
*/
QMatrixXcd eigen_zero_matrix(size_t rows);
QMatrixXcd eigen_unitary_matrix(size_t rows);

/**
* @brief check whether the input matrix is a unitary matrix
* @ingroup Utilities
* @param[in] const QStat& the input matrix
* @param[in] const double the max precision, default 0.000001
* @return if the input matrix is unitary matrix return true, or else return false
*/
bool is_unitary_matrix(const QStat &circuit_matrix, const double precision = MAX_COMPARE_PRECISION);
bool is_unitary_matrix_by_eigen(const QStat& circuit_matrix, const double precision = MAX_COMPARE_PRECISION);
bool is_unitary_matrix_by_eigen(const QMatrixXcd& circuit_matrix, const double precision = MAX_COMPARE_PRECISION);

QPANDA_END
#endif // QSTATMATRIX_H

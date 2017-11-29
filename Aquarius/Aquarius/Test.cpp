//#include "Matrix44.h"
//#include "Vector3.h"
//
//#include <iostream>
//
//#include <cmath>
//#include "Defines.h"
//
//using namespace std;
//using namespace igad;
//
//void PrintMatrix(Matrix44 matrix);
//
//void Vector3Test()
//{
//	float epsilon = 0.000001;
//
//	cout << "Vector3 test: \n\n";
//	///Test 1: Default constructor
//	Vector3 vector1;
//
//	cout << "Test 1: Default constructor: ";
//	if (vector1.x == vector1.y == vector1.z == 0)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 2: Constructor with given components
//	Vector3 vector2(10.0f, 30.0f, 50.0f);
//
//	cout << "Test 2: Constructor with given components: ";
//	if ((vector2.x == 10.0f) && (vector2.y == 30.0f) && (vector2.z == 50.0f))
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 3: Operator+
//	Vector3 vector3_1;
//	Vector3 vector3_2;
//
//	vector3_1.x = 1.0f;
//	vector3_1.y = 3.0f;
//	vector3_1.z = 5.0f;
//	vector3_2.x = 2.0f;
//	vector3_2.y = 4.0f;
//	vector3_2.z = 6.5f;
//
//	Vector3 vector3 = vector3_1 + vector3_2;
//
//	cout << "Test 3: Operator+: ";
//	if ((vector3.x == 3.0f) && (vector3.y == 7.0f) && (vector3.z == 11.5f))
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 4: Operator-
//	Vector3 vector4_1;
//	Vector3 vector4_2;
//
//	vector4_1.x = 10.0f;
//	vector4_1.y = 20.0f;
//	vector4_1.z = 30.0f;
//	vector4_2.x = 5.0f;
//	vector4_2.y = 10.0f;
//	vector4_2.z = 15.5f;
//
//	Vector3 vector4 = vector4_1 - vector4_2;
//
//	cout << "Test 4: Operator-: ";
//	if ((vector4.x == 5.0f) && (vector4.y == 10.0f) && (vector4.z == 14.5f))
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 5: Operator*
//	Vector3 vector5;
//
//	vector5.x = 2.0f;
//	vector5.y = 4.0f;
//	vector5.z = 8.0f;
//	vector5 = vector5 * 3.5f;
//	cout << "Test 5: Operator*: ";
//
//	if ((vector5.x == 7.0f) && (vector5.y == 14.0f) && (vector5.z == 28.0f))
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 6: Operator/
//	Vector3 vector6;
//
//	vector6.x = 9.0f;
//	vector6.y = 15.0f;
//	vector6.z = 18.0f;
//	vector6 = vector6 / 3.0f;
//	cout << "Test 6: Operator/: ";
//	if ((vector6.x == 3.0f) && (vector6.y == 5.0f) && (vector6.z == 6.0f))
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 7: Operator- (negative vector)
//	Vector3 vector7;
//
//	vector7.x = 5.0f;
//	vector7.y = 6.0f;
//	vector7.z = 7.0f;
//	vector7 = -vector7;
//	cout << "Test 7: Operator- (negative vector): ";
//	if ((vector7.x == -5.0f) && (vector7.y == -6.0f) && (vector7.z == -7.0f))
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 8: Operator* (dot product)
//	Vector3 vector8_1;
//	Vector3 vector8_2;
//
//	vector8_1.x = 3.0f;
//	vector8_1.y = 5.0f;
//	vector8_1.z = 7.7f;
//	vector8_2.x = 1.0f;
//	vector8_2.y = 2.0f;
//	vector8_2.z = 10.0f;
//
//	float dot8 = vector8_1 * vector8_2;
//
//	cout << "Test 8: Operator* (dot product): ";
//	if (dot8 == 90.0f)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 9: Operator+=
//	Vector3 vector9_1;
//	Vector3 vector9_2;
//
//	vector9_1.x = 7.0f;
//	vector9_1.y = 3.0f;
//	vector9_1.z = 6.0f;
//	vector9_2.x = 3.7f;
//	vector9_2.y = 6.3f;
//	vector9_2.z = 7.6f;
//	vector9_1 += vector9_2;
//	cout << "Test 9: Operator+=: ";
//	if ((vector9_1.x == 10.7f) && (vector9_1.y == 9.3f) && (vector9_1.z == 13.6f))
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 10: Operator-=
//	Vector3 vector10_1;
//	Vector3 vector10_2;
//
//	vector10_1.x = 12.3;
//	vector10_1.y = 45.6;
//	vector10_1.z = 78.9;
//	vector10_2.x = 5.5f;
//	vector10_2.y = 10.1f;
//	vector10_2.z = 20.2f;
//	vector10_1 -= vector10_2;
//	cout << "Test 10: Operator-=: ";
//	if ((vector10_1.x == 6.8f) && (vector10_1.y == 35.5f) && (vector10_1.z == 58.7f))
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 11: Operator*=
//	Vector3 vector11;
//
//	vector11.x = 14.0f;
//	vector11.y = -24.0f;
//	vector11.z = 34.0f;
//	vector11 *= -2.0f;
//	cout << "Test 11: Operator *=: ";
//	if ((vector11.x == -28.0f) && (vector11.y == 48.0f) && (vector11.z == -68.0f))
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 12: Cross
//	Vector3 vector12_1;
//	Vector3 vector12_2;
//
//	vector12_1.x = 3.0f;
//	vector12_1.y = 6.0f;
//	vector12_1.z = 12.0f;
//	vector12_2.x = 16.0f;
//	vector12_2.y = 8.0f;
//	vector12_2.z = 4.0f;
//
//	Vector3 vector12 = vector12_1.Cross(vector12_2);
//
//	cout << "Test 13: Cross: ";
//	if ((abs(vector12.x - -72.0f) < epsilon) && (abs(vector12.y - 180.0f) < epsilon) && (abs(vector12.z - -72.0f) < epsilon))
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//		cout << "X, y , z " << vector12.x << ", " << vector12.y << ", " << vector12.z << endl;
//	}
//
//	///Test 13: Dot
//	Vector3 vector13_1;
//	Vector3 vector13_2;
//
//	vector13_1.x = 15.0f;
//	vector13_1.y = 11.0f;
//	vector13_1.z = 8.0f;
//	vector13_2.x = 3.0f;
//	vector13_2.y = 4.0f;
//	vector13_2.z = 7.0f;
//
//	float dot13 = vector13_1.Dot(vector13_2);
//
//	cout << "Test 13: Dot: ";
//	if (dot13 == 145.0f)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 14: Magnitude
//	Vector3 vector14;
//
//	vector14.x = 3.0f;
//	vector14.y = 12.0f;
//	vector14.z = 4.0f;
//
//	float mag14 = vector14.Magnitude();
//
//	cout << "Test 14: Magnitude: ";
//	if (abs(mag14 - 13.0f) < epsilon)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 15: SquareMagnitude
//	Vector3 vector15;
//
//	vector15.x = 3.0f;
//	vector15.y = 8.0f;
//	vector15.z = 10.0f;
//
//	float sqrMag15 = vector15.SquareMagnitude();
//
//	cout << "Test 15: SquareMagnitude: ";
//	if (abs(sqrMag15 - 173.0f) < epsilon)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 16: Normalize
//	Vector3 vector16(3.0f, 4.0f, 12.0f);
//
//	vector16.Normalize();
//
//	cout << "Test 16: Normalize: ";
//	//if(vector16.Magnitude() == 1)
//	if ((abs(vector16.x - (3.0f / 13.0f)) < epsilon) && (abs(vector16.y - (4.0f / 13.0f)) < epsilon) && (abs(vector16.z - (12.0f / 13.0f)) < epsilon))
//	{
//		cout << " OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 17: Operator==
//	Vector3 vector17_1;
//	Vector3 vector17_2;
//
//	vector17_1.x = 2.0f;
//	vector17_1.y = 5.0f;
//	vector17_1.z = 4.4f;
//	vector17_2.x = 2.0f;
//	vector17_2.y = 5.0f;
//	vector17_2.z = 4.4f;
//
//	cout << "Test 17: Operator==: ";
//	if (vector17_1 == vector17_2)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 18: Operator==
//	Vector3 vector18_1;
//	Vector3 vector18_2;
//
//	vector18_1.x = 2.0f;
//	vector18_1.y = 5.0f;
//	vector18_1.z = 4.4f;
//	vector18_2.x = 2.0f;
//	vector18_2.y = 5.0f;
//	vector18_2.z = 4.4f;
//
//	cout << "Test 18: Operator==: ";
//	if (vector18_1 == vector18_2)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 19: Operator !=
//	Vector3 vector19_1;
//	Vector3 vector19_2;
//	Vector3 vector19_3;
//
//	vector19_1.x = 6.0f;
//	vector19_1.y = 18.0f;
//	vector19_1.z = 2.0f;
//	vector19_2.x = 6.0f;
//	vector19_2.y = 8.0f;
//	vector19_2.z = 2.0f;
//	vector19_3.x = 5.0f;
//	vector19_3.y = 18.0f;
//	vector19_3.z = 14.0f;
//
//	cout << "Test 19: Operator!=: ";
//	if (!(vector19_1 != vector19_1) && (vector19_1 != vector19_2) && (vector19_1 != vector19_3) && (vector19_2 != vector19_3))
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 20: Clear
//	Vector3 vector20;
//
//	vector20.x = 1.1f;
//	vector20.x = 2.2f;
//	vector20.z = 3.3f;
//	vector20.Clear();
//	cout << "Test 19: Clear: ";
//	if (vector20.x == vector20.y == vector20.z == 0.0f)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//}
//
//void Matrix44Test()
//{
//	bool failure = false;
//	float epsilon = 0.000001;
//	Matrix44 matrix0_1;
//	float matrixValues_1[16] =
//	{
//		1.0f,  3.0f,  5.0f,  9.0f,
//		1.0f,  3.0f,  1.0f,  7.0f,
//		4.0f,  3.0f,  9.0f,  7.0f,
//		5.0f,  2.0f,  0.0f,  9.0f
//	};
//
//	for (char i = 0; i < 16; i++)
//	{
//		matrix0_1.f[i] = matrixValues_1[i];
//	}
//
//	Matrix44 matrix0_2;
//	float matrixValues_2[16] =
//	{
//		1.0f,   2.0f,   3.0f,   4.0f,
//		5.0f,   6.0f,   7.0f,   8.0f,
//		9.0f,  10.0f,  11.0f,  12.0f,
//		13.0f,  14.0f,  15.0f,  16.0f
//	};
//	for (char i = 0; i < 16; i++)
//	{
//		matrix0_2.f[i] = matrixValues_2[i];
//	}
//
//	cout << "\n\nMatrix44 test:\n\n";
//	///Test 1: Construtor with given values
//	Matrix44 matrix1
//	(
//		1.5f, 3.0f, 4.5f, 6.0f,
//		7.5f, 9.0f, 10.5f, 12.0f,
//		13.5f, 15.0f, 16.5f, 18.0f,
//		19.5f, 21.0f, 22.5f, 24.0f
//	);
//
//	for (char i = 0; i < 16; i++)
//	{
//		if (matrix1.f[i] != (i + 1) * 1.5f)
//		{
//			failure = true;
//			break;
//		}
//	}
//
//	cout << "Test 1: Construtor with given values: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 2: Default constructor (identity matrix)
//	Matrix44 matrix2;
//
//	failure = false;
//	for (char i = 0; i < 16; i++)
//	{
//		if (i % 5 == 0)
//		{
//			if (matrix2.f[i] != 1.0f)
//			{
//				failure = true;
//				break;
//			}
//		}
//		else
//		{
//			if (matrix2.f[i] != 0.0f)
//			{
//				failure = true;
//				break;
//			}
//		}
//	}
//	cout << "Test 2: Default constructor (identity matrix): ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 3: Operator* (transforming vector by matrix)
//	Vector3 vector3_1;
//
//	vector3_1.x = 2.0f;
//	vector3_1.y = 3.0f;
//	vector3_1.z = 4.0f;
//
//	Vector3 vector3 = matrix0_1 * vector3_1;
//
//	cout << "Test 3: Operator* (transforming vector by matrix): ";
//	if ((vector3.x == 40.0f) && (vector3.y == 22.0f) && (vector3.z == 60.0f))
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "vector3.x = " << vector3.x << "\n";
//		//cout << "matrix: " << matrix0_1.m[0][2] << "\n";
//		
//		cout << "FAILED\n";
//	}
//
//	///Test 4: Operator+
//	Matrix44 matrix4 = matrix0_2 + matrix0_2;
//
//	failure = false;
//	for (char i = 0; i < 16; i++)
//	{
//		if (matrix4.f[i] != 2 * (i + 1))
//		{
//			failure = true;
//			break;
//		}
//	}
//	cout << "Test 4: Operator+: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 5: Operator-
//	Matrix44 matrix5 = matrix0_1 - matrix0_2;
//
//	failure = false;
//	for (char i = 0; i < 16; i++)
//	{
//		if (matrix5.f[i] != (matrix0_1.f[i] - matrix0_2.f[i]))
//		{
//			failure = true;
//			break;
//		}
//	}
//	cout << "Test 5: Operator-: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 6: operator* (matrix multiplication)
//	Matrix44 matrix6 = matrix0_1 * matrix0_2;
//	float matrix6_check[] =
//	{
//		178.0f, 196.0f, 214.0f, 232.0f,
//		116.0f, 128.0f, 140.0f, 152.0f,
//		191.0f, 214.0f, 237.0f, 260.0f,
//		132.0f, 148.0f, 164.0f, 180.0f
//	};
//
//	cout << "\n***matrix0_1\n";
//	//PrintMatrix(matrix0_1);
//	failure = false;
//
//	for (char i = 0; i < 16; i++)
//	{
//		if (abs(matrix6_check[i] - matrix6.f[i]) > epsilon)
//		{
//			failure = true;
//			break;
//		}
//	}
//	cout << "Test 6: operator* (matrix multiplication): ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//
//		for (int row = 0; row < 4; row++)
//		{
//			for (int col = 0; col < 4; col++)
//			{
//				cout << matrix6.m[row][col] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//	
//
//	///Test 7: GetTranslation
//	Vector3 vector7 = matrix0_2.GetTranslation();
//
//	failure = false;
//	for (char i = 0; i < 3; i++)
//	{
//		if (vector7.f[i] != 13.0f + i)
//		{
//			failure = true;
//			break;
//		}
//	}
//	cout << "Test 7: GetTranslation: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 8: SetTranslation
//	Matrix44 matrix8 = matrix0_1;
//	Vector3 vector8;
//
//	vector8.x = 1.5f;
//	vector8.y = 3.0f;
//	vector8.z = 4.5f;
//	matrix8.SetTranslation(vector8);
//	failure = false;
//	for (char i = 0; i < 3; i++)
//	{
//		if (matrix8.translation.f[i] != 1.5f * (i + 1))
//		{
//			failure = true;
//			break;
//		}
//	}
//	for (char i = 0; i < 12; i++)
//	{
//		if (matrix8.f[i] != matrix0_1.f[i])
//		{
//			failure = true;
//			break;
//		}
//	}
//	if (matrix8.one != matrix0_1.one)
//	{
//		failure = true;
//	}
//	cout << "Test 8: SetTranslation: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 9: GetXAxis
//	Vector3 vector9 = matrix0_2.GetXAxis();
//
//	failure = false;
//	for (char i = 0; i < 3; i++)
//	{
//		if (vector9.f[i] != 1.0f + i)
//		{
//			failure = true;
//			break;
//		}
//	}
//	cout << "Test 9: GetXAxis: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 10: GetYAxis
//	Vector3 vector10 = matrix0_2.GetYAxis();
//
//	failure = false;
//	for (char i = 0; i < 3; i++)
//	{
//		if (vector10.f[i] != 5.0f + i)
//		{
//			failure = true;
//			break;
//		}
//	}
//	cout << "Test 10: GetYAxis: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 11: GetZAxis
//	Vector3 vector11 = matrix0_2.GetZAxis();
//
//	failure = false;
//	for (char i = 0; i < 3; i++)
//	{
//		if (vector11.f[i] != 9.0f + i)
//		{
//			failure = true;
//			break;
//		}
//	}
//	cout << "Test 11: GetZAxis: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 12: Determinant
//	Matrix44 identity;
//	float det12 = matrix0_1.Determinant(identity);
//
//	cout << "Test 12: Determinant: ";
//	if (det12 == -376.0f)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "determinant: " << det12 << "\n";
//		cout << "FAILED\n";
//	}
//
//	///Test 13: Invert
//	Matrix44 matrix13_1 = matrix0_1;
//	Matrix44 matrix13_2 = matrix0_2;
//	bool invert13_1Return;
//	bool invert13_2Return;
//
//	float invert13_check[16] =
//	{
//		-13.0f / 47.0f,  02.0f / 47.0f,  07.0f / 47.0f,  06.0f / 47.0f,
//		-05.0f / 08.0f,  07.0f / 08.0f,  01.0f / 04.0f, -01.0f / 04.0f,
//		39.0f / 376.0f, -53.0f / 376.0f,  13.0f / 188.0f, -09.0f / 188.0f,
//		55.0f / 188.0f, -41.0f / 188.0f, -13.0f / 94.0f,  09.0f / 94.0f
//	};
//
//	invert13_1Return = matrix13_1.Invert();
//	invert13_2Return = matrix13_2.Invert();
//
//
//	failure = false;
//
//	for (char i = 0; i < 16; i++)
//	{
//		//Checking invertible matrix
//		if (abs(matrix13_1.f[i] - invert13_check[i]) > epsilon)
//		{
//			
//			failure = true;
//			break;
//		}
//
//		//Checking non-invertible matrix
//		if (matrix13_2.f[i] != matrix0_2.f[i])
//		{
//			failure = true;
//			break;
//		}
//	}
//	cout << "Test 13: Invert: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//		cout << "\t - Returns TRUE when inverting invertible matrices: ";
//		if (invert13_1Return == true)
//		{
//			cout << "OK\n";
//		}
//		else
//		{
//			cout << "FAILED\n";
//		}
//		cout << "\t - Returns FALSE when inverting non-invertible matrices: ";
//		if (invert13_2Return == false)
//		{
//			cout << "OK\n";
//		}
//		else
//		{
//			cout << "FAILED\n";
//		}
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 14: Transpose
//	Matrix44 matrix14 = matrix0_1;
//
//	matrix14.Transpose();
//	failure = false;
//	for (char row = 0; row < 4; row++)
//	{
//		for (char column = 0; column < 4; column++)
//		{
//			if (matrix14.m[row][column] != matrix0_1.m[column][row])
//			{
//				failure = true;
//				break;
//			}
//		}
//	}
//	cout << "Test 14: Transpose: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 15: SetOrientation
//	Matrix44 matrix15 = matrix0_2;
//	Vector3 vector15_1 = matrix0_1.xAxis;
//	Vector3 vector15_2 = matrix0_1.yAxis;
//	Vector3 vector15_3 = matrix0_1.zAxis;
//
//	matrix15.SetOrientation(vector15_1, vector15_2, vector15_3);
//	failure = false;
//	for (char mat_row = 0; mat_row < 3; mat_row++)
//	{
//		for (char i = 0; i < 3; i++)
//		{
//			if (matrix15.m[mat_row][i] != matrix0_1.m[mat_row][i])
//			{
//				failure = true;
//				break;
//			}
//		}
//	}
//	for (char i = 11; i < 16; i++)
//	{
//		if (matrix15.f[i] != matrix0_2.f[i])
//		{
//			failure = true;
//			break;
//		}
//	}
//	for (char i = 0; i < 3; i++)
//	{
//		if (matrix15.m[3][i] != matrix0_2.m[3][i])
//		{
//			failure = true;
//			break;
//		}
//	}
//
//	cout << "Test 15: SetOrientation: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//
//		//for (int i = 0; i < 3; i++)
//		//{
//		//	cout <<
//		//}
//	}
//
//	///Test 16: SetEulerAxis
//	Matrix44 matrix16 = matrix0_1;
//	float matrix16_check[] =
//	{
//		-0.883883476f, 0.306186140f, -0.353553355f, 9.0f,
//		-0.433012664f,		 -0.25f,  0.866025448f, 7.0f,
//		0.176776648f, 0.918558657f,  0.353553355f, 7.0f,
//		5.0f,		   2.0f,		  0.0f, 9.0f
//	};
//
//	matrix16.SetEulerAxis(Pi / 4.0f, Pi / 3.0f, Pi * (2.0f / 3.0f));
//	failure = false;
//	for (char i = 0; i < 16; i++)
//	{
//		if (abs(matrix16_check[i] - matrix16.f[i]) > epsilon)
//		{
//			failure = true;
//			break;
//		}
//	}
//	cout << "Test 16: SetEulerAxis: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//
//		cout << "matrix16_check\n\n";
//		for (int i = 0; i < 16; i++)
//		{
//			if (i % 4 == 0)
//				cout << "\n";
//				cout << matrix16_check[i] << " ";
//				
//		}
//		cout << endl;
//
//		cout << "\n\nmatrix16.m\n\n";
//		for (int row = 0; row < 4; row++)
//		{
//			for (int col = 0; col < 4; col++)
//			{
//				cout << matrix16.m[row][col] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//
//	///Test 17: CreateIdentity
//	Matrix44 matrix17 = Matrix44::CreateIdentity();
//
//	failure = false;
//	for (char i = 0; i < 16; i++)
//	{
//		if (i % 5 == 0)
//		{
//			if (matrix17.f[i] != 1.0f)
//			{
//				failure = true;
//				break;
//			}
//		}
//		else
//		{
//			if (matrix17.f[i] != 0.0f)
//			{
//				failure = true;
//				break;
//			}
//		}
//	}
//	cout << "Test 17: Create Identity: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 18: CreateTranslation
//	Matrix44 matrix18 = Matrix44::CreateTranslation(0.0f, 5.0f, 10.0f);
//
//	for (char i = 0; i < 12; i++)
//	{
//		if (i % 5 == 0)
//		{
//			if (matrix18.f[i] != 1.0f)
//			{
//				failure = true;
//				break;
//			}
//		}
//		else
//		{
//			if (matrix18.f[i] != 0.0f)
//			{
//				failure = true;
//				break;
//			}
//		}
//	}
//	for (char i = 0; i < 3; i++)
//	{
//		if (matrix18.translation.f[i] != i * 5.0f)
//		{
//			failure = true;
//			break;
//		}
//	}
//	cout << "Test 18: CreateTranslation: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 19: Create Scale
//	Matrix44 matrix19 = Matrix44::CreateScale(matrix0_1.zAxis);
//
//	failure = false;
//	for (char i = 0; i < 15; i++)
//	{
//		if (i % 5 == 0)
//		{
//			if (matrix19.f[i] != matrix0_1.f[8 + (i / 5)])
//			{
//				failure = true;
//				break;
//			}
//		}
//		else
//		{
//			if (matrix19.f[i] != 0.0f)
//			{
//				failure = true;
//				break;
//			}
//		}
//	}
//	if (matrix19.f[15] != 1.0f) {
//		failure = true;
//	}
//	cout << "Test 19: Create Scale: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 20: CreateRotate
//	float angle20 = Pi / 6.0f;
//	float sin20 = std::sin(angle20);
//	float cos20 = std::cos(angle20);
//	Vector3 vector20;
//
//	vector20.x = 4.0f;
//	vector20.y = 3.0f;
//	vector20.z = 5.0f;
//
//	Matrix44 matrix20 = Matrix44::CreateRotate(angle20, vector20);
//	float matrix20_check[] =
//	{
//		16.0f - 15 * cos20, 12.0f - 12 * cos20 + 5 * sin20, 20.0f - 20 * cos20 - 3 * sin20, 0.0f,
//		12.0f - 12 * cos20 - 5 * sin20, 9.0f - 8 * cos20, 15.0f - 15 * cos20 + 4 * sin20, 0.0f,
//		20.0f - 20 * cos20 + 3 * sin20, 15.0f - 15 * cos20 - 4 * sin20, 25.0f - 24 * cos20, 0.0f,
//		0.0f, 0.0f, 0.0f, 1.0f
//	};
//
//	failure = false;
//	for (char i = 0; i < 16; i++)
//	{
//		if (abs(matrix20.f[i] - matrix20_check[i]) > epsilon)
//		{
//			failure = true;
//			break;
//		}
//	}
//	cout << "Test 20: CreateRotate: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//
//		for (int i = 0; i < 16; i++)
//		{
//			cout << matrix20_check[i] << ", ";
//		}
//		cout << endl;
//
//		for (int row = 0; row < 4; row++)
//		{
//			for (int col = 0; col < 4; col++)
//			{
//				cout << matrix20.m[row][col] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//
//	///Test 21: CreateRotateX
//	Matrix44 matrix21 = Matrix44::CreateRotateX(1.3755f);
//	float matrix21_check[] =
//	{
//		1.0f,		0.0f		,		0.0f		, 0.0f,
//		0.0f,  std::cos(1.3755f),   std::sin(1.3755f), 0.0f,
//		0.0f,  -std::sin(1.3755f),  std::cos(1.3755f), 0.0f,
//		0.0f,		0.0f		,		 0.0f 		 , 1.0f
//	};
//
//	failure = false;
//	for (char i = 0; i < 16; i++)
//	{
//		if (abs(matrix21.f[i] - matrix21_check[i]) > epsilon)
//		{
//			failure = true;
//			break;
//		}
//	}
//
//	cout << "Test 21: CreateRotateX: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//
//		for (int row = 0; row < 16; row++)
//		{
//			cout << matrix21_check[row] << ", ";
//		}
//		cout << endl;
//
//		for (int row = 0; row < 4; row++)
//		{
//			for (int col = 0; col < 4; col++)
//			{
//				cout << matrix21.m[row][col] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl;
//
//	}
//
//	///Test 22: CreateRotateY:
//	Matrix44 matrix22 = Matrix44::CreateRotateY(2.7513f);
//	float matrix22_check[] =
//	{
//		std::cos(2.7513f), 0.0f, -std::sin(2.7513f), 0.0f,
//		0.0f		      , 1.0f,		0.0f	    , 0.0f,
//		std::sin(2.7513f), 0.0f,   std::cos(2.7513f), 0.0f,
//		0.0f			  ,	0.0f,		0.0f	    , 1.0f
//	};
//	failure = false;
//	for (char i = 0; i < 16; i++)
//	{
//		if (abs(matrix22.f[i] - matrix22_check[i]) > epsilon)
//		{
//			failure = true;
//			break;
//		}
//	}
//	cout << "Test 22: CreateRotateY: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 23: CreateRotateZ
//	Matrix44 matrix23 = Matrix44::CreateRotateZ(1.6258f);
//	float matrix23_check[] =
//	{
//		std::cos(1.6258f),   std::sin(1.6258f), 0.0f, 0.0f,
//		-std::sin(1.6258f),   std::cos(1.6258f), 0.0f, 0.0f,
//		0.0f	   ,			0.0f	   , 1.0f, 0.0f,
//		0.0f	   ,			0.0f	   , 0.0f, 1.0f
//	};
//	failure = false;
//	for (char i = 0; i < 16; i++)
//	{
//		if (abs(matrix23.f[i] - matrix23_check[i]) > epsilon)
//		{
//			failure = true;
//			break;
//		}
//	}
//	cout << "Test 23: CreateRotateZ: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 24: CreateOrtho
//	Matrix44 matrix24 = Matrix44::CreateOrtho(1.0f, 5.0f, 3.0f, 8.0f, 4.0f, 12.0f);
//	float matrix24_check[] =
//	{
//		0.50f,  0.00f,   0.00f,  0.00f,
//		0.00f,  0.40f,   0.00f,  0.00f,
//		0.00f,  0.00f,  -0.25f,  0.00f,
//		-1.50f, -2.20f,  -2.00f,  1.00f
//	};
//
//	failure = false;
//	for (char i = 0; i < 16; i++)
//	{
//		if (abs(matrix24.f[i] - matrix24_check[i]) > epsilon)
//		{
//			failure = true;
//			break;
//		}
//	}
//
//	cout << "Test 24: CreateOrtho: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 25: CreateFrustum
//	Matrix44 matrix25 = Matrix44::CreateFrustum(1.0f, 5.0f, 3.0f, 8.0f, 4.0f, 12.0f);
//	float matrix25_check[] =
//	{
//		2.0f, 0.0f,   0.0f,  0.0f,
//		0.0f, 1.6f,   0.0f,  0.0f,
//		1.5f, 2.2f,  -2.0f, -1.0f,
//		0.0f, 0.0f, -12.0f,  0.0f
//	};
//	failure = false;
//	for (char i = 0; i < 16; i++)
//	{
//		if (abs(matrix25.f[i] - matrix25_check[i]) > epsilon)
//		{
//			failure = true;
//			break;
//		}
//	}
//	cout << "Test 25: CreateFrustum: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 26: CreatePerspective
//	Matrix44 matrix26 = Matrix44::CreatePerspective(2.0f, 2.0f, 3.0f, 7.0f);
//	float x = cos(1.0f) / sin(1.0f);
//	float matrix26_check[] =
//	{
//		x / 2.0f, 0.0f,   0.0f,  0.0f,
//		0.0f,	 x,   0.0f,  0.0f,
//		0.0f, 0.0f,	 -2.5f, -1.0f,
//		0.0f, 0.0f, -10.5f,  0.0f
//	};
//
//	failure = false;
//	for (char i = 0; i < 16; i++)
//	{
//		if (abs(matrix26.f[i] - matrix26_check[i]) > epsilon)
//		{
//			failure = true;
//			break;
//		}
//	}
//	cout << "Test 26: CreatePerspective: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//
//	///Test 27: CreateLookAt
//	Vector3 vector27_1;
//	Vector3 vector27_2;
//	Vector3 vector27_3;
//
//
//	vector27_1.x = 3.0f;
//	vector27_1.y = 2.0f;
//	vector27_1.z = 5.0f;
//	vector27_2.x = 6.0f;
//	vector27_2.y = 1.0f;
//	vector27_2.z = 8.0f;
//	vector27_3.x = 7.0f;
//	vector27_3.y = 9.0f;
//	vector27_3.z = 4.0f;
//
//	Matrix44 matrix27 = Matrix44::CreateLookAt(vector27_1, vector27_2, vector27_3);
//	float matrix27_check[] =
//	{
//		-0.661222875f,  0.298496485f, -0.688247204f, 0.0f,
//		0.191967934f,  0.954210043f,  0.229415730f, 0.0f,
//		0.725212157f, 0.0195735246f, -0.688247204f, 0.0f,
//		-2.02632809f,  -2.90177727f,   5.04714632f, 1.0f
//	};
//
//	failure = false;
//	for (char i = 0; i < 16; i++)
//	{
//		if (abs(matrix27.f[i] - matrix27_check[i]) > epsilon)
//		{
//			failure = true;
//			break;
//		}
//	}
//	cout << "Test 27: CreateLookAt: ";
//	if (!failure)
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//
//		for (int row = 0; row < 16; row++)
//		{
//			cout << matrix27_check[row] << ", ";
//		}
//		cout << endl;
//
//		for (int row = 0; row < 4; row++)
//		{
//			for (int col = 0; col < 4; col++)
//			{
//				cout << matrix27.m[row][col] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//
//	///Test 28: TransformDirectionVector
//	Vector3 vector28_1;
//	Vector3 vector28_2;
//
//	vector28_2.x = 8.0f;
//	vector28_2.y = 5.0f;
//	vector28_2.z = -6.0f;
//	vector28_1 = matrix0_1.TransformDirectionVector(vector28_2);
//	cout << "Test 28: TransformDirectionVector: ";
//
//	if ((vector28_1.x == -11.0f) && (vector28_1.y == 21.0f) && (vector28_1.z == -9.0f))
//	{
//		cout << "OK\n";
//	}
//	else
//	{
//		cout << "FAILED\n";
//	}
//}
//
//int main()
//{
//	Vector3Test();
//
//	Matrix44Test();
//
//	cin.get();
//
//	return 0;
//}
//
////#include "Vector3.h"
////#include "Matrix44.h"
////
////#include <iostream>
////
////using namespace std;
////using namespace igad;
////
//void PrintMatrix(Matrix44 matrix)
//{
//	cout << endl << "Matrix: " << endl;
//
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			cout << matrix.m[i][j] << "      ";
//		}
//		cout << endl;
//	}
//
//	cout << endl;
//
//}
////
////void Vector3Test()
////{
////	cout << "Vector3 test: \n\n";
////	///Test 1: Default constructor
////	Vector3 vector1;
////
////	cout << "Test 1: Default constructor: ";
////	if (vector1.x == vector1.y == vector1.z == 0)
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 2: Constructor with given components
////	Vector3 vector2(10.0f, 30.0f, 50.0f);
////
////	cout << "Test 2: Constructor with given components: ";
////	if((vector2.x == 10.0f) && (vector2.y == 30.0f) && (vector2.z == 50.0f))
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 3: Operator+
////	Vector3 vector3_1;
////	Vector3 vector3_2;
////
////	vector3_1.x = 1.0f;
////	vector3_1.y = 3.0f;
////	vector3_1.z = 5.0f;
////	vector3_2.x = 2.0f;
////	vector3_2.y = 4.0f;
////	vector3_2.z = 6.5f;
////
////	Vector3 vector3 = vector3_1 + vector3_2;
////
////	cout << "Test 3: Operator+: ";
////	if((vector3.x == 3.0f) && (vector3.y == 7.0f) && (vector3.z == 11.5f))
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 4: Operator-
////	Vector3 vector4_1;
////	Vector3 vector4_2;
////
////	vector4_1.x = 10.0f;
////	vector4_1.y = 20.0f;
////	vector4_1.z = 30.0f;
////	vector4_2.x = 5.0f;
////	vector4_2.y = 10.0f;
////	vector4_2.z = 15.5f;
////
////	Vector3 vector4 = vector4_1 - vector4_2;
////
////	cout << "Test 4: Operator-: ";
////	if((vector4.x == 5.0f) && (vector4.y == 10.0f) && (vector4.z == 14.5f))
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 5: Operaator*
////	Vector3 vector5;
////
////	vector5.x = 2.0f;
////	vector5.y = 4.0f;
////	vector5.z = 8.0f;
////	vector5 = vector5 * 3.5f;
////	cout << "Test 5: Operaator*: ";
////	if((vector5.x == 7.0f) && (vector5.y == 14.0f) && (vector5.z == 28.0f))
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 6: Operator/
////	Vector3 vector6;
////
////	vector6.x =  9.0f;
////	vector6.y = 15.0f;
////	vector6.z = 18.0f;
////	vector6 = vector6 / 3.0f;
////	cout << "Test 6: Operator/: ";
////	if((vector6.x == 3.0f) && (vector6.y == 5.0f) && (vector6.z == 6.0f))
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 7: Operator- (negative vector)
////	Vector3 vector7;
////
////	vector7.x = 5.0f;
////	vector7.y = 6.0f;
////	vector7.z = 7.0f;
////	vector7 = -vector7;
////	cout << "Test 7: Operator- (negative vector): ";
////	if((vector7.x == -5.0f) && (vector7.y == -6.0f) && (vector7.z == -7.0f))
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 8: Operator* (dot product)
////	Vector3 vector8_1;
////	Vector3 vector8_2;
////
////	vector8_1.x =  3.0f;
////	vector8_1.y =  5.0f;
////	vector8_1.z =  7.7f;
////	vector8_2.x =  1.0f;
////	vector8_2.y =  2.0f;
////	vector8_2.z = 10.0f;
////
////	float dot8 = vector8_1 * vector8_2;
////	
////	cout << "Test 8: Operator* (dot product): ";
////	if(dot8 == 90.0f)
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 9: Operator+=
////	Vector3 vector9_1;
////	Vector3 vector9_2;
////
////	vector9_1.x = 7.0f;
////	vector9_1.y = 3.0f;
////	vector9_1.z = 6.0f;
////	vector9_2.x = 3.7f;
////	vector9_2.y = 6.3f;
////	vector9_2.z = 7.6f;
////	vector9_1 += vector9_2;
////	cout << "Test 9: Operator+=: ";
////	if((vector9_1.x == 10.7f) && (vector9_1.y == 9.3f) && (vector9_1.z == 13.6f))
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 10: Operator-=
////	Vector3 vector10_1;
////	Vector3 vector10_2;
////
////	vector10_1.x = 12.3;
////	vector10_1.y = 45.6;
////	vector10_1.z = 78.9;
////	vector10_2.x = 5.5f;
////	vector10_2.y = 10.1f;
////	vector10_2.z = 20.2f;
////	vector10_1 -= vector10_2;
////	cout << "Test 10: Operator-=: ";
////	if((vector10_1.x == 6.8f) && (vector10_1.y == 35.5f) && (vector10_1.z == 58.7f))
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 11: Operator*=
////	Vector3 vector11;
////	
////	vector11.x =  14.0f;
////	vector11.y = -24.0f;
////	vector11.z =  34.0f;
////	vector11 *= -2.0f;
////	cout << "Test 11: Operator *=: ";
////	if((vector11.x == -28.0f) && (vector11.y == 48.0f) && (vector11.z == -68.0f))
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 12: Cross
////	Vector3 vector12_1;
////	Vector3 vector12_2;
////
////	vector12_1.x =  3.0f;
////	vector12_1.y =  6.0f;
////	vector12_1.z = 12.0f;
////	vector12_2.x = 16.0f;
////	vector12_2.y =  8.0f;
////	vector12_2.z =  4.0f;
////
////	Vector3 vector12 = vector12_1.Cross(vector12_2);
////
////	cout << "Test 13: Cross: ";
////	if ((vector12.x == -72.0f) && (vector12.y == 180.0f) && (vector12.z == -72.0f))
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 13: Dot
////	Vector3 vector13_1;
////	Vector3 vector13_2;
////
////	vector13_1.x = 15.0f;
////	vector13_1.y = 11.0f;
////	vector13_1.z =  8.0f;
////	vector13_2.x =  3.0f;
////	vector13_2.y =  4.0f;
////	vector13_2.z =  7.0f;
////
////	float dot13 = vector13_1.Dot(vector13_2);
////
////	cout << "Test 13: Dot: ";
////	if(dot13 == 145.0f)
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 14: Magnitude
////	Vector3 vector14;
////
////	vector14.x = 3.0f;
////	vector14.y = 12.0f;
////	vector14.z = 4.0f;
////
////	float mag14 = vector14.Magnitude();
////
////	cout << "Test 14: Magnitude: ";
////	if(mag14 == 13.0f)
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 15: SquareMagnitude
////	Vector3 vector15;
////
////	vector15.x =  3.0f;
////	vector15.y =  8.0f;
////	vector15.z = 10.0f;
////
////	float sqrMag15 = vector15.SquareMagnitude();
////
////	cout << "Test 15: SquareMagnitude: ";
////	if(sqrMag15 == 173.0f)
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 16: Normalize
////	Vector3 vector16;
////
////	vector16.x = 3.0f;
////	vector16.y = 4.0f;
////	vector16.z = 12.0f;
////	vector16.Normalize();
////	cout << "Test 16: Normalize: ";
////	if((vector16.x == 3.0f / 13.0f) && (vector16.y == 4.0f / 13.0f) && (vector16.z == 12.0f / 13.0f))
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 17: Operator==
////	Vector3 vector17_1;
////	Vector3 vector17_2;
////
////	vector17_1.x = 2.0f;
////	vector17_1.y = 5.0f;
////	vector17_1.z = 4.4f;
////	vector17_2.x = 2.0f;
////	vector17_2.y = 5.0f;
////	vector17_2.z = 4.4f;
////
////	cout << "Test 17: Operator==: ";
////	if(vector17_1 == vector17_2)
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 18: Operator==
////	Vector3 vector18_1;
////	Vector3 vector18_2;
////
////	vector18_1.x = 2.0f;
////	vector18_1.y = 5.0f;
////	vector18_1.z = 4.4f;
////	vector18_2.x = 2.0f;
////	vector18_2.y = 5.0f;
////	vector18_2.z = 4.4f;
////
////	cout << "Test 17: Operator==: ";
////	if(vector18_1 == vector18_2)
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 19: Operator !=
////	Vector3 vector19_1;
////	Vector3 vector19_2;
////	Vector3 vector19_3;
////
////	vector19_1.x =  6.0f;
////	vector19_1.y = 18.0f;
////	vector19_1.z =  2.0f;
////	vector19_2.x =  6.0f;
////	vector19_2.y =  8.0f;
////	vector19_2.z =  2.0f;
////	vector19_3.x =  5.0f;
////	vector19_3.y = 18.0f;
////	vector19_3.z = 14.0f;
////
////	cout << "Test 19: Operator!=: ";
////	if (!(vector19_1 != vector19_1) && (vector19_1 != vector19_2) && (vector19_1 != vector19_3) && (vector19_2 != vector19_3))
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	///Test 20: Clear
////	Vector3 vector20;
////
////	vector20.x = 1.1f;
////	vector20.x = 2.2f;
////	vector20.z = 3.3f;
////	vector20.Clear();
////	cout << "Test 19: Clear: ";
////	if(vector20.x == vector20.y == vector20.z == 0.0f)
////	{
////		cout << "OK\n";
////	}
////	else
////	{
////		cout << "FAILED\n";
////	}
////
////	cout << endl;
////}
////
////void MatrixTest()
////{
////	//2x2 <-----------------------------------------------------------------------
////	cout << "Testing 2x2 determinant" << endl;
////
////	Matrix22 mat22 = Matrix22(10.f, 8.f, 2.f, 4.f);
////
////	float det22 = mat22.Determinant();
////
////	if (det22 == 24.f)
////	{
////		cout << "Test PASSED." << endl;
////	}
////	else {
////		cout << "Test FAILED." << endl;
////	}
////
////	cout << "Your determinant was: " << det22 << endl << endl;
////
////	//3x3 <-----------------------------------------------------------------------
////	cout << "Testing 3x3 determinant" << endl;
////
////	Matrix33 mat33 = Matrix33(10.f, 8.f, 12.f, 2.f, 4.f, 5.f, 25.f, 2.f, 25.f);
////
////	float det33 = mat33.Determinant();
////
////	if (det33 == 347.9999999999999f)
////	{
////		cout << "Test PASSED." << endl;
////	}
////	else {
////		cout << "Test FAILED." << endl;
////	}
////
////	cout << "Your determinant was: " << det33 << endl << endl;
////
////	//Identity <-----------------------------------------------------------------------
////	cout << "Testing identity matrix" << endl;
////
////	Matrix44 identityMatrix = Matrix44();
////
////	PrintMatrix(identityMatrix);
////
////	//Determinant 4x4 <-----------------------------------------------------------------------
////	cout << "Testing determinant: " << endl;
////
////	Matrix44 matrix = Matrix44(10.0f, 8.f, 12.f, 0.f,
////								2.f, 4.f, 5.f, 80.f,
////								25.f, 2.f, 25.f, 61.f,
////								40.f, 96.f, 7.f, 3.f);
////
////	PrintMatrix(matrix);
////
////	bool failed = false;
////
////	float det = matrix.Determinant();
////
////	if (det == 1008972.f)
////	{
////		cout << "1 OK, ";
////	}
////	else {
////		cout << "1 FAILED, ";
////	}
////
////	cout << "Determinant calculated as: " << det << ", " << endl;
////
////	matrix = Matrix44(2.0f, 5.f, 9.f, 7.f,
////		0.f, 4.f, 5.f, 6.f,
////		5.f, 9.f, 0.f, 1.f,
////		3.f, 2.f, 7.f, 2.f);
////
////	PrintMatrix(matrix);
////
////	det = matrix.Determinant();
////
////	if (det == 70)
////	{
////		cout << "2 OK, ";
////	}
////	else {
////		cout << "2 FAILED, ";
////	}
////
////	cout << "Determinant calculated as: " << det << endl << endl;
////
////	//Matrix of minors <-----------------------------------------------------------------------
////	/*PrintMatrix(matrix);
////
////	if (matrix.f[0] == 2.f && matrix.f[1] == 0.f && matrix.f[2] == 5.f && matrix.f[3] == 3.f &&
////		matrix.f[4] == 5.f && matrix.f[5] == 4.f && matrix.f[6] == 9.f && matrix.f[7] == 2.f &&
////		matrix.f[8] == 9.f && matrix.f[9] == 5.f && matrix.f[10] == 0.f && matrix.f[11] == 7.f &&
////		matrix.f[12] == 7.f && matrix.f[13] == 6.f && matrix.f[14] == 1.f && matrix.f[15] == 2.f)
////	{
////		cout << "Test PASSED, matrix transposed correctly." << endl;
////	}
////	else {
////		cout << "Test FAILED." << endl;
////	}*/
////
////	//Cofactor <-----------------------------------------------------------------------
////
////
////	//Transpose <-----------------------------------------------------------------------
////	cout << "Testing transpose" << endl;
////
////	matrix.Transpose();
////
////	PrintMatrix(matrix);
////
////	if (matrix.f[0] == 2.f && matrix.f[1] == 0.f && matrix.f[2] == 5.f && matrix.f[3] == 3.f &&
////		matrix.f[4] == 5.f && matrix.f[5] == 4.f && matrix.f[6] == 9.f && matrix.f[7] == 2.f &&
////		matrix.f[8] == 9.f && matrix.f[9] == 5.f && matrix.f[10] == 0.f && matrix.f[11] == 7.f &&
////		matrix.f[12] == 7.f && matrix.f[13] == 6.f && matrix.f[14] == 1.f && matrix.f[15] == 2.f)
////	{
////		cout << "Test PASSED, matrix transposed correctly." << endl;
////	}
////	else {
////		cout << "Test FAILED." << endl;
////	}
////
////	//Inverse <-----------------------------------------------------------------------
////	cout << endl << "Testing Inverse" << endl;
////
////	matrix = Matrix44(2.0f, 5.f, 9.f, 7.f,
////		0.f, 4.f, 5.f, 6.f,
////		5.f, 9.f, 0.f, 1.f,
////		3.f, 2.f, 7.f, 2.f);
////
////	cout << "Matrix can be inverted: " << matrix.Invert() << endl;
////
////	PrintMatrix(matrix);
////
////	if (matrix.f[0] == 3.85714285714286f && matrix.f[1] == -3.74285714285714f && matrix.f[2] == 0.0285714285714288f && matrix.f[3] == -2.28571428571428f &&
////		matrix.f[4] == -2.5f && matrix.f[5] == 2.4 && matrix.f[6] == 0.0999999999999999f && matrix.f[7] == 1.5f &&
////		matrix.f[8] == -1.85714285714286f && matrix.f[9] == 1.74285714285714f && matrix.f[10] == -0.0285714285714286f && matrix.f[11] == 1.28571428571429f &&
////		matrix.f[12] == 3.21428571428571f && matrix.f[13] == -2.88571428571429f && matrix.f[14] == -0.0428571428571429f && matrix.f[15] == -2.07142857142857f)
////	{
////		cout << "Test PASSED, matrix inverted correctly." << endl;
////	}
////	else {
////		cout << "Test FAILED." << endl;
////	}
////
////}
////
////
////
////int main()
////{	
////	Vector3Test();
////
////	MatrixTest();
////
////	cin.get();
////	
////	return 0;
////}
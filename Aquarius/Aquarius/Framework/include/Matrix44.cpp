#include "Matrix44.h"
#include <math.h> // includes the sin and cos functions.
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#define PI 3.14159265

using namespace igad;

//Initialises a matrix44 object taking values from a glm mat4 object
igad::Matrix44::Matrix44(glm::mat4 a_mat)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m[i][j] = a_mat[i][j];
		}
	}
	
}

glm::mat4 igad::Matrix44::convertToglmMatrix(Matrix44 m)
{

	glm::mat4 m4;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m4[i][j] = m.m[i][j];
		}
	}


	return m4;
}

glm::vec3 igad::Matrix44::importFrom(Vector3 v3)
{	
	glm::vec3 vector3_glm = glm::vec3(v3.x, v3.y, v3.z);
	return vector3_glm;
}



void igad::Matrix44::printMatrix(Matrix44 myMatrix)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << myMatrix.m[i][j] << " ";
		}

		std::cout << "\n";
	}
	std::cout << "\n\n";
}

Matrix44::Matrix44(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13,
	float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33)
{
	m[0][0] = m00;
	m[1][0] = m10;
	m[2][0] = m20;
	m[3][0] = m30;

	m[0][1] = m01;
	m[1][1] = m11;
	m[2][1] = m21;
	m[3][1] = m31;

	m[0][2] = m02;
	m[1][2] = m12;
	m[2][2] = m22;
	m[3][2] = m32;

	m[0][3] = m03;
	m[1][3] = m13;
	m[2][3] = m23;
	m[3][3] = m33;
	
}

igad::Matrix44::Matrix44()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
			{
				m[i][j] = 1;
			}
			else
			{
				m[i][j] = 0;
			}
		}
	}
}

Vector3 igad::Matrix44::operator*(const Vector3 & vec) const
{
	Vector3 product;

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (row == 0)
			{
				if (col == 0)
					product.x += this->m[row][col] * vec.x;
				if (col == 1)
					product.x += this->m[row][col] * vec.y;
				if (col == 2)
					product.x += this->m[row][col] * vec.z;
				if (col == 3)
					product.x += this->m[row][col] * 1;
			}

			if (row == 1)
			{
				if (col == 0)
					product.y += this->m[row][col] * vec.x;
				if (col == 1)
					product.y += this->m[row][col] * vec.y;
				if (col == 2)
					product.y += this->m[row][col] * vec.z;
				if (col == 3)
					product.y += this->m[row][col] * 1;
			}

			if (row == 2)
			{
				if (col == 0)
					product.z += this->m[row][col] * vec.x;
				if (col == 1)
					product.z += this->m[row][col] * vec.y;
				if (col == 2)
					product.z += this->m[row][col] * vec.z;
				if (col == 3)
					product.z += this->m[row][col] * 1;
			}
		}
	}
	return product;
}

Matrix44 igad::Matrix44::operator+(const Matrix44 & mat) const
{
	Matrix44 sum;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sum.m[i][j] = this->m[i][j] + mat.m[i][j];
		}
	}	
	return sum;
}

void igad::Matrix44::print(Matrix44 myMatrix)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << myMatrix.m[i][j] << " ";
		}
		std::cout << "\n";
	}
}

Matrix44 igad::Matrix44::operator-(const Matrix44 & mat) const
{
	Matrix44 subtraction;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			subtraction.m[i][j] = this->m[i][j] - mat.m[i][j];
		}
	}

	return subtraction;
}

Matrix44 igad::Matrix44::operator*(const Matrix44 & mat) const
{

	Matrix44 product;
	for (int column = 0; column < 4; column++)
	{
		for (int row = 0; row < 4; row++)
		{
		
		
			product.m[column][row] = 0;
			for (int iteration = 0; iteration < 4; iteration++)
			{
				product.m[column][row] += this->m[column][iteration]* mat.m[iteration][row];
			}
		}
	}

	

	return product;
}

Vector3 igad::Matrix44::GetTranslation() const
{
	return this->translation;
}

void igad::Matrix44::SetTranslation(const Vector3 & vec)
{
	this->translation = vec;
}

Vector3 igad::Matrix44::GetXAxis() const
{
	return this->xAxis;
}

Vector3 igad::Matrix44::GetYAxis() const
{
	return this->yAxis;
}

Vector3 igad::Matrix44::GetZAxis() const
{
	return this->zAxis;
}

float igad::Matrix44::Determinant(Matrix44 &identity_44, bool inverse) const
{
	//std::cout << "*****entered Determinant()\n\n";
	
	float copy[4][4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			copy[i][j] = this-> m[i][j];
		}
	}

	float det = 1;
	float factor = 0;
	int shift = 0;
	float signal = 1;

	//int o = 0;
	//gaussian elimination

	//First we will do mathematical manipulation on the rows of the matrix in order to have a upper triangular matrix.
	//initialise(m);
	/*std::cout << "Original matrix at the start of the calculate det function: \n";
	print(m);*/

	//Change start to n so it can be useful with other sized matrices




	for (int start = 0; start < 3; start++)
	{
		//divides all row elements by the diagonal element so the element becomes 1. Only done when the goal is to obtain
		//a inverse matrix by gaussian elimination.
	



		for (int row = start + 1; row < 4; row++)
		{

			//reorders rows in case the diagonal member is zero, then changes the determinant signal to negative.
			if (copy[start][start] == 0)
			{
				//std::cout << "reordering...\n";
				while (shift + start < 3 && copy[start][start] == 0)
				{
					shift++;
					//cout << "loop\n";

					for (int col = 0; col < 4; col++)
					{
						int temp = copy[start + shift][col];
						copy[start + shift][col] = copy[start][col];
						copy[start][col] = temp;
						signal = -1;

						//For identity matrix:
						if (inverse)
						{

							int temp2 = identity_44.m[start + shift][col];
							identity_44.m[start + shift][col] = identity_44.m[start][col];
							identity_44.m[start][col] = temp2;
							signal = -1;
						}

					}
				}

				/*cout << "Original matrix after reordering.\n";
				print(m);*/

				/*if (inverse)
				{
					cout << "Inverse Matrix after reordering.\n";

					print(identity_44);
				}*/
			}

			if (inverse && copy[start][start] != 0)
			{
				float common_divisor = copy[start][start];

				for (int j = 0; j < 4; j++)
				{

					copy[start][j] = copy[start][j] / common_divisor;

					identity_44.m[start][j] = identity_44.m[start][j] / common_divisor;
				}
				/*cout << "\n\nIdentity matrix before the start loop: " << start << "\n";
				print(identity_44);*/
			}
			/*cout << "Original matrix before the start loop: " << start << "\n";
			print(m);*/


		/*	std::cout << "\n\nOriginal matrix at the beginning of the row loop." << row << "\n";
			
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					std::cout << copy[i][j] << " ";
				}
				std::cout << "\n";
			}

			std::cout << "\n\n";*/

			//std::cout << "Identity matrix at the beginning of the row loop." << row << "\n";
			//print(identity_44);

			//If the first member of the new row to be changed is already zero, skip this step.
			if (copy[row][start] != 0 && copy[start][start] != 0)
			{

				factor = -copy[row][start] / copy[start][start];
				//cout << "\nfactor: " << factor << "\n";
				for (int col = 0; col < 4; col++)
				{
					/*cout << "Original matrix at the beginning of the col loop." << col << "\n";
					print(m);
					cout << "Identity matrix at the beginning of the col loop." << col << "\n";
					print(identity_44);*/

					if (col == start)
					{

					}
					/*cout << "m[start][col] = " << m[start][col] << " \n ";
					cout << "product: " << factor*m[start][col] << "\n";*/
					float product = factor*copy[start][col];
					copy[row][col] = copy[row][col] + product;

					if (inverse)
					{

						//co << "factor2 = " << factor << " identity_44[start][col] = " << identity_44[row][col] << "\n";
						float product2 = factor*identity_44.m[start][col];
						//cout << "\n product2 = " << product2 << "\n";
						identity_44.m[row][col] = identity_44.m[row][col] + product2;
						//cout << "\nidentity_44[" << row << "][" << col << "] = " << identity_44[row][col] << "\n";
					}
					//print(m);
				}
			}
		}

		if (inverse)
		{


			if (start == 2 && copy[3][3] != 0)
			{
				float common_divisor = copy[3][3];
				copy[3][3] = copy[3][3] / common_divisor;

				//cout << "\divides all of the last row's elements by the last diagonal member of the original matrix: \n";
				for (int j = 0; j < 4; j++)
				{

					identity_44.m[3][j] = identity_44.m[3][j] / common_divisor;
				}

				/*cout << "Inverse Matrix after last diagonal's simplification: \n";
				print(identity_44);*/

				/*std::cout << "Original Matrix with a diagonal equal to 1: \n";
				
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						std::cout << copy[i][j] << " ";
					}
					std::cout << "\n";
				}*/

			}
		}



	}


	//this* = std::move(result);
	

	//After we have a upper triangular matrix, the last step is to multiply the terms in the main diagonal.

	for (int counter = 0; counter < 4; counter++)
	{
		det *= copy[counter][counter];
	}

	det *= signal;
	//std::cout << "det: " << det << "\n";

	if (inverse && det != 0)
	{
		//std::cout << "***left Determinant() \n\n";

		/**Obtaining a lower traingular matrix:*/
		float factor = 0;

		for (int start = 3; start > 0; start--)
		{
			//std::cout << "start: " << start << "\n";

			for (int row = start - 1; row >= 0; row--)
			{

				/*std::cout << "**beginning of row loop: " << row << "\n";
				cout << "Original Matrix: \n";
				print(m);
				cout << "Identity Matrix: \n";
				print(identity_44);*/

				//If the first member of the new row to be changed is already zero, skip this step.
				if (copy[row][start] != 0)
				{
					factor = -copy[row][start] / copy[start][start];
					//cout << "\nfactor defined: " << factor << "\n";

					for (int col = 3; col >= 0; col--)
					{

						/*cout << "beginning of col loop: " << col << "\n";
						cout << "Original Matrix: \n";
						print(m);
						cout << "Identity Matrix: \n";
						print(identity_44);

						cout << "\nfactor: " << factor << "\n";
						cout << "m[start][col] = " << m[start][col] << " \n ";
						cout << "product: " << factor*m[start][col] << "\n";*/

						float product = 0;
						product = factor*copy[start][col];
						//cout << "m["<< row << "]["<<col<<"] = " << m[row][col];
						copy[row][col] = copy[row][col] + product;

						float product2 = factor*identity_44.m[start][col];
						identity_44.m[row][col] = identity_44.m[row][col] + product2;
						//m[row][col] = m[row][col]/1;
						//cout << "\nm["<< row << "]["<<col << "] = " << m[row][col] << "\n ";
					}
				}
			}

		}
		//std::cout << "Original Matrix finally equal to Identity matrix: \n";
		////print(copy);
		//for (int i = 0; i < 4; i++)
		//{
		//	for (int j = 0; j < 4; j++)
		//	{
		//		std::cout << copy[i][j] << " ";
		//	}
		//	std::cout << "\n";
		//}
		//std::cout << "\n Inverse Matrix...\n";
		////print(identity_44);

		//for (int i = 0; i < 4; i++)
		//{
		//	for (int j = 0; j < 4; j++)
		//	{
		//		std::cout << identity_44.m[i][j] << " ";
		//	}
		//	std::cout << "\n";
		//}
	}


	return det;
}

/*Obtains the inverse matrix by gaussian elimination. Makes use of determinant function, which already 
Creates a upper triangular matrix by Gaussian elimination.*/
bool igad::Matrix44::Invert()
{
	
	Matrix44 identity_44;

	if (Determinant(identity_44, true) != 0)
	{		

		*this = std::move(identity_44);
		return true;
	}

	return false;
}



void igad::Matrix44::Transpose()
{
	/*In order to scan through the matrix swapping values from rows to columns
	*Im creating two loops: 
	*
	*1-The first is the 'iteration' loop. In this loop the variable 'iteration' determines 
	*which diagonal element is being looked at to swap the row and column values to the right and below
	*it.
	*
	*2-The second loop is the 'position' loop, located inside the first loop curly brackets, responsible for 
	skipping along the selected rows and columns respective to  the diagonal element selected by the iteration loop.
	* 
	*The values will be swapped using an integer hold value.
	*/

	for (int iter = 0; iter < 3; iter++)
	{
		float hold = 0;
		
		for (int pos = iter + 1; pos < 4; pos++)
		{
			hold = this->m[pos][iter];
			this->m[pos][iter] = this->m[iter][pos];
			this-> m[iter][pos] = hold;
		}
	}


}

void igad::Matrix44::SetOrientation(const Vector3 & x, const Vector3 & y, const Vector3 & z)
{
	this->xAxis = x;
	this->yAxis = y;
	this->zAxis = z;
}

void igad::Matrix44::SetEulerAxis(float yaw, float pitch, float roll)
{
	

	Matrix44 xRotation = CreateRotateX(pitch);
	Matrix44 yRotation = CreateRotateY(yaw);
	Matrix44 zRotation = CreateRotateZ(roll);




	//How to set the rotation?
	Matrix44 rotation_zxy = yRotation*xRotation*zRotation;


	
	//Add translation 

	/*Matrix44 result = rotation_zxy;
	std::cout << "\n result: \n";
	printMatrix(result);
	result.m[3][0] += translation.x;
	result.m[3][1] += translation.y;
	result.m[3][2] += translation.z;
	result.m[3][3] += 1;
*/

	

	xAxis = rotation_zxy.GetXAxis();
	yAxis = rotation_zxy.GetYAxis();
	zAxis = rotation_zxy.GetZAxis();

	//std::cout << "xAxis.z = " << xAxis << "\n";
	
}

Matrix44 igad::Matrix44::CreateIdentity()
{
	Matrix44 identity_44;

	for (int i = 0; i <4; i++)
	{
		for (int j = 0; j <4; j++)
		{

			if (i == j)
			{
				identity_44.m[i][j] = 1;
			}
			else
			{
				identity_44.m[i][j] = 0;
			}
		}

	}

	return identity_44;
}

Matrix44 igad::Matrix44::CreateTranslation(float x, float y, float z)
{
	if(y != 0)
	std::cout << "createTranslation\n\n" << x << " " << y <<" " << z << "\n";
	Matrix44 translation_matrix = Matrix44(	1, 0, 0, 0,
											0, 1, 0, 0,
											0, 0, 1, 0,
											x, y, z, 1);
											
	return translation_matrix;
	
}

Matrix44 igad::Matrix44::CreateScale(Vector3 scale)
{
	Matrix44 mat;
	mat.f[0] = scale.x;
	mat.f[5] = scale.y;
	mat.f[10] = scale.z;
	mat.f[15] = 1;

	return mat;
}

Matrix44 igad::Matrix44::CreateRotate(float angle, const Vector3 & axis)
{
	/*angle = (float)angle*PI / 180;
	glm::mat4 trans;
	Matrix44 rotate(glm::rotate(trans, angle, glm::vec3(axis.x, axis.y, axis.z)));
	
	return rotate;*/
	return Matrix44();
}

Matrix44 igad::Matrix44::CreateRotateX(float pitch)
{
	float cos_x = (float)cos(pitch);
	float sin_x = (float)sin(pitch);

	//std::cout << "*****angle: " << pitch*PI / 180 << "\n";

	Matrix44 xRotation = Matrix44(1.0f, 0.0f, 0.0f, 0.0f,
								0.0f, cos_x, sin_x, 0.0f,
								0.0f, -sin_x, cos_x, 0.0f,
								0.0f, 0.0f, 0.0f, 1.0f);

	return xRotation;
}

Matrix44 igad::Matrix44::CreateRotateY(float yaw)
{
	float cos_y = (float)cos(yaw);
	float sin_y = (float)sin(yaw);

	Matrix44 yRotation = Matrix44(	cos_y, 0.0f, sin_y, 0.0f,
									0.0f, 1.0f, 0.0f, 0.0f,
									-sin_y, 0, cos_y, 0.0f,
									0.0f, 0.0f, 0.0f, 1.0f);

	return yRotation;
}

Matrix44 igad::Matrix44::CreateRotateZ(float roll)
{
	float cos_z = (float)cos(roll);
	float sin_z = (float)sin(roll);

	Matrix44 zRotation = Matrix44(cos_z, sin_z, 0.0f, 0.0f,
									-sin_z, cos_z, 0.0f, 0.0f,
									0.0f, 0.0f, 1.0f, 0.0f,
									0.0f, 0.0f, 0.0f, 1.0f);

	return zRotation;
}

Matrix44 igad::Matrix44::CreateOrtho(float left, float right, float bottom, float top, float nearZ, float farZ)
{
	Matrix44 ortho (glm::ortho(left, right, bottom, top, nearZ, farZ));
	return ortho;
}

Matrix44 igad::Matrix44::CreateFrustum(float left, float right, float bottom, float top, float nearZ, float farZ)
{
	Matrix44 frustum(glm::frustum(left, right,  bottom,  top,  nearZ,  farZ));
	return frustum;
}

Matrix44 igad::Matrix44::CreatePerspective(float fovy, float aspect, float nearZ, float farZ)
{
	Matrix44 perspective(glm::perspective(fovy, aspect, nearZ, farZ));
	return perspective;
}

Matrix44 igad::Matrix44::CreateLookAt(const Vector3 & eye, const Vector3 & center, const Vector3 & up)
{
	/*glm::vec3 v2;
	glm::vec3 v3 = v2;*/
	glm::vec3 v3_eye = importFrom(eye);
	glm::vec3 v3_center = importFrom(center);
	glm::vec3 v3_up = importFrom(up);
	
	Matrix44 lookAt(glm::lookAt(v3_eye, v3_center, v3_up));
	return lookAt;
}

Vector3 igad::Matrix44::TransformDirectionVector(const Vector3 & direction)
{
	Vector3 product;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 4; col++)
		{
		
		
			if (row == 0)
			{
				if (col == 0)
					product.x += this->m[col][row] * direction.x;
				if (col == 1)			 
					product.x += this->m[col][row] * direction.y;
				if (col == 2)			
					product.x += this->m[col][row] * direction.z;
				if (col == 3)			
					product.x += this->m[col][row] * 0;
			}							
			if (row == 1)				 
			{							
				if (col == 0)			 
					product.y += this->m[col][row] * direction.x;
				if (col == 1)			
					product.y += this->m[col][row] * direction.y;
				if (col == 2)			 
					product.y += this->m[col][row] * direction.z;
				if (col == 3)			
					product.y += this->m[col][row] * 0;
			}							

			if (row == 2)				
			{							
				if (col == 0)			 
					product.z += this->m[col][row] * direction.x;
				if (col == 1)			
					product.z += this->m[col][row] * direction.y;
				if (col == 2)			 
					product.z += this->m[col][row] * direction.z;
				if (col == 3)			
					product.z += this->m[col][row] * 0;
			}								
		}									 
	}										  

	//print product
	
	return product;
}





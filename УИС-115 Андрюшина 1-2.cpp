#include "Vector3D.h"

int main()
{
	Vector3D v(1, 2, 3);
	cout << v << endl;
	cout <<"Length = " <<v.get_vector_length() << endl;
}



#pragma once
#include <iostream>
#include <cmath>
using namespace std;
class Vector3D
{
private:
	double x;
	double y;
	double z;
public:
	/**
	 \brief	Конструктор
	 */
	explicit Vector3D(const double x, const double y, const double z);
	/**
	 \brief	Деструктор по умолчанию.
	 */
	~Vector3D() = default;
	/**
	 \brief	Конструктор копирования по умолчанию.
	 */
	Vector3D(const  Vector3D&) = default;
	/**
	 \brief	Конструктор присваивания по умолчанию.
	 */
	Vector3D& operator=(const  Vector3D&) = default;
	/**
	 \brief	Оператор сдвига
	 */
	friend ostream& operator<<(ostream& out, Vector3D& vec);
	/**
	 \brief	Оператор сложения 
	 */
	Vector3D operator+(const Vector3D& other);
	/**
	 \brief	Оператор вычитания 
	 */
	Vector3D operator-(const Vector3D& other);
	/**
	 \brief	Скалярное произведение векторов
	 */
	double operator*(const Vector3D& other);
	/**
	 \brief	Оператор умножения на число
	 */
	Vector3D operator*(const double a);
	/**
	 \brief	длина вектора
	 */
	double get_vector_length() const;
	/**
	 \brief	 x
	 */
	double get_x()const;
	/**
	 \brief	 y
	 */
	double get_y()const;
	/**
	 \brief	 z
	 */
	double get_z()const;
	/**
	 \brief	 равно
	 */
	bool operator==(const Vector3D& other);
	/**
	 \brief	 больше
	 */
	bool operator>(const Vector3D& other);
	/**
	 \brief меньше
	 */
	bool operator<(const Vector3D& other);
};





#include "Vector3D.h"
Vector3D::Vector3D(const double x, const double y, const double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
ostream& operator<<(ostream& exit, Vector3D& vec)
{
	exit << "x = " << vec.get_x() << endl;
	exit << "y = " << vec.get_y() << endl;
	exit << "z = " << vec.get_z() << endl;
	return exit;
}
Vector3D Vector3D::operator+(const Vector3D& other)
{
	return Vector3D(this->x + other.x, this->y + other.y, this->z + other.z);
}
Vector3D Vector3D::operator-(const Vector3D& other)
{
	return Vector3D(this->x - other.x, this->y - other.y, this->z - other.z);
}
Vector3D Vector3D::operator*(const double a)
{
	return Vector3D(this->x * a, this->y * a, this->z * a);
}
double Vector3D::operator*(const Vector3D& other)
{
	return this->x * other.x + this->y * other.y + this->z * other.z;
}
double Vector3D::get_vector_length() const
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}
double Vector3D::get_x()const
{
	return x;
}
double Vector3D::get_y()const
{
	return y;
}
double Vector3D::get_z()const
{
	return z;
}
bool Vector3D::operator>(const Vector3D& other)
{
	if (this->get_vector_length() > other.get_vector_length())
	{
		return true;
	}
		return false;
}
bool Vector3D::operator<(const Vector3D& other)
{
	if (this->get_vector_length() < other.get_vector_length())
	{
		return true;
	}
	return false;
}
bool Vector3D::operator==(const Vector3D& other)
{
	if (fabs(this->get_vector_length() - other.get_vector_length()) < numeric_limits<double>::epsilon())
	{
		return true;
	}
	return false;
}
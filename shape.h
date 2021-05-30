/**
*	������ ������
*/
#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

/**
*	����������� ������
*/
class Shape
{
public:

	Shape() = default;
	virtual ~Shape() = default;

	/**
	*	��������� ������
	*/
	virtual void Show() = 0;
};

/**
*	����
*/
class Circle : public Shape
{
public:

	Circle() = delete;

	Circle(int center, int radius) : m_center{ center }, m_radius{ radius }{}

	~Circle() = default;

	/**
	*	��������� �����
	*/
	virtual void Show() override
	{
		std::cout << "Show circle " << m_center << " " << m_radius << std::endl;
	}

private:

	int m_center;
	int m_radius;

};

/**
*	�������
*/
class Square : public Shape
{
public:

	Square() = delete;

	Square(int top_left, int side) : m_top_left{ top_left }, m_side{ side }{}

	~Square() = default;

	/**
	*	��������� ��������
	*/
	virtual void Show() override
	{
		std::cout << "Show square " << m_top_left << " " << m_side << std::endl;
	}

private:

	int m_top_left;
	int m_side;

};

#endif

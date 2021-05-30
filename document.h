/**
*	������ ���������
*/
#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <vector>
#include <memory>

#include "shape.h"

class Document
{
public:

	Document(std::string name) : m_name{name} {};

	~Document() = default;

	/**
	*	��������� ����� ���������
	*/
	std::string GetName() { return m_name; };

	/**
	*	���������� ������ � �������� � ���������
	*/
	void AddShape(std::unique_ptr<Shape>&& p)
	{
		p->Show();
		m_shapes.push_back(std::move(p)); // empace_back
	}

	/**
	*	�������� ������
	*/
	bool DelShape(int index)
	{
		if (index >= m_shapes.size())
			return false;
		else
		{
			m_shapes.erase(m_shapes.cbegin() + index);
			return true;
		}
	}

	/**
	*	��������� ���� ����� ���������
	*/
	void ShowAll()
	{
		for (const auto& p : m_shapes)
		{
			p->Show();
		}
	}

private:

	std::string m_name; //  ��� ���������
	std::vector<std::unique_ptr<Shape>> m_shapes;

};

#endif 

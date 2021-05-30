/**
*	Модуль документа
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
	*	Получение имени документа
	*/
	std::string GetName() { return m_name; };

	/**
	*	Добавление фигуры в документ и отрисовка
	*/
	void AddShape(std::unique_ptr<Shape>&& p)
	{
		p->Show();
		m_shapes.push_back(std::move(p)); // empace_back
	}

	/**
	*	Удаление фигуры
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
	*	Отрисовка всех фигур документа
	*/
	void ShowAll()
	{
		for (const auto& p : m_shapes)
		{
			p->Show();
		}
	}

private:

	std::string m_name; //  имя документа
	std::vector<std::unique_ptr<Shape>> m_shapes;

};

#endif 

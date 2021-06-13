/**
*	Модуль контролера
*/
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <vector>
#include <memory>

#include "document.h"

class Controller
{
public:

	Controller() = default;
	~Controller() = default;

	/**
	*	Создание нового документа
	*/
	bool CreateDoc(const std::string& name);

	/**
	*	Импорт документа из файла
	*/
	bool ImportDoc(const std::string& file_name);

	/**
	*	Экспорт текущего документа в файл
	*/
	bool ExportDoc();

	/**
	*	Получение списка имен открытых документов
	*/
	std::vector<std::string> GetDocsName();

	/**
	*	Получение индекса документа видимого пользователю
	*/	
	size_t GetCurrentDocIndex() 
	{
		return m_current_doc_index;
	};

	/**
	*	Изменение индекса документа видимого пользователю
	*/
	bool SetCurrentDocIndex(size_t index);

	/**
	*	Изменение индекса документа видимого пользователю
	*	(по имени докумета)
	*/
	bool SetCurrentDocIndex(const std::string& name);

	/**
		Документ с таким именем существует?
	*/
	bool IsDocExist(const std::string& name);

	/* Фигуры */

	/**
	*	Добавление круга
	*/
	bool AddCircle(int center, int radius);

	/**
	*	Добавление квадрата
	*/
	bool AddSquare(int top_left, int side);

	/**
	*	Удаление фигуры
	*/
	bool DelShape(int index);


private:

	std::vector<std::unique_ptr<Document>> m_documents; // отрытые документы
	size_t m_current_doc_index = 0; // индекс документа видимого пользователю

};

#endif 

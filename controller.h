/**
*	������ ����������
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
	*	�������� ������ ���������
	*/
	bool CreateDoc(std::string name);

	/**
	*	������ ��������� �� �����
	*/
	bool ImportDoc(std::string file_name);

	/**
	*	������� �������� ��������� � ����
	*/
	bool ExportDoc();

	/**
	*	��������� ������ ���� �������� ����������
	*/
	std::vector<std::string> GetDocsName();

	/**
	*	��������� ������� ��������� �������� ������������
	*/	
	size_t GetCurrentDocIndex() 
	{
		return m_current_doc_index;
	};

	/**
	*	��������� ������� ��������� �������� ������������
	*/
	bool SetCurrentDocIndex(size_t index);

	/**
	*	��������� ������� ��������� �������� ������������
	*	(�� ����� ��������)
	*/
	bool SetCurrentDocIndex(const std::string& name);

	/**
		�������� � ����� ������ ����������?
	*/
	bool IsDocExist(const std::string& name);

	/* ������ */

	/**
	*	���������� �����
	*/
	bool AddCircle(int center, int radius);

	/**
	*	���������� ��������
	*/
	bool AddSquare(int top_left, int side);

	/**
	*	�������� ������
	*/
	bool DelShape(int index);


private:

	std::vector<std::unique_ptr<Document>> m_documents; // ������� ���������
	size_t m_current_doc_index = 0; // ������ ��������� �������� ������������

};

extern Controller Ctrl;

#endif 

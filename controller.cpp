/**
*	������ ����������
*/

#include <iostream>

#include "controller.h"

using namespace std;

Controller Ctrl;

/**
*	�������� ������ ���������
*/
bool Controller::CreateDoc(string name)
{
	try {

		// ���������� ��������� � ��� ����������

		m_documents.push_back(make_unique<Document>(name));
		m_current_doc_index = m_documents.size() - 1;

	} 
	catch (...)
	{
		return false;
	}

	return true;
}

/**
*	������ ��������� �� �����
*/
bool Controller::ImportDoc(string file_name)
{
	try {

		cout << "Open file \"" << file_name << "\"\n";
		cout << "Read document form the file\n";

		// ���������� ��������� � ��� ����������

		m_documents.push_back(make_unique<Document>(file_name));
		m_current_doc_index = m_documents.size() - 1;

	}
	catch (...)
	{
		return false;
	}

	return true;
}

/**
*	������� �������� ��������� � ����
*/
bool Controller::ExportDoc()
{
	if (m_documents.size() == 0)
	{
		cout << "No open documents\n";
		return false;
	}

	string file_name = m_documents[m_current_doc_index]->GetName();

	cout << "Open file \"" << file_name << "\"\n";
	cout << "Write document to the file\n";

	return true;
}

/**
*	��������� ������ ���� �������� ����������
*/
std::vector<std::string> Controller::GetDocsName()
{
	vector<string> res;

	try {

		for (const auto& doc : m_documents)
			res.push_back(doc->GetName());
	}

	catch(...){}

	return res;
}

/**
*	��������� ������� ��������� �������� ������������
*/
bool Controller::SetCurrentDocIndex(size_t index)
{
	if (index < m_documents.size())
	{
		m_current_doc_index = index;
		m_documents[m_current_doc_index]->ShowAll();
		return true;
	}

	return false;
};

/**
*	��������� ������� ��������� �������� ������������
*	(�� ����� ��������)
*/
bool Controller::SetCurrentDocIndex(const std::string& name)
{
	for (size_t i = 0; i < m_documents.size(); ++i)
	{
		if (name == m_documents[i]->GetName())
		{
			m_current_doc_index = i;
			m_documents[m_current_doc_index]->ShowAll();
			return true;
		}
	}

	return false;
}

/**
	�������� � ����� ������ ����������?
*/
bool Controller::IsDocExist(const std::string& name)
{
	bool res = false;

	try {

		vector<string> names = Ctrl.GetDocsName();

		if (find(names.cbegin(), names.cend(), name) != names.cend())
			res = true;
	}
	catch (...){}

	return res;
}


/* ������ */

/**
*	���������� �����
*/
bool Controller::AddCircle(int center, int radius)
{
	try {

		if (m_documents.size())
			m_documents[m_current_doc_index]->AddShape(make_unique<Circle>(center, radius));
		else
			return false;

	}
	catch (...) 
	{
		return false;
	}

	return true;
}

/**
*	���������� ��������
*/
bool Controller::AddSquare(int top_left, int side)
{
	try {

		if (m_documents.size())
			m_documents[m_current_doc_index]->AddShape(make_unique<Square>(top_left, side));
		else
			return false;

	}
	catch (...)
	{
		return false;
	}

	return true;
}

/**
*	�������� ������
*/
bool Controller::DelShape(int index)
{
	try{

	return m_documents[m_current_doc_index]->DelShape(index);

	}
	catch (...)
	{
		return false;
	}
}

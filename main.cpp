/**
*	Модуль взаимодействия с польлзователем (компонент "VIEW")
*/

#include <iostream>
#include <string>

#include "controller.h"

using namespace std;

Controller Ctrl; // контроллер

/**
*	Интрефейс пользователя
*/
class UI
{
public:

	UI() = default;
	~UI() = default;

	/**
	*	Получение команд от пользователя и их выполнение
	*/
	void UserProcess()
	{
		PrintCommands();

		char cmd;

		while (cout << "Enter command:\n" && cin >> cmd && cmd != static_cast<char>(Cmd::exit))
		{
			switch (static_cast<Cmd>(cmd))
			{
				case Cmd::create_doc: CreateDoc();
				break;

				case Cmd::import_doc: ImportDoc();
				break;

				case Cmd::export_doc: ExportDoc();
				break;

				case Cmd::print_all_docs_name: PrintAllDocsName();
				break;

				case Cmd::change_current_doc: ChangeCurrentDoc();
				break;

				case Cmd::add_shape: CreateShape();
				break;

				case Cmd::del_spape: DeleteShape();
				break;
				
				case Cmd::help: PrintCommands();
				break;

				default: cout << "Unknow command\n";
			}
		}

		cout << "Exit\n";
	}

private:

	/**
	*	Создание нового докумета
	*/
	void CreateDoc(void)
	{
		string name = EnterDocName();

		if (!Ctrl.IsDocExist(name))
		{
			if (Ctrl.CreateDoc(name))
				cout << "Document " + name + " is created\n";
			else
				cout << "Create error\n";
		}
		else
		{
			cout << "Document with this name already exist\n";
		}

	}

	/**
	*	Импорт документа
	*/
	void ImportDoc()
	{
		string file_name = EnterFileName();

		if (!Ctrl.IsDocExist(file_name))
		{
			if (Ctrl.ImportDoc(file_name))
				cout << "Document " + file_name + " is imported\n";
			else
				cout << "Import error\n";
		}
		else
		{
			cout << "Document with this name already exist\n";
		}
	}

	/**
	*	Экспорт документа
	*/
	void ExportDoc()
	{
		if (Ctrl.ExportDoc())
			cout << "Currentd document is exported\n";
		else
			cout << "Export error\n";
	}

	/**
	*	Вывод пользователю имен всех открытых документов
	*/
	void PrintAllDocsName()
	{
		vector<string> names = Ctrl.GetDocsName();

		if (names.size() == 0)
		{
			cout << "There are no documents\n";
		}
		{
			for (size_t i = 0; i < names.size(); ++i)
			{
				cout << names[i];

				if (i == Ctrl.GetCurrentDocIndex())
					cout << " - current\n";
				else
					cout << endl;
			}
		}
	}

	/**
	*	Изменение текущего документа видимого пользователю
	*/
	void ChangeCurrentDoc()
	{
		string name = EnterDocName();

		if (Ctrl.SetCurrentDocIndex(name))
		{
			cout << "OK\n";
		}
		else
		{
			cout << "There is no documents with such name\n";
		}
	}

	/**
	*	Создание графического примитива
	*/
	void CreateShape(void)
	{
		PrintShapes();

		char shape;

		cin >> shape;

		switch (static_cast<ShapeType>(shape))
		{
			case ShapeType::circle:
			{
				int center, radius;

				cout << "Enter center of the circle ";
				cin >> center;
				cout << "Enter radius of the circle ";
				cin >> radius;

				if (Ctrl.AddCircle(center, radius))
					cout << "Circle is added\n";
				else
					cout << "Error occurs during adding\n";
			}
			break;

			case ShapeType::square:
			{
				int top_left, side;

				cout << "Enter top left angle of square ";
				cin >> top_left;
				cout << "Enter side of the squre ";
				cin >> side;

				if (Ctrl.AddSquare(top_left, side ))
					cout << "Square is added\n";
				else
					cout << "Error occurs during adding\n";
			}
			break;

			default:
				cout << "Unknown shape\n";
		}
	}

	/**
	*	Удаление графического примитива
	*/
	void DeleteShape(void)
	{
		cout << "Enter index of the shape ";

		int index;
		
		cin >> index;

		bool res = Ctrl.DelShape(index);

		if (res)
			cout << "Ok\n";
		else
			cout << "Error\n";
	}

	/**
	*	Получение имени документа от пользователя
	*/
	string EnterDocName(void)
	{
		cout << "Enter document name: ";
		string name;
		cin >> name;
		return name;
	}

	/**
	*	Получение имени файла от пользователя
	*/
	string EnterFileName(void)
	{
		cout << "Enter file name: ";
		string name;
		cin >> name;
		return name;
	}

	/**
	*	Вывод на экран списка возможны команд
	*/
	void PrintCommands(void)
	{
		cout << static_cast<char>(Cmd::exit) << " - exit program\n";
		cout << static_cast<char>(Cmd::create_doc) << " - create document\n";
		cout << static_cast<char>(Cmd::import_doc) << " - import document\n";
		cout << static_cast<char>(Cmd::export_doc) << " - export document\n";
		cout << static_cast<char>(Cmd::print_all_docs_name) << " - print all documents names\n";
		cout << static_cast<char>(Cmd::change_current_doc) << " - change current document\n";
		cout << static_cast<char>(Cmd::add_shape) << " - add shape\n";
		cout << static_cast<char>(Cmd::del_spape) << " - delete shape\n";
		cout << static_cast<char>(Cmd::help) << " - print commands list\n";
	}

	/**
	*	Вывод на экран списка возможны фигур
	*/
	void PrintShapes(void)
	{
		cout << "Enter shape:\n";
		cout << static_cast<char>(ShapeType::circle) << " - circle\n";
		cout << static_cast<char>(ShapeType::square) << " - square\n";
	}

	/**
	*	Команды пользователя
	*/
	enum class Cmd
	{
		exit = 'e',
		create_doc = 'c',
		import_doc = 'i',
		export_doc = 'x',
		print_all_docs_name = 'a',
		change_current_doc = 'h',
		add_shape = 's',
		del_spape = 'd',
		help = '?'
	};

	/**
	*	Типы фигур
	*/
	enum class ShapeType
	{
		circle = 'c',
		square = 's'
	};
};

int main()
{
	UI ui;

	// Взаимодействие с пользователем

	ui.UserProcess();

	return 0;
}

#include <QApplication>
#include "interfaceGUI.h"
#include "tests.h"

int main(int argc, char** argv)
{
	//Tests tests;
	//tests.tests_unitaires();
	//tests.tests_validation();
	//system("pause");

	QApplication app(argc, argv);
	InterfaceGUI i ("Graphicus-03 (GraphicusGUI)");
	return app.exec();
}

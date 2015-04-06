#include "stdafx.h"
#include "firestormeditor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FirestormEditor w;
	w.show();
	return a.exec();
}

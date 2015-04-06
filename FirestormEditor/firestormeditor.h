#ifndef FIRESTORMEDITOR_H
#define FIRESTORMEDITOR_H

#include <QtWidgets/QMainWindow>
#include "ui_firestormeditor.h"

class FirestormEditor : public QMainWindow
{
	Q_OBJECT

public:
	FirestormEditor(QWidget *parent = 0);
	~FirestormEditor();

private:
	Ui::FirestormEditorClass ui;
};

#endif // FIRESTORMEDITOR_H

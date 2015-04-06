/********************************************************************************
** Form generated from reading UI file 'firestormeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRESTORMEDITOR_H
#define UI_FIRESTORMEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FirestormEditorClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FirestormEditorClass)
    {
        if (FirestormEditorClass->objectName().isEmpty())
            FirestormEditorClass->setObjectName(QStringLiteral("FirestormEditorClass"));
        FirestormEditorClass->resize(600, 400);
        menuBar = new QMenuBar(FirestormEditorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        FirestormEditorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FirestormEditorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FirestormEditorClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(FirestormEditorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        FirestormEditorClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(FirestormEditorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FirestormEditorClass->setStatusBar(statusBar);

        retranslateUi(FirestormEditorClass);

        QMetaObject::connectSlotsByName(FirestormEditorClass);
    } // setupUi

    void retranslateUi(QMainWindow *FirestormEditorClass)
    {
        FirestormEditorClass->setWindowTitle(QApplication::translate("FirestormEditorClass", "FirestormEditor", 0));
    } // retranslateUi

};

namespace Ui {
    class FirestormEditorClass: public Ui_FirestormEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRESTORMEDITOR_H

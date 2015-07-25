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
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FirestormEditorClass
{
public:
    QWidget *centralWidget;
    QOpenGLWidget *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FirestormEditorClass)
    {
        if (FirestormEditorClass->objectName().isEmpty())
            FirestormEditorClass->setObjectName(QStringLiteral("FirestormEditorClass"));
        FirestormEditorClass->resize(600, 400);
        centralWidget = new QWidget(FirestormEditorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openGLWidget = new QOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(0, 10, 591, 331));
        FirestormEditorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FirestormEditorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        FirestormEditorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FirestormEditorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FirestormEditorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
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

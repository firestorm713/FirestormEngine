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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FirestormEditorClass
{
public:
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionNew_Scene;
    QAction *actionSave_Scene;
    QAction *actionOpen_Scene;
    QAction *actionNew_Entity;
    QAction *actionAdd_Component;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_3;
    QTreeWidget *treeWidget;
    QOpenGLWidget *openGLWidget;
    QTreeWidget *treeWidget_3;
    QLabel *label_2;
    QTreeWidget *treeWidget_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuProject;
    QMenu *menuEntity;
    QMenu *menuComponent;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FirestormEditorClass)
    {
        if (FirestormEditorClass->objectName().isEmpty())
            FirestormEditorClass->setObjectName(QStringLiteral("FirestormEditorClass"));
        FirestormEditorClass->resize(814, 608);
        actionNew = new QAction(FirestormEditorClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionSave = new QAction(FirestormEditorClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionOpen = new QAction(FirestormEditorClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionNew_Scene = new QAction(FirestormEditorClass);
        actionNew_Scene->setObjectName(QStringLiteral("actionNew_Scene"));
        actionSave_Scene = new QAction(FirestormEditorClass);
        actionSave_Scene->setObjectName(QStringLiteral("actionSave_Scene"));
        actionOpen_Scene = new QAction(FirestormEditorClass);
        actionOpen_Scene->setObjectName(QStringLiteral("actionOpen_Scene"));
        actionNew_Entity = new QAction(FirestormEditorClass);
        actionNew_Entity->setObjectName(QStringLiteral("actionNew_Entity"));
        actionAdd_Component = new QAction(FirestormEditorClass);
        actionAdd_Component->setObjectName(QStringLiteral("actionAdd_Component"));
        centralWidget = new QWidget(FirestormEditorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(550, 10, 47, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(280, 330, 61, 16));
        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(550, 30, 256, 441));
        openGLWidget = new QOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(0, 0, 531, 321));
        treeWidget_3 = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        treeWidget_3->setHeaderItem(__qtreewidgetitem1);
        treeWidget_3->setObjectName(QStringLiteral("treeWidget_3"));
        treeWidget_3->setGeometry(QRect(270, 350, 256, 192));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 330, 61, 16));
        treeWidget_2 = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setText(0, QStringLiteral("1"));
        treeWidget_2->setHeaderItem(__qtreewidgetitem2);
        treeWidget_2->setObjectName(QStringLiteral("treeWidget_2"));
        treeWidget_2->setGeometry(QRect(0, 350, 256, 192));
        FirestormEditorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FirestormEditorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 814, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuProject = new QMenu(menuBar);
        menuProject->setObjectName(QStringLiteral("menuProject"));
        menuEntity = new QMenu(menuBar);
        menuEntity->setObjectName(QStringLiteral("menuEntity"));
        menuComponent = new QMenu(menuBar);
        menuComponent->setObjectName(QStringLiteral("menuComponent"));
        FirestormEditorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FirestormEditorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FirestormEditorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FirestormEditorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FirestormEditorClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuProject->menuAction());
        menuBar->addAction(menuEntity->menuAction());
        menuBar->addAction(menuComponent->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionOpen);
        menuProject->addAction(actionNew_Scene);
        menuProject->addAction(actionSave_Scene);
        menuProject->addAction(actionOpen_Scene);
        menuEntity->addAction(actionNew_Entity);
        menuComponent->addAction(actionAdd_Component);

        retranslateUi(FirestormEditorClass);

        QMetaObject::connectSlotsByName(FirestormEditorClass);
    } // setupUi

    void retranslateUi(QMainWindow *FirestormEditorClass)
    {
        FirestormEditorClass->setWindowTitle(QApplication::translate("FirestormEditorClass", "FirestormEditor", 0));
        actionNew->setText(QApplication::translate("FirestormEditorClass", "New", 0));
        actionSave->setText(QApplication::translate("FirestormEditorClass", "Save", 0));
        actionOpen->setText(QApplication::translate("FirestormEditorClass", "Open", 0));
        actionNew_Scene->setText(QApplication::translate("FirestormEditorClass", "New Scene", 0));
        actionSave_Scene->setText(QApplication::translate("FirestormEditorClass", "Save Scene", 0));
        actionOpen_Scene->setText(QApplication::translate("FirestormEditorClass", "Open Scene", 0));
        actionNew_Entity->setText(QApplication::translate("FirestormEditorClass", "New Entity", 0));
        actionAdd_Component->setText(QApplication::translate("FirestormEditorClass", "Add Component", 0));
        label->setText(QApplication::translate("FirestormEditorClass", "Inspector", 0));
        label_3->setText(QApplication::translate("FirestormEditorClass", "Scene View", 0));
        label_2->setText(QApplication::translate("FirestormEditorClass", "Project View", 0));
        menuFile->setTitle(QApplication::translate("FirestormEditorClass", "File", 0));
        menuProject->setTitle(QApplication::translate("FirestormEditorClass", "Project", 0));
        menuEntity->setTitle(QApplication::translate("FirestormEditorClass", "Entity", 0));
        menuComponent->setTitle(QApplication::translate("FirestormEditorClass", "Component", 0));
    } // retranslateUi

};

namespace Ui {
    class FirestormEditorClass: public Ui_FirestormEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRESTORMEDITOR_H

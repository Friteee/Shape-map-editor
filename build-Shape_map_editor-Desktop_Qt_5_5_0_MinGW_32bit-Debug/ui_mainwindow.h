/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionNew;
    QAction *actionMap_options;
    QAction *actionResize;
    QWidget *centralWidget;
    QGraphicsView *graphicsMap;
    QTabWidget *tileSetManager;
    QWidget *Tileset;
    QTabWidget *tileSets;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QTabWidget *tileTypes;
    QWidget *TileType;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuOptions;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1294, 811);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAcceptDrops(false);
        MainWindow->setAutoFillBackground(false);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionMap_options = new QAction(MainWindow);
        actionMap_options->setObjectName(QStringLiteral("actionMap_options"));
        actionResize = new QAction(MainWindow);
        actionResize->setObjectName(QStringLiteral("actionResize"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsMap = new QGraphicsView(centralWidget);
        graphicsMap->setObjectName(QStringLiteral("graphicsMap"));
        graphicsMap->setGeometry(QRect(450, 10, 831, 741));
        tileSetManager = new QTabWidget(centralWidget);
        tileSetManager->setObjectName(QStringLiteral("tileSetManager"));
        tileSetManager->setGeometry(QRect(30, 10, 381, 441));
        tileSetManager->setTabsClosable(false);
        Tileset = new QWidget();
        Tileset->setObjectName(QStringLiteral("Tileset"));
        tileSets = new QTabWidget(Tileset);
        tileSets->setObjectName(QStringLiteral("tileSets"));
        tileSets->setGeometry(QRect(20, 10, 331, 351));
        tileSets->setTabPosition(QTabWidget::South);
        addButton = new QPushButton(Tileset);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(20, 370, 51, 23));
        deleteButton = new QPushButton(Tileset);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(80, 370, 51, 23));
        tileSetManager->addTab(Tileset, QString());
        tileTypes = new QTabWidget(centralWidget);
        tileTypes->setObjectName(QStringLiteral("tileTypes"));
        tileTypes->setGeometry(QRect(30, 460, 381, 291));
        TileType = new QWidget();
        TileType->setObjectName(QStringLiteral("TileType"));
        tileTypes->addTab(TileType, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1294, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuEdit->addAction(actionResize);
        menuOptions->addAction(actionMap_options);

        retranslateUi(MainWindow);

        tileSetManager->setCurrentIndex(0);
        tileSets->setCurrentIndex(-1);
        tileTypes->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Shape map editor", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionMap_options->setText(QApplication::translate("MainWindow", "Map options", 0));
        actionResize->setText(QApplication::translate("MainWindow", "Resize", 0));
        addButton->setText(QApplication::translate("MainWindow", "Add", 0));
        deleteButton->setText(QApplication::translate("MainWindow", "Delete", 0));
        tileSetManager->setTabText(tileSetManager->indexOf(Tileset), QApplication::translate("MainWindow", "Tile Set", 0));
        tileTypes->setTabText(tileTypes->indexOf(TileType), QApplication::translate("MainWindow", "Tile Type", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

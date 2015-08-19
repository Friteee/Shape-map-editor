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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
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
    QAction *actionResize;
    QAction *actionChange_background;
    QAction *actionDraw;
    QAction *actionErase;
    QAction *actionMove;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tileTypes;
    QWidget *TileType;
    QLineEdit *lineEdit;
    QGraphicsView *graphicsView;
    QComboBox *comboBox;
    QCheckBox *checkBox;
    QTabWidget *tileSetManager;
    QWidget *Tileset;
    QTabWidget *tileSets;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QGraphicsView *graphicsMap;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1173, 733);
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
        actionResize = new QAction(MainWindow);
        actionResize->setObjectName(QStringLiteral("actionResize"));
        actionChange_background = new QAction(MainWindow);
        actionChange_background->setObjectName(QStringLiteral("actionChange_background"));
        actionDraw = new QAction(MainWindow);
        actionDraw->setObjectName(QStringLiteral("actionDraw"));
        actionDraw->setCheckable(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/pencil.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionDraw->setIcon(icon);
        actionErase = new QAction(MainWindow);
        actionErase->setObjectName(QStringLiteral("actionErase"));
        actionErase->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/eraser.ico"), QSize(), QIcon::Normal, QIcon::On);
        actionErase->setIcon(icon1);
        actionMove = new QAction(MainWindow);
        actionMove->setObjectName(QStringLiteral("actionMove"));
        actionMove->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/move.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMove->setIcon(icon2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tileTypes = new QTabWidget(centralWidget);
        tileTypes->setObjectName(QStringLiteral("tileTypes"));
        tileTypes->setMinimumSize(QSize(380, 200));
        tileTypes->setMaximumSize(QSize(380, 200));
        TileType = new QWidget();
        TileType->setObjectName(QStringLiteral("TileType"));
        lineEdit = new QLineEdit(TileType);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(160, 50, 113, 20));
        graphicsView = new QGraphicsView(TileType);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(50, 40, 64, 64));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setInteractive(false);
        graphicsView->setTransformationAnchor(QGraphicsView::NoAnchor);
        graphicsView->setResizeAnchor(QGraphicsView::NoAnchor);
        graphicsView->setRubberBandSelectionMode(Qt::ContainsItemShape);
        comboBox = new QComboBox(TileType);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(160, 10, 111, 22));
        checkBox = new QCheckBox(TileType);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(160, 90, 111, 17));
        tileTypes->addTab(TileType, QString());

        gridLayout->addWidget(tileTypes, 2, 0, 1, 1);

        tileSetManager = new QTabWidget(centralWidget);
        tileSetManager->setObjectName(QStringLiteral("tileSetManager"));
        tileSetManager->setMinimumSize(QSize(380, 430));
        tileSetManager->setMaximumSize(QSize(380, 430));
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

        gridLayout->addWidget(tileSetManager, 0, 0, 2, 1);

        graphicsMap = new QGraphicsView(centralWidget);
        graphicsMap->setObjectName(QStringLiteral("graphicsMap"));
        graphicsMap->setMinimumSize(QSize(400, 400));
        graphicsMap->setAutoFillBackground(true);
        graphicsMap->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsMap->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsMap->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        graphicsMap->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(graphicsMap, 0, 1, 4, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1173, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuEdit->addAction(actionResize);
        menuEdit->addAction(actionChange_background);
        mainToolBar->addAction(actionDraw);
        mainToolBar->addAction(actionErase);
        mainToolBar->addAction(actionMove);

        retranslateUi(MainWindow);

        tileTypes->setCurrentIndex(0);
        tileSetManager->setCurrentIndex(0);
        tileSets->setCurrentIndex(-1);


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
        actionResize->setText(QApplication::translate("MainWindow", "Map settings", 0));
#ifndef QT_NO_TOOLTIP
        actionResize->setToolTip(QApplication::translate("MainWindow", "Resize", 0));
#endif // QT_NO_TOOLTIP
        actionChange_background->setText(QApplication::translate("MainWindow", "Change background", 0));
        actionDraw->setText(QApplication::translate("MainWindow", "Draw", 0));
#ifndef QT_NO_TOOLTIP
        actionDraw->setToolTip(QApplication::translate("MainWindow", "Draw tiles", 0));
#endif // QT_NO_TOOLTIP
        actionErase->setText(QApplication::translate("MainWindow", "Erase", 0));
#ifndef QT_NO_TOOLTIP
        actionErase->setToolTip(QApplication::translate("MainWindow", "Erase tiles", 0));
#endif // QT_NO_TOOLTIP
        actionMove->setText(QApplication::translate("MainWindow", "Move", 0));
#ifndef QT_NO_TOOLTIP
        actionMove->setToolTip(QApplication::translate("MainWindow", "Move the tiles", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Size of the object in pixels</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        lineEdit->setText(QApplication::translate("MainWindow", "32", 0));
#ifndef QT_NO_WHATSTHIS
        graphicsView->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>Image of the tile</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Tile", 0)
         << QApplication::translate("MainWindow", "Prop", 0)
        );
#ifndef QT_NO_TOOLTIP
        comboBox->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Type of the object</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        checkBox->setText(QApplication::translate("MainWindow", "Invincible", 0));
        tileTypes->setTabText(tileTypes->indexOf(TileType), QApplication::translate("MainWindow", "Tile Type", 0));
#ifndef QT_NO_WHATSTHIS
        tileSets->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>Graphical representation of tile set</p><p><br/></p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        addButton->setText(QApplication::translate("MainWindow", "Add", 0));
        deleteButton->setText(QApplication::translate("MainWindow", "Delete", 0));
        tileSetManager->setTabText(tileSetManager->indexOf(Tileset), QApplication::translate("MainWindow", "Tile Set", 0));
#ifndef QT_NO_WHATSTHIS
        graphicsMap->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>Map</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

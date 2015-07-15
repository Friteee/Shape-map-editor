/********************************************************************************
** Form generated from reading UI file 'addtileset.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTILESET_H
#define UI_ADDTILESET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddTileset
{
public:
    QLineEdit *tileSize;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *margin;
    QLineEdit *fileBrowse;
    QLabel *label_3;
    QPushButton *browseButton;
    QPushButton *addButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *AddTileset)
    {
        if (AddTileset->objectName().isEmpty())
            AddTileset->setObjectName(QStringLiteral("AddTileset"));
        AddTileset->resize(460, 197);
        tileSize = new QLineEdit(AddTileset);
        tileSize->setObjectName(QStringLiteral("tileSize"));
        tileSize->setGeometry(QRect(140, 20, 113, 20));
        label = new QLabel(AddTileset);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 68, 19));
        label_2 = new QLabel(AddTileset);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(51, 60, 59, 19));
        margin = new QLineEdit(AddTileset);
        margin->setObjectName(QStringLiteral("margin"));
        margin->setGeometry(QRect(140, 60, 113, 20));
        fileBrowse = new QLineEdit(AddTileset);
        fileBrowse->setObjectName(QStringLiteral("fileBrowse"));
        fileBrowse->setGeometry(QRect(140, 100, 181, 20));
        label_3 = new QLabel(AddTileset);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(75, 100, 30, 19));
        browseButton = new QPushButton(AddTileset);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        browseButton->setGeometry(QRect(340, 100, 61, 21));
        addButton = new QPushButton(AddTileset);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(270, 160, 75, 23));
        cancelButton = new QPushButton(AddTileset);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(360, 160, 75, 23));

        retranslateUi(AddTileset);

        QMetaObject::connectSlotsByName(AddTileset);
    } // setupUi

    void retranslateUi(QDialog *AddTileset)
    {
        AddTileset->setWindowTitle(QApplication::translate("AddTileset", "Dialog", 0));
        tileSize->setText(QApplication::translate("AddTileset", "32", 0));
        label->setText(QApplication::translate("AddTileset", "<html><head/><body><p><span style=\" font-size:12pt;\">Tile Size:</span></p><p><br/></p></body></html>", 0));
        label_2->setText(QApplication::translate("AddTileset", "<html><head/><body><p><span style=\" font-size:12pt;\">Margin:</span></p></body></html>", 0));
        margin->setText(QApplication::translate("AddTileset", "0", 0));
        label_3->setText(QApplication::translate("AddTileset", "<html><head/><body><p><span style=\" font-size:12pt;\">File:</span></p></body></html>", 0));
        browseButton->setText(QApplication::translate("AddTileset", "Browse", 0));
        addButton->setText(QApplication::translate("AddTileset", "Add", 0));
        cancelButton->setText(QApplication::translate("AddTileset", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class AddTileset: public Ui_AddTileset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTILESET_H

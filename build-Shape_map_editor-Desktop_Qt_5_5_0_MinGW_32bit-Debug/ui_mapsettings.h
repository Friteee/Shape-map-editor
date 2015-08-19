/********************************************************************************
** Form generated from reading UI file 'mapsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPSETTINGS_H
#define UI_MAPSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_MapSettings
{
public:
    QFormLayout *formLayout;
    QLineEdit *widthEdit;
    QDialogButtonBox *buttonBox;
    QLineEdit *heightEdit;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *MapSettings)
    {
        if (MapSettings->objectName().isEmpty())
            MapSettings->setObjectName(QStringLiteral("MapSettings"));
        MapSettings->resize(266, 99);
        formLayout = new QFormLayout(MapSettings);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        widthEdit = new QLineEdit(MapSettings);
        widthEdit->setObjectName(QStringLiteral("widthEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widthEdit);

        buttonBox = new QDialogButtonBox(MapSettings);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(2, QFormLayout::FieldRole, buttonBox);

        heightEdit = new QLineEdit(MapSettings);
        heightEdit->setObjectName(QStringLiteral("heightEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, heightEdit);

        label = new QLabel(MapSettings);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        label_2 = new QLabel(MapSettings);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);


        retranslateUi(MapSettings);
        QObject::connect(buttonBox, SIGNAL(accepted()), MapSettings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MapSettings, SLOT(reject()));

        QMetaObject::connectSlotsByName(MapSettings);
    } // setupUi

    void retranslateUi(QDialog *MapSettings)
    {
        MapSettings->setWindowTitle(QApplication::translate("MapSettings", "Dialog", 0));
        label->setText(QApplication::translate("MapSettings", "<html><head/><body><p><span style=\" font-size:14pt;\">Set height</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("MapSettings", "<html><head/><body><p><span style=\" font-size:14pt;\">Set width</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MapSettings: public Ui_MapSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPSETTINGS_H

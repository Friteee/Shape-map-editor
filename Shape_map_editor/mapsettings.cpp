#include <QMessageBox>
#include "mapsettings.h"
#include "ui_mapsettings.h"

MapSettings::MapSettings(Map * init_map , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MapSettings)
{
    map = init_map;
    ui->setupUi(this);
}

MapSettings::~MapSettings()
{
    delete ui;
}

void MapSettings::on_buttonBox_accepted()
{
    if(ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::critical(this, tr("Warning"), tr("One of the sizes empty"));
    }
}

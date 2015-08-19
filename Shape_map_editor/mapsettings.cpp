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
    if(ui->widthEdit->text().isEmpty() || ui->heightEdit->text().isEmpty())
    {
        QMessageBox::critical(this, tr("Warning"), tr("One of the sizes empty"));
        return;
    }
    map->size_.setHeight(ui->heightEdit->text().toInt());
    map->size_.setWidth(ui->widthEdit->text().toInt());
    map->setSceneRect(0, 0, ui->widthEdit->text().toInt(), ui->heightEdit->text().toInt());
    map->drawGrid();
}

#include "addtileset.h"
#include "ui_addtileset.h"
#include <QFileDialog>
#include <QMessageBox>

AddTileset::AddTileset(QWidget *parent , TileSetManager * init_manager) :
    QDialog(parent),
    ui(new Ui::AddTileset)
{
    manager = init_manager;
    ui->setupUi(this);
}

AddTileset::~AddTileset()
{
    delete ui;
}


void AddTileset::on_browseButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Tileset"), "untitled", tr("Image files (*.bmp , *.gif , *.jpg , *.jpeg , *.png , *.pbm , *.pgm , *.ppm , *.xpm , *.xbm)"));
    ui->fileBrowse->setText(filename);
}

void AddTileset::on_addButton_clicked()
{
    int margin = atoi(ui->margin->displayText().toStdString().c_str());
    int size = atoi(ui->tileSize->displayText().toStdString().c_str());
    if(size == 0)
    {
        QMessageBox::critical(this,tr("Warning"),tr("Size can not be 0"));
        return;
    }
    QString filename = ui->fileBrowse->displayText();
    if(filename == "")
    {
        QMessageBox::critical(this,tr("Warning"),tr("Input the filename"));
        return;
    }
    manager->add_tileset(margin, size, filename);
    this->close();
}

void AddTileset::on_cancelButton_clicked()
{
    this->close();
}

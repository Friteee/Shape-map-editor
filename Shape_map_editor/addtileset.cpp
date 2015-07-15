#include "addtileset.h"
#include "ui_addtileset.h"
#include <QFileDialog>

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
    QString filename = ui->fileBrowse->displayText();
    manager->add_tileset(margin, size, filename);
    this->close();
}

void AddTileset::on_cancelButton_clicked()
{
    this->close();
}

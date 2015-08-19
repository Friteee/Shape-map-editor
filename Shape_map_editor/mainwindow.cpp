#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    main_map = new Map;
    tilesets_manager = new TileSetManager(ui->tileSets);
    toolbar.init(main_map,ui->actionDraw,ui->actionMove,ui->actionErase,&current_type);
    current_type.init_view(ui->graphicsView);
    tilesets_manager->register_current_type(&current_type);
    main_map->init(ui->graphicsMap , &toolbar);
    QPainter painter;
    main_map->setCurrentType(&current_type);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Map"), "untitled", tr("Map files (*.shm)"));
    if(filename.isNull())
        return;
    main_map->open(filename);

}

void MainWindow::on_actionNew_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("New Map"), "untitled" , tr("Map files (*.shm)"));
    if(filename.isNull())
        return;
    main_map->save();
    main_map->createNew(filename);
}

void MainWindow::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("New Map"), "untitled" , tr("Map files (*.shm)"));
    if(filename.isNull())
        return;
    main_map->save(filename);
}

void MainWindow::on_addButton_clicked()
{
    tilesets_manager->add();
}

void MainWindow::on_deleteButton_clicked()
{
    tilesets_manager->delete_current();
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    current_type.change_size(arg1);
}

void MainWindow::on_actionChange_background_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Background_image"), "untitled" , tr("Image files (*.bmp , *.gif , *.jpg , *.jpeg , *.png , *.pbm , *.pgm , *.ppm , *.xpm , *.xbm)"));
    if(filename.isNull())
        return;
    main_map->changeBackground(filename);
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    current_type.change_invincibility(checked);
}

void MainWindow::on_actionSave_triggered()
{
    main_map->save();
}

void MainWindow::on_actionResize_triggered()
{
    main_map->changeSize();
}


void MainWindow::on_actionDraw_triggered()
{
    toolbar.actionTriggered(ui->actionDraw);
}

void MainWindow::on_actionErase_triggered()
{
    toolbar.actionTriggered(ui->actionErase);
}

void MainWindow::on_actionMove_triggered()
{
    toolbar.actionTriggered(ui->actionMove);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    current_type.change_type(index);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tilesets_manager = new TileSetManager(ui->tileSets);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Map"), "untitled", tr("Map files (*.shm)"));
    main_map.open(filename);

}

void MainWindow::on_actionNew_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("New Map"), "untitled" , tr("Map files (*.shm)"));
    main_map.save();
    main_map.create_new(filename);
}

void MainWindow::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("New Map"), "untitled" , tr("Map files (*.shm)"));
    main_map.save(filename);
}

void MainWindow::on_addButton_clicked()
{
    tilesets_manager->add();
}

void MainWindow::on_deleteButton_clicked()
{
    tilesets_manager->delete_current();
}

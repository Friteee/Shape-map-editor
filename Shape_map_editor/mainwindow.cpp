#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    main_map(this),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tilesets_manager = new TileSetManager(ui->tileSets);
    current_type.init_view(ui->graphicsView);
    tilesets_manager->register_current_type(&current_type);
    main_map.init(ui->graphicsMap);
    QPainter painter;
    main_map.drawBackground(&painter,QRect(0,0,main_map.width(),main_map.height()));
    ui->graphicsMap->show();
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
    main_map.createNew(filename);
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

void MainWindow::on_comboBox_editTextChanged(const QString &arg1)
{
    current_type.change_type(arg1);
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    current_type.change_size(arg1);
}

void MainWindow::on_actionChange_background_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Background_image"), "untitled" , tr("Image files (*.bmp , *.gif , *.jpg , *.jpeg , *.png , *.pbm , *.pgm , *.ppm , *.xpm , *.xbm)"));
    main_map.changeBackground(filename);
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    current_type.change_invincibility(checked);
}

void MainWindow::on_actionSave_triggered()
{
    main_map.save();
}

void MainWindow::on_actionResize_triggered()
{
    main_map.changeSize();
}

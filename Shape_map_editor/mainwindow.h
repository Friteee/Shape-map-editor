#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QGraphicsScene>
#include "tilesetmanager.h"
#include "map.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    void on_actionNew_triggered();

    void on_actionSave_as_triggered();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

private:
    Map main_map;
    QGraphicsScene * scene;
    TileSetManager * tilesets_manager;
    Ui::MainWindow * ui;
};

#endif // MAINWINDOW_H

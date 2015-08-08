#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QGraphicsScene>
#include "currenttype.h"
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

    void on_comboBox_editTextChanged(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_actionChange_background_triggered();

    void on_checkBox_toggled(bool checked);

    void on_actionSave_triggered();

    void on_actionResize_triggered();

private:
    CurrentType current_type;
    Map main_map;
    QGraphicsScene * scene;
    TileSetManager * tilesets_manager;
    Ui::MainWindow * ui;
};

#endif // MAINWINDOW_H

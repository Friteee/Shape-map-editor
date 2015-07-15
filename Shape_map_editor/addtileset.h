#ifndef ADDTILESET_H
#define ADDTILESET_H

#include <QDialog>
#include "tilesetmanager.h"

namespace Ui {
class AddTileset;
}

class TileSetManager;

class AddTileset : public QDialog
{
    Q_OBJECT

public:
    explicit AddTileset(QWidget *parent = 0 , TileSetManager * init_manager = 0);
    ~AddTileset();

private slots:

    void on_browseButton_clicked();

    void on_addButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::AddTileset *ui;
    TileSetManager *manager;
};

#endif // ADDTILESET_H

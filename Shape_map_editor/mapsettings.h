#ifndef MAPSETTINGS_H
#define MAPSETTINGS_H

#include "map.h"
#include <QDialog>

class Map;

namespace Ui {
class MapSettings;
}

class MapSettings : public QDialog
{
    Q_OBJECT

public:
    explicit MapSettings(Map * init_map , QWidget *parent = 0);
    ~MapSettings();

private slots:
    void on_buttonBox_accepted();

private:
    Map * map;
    Ui::MapSettings *ui;
};

#endif // MAPSETTINGS_H

#ifndef TILESETMANAGER_H
#define TILESETMANAGER_H

#include <QTabWidget>
#include <list>
#include "tileset.h"
#include "addtileset.h"

class AddTileset;

class TileSetManager
{
public:
    TileSetManager(QTabWidget * tab);
    void add();
    void delete_current();
    void add_tileset(int margin, int size, QString filename);
private:
    std::list<TileSet> tilesets;
    AddTileset * window;
    QTabWidget * tileset_tab;
};

#endif // TILESETMANAGER_H

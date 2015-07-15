#include "tilesetmanager.h"

TileSetManager::TileSetManager(QTabWidget * tab)
{
    tileset_tab = tab;
}

void TileSetManager::add()
{
    window = new AddTileset(0,this);
    window->show();
}

void TileSetManager::delete_current()
{

}

void TileSetManager::add_tileset(int margin, int size, QString filename)
{

}

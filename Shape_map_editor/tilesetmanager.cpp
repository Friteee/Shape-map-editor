#include "tilesetmanager.h"

TileSetManager::TileSetManager(QTabWidget * tab)
{
    tileset_tab = tab;
    window = 0;
}

TileSetManager::~TileSetManager()
{
    TileSet * buffer = tilesets.back();
    tilesets.pop_back();
    while(buffer!=0)
    {
        delete buffer;
        buffer = tilesets.back();
        tilesets.pop_back();
    }
}

void TileSetManager::add()
{
    if(window != 0)
        delete window;
    window = new AddTileset(0,this);
    window->show();
}

void TileSetManager::delete_current()
{
    int current = tileset_tab->currentIndex();
    tileset_tab->removeTab(current);
    std::list<TileSet*>::iterator iterator = tilesets.begin();
    std::advance(iterator,current);
    tilesets.erase(iterator);
}

void TileSetManager::add_tileset(int margin, int size, QString filename)
{
    TileSet * buffer_tile_set = new TileSet(tileset_tab);
    if(tileset_tab!=0)
        tileset_tab->addTab(buffer_tile_set,filename);
    buffer_tile_set->init(filename,margin,size);
    tilesets.push_back(buffer_tile_set);
}

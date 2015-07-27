#include "map.h"
#include <fstream>

Map::Map()
{
    filename_ = "";
}

void Map::open(QString filename)
{
    filename_ = filename;
    std::ifstream in;
    in.open(filename_.toStdString().c_str());
}

void Map::save()
{

}

void Map::save(QString filename)
{
    filename_ = filename;
}

void Map::create_new(QString filename)
{
    filename_ = filename;
    std::ofstream out;
    out.open(filename_.toStdString().c_str());
}

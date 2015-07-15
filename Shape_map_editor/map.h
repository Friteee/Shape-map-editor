#ifndef MAP_H
#define MAP_H

#include <vector>
#include <QString>

class Map
{
public:
    Map();
    void open(QString filename);
    void save();
    void save(QString filename);
    void create_new(QString filename);
private:
    std::vector<int> tiles_;
    std::vector<int> types_;
    QString*background_;
    QString filename_;
};

#endif // MAP_H

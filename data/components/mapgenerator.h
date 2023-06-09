#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include <QSize>

struct coords {
    int x, y;
};

class MapGenerator {
public:
    MapGenerator();
    ~MapGenerator();
    static void generateMaze(int r, int c, int a, coords P0, coords Pf);
    static int getValueInPoint(int r, int c);
    static void generateRandomMaze();
    static void generateRandomMaze(int r);
    static void clearMap();
    static QSize getSize();

private:
    static MapGenerator* instance;
    static int** maze;
    static QSize size;
};

#endif // MAPGENERATOR_H

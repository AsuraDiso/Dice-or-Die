#include "mapgenerator.h"
#include <iostream>
#include <cstdlib>
#include <QTime>

MapGenerator *MapGenerator::instance = nullptr;
int** MapGenerator::maze = nullptr;
QSize MapGenerator::size = QSize(0, 0);

MapGenerator::MapGenerator()
{
    Q_ASSERT(instance == nullptr);
    instance = this;
}

MapGenerator::~MapGenerator()
{
   // Q_ASSERT(instance != nullptr);
    instance = nullptr;
}

QSize MapGenerator::getSize()
{
    return size;
}

void MapGenerator::generateRandomMaze()
{
    srand(static_cast<unsigned>(QTime::currentTime().msecsSinceStartOfDay()));

    int s = 10;
    coords p0, p1;
    p0.x = s / 2;
    p0.y = 0;
    p1.x = s / 2;
    p1.y = s - 1;
    int a = s*s/10;
    generateMaze(s, s, a, p0, p1);
}

void MapGenerator::generateRandomMaze(int r)
{
    srand(static_cast<unsigned>(QTime::currentTime().msecsSinceStartOfDay()));

    int s = r;
    coords p0, p1;
    p0.x = s / 2;
    p0.y = 0;
    p1.x = s / 2;
    p1.y = s - 1;
    int a = s*s/10;
    generateMaze(s, s, a, p0, p1);
}
int MapGenerator::getValueInPoint(int r, int c)
{
    return maze[r][c];
}

void MapGenerator::generateMaze(int r, int c, int a, coords P0, coords Pf)
{
    size.setHeight(c);
    size.setWidth(r);

    int ROWS = r;
    int COLS = c;

    maze = new int*[ROWS];
    for (int i = 0; i < ROWS; i++) {
        maze[i] = new int[COLS];
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = 0;
        }
    }

    bool** seen = new bool*[ROWS];
    for (int i = 0; i < ROWS; i++) {
        seen[i] = new bool[COLS];
        for (int j = 0; j < COLS; j++) {
            seen[i][j] = false;
        }
    }

    int* previous = new int[ROWS * COLS];
    for (int i = 0; i < ROWS * COLS; i++) {
        previous[i] = -1;
    }

    int* to_stack = new int[ROWS * COLS * 2];
    int to_stack_size = 0;
    to_stack[to_stack_size++] = P0.x;
    to_stack[to_stack_size++] = P0.y;

    while (to_stack_size > 0) {
        int random_index = rand() % (to_stack_size / 2);
        int current_x = to_stack[random_index * 2];
        int current_y = to_stack[random_index * 2 + 1];
        to_stack[random_index * 2] = to_stack[(to_stack_size / 2 - 1) * 2];
        to_stack[random_index * 2 + 1] = to_stack[(to_stack_size / 2 - 1) * 2 + 1];
        to_stack_size -= 2;

        seen[current_x][current_y] = true;

        if (current_x + 1 < ROWS && maze[current_x + 1][current_y] == 1 && previous[current_x * COLS + current_y] != (current_x + 1) * COLS + current_y)
            continue;
        if (current_x > 0 && maze[current_x - 1][current_y] == 1 && previous[current_x * COLS + current_y] != (current_x - 1) * COLS + current_y)
            continue;
        if (current_y + 1 < COLS && maze[current_x][current_y + 1] == 1 && previous[current_x * COLS + current_y] != current_x * COLS + current_y + 1)
            continue;
        if (current_y > 0 && maze[current_x][current_y - 1] == 1 && previous[current_x * COLS + current_y] != current_x * COLS + current_y - 1)
            continue;

        maze[current_x][current_y] = 1;

        if (current_x + 1 < ROWS && !seen[current_x + 1][current_y]) {
            seen[current_x + 1][current_y] = true;
            to_stack[to_stack_size++] = current_x + 1;
            to_stack[to_stack_size++] = current_y;
            previous[(current_x + 1) * COLS + current_y] = current_x * COLS + current_y;
        }

        if (current_x > 0 && !seen[current_x - 1][current_y]) {
            seen[current_x - 1][current_y] = true;
            to_stack[to_stack_size++] = current_x - 1;
            to_stack[to_stack_size++] = current_y;
            previous[(current_x - 1) * COLS + current_y] = current_x * COLS + current_y;
        }

        if (current_y + 1 < COLS && !seen[current_x][current_y + 1]) {
            seen[current_x][current_y + 1] = true;
            to_stack[to_stack_size++] = current_x;
            to_stack[to_stack_size++] = current_y + 1;
            previous[current_x * COLS + current_y + 1] = current_x * COLS + current_y;
        }

        if (current_y > 0 && !seen[current_x][current_y - 1]) {
            seen[current_x][current_y - 1] = true;
            to_stack[to_stack_size++] = current_x;
            to_stack[to_stack_size++] = current_y - 1;
            previous[current_x * COLS + current_y - 1] = current_x * COLS + current_y;
        }

        if (current_x == Pf.x && current_y == Pf.y) {
            break;
        }
    }

    maze[P0.x][P0.y] = 2;
    maze[Pf.x][Pf.y] = 3;

    int am = 0;
    int ac = 0;
    int cm = a/2;
    bool shouldspawnshop = (rand() % 3 < 1);
    qDebug() << shouldspawnshop;
    bool spawnedshop = false;
    int attempts = 0;
    while ((am < a or ac < cm or (shouldspawnshop and not spawnedshop)) and (attempts < ROWS*COLS*2)) {
        for (int i = 1; i < ROWS-1; i++) {
            if (am >= a and ac >= cm and spawnedshop) break;
            for (int j = 1; j < COLS-1; j++) {
                if (am >= a and ac >= cm and spawnedshop) break;
                if (shouldspawnshop and not spawnedshop and rand() % 10 < 1){
                    spawnedshop = true;
                    maze[i][j] = 6;
                }
                if (maze[i][j-1]==4 or maze[i][j+1]==4 or maze[i-1][j]==4 or maze[i+1][j]==4) {attempts++; continue;}
                if (maze[i][j] == 1 and (rand() % 2 < 1) and (ac < cm)) {
                    ac++;
                    maze[i][j] = 5;
                }
                if (maze[i-1][j-1]==4 or maze[i+1][j-1]==4 or maze[i-1][j+1]==4 or maze[i+1][j+1]==4) {attempts++; continue;}
                if (maze[i][j] == 1 && (rand() % 2 < 1) and (am < a)) {
                    am++;
                    maze[i][j] = 4;
                }
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        delete[] seen[i];
    }
    delete[] seen;
    delete[] previous;
    delete[] to_stack;

    if (attempts > ROWS*COLS*2) generateRandomMaze();
}

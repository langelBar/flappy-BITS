#include <iostream>
#include <basics.h>

using namespace std;

#ifndef TUBE_H
#define TUBE_H

struct locate{
    int x;
    int y;
    bool estado;
};

class tube : public basics
{
private:
    locate loc[30];
    int sup;
    int inf;
    int mov;
public:
    tube();
    int getMov() const;
    void setMov(int newMov);
    int getSup() const;
    void setSup(int newSup);
    int getInf() const;
    void setInf(int newInf);
    void drawTube();
    void clearTube();
    bool compare(int datX,int datY);
    void changeSize();
    void iniLoc(int f);
};

#endif // TUBE_H

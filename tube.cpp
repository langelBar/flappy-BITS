#include <math.h>
#include "tube.h"

int tube::getMov() const
{
    return mov;
}

void tube::setMov(int newMov)
{
    mov = newMov;
}

int tube::getSup() const
{
    return sup;
}

void tube::setSup(int newSup)
{
    sup = newSup;
}

int tube::getInf() const
{
    return inf;
}

void tube::setInf(int newInf)
{
    inf = newInf;
}

void tube::drawTube()
{
    for (int i = 1; i < 29+1; ++i) {
        if(this->loc[i].estado!=true){
             basics::changeColor(42);basics::gotoxy(this->mov,i);cout<<"#";
             basics::changeColor(14);
        }
        this->loc[i].x=mov;
    }

}

void tube::clearTube()
{
    for (int i = 1; i < 29+1; ++i) {
        basics::gotoxy(this->mov,i);cout<<" ";
    }
    this->mov--;
    if(mov==1){
        this->mov=79;
        iniLoc(mov);
    }
}

bool tube::compare(int datX, int datY)
{
    for (int i = 0; i < 29+1; ++i) {
        if(datX==this->loc[i].x && datY==this->loc[i].y && this->loc[i].estado==false){
            return true;
        }
    }
    return false;
}

void tube::changeSize()
{
    this->inf=rand()-1;
}

void tube::iniLoc(int f)
{
    int dat=rand()%20 + 5;
    for (int i = 0; i < 30 -1; ++i) {
        this->loc[i].y=i+1;
        this->loc[i].x=f;
        this->loc[i].estado=false;
    }
    for (int a = dat ; a < dat+5; ++a) {
        this->loc[a].estado=true;
    }
}

tube::tube()
{
    this->inf=0;
    this->sup=0;
    this->mov=79;
    changeSize();
    iniLoc(mov);
}

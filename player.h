#include <iostream>
#include <basics.h>

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class player : public basics
{
private:
    int mov;
    int contAnim;
    int score;
public:
    player();
    void drawPlayer();
    void clearPlayer();
    void move();
    int getMov() const;
    void setMov(int newMov);
    int getScore() const;
    void setScore(int newScore);
    void viewScore();
};

#endif // PLAYER_H

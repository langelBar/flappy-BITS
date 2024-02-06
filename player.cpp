#include "player.h"
#include <conio.h>
#define ENTER 13

int player::getMov() const
{
    return mov;
}

void player::setMov(int newMov)
{
    mov = newMov;
}

int player::getScore() const
{
    return score;
}

void player::setScore(int newScore)
{
    score = newScore;
}

void player::viewScore()
{
    gotoxy(82,3);cout<<"SCORE :"<<this->score;
}

player::player()
{
    this->mov=12;
    this->contAnim=0;
    this->score=0;
}

void player::drawPlayer()
{
    if(this->contAnim%4 == 0){
        basics::changeColor(6);gotoxy(1, mov);     printf("\\\\");
        basics::changeColor(7);gotoxy(1, mov+1);   printf("[*]>");
    }else {
        basics::changeColor(7);gotoxy(1, mov+1);   printf("[*]>");
        basics::changeColor(6);gotoxy(1, mov+2);   printf("//");
    }
    basics::changeColor(14);
    this->contAnim++;
}

void player::clearPlayer()
{
    gotoxy(1, mov);     printf("  ");
    gotoxy(1, mov+1);   printf("    ");
    gotoxy(1, mov+2);     printf("  ");
    if(contAnim>40){
        contAnim=0;
    }
    this->mov++;
}

void player::move()
{
    if(kbhit()){
        char tecla = getch();
        gotoxy(1, mov);     printf("  ");
        gotoxy(1, mov+1);   printf("    ");
        gotoxy(1, mov+2);     printf("  ");
        if(tecla == ENTER)this->mov=mov-3;

    }
}

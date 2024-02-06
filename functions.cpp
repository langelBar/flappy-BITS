#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;
int height=100;
int width=30;

void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

void chargeMenu(){
    for (int a = 0; a < height; ++a) {
        gotoxy(a,14); printf("%c",178);
        Sleep(1);
    }
}

void drawBoard(){
    for(int i=1;i<height;i++){
        gotoxy(i,0); printf("%c",205);
    }
    for(int e=1;e<height;e++){
        gotoxy(e,30); printf("%c",205);
    }
    for(int a=1;a<width;a++){
        gotoxy(100,a); printf("%c",186);
    }
    for(int b=1;b<width;b++){
        gotoxy(0,b); printf("%c",186);
    }
    //score
    for(int a=1;a<width;a++){
        gotoxy(80,a); printf("%c",186);
    }
    for(int b=80;b<height;b++){
        gotoxy(b,4); printf("%c",205);
    }
    gotoxy(80,4);printf("%c",204);
    gotoxy(100,4);printf("%c",185);
    gotoxy(80,30);printf("%c",202);
    gotoxy(80,0);printf("%c",203);
    //corners
    gotoxy(0,0); printf("%c",201);
    gotoxy(100,0); printf("%c",187);
    gotoxy(0,30); printf("%c",200);
    gotoxy(100,30); printf("%c",188);
}

int menu(){
    int dat=0;
    gotoxy(45,10);cout<<"MENU"<<endl;
    gotoxy(45,11);cout<<"1.-START GAME"<<endl;
    gotoxy(45,12);cout<<"2.-SCOREBOARD"<<endl;
    gotoxy(45,13);cout<<"3.-CONFIG"<<endl;
    gotoxy(45,14);cout<<"0.-exit"<<endl;
    do{
        gotoxy(45,16);cout<<"input : "<<endl;
        gotoxy(54,16);cin>>dat;
    }while(dat>4 || dat<0);
    return dat;
}

struct sPlayer{
    string name;
    int nmr;
};

struct nodoScore{
    sPlayer *info;
    nodoScore *sgte;
};

struct listScore{
    nodoScore *con;
    int total;
};


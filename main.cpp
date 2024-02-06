#include <iostream>
#include "functions.cpp"
#include <tube.h>
#include <player.h>
#include <fstream>

using namespace std;

void iniConfig(){
    basics::changeScreen();
    basics::disableCursor();
}


void startGame(int &pun){
    bool game=true;
    chargeMenu();
    system("cls");
    player player1=player();
    tube tube1=tube();
    tube tube2=tube();
    tube tube3=tube();
    tube2.setMov(60);
    tube3.setMov(40);
    drawBoard();
    do{
        player1.viewScore();
        player1.drawPlayer();
        if(tube1.compare(5,player1.getMov())||tube2.compare(5,player1.getMov())||tube2.compare(5,player1.getMov())){
            game=false;
        }
        player1.move();
        Sleep(30);
        tube1.drawTube();
        tube2.drawTube();
        tube3.drawTube();
        Sleep(30);
        if(player1.getMov()==28){
            game=false;
        }
        player1.clearPlayer();
        tube1.clearTube();
        tube2.clearTube();
        tube3.clearTube();
        player1.setScore(player1.getScore()+1);
    }while(game==true);
    pun=player1.getScore();
}


void insertarNodo(listScore *lista,string nombre, int numero) {
    sPlayer* jugador = new sPlayer;
    jugador->name = nombre;
    jugador->nmr = numero;

    nodoScore* nuevoNodo = new nodoScore;
    nuevoNodo->info = jugador;
    nuevoNodo->sgte = nullptr;

    if (!lista->con) {
        lista->con = nuevoNodo;
    } else {
        nodoScore* actual = lista->con;
        while (actual->sgte) {
            actual = actual->sgte;
        }
        actual->sgte = nuevoNodo;
    }
    lista->total++;
}

void printList(listScore *lista) {
    nodoScore* actual = lista->con;
    while (actual) {
        cout << "Nombre: " << actual->info->name << ", Número: " << actual->info->nmr << endl;
                actual = actual->sgte;
    }
}

void loadData(ifstream &archivo,listScore *listaScore){
    archivo.open("datos.txt");
    if (!archivo) {
        cerr << "Error al abrir el archivo datos.txt" << endl;
        return;
    }
    string nombre;
    int numero;
    while (archivo >> nombre >> numero) {
        insertarNodo(listaScore, nombre, numero);
    }

    archivo.close();

}

void guardarListaEnArchivo(listScore *lista,int pun) {
    ofstream archivo("datos.txt");
    if (!archivo) {
        cerr << "Error al abrir el archivo " << "datos" << " para escritura." << endl;
        system("pause");
        return;
    }
    string nombre;
    system("cls");
    basics::gotoxy(10,15);cout<<"INGRESE SU NOMBRE DE JUGADOR:";
    basics::gotoxy(40,15);cin>>nombre;
    system("cls");
    insertarNodo(lista,nombre,pun);
    nodoScore* actual = lista->con;
    while (actual) {
        archivo << actual->info->name << " " << actual->info->nmr << endl;
        actual = actual->sgte;
    }

    archivo.close();
}


int main()
{
    ifstream data;
    int pun=0,numero=14,opc=0;
    listScore *listaScore = new listScore();
    listaScore->con=NULL;
    listaScore->total=0;
    loadData(data,listaScore);
    iniConfig();
    basics::changeColor(numero);chargeMenu();
    do{
        system("cls");
        opc=menu();
        system("cls");
        switch (opc) {
        case 1:
            startGame(pun);
            guardarListaEnArchivo(listaScore,pun);
            break;
        case 2:
            printList(listaScore);
            system("pause>>NULL");
            break;
        case 3:
            system("cls");
            cout<<"INGRESE UN NUMERO PARA CAMBIAR EL COLOR:";
            cin>>numero;
            break;
        case 0:

            break;
        default:
            break;
        }
    }while(opc!=0);
}

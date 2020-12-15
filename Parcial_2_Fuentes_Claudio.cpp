#include <iostream>
#include <locale.h>

using namespace std;

char tateti[3][3]={'1','2','3','4','5','6','7','8','9'}, player1[12]={"Jugador 'X'"}, player2[12]={"Jugador 'O'"};
char inPlayer[2]={"0"}, turnPlayer[2]={"0"};
int posBusy[9]={0,0,0,0,0,0,0,0,0};
int coinPlay=0, jump=0, turn=1, posTable1=0, posTable2=0, games=0, x=0, y=0;
bool tie1=false, tie2=false, goOn1=false, goOn2=false, repeat=false;
void gameTable(){ //Tablero principal de juego TaTeTi
    for(int f=0;f<3;f++){
        jump=1;
        cout<<"        | ";
        for (int c=0;c<3;c++){
            cout << tateti[f][c] <<" | ";
            if(jump==3){
                cout<<endl;
            }
            jump++;
        }
    }

}
void startTateti(){ //Comienzo de juego
    while (repeat==false){ //Para el caso que el usuario ingrese int diferentes de 1 o 2 ó caracteres.
           cout<<"Para "<<player1<<" ingresá el 1 y para "<<player2<<" ingresá el 2: ";
           cin>>turnPlayer;
           y=atoi (turnPlayer); //Atoi convierte un char en int. Acera Garcia M. imp. c++ (pag 218).
           if (y==1 || y==2){
              turn=y;
              repeat=true;
           }
           else{
              cout<<"Por favor ingrese solamente 1 ó 2, gracias."<<endl;
           }
    }
}
void win2(){ //Se verifica si jugador O gana.
    int c=0;
    while (c<3){ //Se comparan las 8 posibles jugadas ganadoras con el jugador O.
        if  (  (tateti[0][c]=='O'
            && tateti[1][c]=='O'
            && tateti[2][c]=='O')
            || (tateti[c][0]=='O'
            && tateti[c][1]=='O'
            && tateti[c][2]=='O')
            || (tateti[0][0]=='O'
            && tateti[1][1]=='O'
            && tateti[2][2]=='O')
            || (tateti[2][0]=='O'
            && tateti[1][1]=='O'
            && tateti[0][2]=='O')){
            cout<<endl<<"****¡¡G A N O!!****"<<player2<<"****"<<endl;
            games=9; // Si se verifica una jufada ganadora de iguala a 9 games para terminar el while del main.
            c=3; // Si se verifica una jufada ganadora de iguala a 3 c  para terminar el while de este void.
            tie2=false;
            }
            else{
                tie2=true;
            }
        c++;
    }
}
void win1(){  //Se verifica si jugador X gana.
    int c=0;
    while (c<3){  //Se comparan las 8 posibles jugadas ganadoras con el jugador X.
        if  ( (tateti[0][c]=='X'
            && tateti[1][c]=='X'
            && tateti[2][c]=='X')
            ||(tateti[c][0]=='X'
            && tateti[c][1]=='X'
            && tateti[c][2]=='X')
            ||(tateti[0][0]=='X'
            && tateti[1][1]=='X'
            && tateti[2][2]=='X')
            ||(tateti[2][0]=='X'
            && tateti[1][1]=='X'
            && tateti[0][2]=='X')){
            cout<<endl<<"****¡¡G A N O!!****"<<player1<<"****"<<endl;
            games=9; // Si se verifica una jufada ganadora de iguala a 9 games para terminar el while del main.
            c=3; // Si se verifica una jufada ganadora de iguala a 3 c  para terminar el while de este void.
            tie1=false;
            }
            else{
                tie1=true;
            }
        c++;
    }
}
void gameTie(){ //Verifica que se completó la partida y a resultado en empate.
    if (games==9 && tie1==true && tie2==true){
    cout<<endl<<"********¡¡E M P A T E!!********"<<endl;
    }

}
int main(){ //Llenado por turno del tablero.
setlocale(LC_ALL,"spanish");
    cout<<"         *****T a T e T i*****"<<endl;
    cout<<"**Elegir quién comienza!**"<<endl;
    startTateti();
    cout<<endl;
    gameTable();
    while(games<9){ //Comienza la iteración hasta completar los casilleros o haya un ganador.
          turn=turn%2; //La variable irá alternando entre 1 y 0.
          goOn1=false; //Para que continúe en el mismo player si es que elijió un casillero ocupado.
          goOn2=false; //Para que continúe en el mismo player si es que elijió un casillero ocupado.
          switch(turn){ //Turnos de los jugadores 1 ó 2.
                case 1 : while (goOn1==false){ //Continuará hasta que el casillero elejido esté libre.
                                cout<<endl<<player1<<" Escoja su casillero: ";
                                cin>>inPlayer; //Ingresa el lugar donde quiere colocar su ficha.
                                posTable1= atoi (inPlayer); //Atoi (array to integer) convierte un char en int. Acera Garcia M. imp. c++ (pag 218).
                                posTable1<=9 ? x=1:x=0;
                            if (x==1 && posTable1!=posBusy[0]   //Se controla que el casillero no esté utilizado.
                                && posTable1!=posBusy[1]
                                && posTable1!=posBusy[2]
                                && posTable1!=posBusy[3]
                                && posTable1!=posBusy[4]
                                && posTable1!=posBusy[5]
                                && posTable1!=posBusy[6]
                                && posTable1!=posBusy[7]
                                && posTable1!=posBusy[8]){
                                posBusy[games]=posTable1;
                                coinPlay=posBusy[games];
                                goOn1=true;
                            }
                            else{
                                cout<<"Número o caracter inválido vuelva a elegir!"<<endl;
                            }
                        }
                                break;
                case 0 : while (goOn2==false){ //Continuará hasta que el casillero elejido esté libre.
                            cout<<endl<<player2<<" Escoja su casillero: ";
                            cin>>inPlayer; //Ingresa el lugar dnde quiere colocar su ficha.
                            posTable2=atoi (inPlayer); //Atoi convierte un char en int. Acera Garcia M. imp. c++ (pag 218).
                            posTable2<=9 ? x=1:x=0;
                            if (x==1 && posTable2!=posBusy[0]  //Se controla que el casillero no esté utilizado.
                                && posTable2!=posBusy[1]
                                && posTable2!=posBusy[2]
                                && posTable2!=posBusy[3]
                                && posTable2!=posBusy[4]
                                && posTable2!=posBusy[5]
                                && posTable2!=posBusy[6]
                                && posTable2!=posBusy[7]
                                && posTable2!=posBusy[8]){
                                posBusy[games]=posTable2;
                                coinPlay=posBusy[games];
                                goOn2=true;
                            }
                            else{
                                cout<<"Número o caracter inválido vuelva a elegir!"<<endl;
                            }
                         }
                         break;
                default : cout<<"Elección inválida!";
            }
        if (turn==1){ //Si es el turno del jugador X se colocará la ficha dónde haya elejido.
            switch(coinPlay){
                case 1 : tateti[0][0]={'X'};
                        break;
                case 2 : tateti[0][1]={'X'};
                        break;
                case 3 : tateti[0][2]={'X'};
                        break;
                case 4 : tateti[1][0]={'X'};
                        break;
                case 5 : tateti[1][1]={'X'};
                        break;
                case 6 : tateti[1][2]={'X'};
                        break;
                case 7 : tateti[2][0]={'X'};
                        break;
                case 8 : tateti[2][1]={'X'};
                        break;
                case 9 : tateti[2][2]={'X'};
                        break;
            }
        }
        else{ //Si no, es el turno del jugador O se colocará la ficha dónde haya elejido.
            switch(coinPlay){
                case 1 : tateti[0][0]={'O'};
                       break;
                case 2 : tateti[0][1]={'O'};
                       break;
                case 3 : tateti[0][2]={'O'};
                       break;
                case 4 : tateti[1][0]={'O'};
                       break;
                case 5 : tateti[1][1]={'O'};
                       break;
                case 6 : tateti[1][2]={'O'};
                       break;
                case 7 : tateti[2][0]={'O'};
                       break;
                case 8 : tateti[2][1]={'O'};
                       break;
                case 9 : tateti[2][2]={'O'};
                       break;
            }
        }
        games++; //contador de jugadas
        turn++; //para cambiar de turno de los jugadores.
        cout<<endl;
        gameTable(); //Va actualizando el tablero.
        win1(); //Verifica si el jugador X es el ganador.
        win2(); //Verifica si el jugador O es el ganador.
        gameTie(); //Verifica que se completó la partida y a resultado en empate.
    }
    cout<<endl<<"         *****T a T e T i*****"<<endl;
    return 0;
}

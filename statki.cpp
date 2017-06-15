#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;
int d;//czy zostal na tablicy jakis statek
int q;//sprawdza trafienie

void rys(char t[10][10]) //rysowanie planszy
{
    cout<<"   ";
    for(int i=0; i<10; i++)
    {
        cout<<i<<" ";
    }
    cout<<"X ";
    cout<<"\n";

    for(int i=0; i<10; i++)
    {
        cout<<" "<<i<<" ";
        for(int j=0; j<10; j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<" ";
        cout<<"\n";
    }

    cout<<" Y";
    cout<<endl<<endl;

}

void rys2(char t[10][10]) //rysowanie okretow komputera jako kropki, gracz nie widzi statkow
{
    cout<<"   ";
    for(int i=0; i<10; i++)
    {
        cout<<i<<" ";
    }
    cout<<"X";
    cout<<"\n";

    for(int i=0; i<10; i++)
    {
        cout<<" "<<i<<" ";
        for(int j=0; j<10; j++)
        {
            if(t[i][j]=='O')
            {
                t[i][j]='.';
                cout<<t[i][j]<<" ";
                t[i][j]='O';
            }
            if(t[i][j]!='O')
            {
                cout<<t[i][j]<<" ";
            }
        }
        cout<<"\n";
    }

    cout<<" Y";
    cout<<endl<<endl;
}

void kropki(char t[10][10]) //wypelnienie tablicy "." siatka strzalow
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            t[i][j]='.';
        }
    }
}

bool sprawdz(char t[10][10],int x, int y)//sprawdza, czy mozna wstawic 'O' w pozycje x y
{
    if (x<0 || x>9 || y<0 || y>9) return false;
    for (int i=x-1; i<=x+1; i++)
        for( int j=y-1; j<=y+1; j++)
            if (!(i<0 || i>9 || j<0 || j>9) && t[i][j]=='O') return false;
    return true;
}

void losuj1(char t[10][10]) //jednomasztowiec x4
{
    int x,y;
    for(int a=1; a<5; a++)
    {
        do
        {
            x=rand()%10;
            y=rand()%10;
        }
        while(!sprawdz(t,x,y));
        t[x][y]='O';
    }
}
void losuj2(char t[10][10]) //dwumasztowiec x3
{
    int x,y,z;
    for(int a=1; a<4; a++)
    {
        z=rand()%2; //losuj orientacje pionowo / poziomo
        if(z==1)
        {
            do
            {
                do
                {
                    x=rand()%10;
                    y=rand()%10;
                }
                while(!sprawdz(t,x,y));
                x=x+1;
            }
            while(!sprawdz(t,x,y));
            t[x][y]='O';
            x=x-1;
            t[x][y]='O';
        }
        else
        {
            do
            {
                do
                {
                    x=rand()%10;
                    y=rand()%10;
                }
                while(!sprawdz(t,x,y));
                y=y+1;
            }
            while(!sprawdz(t,x,y));
            t[x][y]='O';
            y=y-1;
            t[x][y]='O';
        }
    }
}
void losuj3(char t[10][10]) //trzymasztowiec x2
{
    int x,y,z;
    for(int a=1; a<3; a++)
    {
        z=rand()%2;
        if(z==1)
        {
            do
            {
                do
                {
                    do
                    {
                        x=rand()%10;
                        y=rand()%10;
                    }
                    while(!sprawdz(t,x,y));
                    x=x+1;
                }
                while(!sprawdz(t,x,y));
                x=x+1;
            }
            while(!sprawdz(t,x,y));
            t[x][y]='O';
            x=x-1;
            t[x][y]='O';
            x=x-1;
            t[x][y]='O';
        }
        else
        {
            do
            {
                do
                {
                    do
                    {
                        x=rand()%10;
                        y=rand()%10;
                    }
                    while(!sprawdz(t,x,y));
                    y=y+1;
                }
                while(!sprawdz(t,x,y));
                y=y+1;
            }
            while(!sprawdz(t,x,y));
            t[x][y]='O';
            y=y-1;
            t[x][y]='O';
            y=y-1;
            t[x][y]='O';
        }

    }
}
void losuj4(char t[10][10]) //czteromasztowce 1
{
    int x,y,z;
    for(int a=1; a<2; a++)
    {
        z=rand()%2;
        if(z==1)
        {
            do
            {
                do
                {
                    do
                    {
                        do
                        {
                            x=rand()%10;
                            y=rand()%10;
                        }
                        while(!sprawdz(t,x,y));
                        x=x+1;
                    }
                    while(!sprawdz(t,x,y));
                    x=x+1;
                }
                while(!sprawdz(t,x,y));
                x=x+1;
            }
            while(!sprawdz(t,x,y));
            t[x][y]='O';
            x=x-1;
            t[x][y]='O';
            x=x-1;
            t[x][y]='O';
            x=x-1;
            t[x][y]='O';
        }
        else
        {
            do
            {
                do
                {
                    do
                    {
                        do
                        {
                            x=rand()%10;
                            y=rand()%10;
                        }
                        while(!sprawdz(t,x,y));
                        y=y+1;
                    }
                    while(!sprawdz(t,x,y));
                    y=y+1;
                }
                while(!sprawdz(t,x,y));
                y=y+1;
            }
            while(!sprawdz(t,x,y));
            t[x][y]='O';
            y=y-1;
            t[x][y]='O';
            y=y-1;
            t[x][y]='O';
            y=y-1;
            t[x][y]='O';
        }

    }
}
void strzal(char t[10][10])
{
    int x,y;
    do
    {
        do
        {
            cout<<"Podaj X:";
            cin>>y;
            //y=rand()%10;
        }
        while(y>9);

        do
        {
            cout<<"Podaj Y:";
            cin>>x;
            //x=rand()%10;
        }
        while(x>9);
    }
    while(t[x][y]=='N' || t[x][y]=='T');
    if(t[x][y]=='.')
    {
        t[x][y]='N';
        q=0;
    }
    if(t[x][y]=='O')
    {
        t[x][y]='T';
        q=1;
    }
}
void kstrzal(char t[10][10])

{
    int x,y;
    do
    {
        x=rand()%10;
        y=rand()%10;
    }
    while(t[x][y]=='N' || t[x][y]=='T');
    if(t[x][y]=='.')
    {
        t[x][y]='N';
        q=0;
    }
    if(t[x][y]=='O')
    {
        t[x][y]='T';
        q=1;
    }

}
bool spr(char t[10][10])
{

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(t[i][j]=='O')
            {
                return true; //sprawdz czy jest okret na planszy
            }
        }
    }
    return false;
}


int main()
{
    srand(time(0));
    int b;
    char t1[10][10];
    char t2[10][10];

    do
    {
        cout<<"Chcesz zagrac? Tak(1) / Nie(2):  ";
        cin>>b;
        cout<<endl;
        //zabezpieczenie przed zla opcja
        if(b>2)
        {
            //drastyczne zakonczenie
            cout<<"Nieznana opcja.\n";
            system("PAUSE");
        }
        if(b<1)
        {
            //drastyczne zakonczenie
            cout<<"Nieznana opcja.\n";
            system("PAUSE");
        }
        if(b==2)
        {
            return EXIT_SUCCESS;
        }

        ////////////////////////////////////////////wlasciwa gra
        if(b==1)
        {
            //wypelnij kropkami plansze
            kropki (t1);
            kropki (t2);

            //losuj statki gracza
            losuj4(t1);
            losuj3(t1);
            losuj2(t1);
            losuj1(t1);
            cout<<"!!! Okrety zostaly ustawione losowo !!!"<<endl<<endl;
            cout<<"Legenda:\nN --- Nie trafiony statek \nT --- Trafiony statek \nO --- Statek\n"<<endl;
            cout<<"Statki gracza"<<endl;
            rys(t1);

            //losuj statki komputera
            losuj4(t2);
            losuj3(t2);
            losuj2(t2);
            losuj1(t2);

            int liczPartie=1;
            char a=true;
            char b=true;
            while(a && b )
            {
                cout<<"Partia nr: "<<liczPartie<<endl;
                do
                {
                    strzal(t2); //jesli gracz i komputer
                    //kstrzal(t2); //jesli chcesz zeby graly 2 kompy
                    cout<<"Ruch Gracza: --- strzaly Gracza na planszy komputera\n";
                    if(q==1)
                        cout<<"BONUS --- dodatkowy strzal gracza !!!"<<endl;
                    rys2(t2);
                }
                while(q==1);  //dodatkowy strzal

                do
                {
                    kstrzal(t1);
                    cout<<"Ruch Komputera: --- strzaly komputera na planszy Gracza\n";
                    if(q==1)
                        cout<<"BONUS --- dodatkowy strzal dla komputera !!!"<<endl;
                    rys(t1);
                }
                while(q==1);  // dodatkowy

                liczPartie++;
                a=spr(t1);
                b=spr(t2);
            }

            cout<<"*** Wynik ***"<<endl;

                cout<<"Okrety Gracza:\n";
                rys(t1);

                cout<<"Okrety Komputer:\n";
                rys(t2);
        }
    }
    while(b==1);
    return 0;
}

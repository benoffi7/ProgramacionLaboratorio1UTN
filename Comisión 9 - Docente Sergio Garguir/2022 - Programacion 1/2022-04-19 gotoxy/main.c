#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "gotoxy.h"

int main()
{
    char c=0;
    int x=0;
    int y=0;
    int i=0;

    hidecursor(0);
    color(9);
    gotoxy(x, y);
    printf("%c", 219);

    do{
        c=getch();

        switch(c){
            case 27:
                x=10;
                y=10;
                while(!kbhit()){
                    color(i);
                    i++;
                    gotoxy(x,y);
                    printf("Hasta la vista Baby........");
                    Sleep(500);
                }
                getch();
                system("cls");
                break;
            case 59:
                color(9);
                break;
            case 60:
                color(10);
                break;
            case 61:
                color(11);
                break;
            case 62:
                color(12);
                break;
            case 63:
                color(13);
                break;
            case 64:
                color(14);
                break;
            case 72:
                if(y>0){
                    y--;
                    gotoxy(x,y);
                    printf("%c",219);
                }else{
                    Beep(523,523);
                }
                break;
            case 75:
                if(x>0){
                    x--;
                    gotoxy(x,y);
                    printf("%c",219);
                }else{
                    Beep(523,523);
                }
            break;
            case 77:
                if(x<79){
                    x++;
                    gotoxy(x,y);
                    printf("%c",219);
                }else{
                    Beep(523,523);
                }
                break;
            case 80:
                if(y<25){
                    y++;
                    gotoxy(x,y);
                    printf("%c",219);
                }else{
                    Beep(523,523);
                }
                break;
        }
    }while(c!=27);

    return 0;
}

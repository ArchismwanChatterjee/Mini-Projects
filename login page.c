#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
char set[6];

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int suggest()
{
    srand(time(0));
    set[6];
    char i;
    for (i = 0; i < 6; i++)
    {
        set[i] = 33 + (rand() % (126 - 33));
    }
    for (i = 0; i < 6; i++)
    {
        printf("%c", set[i]);
    }
    Sleep(3000);
    return 0;
}

int mannual()
{
    set[6];
    for (int i = 0; i < 6; i++)
        set[i] = getch();
}

int main()
{
start:
    system("cls");
    srand(time(0));
    int flag = 0, ch;
    printf("WELCOME\n");
    printf("Please set your password before logging in to the portal \n");
    gotoxy(50, 10);
    printf("Set your password\n");

    printf("1.Use suggested strong password\n2.Enter manually \n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        suggest();
        break;
    case 2:
        mannual();
        break;
    default:
        printf("Wrong Input");
        break;
    }
    if (ch != 1 && ch != 2)
        exit(0);

    printf("\n You will be automatically generated to login portal after few secs ");
    int i = 1 + rand() % 9;
    Sleep(1000);

    for (i; i >= 0; i--)
    {
        system("cls");
        printf("%d", i % 60);
        Sleep(1000);
    }

    printf("\n Wait generating the portal");
    Sleep(500);

    system("cls");
    gotoxy(10, 10);
    printf("Enter your password \n");
    int get[6];

    for (int i = 0; i < 6; i++)
    {
        get[i] = getche();
        Sleep(1);
        printf("\b*");
    }

    for (int i = 0; i < 6; i++)
    {
        if (set[i] != get[i])
            flag++;
    }

    if (flag == 0)
    {
        system("cls");
        gotoxy(10, 10);
        printf("***************Password is correct***************\n");
    }
    else
    {
        system("cls");
        gotoxy(10, 10);
        printf("***************Password is incorrect***************\n");
        Sleep(500);
        system("cls");
        goto start;
    }

    return 0;
}

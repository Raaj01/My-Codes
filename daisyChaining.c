#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <time.h>
struct Device
{
    char deviceName;
    int PI;
    int PO;
    int INT;
    int deviceCount;
};
int main()
{
    int i, n, j, INTA = 1;
    struct Device devices[5];
    char choice;
    do{
    for (i = 0; i < 5; i++)
    {
        devices[i].deviceName = 'A' + i;
        devices[i].PI = 0;
        devices[i].PO = 0;
        devices[i].INT = 1;
        devices[i].deviceCount = 0;
    }
    printf("The devices are\n");
    for (i = 0; i < 5; i++)
    {
        printf("%c\t", devices[i].deviceName);
    }
    printf("\nEnter the no of time to run interrupts: ");
    scanf("%d", &n);
    srand(time(0));
    for (i = 0; i < n; ++i)
    {
        int k;
        k = rand() % 5;
        devices[k].INT = 0;
        devices[0].PI = INTA;
        for (j = 0; j < 5; ++j)
        {
            // printf("k=%d\t", k);
            if (devices[j].INT != 0)
            {
                devices[j].PO = devices[j].PI;
                devices[j + 1].PI = devices[j].PO;
            }
            else
            {
                ++devices[j].deviceCount;
                devices[j].INT=1;
                break;
            }
            devices[j].PI=0;
            devices[j].PO=0;
        }
    }
    int tempCounter=0;
    printf("The result are: \n");
    for (i = 0; i < 5; i++)
    {
        printf("%c : %d\n", devices[i].deviceName, devices[i].deviceCount);
        tempCounter=tempCounter+devices[i].deviceCount;
    }
    printf("Total : %d",tempCounter);
    printf("\nDo you want to continue(Y/N) : ");
    scanf("%s",&choice);
    }while(choice=='y'||choice=='Y');
    return(0);
}


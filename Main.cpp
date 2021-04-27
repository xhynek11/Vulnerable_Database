#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stdlib.h>
#include "Functions.h"


int main(void) {
    int authorized = 0;
    char sys_pass[8] = "secret!";
    char usr_pass[8];

    int isVisible = 0;
    char findigIn[8];

    char byClass[8];
    int canAcces = 0;
    int navigace = 0;
    int admGue = 0;
    bool wrngPsw = true;
    bool isLogin = true;
    int trashBin = 0;

    while (true) {

        printf("Continue like Admin[0] or Guest[1]?");
        scanf("%d", &admGue);
        if (admGue == 0)
        {
            system("cls");
            while (wrngPsw) {
                printf("Enter Password: ");
                scanf("%s", usr_pass);
                if (strcmp(sys_pass, usr_pass) == 0) {
                    authorized = 1;
                    isVisible = 1;
                    wrngPsw = false;
                    isLogin = true;
                }
                else
                {
                    system("cls");
                    printf("Error[Wrong Password!]\n");
                    wrngPsw = true;
                }
            }
        }
        else if (admGue == 1) {
            authorized = 0;
            isVisible = 0;
            isLogin = true;
        }

        while (isLogin) {
            system("cls");
            printf("\nSelect your action: ");
            printf("\n[1] Read Database");
            printf("\n[2] Edit Database");
            printf("\n[3] Find Students By Class");
            printf("\n[4] Add User To Database");
            printf("\n[5] Logout");
            printf("\n[6] Exit");
            printf("\n");
            scanf("%d", &navigace);
            switch (navigace)
            {
            case 1:
                readFile(isVisible);
                printf("Enter [0] for continue: ");
                scanf("%d", &trashBin);
                break;
            case 2:
                changeFile(authorized);
                printf("Enter [0] for continue: ");
                scanf("%d", &trashBin);
                break;
            case 3:
                printf("enter class[IBEP],[PFMAN],[UFYZ]: ");
                scanf("%s", byClass);
                sprintf(findigIn, byClass);
                printf("Finding users in class %s\n", findigIn);

                /*   printf("\n    byClass:   %s\n", byClass);
                   printf("    findigIn:  %s\n", findigIn);
                   printf("    isVisible: %d\n", isVisible);
                   printf("    byClass   addres: %p\n", (void*)byClass);
                   printf("    findigIn  addres: %p\n", (void*)findigIn);
                   printf("    isVisible addres: %p\n\n", (void*)&isVisible);*/

                findByClass(byClass, isVisible);
                printf("Enter [0] for continue: ");
                scanf("%d", &trashBin);
                break;
            case 4:
                addUser();
                printf("User succesfully add to Database");
                printf("Enter [0] for continue: ");
                scanf("%d", &trashBin);
                break;
            case 5:
                isLogin = false;
                break;
            case 6:
                return 0;
                break;
            default:
                break;
            }
        }
    }
}
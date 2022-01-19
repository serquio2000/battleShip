#define _CRT_SECURE_NO_WARNINGS
#define ROW 10
#define COLS 10
#include <stdio.h>
#include<conio.h>
void main() {
    int option = 0, table[ROW][COLS], table2[ROW][COLS];
    int positionX = 0;
    char positionY = 0;
    for (int i = 0; i < COLS; i++) {        //loop for do table game
        for (int j = 0; j < ROW; j++) {
            table[i][j] = 0;
        }
    }
   
    //main menu 
    do {//menu options validate
        printf("1.easy\n 2.medium\n 3.hard\n 4.extreme\n 0.Exit\n"); //option for choose difficulty
        printf("what difficulty would you like to select:\n");
        scanf("%d", &option);

        switch (option) {

        case 1:
            printf("the difficulty  is easy:\n");  //option1

            break;
        case 2:
            printf("the difficulty  is medium:\n"); //option2

            break;
        case 3:
            printf("the difficulty  is hard:\n");  //option3

            break;
        case 4:
            printf("the difficulty  is extreme:\n"); //option4

            break;
        default:

            printf("try again,select other number: \n"); // any option


        }



    } while (option < 1 || option >4);
    //build float
    for (int i = 0; i < 4; i++) {   //loop for choose position of ship 
        printf("BUILD YOUR FLOAT\n");
        printf("  ");
        for (int n = 0; n < COLS; n++) {
            printf(" %c", n + 65); // variable plus digit of list ascii to print letters
        }

        printf("\n");
        for (int y = 0; y < ROW; y++) {
            printf("%*d", 2, y + 1);//number rows

            for (int x = 0; x < COLS; x++)
            {

                if (table[y][x] != 1)
                {
                    printf(" %c", 254);//character used for free space
                }
                else
                {
                    printf(" %c", 88);//character used for target selection 
                }
            }
            printf("\n");
        }


        do {//row validate
            printf("\n\n insert value of row: ");
            fflush(stdin);
            scanf("%d", &positionX);
        } while (positionX < 0 || positionX>10);
        do {//cols validate
            printf("insert value of cols: ");
            fflush(stdin);
            scanf(" %c", &positionY);
        } while (positionY < 96 || positionY >106);
        table[positionX - 1][positionY - 97] = 1;// assign value to array according to the value  input keyboard 
        getchar();
        getchar();
    }
    //try to guess the float
    //start array table to zero
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROW; j++) {
            table2[i][j] = 0;
        }
    }
        //start loop targets 
    for (int i = 0; i < 4; i++) {
        printf("TARGET TO ATTACK\n");
        printf("  ");
        //loop for cols
        for (int n = 0; n < COLS; n++) {
            printf(" %c", n + 65);
        }
        printf("\n");
        //loop for rows
        for (int y = 0; y < ROW; y++) {
            printf("%*d", 2, y + 1);
            //loop for compare if is target of not target
            for (int x = 0; x < COLS; x++)
            {

                if (table2[y][x] == 1)
                {
                    printf(" %c", 88);//pass to select 
                }
                else if (table2[y][x] == 2) {
                    printf(" %c", 43); // fail to select
                }
                else
                {
                    printf(" %c", 45); // free space
                }
            }
            printf("\n");
        }


        do {//validar row
            printf("\n\n insert value of row: ");
            fflush(stdin);
            scanf("%d", &positionX);
        } while (positionX < 0 || positionX>10);
        do {//validar cols
            printf("insert value of cols: ");
            fflush(stdin);
            scanf(" %c", &positionY);
        } while (positionY < 96 || positionY >106);
        if (table[positionX - 1][positionY - 97] == 1) {
            table2[positionX - 1][positionY - 97] = 1; //pass to select

            printf("blanco %d", table[positionX - 1][positionY - 97]);
        }
        else if (table2[positionX - 1][positionY - 97] = 2) {
            printf("\nfila:%d | columna:%c tablero[%d][%d]\n", positionX, positionY, positionX - 1, positionY - 97);// fail to select
        }
        getchar();
        getchar();
    }
}
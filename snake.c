#include <stdlib.h>
#include <stdio.h>


#define COLS 60
#define ROWS 30


int titleScreen(){

     
    printf("#");
    for(int i = 0; i < COLS; i++){

        printf("#");
        
    }

    printf("#\n");
    for(int j = 0; j < 3; j++){
        
        printf("#\t\t\t\t\t\t\t     #\n");
    
    }

    printf("#\t\t\t    WELCOME\t\t\t     #\n");
    printf("#\t\t\t\t\t\t\t     #\n");

    printf("#\t \t  \t      TO\t\t\t     #\n");
    
    printf("#\t\t\t\t\t\t\t     #\n");
    printf("#\t\t      Your Finance System    \t\t     #\n");

    printf("#\t\t\t\t\t\t\t     #\n");
    printf("#\t\t\t\t\t\t\t     #\n");


    for(int i = 0; i < 2; i++){
        
        printf("#\t\t\t\t\t\t\t     #\n");
    
    }
    printf("#\t\tPlease press Enter to continue... \t     #\n");

    for(int j = 0; j < 2; j++){
        
        printf("#\t\t\t\t\t\t\t     #\n");
    
    }

    printf("#");
    
    for(int i = 0; i < COLS; i++){

        printf("#");
        
    }
    printf("#\n");

    return 0;

}

int profile(){

    system("cls");
    printf("Select profile:");

    // i - це кількість профілів
    for(int i = 0; i < 3; i++){

        // j(s=%s) - це В ТЕОРІЇ назва профілю, на практиці ж я хз куди це припихнути) тому це знову ЗАТИЧКА
        //for(int j; j=0; j++){

            printf("%d - *profile name*\n", i);

        //}
    }
    
    printf("\nKoroche, nazmu '1' i zabei: ");

    return 0;
}


int mainMenu(){

    system("cls");

    printf("#\n");

   
    /*    for(int i = 0; i < COLS; i++){

            printf("#");
            
        }

    printf("\n");
    */

    // (%s) Підкачати назву профілю
    printf("#\t  Profile name: s\n");

    // (%d) Підкачати кількість грошей
    printf("#\t  Balance: d\n");

    // (%d) Підкачати всі мінуси* (витрати)
    printf("#\t  Expenses: -d\n");
    
    // (%d) Підкачати всі плюси* (добутки)
    printf("#\t  Product: +d\n");

    printf("#\n#\n#\n");

    printf("#\t1 - Add transaction \n#\t2 - Open general statistic \n#\t3 - Account statistics \n#\t4 - Expense statistics \n#\t5 - Product statistics\n");

   





    return 0;
}

/*int transactions(){

    printf("#\t 1 - Add to the balance \n#\t 2 - Subtract from the balance \n");

}*/

int main(){

    titleScreen();
    
    // Натискання Enter
    if (getchar() == '\n'){

        profile();
 
    }

    if (getchar() == '1') {
        while (getchar() != '\n');
    
        mainMenu();
        printf("Enter the number to choose: ");
        char choice = getchar();       
        while (getchar() != '\n'); //очищення буферу     
        
        while (getchar() != '\n') {
        if(getchar() == '1'){
        system("cls");
        // Вибір додавати чи віднімати з балансу
        printf("plus or minus");        

       }else if(choice == '2'){
        system("cls");
        // Підкачати статистику з файлу
        printf("your statistic");

       }else if(choice == '3'){
        system("cls");
        // Рахунки, їх баланс і/або кількість добутку/втрат
        printf("rahunki");

       }else if(getchar() == '4'){
        system("cls");
        //тут загальні витрати і на шо, всеодно треба буде вести список транзакцій
        printf("ACHTO TI ZABIL V MOEM HOLODILNIKE");

       }else if(getchar() == '5'){
        system("cls");
        //тут те саме що й в 4-му тільки навпаки, тобто список транзакцій з додатніми числами
        printf("AAAAVTOMOBILE");

    } 
    
  }        
    // printf("Cake is lie"); // PLACEHOLDER Тут має бути функція меню добутку/витрат

    // Після виконання очищується консоль та інтерфейс переносить на головне меню    
    

    return 0;
}

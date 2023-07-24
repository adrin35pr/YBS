#include <iostream>
#include <unistd.h>
#include <string>
#include <cstdlib>
using namespace std;


#define ROWS 30 
#define COLS 60


void TITLE_SCREEN(){

    
    printf("#");
    for (int i = 0; i < COLS; i++)
    {
        printf("#");
    }
    printf("#\n");

    for (int j = 0; j < 3; j++)
    {
        printf("#\t\t\t\t\t\t\t     #\n");
    }

    printf("#\t\t\t    WELCOME\t\t\t     #\n");
    printf("#\t\t\t\t\t\t\t     #\n");

    printf("#\t \t  \t      TO\t\t\t     #\n");

    printf("#\t\t\t\t\t\t\t     #\n");
    printf("#\t\t            LIBRARY         \t\t     #\n");

    printf("#\t\t\t\t\t\t\t     #\n");
    printf("#\t\t\t\t\t\t\t     #\n");

    for (int i = 0; i < 2; i++)
    {
        printf("#\t\t\t\t\t\t\t     #\n");
    }
    printf("#\t\tPlease press Enter to continue... \t     #\n");

    for (int j = 0; j < 2; j++)
    {
        printf("#\t\t\t\t\t\t\t     #\n");
    }

    printf("#");
    for (int i = 0; i < COLS; i++)
    {
        printf("#");
    }
    printf("#\n");

}

class Book{
    public:
        // Вся інформація про книгу
        string book_name;
        string book_author;
        int publication_year;
        bool library_status;
};

class Reader {
    private:
        string reader_name;
        //Взяті книги поки що будуть у вигляді кількості
        int taken_books {};

};

class Library{
    public:
    // 1 - це поки що затичка, треба буде подобавляти книжок і додати функцію "Пожертва", воно як раз і буде фігньою що додає книжки
        Book library_books[1] = { {"1984", "George Orwell", 1949, }, };

};

    int main(){
        
        TITLE_SCREEN();

        
        string enter_pusher;
        getline(cin, enter_pusher);

        if (enter_pusher == "\n"){

            system("cls");

        }

        
        cout << "1. Library;" << endl;
        cout << "2. Readers" << endl;
        
        cout << "Choose by using numbers: ";
        int choice_main_menu;
        cin >> choice_main_menu;

        if (choice_main_menu == 1){
            //тут треба прогрузити весь списко книг, тобто весь клас Library
            cout << "Choose a book using numbers: " << endl;
            int book_number;
            cin >> book_number;

            int i; i = book_number;
    
            Library library;
                cout << "Book: " << library.library_books[i-1].book_name << endl;
                cout << "Author: " << library.library_books[i-1].book_author << endl;
                cout << "Year: " << library.library_books[i-1].publication_year << endl;
                if (library.library_books[i-1].library_status == 0){
                    cout << "Status: Not enable" << endl;
                } else if (library.library_books[i-1].library_status == 1){
                    cout << "Status: Enable" << endl;
                }
          
            }


        
            if (choice_main_menu == 0){
            cout <<  "see you next time";
            sleep(1);
            return 0;
            }

        return 0;
    }
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
        Book library_books[5] = { 
            {"1984", "George Orwell", 1949, },
            {"Harry Potter and the Sorcerer's Stone", "J.K. Rowling", 1997, true},
            {"To Kill a Mockingbird", "Harper Lee", 1960, false},
            {"The Great Gatsby", "F. Scott Fitzgerald", 1925, true},
            {"Pride and Prejudice", "Jane Austen", 1813, false}
            };

};

    int main(){
        TITLE_SCREEN();

        string enter_pusher;
        getline(cin, enter_pusher);
        system("cls");

        Library library;
        
        while (1){
            
        cout << "1. Library;" << endl;
        cout << "2. Readers" << endl;
        cout << "0. Exit" << endl;
        
        cout << "Choose by using numbers: ";
        int choice_main_menu;
        cin >> choice_main_menu;
        
        if (choice_main_menu == 1){

            system("cls");
            for(int j = 0; j < 5; j++){
                cout << j+1 << " ";
                cout << library.library_books[j].book_name << ", " << library.library_books[j].book_author << endl;
            }

            cout << "Choose a book using numbers or push Esc to back to main menu: " << endl;
                
            int book_number;
            cin >> book_number;

            int i = book_number - 1; 

            cout << "Book: " << library.library_books[i].book_name << endl;
            cout << "Author: " << library.library_books[i].book_author << endl;
            cout << "Year: " << library.library_books[i].publication_year << endl;
            
            if (library.library_books[i].library_status == false) {
                cout << "Status: Not enable" << endl;
            }
            else if (library.library_books[i].library_status == true) {
                cout << "Status: Enable" << endl;
            }
                
                cout << "\n" << "Press Enter to continue..." << endl;

                cin.ignore();
                getline(cin, enter_pusher);
                
                if (enter_pusher == "\n") {
                    system("cls");
                    continue; 
                }
                
            }

            if (choice_main_menu == 2){

                

            }
        
            if (choice_main_menu == 0){
            cout <<  "see you next time";
            sleep(1);
            exit(0);
            break;
            }
        }
        return 0;
    }
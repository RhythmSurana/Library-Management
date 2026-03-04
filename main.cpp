#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>
#include <cstdio>

using namespace std;

// Admin & User Credentials
#define ADMINUSER "admin"
#define ADMINPASSWORD "1234"
#define USER "student"
#define USERPASSWORD "1234"

// Function Prototypes
int addBook();
int deleteBook();
int updateBook();
int listOfAllBooks();
int borrowBook();
int returnBook();

int main() {

    int outerChoice = 0;

    while (outerChoice != 9) {
        system("cls");
        cout << "\n Library Management System \n";
        cout << "\n1. Admin";
        cout << "\n2. User";
        cout << "\n9. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> outerChoice;

        if (outerChoice == 1) {

            char adminUser[20];
            char adminPassword[20];

            cout << "\nAdmin Login";
            cout << "\nUsername: ";
            cin >> adminUser;
            cout << "Password: ";
            cin >> adminPassword;

            if (strcmp(adminUser, ADMINUSER) == 0 &&
                strcmp(adminPassword, ADMINPASSWORD) == 0) {

                int innerChoice = 0;
                while (innerChoice != 9) {

                    system("cls");
                    cout << "\nAdmin Panel\n";
                    cout << "1. Add Book";
                    cout << "\n2. Update Book";
                    cout << "\n3. Delete Book";
                    cout << "\n4. List All Books";
                    cout << "\n9. Exit";
                    cout << "\nChoice: ";
                    cin >> innerChoice;

                    switch (innerChoice) {
                        case 1: addBook(); break;
                        case 2: updateBook(); break;
                        case 3: deleteBook(); break;
                        case 4: listOfAllBooks(); break;
                    }
                }
            }
            else {
                cout << "\nInvalid Credentials!";
                getchar(); getchar();
            }
        }

        else if (outerChoice == 2) {

            char user[20], pass[20];

            cout << "\nUser Login";
            cout << "\nUsername: ";
            cin >> user;
            cout << "Password: ";
            cin >> pass;

            if (strcmp(user, USER) == 0 &&
                strcmp(pass, USERPASSWORD) == 0) {

                int innerChoice = 0;
                while (innerChoice != 9) {

                    system("cls");
                    cout << "\nUser Panel\n";
                    cout << "1. Borrow Book";
                    cout << "\n2. Return Book";
                    cout << "\n3. List All Books";
                    cout << "\n9. Exit";
                    cout << "\nChoice: ";
                    cin >> innerChoice;

                    switch (innerChoice) {
                        case 1: borrowBook(); break;
                        case 2: returnBook(); break;
                        case 3: listOfAllBooks(); break;
                    }
                }
            }
            else {
                cout << "\nInvalid Credentials!";
                getchar(); getchar();
            }
        }
    }

    return 0;
}

int addBook() {

    int id;
    char name[50], author[50];

    cout << "\nEnter Book ID: ";
    cin >> id;

    cout << "Enter Book Name: ";
    cin >> name;

    cout << "Enter Author Name: ";
    cin >> author;

    char filename[30];
    sprintf(filename, "%d.dat", id);

    ofstream file(filename);

    file << name << endl;
    file << author << endl;
    file << "Available" << endl;

    file.close();

    cout << "\nBook Added Successfully!";
    getchar(); getchar();

    return 0;
}

int deleteBook() {

    int id;
    cout << "\nEnter Book ID to delete: ";
    cin >> id;

    char filename[30];
    sprintf(filename, "%d.dat", id);

    if (remove(filename) == 0)
        cout << "\nBook Deleted Successfully!";
    else
        cout << "\nBook Not Found!";

    getchar(); getchar();
    return 0;
}

int updateBook() {

    int id;
    cout << "\nEnter Book ID to update: ";
    cin >> id;

    char filename[30];
    sprintf(filename, "%d.dat", id);

    ifstream file(filename);

    if (!file) {
        cout << "\nBook Not Found!";
        getchar(); getchar();
        return 0;
    }

    file.close();

    char name[50], author[50];

    cout << "\nEnter New Book Name: ";
    cin >> name;
    cout << "Enter New Author Name: ";
    cin >> author;

    ofstream file2(filename);
    file2 << name << endl;
    file2 << author << endl;
    file2 << "Available" << endl;
    file2.close();

    cout << "\nBook Updated Successfully!";
    getchar(); getchar();

    return 0;
}

int listOfAllBooks() {

    system("dir *.dat");
    getchar(); getchar();
    return 0;
}

int borrowBook() {

    int id;
    cout << "\nEnter Book ID to borrow: ";
    cin >> id;

    char filename[30];
    sprintf(filename, "%d.dat", id);

    ifstream file(filename);
    if (!file) {
        cout << "\nBook Not Found!";
        getchar(); getchar();
        return 0;
    }

    string name, author, status;
    getline(file, name);
    getline(file, author);
    getline(file, status);
    file.close();

    if (status == "Borrowed") {
        cout << "\nBook Already Borrowed!";
    } else {
        ofstream file2(filename);
        file2 << name << endl;
        file2 << author << endl;
        file2 << "Borrowed" << endl;
        file2.close();
        cout << "\nBook Borrowed Successfully!";
    }

    getchar(); getchar();
    return 0;
}

int returnBook() {

    int id;
    cout << "\nEnter Book ID to return: ";
    cin >> id;

    char filename[30];
    sprintf(filename, "%d.dat", id);

    ifstream file(filename);
    if (!file) {
        cout << "\nBook Not Found!";
        getchar(); getchar();
        return 0;
    }

    string name, author, status;
    getline(file, name);
    getline(file, author);
    getline(file, status);
    file.close();

    ofstream file2(filename);
    file2 << name << endl;
    file2 << author << endl;
    file2 << "Available" << endl;
    file2.close();

    cout << "\nBook Returned Successfully!";
    getchar(); getchar();

    return 0;
}

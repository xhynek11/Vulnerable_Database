#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions.h"
using namespace std;

void readFile(int isVisible) {
    std::string line;
    //Pøeète  celı obsah texáku a nahraje do promìné typu ifstream "MyReadFile"
    ifstream MyReadFile("Database.txt");

    //Cyklus while kterı po øádcích ète "MyReadFile" a obah øádku nahrává do promìné "line"
    while (getline(MyReadFile, line)) {
        //pomocí "delimeter" se øádek po jednotlivıch poloách vypíše øádek
        std::string delimiter = ";";
        int count = 0;
        size_t pos = 0; //prc
        std::string token;
        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos); //more prc
            if (count == 1 && isVisible == 0) {
                std::cout << "***** ";
            }
            else {
                std::cout << token + " ";
            }
            line.erase(0, pos + delimiter.length());
            count++;
        }
        std::cout << line << std::endl;
    }

    // Close the file
    MyReadFile.close();
}

void changeFile(int authotized) {
    if (authotized == 0) {
        cout << "Only Admin can edit database!";
        return;
    }
    else if (authotized == 1) {
    }

    std::string out;
    std::string change;
    int index = 0;
    printf("Jaky zaznam chcete upravit");
    scanf("%d", &index);
    std::string delimiter = "[" + std::to_string(index) + "]";

    // Read from the text file
    ifstream MyReadFile("Database.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, change)) {
        // Output the text from the file
        if (change.find(delimiter)) {
            out += change + "\n";
        }
        else {
            cout << change.find(delimiter);
            std::cout << "Rozhodli jste se upravit:";
            printLine(change);

            string str_search = "";
            printf("Zadejte co chcete upravit: ");
            cin >> str_search;
            string str_replace = "";
            printf("Zadejte na co to chcete zmenit: ");
            cin >> str_replace;

            size_t pos = change.find(str_search);
            change.replace(pos, string(str_search).length(), str_replace);
            out += change + "\n";
        }

    }
    MyReadFile.close();
    ofstream out_file("Database.txt");
    out_file << out;
    out_file.close();
}

void printLine(std::string s) {
    std::string delimiter = ";";

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        std::cout << token + " ";
        s.erase(0, pos + delimiter.length());
    }
    std::cout << s << std::endl;
}

int findByClass(char bC[8], int visibility) {
    std::string byClass = bC;

    if (byClass == "IBEP" || byClass == "UFYZ" || byClass == "PFMAN") {
    }
    else {
        byClass = "ALL";
    }
    std::string s;
    std::string sCopy;
    bool skip = true;
    // Read from the text file
    ifstream MyReadFile("Database.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, s)) {
        if (byClass != "ALL") {
            skip = true;
            sCopy = s;
            std::string delimiter = ";";
            int count = 0;
            size_t pos = 0;
            //Projde novı øádek a rozhodne podle skupiny zda se má øádek vypsat èi ne
            std::string token;
            while ((pos = sCopy.find(delimiter)) != std::string::npos) {
                token = sCopy.substr(0, pos);
                if (count == 4) {
                    if (token == bC) {
                        skip = false;
                    }
                }
                sCopy.erase(0, pos + delimiter.length());
                count++;
            }
        }
        else {
            skip = false;
        }

        // Output the text from the file
        if (skip == false) {
            std::string delimiter = ";";
            int count = 0;
            size_t pos = 0;
            std::string token;
            while ((pos = s.find(delimiter)) != std::string::npos) {
                token = s.substr(0, pos);
                if (count == 1 && visibility == 0) {
                    std::cout << "***** ";
                }
                else {
                    std::cout << token + " ";
                }
                s.erase(0, pos + delimiter.length());
                count++;
            }
            std::cout << s << std::endl;
        }
    }

    // Close the file
    MyReadFile.close();
    return 1;
}

void addUser() {
    std::string login;
    std::string psswd;
    std::string name;
    std::string surname;
    std::string userClass;
    std::string birthDate;

    std::cout << "\nEnter User´s login: ";
    cin >> login;
    std::cout << "\nEnter User´s password: ";
    cin >> psswd;
    std::cout << "\nEnter User´s name: ";
    cin >> name;
    std::cout << "\nEnter User´s surname: ";
    cin >> surname;
    std::cout << "\nEnter User´s class: ";
    cin >> userClass;
    std::cout << "\nEnter User´s year of birth: ";
    cin >> birthDate;

    std::string out;
    std::string s;
    int index = 1;

    // Read from the text file
    ifstream MyReadFile("Database.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, s)) {
        // Output the text from the file
        out += s + "\n";
        index++;
    }
    out += "[" + to_string(index) + "]" + login + ";" + psswd + ";" + name + ";" + surname + ";" + userClass + ";" + birthDate;

    MyReadFile.close();
    ofstream out_file("Database.txt");
    out_file << out;
    out_file.close();
}
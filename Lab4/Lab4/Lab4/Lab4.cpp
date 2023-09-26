#include <iostream>
#include<vector>
#include"Show.h"
#include "TV.h"
#include "Movie.h"

int main()
{
    while (true) {
        int sel;
        std::cout << "Press 1 for instance of show \nPress 2 for instance of TV Show \nPress 3 for instance of Movie \nPress 4 for instance of TV Show declared as Show \nPress 5 for instance of Movie declared as Show \nPress 6 to exit" << std::endl;
        std::cin >> sel;
        system("CLS");
        if (sel == 1) {
            Show* instance = new Show();
            std::cout << std::endl;
            instance->play_();
        }
        else if (sel == 2) {
            TV* instance = new TV();
            std::cout << std::endl;
            instance->play_();
        }
        else if (sel == 3) {
            Movie* instance = new Movie();
            std::cout << std::endl;
            instance->play_();
        }
        else if (sel == 4) {
            Show* instance = new TV();
            std::cout << std::endl;
            instance->play_();
        }
        else if (sel == 5) {
            Show* instance = new Movie();
            std::cout << std::endl;
            instance->play_();
        }
        else { return 0; }
        continue;
    }
    return 0;
}

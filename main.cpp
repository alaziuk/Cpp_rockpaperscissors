#include <iostream>
#include <stdlib.h>
#include <time.h> 

enum choice {Rock, Paper, Scissors};

class Game {
    public:
        Game() {}

        void play() {
            playerMove();
            botMove();
            conclude();
        }
    
    private:
        choice choicePlayer_;
        choice choiceBot_;

        void botMove() {
            srand (time(NULL));
            choiceBot_ = (choice)(rand() % 3);
        }

        void playerMove(){
            int ichoice;
            while (true) {   
                std::cout << "***********************************************\n";
                std::cout << "Choices:\n";
                std::cout << "1 - Rock\n";
                std::cout << "2 - Paper\n";
                std::cout << "3 - Scissors\n";
                std::cout << "***********************************************\n";
                std::cout << "Your choice (1-3): ";
                std::cin >> ichoice;

                if(ichoice == 1 || ichoice == 2 || ichoice == 3){
                    choicePlayer_ = (choice)(ichoice-1);
                    break;
                } else {
                    std::cout << "WRONG INPUT!!!!\n";
                }
            }
        }

        std::string enumString (choice input) {
            switch (input) {
                case Rock:
                    return "Rock";
                case Paper:
                    return "Paper";
                case Scissors:
                    return "Scissors";
                default:
                    return "";
            }
        }

        void announce(std::string string, int conclusion) {
            std::cout << string << '\n';
            if (conclusion == 0) {
                std::cout << "You lose!\n";
            } else if (conclusion == 1) {
                std::cout << "You win!\n";
            } else {
                std::cout << "Draw!\n";
            }
            std::cout << "***********************************************\n";
        }

        void conclude() {
            std::cout << "***********************************************\n";
            std::cout << "Your choice: " << enumString(choicePlayer_) << '\n';
            std::cout << "Bot's choice: " << enumString(choiceBot_) << '\n';

            if ((int)choicePlayer_ == 0 && (int)choiceBot_ == 0) {
                announce("Two stones created a spark! Is it the first step to your love story?", -1);
            } 
            if ((int)choicePlayer_ == 0 && (int)choiceBot_ == 1) {
                announce("Paper beats rock!", 0);
            } 
            if ((int)choicePlayer_ == 0 && (int)choiceBot_ == 2) {
                announce("Rock beats scissors!", 1);
            }
            if ((int)choicePlayer_ == 1 && (int)choiceBot_ == 0) {
                announce("Paper beats rock!", 1);
            }
            if ((int)choicePlayer_ == 1 && (int)choiceBot_ == 1) {
                announce("You have taken first step to create a book!", -1);
            }
            if ((int)choicePlayer_ == 1 && (int)choiceBot_ == 2) {
                announce("Scissors beat paper!", 0);
            }
            if ((int)choicePlayer_ == 2 && (int)choiceBot_ == 0) {
                announce("Rock beats scissors!", 0);
            }
            if ((int)choicePlayer_ == 2 && (int)choiceBot_ == 1) {
                announce("Scissors beat paper!", 1);
            }
            if ((int)choicePlayer_ == 2 && (int)choiceBot_ == 2) {
                announce("Oh my, two scissors!", -1);
            }
        }
};


int main() {
    Game Game;
    Game.play();
    return 0;
}
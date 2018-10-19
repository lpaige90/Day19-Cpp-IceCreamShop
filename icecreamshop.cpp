#include "icecream.h"
#include <iostream>
#include <memory>

int main(void) {
    int numScoops;
    
    std::cout << "Welcome to the Ice Cream Shop! How many scoops would you like? (1, 2, or 3) " << std::endl;

    std::cin >> numScoops;

    std::cout << "\nAlright, " << numScoops << " scoops it is!" << std::endl;
    std::cout << "Here's a list of our current flavors:\n1 - Vanilla\n2 - Chocolate\n3 - Birthday Cake\n4 - Cookie Dough\n5 - Pumpkin\n6 - Cherry" << std::endl;

    if (numScoops == 1) {
        int flavor1;

        std::cout << "What flavor would you like? (Enter a number from 1-6) ";
        std::cin >> flavor1;

        if ( !(1 <= flavor1 <= 6)) {
            std::cout << "We don't have that flavor here. Sorry!";
            exit(EXIT_FAILURE);
        }

        std::cout << "\nGood choice. Here you go!";
        std::unique_ptr<OneScoop> iceCream(new OneScoop(flavor1));
        iceCream->order();
    } else if (numScoops == 2) {
        int flavor1;
        int flavor2;

        std::cout << "What flavor would you like for the first scoop? (Enter a number from 1-6) ";
        std::cin >> flavor1;

        if ( !(1 <= flavor1 <= 6)) {
            std::cout << "We don't have that flavor here. Sorry!";
            exit(EXIT_FAILURE);
        }

        std::cout << "What about for the second scoop? (Enter a number from 1-6) ";
        std::cin >> flavor2;

        if ( !(1 <= flavor2 <= 6)) {
            std::cout << "We don't have that flavor here. Sorry!";
            exit(EXIT_FAILURE);
        }

        std::cout << "\nGreat choices. Here you go!";
        std::unique_ptr<TwoScoops> iceCream(new TwoScoops(flavor1, flavor2));
        iceCream->order();
    } else if (numScoops == 3) {
        int flavor1;
        int flavor2;
        int flavor3;

        std::cout << "What flavor would you like for the first scoop? (Enter a number from 1-6) ";
        std::cin >> flavor1;

        if ( !(1 <= flavor1 <= 6)) {
            std::cout << "We don't have that flavor here. Sorry!";
            exit(EXIT_FAILURE);
        }

        std::cout << "What about for the second scoop? (Enter a number from 1-6) ";
        std::cin >> flavor2;

        if ( !(1 <= flavor2 <= 6)) {
            std::cout << "We don't have that flavor here. Sorry!";
            exit(EXIT_FAILURE);
        }

        std::cout << "And the third? (Enter a number from 1-6) ";
        std::cin >> flavor3;

        if ( !(1 <= flavor3 <= 6)) {
            std::cout << "We don't have that flavor here. Sorry!";
            exit(EXIT_FAILURE);
        }

        std::cout << "\nThose are all great choices. Here you go!";
        std::unique_ptr<ThreeScoops> iceCream(new ThreeScoops(flavor1, flavor2, flavor3));
        iceCream->order();
    } else {
        std::cout << "I'm afraid that's not an option and you're going to have to leave.";
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}

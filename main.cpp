#include <iostream>
#include "gradebook.h"

int main() {
    // Have different options that the user can enter
    std::string file_name = "Brandt_grades.txt";
    Gradebook brandt_gradebook(file_name);

    // Prints the contents of the gradebook for testing purposes
    for (int i = 0; i < 3; i++) {
        std::cout << brandt_gradebook.get_category()[i] << " ";
        std::cout << brandt_gradebook.get_title_assignment()[i] << " ";
        std::cout << brandt_gradebook.get_earned_points()[i] << " ";
        std::cout << brandt_gradebook.get_completed()[i] << std::endl;

    }

}

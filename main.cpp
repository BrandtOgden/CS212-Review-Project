#include <iostream>
#include "gradebook.h"

int main() {
    // Have different options that the user can enter
    std::string file_name = "Brandt_grades.txt";
    Gradebook brandt_gradebook(file_name);

    //brandt_gradebook.list_assignments();
    std::string letter_grade = Gradebook::get_letter_grade(5, 10);
    std::cout << letter_grade;


}

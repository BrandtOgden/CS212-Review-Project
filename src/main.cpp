#include <iostream>
#include <fstream>
#include <limits>
#include "gradebook.h"

// INITIAL OUTLINE FOR MAIN
/* There will be a menu that will be displayed so the user can choose a number. For certain options, a sub-menu will open
1- Get Grade
 1a- for getting the current course grade
 1b- for getting the course grade and total grade for each category
 1c- for getting the course grade and all grades on assignments for each category
 1d- for getting the grade of an individual category
 1e- for getting the grade of an individual assignment
2- List assignments
 2a- for listing all assignments in the gradebook
 2b- listing all assignments in a specific category
3- add a new assignment
4- edit an assignment
 4a- edit assignment name
 4b- edit category name
 4c- edit points earned
 4d- mark assignment as complete
5- remove an assignment from the gradebook
*/

// We'll get the user's choice and check to make sure it's valid

/* Perform functions on the gradebook
1a- will print get_total_grade to get the overall course grade
1b- will print get_total_grade just like option 1, and it will print get_category_total on each category to get that category's grade
1c- will print get_total_grade just, like the first two options. For each category it will print that category's
    grade and then iterate through all the assignments in that category and print those grades with get_grade_individual
2a- will run list_assignments to list all the assignments in the gradebook
2b- will run iterate through the assignments vector and print out assignments if it matches the entered category
3- will ask the user to enter all the information to write to the text file with new line in the Category Title EarnedPoints IsCompleted format
4a-d will ask the user for the new assignment name, category name, points earned, or completion and set that assignments value's accordingly
5- will remove that line from the file and the vectors storing the assignment's info
 */

// after the user enters a choice it will run the function and ask the user to enter another input. They can enter 'quit' to stop


int main() {
    /* Have different options for what the user can do and then show the options menu to do different things with it
    1- Ryan Brooks
    2- Ryan Shilling
    3- Jake Dansereau
    4- Brandt Ogden
     */

    std::string choice;

    // repeat until the user enters 2 to quit
    while (choice != "2") {
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "Type 1 - Open the gradebook of one us" << std::endl;
        std::cout << "     2 - Quit" << std::endl;
        std::cin >> choice;
        while (choice != "1" && choice != "2") {
            std::cout << "Invalid option, try again!" << std::endl;
            std::cin >> choice;
        }

        // Variable to store the gradebook
        Gradebook *gradebook;

        // Handles the different choices that the user has
        if (choice == "1") {
            std::cout << "Which person's gradebook would you like to open?" << std::endl;
            std::cout << "    1 - Ryan Brooks" << std::endl;
            std::cout << "    2 - Ryan Shilling" << std::endl;
            std::cout << "    3 - Jake Dansereau" << std::endl;
            std::cout << "    4 - Brandt Ogden" << std::endl;
            std::string person_choice;
            std::cin >> person_choice;

            // Check for valid input
            while (person_choice != "1" && person_choice != "2" && person_choice != "3" && person_choice != "4") {
                std::cout << "Invalid option, try again!" << std::endl;
                std::cin >> person_choice;
            }

            // Does things based on the person_choice
            if (person_choice == "1") {
                gradebook = new Gradebook("RyanB_grades.txt");
            } else if (person_choice == "2") {
                gradebook = new Gradebook("RyanS_grades.txt");
            } else if (person_choice == "3") {
                gradebook = new Gradebook("Jake_grades.txt");
            } else {
                // Choice d
                gradebook = new Gradebook("Brandt_grades.txt");
            }
        } else {
            exit(0);
        }


        // Start of the main loop that will do different things to do the gradebook
        std::cout << "What would you like to do with the gradebook?" << std::endl;
        std::cout << "    1 - Get your grade" << std::endl;
        std::cout << "    2 - List the current deliverables" << std::endl;
        std::cout << "    3 - Create a new assignment" << std::endl;
        std::cout << "    4 - Edit an existing assignment" << std::endl;
        std::cout << "    5 - Remove an assignment" << std::endl;

        // Get input from user and check for valid form
        std::string gradebook_choice;
        std::cin >> gradebook_choice;
        while (gradebook_choice != "1" && gradebook_choice != "2" && gradebook_choice != "3" &&
               gradebook_choice != "4" && gradebook_choice != "5") {
            std::cout << "Invalid option, try again!" << std::endl;
            std::cin >> gradebook_choice;
        }


        // Do things with that choice
        if (gradebook_choice == "1") {
            // Give the user the choice for different options to do
            std::cout << "What grade would you like?" << std::endl;
            std::cout << "    a - Your overall course grade" << std::endl;
            std::cout << "    b - Your overall course grade and the grade of each category" << std::endl;
            std::cout
                    << "    c - Your overall course grade, grade of each category, and all the grades of the different deliverables"
                    << std::endl;
            std::cout << "    d - Your grade for one specific category" << std::endl;
            std::cout << "    e - Your grade for a specific deliverable" << std::endl;

            // Checks for a valid option
            std::string grade_choice;
            std::cin >> grade_choice;
            while (grade_choice != "a" && grade_choice != "b" && grade_choice != "c" && grade_choice != "d" &&
                   grade_choice != "e") {
                std::cout << "Invalid option, try again!" << std::endl;
                std::cin >> grade_choice;
            }

            //based on letter entered, do different option(s)
            if (grade_choice == "a") {
                //initializes a grade_return variable and sets it to function call
                float grade_return = gradebook->get_total_grade();
                //passing grade_return into helper function to get letter grade
                std::string letter_grade = HelperFunctions::get_letter_grade(grade_return);

                //outputting results
                std::cout << "Your total grade for the course is: " << grade_return << "%" << std::endl;
                std::cout << "Your letter grade is: " << letter_grade << std::endl;

            } else if (grade_choice == "b") {
                //initializes a grade_return variable and sets it to function call
                float grade_return = gradebook->get_total_grade();
                //passing grade_return into helper function to get letter grade
                std::string letter_grade = HelperFunctions::get_letter_grade(grade_return);

                //outputting overall course grade and grade for each category
                std::cout << "Your total grade for the course is: " << grade_return << "%" << std::endl;
                std::cout << "Your letter grade is: " << letter_grade << std::endl;
                //getting each specific category grade for options b and c
                gradebook->get_category_total("Lab");
                gradebook->get_category_total("Assignment");
                gradebook->get_category_total("Project1");
                gradebook->get_category_total("Project2");
                gradebook->get_category_total("Exam");


            } else if (grade_choice == "c") {
                //initializes a grade_return variable and sets it to function call
                float grade_return = gradebook->get_total_grade();
                //passing grade_return into helper function to get letter grade
                std::string letter_grade = HelperFunctions::get_letter_grade(grade_return);


                //outputting overall course grade and grade for each category
                std::cout << "Your total grade for the course is: " << grade_return << "%" << std::endl;
                std::cout << "Your letter grade is: " << letter_grade << std::endl << std::endl;
                //getting each specific category grade for options b and c
                gradebook->get_category_total("Lab");
                gradebook->get_category_total("Assignment");
                gradebook->get_category_total("Project1");
                gradebook->get_category_total("Project2");
                gradebook->get_category_total("Exam");


                std::cout << std::endl;
                //getting each specific assignment grade
                for (int i = 0; i < gradebook->get_title_assignment().size(); i++) {
                    int individual = gradebook->get_grade_individual(gradebook->get_title_assignment()[i]);
                    if (individual == -1) {
                        std::cout << "There is not an assignment called " << gradebook->get_title_assignment()[i]
                                  << std::endl;
                    } else if (individual == -2) {
                        std::cout << gradebook->get_title_assignment()[i] << " has not been completed yet."
                                  << std::endl;
                    } else {
                        std::cout << "Your grade for " << gradebook->get_title_assignment()[i] << " is: "
                                  << individual << "%" << std::endl;
                    }
                }
            } else if (grade_choice == "d") {
                float grade_return;
                //setting single_category to temporary value
                std::string single_category = "temp";
                std::cout << "Enter a category you want to see the grade for: " << std::endl
                          << "(enter 'Lab', 'Assignment', 'Project 1', Project 2', or 'Exam')" << std::endl;
                std::cin >> single_category;
                //while the category input does not equal one of the correct category options, it continues to ask for input
                while (single_category != "Lab" and single_category != "Assignment" and
                       single_category != "Project 1" and single_category != "Project 2" and
                       single_category != "Exam") {
                    std::cout << "Invalid category, please try again:" << std::endl;
                    std::cin >> single_category;
                }
                //getting the grade_return from the get_category_total function for specific category
                grade_return = gradebook->get_category_total(single_category);

                //error checking to make sure there is a grade for that specific category
                if (grade_return != 0) {
                    std::cout << "Your grade for " << single_category << " is " << grade_return << "%\n";
                }

            } else if (grade_choice == "e") {
                // Prompts the user to enter an assignment
                std::string name_deliverable;
                std::cout << "Enter the name of an assignment:" << std::endl;
                std::cin >> name_deliverable;
                while (gradebook->get_grade_individual(name_deliverable) == -1) {
                    std::cout << "There is not an assignment called " << name_deliverable << " try again!"
                              << std::endl;
                    std::cin >> name_deliverable;
                }

                // Checks if the assignment has not been completed
                if (gradebook->get_grade_individual(name_deliverable) == -2) {
                    std::cout << "This assignment has not been completed" << std::endl;
                } else {
                    // Calculates and outputs the grade
                    int pct = gradebook->get_grade_individual(name_deliverable);
                    std::string letter_grade = HelperFunctions::get_letter_grade(pct);
                    std::cout << "Your grade for " << name_deliverable << " is a " << pct << "%" << std::endl;
                    std::cout << "Your letter grade for " << name_deliverable << " is a " << letter_grade << std::endl;
                }
            }
        } else if (gradebook_choice == "2") {
            // Outputs all the different deliverables in the text file
            std::cout << "Your current deliverables are: " << std::endl;
            gradebook->list_assignments();

        } else if (gradebook_choice == "3") {
            // Makes a new assignment by writing to the gradebook file with certain criteria from the user
            std::string category;
            std::string name;
            int points_earned = -1;
            std::string is_completed;

            // User will enter a category from the given options
            // checks whether the category is one of the valid options
            std::cout << "Enter the category of the assignment:" << std::endl;
            std::cout << "Categories:\n    Assignment\n    Lab\n    Project1\n    Project2" << std::endl;
            std::cin >> category;
            // if it's one of the categories, it's a good input
            // loop until the input is good by asking the user to enter the category again
            bool good_input = false;
            if (category == "Assignment" or category == "Lab" or category == "Project1" or category == "Project2" or
                category == "Exam")
                good_input = true;
            while (!good_input) {
                std::cout << "Invalid input, try again.\n";
                std::cin >> category;
                if (category == "Assignment" or category == "Lab" or category == "Project1" or
                    category == "Project2" or category == "Exam")
                    good_input = true;
            }

            // Then asks user to enter the name of the assignment
            // As long as an assignment with the name does not already exist, the name is accepted
            std::cout << "Enter the name of the assignment:" << std::endl;
            std::cin >> name;
            bool good_name = true;
            for (int i = 0; i < gradebook->get_title_assignment().size(); i++) {
                if (name == gradebook->get_title_assignment()[i]) {
                    std::cout << "There is already a deliverable with the title " << name << ". Try again.\n";
                    good_name = false;
                }
            }
            // loop until a good name is entered
            while (!good_name) {
                std::cin >> name;
                good_name = true;
                for (int i = 0; i < gradebook->get_title_assignment().size(); i++) {
                    if (name == gradebook->get_title_assignment()[i]) {
                        std::cout << "There is already a deliverable with the title " << name << ". Try Again.\n";
                        good_name = false;
                    }
                }
            }

            // the assignment's total points based on its category
            int total_points;
            if (category == "Assignment") total_points = 50;
            if (category == "Lab") total_points = 20;
            if (category == "Project1") total_points = 150;
            if (category == "Project2") total_points = 350;
            if (category == "Exam") total_points = 100;

            // enter a number of points earned
            // to be good input, the points must be a number, non-negative, and less than or equal to the max number of points
            std::cout << "Enter the number of points earned for the assignment:" << std::endl;
            std::cin >> points_earned;
            while (true) {
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input, try again.\n";
                    std::cin >> points_earned;
                }
                if (!std::cin.fail()) break;
            }
            // loop until good input conditions are met
            while (points_earned <= 0 || points_earned > total_points) {
                std::cout << "Invalid input, try again.\n";
                std::cin >> points_earned;
                while (true) {
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input, try again.\n";
                        std::cin >> points_earned;
                    }
                    if (!std::cin.fail()) break;
                }
            }

            // asks whther the assingment has been completed for not
            // the input is y/n and then is used to write completed or not-completed as a string when creating the new assignment
            std::cout << "Has the assignment been completed or not? Enter y/n:" << std::endl;
            std::cin >> is_completed;
            while (is_completed != "y" && is_completed != "n") {
                std::cout << "Invalid input, try again.\n";
                std::cin >> points_earned;
            }
            if (is_completed == "y") is_completed = "completed";
            else is_completed = "not-completed";

            // make the new assignment with the info
            std::cout << gradebook->new_assignment(category, name, points_earned, is_completed) << std::endl;

        } else if (gradebook_choice == "4") {
            //choice 4 allows editing the grade of a single assignment and completion status of an assignment
            std::string name_deliverable;
            std::cout << "Enter the name of an assignment:" << std::endl;
            std::cin >> name_deliverable;

            //Checking existence of deliverable by name
            while (gradebook->get_grade_individual(name_deliverable) == -1) {
                std::cout << "There is not an assignment called " << name_deliverable << " try again!" << std::endl;
                std::cin >> name_deliverable;
            }

            //Menu allows choice between editing modes
            std::cout << "What would you like to edit about this deliverable?" << "\n";
            std::cout << "    a - Edit the Grade" << "\n";
            std::cout << "    b - Edit the completion status" << "\n";
            std::string choice;
            std::cin >> choice;

            //Checking user inputted either a or b
            bool good_input = false;
            if (choice == "a" or choice == "b") good_input = true;
            while (!good_input) {
                std::cout << "Invalid input, try again.\n";
                std::cin >> choice;
                if (choice == "a" or choice == "b") good_input = true;
            }

            if (choice == "a") {
                //Searches for the index of the deliverable
                int index = -1;
                std::vector<std::string> categoryList = gradebook->get_category();
                std::vector<std::string> assignmentList = gradebook->get_title_assignment();
                for (int i = 0; i < categoryList.size(); i++) {
                    if (assignmentList[i] == name_deliverable) {
                        index = i;
                        break;
                    }
                }

                //Uses index just searched for to find the max points allowed for the deliverable.
                int total_points;
                if (categoryList[index] == "Assignment") total_points = 50;
                if (categoryList[index] == "Lab") total_points = 20;
                if (categoryList[index] == "Project1") total_points = 150;
                if (categoryList[index] == "Project2") total_points = 350;
                if (categoryList[index] == "Exam") total_points = 100;

                //Input for new points earned
                int new_grade;
                std::cout << "Enter the new grade for " << name_deliverable
                          << "\nMaximum points on this deliverable is " << total_points << ".\n";
                std::cin >> new_grade;

                //Makes sure entered value is an integer
                while (true) {
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input, try again.\n";
                        std::cin >> new_grade;
                    }
                    if (!std::cin.fail()) break;
                }

                //Assures valid input
                while (new_grade < 0 or new_grade > total_points) {
                    std::cout << "Invalid input, try again.\n";
                    std::cin >> new_grade;
                    while (true) {
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Invalid input, try again.\n";
                            std::cin >> new_grade;
                        }
                        if (!std::cin.fail()) break;
                    }
                }

                //Calls edit_grade function which edits the vectors all information is stored in
                gradebook->edit_grade(name_deliverable, new_grade);
                std::cout << "Successfully updated grade.\n";

            } else if (choice == "b") {
                //Prompts user for completion status of previously selected deliverable
                std::string completion_str;
                std::cout << "Should this deliverable be completed or not-completed?\nEnter 'completed' or 'not-completed'.\n";
                std::cin >> completion_str;
                bool good_input = false;

                //Idiot proofing input for completion status
                if (completion_str == "completed" or completion_str == "not-completed") good_input = true;
                while (!good_input) {
                    std::cout << "Invalid input, try again.\n";
                    std::cin >> completion_str;
                    if (completion_str == "completed" or completion_str == "not-completed") good_input = true;
                }

                //assigning a boolean value to correspond with completion input
                bool completion;
                if (completion_str == "completed") completion = true;
                else completion = false;

                //Calls edit_completion function to change the completion status in the vectors
                gradebook->edit_completion(name_deliverable, completion);
                std::cout << "Successfully updated completion.\n";
            }
        } else {
            //This option allows the user to remove an assignment from the txt

            //Prompts user for input of a deliverable name
            std::string name_deliverable;
            std::cout << "What deliverable would you like to remove?" << std::endl;
            std::cin >> name_deliverable;

            //Idiot proofing the input for assignment name
            while (gradebook->get_grade_individual(name_deliverable) == -1) {
                std::cout << "There is not a deliverable called " << name_deliverable << " try again!" << std::endl;
                std::cin >> name_deliverable;
            }

            //calls remove_assignment function to edit the vectors.
            std::cout << gradebook->remove_assignment(name_deliverable);
        }
    }
}

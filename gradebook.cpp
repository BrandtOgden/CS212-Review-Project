#include "gradebook.h"

// Implement functions as defined in gradebook.h
Gradebook::Gradebook(std::string file_name) {
    // ALL FILES WE WANT TO USE HAVE TO BE IN THE GRADES FOLDER
    // WILL WANT TO MENTION THIS IS THE VIDEO
    // First line should be the name whose grades are in the file
    // The next lines should be in the format,
    // Category Title EarnedPoints IsCompleted

    // Opens the file
    std::ifstream infile("Grades/" + file_name);

    // Gets the name from the first line and store it in the private variable name
    std::getline(infile, this->name);

    // Gets all the assignments from the rest of the text file
    std::string line;
    // Loop until end of file
    while (std::getline(infile, line)) {
        // Tokenize each line to get category title etc...
        std::stringstream line_stream(line);
        // Variables to temporarily hold the tokens
        std::string category, title_assignment;
        int earned_points;
        bool completed;
        // Loop until there are no more tokens in line_stream
        while (line_stream.good()) {
            line_stream >> category;
            line_stream >> title_assignment;
            line_stream >> earned_points;
            line_stream >> completed;

            // Add them to their respective class variables
            this->category.push_back(category);
            this->title_assignment.push_back(title_assignment);
            this->earned_points.push_back(earned_points);
            this->completed.push_back(completed);
        }
    }
}


void Gradebook::list_assignments() {
    // Loop through title_assignment and output all the names so the user knows what
    // assignments there are
    for (int i = 0; i < this->title_assignment.size(); i++) {
        std::cout << i << ": " << this->title_assignment[i] << std::endl;
    }
}


float Gradebook::get_grade_individual(std::string name_assignment) {
    // output the grade of name_assignment
    // outputs earned points and total points along with the percentage and letter grade
    // variable to hold the value of total points
    int total_points;
    for (int i = 0; i < this->title_assignment.size(); i++) {
        if (this->title_assignment[i] == name_assignment) {
            // Check for what the category is because that will change the total points
            if (this->category[i] == "Lab") {
                total_points = 20;
            } else if (this->category[i] == "Assignment") {
                total_points = 50;
            } else if (this->category[i] == "Project 1") {
                total_points = 150;
            } else if (this->category[i] == "Project 2") {
                total_points = 350;
            } else if (this->category[i] == "Exam") {
                total_points = 100;
            }
        }
    }
    return 0;

}


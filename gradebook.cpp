#include "gradebook.h"
#include <vector> 
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
        std::cout << this->title_assignment[i] << std::endl;
    }
}

// output the grade of name_assignment
// outputs earned points and total points along with the percentage and letter grade
bool Gradebook::get_grade_individual(std::string name_assignment) {
    // variable to hold the value of total points
    int total_points;
    // Variable to hold the index of the assignment we are dealing with
    int index = -1;
    for (int i = 0; i < this->title_assignment.size(); i++) {
        if (this->title_assignment[i] == name_assignment) {
            index = i;
            break;
        }
    }

    // Checks whether the name of assignment has been found
    if (index == -1) {
        std::cout << "There is not an assignment called " << name_assignment <<  " try again!" << std::endl;
        return false;
    } else {
        // Check for what the category is because that will change the total points
        if (this->category[index] == "Lab") {
            total_points = 20;
        } else if (this->category[index] == "Assignment") {
            total_points = 50;
        } else if (this->category[index] == "Project 1") {
            total_points = 150;
        } else if (this->category[index] == "Project 2") {
            total_points = 350;
        } else if (this->category[index] == "Exam") {
            total_points = 100;
        }

        // Calculates the percentage
        int pct = std::round((float(this->earned_points[index]) / float(total_points)) * 100);
        // Calculates letter grade
        std::string letter_grade = HelperFunctions::get_letter_grade(pct);

        // Outputs the grade
        std::cout << "Your grade for " << this->title_assignment[index] << " is a " << letter_grade << " or "
                  << std::to_string(pct) << "%" << std::endl;
        return true;
    }

}
//gets all grades from specific category selected by user and returns the overall
//point sum for that category  
float get_category_total(std::string category){
    std::vector<int>labGrades;
    float sumPoints; 
    if(this->category = "Lab"){
        //going through category list and storing indices that match the category entered
        //if category matches the user input, it adds the points at current index to
        //the labGrades vector
        for(int i = 0; i < categoryList.size(); i++){
            if(categoryList[i] == category){
                labGrades.push_back(earned_points[i]);
            }
        }
        //going through labGrades vector and summing values for particular category
        for(int j = 0; j < labGrades.size(); j++){
            sumPoints += labGrades[j]; 
        }
        //clearing the labGrades vector for next category input use
        labGrades.clear();

        //returning the total points earned for the category
        return sumPoints; 
    }
    else if(this->category = "Assignment"){
          //going through category list and storing indices that match the category entered
        //if category matches the user input, it adds the points at current index to
        //the assignmentGrades vector
        for(int i = 0; i < categoryList.size(); i++){
            if(categoryList[i] == category){
                assignmentGrades.push_back(earned_points[i]);
            }
        }
        //going through assignmentGrades vector and summing values for particular category
        for(int j = 0; j < assignmentGrades.size(); j++){
            sumPoints += assignmentGrades[j]; 
        }
        //clearing the assignmentGrades vector for next category input use
        assignmentGrades.clear();

        //returning the total points earned for the category
        return sumPoints;
    }
    else if(this->category = "Project 1"){
          //going through category list and storing indices that match the category entered
        //if category matches the user input, it adds the points at current index to
        //the proj1Grades vector
        for(int i = 0; i < categoryList.size(); i++){
            if(categoryList[i] == category){
                proj1Grades.push_back(earned_points[i]);
            }
        }
        //going through proj1Grades vector and summing values for particular category
        for(int j = 0; j < proj1Grades.size(); j++){
            sumPoints += proj1Grades[j]; 
        }
        //clearing the proj1Grades vector for next category input use
        proj1Grades.clear();

        //returning the total points earned for the category
        return sumPoints;
    }
    else if(this->category = "Project 2"){
        //going through category list and storing indices that match the category entered
        //if category matches the user input, it adds the points at current index to
        //the proj1Grades vector
        for(int i = 0; i < categoryList.size(); i++){
            if(categoryList[i] == category){
                proj2Grades.push_back(earned_points[i]);
            }
        }
        //going through proj2Grades vector and summing values for particular category
        for(int j = 0; j < proj2Grades.size(); j++){
            sumPoints += proj2Grades[j]; 
        }
        //clearing the proj2Grades vector for next category input use
        proj2Grades.clear();

        //returning the total points earned for the category
        return sumPoints;
    }
    else if(this->category = "Exam"){
          //going through category list and storing indices that match the category entered
        //if category matches the user input, it adds the points at current index to
        //the examGrades vector
        for(int i = 0; i < categoryList.size(); i++){
            if(categoryList[i] == category){
                examGrades.push_back(earned_points[i]);
            }
        }
        //going through examGrades vector and summing values for particular category
        for(int j = 0; j < examGrades.size(); j++){
            sumPoints += examGrades[j]; 
        }
        //clearing the labGrades vector for next category input use
        examGrades.clear();

        //returning the total points earned for the category
        return sumPoints;
    }else{
        std::cout << "Error"; //TEMPORARY CONDITIONAL 
    }
    //resetting sumPoints back to 0
    sumPoints = 0; 
    return 0; 
}



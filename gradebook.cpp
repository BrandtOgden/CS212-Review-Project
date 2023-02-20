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


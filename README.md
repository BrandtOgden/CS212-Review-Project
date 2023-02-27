# CS212-Review-Project
**Ryan Shilling, Ryan Brooks, Jake Dansereau, Brandt Ogden**



## Summary 
Courses that have a large quantity of assignments, projects, and/or labs can 
make it difficult for students to view their grades for each. Additionally, 
it can be difficult to calculate the weight that each of these deliverables
count towards in finding one's overall grade for the course. Hence, the
goal of this project is to provide a way for students to be able to access 
various aspects of their grades for CS 212. Such options include getting
one's overall grade for the course, listing the grades of a student's
deliverables, and being able to add, edit, and/or remove assignments. 
Getting one's grades is imperative to seeing where a student stands in the 
course. Listing the deliverables will allow students to view specific 
assignments to give them a more detailed view of their course progress.
Being able to add, edit, and remove assigments will allow students to 
manipulate their points and completion status. This serves several purposes, 
including being able to modify points should their be any changes made to 
how grades are calculated for different categories, as well as being able 
to mark deliverables as completed as the course progresses.  Overall, these 
options will allow users to not only receive their general grades for the course, 
but to be able to manipulate grade information, hence allowing this program 
to be applicable throughout a student's progress in a course. 



## Planning 
In our first planning session we outlined the different functions that we were 
going to need in our class along with the different private variables we would 
need, and started to think about how these functions would be working.
<img src="https://user-images.githubusercontent.com/123508751/221453881-786c4854-2ade-4c52-afe7-09f3017ce446.jpg"  width="400" height="400">
During this planning session we divided who would do the different functions.
Brandt worked on the constructor for the gradebook which took input from a file
and put it into the private vectors associated with the GradeBook class. He also 
worked on the get_individual_grade function along with the corresponding
options in main. Jake worked on the get_category_grade and get_total_grade 
functions along with the corresponding options in main. Ryan Shilling worked 
on the edit functions that allow the user to edit different grades and completion
status along with the corresponding options in main. Ryan Brooks wrote the 
outline for main (you can see this in the comments at the top of main.cpp) and 
did most of the miscellaneous work on it that didn't fit into anyone else's role,
including the ability to remove an assignment.  

## Compilation Instructions
There are two options to run the program:  
**Option 1**  
To run the program, acess the root directory section of the Github. You can access the 
following root directory on the Github here: https://github.com/BrandtOgden/CS212-Review-Project
Once on the main repository page, select the 'Code' button at the top right, and copy the link
to the Github. Alternatively, use this link: https://github.com/BrandtOgden/CS212-Review-Project.git
Open up Git within CLion, navigate to 'Version Control' at the bottom left hand. In the console
section, select 'Create Git Repository' and upload the link. You will now have access to all of 
the files.  You may then proceed to run the program. Note that when you compile the program, make 
sure you are in the root directory of the repository.

**Option 2**
If Option 1 does not work, you can also download the zip by accessing the 'Code' button in the
repository, and clicking 'Download Zip'. You can then access these files on your computer and 
open them in CLion. 
  
**If trouble running within CLion:**  
If you are not able to compile and run the program within CLion, simply download
gradebook.cpp, help_functions.cpp, main.cpp, and gradebook.h from the Github
repository. Once in g++, access the terminal and type in the following g++
argument (Note, if the g++ compiler is not installed, make sure to install
and configure before running this command line):  
  ```
  g++ -std=c+11 gradebook.cpp helper_functions.cpp main.cpp -o prog && ./prog  
   ``` 

## Runtime Instructions 
During runtime different options will be shown to allow you to do different things 
with the grades in the text file. It will explain exactly what your options are and
what you need to type. All the inputs are "idiot-proofed" and will not allow you
to continue until you give a valid input. Different examples of inputs are shown in 
the next section.  The following provides the specific options paths given in the
menu:  
  
Upon running the program, the user will be presented with two options: 
   
```
  Type 1 - Open the gradebook of one us  
       2 - Quit  
    
```
        
Entering option 2 will terminate the program with exit code 0. Entering option 
1 will present the user with the mock grade text files of the four 
members of our group. The menu option will look as follows:  
```
Which person's gradebook would you like to open?
    1 - Ryan Brooks  
    2 - Ryan Shilling  
    3 - Jake Dansereau  
    4 - Brandt Ogden  
```
Entering an option 1-4 prompts the 'main menu' for selecting different viewing 
options for grades:  
  ```
What would you like to do with the gradebook?  
    1 - Get your grade  
    2 - List the current deliverables  
    3 - Create a new assignment  
    4 - Edit an existing assignment  
    5 - Remove an assignment  
   ```   
**Option 1**  
Selecting option 1 will allow the user to get their overall grade for the course.
They can select various viewing options for their grade as follows:  
```
What grade would you like?  
    a - Your overall course grade  
    b - Your overall course grade and the grade of each category  
    c - Your overall course grade, grade of each category, and all the grades of the different deliverables  
    d - Your grade for one specific category  
    e - Your grade for a specific deliverable  
``` 
Selecting option 'a' prints the user's overall course grade numerically and the
corresponding alphabetical grade.  Selecting option 'b' prints the former along
with the grade of each specific category's grade. Selecting option 'c' prints the
former two along with the specific grade of each of the completed assignments from
the text file.  Selecting option 'd' then prompts the user to enter a specific 
category as follows:  
```
Enter a category you want to see the grade for:  
(enter 'Lab', 'Assignment', 'Project 1', Project 2', or 'Exam')
```
Entering one of these assignments will output the grade for that specific category.
Note that the user must enter one of the exact categories from the course, otherwise
they will again be prompted to enter a valid input. Lastly, selecting option 'e' 
allows the user to enter a specific deliverable and receive the grade for it as follows:  
 ``` 
Enter the name of an assignment:  
 ``` 
Note that the user must enter one of the exact categories from the course, otherwise
they will again be prompted to enter a valid input. After reaching the end of either 
of these options a-e for option 1, they will be prompted with an option to continue
in the gradebook or to quit:  
  ```
What would you like to do?
Type 1 - Open the gradebook of one us
     2 - Quit  
  ```
**Option 2**  
Selecting option 2 allows the user to get all of their current deliverables that are 
in the selected text file. After viewing the deliveries, the user is promped with 
the option to once again continue or quit, as seen above.   

**Option 3**  
Selecting option 3 allows the user to enter a specific category in order to create
a new assignment. Upon selecting 3, type in one of the categories for the course:  
```
Enter the category of the assignment:  
Categories:  
    Assignment  
    Lab  
    Project1  
    Project2   
```
Note that failing to enter a proper assignment name will result in an error and 
will prompt you to type in a valid assignment. Once a valid assignment is entered, 
you will be prompted to enter a specific deliverable as follows:  
  ```
  Enter the name of the assignment:  
  ```
If the user repeats a deliverable that is already created/exists in the file, they
are prompted to enter a different deliverable. Once a unique deliverable is entered, 
enter the number of points earned for the assignment as follows:  
  ```
  Enter the number of points earned for the assignment:  
  ``` 
Upon entering a valid point amount, you will be prompted to enter whether or not the
assignment has been completed. Enter 'y' or 'n':   
  ```
Has the assignment been completed or not? Enter y/n:  
  ```
After entering either 'y' or 'n', you will be delivered the following message:  
```
Assignment "Lab05" has been assignment created  
What would you like to do?  
Type 1 - Open the gradebook of one us  
     2 - Quit  
```    
Once again, the user can either continue into the gradebook, or quit. 
  
**Option 4**
Selecting option 4 will prompt the user with the following message:  
    ```
  Enter the name of an assignment:  
    ```
Enter a valid assignment, otherwise you will be prompted to enter a
valid input again.  Entering a valid assignment will prompt the user
with:  
```
What would you like to edit about this deliverable?  
    a - Edit the Grade  
    b - Edit the completion status  
```    
Editing the grade will prompt the user to enter the grade they want to change it to:  
 ```
  Enter the new grade for A2  
Maximum points on this deliverable is 50.  
 ``` 
The user is then prompted with a message letting them know the grade
has been updated:  
```
  Successfully updated grade.  
What would you like to do?  
Type 1 - Open the gradebook of one us  
     2 - Quit  
```    
Once again the user can either quit or go back into the gradebook. Entering 
option b will edit the completion status, prompting the user to enter either
'completed' or 'not-completed':  
  ```
  Should this deliverable be completed or not-completed?  
Enter 'completed' or 'not-completed'.  
  ```
Entering one of those options will successfully update the file and prompt
the user as follows:  
  ```
  Successfully updated completion.  
What would you like to do?  
Type 1 - Open the gradebook of one us  
     2 - Quit  
 ```       
**Option 5**  
Entering option 5 will prompt the user will the following:  
  ```
  What deliverable would you like to remove?  
   ``` 
Enter a specific deliverable. If the deliverable is not found
it will output the error and prompt the  user to enter a correct
deliverable. If the user enters a deliverable that is found, they
are prompted with the following example:  
```
  Assignment "A2" has been removed  
What would you like to do?  
Type 1 - Open the gradebook of one us  
     2 - Quit  
``` 
## Sample Runs


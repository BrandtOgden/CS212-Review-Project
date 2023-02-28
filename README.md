# CS212-Review-Project
**Ryan Shilling, Ryan Brooks, Jake Dansereau, Brandt Ogden**



## Summary 
Courses that have a large quantity of assignments, projects, and/or labs can 
make it difficult for students to view their grades for each. Additionally, 
it can be difficult to calculate the weight that each of these deliverables
count towards one's overall grade for the course. Hence, the
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
<p align="center" width="100%">
    <img width="500" height="500" src="https://user-images.githubusercontent.com/123508751/221453881-786c4854-2ade-4c52-afe7-09f3017ce446.jpg"> 
</p>

During this planning session we divided who would do the different functions.
Brandt worked on the constructor for the gradebook which took input from a file
and put it into the private vectors associated with the GradeBook class. He also 
worked on the get_individual_grade function along with the corresponding
options in main. Jake worked on the get_category_grade and get_total_grade 
functions along with the corresponding options in main. Ryan Shilling worked 
on the edit functions that allow the user to edit different grades and completion
status along with the corresponding options in main. Ryan Brooks wrote the 
outline for main (you can see this in the comments at the main.cpp file) and 
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
gradebook.cpp, helper_functions.cpp, main.cpp, and gradebook.h from the Github
repository. Once in g++, access the terminal and type in the following g++
argument (Note, if the g++ compiler is not installed, make sure to install
and configure before running this command line):  
```
  g++ -std=c+11 gradebook.cpp helper_functions.cpp main.cpp -o prog && ./prog  
``` 
   
**Setting up text files:**
When setting up the program, ensure that all .txt files with the grades are inside 
of the cmake-build-debug/Grades. When you pull from the GitHub repository our text files
are in there by default

**IMPORTANT: IF THESE FILES ARE NOT IN THE cmake-build-debug/Grades THE PROGRAM WILL NOTE WORK**
  

Note that if you want to set up your own text file, ensure that you input data into the 
file in the following format: 
```
first_name last_name  
category deliverable_name points_earned completion
category deliverable_name points_earned completion
category deliverable_name points_earned completion
...etc...
```
completion should be entered as the word ```completed``` or ```not completed```

This will ensure all information is read correctly.   
    


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
### Example 1
This is an accurate reflection of what Brandt's current grade is for CS 212.
You can see it display the total grade, grade of each category, and the grade
or each individual deliverable.

Input: Option 4 - Brandt's Gradebook

This is "Brandt_grades.txt":
```
Brandt Ogden
Assignment A2 50 completed
Assignment A3 0 not-completed
Assignment A4 0 not-completed
Assignment A5 0 not-completed
Lab L1 20 completed
Lab L2 20 completed
Lab L3 20 completed
Lab L4 20 completed
Lab L5 20 completed
Lab L6 0 not-completed
Lab L7 0 not-completed
Lab L8 0 not-completed
Lab L9 0 not-completed
Lab L10 0 not-completed
Lab L11 0 not-completed
Lab L12 0 not-completed
Project1 P1 0 not-completed
Project2 P2 0 not-completed
Exam FinalExam 0 not-completed
```

Console Input/Output:
```
What would you like to do?
Type 1 - Open the gradebook of one us
     2 - Quit
1
Which person's gradebook would you like to open?
    1 - Ryan Brooks
    2 - Ryan Shilling
    3 - Jake Dansereau
    4 - Brandt Ogden
4
What would you like to do with the gradebook?
    1 - Get your grade
    2 - List the current deliverables
    3 - Create a new assignment
    4 - Edit an existing assignment
    5 - Remove an assignment
1
What grade would you like?
    a - Your overall course grade
    b - Your overall course grade and the grade of each category
    c - Your overall course grade, grade of each category, and all the grades of the different deliverables
    d - Your grade for one specific category
    e - Your grade for a specific deliverable
c
Your total grade for the course is: 100%
Your letter grade is: A

Your total lab grade is: 100%
Your total assignment grade is: 100%
No Project 1 grade entered.
No Project 2 grade entered.
No Exam grade entered.

Your grade for A2 is: 100%
A3 has not been completed yet.
A4 has not been completed yet.
A5 has not been completed yet.
Your grade for L1 is: 100%
Your grade for L2 is: 100%
Your grade for L3 is: 100%
Your grade for L4 is: 100%
Your grade for L5 is: 100%
L6 has not been completed yet.
L7 has not been completed yet.
L8 has not been completed yet.
L9 has not been completed yet.
L10 has not been completed yet.
L11 has not been completed yet.
L12 has not been completed yet.
P1 has not been completed yet.
P2 has not been completed yet.
FinalExam has not been completed yet.
What would you like to do?
Type 1 - Open the gradebook of one us
     2 - Quit
2
```

### Example 2
This shows the functionality of the edit option using a somewhat random grade for each deliverable,
and a somewhat random completion status. As you can see in the output we change the number of earned points
for A2 from 50 to 10 which changes the grade from an A to an F. "Jake_grades.txt" is shown after we
run the program to show that we are pushing the changes we made from the console to the text file.

Input: Option 3 - Jake's Gradebook

"Jake_grades.txt" before we running the program:
```
Jake Dansereau
Assignment A2 50 completed
Assignment A3 35 completed
Assignment A4 45 not-completed
Assignment A5 10 not-completed
Lab L1 20 completed
Lab L2 17 completed
Lab L3 15 completed
Lab L4 18 completed
Lab L5 20 completed
Lab L6 14 completed
Lab L7 20 not-completed
Lab L8 20 not-completed
Lab L9 20 not-completed
Lab L10 20 not-completed
Lab L11 20 not-completed
Lab L12 20 not-completed
Project1 P1 150 completed
Project2 P2 300 completed
Exam FinalExam 90 completed
```

Console Input/Output:
```
What would you like to do?
Type 1 - Open the gradebook of one us
     2 - Quit
1
Which person's gradebook would you like to open?
    1 - Ryan Brooks
    2 - Ryan Shilling
    3 - Jake Dansereau
    4 - Brandt Ogden
3
What would you like to do with the gradebook?
    1 - Get your grade
    2 - List the current deliverables
    3 - Create a new assignment
    4 - Edit an existing assignment
    5 - Remove an assignment
1
What grade would you like?
    a - Your overall course grade
    b - Your overall course grade and the grade of each category
    c - Your overall course grade, grade of each category, and all the grades of the different deliverables
    d - Your grade for one specific category
    e - Your grade for a specific deliverable
e
Enter the name of an assignment:
A2
Your grade for A2 is a A
What would you like to do?
Type 1 - Open the gradebook of one us
     2 - Quit
1
Which person's gradebook would you like to open?
    1 - Ryan Brooks
    2 - Ryan Shilling
    3 - Jake Dansereau
    4 - Brandt Ogden
3
What would you like to do with the gradebook?
    1 - Get your grade
    2 - List the current deliverables
    3 - Create a new assignment
    4 - Edit an existing assignment
    5 - Remove an assignment
4
Enter the name of an assignment:
A2
What would you like to edit about this deliverable?
    a - Edit the Grade
    b - Edit the completion status
a
Enter the new grade for A2
Maximum points on this deliverable is 50.
10
Successfully updated grade.
What would you like to do?
Type 1 - Open the gradebook of one us
     2 - Quit
1
Which person's gradebook would you like to open?
    1 - Ryan Brooks
    2 - Ryan Shilling
    3 - Jake Dansereau
    4 - Brandt Ogden
3
What would you like to do with the gradebook?
    1 - Get your grade
    2 - List the current deliverables
    3 - Create a new assignment
    4 - Edit an existing assignment
    5 - Remove an assignment
1
What grade would you like?
    a - Your overall course grade
    b - Your overall course grade and the grade of each category
    c - Your overall course grade, grade of each category, and all the grades of the different deliverables
    d - Your grade for one specific category
    e - Your grade for a specific deliverable
e
Enter the name of an assignment:
A2
Your grade for A2 is a F
What would you like to do?
Type 1 - Open the gradebook of one us
     2 - Quit
2
```
"Jake_grades.txt" after running the program:
```
Jake Dansereau
Assignment A2 10 completed
Assignment A3 35 completed
Assignment A4 45 not-completed
Assignment A5 10 not-completed
Lab L1 20 completed
Lab L2 17 completed
Lab L3 15 completed
Lab L4 18 completed
Lab L5 20 completed
Lab L6 14 completed
Lab L7 20 not-completed
Lab L8 20 not-completed
Lab L9 20 not-completed
Lab L10 20 not-completed
Lab L11 20 not-completed
Lab L12 20 not-completed
Project1 P1 150 completed
Project2 P2 300 completed
Exam FinalExam 90 completed
```

### Example 3
This example demonstrates the ability to be able to list the different deliverables in the gradebook,
and to be able to remove a deliverable, and show these changes in the text file.

Input: Option 1 - Ryan Brook's Gradebook

"RyanB_grades.txt" before running the program:
```
Ryan Brooks
Assignment A2 50 completed
Assignment A3 30 completed
Lab L1 15 completed
Lab L2 20 completed
```

Console Input/Output:
```
What would you like to do?
Type 1 - Open the gradebook of one us
     2 - Quit
1
Which person's gradebook would you like to open?
    1 - Ryan Brooks
    2 - Ryan Shilling
    3 - Jake Dansereau
    4 - Brandt Ogden
1
What would you like to do with the gradebook?
    1 - Get your grade
    2 - List the current deliverables
    3 - Create a new assignment
    4 - Edit an existing assignment
    5 - Remove an assignment
2
Your current deliverables are:
A2
A3
L1
L2
What would you like to do?
Type 1 - Open the gradebook of one us
     2 - Quit
1
Which person's gradebook would you like to open?
    1 - Ryan Brooks
    2 - Ryan Shilling
    3 - Jake Dansereau
    4 - Brandt Ogden
1
What would you like to do with the gradebook?
    1 - Get your grade
    2 - List the current deliverables
    3 - Create a new assignment
    4 - Edit an existing assignment
    5 - Remove an assignment
5
What deliverable would you like to remove?
A3
Assignment "A3" has been removed
What would you like to do?
Type 1 - Open the gradebook of one us
     2 - Quit
1
Which person's gradebook would you like to open?
    1 - Ryan Brooks
    2 - Ryan Shilling
    3 - Jake Dansereau
    4 - Brandt Ogden
1
What would you like to do with the gradebook?
    1 - Get your grade
    2 - List the current deliverables
    3 - Create a new assignment
    4 - Edit an existing assignment
    5 - Remove an assignment
2
Your current deliverables are:
A2
L1
L2
What would you like to do?
Type 1 - Open the gradebook of one us
     2 - Quit
2
```

"RyanB_grade.txt" after running the program:
```
Ryan Brooks
Assignment A2 50 completed
Lab L1 20 completed
Lab L2 20 completed
```


### Example 4
This example shows that you can have the program only display the total grade and can create a new assignment.
Creating a new assignment both changes the total grade and changes the text file after running the program.

Input: Option 2 - Ryan Shilling's Gradebook

"RyanS_grades.txt" before running the program:
```
Ryan Shilling
Assignment A2 50 completed
Assignment A3 30 completed
Lab L1 20 completed
Lab L2 20 completed
```

Console Input/Output:
``` 
What would you like to do?
Type 1 - Open the gradebook of one us
     2 - Quit
1
Which person's gradebook would you like to open?
    1 - Ryan Brooks
    2 - Ryan Shilling
    3 - Jake Dansereau
    4 - Brandt Ogden
2
What would you like to do with the gradebook?
    1 - Get your grade
    2 - List the current deliverables
    3 - Create a new assignment
    4 - Edit an existing assignment
    5 - Remove an assignment
1
What grade would you like?
    a - Your overall course grade
    b - Your overall course grade and the grade of each category
    c - Your overall course grade, grade of each category, and all the grades of the different deliverables
    d - Your grade for one specific category
    e - Your grade for a specific deliverable
a
Your total grade for the course is: 86%
Your letter grade is: B
What would you like to do?
Type 1 - Open the gradebook of one us
     2 - Quit
1
Which person's gradebook would you like to open?
    1 - Ryan Brooks
    2 - Ryan Shilling
    3 - Jake Dansereau
    4 - Brandt Ogden
2
What would you like to do with the gradebook?
    1 - Get your grade
    2 - List the current deliverables
    3 - Create a new assignment
    4 - Edit an existing assignment
    5 - Remove an assignment
3
Enter the category of the assignment:
Categories:
    Assignment
    Lab
    Project1
    Project2
Assignment 
Enter the name of the assignment:
A4
Enter the number of points earned for the assignment:
25
Has the assignment been completed or not? Enter y/n:
y
Assignment "A4" has been assignment created
What would you like to do?
Type 1 - Open the gradebook of one us
     2 - Quit
1
Which person's gradebook would you like to open?
    1 - Ryan Brooks
    2 - Ryan Shilling
    3 - Jake Dansereau
    4 - Brandt Ogden
2
What would you like to do with the gradebook?
    1 - Get your grade
    2 - List the current deliverables
    3 - Create a new assignment
    4 - Edit an existing assignment
    5 - Remove an assignment
1
What grade would you like?
    a - Your overall course grade
    b - Your overall course grade and the grade of each category
    c - Your overall course grade, grade of each category, and all the grades of the different deliverables
    d - Your grade for one specific category
    e - Your grade for a specific deliverable
a
Your total grade for the course is: 76%
Your letter grade is: C
What would you like to do?
Type 1 - Open the gradebook of one us
     2 - Quit
2
```

"RyanS_grade.txt" after running the program:
```
Ryan Shilling
Assignment A2 50 completed
Assignment A3 30 completed
Lab L1 20 completed
Lab L2 20 completed
Assignment A4 25 completed
```


### Example 5
This example shows being able to display the total grade, along with the different grades for each category. It shows
how the program handles it if there are not any deliverables in a category. This example also shows the different 
ways that out program handle checking user input to make sure they enter a value that the program can deal with.

Input Option 2 - Ryan Shilling's Gradebook

"RyanS_grades.txt" before running the program
```
Ryan Shilling
Assignment A2 50 completed
Assignment A3 30 completed
Lab L1 20 completed
Lab L2 20 completed
```

Console Input/Output:
```
What would you like to do?
Type 1 - Open the gradebook of one us
     2 - Quit
blablabla
Invalid option, try again!
1
Which person's gradebook would you like to open?
    1 - Ryan Brooks
    2 - Ryan Shilling
    3 - Jake Dansereau
    4 - Brandt Ogden
NONONONONONONONONONONONON
Invalid option, try again!
2
What would you like to do with the gradebook?
    1 - Get your grade
    2 - List the current deliverables
    3 - Create a new assignment
    4 - Edit an existing assignment
    5 - Remove an assignment
1
What grade would you like?
    a - Your overall course grade
    b - Your overall course grade and the grade of each category
    c - Your overall course grade, grade of each category, and all the grades of the different deliverables
    d - Your grade for one specific category
    e - Your grade for a specific deliverable
asdkfljsadfj
Invalid option, try again!
b
Your total grade for the course is: 86%
Your letter grade is: B
Your total lab grade is: 100%
Your total assignment grade is: 80%
No Project 1 grade entered.
No Project 2 grade entered.
No Exam grade entered.
What would you like to do?
Type 1 - Open the gradebook of one us
     2 - Quit
2
```















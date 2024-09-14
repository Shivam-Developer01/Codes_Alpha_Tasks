#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Course
{
    string name;
    float creditHours;
    float gradePoints;
    string grade;
};

// For accurate calculation of the marks

string calcgrade(float percent, float &gpa)
{
    if (percent >= 90 && percent <= 100)
    {
        gpa = 4.00;
        return "A+";
    }
    else if (percent >= 75 && percent <= 90)
    {
        gpa = 3.33 + (percent - 75) * 0.027;
        return "A";
    }
    else if (percent >= 71 && percent < 75)
    {
        gpa = 3.00 + (percent - 71) * 0.075;
        return "B+";
    }
    else if (percent >= 68 && percent <71)
    {
        gpa = 2.66 + (percent - 68) * 0.11;
        return "B";
    } 
    else if (percent >= 61 && percent <68)
    {
        gpa = 2.00 + (percent - 61) * 0.095;
        return "C";
    }
    else if (percent >= 50 && percent <61)
    {
        gpa = 1 + (percent - 50) * 0.090;
        return "D";
    }
    else
    {
        gpa = 0.00;
        return "F";
    }
}


int main()
{
    int numCourses;
    vector<Course> courses;
    float totalCredits = 0.0, totalGradePoints = 0.0, cgpa;
    cout << "\t ------------------CGPA CALCULATOR FOR THE STUDENTS----------------------\n\n"<<endl;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; i++)
    {
        Course course;
        float totalMarks, obtainMarks, percent;

        // For Entering course data
        cout << "Enter the name of course " << i + 1 << ": ";
        cin >> course.name;

        cout << "Enter the credit hours for " << course.name << ": ";
        cin >> course.creditHours;

        cout << "Enter the Total Marks for " << course.name << ": ";
        cin >> totalMarks;

        cout << "Enter the Obtain Marks for " << course.name << ": ";
        cin >> obtainMarks;

        // For accurate calculation of the marks
        if (obtainMarks <= totalMarks)
        {
            percent = 100 * float(obtainMarks) / float(totalMarks);
            course.grade = calcgrade(percent, course.gradePoints);
        }
        else{
            cout << "Invalid Obtain Marks for " << course.name << endl;
            return 1;    // Exit if input is incorrect
        }

        courses.push_back(course);
        totalCredits += course.creditHours;
        totalGradePoints += course.gradePoints * course.creditHours;
    }

    cgpa = totalGradePoints / totalCredits;

    cout << "\n*** Course Graded ***\n";
    for (int i=0; i < numCourses; i++)
    {
        cout << "Course: " << courses[i].name << endl;
        cout << "Grade: " << courses[i].grade << " (GPA: " << fixed << setprecision(2) << courses[i].gradePoints << ")" << endl;
        cout << "Credit Hours: " << courses[i].creditHours << endl;
        cout << "**********************************" << endl;
    }

    // Show final results of the courses

    cout << "\n NOw Total Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Your CGPA is: : " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}
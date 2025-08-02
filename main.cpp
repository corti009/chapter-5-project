#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> studentNames = {
        "Jackie", "Sam", "Tom", "Bill", "Mary", "Paul", "Zev", "Barb"
    }; 

    if (studentNames.empty()) {
        std::cout << "No students found in the lineup." << std::endl;
        return 0; 
    }
    int totalStudents = studentNames.size();
    std::string frontOfLine = *std::min_element(studentNames.begin(), studentNames.end());
    std::string endOfLine = *std::max_element(studentNames.begin(), studentNames.end());

    std::cout << "Total number of students: " << totalStudents << std::endl; 
    std::cout << "Student at the front of the line: " << frontOfLine << std::endl; 
    std::cout << "Student at the end of the line: " << endOfLine << std::endl; 

    return 0;
}
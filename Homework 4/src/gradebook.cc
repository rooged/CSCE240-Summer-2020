/* Copyright 240 Timothy Gedney
*
* Expanded upon the provided methods in the .h file. Created new method to create a gradeBook instance
*/

#include <inc/gradebook.h>
#include <cstddef>
//using size_t

vector<char> grades;

//create pointer and assign
GradeBook::GradeBook() {
  (*this).grades.clear();
}

//adds new grade to the vector using the push back method
void GradeBook::Add(char grade) {
  grades.push_back(grade);
}

//returns grade at the index entered, retruns '\0' if the grade vector is empty
char GradeBook::Get(size_t index) const {
  if (index >= grades.size()) {
    return '\0';
  }
  return grades[index];
}

//adds new grade
const GradeBook GradeBook::Add(const GradeBook& that) const {
  GradeBook addGrade = CreateGradeBook();
  for (size_t i = 0; i < that.GetSize(); i++) {
    addGrade.Add(that.Get(i));
  }
  return addGrade;
}

//returns the GPA of a gradebook, if/else statements convert the letters to numerical values &
//calculates the GPA then converts the GPA back into a letter grade to be returned
char GradeBook::GetGPA() const {
  if (grades.size() == 0) {
    return '\0';
  }
  double sum = 0;
  for (size_t i = 0; i < grades.size(); i++) {
    if (grades[i] == 'A') {
      sum += 4;
    } else if (grades[i] == 'B') {
      sum += 3;
    } else if (grades[i] == 'C') {
      sum += 2;
    } else {
      sum += 1;
    }
  }
  double gpa = sum / grades.size();
  char answer;
  if (gpa >= 3.5) {
    answer = 'A';
  } else if (gpa >= 2.5) {
    answer = 'B';
  } else if (gpa >= 1.5) {
    answer = 'C';
  } else if (gpa >= 0.5) {
    answer = 'D';
  } else {
    answer = 'F';
  }
  return answer;
}

//finds the highest grade in a gradebook by using if/else statements to find & return the grade
char GradeBook::GetMax() const {
  if (grades.size() == 0) {
    return '\0';
  }
  char max = 'F';
  char current;
  for (size_t i = 0; i < grades.size(); i++) {
    current = grades[i];
    if (current == 'A') {
      max = current;
    } else if (current == 'B' && max != 'A') {
      max = current;
    } else if (current == 'C' && (max != 'A' || max != 'B')) {
      max = current;
    } else if (current == 'D' && (max != 'A' || max != 'B' || max != 'C')) {
      max = current;
    }
  }
  return max;
}

//returns the size of the grades vector
const size_t GradeBook::GetSize() const {
  return grades.size();
}

//returns a boolean value by checking if the two gradebooks are both empty or if their gpa's & max
//grades are equal
bool GradeBook::Equals(const GradeBook& that) const {
  GradeBook compareGrade = CreateGradeBook();
  if ((that.GetSize() == 0 && compareGrade.GetSize() == 0) ||
       ((that.GetGPA() == compareGrade.GetGPA()) && (that.GetMax() == compareGrade.GetMax()))) {
    return true;
  } else {
    return false;
  }
}

//returns a boolean value by checking if the calling instance is empty, has a lower gpa, or if the two
//have the same gpa, the calling instance has a lower max grade
bool GradeBook::LessThan(const GradeBook& that) const {
  GradeBook compareGrade = CreateGradeBook();
  if (that.GetSize() == 0) {
    return true;
  } else if (that.GetGPA() < compareGrade.GetGPA()) {
    return true;
  } else if (that.GetGPA() == compareGrade.GetGPA()) {
    if (that.GetMax() < compareGrade.GetMax()) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

//creates a new gradebook instance from the vector to be compared in methods
GradeBook GradeBook::CreateGradeBook() const {
  GradeBook gradeBook;
  for (size_t i = 0; i < grades.size(); i++) {
    gradeBook.Add(grades[i]);
  }
  return gradeBook;
}
                                                                                          
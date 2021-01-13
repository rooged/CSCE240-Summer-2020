/*  Copyright 240 Timothy Gedney
 *
 *  Finalize correct header file designation & added new method to create new gradebook instance
 */
#ifndef INC_GRADEBOOK_H_
#define INC_GRADEBOOK_H_

#include <cstddef>
// using size_t
#include <vector>
using std::vector;
#include <cmath>

class GradeBook {
 public:
  //  adds new grade to instance
  void Add(char grade);


  //  returns average of all grades or \0 if empty
  char GetGPA() const;

  //  returns max grade in gradebook or \0 if empty
  char GetMax() const;

  //  returns the number of grades currently stored
  const size_t GetSize() const;

  //  creates new gradebook instance
  GradeBook CreateGradeBook() const;

  /* Returns the grade at the supplied index. When that index is out of range, a
   * value of \0 is returned.
   */
  char operator[](size_t index) const;


  /* Adds two GradeBook instances together and returns their join as a new
   * object.
   * Order is maintained by adding the calling instance's grades to the new
   * Gradebook instance, followed by the parameter GradeBook's instances.
   */
  const GradeBook operator+(const GradeBook& that) const;


  /* Returns true when two GradeBook instances have the same average grade
   * value; returns false otherwise. An empty instance is treated as having an
   * average grade value of -1---that is, less than F. Two empty GradeBook
   * instances are considered equal.
   */
  bool operator==(const GradeBook& that) const;


  /* Returns false when two GradeBook instances have the same average grade
   * value; returns true otherwise. An empty instance is treated as having an
   * average grade value of -1---that is, less than F. Two empty GradeBook
   * instances are considered equal.
   */
  bool operator!=(const GradeBook& that) const;


  /* Returns true when the calling instance has a smaller grade average than the
   * paramter instance's average. If they are even, it compares their max
   * grades. An empty instance is treated as having an average grade value of
   * -1--that is, less than F. Two empty GradeBook instances are equal.
   */
  bool operator<(const GradeBook& that) const;

 private:
  vector<char> grades;
};

#endif  // INC_GRADEBOOK_H_
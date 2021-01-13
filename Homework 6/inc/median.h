/*  Copyright 240 Timothy Gedney
 *
 *  Finalize correct header file designation
 */
#ifndef INC_MEDIAN_H_
#define INC_MEDIAN_H_

/* This child of the Statistic class should be a concrete class---that is, it
 * should implement both Collect and Calculate methods from the parent class
 * Statistic. I will let you decide how to implement those methods.
 *
 * The Calculate method should return the median of data gathered by the Collect
 * method. You are free to implement both methods by any means you choose.
 */

#include <inc/statistic.h>
#include <vector>
using std::vector;

namespace csce240 {

class Median : public Statistic {
 public:
  //  sorts the array, smallest to largest
  void Sort();

  /* Collects a datum into some collection (decided by you).
   */
  void Collect(double datum);


  /* Calculates and returns the median of the data collected by the Collect
   * method.
   */
  double Calculate() const;

 private:
  vector<double> array;
};
}  //  namespace csce240

#endif  // INC_MEDIAN_H_
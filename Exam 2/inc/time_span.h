/* Copyright 240 Timothy Gedney
*
* Finalize correct header file to fit within parameters
*/
#ifndef TIME_SPAN_H_ //define guards
#define TIME_SPAN_H_

// TimeSpan Points:
//   Compiles: 1 (make test_time_span)
//   Lints: 1  (cpplint --root=./ */time_span.*)
//   TestPlusTimeSpan: 1
//   TestPlusInt: 1
//   TestPlusExtract: 1
//   TestPlusInsert: 1


#include <istream>
#include <ostream>


/* A measurement of time, representable as a number of hours minutes and
 * seconds.
 *
 *  You must supply the provided portions of the public interface without
 *  change. You may add other useful methods, as you require.
 */
class TimeSpan {
 public:
  // represents no time
  TimeSpan();

  // represents a span covering the parameters
  TimeSpan(int hours, int minutes, int seconds);

  // these must be provided for any test to pass
  inline int hours() const { return hour_; } // returns the whole hours in the span
  inline int minutes() const { return min_; } // returns the whole minutes in the span
  inline int seconds() const { return sec_; } // returns the seconds in the span


  // returns the sum of two TimeSpan instances
  const TimeSpan Add(const TimeSpan& that) const;
  const TimeSpan operator+(const TimeSpan& rhs) const;
//  const TimeSpan operator+(int rhs) const;

  std::istream& Insert(std::istream* in);
  std::ostream& Extract(std::ostream* out) const;

private:
  int hour_;
  int min_;
  int sec_;
};

// returns the sum of a number of seconds as an int and a TimeSpan
const TimeSpan operator+(int lhs, const TimeSpan& rhs);

// extracts the TimeSpan as HH : MM : SS
std::istream& operator>>(std::istream& lhs, TimeSpan& rhs);

// inserts the TimeSpan from HH : MM : SS each being formatted as an int
std::ostream& operator<<(std::ostream& lhs, const TimeSpan& rhs);

#endif // TIME_SPAN_H_

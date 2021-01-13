/* Copyright 240 Timothy Gedney
*
* Expanded upon the provided methods in the .h file
*/

#include <inc/time_span.h>
using std::istream;
using std::ostream;

//default constructor
TimeSpan::TimeSpan() : hour_(0), min_(0), sec_(0) {
  //empty
}

//parameterized constructor
TimeSpan::TimeSpan(int hour, int minute, int sec) {
  if (hour < 0) {
    hour *= -1;
  }
  if (minute < 0) {
    minute *= -1;
  }
  if (sec < 0) {
    sec *= -1;
  }

  int leftover = 0;
  if (sec > 59) {
    leftover = sec / 60;
    sec = sec % 60;
    minute += leftover;
  }
  if (minute > 59) {
    leftover = minute / 60;
    minute = minute % 60;
    hour += leftover;
  }

  hour_ = hour;
  min_ = minute;
  sec_ = sec;
}

//adds to TimeSpan instances together & returns the sum
const TimeSpan TimeSpan::Add(const TimeSpan& that) const {
  int sec = sec_ + that.sec_;
  int minute = min_ + that.min_;
  int hour = hour_ + that.hour_;

  int leftover = 0;
  if (sec > 59) {
    leftover = sec / 60;
    sec = sec % 60;
    minute += leftover;
  }
  if (minute > 59) {
    leftover = minute / 60;
    minute = minute % 60;
    hour += leftover;
  }

  return TimeSpan(hour, minute, sec);
}

const TimeSpan TimeSpan::operator+(const TimeSpan& rhs) const {
  return Add(rhs);
}

//returns the sum of a number of seconds as an int and a TimeSpan
const TimeSpan operator+(int lhs, const TimeSpan& rhs) {
  TimeSpan time = TimeSpan(0, 0, lhs);
  return time.Add(rhs);
}

istream& TimeSpan::Insert(istream* in) {
  char colon_sym;
  *in >> std::skipws >> hour_ >> colon_sym >> min_ >> colon_sym >> sec_;
  if (hour_ < 0) {
    hour_ *= -1;
  }
  if (min_ < 0) {
    min_ *= -1;
  }
  if (sec_ < 0) {
    sec_ *= -1;
  }

  return *in;
}

//extracts the TimeSpan as HH : MM : SS
std::istream& operator>>(std::istream& lhs, TimeSpan& rhs) {
  return rhs.Insert(&lhs);
}

ostream& TimeSpan::Extract(ostream* out) const {
  *out << hour_ << " : " << min_ << " : " << sec_;
  return *out;
}

//insert the TimeSpan from HH : MM : SS each being formatted as an int
std::ostream& operator<<(std::ostream& lhs, const TimeSpan& rhs) {
  return rhs.Extract(&lhs);
}

/* Copyright 240 Timothy Gedney
*
* Expand the provided calculation library from comp_geo.h to be implemented and calculated here.
* The methods should stick to the specifications provided
*/
#include <comp_geo.h>
#include <iostream>
#include <cmath>
//using pow
//using fabs

//calculates circumference using C = 2*pi*r
//where radius is calculated from the CalcDistance method
double CalcCircumference(double x_center, double y_center, double x_boundary, double y_boundary) {
  double radius = CalcDistance(x_center, y_center, x_boundary, y_boundary);
  return 2 * k_pi * radius;
}

//calculates the area of a circle using A = pi*r^2
//where radius is calculated from the CalcDistance method
double CalcCircleArea(double x_center, double y_center, double x_boundary, double y_boundary) {
  double radius = CalcDistance(x_center, y_center, x_boundary, y_boundary);
  return k_pi * pow(radius, 2);
}

//a helper method used by CalcPerimeter & CalcRectangleArea to calculate a ractangle sides length
double CalcRectangleSide(double point_1, double point_2) {
  return fabs(point_2 - point_1);
}

//calculates a rectangles perimeter by using CalcRectangleSide to get the side lengths
//then adds them together twice over to reduce processing power
double CalcPerimeter(double x_ll, double y_ll, double x_ur, double y_ur) {
  double length = CalcRectangleSide(x_ll, x_ur);
  double height = CalcRectangleSide(y_ll, y_ur);
  return length + length + height + height;
}

//calculates a rectangles area by using CalcRectangleSide to get the side lengths
//then multiplies them together to get area
double CalcRectangleArea(double x_ll, double y_ll, double x_ur, double y_ur) {
  double length = CalcRectangleSide(x_ll, x_ur);
  double height = CalcRectangleSide(y_ll, y_ur);
  return length * height;
}

//calculates the squared distance between two points using (x2-x1)^2 + (y2-y1)
double CalcDistanceSquared(double x_1, double y_1, double x_2, double y_2) {
  return pow(x_2 - x_1, 2) + pow(y_2 - y_1, 2);
}

//calculates the distance between two points by using CalcDistanceSquared &
//square rooting the distance
double CalcDistance(double x_1, double y_1, double x_2, double y_2) {
  double distanceSquared = CalcDistanceSquared(x_1, y_1, x_2, y_2);
  return sqrt(distanceSquared);
}

//returns whether two points are equal by subtracting each x & y values,
//if the subtracted number is less than epsilon(a small predefined number) then they are counted as equal
bool PointsEqual(double x_1, double y_1, double x_2, double y_2) {
  double epsilon = 0.000001;
  if (fabs(x_2 - x_1) < epsilon && fabs(y_2 - y_1) < epsilon) {
    return true;
  } else {
    return false;
  }
}

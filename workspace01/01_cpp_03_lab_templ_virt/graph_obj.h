/*******************************************************************************
 *                                Copyright 2002
 *                            Fraunhofer-Gesellschaft
 *                      Institut fuer Integrierte Schaltungen
 *                             All rights reserved
 *
 * Filename:                 $RCSfile: graph_obj.h,v $
 * Author:                   Bernhard Niemann, Fhg
 * Limitations:
 * Known Errors:
 * No Warranty:
 * This file is part of the "Modeling SystemC" training class. It is provided
 * on an AS IS basis WITHOUT WARRANTY OF ANY KIND, either express or implied. 
 * 
 * =============================================================================

 * $Id: graph_obj.h,v 1.2 2006/03/28 11:41:04 systemC Exp $
 * $Log: graph_obj.h,v $
 * Revision 1.2  2006/03/28 11:41:04  systemC
 * + adopt to work with gcc and MS VC++
 *
 * Revision 1.1.1.1  2002/09/03 09:30:31  systemC
 * first import
 *
 *
 ******************************************************************************/

#include <iostream>

class graph_obj
{
public:
  virtual ~graph_obj() {
	  std::cout << "graph_obj destructor called" << std::endl;
  }
  
  virtual double area() const = 0;

  void dump(std::ostream& os) const {
    os << area();
  }
};

std::ostream& operator<<(std::ostream& os, const graph_obj& obj) {
  obj.dump(os);
  return os;
}

class rect : public graph_obj
{
public:
  rect(double len = 0.0, double height = 0.0) : _len(len), _height(height) {
	std::cout << "rect created" << std::endl;
  }
  virtual ~rect() {
	std::cout << "rect deleted" << std::endl;
  }
  virtual double area() const {
    return _len * _height;
  }

protected:
  double _len;
  double _height;
};

// TASK: implement a class circle that inherits from the virtual base class
// graph_obj and implements the method area(). The constructor should take
// the radius as an optional argument (default = 0.0) 
// Hint: don't forget to implement a destructor as well.
class circle 
{
 // ???
};

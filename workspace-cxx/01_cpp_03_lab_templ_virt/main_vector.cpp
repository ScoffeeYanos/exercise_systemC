/*******************************************************************************
 *                                Copyright 2002
 *                            Fraunhofer-Gesellschaft
 *                      Institut fuer Integrierte Schaltungen
 *                             All rights reserved
 *
 * Filename:                 $RCSfile: main_vector.cpp,v $
 * Author:                   Bernhard Niemann, Fhg
 * Limitations:
 * Known Errors:
 * No Warranty:
 * This file is part of the "Modeling SystemC" training class. It is provided
 * on an AS IS basis WITHOUT WARRANTY OF ANY KIND, either express or implied. 
 * 
 * =============================================================================
 * $Id: main_vector.cpp,v 1.2 2006/03/28 11:41:04 systemC Exp $
 * $Log: main_vector.cpp,v $
 * Revision 1.2  2006/03/28 11:41:04  systemC
 * + adopt to work with gcc and MS VC++
 *
 * Revision 1.1.1.1  2002/09/03 09:30:31  systemC
 * first import
 *
 *
 ******************************************************************************/

#include "vector.h"

#include <iostream>

// test bench 
int main()
{
  vector<int> x(2,1);
  vector<int> y(3,2);
  vector<int> z(2,2);

  std::cout << "-----------------------" << std::endl;

  x += y;
  x.dump(std::cout);

  std::cout << "-----------------------" << std::endl;

  x += z;
  x.dump(std::cout);

  std::cout << "-----------------------" << std::endl;

  x.write(-1,0);
  x.write(-1,2);
  x.dump(std::cout);

  std::cout << "-----------------------" << std::endl;

  x=z;
  x.dump(std::cout);
  z.dump(std::cout);

  return 0;
}

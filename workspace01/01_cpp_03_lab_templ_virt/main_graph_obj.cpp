/*******************************************************************************
 *                                Copyright 2002
 *                            Fraunhofer-Gesellschaft
 *                      Institut fuer Integrierte Schaltungen
 *                             All rights reserved
 *
 * Filename:                 $RCSfile: main_graph_obj.cpp,v $
 * Author:                   Bernhard Niemann, Fhg
 * Limitations:
 * Known Errors:
 * No Warranty:
 * This file is part of the "Modeling SystemC" training class. It is provided
 * on an AS IS basis WITHOUT WARRANTY OF ANY KIND, either express or implied. 
 * 
 * =============================================================================

 * $Id: main_graph_obj.cpp,v 1.2 2006/03/28 11:41:04 systemC Exp $
 * $Log: main_graph_obj.cpp,v $
 * Revision 1.2  2006/03/28 11:41:04  systemC
 * + adopt to work with gcc and MS VC++
 *
 * Revision 1.1.1.1  2002/09/03 09:30:31  systemC
 * first import
 *
 *
 ******************************************************************************/

#include "graph_obj.h"

#include <iostream>

using namespace std;

int main()
{
  rect x(1,2);
  cout << "area: " << x.area() << endl;

  cout << "---------------------------------" << endl;

  circle c(1);
  cout << "area: " << c.area() << endl;

  cout << "---------------------------------" << endl;

  graph_obj* g_ptr = new circle(2);
  cout << "area: " << g_ptr->area() << endl;
  delete g_ptr;

  cout << "---------------------------------" << endl;

  return 0;
}

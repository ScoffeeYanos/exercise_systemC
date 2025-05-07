/*******************************************************************************
 *                                Copyright 2002
 *                            Fraunhofer-Gesellschaft
 *                      Institut fuer Integrierte Schaltungen
 *                             All rights reserved
 *
 * Filename:                 $RCSfile: vector.cpp,v $
 * Author:                   Bernhard Niemann, Fhg
 * Limitations:
 * Known Errors:
 * No Warranty:
 * This file is part of the "Modeling SystemC" training class. It is provided
 * on an AS IS basis WITHOUT WARRANTY OF ANY KIND, either express or implied. 
 * 
 * =============================================================================
 * $Id: vector.cpp,v 1.2 2006/03/28 11:41:04 systemC Exp $
 * $Log: vector.cpp,v $
 * Revision 1.2  2006/03/28 11:41:04  systemC
 * + adopt to work with gcc and MS VC++
 *
 * Revision 1.1.1.1  2002/09/03 09:30:30  systemC
 * first import
 *
 *
 ******************************************************************************/

#include "vector.h"

// constructor(s)
vector::vector(int size) 
{
  _size = size;
  _buf = new t_vector[_size];

  for(int idx = 0;idx < _size;++idx) {
      _buf[idx] = -1;
  }

  std::cout << "vector of size: " << _size << " created [ ";
  for(int idx = 0; idx < _size;++idx) {
    std::cout << _buf[idx] << " ";
  }
  std::cout << " ]" << std::endl;
}

// destructor
vector::~vector() 
{
  delete [] _buf;
  std::cout << "vector of size: " << _size << " deleted" << std::endl;
}


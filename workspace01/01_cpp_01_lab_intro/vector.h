/*******************************************************************************
 *                                Copyright 2002
 *                            Fraunhofer-Gesellschaft
 *                      Institut fuer Integrierte Schaltungen
 *                             All rights reserved
 *
 * Filename:                 $RCSfile: vector.h,v $
 * Author:                   Bernhard Niemann, Fhg
 * Limitations:
 * Known Errors:
 * No Warranty:
 * This file is part of the "Modeling SystemC" training class. It is provided
 * on an AS IS basis WITHOUT WARRANTY OF ANY KIND, either express or implied. 
 * 
 * =============================================================================

 * $Id: vector.h,v 1.1.1.1 2002/09/03 09:30:30 systemC Exp $
 * $Log: vector.h,v $
 * Revision 1.1.1.1  2002/09/03 09:30:30  systemC
 * first import
 *
 *
 ******************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

typedef int t_vector;

// class declaration
class vector
{
public:
  vector(int size = 16);
  ~vector();

protected:
  t_vector* _buf;
  int _size;
  
};

#endif // VECTOR_H

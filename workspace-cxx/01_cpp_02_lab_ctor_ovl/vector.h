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

 * $Id: vector.h,v 1.2 2006/03/28 11:36:30 nmn Exp $
 * $Log: vector.h,v $
 * Revision 1.2  2006/03/28 11:36:30  nmn
 * + adopt to work with gcc and MS VC++
 *
 * Revision 1.1.1.1  2002/09/03 09:30:31  systemC
 * first import
 *
 *
 ******************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

typedef int t_vector;

class vector
{
public:
  // TASK: implement a constructor where you can optionally specify
  // the initial value for the vector elements (default = 0)
  vector(int size = 16 /* ??? */,int init_val = 0);
  ~vector();

  // read from VECTOR
  // TASK: implement reading from vector with range check
  // ???
  bool read(t_vector &ref, int idx) const; // read with range check
  t_vector read(int idx) const; // fast read without range check

  // write to VECTOR
  bool write(const t_vector& val, int idx); // write with range check
  
  // operators
  bool operator==(const vector& rhs) const;

  vector& operator=(const vector& rhs);
  vector& operator+=(const vector& rhs);

  // persisitence and I/O
  void dump(std::ostream& os) const;

protected:
  // helper functions
  bool is_legal_idx(const int& idx) const; // implement the range checking

protected:
  t_vector* _buf;
  int _size;
};

inline 
bool vector::is_legal_idx(const int& idx) const
{
  return ((idx < _size) && (idx >= 0));
}

#endif // VECTOR_H

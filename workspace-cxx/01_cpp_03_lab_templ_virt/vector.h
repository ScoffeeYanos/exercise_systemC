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

 * $Id: vector.h,v 1.2 2006/03/28 11:41:04 systemC Exp $
 * $Log: vector.h,v $
 * Revision 1.2  2006/03/28 11:41:04  systemC
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


// TASK: modify the vector class to be a vector for arbitrary data types
// i.e. vector -> vector<T>
// Hints:
// 1. we have defined t_vector as the data type to be stored in the vector.
//    now we want to use a generic type T instead of t_vector
// 2. remember to modify class declaration AND method definitions
// 3. to help you the constructor (vector<T>::vector(int,T)) has already
//    been implemented. Take this as an example for your modifications
// 4. This time no "???" have been provided!!

typedef int t_vector;
template<class T>
class vector
{
public:
  vector(int size = 16, T init_val = T());
  ~vector();

  // read from VECTOR
  bool read(T& val, int idx) const; // read with range check
  T read(int idx) const; // fast read without range check

  // write to VECTOR
  bool write(const T& val, int idx); // write with range check
  
  // operators
  bool operator==(const vector<T>& rhs) const;

  vector<T>& operator=(const vector<T>& rhs);
  vector<T>& operator+=(const vector<T>& rhs);

  // persisitence and I/O
  void dump(std::ostream& os) const;

protected:
  // helper functions
  bool is_legal_idx(const int& idx) const; // implement the range checking

protected:
  T* _buf;
  int _size;
};

template< class T >
inline
vector<T>::vector(int size, T init_val) 
{
  _size = size;
  _buf = new T[_size];

  for(int idx = 0;idx < _size;++idx) {
    _buf[idx] = init_val;
  }

  std::cout << "vector of size: " << _size << " created [ ";
  for(int idx = 0; idx < _size;++idx) {
	std::cout << _buf[idx] << " ";
  }
  std::cout << " ]" << std::endl;
}

template< class T >
vector<T>::~vector()
{
  delete [] _buf;
  std::cout << "vector of size: " << _size << " deleted" << std::endl;
}

template< class T >
bool vector<T>::read(T& val, int idx) const
{
  if( !is_legal_idx(idx) ) {
    return false;
  }
  else {
    val = _buf[idx];
  }
  return true;
}

template< class T >
T vector<T>::read(int idx) const
{
  return _buf[idx];
}

template< class T >
bool vector<T>::write(const T& val, int idx)
{
  if( !is_legal_idx(idx) ) {
    return false;
  }
  else {
    _buf[idx] = val;
  }
  return true;
}

template< class T >
bool vector<T>::operator==(const vector<T>& rhs) const
{
  if(_size != rhs._size)
    return false;

  bool result = true;
  for(int idx = 0;idx < _size;++idx) {
    result = result && (_buf[idx] == rhs._buf[idx]);
  }
  return result;
}

template< class T >
vector<T>& vector<T>::operator=(const vector<T>& rhs)
{
  // do nothing if sizes don't match
  if(_size != rhs._size)
    return *this;

  for(int idx = 0;idx < _size;++idx) {
    _buf[idx] = rhs._buf[idx];
  }
  return *this;
}

template< class T >
vector<T>& vector<T>::operator+=(const vector<T>& rhs)
{
  // do nothing if sizes don't match
  if(_size != rhs._size)
    return *this;

  for(int idx = 0;idx < _size;++idx) {
    _buf[idx] += rhs._buf[idx];
  }
  return *this;
}

template< class T >
void vector<T>::dump(std::ostream& os) const
{
  os << this << " [ ";
  for(int idx = 0;idx < _size;++idx) {
    os << _buf[idx] << " ";
  }
  os << " ]" << std::endl;
}

template< class T >
inline 
bool vector<T>::is_legal_idx(const int& idx) const
{
  return ((idx < _size) && (idx >= 0));
}

#endif // VECTOR_H

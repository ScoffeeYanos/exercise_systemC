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
 * Revision 1.1.1.1  2002/09/03 09:30:31  systemC
 * first import
 *
 *
 ******************************************************************************/

#include "vector.h"

#include <iostream>

vector::vector(int size /*= 16 ??? */ , int init_val) {
    _size = size;
    _buf = new t_vector[_size];

    // TASK: implement initialization of vector elements to init_val
    for (int idx = 0; idx < _size; ++idx) {
        _buf[idx] = init_val;
    }

    std::cout << "vector of size: " << _size << " created [ ";
    for (int idx = 0; idx < _size; ++idx) {
        std::cout << _buf[idx] << " ";
    }
    std::cout << " ]" << std::endl;
}

vector::~vector() {
    delete[] _buf;
    std::cout << "vector of size: " << _size << " deleted" << std::endl;
}

// TASK: implement reading from vector with range check
bool vector::read(int &ref, int idx) const {
    if (idx >= _size) {
        return false;
    }
    ref = _buf[idx];
    return true;
}

t_vector vector::read(int idx) const {
    return _buf[idx];
}

bool vector::write(const t_vector &val, int idx) {
    if (!is_legal_idx(idx)) {
        return false;
    } else {
        _buf[idx] = val;
    }
    return true;
}

bool vector::operator==(const vector &rhs) const {
    if (_size != rhs._size)
        return false;

    bool result = true;
    for (int idx = 0; idx < _size; ++idx) {
        result = result && (_buf[idx] == rhs._buf[idx]);
    }
    return result;
}

// TASK: finish implementation of operator=
vector &vector::operator=(const vector &rhs) {
    // do nothing if sizes don't match
    // assign the two vectors if sizes match

    if (this == &rhs) {
        return *this;
    }
    if (_size != rhs._size) {
        return *this;
    }
    for (int i = 0; i < _size; ++i) {
        _buf[i] = rhs._buf[i];
    }
    return *this;
}

// TASK: finish implementation of operator+=
vector &vector::operator+=(const vector &rhs) {
    // do nothing if sizes don't match
    // add the two vectors if sizes match
    if (_size != rhs._size) {
        return *this;
    }
    for (int idx = 0; idx < _size; ++idx) {
        _buf[idx] += rhs._buf[idx];
    }
    return *this;
}

void vector::dump(std::ostream &os) const {
    os << this << " [ ";
    for (int idx = 0; idx < _size; ++idx) {
        os << _buf[idx] << " ";
    }
    os << " ]" << std::endl;
}

#include <cmath>
#include "vehicles.h"

vehicle::vehicle(color col) : _col(col)
{}

color vehicle::get_color() const
{
  return _col;
}

vehicle::~vehicle() {
}

car::car(color col) : vehicle(col)
{
  _vx = _vy = 0;
}

void car::set_speed(double vx, double vy)
{
  _vx = vx;
  _vy = vy;
}

double car::get_speed() const
{
  return sqrt(_vx*_vx + _vy*_vy);
}

const char *car::get_type() const
{
  return "car";
}

jet::jet(color col) : vehicle(col)
{
  _vx = _vy = _vz = 0;
}

void jet::set_speed(double vx, double vy, double vz)
{
  _vx = vx;
  _vy = vy;
  _vz = vz;
}

double jet::get_speed() const
{
  return sqrt(_vx*_vx + _vy*_vy + _vz*_vz);
}

const char *jet::get_type() const
{
  return "jet";
}

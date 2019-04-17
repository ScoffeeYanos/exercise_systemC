#ifndef VEHICLES_H
#define VEHICLES_H

#include <ostream>

//----------------------------------- Color ------------------------------------

enum color
{
  red, green, blue, yellow, black, silver, gold
};

static inline std::ostream& operator<<(std::ostream &os, const color &col)
{
  switch(col) {
    case red:    return os << "red";
    case green:  return os << "green";
    case blue:   return os << "blue";
    case yellow: return os << "yellow";
    case black:  return os << "black";
    case silver: return os << "silver";
    case gold:   return os << "gold";
    default:     return os << "blank";
  }
}

//---------------------------------- Vehicle -----------------------------------

class vehicle
{
  public:
    vehicle(color col);
    color get_color() const;
    virtual double get_speed() const = 0;
    virtual const char *get_type() const = 0;
    virtual ~vehicle();
  protected:
    color _col;
};

static inline std::ostream& operator<<(std::ostream &os, const vehicle &veh)
{
  return os << veh.get_color() << "-colored " << veh.get_type() << " with speed " << veh.get_speed();
}

//------------------------------------ Car -------------------------------------

class car : public vehicle
{
  public:
    car(color col);
    void set_speed(double vx, double vy);
    double get_speed() const;
    virtual const char *get_type() const;
  protected:
    double _vx;
    double _vy;
};

//------------------------------------ Jet -------------------------------------

class jet : public vehicle
{
  public:
    jet(color col);
    void set_speed(double vx, double vy, double vz);
    double get_speed() const;
    virtual const char *get_type() const;
  protected:
    double _vx;
    double _vy;
    double _vz;
};

#endif // VEHICLES_H

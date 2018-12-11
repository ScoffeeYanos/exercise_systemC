#ifndef COMPLEX_H
#define COMPLEX_H

#include <ostream>

class complex
{
  friend std::ostream& operator<<(std::ostream&, const complex&);
  
  public:
    complex(double re=0, double im=0);

    complex operator+(const complex&) const;
    complex operator-(const complex&) const;
    complex operator*(const complex&) const;

    const complex& operator+=(const complex&);
    const complex& operator-=(const complex&);
    const complex& operator*=(const complex&);

    bool operator<(const complex&) const;
    bool operator>(const complex&) const;
    bool operator<=(const complex&) const;
    bool operator>=(const complex&) const;
    bool operator==(const complex&) const;
    
    double abs() const;

  protected:
    double _re;
    double _im;
};

#endif // COMPLEX_H

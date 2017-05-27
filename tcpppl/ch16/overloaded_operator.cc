//
// Created by 孙永录 on 27/05/2017.
//

#include "concrete_class.cc"

using namespace Chrono;

inline bool operator==(Date a, Date b) {
  return a.day() == b.day() && a.month() == b.month() && a.year() == b.year();
}

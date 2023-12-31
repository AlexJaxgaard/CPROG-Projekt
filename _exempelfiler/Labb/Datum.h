// Labb3, Datum.h – klassdefinition

#ifndef DATUM_H
#define DATUM_H

#include <array>
#include <iostream>

class Datum
{
  friend std::ostream &operator<<(std::ostream &, const Datum &);

  unsigned int year;
  unsigned int month;
  unsigned int day;

  // Deklaration av statisk privat medlem, "ant_dagar per månad"
  static const std::array<unsigned int, 13> ANT_DAGAR_PER_MAANAD;
  // void step_one_day(); // Öka datum med en dag

public:
  Datum();

  Datum(int, int, int);
  void set_date(int, int, int); // set year, month, day

  // OBS. funktionen "step_one_day()" bör vara PRIVATE
  void step_one_day();           // Öka datum med en dag
  static bool is_skott_aar(int); // Är det skottår?
  bool end_of_month(int) const;  // Är dagen den sista i månaden?
  bool operator<(const Datum &other) const;
  bool operator>(const Datum &other) const;
  bool operator<=(const Datum &other) const;
  bool operator==(const Datum &other) const;
  bool operator!=(const Datum &other) const;
  Datum &operator++();
  Datum operator+=(int a);

  Datum operator+(int days) const;
  Datum operator+(Datum datum);

  

  Datum operator++(int);
};
extern Datum operator+(int days, const Datum& date);

#endif

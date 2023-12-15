// Labb3, Datum.cpp – definitioner av icke-triviala medlemsfunktioner

#include <iostream>
#include <string>
#include "Datum.h"

// Initialisera statisk medlem
// (första elementet används inte i denna lösning!)
const std::array<unsigned int, 13> Datum::ANT_DAGAR_PER_MAANAD = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Konstruktor
Datum::Datum(int year, int month, int day)
{
  set_date(year, month, day);
}

Datum::Datum()
{
  set_date(2000, 01, 01);
}

void Datum::set_date(int yy, int mm, int dd)
{
  // Glöm inte att kontrollera inmatade värden, annars "exception"
  year = yy;
  month = mm;
  day = dd;
}

// Denna medlemsfunktion är tänkt att lägga till 1 dag till befintligt datum.
// Om sista dagen i månaden, så byt månad.
//     Om skottår, så ta hänsyn till att februari(månad 2) har 29 dagar.
// Om sista dagen på året, så byt år.
void Datum::step_one_day()
{
  // Dagen är inte sista dagen i månaden!
  if (!end_of_month(day))
    ++day;
  else if (month < 12)
  {
    ++month;
    day = 1;
  }
  else
  {
    ++year;
    month = 1;
    day = 1;
  }
}

// Returnera true om yy(year) är skottår!
bool Datum::is_skott_aar(int yy)
{
  if (yy % 400 == 0 ||
      (yy % 100 != 0 && yy % 4 == 0))
    return true;
  else
    return false;
}

// Är det sista dagen (dd) i månaden?
bool Datum::end_of_month(int dd) const
{
  if (month == 2 && is_skott_aar(year))
    return dd == 29;
  else
    return dd == ANT_DAGAR_PER_MAANAD[month];
}

// operator<<
std::ostream &operator<<(std::ostream &output, const Datum &d)
{
  static const std::string monthNames[] = {
      "", "January", "February", "March", "April", "May", "June",
      "July", "August", "September", "October", "November", "December"};

  output << d.day << ' ' << monthNames[d.month] << ' ' << d.year;
  return output;
}

bool Datum::operator<(const Datum &other) const
{
    if (this->year < other.year)
    {
        return true;
    }
    else if (this->year == other.year)
    {
        if (this->month < other.month)
        {
            return true;
        }
        else if (this->month == other.month)
        {
            if (this->day < other.day)
            {
                return true;
            }
        }
    }

    return false;
}

bool Datum::operator>(const Datum &other) const
{
    if (this->year > other.year)
    {
        return true;
    }
    else if (this->year == other.year)
    {
        if (this->month > other.month)
        {
            return true;
        }
        else if (this->month == other.month)
        {
            if (this->day > other.day)
            {
                return true;
            }
        }
    }

    return false;
}

bool Datum::operator<=(const Datum &other) const
{
  return this->day <= other.day && this->month <= other.month && this->year <= other.year;
}

bool Datum::operator==(const Datum &other) const
{
  return this->day == other.day && this->month == other.month && this->year == other.year;
}

bool Datum::operator!=(const Datum &other) const
{
  return !(*this == other);
}

Datum Datum::operator+=(int a)
{

  for (int i = 0; i < a; i++)
  {
    step_one_day();
  }

  return *this;
}

Datum Datum::operator+(int days) const
{
  Datum datum = *this;
  datum.day += days;
  return datum;
}

// Prefix increment
Datum &Datum::operator++()
{

  step_one_day();

  return *this;
}

// Postfix increment
Datum Datum::operator++(int days)
{
  // Save the current state
  Datum temp = *this;

  // Use the prefix increment operator
  ++*this;

  return temp;
}

Datum operator+(int days, const Datum &date)
{
  return date + days;
}
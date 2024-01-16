// Downloaded from https://repo.progsbase.com - Code Developed Using progsbase.

#include <cmath>
#include <cstring>
#include <vector>
#include <cwchar>

using namespace std;

#define toVector(s) (new vector<wchar_t> ((s), (s) + wcslen(s)))

struct BooleanArrayReference;

struct BooleanReference;

struct CharacterReference;

struct NumberArrayReference;

struct NumberReference;

struct StringArrayReference;

struct StringReference;

struct Date;

struct DateReference;

struct Interval;

struct DateTimeTimezone;

struct DateTimeTimezoneReference;

struct DateTime;

struct DateTimeReference;

struct BooleanArrayReference{
  vector<bool> *booleanArray;
};

struct BooleanReference{
  bool booleanValue;
};

struct CharacterReference{
  wchar_t characterValue;
};

struct NumberArrayReference{
  vector<double> *numberArray;
};

struct NumberReference{
  double numberValue;
};

struct StringArrayReference{
  vector<StringReference*> *stringArray;
};

struct StringReference{
  vector<wchar_t> *string;
};

struct Date{
  double year;
  double month;
  double day;
};

struct DateReference{
  Date *date;
};

struct Interval{
  Date *first;
  Date *last;
};

struct DateTimeTimezone{
  DateTime *dateTime;
  double timezoneOffsetSeconds;
};

struct DateTimeTimezoneReference{
  DateTimeTimezone *dateTimeTimezone;
};

struct DateTime{
  Date *date;
  double hours;
  double minutes;
  double seconds;
};

struct DateTimeReference{
  DateTime *dateTime;
};

bool IsValidNorwegianPersonalIdentificationNumber(vector<wchar_t> *fnummer, StringReference *message);
bool GetDateFromNorwegianPersonalIdentificationNumber(vector<wchar_t> *fnummer, DateReference *dateRef, StringReference *message);

void Test1(NumberReference *failures);

double test();

BooleanReference *CreateBooleanReference(bool value);
BooleanArrayReference *CreateBooleanArrayReference(vector<bool> *value);
BooleanArrayReference *CreateBooleanArrayReferenceLengthValue(double length, bool value);
void FreeBooleanArrayReference(BooleanArrayReference *booleanArrayReference);
CharacterReference *CreateCharacterReference(wchar_t value);
NumberReference *CreateNumberReference(double value);
NumberArrayReference *CreateNumberArrayReference(vector<double> *value);
NumberArrayReference *CreateNumberArrayReferenceLengthValue(double length, double value);
void FreeNumberArrayReference(NumberArrayReference *numberArrayReference);
StringReference *CreateStringReference(vector<wchar_t> *value);
StringReference *CreateStringReferenceLengthValue(double length, wchar_t value);
void FreeStringReference(StringReference *stringReference);
StringArrayReference *CreateStringArrayReference(vector<StringReference*> *strings);
StringArrayReference *CreateStringArrayReferenceLengthValue(double length, vector<wchar_t> *value);
void FreeStringArrayReference(StringArrayReference *stringArrayReference);

Date *CreateDate(double year, double month, double day);
bool IsLeapYearWithCheck(double year, BooleanReference *isLeapYearReference, StringReference *message);
bool IsLeapYear(double year);
bool DayToDateWithCheck(double dayNr, DateReference *dateReference, StringReference *message);
Date *DayToDate(double dayNr);
bool GetMonthFromDayNrWithCheck(double dayNr, double year, NumberReference *monthReference, NumberReference *remainderReference, StringReference *message);
double GetMonthFromDayNr(double dayNr, double year, NumberReference *remainderReference);
bool GetYearFromDayNrWithCheck(double dayNr, NumberReference *yearReference, NumberReference *remainder, StringReference *message);
double GetYearFromDayNr(double dayNr, NumberReference *remainder);
double DaysBetweenDates(Date *A, Date *B);
bool GetDaysInMonthWithCheck(double year, NumberArrayReference *daysInMonthReference, StringReference *message);
vector<double> *GetDaysInMonth(double year);
bool DateToDaysWithCheck(Date *date, NumberReference *dayNumberReferenceReference, StringReference *message);
double DateToDays(Date *date);
bool DateToWeekdayNumberWithCheck(Date *date, NumberReference *weekDayNumberReference, StringReference *message);
double DateToWeekdayNumber(Date *date);
double DateToWeeknumber(Date *date, NumberReference *yearRef);
bool DaysInMonthsWithCheck(double month, double year, NumberReference *daysInMonthsReference, StringReference *message);
double DaysInMonths(double month, double year);
bool DaysInYearsWithCheck(double years, NumberReference *daysReference, StringReference *message);
double DaysInYears(double years);
bool IsValidDate(Date *date, StringReference *message);
bool AddDaysToDate(Date *date, double days, StringReference *message);
void AssignDate(Date *a, Date *b);
void AddMonthsToDate(Date *date, double months);
bool DateToStringISO8601WithCheck(Date *date, StringReference *datestr, StringReference *message);
vector<wchar_t> *DateToStringISO8601(Date *date);
Date *DateFromStringISO8601(vector<wchar_t> *str);
bool DateFromStringISO8601WithCheck(vector<wchar_t> *str, DateReference *dateRef, StringReference *message);
bool IsValidDateISO8601(vector<wchar_t> *str, StringReference *message);
bool DateEquals(Date *a, Date *b);
Date *CopyDate(Date *a);
double GetSecondsFromDate(Date *date);
bool DateIsInInterval(Interval *interval, Date *date);
bool DateLessThan(Date *a, Date *b);

DateTimeTimezone *CreateDateTimeTimezone(double year, double month, double day, double hours, double minutes, double seconds, double timezoneOffsetSeconds);
DateTimeTimezone *CreateDateTimeTimezoneInHoursAndMinutes(double year, double month, double day, double hours, double minutes, double seconds, double timezoneOffsetHours, double timezoneOffsetMinutes);
bool GetDateFromDateTimeTimeZone(DateTimeTimezone *dateTimeTimezone, DateTimeReference *dateTimeReference, StringReference *message);
bool CreateDateTimeTimezoneFromDateTimeAndTimeZoneInSeconds(DateTime *dateTime, double timezoneOffsetSeconds, DateTimeTimezoneReference *dateTimeTimezoneReference, StringReference *message);
bool CreateDateTimeTimezoneFromDateTimeAndTimeZoneInHoursAndMinutes(DateTime *dateTime, double timezoneOffsetHours, double timezoneOffsetMinutes, DateTimeTimezoneReference *dateTimeTimezoneReference, StringReference *message);
bool GetDateTimeTimezoneFromSeconds(DateTimeTimezoneReference *dateTimeTzRef, double seconds, double offset, StringReference *message);

DateTime *CreateDateTime(double year, double month, double day, double hours, double minutes, double seconds);
bool GetDateTimeFromSeconds(double seconds, DateTimeReference *dateTimeReference, StringReference *message);
double GetSecondsFromDateTime(DateTime *dateTime);
double GetSecondsFromMinutes(double minutes);
double GetSecondsFromHours(double hours);
double GetSecondsFromDays(double days);
double GetSecondsFromWeeks(double weeks);
double GetMinutesFromSeconds(double seconds);
double GetHoursFromSeconds(double seconds);
double GetDaysFromSeconds(double seconds);
double GetWeeksFromSeconds(double seconds);
Date *GetDateFromDateTime(DateTime *dateTime);
bool AddSecondsToDateTimeWithCheck(DateTime *dateTime, double seconds, DateTimeReference *dateTimeReference, StringReference *message);
bool AddSecondsToDateTime(DateTime *dateTime, double seconds, DateTimeReference *dateTimeReference, StringReference *message);
bool AddMinutesToDateTime(DateTime *dateTime, double minutes, DateTimeReference *dateTimeReference, StringReference *message);
bool AddHoursToDateTime(DateTime *dateTime, double hours, DateTimeReference *dateTimeReference, StringReference *message);
bool AddDaysToDateTime(DateTime *dateTime, double days, DateTimeReference *dateTimeReference, StringReference *message);
bool AddWeeksToDateTime(DateTime *dateTime, double weeks, DateTimeReference *dateTimeReference, StringReference *message);
bool DateTimeToStringISO8601WithCheck(DateTime *datetime, StringReference *dateStr, StringReference *message);
bool IsValidDateTime(DateTime *datetime, StringReference *message);
vector<wchar_t> *DateTimeToStringISO8601(DateTime *datetime);
DateTime *DateTimeFromStringISO8601(vector<wchar_t> *str);
bool DateTimeFromStringISO8601WithCheck(vector<wchar_t> *str, DateTimeReference *dateTimeRef, StringReference *message);
bool IsValidDateTimeISO8601(vector<wchar_t> *str, StringReference *message);
bool DateTimeEquals(DateTime *a, DateTime *b);
void FreeDateTime(DateTime *datetime);

wchar_t charToLowerCase(wchar_t character);
wchar_t charToUpperCase(wchar_t character);
bool charIsUpperCase(wchar_t character);
bool charIsLowerCase(wchar_t character);
bool charIsLetter(wchar_t character);
bool charIsNumber(wchar_t character);
bool charIsWhiteSpace(wchar_t character);
bool charIsSymbol(wchar_t character);
bool charCharacterIsBefore(wchar_t a, wchar_t b);
wchar_t charDecimalDigitToCharacter(double digit);
double charCharacterToDecimalDigit(wchar_t c);

void AssertFalse(bool b, NumberReference *failures);
void AssertTrue(bool b, NumberReference *failures);
void AssertEquals(double a, double b, NumberReference *failures);
void AssertBooleansEqual(bool a, bool b, NumberReference *failures);
void AssertCharactersEqual(wchar_t a, wchar_t b, NumberReference *failures);
void AssertStringEquals(vector<wchar_t> *a, vector<wchar_t> *b, NumberReference *failures);
void AssertNumberArraysEqual(vector<double> *a, vector<double> *b, NumberReference *failures);
void AssertBooleanArraysEqual(vector<bool> *a, vector<bool> *b, NumberReference *failures);
void AssertStringArraysEqual(vector<StringReference*> *a, vector<StringReference*> *b, NumberReference *failures);

double Negate(double x);
double Positive(double x);
double Factorial(double x);
double Round(double x);
double BankersRound(double x);
double Ceil(double x);
double Floor(double x);
double Truncate(double x);
double Absolute(double x);
double Logarithm(double x);
double NaturalLogarithm(double x);
double Sin(double x);
double Cos(double x);
double Tan(double x);
double Asin(double x);
double Acos(double x);
double Atan(double x);
double Atan2(double y, double x);
double Squareroot(double x);
double Exp(double x);
bool DivisibleBy(double a, double b);
double Combinations(double n, double k);
double Permutations(double n, double k);
bool EpsilonCompare(double a, double b, double epsilon);
double GreatestCommonDivisor(double a, double b);
double GCDWithSubtraction(double a, double b);
bool IsInteger(double a);
bool GreatestCommonDivisorWithCheck(double a, double b, NumberReference *gcdReference);
double LeastCommonMultiple(double a, double b);
double Sign(double a);
double Max(double a, double b);
double Min(double a, double b);
double Power(double a, double b);
double Gamma(double x);
double LogGamma(double x);
double LanczosApproximation(double z);
double Beta(double x, double y);
double Sinh(double x);
double Cosh(double x);
double Tanh(double x);
double Cot(double x);
double Sec(double x);
double Csc(double x);
double Coth(double x);
double Sech(double x);
double Csch(double x);
double Error(double x);
double ErrorInverse(double x);
double FallingFactorial(double x, double n);
double RisingFactorial(double x, double n);
double Hypergeometric(double a, double b, double c, double z, double maxIterations, double precision);
double HypergeometricDirect(double a, double b, double c, double z, double maxIterations, double precision);
double BernouilliNumber(double n);
double AkiyamaTanigawaAlgorithm(double n);

vector<double> *StringToNumberArray(vector<wchar_t> *string);
vector<wchar_t> *NumberArrayToString(vector<double> *array);
bool NumberArraysEqual(vector<double> *a, vector<double> *b);
bool BooleanArraysEqual(vector<bool> *a, vector<bool> *b);
bool StringsEqual(vector<wchar_t> *a, vector<wchar_t> *b);
void FillNumberArray(vector<double> *a, double value);
void FillString(vector<wchar_t> *a, wchar_t value);
void FillBooleanArray(vector<bool> *a, bool value);
bool FillNumberArrayRange(vector<double> *a, double value, double from, double to);
bool FillBooleanArrayRange(vector<bool> *a, bool value, double from, double to);
bool FillStringRange(vector<wchar_t> *a, wchar_t value, double from, double to);
vector<double> *CopyNumberArray(vector<double> *a);
vector<bool> *CopyBooleanArray(vector<bool> *a);
vector<wchar_t> *CopyString(vector<wchar_t> *a);
bool CopyNumberArrayRange(vector<double> *a, double from, double to, NumberArrayReference *copyReference);
bool CopyBooleanArrayRange(vector<bool> *a, double from, double to, BooleanArrayReference *copyReference);
bool CopyStringRange(vector<wchar_t> *a, double from, double to, StringReference *copyReference);
bool IsLastElement(double length, double index);
vector<double> *CreateNumberArray(double length, double value);
vector<bool> *CreateBooleanArray(double length, bool value);
vector<wchar_t> *CreateString(double length, wchar_t value);
void SwapElementsOfNumberArray(vector<double> *A, double ai, double bi);
void SwapElementsOfStringArray(StringArrayReference *A, double ai, double bi);
void ReverseNumberArray(vector<double> *array);

bool IsValidNorwegianPersonalIdentificationNumber(vector<wchar_t> *fnummer, StringReference *message){
  bool gyldig;
  double i, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
  double k1, k2;
  DateReference *dateRef;

  if(fnummer->size() == 11.0){
    gyldig = true;
    for(i = 0.0; i < fnummer->size(); i = i + 1.0){
      if(charIsNumber(fnummer->at(i))){
      }else{
        gyldig = false;
      }
    }

    if(gyldig){
      d1 = charCharacterToDecimalDigit(fnummer->at(0));
      d2 = charCharacterToDecimalDigit(fnummer->at(1));
      d3 = charCharacterToDecimalDigit(fnummer->at(2));
      d4 = charCharacterToDecimalDigit(fnummer->at(3));
      d5 = charCharacterToDecimalDigit(fnummer->at(4));
      d6 = charCharacterToDecimalDigit(fnummer->at(5));
      d7 = charCharacterToDecimalDigit(fnummer->at(6));
      d8 = charCharacterToDecimalDigit(fnummer->at(7));
      d9 = charCharacterToDecimalDigit(fnummer->at(8));
      d10 = charCharacterToDecimalDigit(fnummer->at(9));
      d11 = charCharacterToDecimalDigit(fnummer->at(10));

      dateRef = new DateReference();
      gyldig = GetDateFromNorwegianPersonalIdentificationNumber(fnummer, dateRef, message);

      if(gyldig){
        if(IsValidDate(dateRef->date, message)){
          k1 = d1*3.0 + d2*7.0 + d3*6.0 + d4*1.0 + d5*8.0 + d6*9.0 + d7*4.0 + d8*5.0 + d9*2.0;
          k1 = fmod(k1, 11.0);
          if(k1 != 0.0){
            k1 = 11.0 - k1;
          }
          if(k1 == 10.0){
            gyldig = false;
            message->string = toVector(L"Control digit 1 is 10, which is invalid.");
          }

          if(gyldig){
            k2 = d1*5.0 + d2*4.0 + d3*3.0 + d4*2.0 + d5*7.0 + d6*6.0 + d7*5.0 + d8*4.0 + d9*3.0 + k1*2.0;
            k2 = fmod(k2, 11.0);
            if(k2 != 0.0){
              k2 = 11.0 - k2;
            }
            if(k2 == 10.0){
              gyldig = false;
              message->string = toVector(L"Control digit 2 is 10, which is invalid.");
            }

            if(gyldig){
              if(k1 == d10){
                if(k2 == d11){
                  gyldig = true;
                }else{
                  gyldig = false;
                  message->string = toVector(L"Check of control digit 2 failed.");
                }
              }else{
                gyldig = false;
                message->string = toVector(L"Check of control digit 1 failed.");
              }
            }
          }
        }else{
          gyldig = false;
          message->string = toVector(L"The date is not a valid date.");
        }
      }
    }else{
      gyldig = false;
      message->string = toVector(L"Each character must be a decimal digit.");
    }
  }else{
    gyldig = false;
    message->string = toVector(L"Must be exactly 11 digits long.");
  }

  return gyldig;
}
bool GetDateFromNorwegianPersonalIdentificationNumber(vector<wchar_t> *fnummer, DateReference *dateRef, StringReference *message){
  double individnummer;
  double day, month, year;
  double i, d1, d2, d3, d4, d5, d6, d7, d8, d9;
  bool success;

  success = true;
  dateRef->date = new Date();

  if(fnummer->size() == 11.0){
    for(i = 0.0; i < fnummer->size(); i = i + 1.0){
      if(charIsNumber(fnummer->at(i))){
      }else{
        success = false;
      }
    }

    if(success){
      d1 = charCharacterToDecimalDigit(fnummer->at(0));
      d2 = charCharacterToDecimalDigit(fnummer->at(1));
      d3 = charCharacterToDecimalDigit(fnummer->at(2));
      d4 = charCharacterToDecimalDigit(fnummer->at(3));
      d5 = charCharacterToDecimalDigit(fnummer->at(4));
      d6 = charCharacterToDecimalDigit(fnummer->at(5));
      d7 = charCharacterToDecimalDigit(fnummer->at(6));
      d8 = charCharacterToDecimalDigit(fnummer->at(7));
      d9 = charCharacterToDecimalDigit(fnummer->at(8));

      /* Individnummer */
      individnummer = d7*100.0 + d8*10.0 + d9;

      /* Make date */
      day = d1*10.0 + d2;
      month = d3*10.0 + d4;
      year = d5*10.0 + d6;

      if(individnummer >= 0.0 && individnummer <= 499.0){
        year = year + 1900.0;
      }else if(individnummer >= 500.0 && individnummer <= 749.0 && year >= 54.0 && year <= 99.0){
        year = year + 1800.0;
      }else if(individnummer >= 900.0 && individnummer <= 999.0 && year >= 40.0 && year <= 99.0){
        year = year + 1900.0;
      }else if(individnummer >= 500.0 && individnummer <= 999.0 && year >= 0.0 && year <= 39.0){
        year = year + 2000.0;
      }else{
        success = false;
        message->string = toVector(L"Invalid combination of individnummer and year.");
      }

      if(success){
        dateRef->date->year = year;
        dateRef->date->month = month;
        dateRef->date->day = day;
      }
    }else{
      message->string = toVector(L"Each character must be a decimal digit.");
    }
  }else{
    message->string = toVector(L"Must be exactly 11 digits long.");
  }

  return success;
}
void Test1(NumberReference *failures){
  StringReference *message;
  DateReference *dateRef;
  bool success;

  message = new StringReference();

  success = IsValidNorwegianPersonalIdentificationNumber(toVector(L"10061270707"), message);
  AssertTrue(success, failures);

  dateRef = new DateReference();

  success = GetDateFromNorwegianPersonalIdentificationNumber(toVector(L"11028559912"), dateRef, message);
  AssertTrue(success, failures);
  AssertEquals(dateRef->date->year, 1885.0, failures);

  success = GetDateFromNorwegianPersonalIdentificationNumber(toVector(L"01019949768"), dateRef, message);
  AssertTrue(success, failures);
  AssertEquals(dateRef->date->year, 1999.0, failures);

  success = GetDateFromNorwegianPersonalIdentificationNumber(toVector(L"01010099931"), dateRef, message);
  AssertTrue(success, failures);
  AssertEquals(dateRef->date->year, 2000.0, failures);
}
double test(){
  NumberReference *failures;

  failures = CreateNumberReference(0.0);

  Test1(failures);

  return failures->numberValue;
}
BooleanReference *CreateBooleanReference(bool value){
  BooleanReference *ref;

  ref = new BooleanReference();
  ref->booleanValue = value;

  return ref;
}
BooleanArrayReference *CreateBooleanArrayReference(vector<bool> *value){
  BooleanArrayReference *ref;

  ref = new BooleanArrayReference();
  ref->booleanArray = value;

  return ref;
}
BooleanArrayReference *CreateBooleanArrayReferenceLengthValue(double length, bool value){
  BooleanArrayReference *ref;
  double i;

  ref = new BooleanArrayReference();
  ref->booleanArray = new vector<bool> (length);

  for(i = 0.0; i < length; i = i + 1.0){
    ref->booleanArray->at(i) = value;
  }

  return ref;
}
void FreeBooleanArrayReference(BooleanArrayReference *booleanArrayReference){
  delete booleanArrayReference->booleanArray;
  delete booleanArrayReference;
}
CharacterReference *CreateCharacterReference(wchar_t value){
  CharacterReference *ref;

  ref = new CharacterReference();
  ref->characterValue = value;

  return ref;
}
NumberReference *CreateNumberReference(double value){
  NumberReference *ref;

  ref = new NumberReference();
  ref->numberValue = value;

  return ref;
}
NumberArrayReference *CreateNumberArrayReference(vector<double> *value){
  NumberArrayReference *ref;

  ref = new NumberArrayReference();
  ref->numberArray = value;

  return ref;
}
NumberArrayReference *CreateNumberArrayReferenceLengthValue(double length, double value){
  NumberArrayReference *ref;
  double i;

  ref = new NumberArrayReference();
  ref->numberArray = new vector<double> (length);

  for(i = 0.0; i < length; i = i + 1.0){
    ref->numberArray->at(i) = value;
  }

  return ref;
}
void FreeNumberArrayReference(NumberArrayReference *numberArrayReference){
  delete numberArrayReference->numberArray;
  delete numberArrayReference;
}
StringReference *CreateStringReference(vector<wchar_t> *value){
  StringReference *ref;

  ref = new StringReference();
  ref->string = value;

  return ref;
}
StringReference *CreateStringReferenceLengthValue(double length, wchar_t value){
  StringReference *ref;
  double i;

  ref = new StringReference();
  ref->string = new vector<wchar_t> (length);

  for(i = 0.0; i < length; i = i + 1.0){
    ref->string->at(i) = value;
  }

  return ref;
}
void FreeStringReference(StringReference *stringReference){
  delete stringReference->string;
  delete stringReference;
}
StringArrayReference *CreateStringArrayReference(vector<StringReference*> *strings){
  StringArrayReference *ref;

  ref = new StringArrayReference();
  ref->stringArray = strings;

  return ref;
}
StringArrayReference *CreateStringArrayReferenceLengthValue(double length, vector<wchar_t> *value){
  StringArrayReference *ref;
  double i;

  ref = new StringArrayReference();
  ref->stringArray = new vector<StringReference*> (length);

  for(i = 0.0; i < length; i = i + 1.0){
    ref->stringArray->at(i) = CreateStringReference(value);
  }

  return ref;
}
void FreeStringArrayReference(StringArrayReference *stringArrayReference){
  double i;

  for(i = 0.0; i < stringArrayReference->stringArray->size(); i = i + 1.0){
    delete stringArrayReference->stringArray->at(i);
  }
  delete stringArrayReference->stringArray;
  delete stringArrayReference;
}
Date *CreateDate(double year, double month, double day){
  Date *date;

  date = new Date();

  date->year = year;
  date->month = month;
  date->day = day;

  return date;
}
bool IsLeapYearWithCheck(double year, BooleanReference *isLeapYearReference, StringReference *message){
  bool itIsLeapYear;
  bool success;

  if(year >= 1752.0){
    success = true;
    itIsLeapYear = IsLeapYear(year);
  }else{
    success = false;
    itIsLeapYear = false;
    message->string = toVector(L"Gregorian calendar was not in general use.");
  }

  isLeapYearReference->booleanValue = itIsLeapYear;
  return success;
}
bool IsLeapYear(double year){
  bool itIsLeapYear;

  if(DivisibleBy(year, 4.0)){
    if(DivisibleBy(year, 100.0)){
      if(DivisibleBy(year, 400.0)){
        itIsLeapYear = true;
      }else{
        itIsLeapYear = false;
      }
    }else{
      itIsLeapYear = true;
    }
  }else{
    itIsLeapYear = false;
  }

  return itIsLeapYear;
}
bool DayToDateWithCheck(double dayNr, DateReference *dateReference, StringReference *message){
  Date *date;
  NumberReference *remainder;
  bool success;

  if(dayNr >=  -79623.0){
    date = new Date();
    remainder = new NumberReference();
    remainder->numberValue = dayNr + 79623.0;
    /* Days since 1752-01-01. Day 0: Thursday, 1970-01-01 */
    /* Find year. */
    date->year = GetYearFromDayNr(remainder->numberValue, remainder);

    /* Find month. */
    date->month = GetMonthFromDayNr(remainder->numberValue, date->year, remainder);

    /* Find day. */
    date->day = 1.0 + remainder->numberValue;

    dateReference->date = date;
    success = true;
  }else{
    success = false;
    message->string = toVector(L"Gregorian calendar was not in general use before 1752.");
  }

  return success;
}
Date *DayToDate(double dayNr){
  Date *date;
  bool success;
  DateReference *dateRef;
  StringReference *message;

  dateRef = new DateReference();
  message = new StringReference();

  success = DayToDateWithCheck(dayNr, dateRef, message);
  if(success){
    date = dateRef->date;
    delete dateRef;
    FreeStringReference(message);
  }else{
    date = CreateDate(1970.0, 1.0, 1.0);
  }

  return date;
}
bool GetMonthFromDayNrWithCheck(double dayNr, double year, NumberReference *monthReference, NumberReference *remainderReference, StringReference *message){
  double month;
  bool success;

  if(dayNr >=  -79623.0){
    month = GetMonthFromDayNr(dayNr, year, remainderReference);
    monthReference->numberValue = month;
    success = true;
  }else{
    success = false;
    message->string = toVector(L"Gregorian calendar not in general use before 1752.");
  }

  return success;
}
double GetMonthFromDayNr(double dayNr, double year, NumberReference *remainderReference){
  vector<double> *daysInMonth;
  bool done;
  double month;

  daysInMonth = GetDaysInMonth(year);
  done = false;
  month = 1.0;

  for(;  !done ; ){
    if(dayNr >= daysInMonth->at(month)){
      dayNr = dayNr - daysInMonth->at(month);
      month = month + 1.0;
    }else{
      done = true;
    }
  }
  remainderReference->numberValue = dayNr;

  return month;
}
bool GetYearFromDayNrWithCheck(double dayNr, NumberReference *yearReference, NumberReference *remainder, StringReference *message){
  bool success;
  double year;

  if(dayNr >= 0.0){
    success = true;
    year = GetYearFromDayNr(dayNr, remainder);
    yearReference->numberValue = year;
  }else{
    success = false;
    message->string = toVector(L"Day number must be 0 or higher. 0 is 1752-01-01.");
  }

  return success;
}
double GetYearFromDayNr(double dayNr, NumberReference *remainder){
  double nrOfDays;
  bool done;
  double year;

  done = false;
  year = 1752.0;

  for(;  !done ; ){
    if(IsLeapYear(year)){
      nrOfDays = 366.0;
    }else{
      nrOfDays = 365.0;
    }

    if(dayNr >= nrOfDays){
      /* First day is 0. */
      dayNr = dayNr - nrOfDays;
      year = year + 1.0;
    }else{
      done = true;
    }
  }
  remainder->numberValue = dayNr;

  return year;
}
double DaysBetweenDates(Date *A, Date *B){
  double daysA, daysB, daysBetween;

  daysA = DateToDays(A);
  daysB = DateToDays(B);

  daysBetween = daysB - daysA;

  return daysBetween;
}
bool GetDaysInMonthWithCheck(double year, NumberArrayReference *daysInMonthReference, StringReference *message){
  vector<double> *daysInMonth;
  bool success;
  Date *date;

  date = CreateDate(year, 1.0, 1.0);

  success = IsValidDate(date, message);
  if(success){
    daysInMonth = GetDaysInMonth(year);

    daysInMonthReference->numberArray = daysInMonth;
  }

  return success;
}
vector<double> *GetDaysInMonth(double year){
  vector<double> *daysInMonth;

  daysInMonth = new vector<double> (1.0 + 12.0);

  daysInMonth->at(0) = 0.0;
  daysInMonth->at(1) = 31.0;

  if(IsLeapYear(year)){
    daysInMonth->at(2) = 29.0;
  }else{
    daysInMonth->at(2) = 28.0;
  }
  daysInMonth->at(3) = 31.0;
  daysInMonth->at(4) = 30.0;
  daysInMonth->at(5) = 31.0;
  daysInMonth->at(6) = 30.0;
  daysInMonth->at(7) = 31.0;
  daysInMonth->at(8) = 31.0;
  daysInMonth->at(9) = 30.0;
  daysInMonth->at(10) = 31.0;
  daysInMonth->at(11) = 30.0;
  daysInMonth->at(12) = 31.0;

  return daysInMonth;
}
bool DateToDaysWithCheck(Date *date, NumberReference *dayNumberReferenceReference, StringReference *message){
  double days;
  bool success;

  success = IsValidDate(date, message);
  if(success){
    days = DateToDays(date);
    dayNumberReferenceReference->numberValue = days;
  }

  return success;
}
double DateToDays(Date *date){
  double days;

  /* Day 1752-01-01 */
  days =  -79623.0;

  days = days + DaysInYears(date->year);
  days = days + DaysInMonths(date->month, date->year);
  days = days + date->day - 1.0;

  return days;
}
bool DateToWeekdayNumberWithCheck(Date *date, NumberReference *weekDayNumberReference, StringReference *message){
  double weekDay;
  bool success;

  success = IsValidDate(date, message);
  if(success){
    weekDay = DateToWeekdayNumber(date);
    weekDayNumberReference->numberValue = weekDay;
  }

  return success;
}
double DateToWeekdayNumber(Date *date){
  double days, weekDay;

  days = DateToDays(date);

  days = days + 79623.0;
  days = days + 5.0;

  weekDay = fmod(days, 7.0) + 1.0;

  return weekDay;
}
double DateToWeeknumber(Date *date, NumberReference *yearRef){
  double weekNumber, weekday, days, daysWeek1Start, weekdayNewYears;
  Date *week1Start, *newyears;

  week1Start = CopyDate(date);

  week1Start->day = 1.0;
  week1Start->month = 1.0;
  weekday = DateToWeekdayNumber(week1Start);

  /* Set week1Start to the start of the Week 1. */
  /* If monday, week 1 begins on Jan. 1st */
  if(weekday == 1.0){
    week1Start->day = 1.0;
  }
  /* If tuesday, week 1 begins on Dec. 31st */
  if(weekday == 2.0){
    week1Start->year = week1Start->year - 1.0;
    week1Start->month = 12.0;
    week1Start->day = 31.0;
  }
  /* If wednesday, week 1 begins on Dec. 30th */
  if(weekday == 3.0){
    week1Start->year = week1Start->year - 1.0;
    week1Start->month = 12.0;
    week1Start->day = 30.0;
  }
  /* If thursday, week 1 begins on Dec. 29th */
  if(weekday == 4.0){
    week1Start->year = week1Start->year - 1.0;
    week1Start->month = 12.0;
    week1Start->day = 29.0;
  }
  /* If friday, week 1 begins on Jan. 4th */
  if(weekday == 5.0){
    week1Start->day = 4.0;
  }
  /* If saturday, week 1 begins on Jan. 3rd */
  if(weekday == 6.0){
    week1Start->day = 3.0;
  }
  /* If sunday, week 1 begins on Jan. 2nd */
  if(weekday == 7.0){
    week1Start->day = 2.0;
  }

  days = DateToDays(date);
  daysWeek1Start = DateToDays(week1Start);

  if(days >= daysWeek1Start){
    weekNumber = 1.0 + floor((days - daysWeek1Start)/7.0);

    if(weekNumber >= 1.0 && weekNumber <= 52.0){
      /* Week is between 1 and 52 in the current year. */
      yearRef->numberValue = date->year;
    }else{
      /* Is week nr 53 or 1 next year? */
      newyears = CopyDate(date);
      newyears->month = 12.0;
      newyears->day = 31.0;
      weekdayNewYears = DateToWeekdayNumber(newyears);
      if(weekdayNewYears == 1.0 || weekdayNewYears == 2.0 || weekdayNewYears == 3.0){
        /* Week 1 next year. */
        weekNumber = 1.0;
        yearRef->numberValue = date->year + 1.0;
      }else{
        /* Week 53 */
        yearRef->numberValue = date->year;
      }
      delete newyears;
    }
  }else{
    /* Week is in previous year. Either 52nd or 53rd. */
    newyears = CopyDate(date);
    newyears->month = 12.0;
    newyears->day = 31.0;
    newyears->year = date->year - 1.0;
    weekNumber = DateToWeeknumber(newyears, yearRef);
    delete newyears;
  }

  delete week1Start;

  return weekNumber;
}
bool DaysInMonthsWithCheck(double month, double year, NumberReference *daysInMonthsReference, StringReference *message){
  double days;
  bool success;
  Date *date;

  date = CreateDate(year, month, 1.0);

  success = IsValidDate(date, message);
  if(success){
    days = DaysInMonths(month, year);

    daysInMonthsReference->numberValue = days;
  }

  return success;
}
double DaysInMonths(double month, double year){
  vector<double> *daysInMonth;
  double days;
  double i;

  daysInMonth = GetDaysInMonth(year);

  days = 0.0;
  for(i = 1.0; i < month; i = i + 1.0){
    days = days + daysInMonth->at(i);
  }

  return days;
}
bool DaysInYearsWithCheck(double years, NumberReference *daysReference, StringReference *message){
  double days;
  bool success;
  Date *date;

  date = CreateDate(years, 1.0, 1.0);

  success = IsValidDate(date, message);
  if(success){
    days = DaysInYears(years);
    daysReference->numberValue = days;
  }

  return success;
}
double DaysInYears(double years){
  double days;
  double i;
  double nrOfDays;

  days = 0.0;
  for(i = 1752.0; i < years; i = i + 1.0){
    if(IsLeapYear(i)){
      nrOfDays = 366.0;
    }else{
      nrOfDays = 365.0;
    }
    days = days + nrOfDays;
  }

  return days;
}
bool IsValidDate(Date *date, StringReference *message){
  bool valid;
  vector<double> *daysInMonth;
  double daysInThisMonth;

  if(date->year >= 1752.0){
    if(date->month >= 1.0 && date->month <= 12.0){
      daysInMonth = GetDaysInMonth(date->year);
      daysInThisMonth = daysInMonth->at(date->month);
      if(date->day >= 1.0 && date->day <= daysInThisMonth){
        valid = true;
      }else{
        valid = false;
        message->string = toVector(L"The month does not have the given day number.");
      }
    }else{
      valid = false;
      message->string = toVector(L"Month must be between 1 and 12, inclusive.");
    }
  }else{
    valid = false;
    message->string = toVector(L"Gregorian calendar was not in general use before 1752.");
  }

  return valid;
}
bool AddDaysToDate(Date *date, double days, StringReference *message){
  double n;
  bool success;
  DateReference *dateReference;
  NumberReference *daysRef;

  daysRef = new NumberReference();
  success = DateToDaysWithCheck(date, daysRef, message);

  if(success){
    n = daysRef->numberValue;
    n = n + days;

    dateReference = new DateReference();
    success = DayToDateWithCheck(n, dateReference, message);
    if(success){
      AssignDate(date, dateReference->date);
    }
  }

  return success;
}
void AssignDate(Date *a, Date *b){
  a->year = b->year;
  a->month = b->month;
  a->day = b->day;
}
void AddMonthsToDate(Date *date, double months){
  double i;

  if(months > 0.0){
    for(i = 0.0; i < months; i = i + 1.0){
      date->month = date->month + 1.0;

      if(date->month == 13.0){
        date->month = 1.0;
        date->year = date->year + 1.0;
      }
    }
  }
  if(months < 0.0){
    for(i = 0.0; i <  -months; i = i + 1.0){
      date->month = date->month - 1.0;

      if(date->month == 0.0){
        date->month = 12.0;
        date->year = date->year - 1.0;
      }
    }
  }
}
bool DateToStringISO8601WithCheck(Date *date, StringReference *datestr, StringReference *message){
  bool success;

  success = IsValidDate(date, message);

  if(success){
    if(date->year <= 9999.0){
      datestr->string = DateToStringISO8601(date);
    }else{
      message->string = toVector(L"This library works from 1752 to 9999.");
    }
  }

  return success;
}
vector<wchar_t> *DateToStringISO8601(Date *date){
  vector<wchar_t> *str;

  str = new vector<wchar_t> (10.0);

  str->at(0) = charDecimalDigitToCharacter(floor(date->year/1000.0));
  str->at(1) = charDecimalDigitToCharacter(floor((fmod(date->year, 1000.0))/100.0));
  str->at(2) = charDecimalDigitToCharacter(floor((fmod(date->year, 100.0))/10.0));
  str->at(3) = charDecimalDigitToCharacter(floor(fmod(date->year, 10.0)));

  str->at(4) = '-';

  str->at(5) = charDecimalDigitToCharacter(floor((fmod(date->month, 100.0))/10.0));
  str->at(6) = charDecimalDigitToCharacter(floor(fmod(date->month, 10.0)));

  str->at(7) = '-';

  str->at(8) = charDecimalDigitToCharacter(floor((fmod(date->day, 100.0))/10.0));
  str->at(9) = charDecimalDigitToCharacter(floor(fmod(date->day, 10.0)));

  return str;
}
Date *DateFromStringISO8601(vector<wchar_t> *str){
  Date *date;
  double n;

  date = new Date();

  n = charCharacterToDecimalDigit(str->at(0))*1000.0;
  n = n + charCharacterToDecimalDigit(str->at(1))*100.0;
  n = n + charCharacterToDecimalDigit(str->at(2))*10.0;
  n = n + charCharacterToDecimalDigit(str->at(3))*1.0;

  date->year = n;

  n = charCharacterToDecimalDigit(str->at(5))*10.0;
  n = n + charCharacterToDecimalDigit(str->at(6))*1.0;

  date->month = n;

  n = charCharacterToDecimalDigit(str->at(8))*10.0;
  n = n + charCharacterToDecimalDigit(str->at(9))*1.0;

  date->day = n;

  return date;
}
bool DateFromStringISO8601WithCheck(vector<wchar_t> *str, DateReference *dateRef, StringReference *message){
  bool valid;

  valid = IsValidDateISO8601(str, message);

  if(valid){
    dateRef->date = DateFromStringISO8601(str);
  }

  return valid;
}
bool IsValidDateISO8601(vector<wchar_t> *str, StringReference *message){
  bool valid;

  if(str->size() == 4.0 + 1.0 + 2.0 + 1.0 + 2.0){

    if(charIsNumber(str->at(0)) && charIsNumber(str->at(1)) && charIsNumber(str->at(2)) && charIsNumber(str->at(3)) && charIsNumber(str->at(5)) && charIsNumber(str->at(6)) && charIsNumber(str->at(8)) && charIsNumber(str->at(9))){
      if(str->at(4) == '-' && str->at(7) == '-'){
        valid = true;
      }else{
        valid = false;
        message->string = toVector(L"ISO8601 date must use \'-\' in positions 5 and 8.");
      }
    }else{
      valid = false;
      message->string = toVector(L"ISO8601 date must use decimal digits in positions 1, 2, 3, 4, 6, 7, 9 and 10.");
    }
  }else{
    valid = false;
    message->string = toVector(L"ISO8601 date must be exactly 10 characters long.");
  }

  return valid;
}
bool DateEquals(Date *a, Date *b){
  return a->year == b->year && a->month == b->month && a->day == b->day;
}
Date *CopyDate(Date *a){
  Date *b;

  b = CreateDate(a->year, a->month, a->day);

  return b;
}
double GetSecondsFromDate(Date *date){
  double seconds, days, secondsInMinute, secondsInHour, secondsInDay;
  NumberReference *dayNumberReferenceReference;
  StringReference *message;
  bool success;

  seconds = 0.0;
  dayNumberReferenceReference = new NumberReference();
  message = new StringReference();

  success = DateToDaysWithCheck(date, dayNumberReferenceReference, message);
  if(success){
    days = dayNumberReferenceReference->numberValue;

    secondsInMinute = 60.0;
    secondsInHour = 60.0*secondsInMinute;
    secondsInDay = 24.0*secondsInHour;

    seconds = seconds + secondsInDay*days;
  }

  delete dayNumberReferenceReference;
  delete message;

  return seconds;
}
bool DateIsInInterval(Interval *interval, Date *date){
  double from, to, day;

  from = DateToDays(interval->first);
  to = DateToDays(interval->last);
  day = DateToDays(date);

  return day >= from && day <= to;
}
bool DateLessThan(Date *a, Date *b){
  double aDays, bDays;

  aDays = DateToDays(a);
  bDays = DateToDays(b);

  return aDays < bDays;
}
DateTimeTimezone *CreateDateTimeTimezone(double year, double month, double day, double hours, double minutes, double seconds, double timezoneOffsetSeconds){
  DateTimeTimezone *dateTimeTimezone;

  dateTimeTimezone = new DateTimeTimezone();

  dateTimeTimezone->dateTime = CreateDateTime(year, month, day, hours, minutes, seconds);
  dateTimeTimezone->timezoneOffsetSeconds = timezoneOffsetSeconds;

  return dateTimeTimezone;
}
DateTimeTimezone *CreateDateTimeTimezoneInHoursAndMinutes(double year, double month, double day, double hours, double minutes, double seconds, double timezoneOffsetHours, double timezoneOffsetMinutes){
  DateTimeTimezone *dateTimeTimezone;

  dateTimeTimezone = new DateTimeTimezone();

  dateTimeTimezone->dateTime = CreateDateTime(year, month, day, hours, minutes, seconds);
  dateTimeTimezone->timezoneOffsetSeconds = GetSecondsFromHours(timezoneOffsetHours) + GetSecondsFromMinutes(timezoneOffsetMinutes);

  return dateTimeTimezone;
}
bool GetDateFromDateTimeTimeZone(DateTimeTimezone *dateTimeTimezone, DateTimeReference *dateTimeReference, StringReference *message){
  DateTime *dateTime;

  dateTime = dateTimeTimezone->dateTime;

  return AddSecondsToDateTimeWithCheck(dateTime,  -dateTimeTimezone->timezoneOffsetSeconds, dateTimeReference, message);
}
bool CreateDateTimeTimezoneFromDateTimeAndTimeZoneInSeconds(DateTime *dateTime, double timezoneOffsetSeconds, DateTimeTimezoneReference *dateTimeTimezoneReference, StringReference *message){
  bool success;
  DateTimeReference *adjustedDateTimeReference;
  DateTimeTimezone *dateTimeTimezone;

  adjustedDateTimeReference = new DateTimeReference();
  dateTimeTimezone = new DateTimeTimezone();

  success = AddSecondsToDateTime(dateTime, timezoneOffsetSeconds, adjustedDateTimeReference, message);

  if(success){
    dateTimeTimezone->dateTime = adjustedDateTimeReference->dateTime;
    dateTimeTimezone->timezoneOffsetSeconds = timezoneOffsetSeconds;

    dateTimeTimezoneReference->dateTimeTimezone = dateTimeTimezone;
  }

  return success;
}
bool CreateDateTimeTimezoneFromDateTimeAndTimeZoneInHoursAndMinutes(DateTime *dateTime, double timezoneOffsetHours, double timezoneOffsetMinutes, DateTimeTimezoneReference *dateTimeTimezoneReference, StringReference *message){
  return CreateDateTimeTimezoneFromDateTimeAndTimeZoneInSeconds(dateTime, GetSecondsFromHours(timezoneOffsetHours) + GetSecondsFromMinutes(timezoneOffsetMinutes), dateTimeTimezoneReference, message);
}
bool GetDateTimeTimezoneFromSeconds(DateTimeTimezoneReference *dateTimeTzRef, double seconds, double offset, StringReference *message){
  bool success;
  DateTimeReference *dateTimeRef;

  dateTimeRef = new DateTimeReference();
  success = GetDateTimeFromSeconds(seconds, dateTimeRef, message);

  if(success){
    success = CreateDateTimeTimezoneFromDateTimeAndTimeZoneInSeconds(dateTimeRef->dateTime, offset, dateTimeTzRef, message);
  }

  return success;
}
DateTime *CreateDateTime(double year, double month, double day, double hours, double minutes, double seconds){
  DateTime *dateTime;

  dateTime = new DateTime();

  dateTime->date = CreateDate(year, month, day);
  dateTime->hours = hours;
  dateTime->minutes = minutes;
  dateTime->seconds = seconds;

  return dateTime;
}
bool GetDateTimeFromSeconds(double seconds, DateTimeReference *dateTimeReference, StringReference *message){
  DateTime *dateTime;
  double secondsInMinute, secondsInHour, secondsInDay, days, remainder;
  Date *date;
  DateReference *dateReference;
  bool success;

  secondsInMinute = 60.0;
  secondsInHour = 60.0*secondsInMinute;
  secondsInDay = 24.0*secondsInHour;
  days = floor(seconds/secondsInDay);
  remainder = seconds - days*secondsInDay;
  dateReference = new DateReference();

  success = DayToDateWithCheck(days, dateReference, message);
  if(success){
    date = dateReference->date;

    dateTime = new DateTime();
    dateTime->date = date;
    dateTime->hours = floor(remainder/secondsInHour);
    remainder = remainder - dateTime->hours*secondsInHour;
    dateTime->minutes = floor(remainder/secondsInMinute);
    remainder = remainder - dateTime->minutes*secondsInMinute;
    dateTime->seconds = remainder;

    dateTimeReference->dateTime = dateTime;
  }

  return success;
}
double GetSecondsFromDateTime(DateTime *dateTime){
  double seconds, secondsInMinute, secondsInHour;

  secondsInMinute = 60.0;
  secondsInHour = 60.0*secondsInMinute;

  seconds = GetSecondsFromDate(dateTime->date);
  seconds = seconds + secondsInHour*dateTime->hours;
  seconds = seconds + secondsInMinute*dateTime->minutes;
  seconds = seconds + dateTime->seconds;

  return seconds;
}
double GetSecondsFromMinutes(double minutes){
  return minutes*60.0;
}
double GetSecondsFromHours(double hours){
  return GetSecondsFromMinutes(hours*60.0);
}
double GetSecondsFromDays(double days){
  return GetSecondsFromHours(days*24.0);
}
double GetSecondsFromWeeks(double weeks){
  return GetSecondsFromDays(weeks*7.0);
}
double GetMinutesFromSeconds(double seconds){
  return seconds/60.0;
}
double GetHoursFromSeconds(double seconds){
  return GetMinutesFromSeconds(seconds)/60.0;
}
double GetDaysFromSeconds(double seconds){
  return GetHoursFromSeconds(seconds)/24.0;
}
double GetWeeksFromSeconds(double seconds){
  return GetDaysFromSeconds(seconds)/7.0;
}
Date *GetDateFromDateTime(DateTime *dateTime){
  return dateTime->date;
}
bool AddSecondsToDateTimeWithCheck(DateTime *dateTime, double seconds, DateTimeReference *dateTimeReference, StringReference *message){
  double secondsInDateTime;
  bool success;

  if(IsValidDateTime(dateTime, message)){
    secondsInDateTime = GetSecondsFromDateTime(dateTime);
    secondsInDateTime = secondsInDateTime + seconds;

    success = GetDateTimeFromSeconds(secondsInDateTime, dateTimeReference, message);
  }else{
    success = false;
  }

  return success;
}
bool AddSecondsToDateTime(DateTime *dateTime, double seconds, DateTimeReference *dateTimeReference, StringReference *message){
  double secondsInDateTime;

  secondsInDateTime = GetSecondsFromDateTime(dateTime);
  secondsInDateTime = secondsInDateTime + seconds;

  return GetDateTimeFromSeconds(secondsInDateTime, dateTimeReference, message);
}
bool AddMinutesToDateTime(DateTime *dateTime, double minutes, DateTimeReference *dateTimeReference, StringReference *message){
  return AddSecondsToDateTime(dateTime, GetSecondsFromMinutes(minutes), dateTimeReference, message);
}
bool AddHoursToDateTime(DateTime *dateTime, double hours, DateTimeReference *dateTimeReference, StringReference *message){
  return AddSecondsToDateTime(dateTime, GetSecondsFromHours(hours), dateTimeReference, message);
}
bool AddDaysToDateTime(DateTime *dateTime, double days, DateTimeReference *dateTimeReference, StringReference *message){
  return AddSecondsToDateTime(dateTime, GetSecondsFromDays(days), dateTimeReference, message);
}
bool AddWeeksToDateTime(DateTime *dateTime, double weeks, DateTimeReference *dateTimeReference, StringReference *message){
  return AddSecondsToDateTime(dateTime, GetSecondsFromWeeks(weeks), dateTimeReference, message);
}
bool DateTimeToStringISO8601WithCheck(DateTime *datetime, StringReference *dateStr, StringReference *message){
  bool success;

  success = DateToStringISO8601WithCheck(datetime->date, dateStr, message);

  if(success){
    delete dateStr->string;

    success = IsValidDateTime(datetime, message);
    if(success){
      dateStr->string = DateTimeToStringISO8601(datetime);
    }
  }

  return success;
}
bool IsValidDateTime(DateTime *datetime, StringReference *message){
  bool success;

  success = IsValidDate(datetime->date, message);

  if(success){
    if(datetime->hours <= 23.0 && datetime->hours >= 0.0){
      if(datetime->minutes <= 59.0 && datetime->minutes >= 0.0){
        if(datetime->seconds <= 59.0 && datetime->seconds >= 0.0){
          success = true;
        }else{
          success = false;
          message->string = toVector(L"Seconds must be between 0 and 59.");
        }
      }else{
        success = false;
        message->string = toVector(L"Minutes must be between 0 and 59.");
      }
    }else{
      success = false;
      message->string = toVector(L"Hours must be between 0 and 23.");
    }
  }

  return success;
}
vector<wchar_t> *DateTimeToStringISO8601(DateTime *datetime){
  vector<wchar_t> *datestr, *str;
  double i;

  str = new vector<wchar_t> (19.0);

  datestr = DateToStringISO8601(datetime->date);
  for(i = 0.0; i < datestr->size(); i = i + 1.0){
    str->at(i) = datestr->at(i);
  }

  str->at(10) = 'T';
  str->at(11) = charDecimalDigitToCharacter(floor((fmod(datetime->hours, 100.0))/10.0));
  str->at(12) = charDecimalDigitToCharacter(floor(fmod(datetime->hours, 10.0)));

  str->at(13) = ':';

  str->at(14) = charDecimalDigitToCharacter(floor((fmod(datetime->minutes, 100.0))/10.0));
  str->at(15) = charDecimalDigitToCharacter(floor(fmod(datetime->minutes, 10.0)));

  str->at(16) = ':';

  str->at(17) = charDecimalDigitToCharacter(floor((fmod(datetime->seconds, 100.0))/10.0));
  str->at(18) = charDecimalDigitToCharacter(floor(fmod(datetime->seconds, 10.0)));

  return str;
}
DateTime *DateTimeFromStringISO8601(vector<wchar_t> *str){
  DateTime *dateTime;
  double n;

  dateTime = new DateTime();

  dateTime->date = DateFromStringISO8601(str);

  n = charCharacterToDecimalDigit(str->at(11))*10.0;
  n = n + charCharacterToDecimalDigit(str->at(12))*1.0;

  dateTime->hours = n;

  n = charCharacterToDecimalDigit(str->at(14))*10.0;
  n = n + charCharacterToDecimalDigit(str->at(15))*1.0;

  dateTime->minutes = n;

  n = charCharacterToDecimalDigit(str->at(17))*10.0;
  n = n + charCharacterToDecimalDigit(str->at(18))*1.0;

  dateTime->seconds = n;

  return dateTime;
}
bool DateTimeFromStringISO8601WithCheck(vector<wchar_t> *str, DateTimeReference *dateTimeRef, StringReference *message){
  bool valid;

  valid = IsValidDateTimeISO8601(str, message);

  if(valid){
    dateTimeRef->dateTime = DateTimeFromStringISO8601(str);
  }

  return valid;
}
bool IsValidDateTimeISO8601(vector<wchar_t> *str, StringReference *message){
  bool valid;

  if(str->size() == 4.0 + 1.0 + 2.0 + 1.0 + 2.0 + 1.0 + 2.0 + 1.0 + 2.0 + 1.0 + 2.0){

    if(charIsNumber(str->at(0)) && charIsNumber(str->at(1)) && charIsNumber(str->at(2)) && charIsNumber(str->at(3)) && charIsNumber(str->at(5)) && charIsNumber(str->at(6)) && charIsNumber(str->at(8)) && charIsNumber(str->at(9)) && charIsNumber(str->at(11)) && charIsNumber(str->at(12)) && charIsNumber(str->at(14)) && charIsNumber(str->at(15)) && charIsNumber(str->at(17)) && charIsNumber(str->at(18))){
      if(str->at(4) == '-' && str->at(7) == '-' && str->at(10) == 'T' && str->at(13) == ':' && str->at(16) == ':'){
        valid = true;
      }else{
        valid = false;
        message->string = toVector(L"ISO8601 date must use \'-\' in positions 5 and 8, \'T\' in position 11 and \':\' in positions 14 and 17.");
      }
    }else{
      valid = false;
      message->string = toVector(L"ISO8601 date must use decimal digits in positions 1, 2, 3, 4, 6, 7, 9, 10, 12, 13, 15, 16, 18 and 19.");
    }
  }else{
    valid = false;
    message->string = toVector(L"ISO8601 date must be exactly 19 characters long.");
  }

  return valid;
}
bool DateTimeEquals(DateTime *a, DateTime *b){
  return DateEquals(a->date, b->date) && a->hours == b->hours && a->minutes == b->minutes && a->seconds == b->seconds;
}
void FreeDateTime(DateTime *datetime){
  delete datetime->date;
  delete datetime;
}
wchar_t charToLowerCase(wchar_t character){
  wchar_t toReturn;

  toReturn = character;
  if(character == 'A'){
    toReturn = 'a';
  }else if(character == 'B'){
    toReturn = 'b';
  }else if(character == 'C'){
    toReturn = 'c';
  }else if(character == 'D'){
    toReturn = 'd';
  }else if(character == 'E'){
    toReturn = 'e';
  }else if(character == 'F'){
    toReturn = 'f';
  }else if(character == 'G'){
    toReturn = 'g';
  }else if(character == 'H'){
    toReturn = 'h';
  }else if(character == 'I'){
    toReturn = 'i';
  }else if(character == 'J'){
    toReturn = 'j';
  }else if(character == 'K'){
    toReturn = 'k';
  }else if(character == 'L'){
    toReturn = 'l';
  }else if(character == 'M'){
    toReturn = 'm';
  }else if(character == 'N'){
    toReturn = 'n';
  }else if(character == 'O'){
    toReturn = 'o';
  }else if(character == 'P'){
    toReturn = 'p';
  }else if(character == 'Q'){
    toReturn = 'q';
  }else if(character == 'R'){
    toReturn = 'r';
  }else if(character == 'S'){
    toReturn = 's';
  }else if(character == 'T'){
    toReturn = 't';
  }else if(character == 'U'){
    toReturn = 'u';
  }else if(character == 'V'){
    toReturn = 'v';
  }else if(character == 'W'){
    toReturn = 'w';
  }else if(character == 'X'){
    toReturn = 'x';
  }else if(character == 'Y'){
    toReturn = 'y';
  }else if(character == 'Z'){
    toReturn = 'z';
  }

  return toReturn;
}
wchar_t charToUpperCase(wchar_t character){
  wchar_t toReturn;

  toReturn = character;
  if(character == 'a'){
    toReturn = 'A';
  }else if(character == 'b'){
    toReturn = 'B';
  }else if(character == 'c'){
    toReturn = 'C';
  }else if(character == 'd'){
    toReturn = 'D';
  }else if(character == 'e'){
    toReturn = 'E';
  }else if(character == 'f'){
    toReturn = 'F';
  }else if(character == 'g'){
    toReturn = 'G';
  }else if(character == 'h'){
    toReturn = 'H';
  }else if(character == 'i'){
    toReturn = 'I';
  }else if(character == 'j'){
    toReturn = 'J';
  }else if(character == 'k'){
    toReturn = 'K';
  }else if(character == 'l'){
    toReturn = 'L';
  }else if(character == 'm'){
    toReturn = 'M';
  }else if(character == 'n'){
    toReturn = 'N';
  }else if(character == 'o'){
    toReturn = 'O';
  }else if(character == 'p'){
    toReturn = 'P';
  }else if(character == 'q'){
    toReturn = 'Q';
  }else if(character == 'r'){
    toReturn = 'R';
  }else if(character == 's'){
    toReturn = 'S';
  }else if(character == 't'){
    toReturn = 'T';
  }else if(character == 'u'){
    toReturn = 'U';
  }else if(character == 'v'){
    toReturn = 'V';
  }else if(character == 'w'){
    toReturn = 'W';
  }else if(character == 'x'){
    toReturn = 'X';
  }else if(character == 'y'){
    toReturn = 'Y';
  }else if(character == 'z'){
    toReturn = 'Z';
  }

  return toReturn;
}
bool charIsUpperCase(wchar_t character){
  bool isUpper;

  isUpper = true;
  if(character == 'A'){
  }else if(character == 'B'){
  }else if(character == 'C'){
  }else if(character == 'D'){
  }else if(character == 'E'){
  }else if(character == 'F'){
  }else if(character == 'G'){
  }else if(character == 'H'){
  }else if(character == 'I'){
  }else if(character == 'J'){
  }else if(character == 'K'){
  }else if(character == 'L'){
  }else if(character == 'M'){
  }else if(character == 'N'){
  }else if(character == 'O'){
  }else if(character == 'P'){
  }else if(character == 'Q'){
  }else if(character == 'R'){
  }else if(character == 'S'){
  }else if(character == 'T'){
  }else if(character == 'U'){
  }else if(character == 'V'){
  }else if(character == 'W'){
  }else if(character == 'X'){
  }else if(character == 'Y'){
  }else if(character == 'Z'){
  }else{
    isUpper = false;
  }

  return isUpper;
}
bool charIsLowerCase(wchar_t character){
  bool isLower;

  isLower = true;
  if(character == 'a'){
  }else if(character == 'b'){
  }else if(character == 'c'){
  }else if(character == 'd'){
  }else if(character == 'e'){
  }else if(character == 'f'){
  }else if(character == 'g'){
  }else if(character == 'h'){
  }else if(character == 'i'){
  }else if(character == 'j'){
  }else if(character == 'k'){
  }else if(character == 'l'){
  }else if(character == 'm'){
  }else if(character == 'n'){
  }else if(character == 'o'){
  }else if(character == 'p'){
  }else if(character == 'q'){
  }else if(character == 'r'){
  }else if(character == 's'){
  }else if(character == 't'){
  }else if(character == 'u'){
  }else if(character == 'v'){
  }else if(character == 'w'){
  }else if(character == 'x'){
  }else if(character == 'y'){
  }else if(character == 'z'){
  }else{
    isLower = false;
  }

  return isLower;
}
bool charIsLetter(wchar_t character){
  return charIsUpperCase(character) || charIsLowerCase(character);
}
bool charIsNumber(wchar_t character){
  bool isNumberx;

  isNumberx = true;
  if(character == '0'){
  }else if(character == '1'){
  }else if(character == '2'){
  }else if(character == '3'){
  }else if(character == '4'){
  }else if(character == '5'){
  }else if(character == '6'){
  }else if(character == '7'){
  }else if(character == '8'){
  }else if(character == '9'){
  }else{
    isNumberx = false;
  }

  return isNumberx;
}
bool charIsWhiteSpace(wchar_t character){
  bool isWhiteSpacex;

  isWhiteSpacex = true;
  if(character == ' '){
  }else if(character == '\t'){
  }else if(character == '\n'){
  }else if(character == '\r'){
  }else{
    isWhiteSpacex = false;
  }

  return isWhiteSpacex;
}
bool charIsSymbol(wchar_t character){
  bool isSymbolx;

  isSymbolx = true;
  if(character == '!'){
  }else if(character == '\"'){
  }else if(character == '#'){
  }else if(character == '$'){
  }else if(character == '%'){
  }else if(character == '&'){
  }else if(character == '\''){
  }else if(character == '('){
  }else if(character == ')'){
  }else if(character == '*'){
  }else if(character == '+'){
  }else if(character == ','){
  }else if(character == '-'){
  }else if(character == '.'){
  }else if(character == '/'){
  }else if(character == ':'){
  }else if(character == ';'){
  }else if(character == '<'){
  }else if(character == '='){
  }else if(character == '>'){
  }else if(character == '?'){
  }else if(character == '@'){
  }else if(character == '['){
  }else if(character == '\\'){
  }else if(character == ']'){
  }else if(character == '^'){
  }else if(character == '_'){
  }else if(character == '`'){
  }else if(character == '{'){
  }else if(character == '|'){
  }else if(character == '}'){
  }else if(character == '~'){
  }else{
    isSymbolx = false;
  }

  return isSymbolx;
}
bool charCharacterIsBefore(wchar_t a, wchar_t b){
  double ad, bd;

  ad = a;
  bd = b;

  return ad < bd;
}
wchar_t charDecimalDigitToCharacter(double digit){
  wchar_t c;
  if(digit == 1.0){
    c = '1';
  }else if(digit == 2.0){
    c = '2';
  }else if(digit == 3.0){
    c = '3';
  }else if(digit == 4.0){
    c = '4';
  }else if(digit == 5.0){
    c = '5';
  }else if(digit == 6.0){
    c = '6';
  }else if(digit == 7.0){
    c = '7';
  }else if(digit == 8.0){
    c = '8';
  }else if(digit == 9.0){
    c = '9';
  }else{
    c = '0';
  }
  return c;
}
double charCharacterToDecimalDigit(wchar_t c){
  double digit;

  if(c == '1'){
    digit = 1.0;
  }else if(c == '2'){
    digit = 2.0;
  }else if(c == '3'){
    digit = 3.0;
  }else if(c == '4'){
    digit = 4.0;
  }else if(c == '5'){
    digit = 5.0;
  }else if(c == '6'){
    digit = 6.0;
  }else if(c == '7'){
    digit = 7.0;
  }else if(c == '8'){
    digit = 8.0;
  }else if(c == '9'){
    digit = 9.0;
  }else{
    digit = 0.0;
  }

  return digit;
}
void AssertFalse(bool b, NumberReference *failures){
  if(b){
    failures->numberValue = failures->numberValue + 1.0;
  }
}
void AssertTrue(bool b, NumberReference *failures){
  if( !b ){
    failures->numberValue = failures->numberValue + 1.0;
  }
}
void AssertEquals(double a, double b, NumberReference *failures){
  if(a != b){
    failures->numberValue = failures->numberValue + 1.0;
  }
}
void AssertBooleansEqual(bool a, bool b, NumberReference *failures){
  if(a != b){
    failures->numberValue = failures->numberValue + 1.0;
  }
}
void AssertCharactersEqual(wchar_t a, wchar_t b, NumberReference *failures){
  if(a != b){
    failures->numberValue = failures->numberValue + 1.0;
  }
}
void AssertStringEquals(vector<wchar_t> *a, vector<wchar_t> *b, NumberReference *failures){
  if( !StringsEqual(a, b) ){
    failures->numberValue = failures->numberValue + 1.0;
  }
}
void AssertNumberArraysEqual(vector<double> *a, vector<double> *b, NumberReference *failures){
  double i;

  if(a->size() == b->size()){
    for(i = 0.0; i < a->size(); i = i + 1.0){
      AssertEquals(a->at(i), b->at(i), failures);
    }
  }else{
    failures->numberValue = failures->numberValue + 1.0;
  }
}
void AssertBooleanArraysEqual(vector<bool> *a, vector<bool> *b, NumberReference *failures){
  double i;

  if(a->size() == b->size()){
    for(i = 0.0; i < a->size(); i = i + 1.0){
      AssertBooleansEqual(a->at(i), b->at(i), failures);
    }
  }else{
    failures->numberValue = failures->numberValue + 1.0;
  }
}
void AssertStringArraysEqual(vector<StringReference*> *a, vector<StringReference*> *b, NumberReference *failures){
  double i;

  if(a->size() == b->size()){
    for(i = 0.0; i < a->size(); i = i + 1.0){
      AssertStringEquals(a->at(i)->string, b->at(i)->string, failures);
    }
  }else{
    failures->numberValue = failures->numberValue + 1.0;
  }
}
double Negate(double x){
  return  -x;
}
double Positive(double x){
  return  +x;
}
double Factorial(double x){
  double i, f;

  f = 1.0;

  for(i = 2.0; i <= x; i = i + 1.0){
    f = f*i;
  }

  return f;
}
double Round(double x){
  return floor(x + 0.5);
}
double BankersRound(double x){
  double r;

  if(Absolute(x - Truncate(x)) == 0.5){
    if( !DivisibleBy(Round(x), 2.0) ){
      r = Round(x) - 1.0;
    }else{
      r = Round(x);
    }
  }else{
    r = Round(x);
  }

  return r;
}
double Ceil(double x){
  return ceil(x);
}
double Floor(double x){
  return floor(x);
}
double Truncate(double x){
  double t;

  if(x >= 0.0){
    t = floor(x);
  }else{
    t = ceil(x);
  }

  return t;
}
double Absolute(double x){
  return abs(x);
}
double Logarithm(double x){
  return log10(x);
}
double NaturalLogarithm(double x){
  return log(x);
}
double Sin(double x){
  return sin(x);
}
double Cos(double x){
  return cos(x);
}
double Tan(double x){
  return tan(x);
}
double Asin(double x){
  return asin(x);
}
double Acos(double x){
  return acos(x);
}
double Atan(double x){
  return atan(x);
}
double Atan2(double y, double x){
  double a;

  /* Atan2 is an invalid operation when x = 0 and y = 0, but this method does not return errors. */
  a = 0.0;

  if(x > 0.0){
    a = Atan(y/x);
  }else if(x < 0.0 && y >= 0.0){
    a = Atan(y/x) + M_PI;
  }else if(x < 0.0 && y < 0.0){
    a = Atan(y/x) - M_PI;
  }else if(x == 0.0 && y > 0.0){
    a = M_PI/2.0;
  }else if(x == 0.0 && y < 0.0){
    a =  -M_PI/2.0;
  }

  return a;
}
double Squareroot(double x){
  return sqrt(x);
}
double Exp(double x){
  return exp(x);
}
bool DivisibleBy(double a, double b){
  return ((fmod(a, b)) == 0.0);
}
double Combinations(double n, double k){
  double i, j, c;

  c = 1.0;
  j = 1.0;
  i = n - k + 1.0;

  for(; i <= n; ){
    c = c*i;
    c = c/j;

    i = i + 1.0;
    j = j + 1.0;
  }

  return c;
}
double Permutations(double n, double k){
  double i, c;

  c = 1.0;

  for(i = n - k + 1.0; i <= n; i = i + 1.0){
    c = c*i;
  }

  return c;
}
bool EpsilonCompare(double a, double b, double epsilon){
  return abs(a - b) < epsilon;
}
double GreatestCommonDivisor(double a, double b){
  double t;

  for(; b != 0.0; ){
    t = b;
    b = fmod(a, b);
    a = t;
  }

  return a;
}
double GCDWithSubtraction(double a, double b){
  double g;

  if(a == 0.0){
    g = b;
  }else{
    for(; b != 0.0; ){
      if(a > b){
        a = a - b;
      }else{
        b = b - a;
      }
    }

    g = a;
  }

  return g;
}
bool IsInteger(double a){
  return (a - floor(a)) == 0.0;
}
bool GreatestCommonDivisorWithCheck(double a, double b, NumberReference *gcdReference){
  bool success;
  double gcd;

  if(IsInteger(a) && IsInteger(b)){
    gcd = GreatestCommonDivisor(a, b);
    gcdReference->numberValue = gcd;
    success = true;
  }else{
    success = false;
  }

  return success;
}
double LeastCommonMultiple(double a, double b){
  double lcm;

  if(a > 0.0 && b > 0.0){
    lcm = abs(a*b)/GreatestCommonDivisor(a, b);
  }else{
    lcm = 0.0;
  }

  return lcm;
}
double Sign(double a){
  double s;

  if(a > 0.0){
    s = 1.0;
  }else if(a < 0.0){
    s =  -1.0;
  }else{
    s = 0.0;
  }

  return s;
}
double Max(double a, double b){
  return fmax(a, b);
}
double Min(double a, double b){
  return fmin(a, b);
}
double Power(double a, double b){
  return pow(a, b);
}
double Gamma(double x){
  return LanczosApproximation(x);
}
double LogGamma(double x){
  return log(Gamma(x));
}
double LanczosApproximation(double z){
  vector<double> *p;
  double i, y, t, x;

  p = new vector<double> (8.0);
  p->at(0) = 676.5203681218851;
  p->at(1) =  -1259.1392167224028;
  p->at(2) = 771.32342877765313;
  p->at(3) =  -176.61502916214059;
  p->at(4) = 12.507343278686905;
  p->at(5) =  -0.13857109526572012;
  p->at(6) = 9.9843695780195716e-6;
  p->at(7) = 1.5056327351493116e-7;

  if(z < 0.5){
    y = M_PI/(sin(M_PI*z)*LanczosApproximation(1.0 - z));
  }else{
    z = z - 1.0;
    x = 0.99999999999980993;
    for(i = 0.0; i < p->size(); i = i + 1.0){
      x = x + p->at(i)/(z + i + 1.0);
    }
    t = z + p->size() - 0.5;
    y = sqrt(2.0*M_PI)*pow(t, z + 0.5)*exp( -t)*x;
  }

  return y;
}
double Beta(double x, double y){
  return Gamma(x)*Gamma(y)/Gamma(x + y);
}
double Sinh(double x){
  return (exp(x) - exp( -x))/2.0;
}
double Cosh(double x){
  return (exp(x) + exp( -x))/2.0;
}
double Tanh(double x){
  return Sinh(x)/Cosh(x);
}
double Cot(double x){
  return 1.0/tan(x);
}
double Sec(double x){
  return 1.0/cos(x);
}
double Csc(double x){
  return 1.0/sin(x);
}
double Coth(double x){
  return Cosh(x)/Sinh(x);
}
double Sech(double x){
  return 1.0/Cosh(x);
}
double Csch(double x){
  return 1.0/Sinh(x);
}
double Error(double x){
  double y, t, tau, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;

  if(x == 0.0){
    y = 0.0;
  }else if(x < 0.0){
    y =  -Error( -x);
  }else{
    c1 =  -1.26551223;
    c2 =  +1.00002368;
    c3 =  +0.37409196;
    c4 =  +0.09678418;
    c5 =  -0.18628806;
    c6 =  +0.27886807;
    c7 =  -1.13520398;
    c8 =  +1.48851587;
    c9 =  -0.82215223;
    c10 =  +0.17087277;

    t = 1.0/(1.0 + 0.5*abs(x));

    tau = t*exp( -pow(x, 2.0) + c1 + t*(c2 + t*(c3 + t*(c4 + t*(c5 + t*(c6 + t*(c7 + t*(c8 + t*(c9 + t*c10)))))))));

    y = 1.0 - tau;
  }

  return y;
}
double ErrorInverse(double x){
  double y, a, t;

  a = (8.0*(M_PI - 3.0))/(3.0*M_PI*(4.0 - M_PI));

  t = 2.0/(M_PI*a) + log(1.0 - pow(x, 2.0))/2.0;
  y = Sign(x)*sqrt(sqrt(pow(t, 2.0) - log(1.0 - pow(x, 2.0))/a) - t);

  return y;
}
double FallingFactorial(double x, double n){
  double k, y;

  y = 1.0;

  for(k = 0.0; k <= n - 1.0; k = k + 1.0){
    y = y*(x - k);
  }

  return y;
}
double RisingFactorial(double x, double n){
  double k, y;

  y = 1.0;

  for(k = 0.0; k <= n - 1.0; k = k + 1.0){
    y = y*(x + k);
  }

  return y;
}
double Hypergeometric(double a, double b, double c, double z, double maxIterations, double precision){
  double y;

  if(abs(z) >= 0.5){
    y = pow(1.0 - z,  -a)*HypergeometricDirect(a, c - b, c, z/(z - 1.0), maxIterations, precision);
  }else{
    y = HypergeometricDirect(a, b, c, z, maxIterations, precision);
  }

  return y;
}
double HypergeometricDirect(double a, double b, double c, double z, double maxIterations, double precision){
  double y, yp, n;
  bool done;

  y = 0.0;
  done = false;

  for(n = 0.0; n < maxIterations &&  !done ; n = n + 1.0){
    yp = RisingFactorial(a, n)*RisingFactorial(b, n)/RisingFactorial(c, n)*pow(z, n)/Factorial(n);
    if(abs(yp) < precision){
      done = true;
    }
    y = y + yp;
  }

  return y;
}
double BernouilliNumber(double n){
  return AkiyamaTanigawaAlgorithm(n);
}
double AkiyamaTanigawaAlgorithm(double n){
  double m, j, B;
  vector<double> *A;

  A = new vector<double> (n + 1.0);

  for(m = 0.0; m <= n; m = m + 1.0){
    A->at(m) = 1.0/(m + 1.0);
    for(j = m; j >= 1.0; j = j - 1.0){
      A->at(j - 1.0) = j*(A->at(j - 1.0) - A->at(j));
    }
  }

  B = A->at(0);

  delete A;

  return B;
}
vector<double> *StringToNumberArray(vector<wchar_t> *string){
  double i;
  vector<double> *array;

  array = new vector<double> (string->size());

  for(i = 0.0; i < string->size(); i = i + 1.0){
    array->at(i) = string->at(i);
  }
  return array;
}
vector<wchar_t> *NumberArrayToString(vector<double> *array){
  double i;
  vector<wchar_t> *string;

  string = new vector<wchar_t> (array->size());

  for(i = 0.0; i < array->size(); i = i + 1.0){
    string->at(i) = array->at(i);
  }
  return string;
}
bool NumberArraysEqual(vector<double> *a, vector<double> *b){
  bool equal;
  double i;

  equal = true;
  if(a->size() == b->size()){
    for(i = 0.0; i < a->size() && equal; i = i + 1.0){
      if(a->at(i) != b->at(i)){
        equal = false;
      }
    }
  }else{
    equal = false;
  }

  return equal;
}
bool BooleanArraysEqual(vector<bool> *a, vector<bool> *b){
  bool equal;
  double i;

  equal = true;
  if(a->size() == b->size()){
    for(i = 0.0; i < a->size() && equal; i = i + 1.0){
      if(a->at(i) != b->at(i)){
        equal = false;
      }
    }
  }else{
    equal = false;
  }

  return equal;
}
bool StringsEqual(vector<wchar_t> *a, vector<wchar_t> *b){
  bool equal;
  double i;

  equal = true;
  if(a->size() == b->size()){
    for(i = 0.0; i < a->size() && equal; i = i + 1.0){
      if(a->at(i) != b->at(i)){
        equal = false;
      }
    }
  }else{
    equal = false;
  }

  return equal;
}
void FillNumberArray(vector<double> *a, double value){
  double i;

  for(i = 0.0; i < a->size(); i = i + 1.0){
    a->at(i) = value;
  }
}
void FillString(vector<wchar_t> *a, wchar_t value){
  double i;

  for(i = 0.0; i < a->size(); i = i + 1.0){
    a->at(i) = value;
  }
}
void FillBooleanArray(vector<bool> *a, bool value){
  double i;

  for(i = 0.0; i < a->size(); i = i + 1.0){
    a->at(i) = value;
  }
}
bool FillNumberArrayRange(vector<double> *a, double value, double from, double to){
  double i, length;
  bool success;

  if(from >= 0.0 && from <= a->size() && to >= 0.0 && to <= a->size() && from <= to){
    length = to - from;
    for(i = 0.0; i < length; i = i + 1.0){
      a->at(from + i) = value;
    }

    success = true;
  }else{
    success = false;
  }

  return success;
}
bool FillBooleanArrayRange(vector<bool> *a, bool value, double from, double to){
  double i, length;
  bool success;

  if(from >= 0.0 && from <= a->size() && to >= 0.0 && to <= a->size() && from <= to){
    length = to - from;
    for(i = 0.0; i < length; i = i + 1.0){
      a->at(from + i) = value;
    }

    success = true;
  }else{
    success = false;
  }

  return success;
}
bool FillStringRange(vector<wchar_t> *a, wchar_t value, double from, double to){
  double i, length;
  bool success;

  if(from >= 0.0 && from <= a->size() && to >= 0.0 && to <= a->size() && from <= to){
    length = to - from;
    for(i = 0.0; i < length; i = i + 1.0){
      a->at(from + i) = value;
    }

    success = true;
  }else{
    success = false;
  }

  return success;
}
vector<double> *CopyNumberArray(vector<double> *a){
  double i;
  vector<double> *n;

  n = new vector<double> (a->size());

  for(i = 0.0; i < a->size(); i = i + 1.0){
    n->at(i) = a->at(i);
  }

  return n;
}
vector<bool> *CopyBooleanArray(vector<bool> *a){
  double i;
  vector<bool> *n;

  n = new vector<bool> (a->size());

  for(i = 0.0; i < a->size(); i = i + 1.0){
    n->at(i) = a->at(i);
  }

  return n;
}
vector<wchar_t> *CopyString(vector<wchar_t> *a){
  double i;
  vector<wchar_t> *n;

  n = new vector<wchar_t> (a->size());

  for(i = 0.0; i < a->size(); i = i + 1.0){
    n->at(i) = a->at(i);
  }

  return n;
}
bool CopyNumberArrayRange(vector<double> *a, double from, double to, NumberArrayReference *copyReference){
  double i, length;
  vector<double> *n;
  bool success;

  if(from >= 0.0 && from <= a->size() && to >= 0.0 && to <= a->size() && from <= to){
    length = to - from;
    n = new vector<double> (length);

    for(i = 0.0; i < length; i = i + 1.0){
      n->at(i) = a->at(from + i);
    }

    copyReference->numberArray = n;
    success = true;
  }else{
    success = false;
  }

  return success;
}
bool CopyBooleanArrayRange(vector<bool> *a, double from, double to, BooleanArrayReference *copyReference){
  double i, length;
  vector<bool> *n;
  bool success;

  if(from >= 0.0 && from <= a->size() && to >= 0.0 && to <= a->size() && from <= to){
    length = to - from;
    n = new vector<bool> (length);

    for(i = 0.0; i < length; i = i + 1.0){
      n->at(i) = a->at(from + i);
    }

    copyReference->booleanArray = n;
    success = true;
  }else{
    success = false;
  }

  return success;
}
bool CopyStringRange(vector<wchar_t> *a, double from, double to, StringReference *copyReference){
  double i, length;
  vector<wchar_t> *n;
  bool success;

  if(from >= 0.0 && from <= a->size() && to >= 0.0 && to <= a->size() && from <= to){
    length = to - from;
    n = new vector<wchar_t> (length);

    for(i = 0.0; i < length; i = i + 1.0){
      n->at(i) = a->at(from + i);
    }

    copyReference->string = n;
    success = true;
  }else{
    success = false;
  }

  return success;
}
bool IsLastElement(double length, double index){
  return index + 1.0 == length;
}
vector<double> *CreateNumberArray(double length, double value){
  vector<double> *array;

  array = new vector<double> (length);
  FillNumberArray(array, value);

  return array;
}
vector<bool> *CreateBooleanArray(double length, bool value){
  vector<bool> *array;

  array = new vector<bool> (length);
  FillBooleanArray(array, value);

  return array;
}
vector<wchar_t> *CreateString(double length, wchar_t value){
  vector<wchar_t> *array;

  array = new vector<wchar_t> (length);
  FillString(array, value);

  return array;
}
void SwapElementsOfNumberArray(vector<double> *A, double ai, double bi){
  double tmp;

  tmp = A->at(ai);
  A->at(ai) = A->at(bi);
  A->at(bi) = tmp;
}
void SwapElementsOfStringArray(StringArrayReference *A, double ai, double bi){
  StringReference *tmp;

  tmp = A->stringArray->at(ai);
  A->stringArray->at(ai) = A->stringArray->at(bi);
  A->stringArray->at(bi) = tmp;
}
void ReverseNumberArray(vector<double> *array){
  double i;

  for(i = 0.0; i < array->size()/2.0; i = i + 1.0){
    SwapElementsOfNumberArray(array, i, array->size() - i - 1.0);
  }
}


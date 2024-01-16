/* Downloaded from https://repo.progsbase.com - Code Developed Using progsbase. */

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <wchar.h>

#define strparam(str) (str), wcslen(str)

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct BooleanArrayReference;
typedef struct BooleanArrayReference BooleanArrayReference;

struct BooleanReference;
typedef struct BooleanReference BooleanReference;

struct CharacterReference;
typedef struct CharacterReference CharacterReference;

struct NumberArrayReference;
typedef struct NumberArrayReference NumberArrayReference;

struct NumberReference;
typedef struct NumberReference NumberReference;

struct StringArrayReference;
typedef struct StringArrayReference StringArrayReference;

struct StringReference;
typedef struct StringReference StringReference;

struct Date;
typedef struct Date Date;

struct DateReference;
typedef struct DateReference DateReference;

struct Interval;
typedef struct Interval Interval;

struct DateTimeTimezone;
typedef struct DateTimeTimezone DateTimeTimezone;

struct DateTimeTimezoneReference;
typedef struct DateTimeTimezoneReference DateTimeTimezoneReference;

struct DateTime;
typedef struct DateTime DateTime;

struct DateTimeReference;
typedef struct DateTimeReference DateTimeReference;

struct BooleanArrayReference{
  _Bool *booleanArray;
  size_t booleanArrayLength;
};

struct BooleanReference{
  _Bool booleanValue;
};

struct CharacterReference{
  wchar_t characterValue;
};

struct NumberArrayReference{
  double *numberArray;
  size_t numberArrayLength;
};

struct NumberReference{
  double numberValue;
};

struct StringArrayReference{
  StringReference **stringArray;
  size_t stringArrayLength;
};

struct StringReference{
  wchar_t *string;
  size_t stringLength;
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

_Bool IsValidNorwegianPersonalIdentificationNumber(wchar_t *fnummer, size_t fnummerLength, StringReference *message);
_Bool GetDateFromNorwegianPersonalIdentificationNumber(wchar_t *fnummer, size_t fnummerLength, DateReference *dateRef, StringReference *message);

void Test1(NumberReference *failures);

double test();

BooleanReference *CreateBooleanReference(_Bool value);
BooleanArrayReference *CreateBooleanArrayReference(_Bool *value, size_t valueLength);
BooleanArrayReference *CreateBooleanArrayReferenceLengthValue(double length, _Bool value);
void FreeBooleanArrayReference(BooleanArrayReference *booleanArrayReference);
CharacterReference *CreateCharacterReference(wchar_t value);
NumberReference *CreateNumberReference(double value);
NumberArrayReference *CreateNumberArrayReference(double *value, size_t valueLength);
NumberArrayReference *CreateNumberArrayReferenceLengthValue(double length, double value);
void FreeNumberArrayReference(NumberArrayReference *numberArrayReference);
StringReference *CreateStringReference(wchar_t *value, size_t valueLength);
StringReference *CreateStringReferenceLengthValue(double length, wchar_t value);
void FreeStringReference(StringReference *stringReference);
StringArrayReference *CreateStringArrayReference(StringReference **strings, size_t stringsLength);
StringArrayReference *CreateStringArrayReferenceLengthValue(double length, wchar_t *value, size_t valueLength);
void FreeStringArrayReference(StringArrayReference *stringArrayReference);

Date *CreateDate(double year, double month, double day);
_Bool IsLeapYearWithCheck(double year, BooleanReference *isLeapYearReference, StringReference *message);
_Bool IsLeapYear(double year);
_Bool DayToDateWithCheck(double dayNr, DateReference *dateReference, StringReference *message);
Date *DayToDate(double dayNr);
_Bool GetMonthFromDayNrWithCheck(double dayNr, double year, NumberReference *monthReference, NumberReference *remainderReference, StringReference *message);
double GetMonthFromDayNr(double dayNr, double year, NumberReference *remainderReference);
_Bool GetYearFromDayNrWithCheck(double dayNr, NumberReference *yearReference, NumberReference *remainder, StringReference *message);
double GetYearFromDayNr(double dayNr, NumberReference *remainder);
double DaysBetweenDates(Date *A, Date *B);
_Bool GetDaysInMonthWithCheck(double year, NumberArrayReference *daysInMonthReference, StringReference *message);
double *GetDaysInMonth(size_t *returnArrayLength, double year);
_Bool DateToDaysWithCheck(Date *date, NumberReference *dayNumberReferenceReference, StringReference *message);
double DateToDays(Date *date);
_Bool DateToWeekdayNumberWithCheck(Date *date, NumberReference *weekDayNumberReference, StringReference *message);
double DateToWeekdayNumber(Date *date);
double DateToWeeknumber(Date *date, NumberReference *yearRef);
_Bool DaysInMonthsWithCheck(double month, double year, NumberReference *daysInMonthsReference, StringReference *message);
double DaysInMonths(double month, double year);
_Bool DaysInYearsWithCheck(double years, NumberReference *daysReference, StringReference *message);
double DaysInYears(double years);
_Bool IsValidDate(Date *date, StringReference *message);
_Bool AddDaysToDate(Date *date, double days, StringReference *message);
void AssignDate(Date *a, Date *b);
void AddMonthsToDate(Date *date, double months);
_Bool DateToStringISO8601WithCheck(Date *date, StringReference *datestr, StringReference *message);
wchar_t *DateToStringISO8601(size_t *returnArrayLength, Date *date);
Date *DateFromStringISO8601(wchar_t *str, size_t strLength);
_Bool DateFromStringISO8601WithCheck(wchar_t *str, size_t strLength, DateReference *dateRef, StringReference *message);
_Bool IsValidDateISO8601(wchar_t *str, size_t strLength, StringReference *message);
_Bool DateEquals(Date *a, Date *b);
Date *CopyDate(Date *a);
double GetSecondsFromDate(Date *date);
_Bool DateIsInInterval(Interval *interval, Date *date);
_Bool DateLessThan(Date *a, Date *b);

DateTimeTimezone *CreateDateTimeTimezone(double year, double month, double day, double hours, double minutes, double seconds, double timezoneOffsetSeconds);
DateTimeTimezone *CreateDateTimeTimezoneInHoursAndMinutes(double year, double month, double day, double hours, double minutes, double seconds, double timezoneOffsetHours, double timezoneOffsetMinutes);
_Bool GetDateFromDateTimeTimeZone(DateTimeTimezone *dateTimeTimezone, DateTimeReference *dateTimeReference, StringReference *message);
_Bool CreateDateTimeTimezoneFromDateTimeAndTimeZoneInSeconds(DateTime *dateTime, double timezoneOffsetSeconds, DateTimeTimezoneReference *dateTimeTimezoneReference, StringReference *message);
_Bool CreateDateTimeTimezoneFromDateTimeAndTimeZoneInHoursAndMinutes(DateTime *dateTime, double timezoneOffsetHours, double timezoneOffsetMinutes, DateTimeTimezoneReference *dateTimeTimezoneReference, StringReference *message);
_Bool GetDateTimeTimezoneFromSeconds(DateTimeTimezoneReference *dateTimeTzRef, double seconds, double offset, StringReference *message);

DateTime *CreateDateTime(double year, double month, double day, double hours, double minutes, double seconds);
_Bool GetDateTimeFromSeconds(double seconds, DateTimeReference *dateTimeReference, StringReference *message);
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
_Bool AddSecondsToDateTimeWithCheck(DateTime *dateTime, double seconds, DateTimeReference *dateTimeReference, StringReference *message);
_Bool AddSecondsToDateTime(DateTime *dateTime, double seconds, DateTimeReference *dateTimeReference, StringReference *message);
_Bool AddMinutesToDateTime(DateTime *dateTime, double minutes, DateTimeReference *dateTimeReference, StringReference *message);
_Bool AddHoursToDateTime(DateTime *dateTime, double hours, DateTimeReference *dateTimeReference, StringReference *message);
_Bool AddDaysToDateTime(DateTime *dateTime, double days, DateTimeReference *dateTimeReference, StringReference *message);
_Bool AddWeeksToDateTime(DateTime *dateTime, double weeks, DateTimeReference *dateTimeReference, StringReference *message);
_Bool DateTimeToStringISO8601WithCheck(DateTime *datetime, StringReference *dateStr, StringReference *message);
_Bool IsValidDateTime(DateTime *datetime, StringReference *message);
wchar_t *DateTimeToStringISO8601(size_t *returnArrayLength, DateTime *datetime);
DateTime *DateTimeFromStringISO8601(wchar_t *str, size_t strLength);
_Bool DateTimeFromStringISO8601WithCheck(wchar_t *str, size_t strLength, DateTimeReference *dateTimeRef, StringReference *message);
_Bool IsValidDateTimeISO8601(wchar_t *str, size_t strLength, StringReference *message);
_Bool DateTimeEquals(DateTime *a, DateTime *b);
void FreeDateTime(DateTime *datetime);

wchar_t charToLowerCase(wchar_t character);
wchar_t charToUpperCase(wchar_t character);
_Bool charIsUpperCase(wchar_t character);
_Bool charIsLowerCase(wchar_t character);
_Bool charIsLetter(wchar_t character);
_Bool charIsNumber(wchar_t character);
_Bool charIsWhiteSpace(wchar_t character);
_Bool charIsSymbol(wchar_t character);
_Bool charCharacterIsBefore(wchar_t a, wchar_t b);
wchar_t charDecimalDigitToCharacter(double digit);
double charCharacterToDecimalDigit(wchar_t c);

void AssertFalse(_Bool b, NumberReference *failures);
void AssertTrue(_Bool b, NumberReference *failures);
void AssertEquals(double a, double b, NumberReference *failures);
void AssertBooleansEqual(_Bool a, _Bool b, NumberReference *failures);
void AssertCharactersEqual(wchar_t a, wchar_t b, NumberReference *failures);
void AssertStringEquals(wchar_t *a, size_t aLength, wchar_t *b, size_t bLength, NumberReference *failures);
void AssertNumberArraysEqual(double *a, size_t aLength, double *b, size_t bLength, NumberReference *failures);
void AssertBooleanArraysEqual(_Bool *a, size_t aLength, _Bool *b, size_t bLength, NumberReference *failures);
void AssertStringArraysEqual(StringReference **a, size_t aLength, StringReference **b, size_t bLength, NumberReference *failures);

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
_Bool DivisibleBy(double a, double b);
double Combinations(double n, double k);
double Permutations(double n, double k);
_Bool EpsilonCompare(double a, double b, double epsilon);
double GreatestCommonDivisor(double a, double b);
double GCDWithSubtraction(double a, double b);
_Bool IsInteger(double a);
_Bool GreatestCommonDivisorWithCheck(double a, double b, NumberReference *gcdReference);
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

double *StringToNumberArray(size_t *returnArrayLength, wchar_t *string, size_t stringLength);
wchar_t *NumberArrayToString(size_t *returnArrayLength, double *array, size_t arrayLength);
_Bool NumberArraysEqual(double *a, size_t aLength, double *b, size_t bLength);
_Bool BooleanArraysEqual(_Bool *a, size_t aLength, _Bool *b, size_t bLength);
_Bool StringsEqual(wchar_t *a, size_t aLength, wchar_t *b, size_t bLength);
void FillNumberArray(double *a, size_t aLength, double value);
void FillString(wchar_t *a, size_t aLength, wchar_t value);
void FillBooleanArray(_Bool *a, size_t aLength, _Bool value);
_Bool FillNumberArrayRange(double *a, size_t aLength, double value, double from, double to);
_Bool FillBooleanArrayRange(_Bool *a, size_t aLength, _Bool value, double from, double to);
_Bool FillStringRange(wchar_t *a, size_t aLength, wchar_t value, double from, double to);
double *CopyNumberArray(size_t *returnArrayLength, double *a, size_t aLength);
_Bool *CopyBooleanArray(size_t *returnArrayLength, _Bool *a, size_t aLength);
wchar_t *CopyString(size_t *returnArrayLength, wchar_t *a, size_t aLength);
_Bool CopyNumberArrayRange(double *a, size_t aLength, double from, double to, NumberArrayReference *copyReference);
_Bool CopyBooleanArrayRange(_Bool *a, size_t aLength, double from, double to, BooleanArrayReference *copyReference);
_Bool CopyStringRange(wchar_t *a, size_t aLength, double from, double to, StringReference *copyReference);
_Bool IsLastElement(double length, double index);
double *CreateNumberArray(size_t *returnArrayLength, double length, double value);
_Bool *CreateBooleanArray(size_t *returnArrayLength, double length, _Bool value);
wchar_t *CreateString(size_t *returnArrayLength, double length, wchar_t value);
void SwapElementsOfNumberArray(double *A, size_t ALength, double ai, double bi);
void SwapElementsOfStringArray(StringArrayReference *A, double ai, double bi);
void ReverseNumberArray(double *array, size_t arrayLength);

_Bool IsValidNorwegianPersonalIdentificationNumber(wchar_t *fnummer, size_t fnummerLength, StringReference *message){
  _Bool gyldig;
  double i, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
  double k1, k2;
  DateReference *dateRef;

  if((double)fnummerLength == 11.0){
    gyldig = true;
    for(i = 0.0; i < (double)fnummerLength; i = i + 1.0){
      if(charIsNumber(fnummer[(int)(i)])){
      }else{
        gyldig = false;
      }
    }

    if(gyldig){
      d1 = charCharacterToDecimalDigit(fnummer[0]);
      d2 = charCharacterToDecimalDigit(fnummer[1]);
      d3 = charCharacterToDecimalDigit(fnummer[2]);
      d4 = charCharacterToDecimalDigit(fnummer[3]);
      d5 = charCharacterToDecimalDigit(fnummer[4]);
      d6 = charCharacterToDecimalDigit(fnummer[5]);
      d7 = charCharacterToDecimalDigit(fnummer[6]);
      d8 = charCharacterToDecimalDigit(fnummer[7]);
      d9 = charCharacterToDecimalDigit(fnummer[8]);
      d10 = charCharacterToDecimalDigit(fnummer[9]);
      d11 = charCharacterToDecimalDigit(fnummer[10]);

      dateRef = (DateReference *)calloc(sizeof(DateReference), 1);
      gyldig = GetDateFromNorwegianPersonalIdentificationNumber(fnummer, fnummerLength, dateRef, message);

      if(gyldig){
        if(IsValidDate(dateRef->date, message)){
          k1 = d1*3.0 + d2*7.0 + d3*6.0 + d4*1.0 + d5*8.0 + d6*9.0 + d7*4.0 + d8*5.0 + d9*2.0;
          k1 = fmod(k1, 11.0);
          if(k1 != 0.0){
            k1 = 11.0 - k1;
          }
          if(k1 == 10.0){
            gyldig = false;
            message->string = L"Control digit 1 is 10, which is invalid.";
            message->stringLength = wcslen(message->string);
          }

          if(gyldig){
            k2 = d1*5.0 + d2*4.0 + d3*3.0 + d4*2.0 + d5*7.0 + d6*6.0 + d7*5.0 + d8*4.0 + d9*3.0 + k1*2.0;
            k2 = fmod(k2, 11.0);
            if(k2 != 0.0){
              k2 = 11.0 - k2;
            }
            if(k2 == 10.0){
              gyldig = false;
              message->string = L"Control digit 2 is 10, which is invalid.";
              message->stringLength = wcslen(message->string);
            }

            if(gyldig){
              if(k1 == d10){
                if(k2 == d11){
                  gyldig = true;
                }else{
                  gyldig = false;
                  message->string = L"Check of control digit 2 failed.";
                  message->stringLength = wcslen(message->string);
                }
              }else{
                gyldig = false;
                message->string = L"Check of control digit 1 failed.";
                message->stringLength = wcslen(message->string);
              }
            }
          }
        }else{
          gyldig = false;
          message->string = L"The date is not a valid date.";
          message->stringLength = wcslen(message->string);
        }
      }
    }else{
      gyldig = false;
      message->string = L"Each character must be a decimal digit.";
      message->stringLength = wcslen(message->string);
    }
  }else{
    gyldig = false;
    message->string = L"Must be exactly 11 digits long.";
    message->stringLength = wcslen(message->string);
  }

  return gyldig;
}
_Bool GetDateFromNorwegianPersonalIdentificationNumber(wchar_t *fnummer, size_t fnummerLength, DateReference *dateRef, StringReference *message){
  double individnummer;
  double day, month, year;
  double i, d1, d2, d3, d4, d5, d6, d7, d8, d9;
  _Bool success;

  success = true;
  dateRef->date = (Date *)calloc(sizeof(Date), 1);

  if((double)fnummerLength == 11.0){
    for(i = 0.0; i < (double)fnummerLength; i = i + 1.0){
      if(charIsNumber(fnummer[(int)(i)])){
      }else{
        success = false;
      }
    }

    if(success){
      d1 = charCharacterToDecimalDigit(fnummer[0]);
      d2 = charCharacterToDecimalDigit(fnummer[1]);
      d3 = charCharacterToDecimalDigit(fnummer[2]);
      d4 = charCharacterToDecimalDigit(fnummer[3]);
      d5 = charCharacterToDecimalDigit(fnummer[4]);
      d6 = charCharacterToDecimalDigit(fnummer[5]);
      d7 = charCharacterToDecimalDigit(fnummer[6]);
      d8 = charCharacterToDecimalDigit(fnummer[7]);
      d9 = charCharacterToDecimalDigit(fnummer[8]);

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
        message->string = L"Invalid combination of individnummer and year.";
        message->stringLength = wcslen(message->string);
      }

      if(success){
        dateRef->date->year = year;
        dateRef->date->month = month;
        dateRef->date->day = day;
      }
    }else{
      message->string = L"Each character must be a decimal digit.";
      message->stringLength = wcslen(message->string);
    }
  }else{
    message->string = L"Must be exactly 11 digits long.";
    message->stringLength = wcslen(message->string);
  }

  return success;
}
void Test1(NumberReference *failures){
  StringReference *message;
  DateReference *dateRef;
  _Bool success;

  message = (StringReference *)calloc(sizeof(StringReference), 1);

  success = IsValidNorwegianPersonalIdentificationNumber(strparam(L"10061270707"), message);
  AssertTrue(success, failures);

  dateRef = (DateReference *)calloc(sizeof(DateReference), 1);

  success = GetDateFromNorwegianPersonalIdentificationNumber(strparam(L"11028559912"), dateRef, message);
  AssertTrue(success, failures);
  AssertEquals(dateRef->date->year, 1885.0, failures);

  success = GetDateFromNorwegianPersonalIdentificationNumber(strparam(L"01019949768"), dateRef, message);
  AssertTrue(success, failures);
  AssertEquals(dateRef->date->year, 1999.0, failures);

  success = GetDateFromNorwegianPersonalIdentificationNumber(strparam(L"01010099931"), dateRef, message);
  AssertTrue(success, failures);
  AssertEquals(dateRef->date->year, 2000.0, failures);
}
double test(){
  NumberReference *failures;

  failures = CreateNumberReference(0.0);

  Test1(failures);

  return failures->numberValue;
}
BooleanReference *CreateBooleanReference(_Bool value){
  BooleanReference *ref;

  ref = (BooleanReference *)calloc(sizeof(BooleanReference), 1);
  ref->booleanValue = value;

  return ref;
}
BooleanArrayReference *CreateBooleanArrayReference(_Bool *value, size_t valueLength){
  BooleanArrayReference *ref;

  ref = (BooleanArrayReference *)calloc(sizeof(BooleanArrayReference), 1);
  ref->booleanArray = value;
  ref->booleanArrayLength = valueLength;

  return ref;
}
BooleanArrayReference *CreateBooleanArrayReferenceLengthValue(double length, _Bool value){
  BooleanArrayReference *ref;
  double i;

  ref = (BooleanArrayReference *)calloc(sizeof(BooleanArrayReference), 1);
  ref->booleanArray = (_Bool*)calloc(sizeof(_Bool) * (length), 1);
  ref->booleanArrayLength = length;

  for(i = 0.0; i < length; i = i + 1.0){
    ref->booleanArray[(int)(i)] = value;
  }

  return ref;
}
void FreeBooleanArrayReference(BooleanArrayReference *booleanArrayReference){
  free(booleanArrayReference->booleanArray);
  free(booleanArrayReference);
}
CharacterReference *CreateCharacterReference(wchar_t value){
  CharacterReference *ref;

  ref = (CharacterReference *)calloc(sizeof(CharacterReference), 1);
  ref->characterValue = value;

  return ref;
}
NumberReference *CreateNumberReference(double value){
  NumberReference *ref;

  ref = (NumberReference *)calloc(sizeof(NumberReference), 1);
  ref->numberValue = value;

  return ref;
}
NumberArrayReference *CreateNumberArrayReference(double *value, size_t valueLength){
  NumberArrayReference *ref;

  ref = (NumberArrayReference *)calloc(sizeof(NumberArrayReference), 1);
  ref->numberArray = value;
  ref->numberArrayLength = valueLength;

  return ref;
}
NumberArrayReference *CreateNumberArrayReferenceLengthValue(double length, double value){
  NumberArrayReference *ref;
  double i;

  ref = (NumberArrayReference *)calloc(sizeof(NumberArrayReference), 1);
  ref->numberArray = (double*)calloc(sizeof(double) * (length), 1);
  ref->numberArrayLength = length;

  for(i = 0.0; i < length; i = i + 1.0){
    ref->numberArray[(int)(i)] = value;
  }

  return ref;
}
void FreeNumberArrayReference(NumberArrayReference *numberArrayReference){
  free(numberArrayReference->numberArray);
  free(numberArrayReference);
}
StringReference *CreateStringReference(wchar_t *value, size_t valueLength){
  StringReference *ref;

  ref = (StringReference *)calloc(sizeof(StringReference), 1);
  ref->string = value;
  ref->stringLength = valueLength;

  return ref;
}
StringReference *CreateStringReferenceLengthValue(double length, wchar_t value){
  StringReference *ref;
  double i;

  ref = (StringReference *)calloc(sizeof(StringReference), 1);
  ref->string = (wchar_t*)calloc(sizeof(wchar_t) * (length), 1);
  ref->stringLength = length;

  for(i = 0.0; i < length; i = i + 1.0){
    ref->string[(int)(i)] = value;
  }

  return ref;
}
void FreeStringReference(StringReference *stringReference){
  free(stringReference->string);
  free(stringReference);
}
StringArrayReference *CreateStringArrayReference(StringReference **strings, size_t stringsLength){
  StringArrayReference *ref;

  ref = (StringArrayReference *)calloc(sizeof(StringArrayReference), 1);
  ref->stringArray = strings;
  ref->stringArrayLength = stringsLength;

  return ref;
}
StringArrayReference *CreateStringArrayReferenceLengthValue(double length, wchar_t *value, size_t valueLength){
  StringArrayReference *ref;
  double i;

  ref = (StringArrayReference *)calloc(sizeof(StringArrayReference), 1);
  ref->stringArray = (StringReference**)calloc(sizeof(StringReference) * (length), 1);
  ref->stringArrayLength = length;

  for(i = 0.0; i < length; i = i + 1.0){
    ref->stringArray[(int)(i)] = CreateStringReference(value, valueLength);
  }

  return ref;
}
void FreeStringArrayReference(StringArrayReference *stringArrayReference){
  double i;

  for(i = 0.0; i < (double)stringArrayReference->stringArrayLength; i = i + 1.0){
    free(stringArrayReference->stringArray[(int)(i)]);
  }
  free(stringArrayReference->stringArray);
  free(stringArrayReference);
}
Date *CreateDate(double year, double month, double day){
  Date *date;

  date = (Date *)calloc(sizeof(Date), 1);

  date->year = year;
  date->month = month;
  date->day = day;

  return date;
}
_Bool IsLeapYearWithCheck(double year, BooleanReference *isLeapYearReference, StringReference *message){
  _Bool itIsLeapYear;
  _Bool success;

  if(year >= 1752.0){
    success = true;
    itIsLeapYear = IsLeapYear(year);
  }else{
    success = false;
    itIsLeapYear = false;
    message->string = L"Gregorian calendar was not in general use.";
    message->stringLength = wcslen(message->string);
  }

  isLeapYearReference->booleanValue = itIsLeapYear;
  return success;
}
_Bool IsLeapYear(double year){
  _Bool itIsLeapYear;

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
_Bool DayToDateWithCheck(double dayNr, DateReference *dateReference, StringReference *message){
  Date *date;
  NumberReference *remainder;
  _Bool success;

  if(dayNr >=  -79623.0){
    date = (Date *)calloc(sizeof(Date), 1);
    remainder = (NumberReference *)calloc(sizeof(NumberReference), 1);
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
    message->string = L"Gregorian calendar was not in general use before 1752.";
    message->stringLength = wcslen(message->string);
  }

  return success;
}
Date *DayToDate(double dayNr){
  Date *date;
  _Bool success;
  DateReference *dateRef;
  StringReference *message;

  dateRef = (DateReference *)calloc(sizeof(DateReference), 1);
  message = (StringReference *)calloc(sizeof(StringReference), 1);

  success = DayToDateWithCheck(dayNr, dateRef, message);
  if(success){
    date = dateRef->date;
    free(dateRef);
    FreeStringReference(message);
  }else{
    date = CreateDate(1970.0, 1.0, 1.0);
  }

  return date;
}
_Bool GetMonthFromDayNrWithCheck(double dayNr, double year, NumberReference *monthReference, NumberReference *remainderReference, StringReference *message){
  double month;
  _Bool success;

  if(dayNr >=  -79623.0){
    month = GetMonthFromDayNr(dayNr, year, remainderReference);
    monthReference->numberValue = month;
    success = true;
  }else{
    success = false;
    message->string = L"Gregorian calendar not in general use before 1752.";
    message->stringLength = wcslen(message->string);
  }

  return success;
}
double GetMonthFromDayNr(double dayNr, double year, NumberReference *remainderReference){
  double *daysInMonth;
  size_t daysInMonthLength;
  _Bool done;
  double month;

  daysInMonth = GetDaysInMonth(&daysInMonthLength, year);
  done = false;
  month = 1.0;

  for(;  !done ; ){
    if(dayNr >= daysInMonth[(int)(month)]){
      dayNr = dayNr - daysInMonth[(int)(month)];
      month = month + 1.0;
    }else{
      done = true;
    }
  }
  remainderReference->numberValue = dayNr;

  return month;
}
_Bool GetYearFromDayNrWithCheck(double dayNr, NumberReference *yearReference, NumberReference *remainder, StringReference *message){
  _Bool success;
  double year;

  if(dayNr >= 0.0){
    success = true;
    year = GetYearFromDayNr(dayNr, remainder);
    yearReference->numberValue = year;
  }else{
    success = false;
    message->string = L"Day number must be 0 or higher. 0 is 1752-01-01.";
    message->stringLength = wcslen(message->string);
  }

  return success;
}
double GetYearFromDayNr(double dayNr, NumberReference *remainder){
  double nrOfDays;
  _Bool done;
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
_Bool GetDaysInMonthWithCheck(double year, NumberArrayReference *daysInMonthReference, StringReference *message){
  double *daysInMonth;
  size_t daysInMonthLength;
  _Bool success;
  Date *date;

  date = CreateDate(year, 1.0, 1.0);

  success = IsValidDate(date, message);
  if(success){
    daysInMonth = GetDaysInMonth(&daysInMonthLength, year);

    daysInMonthReference->numberArray = daysInMonth;
    daysInMonthReference->numberArrayLength = daysInMonthLength;
  }

  return success;
}
double *GetDaysInMonth(size_t *returnArrayLength, double year){
  double *daysInMonth;
  size_t daysInMonthLength;

  daysInMonth = (double*)calloc(sizeof(double) * (1.0 + 12.0), 1);
  daysInMonthLength = 1.0 + 12.0;

  daysInMonth[0] = 0.0;
  daysInMonth[1] = 31.0;

  if(IsLeapYear(year)){
    daysInMonth[2] = 29.0;
  }else{
    daysInMonth[2] = 28.0;
  }
  daysInMonth[3] = 31.0;
  daysInMonth[4] = 30.0;
  daysInMonth[5] = 31.0;
  daysInMonth[6] = 30.0;
  daysInMonth[7] = 31.0;
  daysInMonth[8] = 31.0;
  daysInMonth[9] = 30.0;
  daysInMonth[10] = 31.0;
  daysInMonth[11] = 30.0;
  daysInMonth[12] = 31.0;

  *returnArrayLength = daysInMonthLength;
  return daysInMonth;
}
_Bool DateToDaysWithCheck(Date *date, NumberReference *dayNumberReferenceReference, StringReference *message){
  double days;
  _Bool success;

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
_Bool DateToWeekdayNumberWithCheck(Date *date, NumberReference *weekDayNumberReference, StringReference *message){
  double weekDay;
  _Bool success;

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
      free(newyears);
    }
  }else{
    /* Week is in previous year. Either 52nd or 53rd. */
    newyears = CopyDate(date);
    newyears->month = 12.0;
    newyears->day = 31.0;
    newyears->year = date->year - 1.0;
    weekNumber = DateToWeeknumber(newyears, yearRef);
    free(newyears);
  }

  free(week1Start);

  return weekNumber;
}
_Bool DaysInMonthsWithCheck(double month, double year, NumberReference *daysInMonthsReference, StringReference *message){
  double days;
  _Bool success;
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
  double *daysInMonth;
  size_t daysInMonthLength;
  double days;
  double i;

  daysInMonth = GetDaysInMonth(&daysInMonthLength, year);

  days = 0.0;
  for(i = 1.0; i < month; i = i + 1.0){
    days = days + daysInMonth[(int)(i)];
  }

  return days;
}
_Bool DaysInYearsWithCheck(double years, NumberReference *daysReference, StringReference *message){
  double days;
  _Bool success;
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
_Bool IsValidDate(Date *date, StringReference *message){
  _Bool valid;
  double *daysInMonth;
  size_t daysInMonthLength;
  double daysInThisMonth;

  if(date->year >= 1752.0){
    if(date->month >= 1.0 && date->month <= 12.0){
      daysInMonth = GetDaysInMonth(&daysInMonthLength, date->year);
      daysInThisMonth = daysInMonth[(int)(date->month)];
      if(date->day >= 1.0 && date->day <= daysInThisMonth){
        valid = true;
      }else{
        valid = false;
        message->string = L"The month does not have the given day number.";
        message->stringLength = wcslen(message->string);
      }
    }else{
      valid = false;
      message->string = L"Month must be between 1 and 12, inclusive.";
      message->stringLength = wcslen(message->string);
    }
  }else{
    valid = false;
    message->string = L"Gregorian calendar was not in general use before 1752.";
    message->stringLength = wcslen(message->string);
  }

  return valid;
}
_Bool AddDaysToDate(Date *date, double days, StringReference *message){
  double n;
  _Bool success;
  DateReference *dateReference;
  NumberReference *daysRef;

  daysRef = (NumberReference *)calloc(sizeof(NumberReference), 1);
  success = DateToDaysWithCheck(date, daysRef, message);

  if(success){
    n = daysRef->numberValue;
    n = n + days;

    dateReference = (DateReference *)calloc(sizeof(DateReference), 1);
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
_Bool DateToStringISO8601WithCheck(Date *date, StringReference *datestr, StringReference *message){
  _Bool success;

  success = IsValidDate(date, message);

  if(success){
    if(date->year <= 9999.0){
      datestr->string = DateToStringISO8601(&datestr->stringLength, date);
    }else{
      message->string = L"This library works from 1752 to 9999.";
      message->stringLength = wcslen(message->string);
    }
  }

  return success;
}
wchar_t *DateToStringISO8601(size_t *returnArrayLength, Date *date){
  wchar_t *str;
  size_t strLength;

  str = (wchar_t*)calloc(sizeof(wchar_t) * (10.0), 1);
  strLength = 10.0;

  str[0] = charDecimalDigitToCharacter(floor(date->year/1000.0));
  str[1] = charDecimalDigitToCharacter(floor((fmod(date->year, 1000.0))/100.0));
  str[2] = charDecimalDigitToCharacter(floor((fmod(date->year, 100.0))/10.0));
  str[3] = charDecimalDigitToCharacter(floor(fmod(date->year, 10.0)));

  str[4] = '-';

  str[5] = charDecimalDigitToCharacter(floor((fmod(date->month, 100.0))/10.0));
  str[6] = charDecimalDigitToCharacter(floor(fmod(date->month, 10.0)));

  str[7] = '-';

  str[8] = charDecimalDigitToCharacter(floor((fmod(date->day, 100.0))/10.0));
  str[9] = charDecimalDigitToCharacter(floor(fmod(date->day, 10.0)));

  *returnArrayLength = strLength;
  return str;
}
Date *DateFromStringISO8601(wchar_t *str, size_t strLength){
  Date *date;
  double n;

  date = (Date *)calloc(sizeof(Date), 1);

  n = charCharacterToDecimalDigit(str[0])*1000.0;
  n = n + charCharacterToDecimalDigit(str[1])*100.0;
  n = n + charCharacterToDecimalDigit(str[2])*10.0;
  n = n + charCharacterToDecimalDigit(str[3])*1.0;

  date->year = n;

  n = charCharacterToDecimalDigit(str[5])*10.0;
  n = n + charCharacterToDecimalDigit(str[6])*1.0;

  date->month = n;

  n = charCharacterToDecimalDigit(str[8])*10.0;
  n = n + charCharacterToDecimalDigit(str[9])*1.0;

  date->day = n;

  return date;
}
_Bool DateFromStringISO8601WithCheck(wchar_t *str, size_t strLength, DateReference *dateRef, StringReference *message){
  _Bool valid;

  valid = IsValidDateISO8601(str, strLength, message);

  if(valid){
    dateRef->date = DateFromStringISO8601(str, strLength);
  }

  return valid;
}
_Bool IsValidDateISO8601(wchar_t *str, size_t strLength, StringReference *message){
  _Bool valid;

  if((double)strLength == 4.0 + 1.0 + 2.0 + 1.0 + 2.0){

    if(charIsNumber(str[0]) && charIsNumber(str[1]) && charIsNumber(str[2]) && charIsNumber(str[3]) && charIsNumber(str[5]) && charIsNumber(str[6]) && charIsNumber(str[8]) && charIsNumber(str[9])){
      if(str[4] == '-' && str[7] == '-'){
        valid = true;
      }else{
        valid = false;
        message->string = L"ISO8601 date must use \'-\' in positions 5 and 8.";
        message->stringLength = wcslen(message->string);
      }
    }else{
      valid = false;
      message->string = L"ISO8601 date must use decimal digits in positions 1, 2, 3, 4, 6, 7, 9 and 10.";
      message->stringLength = wcslen(message->string);
    }
  }else{
    valid = false;
    message->string = L"ISO8601 date must be exactly 10 characters long.";
    message->stringLength = wcslen(message->string);
  }

  return valid;
}
_Bool DateEquals(Date *a, Date *b){
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
  _Bool success;

  seconds = 0.0;
  dayNumberReferenceReference = (NumberReference *)calloc(sizeof(NumberReference), 1);
  message = (StringReference *)calloc(sizeof(StringReference), 1);

  success = DateToDaysWithCheck(date, dayNumberReferenceReference, message);
  if(success){
    days = dayNumberReferenceReference->numberValue;

    secondsInMinute = 60.0;
    secondsInHour = 60.0*secondsInMinute;
    secondsInDay = 24.0*secondsInHour;

    seconds = seconds + secondsInDay*days;
  }

  free(dayNumberReferenceReference);
  free(message);

  return seconds;
}
_Bool DateIsInInterval(Interval *interval, Date *date){
  double from, to, day;

  from = DateToDays(interval->first);
  to = DateToDays(interval->last);
  day = DateToDays(date);

  return day >= from && day <= to;
}
_Bool DateLessThan(Date *a, Date *b){
  double aDays, bDays;

  aDays = DateToDays(a);
  bDays = DateToDays(b);

  return aDays < bDays;
}
DateTimeTimezone *CreateDateTimeTimezone(double year, double month, double day, double hours, double minutes, double seconds, double timezoneOffsetSeconds){
  DateTimeTimezone *dateTimeTimezone;

  dateTimeTimezone = (DateTimeTimezone *)calloc(sizeof(DateTimeTimezone), 1);

  dateTimeTimezone->dateTime = CreateDateTime(year, month, day, hours, minutes, seconds);
  dateTimeTimezone->timezoneOffsetSeconds = timezoneOffsetSeconds;

  return dateTimeTimezone;
}
DateTimeTimezone *CreateDateTimeTimezoneInHoursAndMinutes(double year, double month, double day, double hours, double minutes, double seconds, double timezoneOffsetHours, double timezoneOffsetMinutes){
  DateTimeTimezone *dateTimeTimezone;

  dateTimeTimezone = (DateTimeTimezone *)calloc(sizeof(DateTimeTimezone), 1);

  dateTimeTimezone->dateTime = CreateDateTime(year, month, day, hours, minutes, seconds);
  dateTimeTimezone->timezoneOffsetSeconds = GetSecondsFromHours(timezoneOffsetHours) + GetSecondsFromMinutes(timezoneOffsetMinutes);

  return dateTimeTimezone;
}
_Bool GetDateFromDateTimeTimeZone(DateTimeTimezone *dateTimeTimezone, DateTimeReference *dateTimeReference, StringReference *message){
  DateTime *dateTime;

  dateTime = dateTimeTimezone->dateTime;

  return AddSecondsToDateTimeWithCheck(dateTime,  -dateTimeTimezone->timezoneOffsetSeconds, dateTimeReference, message);
}
_Bool CreateDateTimeTimezoneFromDateTimeAndTimeZoneInSeconds(DateTime *dateTime, double timezoneOffsetSeconds, DateTimeTimezoneReference *dateTimeTimezoneReference, StringReference *message){
  _Bool success;
  DateTimeReference *adjustedDateTimeReference;
  DateTimeTimezone *dateTimeTimezone;

  adjustedDateTimeReference = (DateTimeReference *)calloc(sizeof(DateTimeReference), 1);
  dateTimeTimezone = (DateTimeTimezone *)calloc(sizeof(DateTimeTimezone), 1);

  success = AddSecondsToDateTime(dateTime, timezoneOffsetSeconds, adjustedDateTimeReference, message);

  if(success){
    dateTimeTimezone->dateTime = adjustedDateTimeReference->dateTime;
    dateTimeTimezone->timezoneOffsetSeconds = timezoneOffsetSeconds;

    dateTimeTimezoneReference->dateTimeTimezone = dateTimeTimezone;
  }

  return success;
}
_Bool CreateDateTimeTimezoneFromDateTimeAndTimeZoneInHoursAndMinutes(DateTime *dateTime, double timezoneOffsetHours, double timezoneOffsetMinutes, DateTimeTimezoneReference *dateTimeTimezoneReference, StringReference *message){
  return CreateDateTimeTimezoneFromDateTimeAndTimeZoneInSeconds(dateTime, GetSecondsFromHours(timezoneOffsetHours) + GetSecondsFromMinutes(timezoneOffsetMinutes), dateTimeTimezoneReference, message);
}
_Bool GetDateTimeTimezoneFromSeconds(DateTimeTimezoneReference *dateTimeTzRef, double seconds, double offset, StringReference *message){
  _Bool success;
  DateTimeReference *dateTimeRef;

  dateTimeRef = (DateTimeReference *)calloc(sizeof(DateTimeReference), 1);
  success = GetDateTimeFromSeconds(seconds, dateTimeRef, message);

  if(success){
    success = CreateDateTimeTimezoneFromDateTimeAndTimeZoneInSeconds(dateTimeRef->dateTime, offset, dateTimeTzRef, message);
  }

  return success;
}
DateTime *CreateDateTime(double year, double month, double day, double hours, double minutes, double seconds){
  DateTime *dateTime;

  dateTime = (DateTime *)calloc(sizeof(DateTime), 1);

  dateTime->date = CreateDate(year, month, day);
  dateTime->hours = hours;
  dateTime->minutes = minutes;
  dateTime->seconds = seconds;

  return dateTime;
}
_Bool GetDateTimeFromSeconds(double seconds, DateTimeReference *dateTimeReference, StringReference *message){
  DateTime *dateTime;
  double secondsInMinute, secondsInHour, secondsInDay, days, remainder;
  Date *date;
  DateReference *dateReference;
  _Bool success;

  secondsInMinute = 60.0;
  secondsInHour = 60.0*secondsInMinute;
  secondsInDay = 24.0*secondsInHour;
  days = floor(seconds/secondsInDay);
  remainder = seconds - days*secondsInDay;
  dateReference = (DateReference *)calloc(sizeof(DateReference), 1);

  success = DayToDateWithCheck(days, dateReference, message);
  if(success){
    date = dateReference->date;

    dateTime = (DateTime *)calloc(sizeof(DateTime), 1);
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
_Bool AddSecondsToDateTimeWithCheck(DateTime *dateTime, double seconds, DateTimeReference *dateTimeReference, StringReference *message){
  double secondsInDateTime;
  _Bool success;

  if(IsValidDateTime(dateTime, message)){
    secondsInDateTime = GetSecondsFromDateTime(dateTime);
    secondsInDateTime = secondsInDateTime + seconds;

    success = GetDateTimeFromSeconds(secondsInDateTime, dateTimeReference, message);
  }else{
    success = false;
  }

  return success;
}
_Bool AddSecondsToDateTime(DateTime *dateTime, double seconds, DateTimeReference *dateTimeReference, StringReference *message){
  double secondsInDateTime;

  secondsInDateTime = GetSecondsFromDateTime(dateTime);
  secondsInDateTime = secondsInDateTime + seconds;

  return GetDateTimeFromSeconds(secondsInDateTime, dateTimeReference, message);
}
_Bool AddMinutesToDateTime(DateTime *dateTime, double minutes, DateTimeReference *dateTimeReference, StringReference *message){
  return AddSecondsToDateTime(dateTime, GetSecondsFromMinutes(minutes), dateTimeReference, message);
}
_Bool AddHoursToDateTime(DateTime *dateTime, double hours, DateTimeReference *dateTimeReference, StringReference *message){
  return AddSecondsToDateTime(dateTime, GetSecondsFromHours(hours), dateTimeReference, message);
}
_Bool AddDaysToDateTime(DateTime *dateTime, double days, DateTimeReference *dateTimeReference, StringReference *message){
  return AddSecondsToDateTime(dateTime, GetSecondsFromDays(days), dateTimeReference, message);
}
_Bool AddWeeksToDateTime(DateTime *dateTime, double weeks, DateTimeReference *dateTimeReference, StringReference *message){
  return AddSecondsToDateTime(dateTime, GetSecondsFromWeeks(weeks), dateTimeReference, message);
}
_Bool DateTimeToStringISO8601WithCheck(DateTime *datetime, StringReference *dateStr, StringReference *message){
  _Bool success;

  success = DateToStringISO8601WithCheck(datetime->date, dateStr, message);

  if(success){
    free(dateStr->string);

    success = IsValidDateTime(datetime, message);
    if(success){
      dateStr->string = DateTimeToStringISO8601(&dateStr->stringLength, datetime);
    }
  }

  return success;
}
_Bool IsValidDateTime(DateTime *datetime, StringReference *message){
  _Bool success;

  success = IsValidDate(datetime->date, message);

  if(success){
    if(datetime->hours <= 23.0 && datetime->hours >= 0.0){
      if(datetime->minutes <= 59.0 && datetime->minutes >= 0.0){
        if(datetime->seconds <= 59.0 && datetime->seconds >= 0.0){
          success = true;
        }else{
          success = false;
          message->string = L"Seconds must be between 0 and 59.";
          message->stringLength = wcslen(message->string);
        }
      }else{
        success = false;
        message->string = L"Minutes must be between 0 and 59.";
        message->stringLength = wcslen(message->string);
      }
    }else{
      success = false;
      message->string = L"Hours must be between 0 and 23.";
      message->stringLength = wcslen(message->string);
    }
  }

  return success;
}
wchar_t *DateTimeToStringISO8601(size_t *returnArrayLength, DateTime *datetime){
  wchar_t *datestr, *str;
  size_t datestrLength, strLength;
  double i;

  str = (wchar_t*)calloc(sizeof(wchar_t) * (19.0), 1);
  strLength = 19.0;

  datestr = DateToStringISO8601(&datestrLength, datetime->date);
  for(i = 0.0; i < (double)datestrLength; i = i + 1.0){
    str[(int)(i)] = datestr[(int)(i)];
  }

  str[10] = 'T';
  str[11] = charDecimalDigitToCharacter(floor((fmod(datetime->hours, 100.0))/10.0));
  str[12] = charDecimalDigitToCharacter(floor(fmod(datetime->hours, 10.0)));

  str[13] = ':';

  str[14] = charDecimalDigitToCharacter(floor((fmod(datetime->minutes, 100.0))/10.0));
  str[15] = charDecimalDigitToCharacter(floor(fmod(datetime->minutes, 10.0)));

  str[16] = ':';

  str[17] = charDecimalDigitToCharacter(floor((fmod(datetime->seconds, 100.0))/10.0));
  str[18] = charDecimalDigitToCharacter(floor(fmod(datetime->seconds, 10.0)));

  *returnArrayLength = strLength;
  return str;
}
DateTime *DateTimeFromStringISO8601(wchar_t *str, size_t strLength){
  DateTime *dateTime;
  double n;

  dateTime = (DateTime *)calloc(sizeof(DateTime), 1);

  dateTime->date = DateFromStringISO8601(str, strLength);

  n = charCharacterToDecimalDigit(str[11])*10.0;
  n = n + charCharacterToDecimalDigit(str[12])*1.0;

  dateTime->hours = n;

  n = charCharacterToDecimalDigit(str[14])*10.0;
  n = n + charCharacterToDecimalDigit(str[15])*1.0;

  dateTime->minutes = n;

  n = charCharacterToDecimalDigit(str[17])*10.0;
  n = n + charCharacterToDecimalDigit(str[18])*1.0;

  dateTime->seconds = n;

  return dateTime;
}
_Bool DateTimeFromStringISO8601WithCheck(wchar_t *str, size_t strLength, DateTimeReference *dateTimeRef, StringReference *message){
  _Bool valid;

  valid = IsValidDateTimeISO8601(str, strLength, message);

  if(valid){
    dateTimeRef->dateTime = DateTimeFromStringISO8601(str, strLength);
  }

  return valid;
}
_Bool IsValidDateTimeISO8601(wchar_t *str, size_t strLength, StringReference *message){
  _Bool valid;

  if((double)strLength == 4.0 + 1.0 + 2.0 + 1.0 + 2.0 + 1.0 + 2.0 + 1.0 + 2.0 + 1.0 + 2.0){

    if(charIsNumber(str[0]) && charIsNumber(str[1]) && charIsNumber(str[2]) && charIsNumber(str[3]) && charIsNumber(str[5]) && charIsNumber(str[6]) && charIsNumber(str[8]) && charIsNumber(str[9]) && charIsNumber(str[11]) && charIsNumber(str[12]) && charIsNumber(str[14]) && charIsNumber(str[15]) && charIsNumber(str[17]) && charIsNumber(str[18])){
      if(str[4] == '-' && str[7] == '-' && str[10] == 'T' && str[13] == ':' && str[16] == ':'){
        valid = true;
      }else{
        valid = false;
        message->string = L"ISO8601 date must use \'-\' in positions 5 and 8, \'T\' in position 11 and \':\' in positions 14 and 17.";
        message->stringLength = wcslen(message->string);
      }
    }else{
      valid = false;
      message->string = L"ISO8601 date must use decimal digits in positions 1, 2, 3, 4, 6, 7, 9, 10, 12, 13, 15, 16, 18 and 19.";
      message->stringLength = wcslen(message->string);
    }
  }else{
    valid = false;
    message->string = L"ISO8601 date must be exactly 19 characters long.";
    message->stringLength = wcslen(message->string);
  }

  return valid;
}
_Bool DateTimeEquals(DateTime *a, DateTime *b){
  return DateEquals(a->date, b->date) && a->hours == b->hours && a->minutes == b->minutes && a->seconds == b->seconds;
}
void FreeDateTime(DateTime *datetime){
  free(datetime->date);
  free(datetime);
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
_Bool charIsUpperCase(wchar_t character){
  _Bool isUpper;

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
_Bool charIsLowerCase(wchar_t character){
  _Bool isLower;

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
_Bool charIsLetter(wchar_t character){
  return charIsUpperCase(character) || charIsLowerCase(character);
}
_Bool charIsNumber(wchar_t character){
  _Bool isNumberx;

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
_Bool charIsWhiteSpace(wchar_t character){
  _Bool isWhiteSpacex;

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
_Bool charIsSymbol(wchar_t character){
  _Bool isSymbolx;

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
_Bool charCharacterIsBefore(wchar_t a, wchar_t b){
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
void AssertFalse(_Bool b, NumberReference *failures){
  if(b){
    failures->numberValue = failures->numberValue + 1.0;
  }
}
void AssertTrue(_Bool b, NumberReference *failures){
  if( !b ){
    failures->numberValue = failures->numberValue + 1.0;
  }
}
void AssertEquals(double a, double b, NumberReference *failures){
  if(a != b){
    failures->numberValue = failures->numberValue + 1.0;
  }
}
void AssertBooleansEqual(_Bool a, _Bool b, NumberReference *failures){
  if(a != b){
    failures->numberValue = failures->numberValue + 1.0;
  }
}
void AssertCharactersEqual(wchar_t a, wchar_t b, NumberReference *failures){
  if(a != b){
    failures->numberValue = failures->numberValue + 1.0;
  }
}
void AssertStringEquals(wchar_t *a, size_t aLength, wchar_t *b, size_t bLength, NumberReference *failures){
  if( !StringsEqual(a, aLength, b, bLength) ){
    failures->numberValue = failures->numberValue + 1.0;
  }
}
void AssertNumberArraysEqual(double *a, size_t aLength, double *b, size_t bLength, NumberReference *failures){
  double i;

  if((double)aLength == (double)bLength){
    for(i = 0.0; i < (double)aLength; i = i + 1.0){
      AssertEquals(a[(int)(i)], b[(int)(i)], failures);
    }
  }else{
    failures->numberValue = failures->numberValue + 1.0;
  }
}
void AssertBooleanArraysEqual(_Bool *a, size_t aLength, _Bool *b, size_t bLength, NumberReference *failures){
  double i;

  if((double)aLength == (double)bLength){
    for(i = 0.0; i < (double)aLength; i = i + 1.0){
      AssertBooleansEqual(a[(int)(i)], b[(int)(i)], failures);
    }
  }else{
    failures->numberValue = failures->numberValue + 1.0;
  }
}
void AssertStringArraysEqual(StringReference **a, size_t aLength, StringReference **b, size_t bLength, NumberReference *failures){
  double i;

  if((double)aLength == (double)bLength){
    for(i = 0.0; i < (double)aLength; i = i + 1.0){
      AssertStringEquals(a[(int)(i)]->string, a[(int)(i)]->stringLength, b[(int)(i)]->string, b[(int)(i)]->stringLength, failures);
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
  return fabs(x);
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
_Bool DivisibleBy(double a, double b){
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
_Bool EpsilonCompare(double a, double b, double epsilon){
  return fabs(a - b) < epsilon;
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
_Bool IsInteger(double a){
  return (a - floor(a)) == 0.0;
}
_Bool GreatestCommonDivisorWithCheck(double a, double b, NumberReference *gcdReference){
  _Bool success;
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
    lcm = fabs(a*b)/GreatestCommonDivisor(a, b);
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
  double *p;
  size_t pLength;
  double i, y, t, x;

  p = (double*)calloc(sizeof(double) * (8.0), 1);
  pLength = 8.0;
  p[0] = 676.5203681218851;
  p[1] =  -1259.1392167224028;
  p[2] = 771.32342877765313;
  p[3] =  -176.61502916214059;
  p[4] = 12.507343278686905;
  p[5] =  -0.13857109526572012;
  p[6] = 9.9843695780195716e-6;
  p[7] = 1.5056327351493116e-7;

  if(z < 0.5){
    y = M_PI/(sin(M_PI*z)*LanczosApproximation(1.0 - z));
  }else{
    z = z - 1.0;
    x = 0.99999999999980993;
    for(i = 0.0; i < (double)pLength; i = i + 1.0){
      x = x + p[(int)(i)]/(z + i + 1.0);
    }
    t = z + (double)pLength - 0.5;
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

    t = 1.0/(1.0 + 0.5*fabs(x));

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

  if(fabs(z) >= 0.5){
    y = pow(1.0 - z,  -a)*HypergeometricDirect(a, c - b, c, z/(z - 1.0), maxIterations, precision);
  }else{
    y = HypergeometricDirect(a, b, c, z, maxIterations, precision);
  }

  return y;
}
double HypergeometricDirect(double a, double b, double c, double z, double maxIterations, double precision){
  double y, yp, n;
  _Bool done;

  y = 0.0;
  done = false;

  for(n = 0.0; n < maxIterations &&  !done ; n = n + 1.0){
    yp = RisingFactorial(a, n)*RisingFactorial(b, n)/RisingFactorial(c, n)*pow(z, n)/Factorial(n);
    if(fabs(yp) < precision){
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
  double *A;
  size_t ALength;

  A = (double*)calloc(sizeof(double) * (n + 1.0), 1);
  ALength = n + 1.0;

  for(m = 0.0; m <= n; m = m + 1.0){
    A[(int)(m)] = 1.0/(m + 1.0);
    for(j = m; j >= 1.0; j = j - 1.0){
      A[(int)(j - 1.0)] = j*(A[(int)(j - 1.0)] - A[(int)(j)]);
    }
  }

  B = A[0];

  free(A);

  return B;
}
double *StringToNumberArray(size_t *returnArrayLength, wchar_t *string, size_t stringLength){
  double i;
  double *array;
  size_t arrayLength;

  array = (double*)calloc(sizeof(double) * ((double)stringLength), 1);
  arrayLength = (double)stringLength;

  for(i = 0.0; i < (double)stringLength; i = i + 1.0){
    array[(int)(i)] = string[(int)(i)];
  }
  *returnArrayLength = arrayLength;
  return array;
}
wchar_t *NumberArrayToString(size_t *returnArrayLength, double *array, size_t arrayLength){
  double i;
  wchar_t *string;
  size_t stringLength;

  string = (wchar_t*)calloc(sizeof(wchar_t) * ((double)arrayLength), 1);
  stringLength = (double)arrayLength;

  for(i = 0.0; i < (double)arrayLength; i = i + 1.0){
    string[(int)(i)] = array[(int)(i)];
  }
  *returnArrayLength = stringLength;
  return string;
}
_Bool NumberArraysEqual(double *a, size_t aLength, double *b, size_t bLength){
  _Bool equal;
  double i;

  equal = true;
  if((double)aLength == (double)bLength){
    for(i = 0.0; i < (double)aLength && equal; i = i + 1.0){
      if(a[(int)(i)] != b[(int)(i)]){
        equal = false;
      }
    }
  }else{
    equal = false;
  }

  return equal;
}
_Bool BooleanArraysEqual(_Bool *a, size_t aLength, _Bool *b, size_t bLength){
  _Bool equal;
  double i;

  equal = true;
  if((double)aLength == (double)bLength){
    for(i = 0.0; i < (double)aLength && equal; i = i + 1.0){
      if(a[(int)(i)] != b[(int)(i)]){
        equal = false;
      }
    }
  }else{
    equal = false;
  }

  return equal;
}
_Bool StringsEqual(wchar_t *a, size_t aLength, wchar_t *b, size_t bLength){
  _Bool equal;
  double i;

  equal = true;
  if((double)aLength == (double)bLength){
    for(i = 0.0; i < (double)aLength && equal; i = i + 1.0){
      if(a[(int)(i)] != b[(int)(i)]){
        equal = false;
      }
    }
  }else{
    equal = false;
  }

  return equal;
}
void FillNumberArray(double *a, size_t aLength, double value){
  double i;

  for(i = 0.0; i < (double)aLength; i = i + 1.0){
    a[(int)(i)] = value;
  }
}
void FillString(wchar_t *a, size_t aLength, wchar_t value){
  double i;

  for(i = 0.0; i < (double)aLength; i = i + 1.0){
    a[(int)(i)] = value;
  }
}
void FillBooleanArray(_Bool *a, size_t aLength, _Bool value){
  double i;

  for(i = 0.0; i < (double)aLength; i = i + 1.0){
    a[(int)(i)] = value;
  }
}
_Bool FillNumberArrayRange(double *a, size_t aLength, double value, double from, double to){
  double i, length;
  _Bool success;

  if(from >= 0.0 && from <= (double)aLength && to >= 0.0 && to <= (double)aLength && from <= to){
    length = to - from;
    for(i = 0.0; i < length; i = i + 1.0){
      a[(int)(from + i)] = value;
    }

    success = true;
  }else{
    success = false;
  }

  return success;
}
_Bool FillBooleanArrayRange(_Bool *a, size_t aLength, _Bool value, double from, double to){
  double i, length;
  _Bool success;

  if(from >= 0.0 && from <= (double)aLength && to >= 0.0 && to <= (double)aLength && from <= to){
    length = to - from;
    for(i = 0.0; i < length; i = i + 1.0){
      a[(int)(from + i)] = value;
    }

    success = true;
  }else{
    success = false;
  }

  return success;
}
_Bool FillStringRange(wchar_t *a, size_t aLength, wchar_t value, double from, double to){
  double i, length;
  _Bool success;

  if(from >= 0.0 && from <= (double)aLength && to >= 0.0 && to <= (double)aLength && from <= to){
    length = to - from;
    for(i = 0.0; i < length; i = i + 1.0){
      a[(int)(from + i)] = value;
    }

    success = true;
  }else{
    success = false;
  }

  return success;
}
double *CopyNumberArray(size_t *returnArrayLength, double *a, size_t aLength){
  double i;
  double *n;
  size_t nLength;

  n = (double*)calloc(sizeof(double) * ((double)aLength), 1);
  nLength = (double)aLength;

  for(i = 0.0; i < (double)aLength; i = i + 1.0){
    n[(int)(i)] = a[(int)(i)];
  }

  *returnArrayLength = nLength;
  return n;
}
_Bool *CopyBooleanArray(size_t *returnArrayLength, _Bool *a, size_t aLength){
  double i;
  _Bool *n;
  size_t nLength;

  n = (_Bool*)calloc(sizeof(_Bool) * ((double)aLength), 1);
  nLength = (double)aLength;

  for(i = 0.0; i < (double)aLength; i = i + 1.0){
    n[(int)(i)] = a[(int)(i)];
  }

  *returnArrayLength = nLength;
  return n;
}
wchar_t *CopyString(size_t *returnArrayLength, wchar_t *a, size_t aLength){
  double i;
  wchar_t *n;
  size_t nLength;

  n = (wchar_t*)calloc(sizeof(wchar_t) * ((double)aLength), 1);
  nLength = (double)aLength;

  for(i = 0.0; i < (double)aLength; i = i + 1.0){
    n[(int)(i)] = a[(int)(i)];
  }

  *returnArrayLength = nLength;
  return n;
}
_Bool CopyNumberArrayRange(double *a, size_t aLength, double from, double to, NumberArrayReference *copyReference){
  double i, length;
  double *n;
  size_t nLength;
  _Bool success;

  if(from >= 0.0 && from <= (double)aLength && to >= 0.0 && to <= (double)aLength && from <= to){
    length = to - from;
    n = (double*)calloc(sizeof(double) * (length), 1);
    nLength = length;

    for(i = 0.0; i < length; i = i + 1.0){
      n[(int)(i)] = a[(int)(from + i)];
    }

    copyReference->numberArray = n;
    copyReference->numberArrayLength = nLength;
    success = true;
  }else{
    success = false;
  }

  return success;
}
_Bool CopyBooleanArrayRange(_Bool *a, size_t aLength, double from, double to, BooleanArrayReference *copyReference){
  double i, length;
  _Bool *n;
  size_t nLength;
  _Bool success;

  if(from >= 0.0 && from <= (double)aLength && to >= 0.0 && to <= (double)aLength && from <= to){
    length = to - from;
    n = (_Bool*)calloc(sizeof(_Bool) * (length), 1);
    nLength = length;

    for(i = 0.0; i < length; i = i + 1.0){
      n[(int)(i)] = a[(int)(from + i)];
    }

    copyReference->booleanArray = n;
    copyReference->booleanArrayLength = nLength;
    success = true;
  }else{
    success = false;
  }

  return success;
}
_Bool CopyStringRange(wchar_t *a, size_t aLength, double from, double to, StringReference *copyReference){
  double i, length;
  wchar_t *n;
  size_t nLength;
  _Bool success;

  if(from >= 0.0 && from <= (double)aLength && to >= 0.0 && to <= (double)aLength && from <= to){
    length = to - from;
    n = (wchar_t*)calloc(sizeof(wchar_t) * (length), 1);
    nLength = length;

    for(i = 0.0; i < length; i = i + 1.0){
      n[(int)(i)] = a[(int)(from + i)];
    }

    copyReference->string = n;
    copyReference->stringLength = nLength;
    success = true;
  }else{
    success = false;
  }

  return success;
}
_Bool IsLastElement(double length, double index){
  return index + 1.0 == length;
}
double *CreateNumberArray(size_t *returnArrayLength, double length, double value){
  double *array;
  size_t arrayLength;

  array = (double*)calloc(sizeof(double) * (length), 1);
  arrayLength = length;
  FillNumberArray(array, arrayLength, value);

  *returnArrayLength = arrayLength;
  return array;
}
_Bool *CreateBooleanArray(size_t *returnArrayLength, double length, _Bool value){
  _Bool *array;
  size_t arrayLength;

  array = (_Bool*)calloc(sizeof(_Bool) * (length), 1);
  arrayLength = length;
  FillBooleanArray(array, arrayLength, value);

  *returnArrayLength = arrayLength;
  return array;
}
wchar_t *CreateString(size_t *returnArrayLength, double length, wchar_t value){
  wchar_t *array;
  size_t arrayLength;

  array = (wchar_t*)calloc(sizeof(wchar_t) * (length), 1);
  arrayLength = length;
  FillString(array, arrayLength, value);

  *returnArrayLength = arrayLength;
  return array;
}
void SwapElementsOfNumberArray(double *A, size_t ALength, double ai, double bi){
  double tmp;

  tmp = A[(int)(ai)];
  A[(int)(ai)] = A[(int)(bi)];
  A[(int)(bi)] = tmp;
}
void SwapElementsOfStringArray(StringArrayReference *A, double ai, double bi){
  StringReference *tmp;

  tmp = A->stringArray[(int)(ai)];
  A->stringArray[(int)(ai)] = A->stringArray[(int)(bi)];
  A->stringArray[(int)(bi)] = tmp;
}
void ReverseNumberArray(double *array, size_t arrayLength){
  double i;

  for(i = 0.0; i < (double)arrayLength/2.0; i = i + 1.0){
    SwapElementsOfNumberArray(array, arrayLength, i, (double)arrayLength - i - 1.0);
  }
}


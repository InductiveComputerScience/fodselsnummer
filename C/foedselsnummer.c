#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define strparam(str) (str), strlen(str)

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct BooleanReference;
typedef struct BooleanReference BooleanReference;

struct DoubleReference;
typedef struct DoubleReference DoubleReference;

struct StringReference;
typedef struct StringReference StringReference;

struct StringToDecimalResult;
typedef struct StringToDecimalResult StringToDecimalResult;

struct datetimeDateTime;
typedef struct datetimeDateTime datetimeDateTime;

struct datetimeSuccess;
typedef struct datetimeSuccess datetimeSuccess;

struct datetimeDate;
typedef struct datetimeDate datetimeDate;

struct DecimalListRef;
typedef struct DecimalListRef DecimalListRef;

struct StringListRef;
typedef struct StringListRef StringListRef;

struct BooleanReference{
  _Bool booleanValue;
};

struct DoubleReference{
  double doubleValue;
};

struct StringReference{
  char *string;
  size_t stringLength;
};

struct StringToDecimalResult{
  double result;
  char *feilmelding;
  size_t feilmeldingLength;
  _Bool success;
};

struct datetimeDateTime{
  double year;
  double month;
  double day;
  double hours;
  double minutes;
  double seconds;
};

struct datetimeSuccess{
  _Bool success;
  char *errorMessage;
  size_t errorMessageLength;
};

struct datetimeDate{
  double year;
  double month;
  double day;
};

struct DecimalListRef{
  double *list;
  size_t listLength;
};

struct StringListRef{
  StringReference **list;
  size_t listLength;
};

_Bool isValidNorwegianPersonalIdentificationNumber(char *fnummer, size_t fnummerLength);
datetimeDate *getDateFromNorwegianPersonalIdentificationNumber(char *fnummer, size_t fnummerLength, DoubleReference *failures);
double charToNumber(char c, DoubleReference *failures);

double test1();

double test();


char *decimalToString(size_t *returnArrayLength, double decimal);
char *numberToString(size_t *returnArrayLength, double decimal, double base);
double getDigits(double base);
double getDigitPosition(double decimal, double base);
char getSingleDigitFromNumber(double c, double base);
char *getNumberTable(size_t *returnArrayLength);

StringToDecimalResult *stringToDecimal(char *string, size_t stringLength);
StringToDecimalResult *stringToDecimalForBase(char *string, size_t stringLength, double base);
double getDecimalFromSingleDecimalDigit(char c, double base);
_Bool isNumber(char c, double base);

datetimeDateTime *datetimegetDateTimeFromSeconds(double seconds);
double datetimegetSecondsFromDateTime(datetimeDateTime *dateTime);

_Bool datetimeisLeapYear(double year, datetimeSuccess *success);
datetimeDate *datetimedayToDate(double dayNr, datetimeSuccess *success);
double datetimegetMonthFromDayNr(double dayNr, double year, DoubleReference *remainder);
double datetimegetYearFromDayNr(double dayNr, DoubleReference *remainder);
double *datetimegetDaysInMonth(size_t *returnArrayLength, double year);
double datetimedateToDayNumber(datetimeDate *date, datetimeSuccess *success);
double datetimedaysInMonths(double month, double year);
double datetimedaysInYears(double years);
_Bool datetimeisValidDate(datetimeDate *date);

void assertFalse(_Bool b, DoubleReference *failures);
void assertTrue(_Bool b, DoubleReference *failures);
void assertEquals(double a, double b, DoubleReference *failures);
void assertStringEquals(char *a, size_t aLength, char *b, size_t bLength, DoubleReference *failures);

double *stringToNumberArray(size_t *returnArrayLength, char *string, size_t stringLength);
char *numberArrayToString(size_t *returnArrayLength, double *array, size_t arrayLength);
_Bool stringsEqual(char *data1, size_t data1Length, char *data2, size_t data2Length);
_Bool numberArraysEqual(double *data1, size_t data1Length, double *data2, size_t data2Length);

char *substring(size_t *returnArrayLength, char *string, size_t stringLength, double from, double to);
char *appendString(size_t *returnArrayLength, char *string, size_t stringLength, char *s, size_t sLength);
char *appendCharacter(size_t *returnArrayLength, char *string, size_t stringLength, char c);
StringReference **split(size_t *returnArrayLength, char *toSplit, size_t toSplitLength, char splitBy);

double *addDecimal(size_t *returnArrayLength, double *list, size_t listLength, double a);
void addDecimalRef(DecimalListRef *list, double i);
double *removeDecimal(size_t *returnArrayLength, double *list, size_t listLength, double n);
double getDecimalRef(DecimalListRef *list, double i);
void removeDecimalRef(DecimalListRef *list, double i);

StringReference **addString(size_t *returnArrayLength, StringReference **list, size_t listLength, StringReference *a);
void addStringRef(StringListRef *list, StringReference *i);
StringReference **removeString(size_t *returnArrayLength, StringReference **list, size_t listLength, double n);
StringReference *getStringRef(StringListRef *list, double i);
void removeStringRef(StringListRef *list, double i);

double Negate(double x);
double Positive(double x);
double Round(double x);
double Ceil(double x);
double Floor(double x);
double Absolute(double x);
double Logarithm(double x);
double NaturalLogarithm(double x);
double Sin(double x);
double Cos(double x);
double Tan(double x);
double Asin(double x);
double Acos(double x);
double Atan(double x);
double Squareroot(double x);
double Exp(double x);
_Bool divisibleBy(double a, double b);

_Bool isValidNorwegianPersonalIdentificationNumber(char *fnummer, size_t fnummerLength){
  _Bool gyldig;
  double d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
  datetimeDate *aDatetimeDate;
  double k1, k2;
  DoubleReference *failures;

  if(fnummerLength == 11.0){
    failures = (DoubleReference *)malloc(sizeof(DoubleReference));
    failures->doubleValue = 0.0;
    d1 = charToNumber(fnummer[0], failures);
    d2 = charToNumber(fnummer[1], failures);
    d3 = charToNumber(fnummer[2], failures);
    d4 = charToNumber(fnummer[3], failures);
    d5 = charToNumber(fnummer[4], failures);
    d6 = charToNumber(fnummer[5], failures);
    d7 = charToNumber(fnummer[6], failures);
    d8 = charToNumber(fnummer[7], failures);
    d9 = charToNumber(fnummer[8], failures);
    d10 = charToNumber(fnummer[9], failures);
    d11 = charToNumber(fnummer[10], failures);
    if(failures->doubleValue == 0.0){
      aDatetimeDate = getDateFromNorwegianPersonalIdentificationNumber(fnummer, fnummerLength, failures);
      if(datetimeisValidDate(aDatetimeDate)){
        if(failures->doubleValue == 0.0){
          k1 = d1*3.0 + d2*7.0 + d3*6.0 + d4*1.0 + d5*8.0 + d6*9.0 + d7*4.0 + d8*5.0 + d9*2.0;
          k1 = fmod(k1, 11.0);
          if(k1 != 0.0){
            k1 = 11.0 - k1;
          }
          if(k1 == 10.0){
            failures->doubleValue = failures->doubleValue + 1.0;
          }
          k2 = d1*5.0 + d2*4.0 + d3*3.0 + d4*2.0 + d5*7.0 + d6*6.0 + d7*5.0 + d8*4.0 + d9*3.0 + k1*2.0;
          k2 = fmod(k2, 11.0);
          if(k2 != 0.0){
            k2 = 11.0 - k2;
          }
          if(k2 == 10.0){
            failures->doubleValue = failures->doubleValue + 1.0;
          }
          if(k1 == d10 && k2 == d11 && failures->doubleValue == 0.0){
            gyldig = true;
          }else{
            gyldig = false;
          }
        }else{
          gyldig = false;
        }
      }else{
        gyldig = false;
      }
    }else{
      gyldig = false;
    }
  }else{
    gyldig = false;
  }

  return gyldig;
}
datetimeDate *getDateFromNorwegianPersonalIdentificationNumber(char *fnummer, size_t fnummerLength, DoubleReference *failures){
  datetimeDate *aDatetimeDate;
  double individnummer;
  double day, month, year;
  double d1, d2, d3, d4, d5, d6, d7, d8, d9;

  aDatetimeDate = (datetimeDate *)malloc(sizeof(datetimeDate));

  d1 = charToNumber(fnummer[0], failures);
  d2 = charToNumber(fnummer[1], failures);
  d3 = charToNumber(fnummer[2], failures);
  d4 = charToNumber(fnummer[3], failures);
  d5 = charToNumber(fnummer[4], failures);
  d6 = charToNumber(fnummer[5], failures);
  d7 = charToNumber(fnummer[6], failures);
  d8 = charToNumber(fnummer[7], failures);
  d9 = charToNumber(fnummer[8], failures);

  if(failures->doubleValue == 0.0){
    individnummer = d7*100.0 + d8*10.0 + d9;
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
      year = year + 1900.0;
    }else{
      failures->doubleValue = failures->doubleValue + 1.0;
    }



    aDatetimeDate->year = year;
    aDatetimeDate->month = month;
    aDatetimeDate->day = day;
  }

  return aDatetimeDate;
}
double charToNumber(char c, DoubleReference *failures){
  double val;

  if(isNumber(c, 10.0)){
    val = getDecimalFromSingleDecimalDigit(c, 10.0);
  }else{
    val = 0.0;
    failures->doubleValue = failures->doubleValue + 1.0;
  }

  return val;
}
double test1(){
  DoubleReference *failures;

  failures = (DoubleReference *)malloc(sizeof(DoubleReference));
  failures->doubleValue = 0.0;

  assertTrue(isValidNorwegianPersonalIdentificationNumber(strparam("10061270707")), failures);

  return failures->doubleValue;
}
double test(){
  double failures;

  failures = 0.0;

  failures = failures + test1();

  return failures;
}
char *decimalToString(size_t *returnArrayLength, double decimal){

    return numberToString(returnArrayLength, decimal, 10.0);
}
char *numberToString(size_t *returnArrayLength, double decimal, double base){
  char *string;
  size_t stringLength;
  double digits;
  double digitPosition;
  _Bool hasPrintedPoint;
  double i, d;

  string = (char*)malloc(sizeof(char) * (0.0));
  stringLength = 0.0;

  digits = getDigits(base);

  /* Find digitPosition: */
  digitPosition = getDigitPosition(decimal, base);

  decimal = round(decimal*pow(base,  -digitPosition  + digits - 1.0));

  hasPrintedPoint = false;

  /* Print leading zeros. */
  if(digitPosition < 0.0){
    string = appendCharacter(&stringLength, string, stringLength, '0');
    string = appendCharacter(&stringLength, string, stringLength, '.');
    hasPrintedPoint = true;
    for(i = 0.0; i <  -digitPosition  - 1.0; i = i + 1.0){
      string = appendCharacter(&stringLength, string, stringLength, '0');
    }
  }

  /* Print number. */
  for(i = 0.0; i < digits; i = i + 1.0){
    d = floor(decimal/pow(base, digits - i - 1.0));
    if( !hasPrintedPoint  && digitPosition - i + 1.0 == 0.0){
      if(decimal != 0.0){
        string = appendCharacter(&stringLength, string, stringLength, '.');
      }
      hasPrintedPoint = true;
    }
    if(decimal == 0.0 && hasPrintedPoint){
    }else{
      string = appendCharacter(&stringLength, string, stringLength, getSingleDigitFromNumber(d, base));
    }
    decimal = decimal - d*pow(base, digits - i - 1.0);
  }

  /* Print trailing zeros. */
  for(i = 0.0; i < digitPosition - digits + 1.0; i = i + 1.0){
    string = appendCharacter(&stringLength, string, stringLength, '0');
  }

  /* Done */
  *returnArrayLength = stringLength;
  return string;
}
double getDigits(double base){
  double t;

  t = pow(10.0, 15.0);
  return floor(log10(t)/log10(base));
}
double getDigitPosition(double decimal, double base){
  double power;
  double t;

  power = ceil(log10(decimal)/log10(base));

  t = decimal*pow(base,  -power );
  if(t < base && t >= 1.0){
  }else if(t >= base){
    power = power + 1.0;
  }else if(t < 1.0){
    power = power - 1.0;
  }


  return power;
}
char getSingleDigitFromNumber(double c, double base){
  char *numberTable;
  size_t numberTableLength;
  char retc;

  numberTable = getNumberTable(&numberTableLength);

  if(c > base - 1.0){
    retc = '?';
  }else{
    retc = numberTable[(int)(c)];
  }

  return retc;
}
char *getNumberTable(size_t *returnArrayLength){
  char *numberTable;
  size_t numberTableLength;

  numberTable = (char*)malloc(sizeof(char) * (16.0));
  numberTableLength = 16.0;
  numberTable[0] = '0';
  numberTable[1] = '1';
  numberTable[2] = '2';
  numberTable[3] = '3';
  numberTable[4] = '4';
  numberTable[5] = '5';
  numberTable[6] = '6';
  numberTable[7] = '7';
  numberTable[8] = '8';
  numberTable[9] = '9';
  numberTable[10] = 'A';
  numberTable[11] = 'B';
  numberTable[12] = 'C';
  numberTable[13] = 'D';
  numberTable[14] = 'E';
  numberTable[15] = 'F';
  *returnArrayLength = numberTableLength;
  return numberTable;
}
StringToDecimalResult *stringToDecimal(char *string, size_t stringLength){

  return stringToDecimalForBase(string, stringLength, 10.0);
}
StringToDecimalResult *stringToDecimalForBase(char *string, size_t stringLength, double base){
  StringToDecimalResult *stringToDecimalResult;
  char c;
  double i, j;
  _Bool isPositive;
  double beforeDecimalPoint;
  double afterDecimalPoint;
  double n;
  double validCharacters;
  double d;

  stringToDecimalResult = (StringToDecimalResult *)malloc(sizeof(StringToDecimalResult));
  stringToDecimalResult->success = true;
  i = 0.0;
  isPositive = true;
  beforeDecimalPoint = 0.0;
  afterDecimalPoint = 0.0;
  n = 0.0;
  validCharacters = 0.0;

  if(base >= 2.0 && base <= 16.0){
    for(j = 0.0; j < stringLength; j = j + 1.0){
      c = string[(int)(j)];
      if(isNumber(c, base) || c == '.' || c == '-'){
        validCharacters = validCharacters + 1.0;
      }
    }
    if(validCharacters == stringLength){
      if(stringLength > 0.0){
        c = string[(int)(i)];
        if(c == '-'){
          isPositive = false;
          i = i + 1.0;
        }
        if(i < stringLength){
          c = string[(int)(i)];
          if(isNumber(c, base)){
            for(; isNumber(c, base) && (i < stringLength); ){
              beforeDecimalPoint = beforeDecimalPoint + 1.0;
              i = i + 1.0;
              if(i < stringLength){
                c = string[(int)(i)];
              }
            }
            if(i < stringLength){
              c = string[(int)(i)];
              if(c == '.'){
                i = i + 1.0;
                if(i < stringLength){
                  c = string[(int)(i)];
                  for(; isNumber(c, base) && (i < stringLength); ){
                    afterDecimalPoint = afterDecimalPoint + 1.0;
                    i = i + 1.0;
                    if(i < stringLength){
                      c = string[(int)(i)];
                    }
                  }
                }else{
                  stringToDecimalResult->success = false;
                  stringToDecimalResult->feilmelding = "Number must have digits after the decimal point.";
                  stringToDecimalResult->feilmeldingLength = strlen(stringToDecimalResult->feilmelding);
                }
              }
            }
          }else{
            stringToDecimalResult->success = false;
            stringToDecimalResult->feilmelding = "Number must start with digits (for negative numbers, after the optional negative sign).";
            stringToDecimalResult->feilmeldingLength = strlen(stringToDecimalResult->feilmelding);
          }
        }
        if(stringToDecimalResult->success != false){
          i = 0.0;
          if( !isPositive ){
            i = 1.0;
          }
          for(j = 0.0; j < beforeDecimalPoint; j = j + 1.0){
            c = string[(int)(i)];
            i = i + 1.0;
            d = getDecimalFromSingleDecimalDigit(c, base);
            n = n + d*pow(base, beforeDecimalPoint - j - 1.0);
          }
          if(afterDecimalPoint > 0.0){
            i = i + 1.0;
            for(j = 0.0; j < afterDecimalPoint; j = j + 1.0){
              c = string[(int)(i)];
              i = i + 1.0;
              d = getDecimalFromSingleDecimalDigit(c, base);
              n = n + d*pow(base, 0.0 - j - 1.0);
            }
          }
          if( !isPositive ){
            n =  -n ;
          }
          stringToDecimalResult->result = n;
          stringToDecimalResult->success = true;
        }
      }else{
        stringToDecimalResult->success = false;
        stringToDecimalResult->feilmelding = "String has no content.";
        stringToDecimalResult->feilmeldingLength = strlen(stringToDecimalResult->feilmelding);
      }
    }else{
      stringToDecimalResult->success = false;
      stringToDecimalResult->feilmelding = "String contains invalid character.";
      stringToDecimalResult->feilmeldingLength = strlen(stringToDecimalResult->feilmelding);
    }
  }else{
    stringToDecimalResult->success = false;
    stringToDecimalResult->feilmelding = "Base must be from 2 to 16.";
    stringToDecimalResult->feilmeldingLength = strlen(stringToDecimalResult->feilmelding);
  }

  return stringToDecimalResult;
}
double getDecimalFromSingleDecimalDigit(char c, double base){
  char *numberTable;
  size_t numberTableLength;
  double i;
  double position;

  numberTable = getNumberTable(&numberTableLength);
  position = 0.0;

  for(i = 0.0; i < base; i = i + 1.0){
    if(numberTable[(int)(i)] == c){
      position = i;
    }
  }

  return position;
}
_Bool isNumber(char c, double base){
  char *numberTable;
  size_t numberTableLength;
  double i;
  _Bool found;

  numberTable = getNumberTable(&numberTableLength);
  found = false;

  for(i = 0.0; i < base; i = i + 1.0){
    if(numberTable[(int)(i)] == c){
      found = true;
    }
  }

  return found;
}
datetimeDateTime *datetimegetDateTimeFromSeconds(double seconds){
  datetimeDateTime *dateTime;
  double secondsInMinute, secondsInHour, secondsInDay, days, remainder;
  datetimeDate *date;

  dateTime = (datetimeDateTime *)malloc(sizeof(datetimeDateTime));

  secondsInMinute = 60.0;
  secondsInHour = 60.0*secondsInMinute;
  secondsInDay = 24.0*secondsInHour;
  days = floor(seconds/secondsInDay);
  remainder = seconds - days*secondsInDay;

  date = datetimedayToDate(days, (datetimeSuccess *)malloc(sizeof(datetimeSuccess)));
  dateTime->year = date->year;
  dateTime->month = date->month;
  dateTime->day = date->day;

  dateTime->hours = floor(remainder/secondsInHour);
  remainder = remainder - dateTime->hours*secondsInHour;
  dateTime->minutes = floor(remainder/secondsInMinute);
  remainder = remainder - dateTime->minutes*secondsInMinute;
  dateTime->seconds = remainder;

  return dateTime;
}
double datetimegetSecondsFromDateTime(datetimeDateTime *dateTime){
  datetimeDate *date;
  double seconds;
  double days;
  double secondsInMinute;
  double secondsInHour;
  double secondsInDay;

  seconds = 0.0;

  date = (datetimeDate *)malloc(sizeof(datetimeDate));
  date->year = dateTime->year;
  date->month = dateTime->month;
  date->day = dateTime->day;

  days = datetimedateToDayNumber(date, (datetimeSuccess *)malloc(sizeof(datetimeSuccess)));

  secondsInMinute = 60.0;
  secondsInHour = 60.0*secondsInMinute;
  secondsInDay = 24.0*secondsInHour;

  seconds = seconds + secondsInDay*days;
  seconds = seconds + secondsInHour*dateTime->hours;
  seconds = seconds + secondsInMinute*dateTime->minutes;
  seconds = seconds + dateTime->seconds;

  return seconds;
}
_Bool datetimeisLeapYear(double year, datetimeSuccess *success){
  _Bool itIsLeapYear;

  if(year >= 1752.0){
    success->success = true;
    if(divisibleBy(year, 4.0)){
      if(divisibleBy(year, 100.0)){
        if(divisibleBy(year, 400.0)){
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
  }else{
    success->success = false;
    itIsLeapYear = false;
    success->errorMessage = "Gregorian calendar was not in general use.";
    success->errorMessageLength = strlen(success->errorMessage);
  }

  return itIsLeapYear;
}
datetimeDate *datetimedayToDate(double dayNr, datetimeSuccess *success){
  datetimeDate *date;
  DoubleReference *remainder;

  date = (datetimeDate *)malloc(sizeof(datetimeDate));
  success->success = true;
  remainder = (DoubleReference *)malloc(sizeof(DoubleReference));
  remainder->doubleValue = dayNr + 79623.0;
  /* Days since 1752-01-01. Day 0: Thursday, 1970-01-01 */
  /* Find year. */
  date->year = datetimegetYearFromDayNr(remainder->doubleValue, remainder);

  /* Find month. */
  date->month = datetimegetMonthFromDayNr(remainder->doubleValue, date->year, remainder);

  /* Find day. */
  date->day = 1.0 + remainder->doubleValue;

  return date;
}
double datetimegetMonthFromDayNr(double dayNr, double year, DoubleReference *remainder){
  double *daysInMonth;
  size_t daysInMonthLength;
  _Bool done;
  double month;

  daysInMonth = datetimegetDaysInMonth(&daysInMonthLength, year);
  done = false;
  month = 1.0;

  for(;  !done ; ){
    if(dayNr > daysInMonth[(int)(month)]){
      dayNr = dayNr - daysInMonth[(int)(month)];
      month = month + 1.0;
    }else{
      done = true;
    }
  }
  remainder->doubleValue = dayNr;

  return month;
}
double datetimegetYearFromDayNr(double dayNr, DoubleReference *remainder){
  double nrOfDays;
  _Bool done;
  double year;

  done = false;
  year = 1752.0;

  for(;  !done ; ){
    if(datetimeisLeapYear(year, (datetimeSuccess *)malloc(sizeof(datetimeSuccess)))){
      nrOfDays = 366.0;
    }else{
      nrOfDays = 365.0;
    }
    if(dayNr >= nrOfDays){
      dayNr = dayNr - nrOfDays;
      year = year + 1.0;
    }else{
      done = true;
    }
  }
  remainder->doubleValue = dayNr;

  return year;
}
double *datetimegetDaysInMonth(size_t *returnArrayLength, double year){
  double *daysInMonth;
  size_t daysInMonthLength;

  daysInMonth = (double*)malloc(sizeof(double) * (1.0 + 12.0));
  daysInMonthLength = 1.0 + 12.0;

  daysInMonth[0] = 0.0;
  daysInMonth[1] = 31.0;
  if(datetimeisLeapYear(year, (datetimeSuccess *)malloc(sizeof(datetimeSuccess)))){
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
double datetimedateToDayNumber(datetimeDate *date, datetimeSuccess *success){
  double days;

  success->success = true;
  days =  -79623.0 ;
  /* Day 1752-01-01 */
  days = days + datetimedaysInYears(date->year);
  days = days + datetimedaysInMonths(date->month, date->year);
  days = days + date->day - 1.0;

  return days;
}
double datetimedaysInMonths(double month, double year){
  double *daysInMonth;
  size_t daysInMonthLength;
  double days;
  double i;

  daysInMonth = datetimegetDaysInMonth(&daysInMonthLength, year);

  days = 0.0;
  for(i = 1.0; i < month; i = i + 1.0){
    days = days + daysInMonth[(int)(i)];
  }

  return days;
}
double datetimedaysInYears(double years){
  double days;
  double i;
  double nrOfDays;

  days = 0.0;
  for(i = 1752.0; i < years; i = i + 1.0){
    if(datetimeisLeapYear(i, (datetimeSuccess *)malloc(sizeof(datetimeSuccess)))){
      nrOfDays = 366.0;
    }else{
      nrOfDays = 365.0;
    }
    days = days + nrOfDays;
  }
  return days;
}
_Bool datetimeisValidDate(datetimeDate *date){
  _Bool valid;
  double *daysInMonth;
  size_t daysInMonthLength;
  double daysInThisMonth;

  if(date->year >= 1752.0){
    if(date->month >= 1.0 && date->month <= 12.0){
      daysInMonth = datetimegetDaysInMonth(&daysInMonthLength, date->year);
      daysInThisMonth = daysInMonth[(int)(date->month)];
      if(date->day >= 1.0 && date->day <= daysInThisMonth){
        valid = true;
      }else{
        valid = false;
      }
    }else{
      valid = false;
    }
  }else{
    valid = false;
  }

  return valid;
}
void assertFalse(_Bool b, DoubleReference *failures){

  if(b){
    failures->doubleValue = failures->doubleValue + 1.0;
  }
}
void assertTrue(_Bool b, DoubleReference *failures){

  if( !b ){
    failures->doubleValue = failures->doubleValue + 1.0;
  }
}
void assertEquals(double a, double b, DoubleReference *failures){

  if(a != b){
    failures->doubleValue = failures->doubleValue + 1.0;
  }
}
void assertStringEquals(char *a, size_t aLength, char *b, size_t bLength, DoubleReference *failures){

  if( !stringsEqual(a, aLength, b, bLength) ){
    failures->doubleValue = failures->doubleValue + 1.0;
  }
}
double *stringToNumberArray(size_t *returnArrayLength, char *string, size_t stringLength){
  double i;
  double *array;
  size_t arrayLength;

  array = (double*)malloc(sizeof(double) * (stringLength));
  arrayLength = stringLength;

  for(i = 0.0; i < stringLength; i = i + 1.0){
    array[(int)(i)] = string[(int)(i)];
  }
  *returnArrayLength = arrayLength;
  return array;
}
char *numberArrayToString(size_t *returnArrayLength, double *array, size_t arrayLength){
  double i;
  char *string;
  size_t stringLength;

  string = (char*)malloc(sizeof(char) * (arrayLength));
  stringLength = arrayLength;

  for(i = 0.0; i < arrayLength; i = i + 1.0){
    string[(int)(i)] = array[(int)(i)];
  }
  *returnArrayLength = stringLength;
  return string;
}
_Bool stringsEqual(char *data1, size_t data1Length, char *data2, size_t data2Length){
  _Bool equal;
  double nrEqual, i;

  equal = false;
  if(data1Length == data2Length){
    nrEqual = 0.0;
    for(i = 0.0; i < data1Length; i = i + 1.0){
      if(data1[(int)(i)] == data2[(int)(i)]){
        nrEqual = nrEqual + 1.0;
      }
    }
    if(nrEqual == data1Length){
      equal = true;
    }
  }else{
    equal = false;
  }

  return equal;
}
_Bool numberArraysEqual(double *data1, size_t data1Length, double *data2, size_t data2Length){
  _Bool equal;
  double nrEqual, i;

  equal = false;
  if(data1Length == data2Length){
    nrEqual = 0.0;
    for(i = 0.0; i < data1Length; i = i + 1.0){
      if(data1[(int)(i)] == data2[(int)(i)]){
        nrEqual = nrEqual + 1.0;
      }
    }
    if(nrEqual == data1Length){
      equal = true;
    }
  }else{
    equal = false;
  }

  return equal;
}
char *substring(size_t *returnArrayLength, char *string, size_t stringLength, double from, double to){
  char *n;
  size_t nLength;
  double i;

  n = (char*)malloc(sizeof(char) * (to - from));
  nLength = to - from;

  for(i = from; i < to; i = i + 1.0){
    n[(int)(i - from)] = string[(int)(i)];
  }

  *returnArrayLength = nLength;
  return n;
}
char *appendString(size_t *returnArrayLength, char *string, size_t stringLength, char *s, size_t sLength){
  char *newString;
  size_t newStringLength;
  double i;

  newString = (char*)malloc(sizeof(char) * (stringLength + sLength));
  newStringLength = stringLength + sLength;

  for(i = 0.0; i < stringLength; i = i + 1.0){
    newString[(int)(i)] = string[(int)(i)];
  }

  for(i = 0.0; i < sLength; i = i + 1.0){
    newString[(int)(stringLength + i)] = s[(int)(i)];
  }

  free(string);

  *returnArrayLength = newStringLength;
  return newString;
}
char *appendCharacter(size_t *returnArrayLength, char *string, size_t stringLength, char c){
  char *newString;
  size_t newStringLength;
  double i;

  newString = (char*)malloc(sizeof(char) * (stringLength + 1.0));
  newStringLength = stringLength + 1.0;

  for(i = 0.0; i < stringLength; i = i + 1.0){
    newString[(int)(i)] = string[(int)(i)];
  }

  newString[(int)(stringLength)] = c;

  free(string);

  *returnArrayLength = newStringLength;
  return newString;
}
StringReference **split(size_t *returnArrayLength, char *toSplit, size_t toSplitLength, char splitBy){
  StringReference **splitt;
  size_t splittLength;
  char *next;
  size_t nextLength;
  double i;
  char c;
  StringReference *n;

  splitt = (StringReference**)malloc(sizeof(StringReference) * 0.0);
  splittLength = 0.0;

  next = (char*)malloc(sizeof(char) * (0.0));
  nextLength = 0.0;
  for(i = 0.0; i < toSplitLength; i = i + 1.0){
    c = toSplit[(int)(i)];
    if(c == splitBy){
      n = (StringReference *)malloc(sizeof(StringReference));
      n->string = next;
      n->stringLength = nextLength;
      splitt = addString(&splittLength, splitt, splittLength, n);
      next = (char*)malloc(sizeof(char) * (0.0));
      nextLength = 0.0;
    }else{
      next = appendCharacter(&nextLength, next, nextLength, c);
    }
  }

  if(nextLength > 0.0){
    n = (StringReference *)malloc(sizeof(StringReference));
    n->string = next;
    n->stringLength = nextLength;
    splitt = addString(&splittLength, splitt, splittLength, n);
  }

  *returnArrayLength = splittLength;
  return splitt;
}
double *addDecimal(size_t *returnArrayLength, double *list, size_t listLength, double a){
  double *newlist;
  size_t newlistLength;
  double i;

  newlist = (double*)malloc(sizeof(double) * (listLength + 1.0));
  newlistLength = listLength + 1.0;
  for(i = 0.0; i < listLength; i = i + 1.0){
    newlist[(int)(i)] = list[(int)(i)];
  }
  newlist[(int)(listLength)] = a;
		
  free(list);
		
  *returnArrayLength = newlistLength;
  return newlist;
}
void addDecimalRef(DecimalListRef *list, double i){

  list->list = addDecimal(&list->listLength, list->list, list->listLength, i);
}
double *removeDecimal(size_t *returnArrayLength, double *list, size_t listLength, double n){
  double *newlist;
  size_t newlistLength;
  double i;

  newlist = (double*)malloc(sizeof(double) * (listLength - 1.0));
  newlistLength = listLength - 1.0;

  for(i = 0.0; i < listLength; i = i + 1.0){
    if(i < n){
      newlist[(int)(i)] = list[(int)(i)];
    }
    if(i > n){
      newlist[(int)(i - 1.0)] = list[(int)(i)];
    }
  }
		
  free(list);
		
  *returnArrayLength = newlistLength;
  return newlist;
}
double getDecimalRef(DecimalListRef *list, double i){

  return list->list[(int)(i)];
}
void removeDecimalRef(DecimalListRef *list, double i){

  list->list = removeDecimal(&list->listLength, list->list, list->listLength, i);
}
StringReference **addString(size_t *returnArrayLength, StringReference **list, size_t listLength, StringReference *a){
  StringReference **newlist;
  size_t newlistLength;
  double i;

  newlist = (StringReference**)malloc(sizeof(StringReference) * listLength + 1.0);
  newlistLength = listLength + 1.0;

  for(i = 0.0; i < listLength; i = i + 1.0){
    newlist[(int)(i)] = list[(int)(i)];
  }
  newlist[(int)(listLength)] = a;
		
  free(list);
		
  *returnArrayLength = newlistLength;
  return newlist;
}
void addStringRef(StringListRef *list, StringReference *i){

  list->list = addString(&list->listLength, list->list, list->listLength, i);
}
StringReference **removeString(size_t *returnArrayLength, StringReference **list, size_t listLength, double n){
  StringReference **newlist;
  size_t newlistLength;
  double i;

  newlist = (StringReference**)malloc(sizeof(StringReference) * listLength - 1.0);
  newlistLength = listLength - 1.0;

  for(i = 0.0; i < listLength; i = i + 1.0){
    if(i < n){
      newlist[(int)(i)] = list[(int)(i)];
    }
    if(i > n){
      newlist[(int)(i - 1.0)] = list[(int)(i)];
    }
  }
		
  free(list);
		
  *returnArrayLength = newlistLength;
  return newlist;
}
StringReference *getStringRef(StringListRef *list, double i){

  return list->list[(int)(i)];
}
void removeStringRef(StringListRef *list, double i){

  list->list = removeString(&list->listLength, list->list, list->listLength, i);
}
double Negate(double x){

  return  -x ;
}
double Positive(double x){

  return  +x ;
}
double Round(double x){

  return round(x);
}
double Ceil(double x){

  return ceil(x);
}
double Floor(double x){

  return floor(x);
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
double Squareroot(double x){

  return sqrt(x);
}
double Exp(double x){

  return exp(x);
}
_Bool divisibleBy(double a, double b){

  return ((fmod(a, b)) == 0.0);
}


#include <stdio.h>

int main(){
	printf("%f\n", test());
	return 0;
}
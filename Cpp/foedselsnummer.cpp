#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

#define toVector(s) (new vector<char> ((s), (s) + strlen(s)))

struct BooleanReference;

struct DoubleReference;

struct StringReference;

struct StringToDecimalResult;

struct datetimeDateTime;

struct datetimeSuccess;

struct datetimeDate;

struct DecimalListRef;

struct StringListRef;

struct BooleanReference{
  bool booleanValue;
};

struct DoubleReference{
  double doubleValue;
};

struct StringReference{
  vector<char> *string;
};

struct StringToDecimalResult{
  double result;
  vector<char> *feilmelding;
  bool success;
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
  bool success;
  vector<char> *errorMessage;
};

struct datetimeDate{
  double year;
  double month;
  double day;
};

struct DecimalListRef{
  vector<double> *list;
};

struct StringListRef{
  vector<StringReference*> *list;
};

bool isValidNorwegianPersonalIdentificationNumber(vector<char> *fnummer);
datetimeDate *getDateFromNorwegianPersonalIdentificationNumber(vector<char> *fnummer, DoubleReference *failures);
double charToNumber(char c, DoubleReference *failures);

double test1();

double test();


vector<char> *decimalToString(double decimal);
vector<char> *numberToString(double decimal, double base);
double getDigits(double base);
double getDigitPosition(double decimal, double base);
char getSingleDigitFromNumber(double c, double base);
vector<char> *getNumberTable();

StringToDecimalResult *stringToDecimal(vector<char> *string);
StringToDecimalResult *stringToDecimalForBase(vector<char> *string, double base);
double getDecimalFromSingleDecimalDigit(char c, double base);
bool isNumber(char c, double base);

datetimeDateTime *datetimegetDateTimeFromSeconds(double seconds);
double datetimegetSecondsFromDateTime(datetimeDateTime *dateTime);

bool datetimeisLeapYear(double year, datetimeSuccess *success);
datetimeDate *datetimedayToDate(double dayNr, datetimeSuccess *success);
double datetimegetMonthFromDayNr(double dayNr, double year, DoubleReference *remainder);
double datetimegetYearFromDayNr(double dayNr, DoubleReference *remainder);
vector<double> *datetimegetDaysInMonth(double year);
double datetimedateToDayNumber(datetimeDate *date, datetimeSuccess *success);
double datetimedaysInMonths(double month, double year);
double datetimedaysInYears(double years);
bool datetimeisValidDate(datetimeDate *date);

void assertFalse(bool b, DoubleReference *failures);
void assertTrue(bool b, DoubleReference *failures);
void assertEquals(double a, double b, DoubleReference *failures);
void assertStringEquals(vector<char> *a, vector<char> *b, DoubleReference *failures);

vector<double> *stringToNumberArray(vector<char> *string);
vector<char> *numberArrayToString(vector<double> *array);
bool stringsEqual(vector<char> *data1, vector<char> *data2);
bool numberArraysEqual(vector<double> *data1, vector<double> *data2);

vector<char> *substring(vector<char> *string, double from, double to);
vector<char> *appendString(vector<char> *string, vector<char> *s);
vector<char> *appendCharacter(vector<char> *string, char c);
vector<StringReference*> *split(vector<char> *toSplit, char splitBy);

vector<double> *addDecimal(vector<double> *list, double a);
void addDecimalRef(DecimalListRef *list, double i);
vector<double> *removeDecimal(vector<double> *list, double n);
double getDecimalRef(DecimalListRef *list, double i);
void removeDecimalRef(DecimalListRef *list, double i);

vector<StringReference*> *addString(vector<StringReference*> *list, StringReference *a);
void addStringRef(StringListRef *list, StringReference *i);
vector<StringReference*> *removeString(vector<StringReference*> *list, double n);
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
bool divisibleBy(double a, double b);

bool isValidNorwegianPersonalIdentificationNumber(vector<char> *fnummer){
  bool gyldig;
  double d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
  datetimeDate *aDatetimeDate;
  double k1, k2;
  DoubleReference *failures;

  if(fnummer->size() == 11.0){
    failures = new DoubleReference();
    failures->doubleValue = 0.0;
    d1 = charToNumber((*fnummer)[0], failures);
    d2 = charToNumber((*fnummer)[1], failures);
    d3 = charToNumber((*fnummer)[2], failures);
    d4 = charToNumber((*fnummer)[3], failures);
    d5 = charToNumber((*fnummer)[4], failures);
    d6 = charToNumber((*fnummer)[5], failures);
    d7 = charToNumber((*fnummer)[6], failures);
    d8 = charToNumber((*fnummer)[7], failures);
    d9 = charToNumber((*fnummer)[8], failures);
    d10 = charToNumber((*fnummer)[9], failures);
    d11 = charToNumber((*fnummer)[10], failures);
    if(failures->doubleValue == 0.0){
      aDatetimeDate = getDateFromNorwegianPersonalIdentificationNumber(fnummer, failures);
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
datetimeDate *getDateFromNorwegianPersonalIdentificationNumber(vector<char> *fnummer, DoubleReference *failures){
  datetimeDate *aDatetimeDate;
  double individnummer;
  double day, month, year;
  double d1, d2, d3, d4, d5, d6, d7, d8, d9;

  aDatetimeDate = new datetimeDate();

  d1 = charToNumber((*fnummer)[0], failures);
  d2 = charToNumber((*fnummer)[1], failures);
  d3 = charToNumber((*fnummer)[2], failures);
  d4 = charToNumber((*fnummer)[3], failures);
  d5 = charToNumber((*fnummer)[4], failures);
  d6 = charToNumber((*fnummer)[5], failures);
  d7 = charToNumber((*fnummer)[6], failures);
  d8 = charToNumber((*fnummer)[7], failures);
  d9 = charToNumber((*fnummer)[8], failures);

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

  failures = new DoubleReference();
  failures->doubleValue = 0.0;

  assertTrue(isValidNorwegianPersonalIdentificationNumber(toVector("10061270707")), failures);

  return failures->doubleValue;
}
double test(){
  double failures;

  failures = 0.0;

  failures = failures + test1();

  return failures;
}
vector<char> *decimalToString(double decimal){

  return numberToString(decimal, 10.0);
}
vector<char> *numberToString(double decimal, double base){
  vector<char> *string;
  double digits;
  double digitPosition;
  bool hasPrintedPoint;
  double i, d;

  string = new vector<char> (0.0);

  digits = getDigits(base);

  /* Find digitPosition: */
  digitPosition = getDigitPosition(decimal, base);

  decimal = round(decimal*pow(base,  -digitPosition  + digits - 1.0));

  hasPrintedPoint = false;

  /* Print leading zeros. */
  if(digitPosition < 0.0){
    string = appendCharacter(string, '0');
    string = appendCharacter(string, '.');
    hasPrintedPoint = true;
    for(i = 0.0; i <  -digitPosition  - 1.0; i = i + 1.0){
      string = appendCharacter(string, '0');
    }
  }

  /* Print number. */
  for(i = 0.0; i < digits; i = i + 1.0){
    d = floor(decimal/pow(base, digits - i - 1.0));
    if( !hasPrintedPoint  && digitPosition - i + 1.0 == 0.0){
      if(decimal != 0.0){
        string = appendCharacter(string, '.');
      }
      hasPrintedPoint = true;
    }
    if(decimal == 0.0 && hasPrintedPoint){
    }else{
      string = appendCharacter(string, getSingleDigitFromNumber(d, base));
    }
    decimal = decimal - d*pow(base, digits - i - 1.0);
  }

  /* Print trailing zeros. */
  for(i = 0.0; i < digitPosition - digits + 1.0; i = i + 1.0){
    string = appendCharacter(string, '0');
  }

  /* Done */
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
  vector<char> *numberTable;
  char retc;

  numberTable = getNumberTable();

  if(c > base - 1.0){
    retc = '?';
  }else{
    retc = (*numberTable)[(int)(c)];
  }

  return retc;
}
vector<char> *getNumberTable(){
  vector<char> *numberTable;

  numberTable = new vector<char> (16.0);
  (*numberTable)[0] = '0';
  (*numberTable)[1] = '1';
  (*numberTable)[2] = '2';
  (*numberTable)[3] = '3';
  (*numberTable)[4] = '4';
  (*numberTable)[5] = '5';
  (*numberTable)[6] = '6';
  (*numberTable)[7] = '7';
  (*numberTable)[8] = '8';
  (*numberTable)[9] = '9';
  (*numberTable)[10] = 'A';
  (*numberTable)[11] = 'B';
  (*numberTable)[12] = 'C';
  (*numberTable)[13] = 'D';
  (*numberTable)[14] = 'E';
  (*numberTable)[15] = 'F';
  return numberTable;
}
StringToDecimalResult *stringToDecimal(vector<char> *string){

  return stringToDecimalForBase(string, 10.0);
}
StringToDecimalResult *stringToDecimalForBase(vector<char> *string, double base){
  StringToDecimalResult *stringToDecimalResult;
  char c;
  double i, j;
  bool isPositive;
  double beforeDecimalPoint;
  double afterDecimalPoint;
  double n;
  double validCharacters;
  double d;

  stringToDecimalResult = new StringToDecimalResult();
  stringToDecimalResult->success = true;
  i = 0.0;
  isPositive = true;
  beforeDecimalPoint = 0.0;
  afterDecimalPoint = 0.0;
  n = 0.0;
  validCharacters = 0.0;

  if(base >= 2.0 && base <= 16.0){
    for(j = 0.0; j < string->size(); j = j + 1.0){
      c = (*string)[(int)(j)];
      if(isNumber(c, base) || c == '.' || c == '-'){
        validCharacters = validCharacters + 1.0;
      }
    }
    if(validCharacters == string->size()){
      if(string->size() > 0.0){
        c = (*string)[(int)(i)];
        if(c == '-'){
          isPositive = false;
          i = i + 1.0;
        }
        if(i < string->size()){
          c = (*string)[(int)(i)];
          if(isNumber(c, base)){
            for(; isNumber(c, base) && (i < string->size()); ){
              beforeDecimalPoint = beforeDecimalPoint + 1.0;
              i = i + 1.0;
              if(i < string->size()){
                c = (*string)[(int)(i)];
              }
            }
            if(i < string->size()){
              c = (*string)[(int)(i)];
              if(c == '.'){
                i = i + 1.0;
                if(i < string->size()){
                  c = (*string)[(int)(i)];
                  for(; isNumber(c, base) && (i < string->size()); ){
                    afterDecimalPoint = afterDecimalPoint + 1.0;
                    i = i + 1.0;
                    if(i < string->size()){
                      c = (*string)[(int)(i)];
                    }
                  }
                }else{
                  stringToDecimalResult->success = false;
                  stringToDecimalResult->feilmelding = toVector("Number must have digits after the decimal point.");
                }
              }
            }
          }else{
            stringToDecimalResult->success = false;
            stringToDecimalResult->feilmelding = toVector("Number must start with digits (for negative numbers, after the optional negative sign).");
          }
        }
        if(stringToDecimalResult->success != false){
          i = 0.0;
          if( !isPositive ){
            i = 1.0;
          }
          for(j = 0.0; j < beforeDecimalPoint; j = j + 1.0){
            c = (*string)[(int)(i)];
            i = i + 1.0;
            d = getDecimalFromSingleDecimalDigit(c, base);
            n = n + d*pow(base, beforeDecimalPoint - j - 1.0);
          }
          if(afterDecimalPoint > 0.0){
            i = i + 1.0;
            for(j = 0.0; j < afterDecimalPoint; j = j + 1.0){
              c = (*string)[(int)(i)];
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
        stringToDecimalResult->feilmelding = toVector("String has no content.");
      }
    }else{
      stringToDecimalResult->success = false;
      stringToDecimalResult->feilmelding = toVector("String contains invalid character.");
    }
  }else{
    stringToDecimalResult->success = false;
    stringToDecimalResult->feilmelding = toVector("Base must be from 2 to 16.");
  }

  return stringToDecimalResult;
}
double getDecimalFromSingleDecimalDigit(char c, double base){
  vector<char> *numberTable;
  double i;
  double position;

  numberTable = getNumberTable();
  position = 0.0;

  for(i = 0.0; i < base; i = i + 1.0){
    if((*numberTable)[(int)(i)] == c){
      position = i;
    }
  }

  return position;
}
bool isNumber(char c, double base){
  vector<char> *numberTable;
  double i;
  bool found;

  numberTable = getNumberTable();
  found = false;

  for(i = 0.0; i < base; i = i + 1.0){
    if((*numberTable)[(int)(i)] == c){
      found = true;
    }
  }

  return found;
}
datetimeDateTime *datetimegetDateTimeFromSeconds(double seconds){
  datetimeDateTime *dateTime;
  double secondsInMinute, secondsInHour, secondsInDay, days, remainder;
  datetimeDate *date;

  dateTime = new datetimeDateTime();

  secondsInMinute = 60.0;
  secondsInHour = 60.0*secondsInMinute;
  secondsInDay = 24.0*secondsInHour;
  days = floor(seconds/secondsInDay);
  remainder = seconds - days*secondsInDay;

  date = datetimedayToDate(days, new datetimeSuccess());
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

  date = new datetimeDate();
  date->year = dateTime->year;
  date->month = dateTime->month;
  date->day = dateTime->day;

  days = datetimedateToDayNumber(date, new datetimeSuccess());

  secondsInMinute = 60.0;
  secondsInHour = 60.0*secondsInMinute;
  secondsInDay = 24.0*secondsInHour;

  seconds = seconds + secondsInDay*days;
  seconds = seconds + secondsInHour*dateTime->hours;
  seconds = seconds + secondsInMinute*dateTime->minutes;
  seconds = seconds + dateTime->seconds;

  return seconds;
}
bool datetimeisLeapYear(double year, datetimeSuccess *success){
  bool itIsLeapYear;

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
    success->errorMessage = toVector("Gregorian calendar was not in general use.");
  }

  return itIsLeapYear;
}
datetimeDate *datetimedayToDate(double dayNr, datetimeSuccess *success){
  datetimeDate *date;
  DoubleReference *remainder;

  date = new datetimeDate();
  success->success = true;
  remainder = new DoubleReference();
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
  vector<double> *daysInMonth;
  bool done;
  double month;

  daysInMonth = datetimegetDaysInMonth(year);
  done = false;
  month = 1.0;

  for(;  !done ; ){
    if(dayNr > (*daysInMonth)[(int)(month)]){
      dayNr = dayNr - (*daysInMonth)[(int)(month)];
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
  bool done;
  double year;

  done = false;
  year = 1752.0;

  for(;  !done ; ){
    if(datetimeisLeapYear(year, new datetimeSuccess())){
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
vector<double> *datetimegetDaysInMonth(double year){
  vector<double> *daysInMonth;

  daysInMonth = new vector<double> (1.0 + 12.0);

  (*daysInMonth)[0] = 0.0;
  (*daysInMonth)[1] = 31.0;
  if(datetimeisLeapYear(year, new datetimeSuccess())){
    (*daysInMonth)[2] = 29.0;
  }else{
    (*daysInMonth)[2] = 28.0;
  }
  (*daysInMonth)[3] = 31.0;
  (*daysInMonth)[4] = 30.0;
  (*daysInMonth)[5] = 31.0;
  (*daysInMonth)[6] = 30.0;
  (*daysInMonth)[7] = 31.0;
  (*daysInMonth)[8] = 31.0;
  (*daysInMonth)[9] = 30.0;
  (*daysInMonth)[10] = 31.0;
  (*daysInMonth)[11] = 30.0;
  (*daysInMonth)[12] = 31.0;

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
  vector<double> *daysInMonth;
  double days;
  double i;

  daysInMonth = datetimegetDaysInMonth(year);

  days = 0.0;
  for(i = 1.0; i < month; i = i + 1.0){
    days = days + (*daysInMonth)[(int)(i)];
  }

  return days;
}
double datetimedaysInYears(double years){
  double days;
  double i;
  double nrOfDays;

  days = 0.0;
  for(i = 1752.0; i < years; i = i + 1.0){
    if(datetimeisLeapYear(i, new datetimeSuccess())){
      nrOfDays = 366.0;
    }else{
      nrOfDays = 365.0;
    }
    days = days + nrOfDays;
  }
  return days;
}
bool datetimeisValidDate(datetimeDate *date){
  bool valid;
  vector<double> *daysInMonth;
  double daysInThisMonth;

  if(date->year >= 1752.0){
    if(date->month >= 1.0 && date->month <= 12.0){
      daysInMonth = datetimegetDaysInMonth(date->year);
      daysInThisMonth = (*daysInMonth)[(int)(date->month)];
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
void assertFalse(bool b, DoubleReference *failures){

  if(b){
    failures->doubleValue = failures->doubleValue + 1.0;
  }
}
void assertTrue(bool b, DoubleReference *failures){

  if( !b ){
    failures->doubleValue = failures->doubleValue + 1.0;
  }
}
void assertEquals(double a, double b, DoubleReference *failures){

  if(a != b){
    failures->doubleValue = failures->doubleValue + 1.0;
  }
}
void assertStringEquals(vector<char> *a, vector<char> *b, DoubleReference *failures){

  if( !stringsEqual(a, b) ){
    failures->doubleValue = failures->doubleValue + 1.0;
  }
}
vector<double> *stringToNumberArray(vector<char> *string){
  double i;
  vector<double> *array;

  array = new vector<double> (string->size());

  for(i = 0.0; i < string->size(); i = i + 1.0){
    (*array)[(int)(i)] = (*string)[(int)(i)];
  }
  return array;
}
vector<char> *numberArrayToString(vector<double> *array){
  double i;
  vector<char> *string;

  string = new vector<char> (array->size());

  for(i = 0.0; i < array->size(); i = i + 1.0){
    (*string)[(int)(i)] = (*array)[(int)(i)];
  }
  return string;
}
bool stringsEqual(vector<char> *data1, vector<char> *data2){
  bool equal;
  double nrEqual, i;

  equal = false;
  if(data1->size() == data2->size()){
    nrEqual = 0.0;
    for(i = 0.0; i < data1->size(); i = i + 1.0){
      if((*data1)[(int)(i)] == (*data2)[(int)(i)]){
        nrEqual = nrEqual + 1.0;
      }
    }
    if(nrEqual == data1->size()){
      equal = true;
    }
  }else{
    equal = false;
  }

  return equal;
}
bool numberArraysEqual(vector<double> *data1, vector<double> *data2){
  bool equal;
  double nrEqual, i;

  equal = false;
  if(data1->size() == data2->size()){
    nrEqual = 0.0;
    for(i = 0.0; i < data1->size(); i = i + 1.0){
      if((*data1)[(int)(i)] == (*data2)[(int)(i)]){
        nrEqual = nrEqual + 1.0;
      }
    }
    if(nrEqual == data1->size()){
      equal = true;
    }
  }else{
    equal = false;
  }

  return equal;
}
vector<char> *substring(vector<char> *string, double from, double to){
  vector<char> *n;
  double i;

  n = new vector<char> (to - from);

  for(i = from; i < to; i = i + 1.0){
    (*n)[(int)(i - from)] = (*string)[(int)(i)];
  }

  return n;
}
vector<char> *appendString(vector<char> *string, vector<char> *s){
  vector<char> *newString;
  double i;

  newString = new vector<char> (string->size() + s->size());

  for(i = 0.0; i < string->size(); i = i + 1.0){
    (*newString)[(int)(i)] = (*string)[(int)(i)];
  }

  for(i = 0.0; i < s->size(); i = i + 1.0){
    (*newString)[(int)(string->size() + i)] = (*s)[(int)(i)];
  }

  delete string;

  return newString;
}
vector<char> *appendCharacter(vector<char> *string, char c){
  vector<char> *newString;
  double i;

  newString = new vector<char> (string->size() + 1.0);

  for(i = 0.0; i < string->size(); i = i + 1.0){
    (*newString)[(int)(i)] = (*string)[(int)(i)];
  }

  (*newString)[(int)(string->size())] = c;

  delete string;

  return newString;
}
vector<StringReference*> *split(vector<char> *toSplit, char splitBy){
  vector<StringReference*> *splitt;
  vector<char> *next;
  double i;
  char c;
  StringReference *n;

  splitt = new vector<StringReference*> (0.0);

  next = new vector<char> (0.0);
  for(i = 0.0; i < toSplit->size(); i = i + 1.0){
    c = (*toSplit)[(int)(i)];
    if(c == splitBy){
      n = new StringReference();
      n->string = next;
      splitt = addString(splitt, n);
      next = new vector<char> (0.0);
    }else{
      next = appendCharacter(next, c);
    }
  }

  if(next->size() > 0.0){
    n = new StringReference();
    n->string = next;
    splitt = addString(splitt, n);
  }

  return splitt;
}
vector<double> *addDecimal(vector<double> *list, double a){
  vector<double> *newlist;
  double i;

  newlist = new vector<double> (list->size() + 1.0);
  for(i = 0.0; i < list->size(); i = i + 1.0){
    (*newlist)[(int)(i)] = (*list)[(int)(i)];
  }
  (*newlist)[(int)(list->size())] = a;
		
  delete list;
		
  return newlist;
}
void addDecimalRef(DecimalListRef *list, double i){

  list->list = addDecimal(list->list, i);
}
vector<double> *removeDecimal(vector<double> *list, double n){
  vector<double> *newlist;
  double i;

  newlist = new vector<double> (list->size() - 1.0);

  for(i = 0.0; i < list->size(); i = i + 1.0){
    if(i < n){
      (*newlist)[(int)(i)] = (*list)[(int)(i)];
    }
    if(i > n){
      (*newlist)[(int)(i - 1.0)] = (*list)[(int)(i)];
    }
  }
		
  delete list;
		
  return newlist;
}
double getDecimalRef(DecimalListRef *list, double i){

  return (*list->list)[(int)(i)];
}
void removeDecimalRef(DecimalListRef *list, double i){

  list->list = removeDecimal(list->list, i);
}
vector<StringReference*> *addString(vector<StringReference*> *list, StringReference *a){
  vector<StringReference*> *newlist;
  double i;

  newlist = new vector<StringReference*> (list->size() + 1.0);

  for(i = 0.0; i < list->size(); i = i + 1.0){
    (*newlist)[(int)(i)] = (*list)[(int)(i)];
  }
  (*newlist)[(int)(list->size())] = a;
		
  delete list;
		
  return newlist;
}
void addStringRef(StringListRef *list, StringReference *i){

  list->list = addString(list->list, i);
}
vector<StringReference*> *removeString(vector<StringReference*> *list, double n){
  vector<StringReference*> *newlist;
  double i;

  newlist = new vector<StringReference*> (list->size() - 1.0);

  for(i = 0.0; i < list->size(); i = i + 1.0){
    if(i < n){
      (*newlist)[(int)(i)] = (*list)[(int)(i)];
    }
    if(i > n){
      (*newlist)[(int)(i - 1.0)] = (*list)[(int)(i)];
    }
  }
		
  delete list;
		
  return newlist;
}
StringReference *getStringRef(StringListRef *list, double i){

  return (*list->list)[(int)(i)];
}
void removeStringRef(StringListRef *list, double i){

  list->list = removeString(list->list, i);
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
double Squareroot(double x){

  return sqrt(x);
}
double Exp(double x){

  return exp(x);
}
bool divisibleBy(double a, double b){

  return ((fmod(a, b)) == 0.0);
}


#include <iostream>

using namespace std;

int main(){
	cout << test();
	return 0;
}
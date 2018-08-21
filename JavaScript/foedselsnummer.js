function isValidNorwegianPersonalIdentificationNumber(fnummer){
  var gyldig;
  var d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
  var aDatetimeDate;
  var k1, k2;
  var failures;
  if(fnummer.length == 11){
    failures = {};
    failures.doubleValue = 0;
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
    if(failures.doubleValue == 0){
      aDatetimeDate = getDateFromNorwegianPersonalIdentificationNumber(fnummer, failures);
      if(datetimeisValidDate(aDatetimeDate)){
        if(failures.doubleValue == 0){
          k1 = d1*3 + d2*7 + d3*6 + d4*1 + d5*8 + d6*9 + d7*4 + d8*5 + d9*2;
          k1 = k1%11;
          if(k1 != 0){
            k1 = 11 - k1;
          }
          if(k1 == 10){
            failures.doubleValue = failures.doubleValue + 1;
          }
          k2 = d1*5 + d2*4 + d3*3 + d4*2 + d5*7 + d6*6 + d7*5 + d8*4 + d9*3 + k1*2;
          k2 = k2%11;
          if(k2 != 0){
            k2 = 11 - k2;
          }
          if(k2 == 10){
            failures.doubleValue = failures.doubleValue + 1;
          }
          if(k1 == d10 && k2 == d11 && failures.doubleValue == 0){
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
function getDateFromNorwegianPersonalIdentificationNumber(fnummer, failures){
  var aDatetimeDate;
  var individnummer;
  var day, month, year;
  var d1, d2, d3, d4, d5, d6, d7, d8, d9;
  aDatetimeDate = {};

  d1 = charToNumber(fnummer[0], failures);
  d2 = charToNumber(fnummer[1], failures);
  d3 = charToNumber(fnummer[2], failures);
  d4 = charToNumber(fnummer[3], failures);
  d5 = charToNumber(fnummer[4], failures);
  d6 = charToNumber(fnummer[5], failures);
  d7 = charToNumber(fnummer[6], failures);
  d8 = charToNumber(fnummer[7], failures);
  d9 = charToNumber(fnummer[8], failures);

  if(failures.doubleValue == 0){
    individnummer = d7*100 + d8*10 + d9;
    day = d1*10 + d2;
    month = d3*10 + d4;
    year = d5*10 + d6;
    if(individnummer >= 0 && individnummer <= 499){
      year = year + 1900;
    }else if(individnummer >= 500 && individnummer <= 749 && year >= 54 && year <= 99){
      year = year + 1800;
    }else if(individnummer >= 900 && individnummer <= 999 && year >= 40 && year <= 99){
      year = year + 1900;
    }else if(individnummer >= 500 && individnummer <= 999 && year >= 0 && year <= 39){
      year = year + 1900;
    }else{
      failures.doubleValue = failures.doubleValue + 1;
    }



    aDatetimeDate.year = year;
    aDatetimeDate.month = month;
    aDatetimeDate.day = day;
  }

  return aDatetimeDate;
}
function charToNumber(c, failures){
  var val;
  if(isNumber(c, 10)){
    val = getDecimalFromSingleDecimalDigit(c, 10);
  }else{
    val = 0;
    failures.doubleValue = failures.doubleValue + 1;
  }

  return val;
}
function test1(){
  var failures;
  failures = {};
  failures.doubleValue = 0;

  assertTrue(isValidNorwegianPersonalIdentificationNumber("10061270707"), failures);

  return failures.doubleValue;
}
function test(){
  var failures;
  failures = 0;

  failures = failures + test1();

  return failures;
}
function decimalToString(decimal){
  return numberToString(decimal, 10);
}
function numberToString(decimal, base){
  var string;
  var digits;
  var digitPosition;
  var hasPrintedPoint;
  var i, d;
  string = [];
  string.length = 0;

  digits = getDigits(base);

  /* Find digitPosition: */
  digitPosition = getDigitPosition(decimal, base);

  decimal = Math.round(decimal*Math.pow(base,  -digitPosition  + digits - 1));

  hasPrintedPoint = false;

  /* Print leading zeros. */
  if(digitPosition < 0){
    string = appendCharacter(string, '0');
    string = appendCharacter(string, '.');
    hasPrintedPoint = true;
    for(i = 0; i <  -digitPosition  - 1; i = i + 1){
      string = appendCharacter(string, '0');
    }
  }

  /* Print number. */
  for(i = 0; i < digits; i = i + 1){
    d = Math.floor(decimal/Math.pow(base, digits - i - 1));
    if( !hasPrintedPoint  && digitPosition - i + 1 == 0){
      if(decimal != 0){
        string = appendCharacter(string, '.');
      }
      hasPrintedPoint = true;
    }
    if(decimal == 0 && hasPrintedPoint){
    }else{
      string = appendCharacter(string, getSingleDigitFromNumber(d, base));
    }
    decimal = decimal - d*Math.pow(base, digits - i - 1);
  }

  /* Print trailing zeros. */
  for(i = 0; i < digitPosition - digits + 1; i = i + 1){
    string = appendCharacter(string, '0');
  }

  /* Done */
  return string;
}
function getDigits(base){
  var t;
  t = Math.pow(10, 15);
  return Math.floor(Math.log10(t)/Math.log10(base));
}
function getDigitPosition(decimal, base){
  var power;
  var t;
  power = Math.ceil(Math.log10(decimal)/Math.log10(base));

  t = decimal*Math.pow(base,  -power );
  if(t < base && t >= 1){
  }else if(t >= base){
    power = power + 1;
  }else if(t < 1){
    power = power - 1;
  }


  return power;
}
function getSingleDigitFromNumber(c, base){
  var numberTable;
  var retc;
  numberTable = getNumberTable();

  if(c > base - 1){
    retc = '?';
  }else{
    retc = numberTable[c];
  }

  return retc;
}
function getNumberTable(){
  var numberTable;
  numberTable = [];
  numberTable.length = 16;
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
  return numberTable;
}
function stringToDecimal(string){
  return stringToDecimalForBase(string, 10);
}
function stringToDecimalForBase(string, base){
  var stringToDecimalResult;
  var c;
  var i, j;
  var isPositive;
  var beforeDecimalPoint;
  var afterDecimalPoint;
  var n;
  var validCharacters;
  var d;
  stringToDecimalResult = {};
  stringToDecimalResult.success = true;
  i = 0;
  isPositive = true;
  beforeDecimalPoint = 0;
  afterDecimalPoint = 0;
  n = 0;
  validCharacters = 0;

  if(base >= 2 && base <= 16){
    for(j = 0; j < string.length; j = j + 1){
      c = string[j];
      if(isNumber(c, base) || c == '.' || c == '-'){
        validCharacters = validCharacters + 1;
      }
    }
    if(validCharacters == string.length){
      if(string.length > 0){
        c = string[i];
        if(c == '-'){
          isPositive = false;
          i = i + 1;
        }
        if(i < string.length){
          c = string[i];
          if(isNumber(c, base)){
            for(; isNumber(c, base) && (i < string.length); ){
              beforeDecimalPoint = beforeDecimalPoint + 1;
              i = i + 1;
              if(i < string.length){
                c = string[i];
              }
            }
            if(i < string.length){
              c = string[i];
              if(c == '.'){
                i = i + 1;
                if(i < string.length){
                  c = string[i];
                  for(; isNumber(c, base) && (i < string.length); ){
                    afterDecimalPoint = afterDecimalPoint + 1;
                    i = i + 1;
                    if(i < string.length){
                      c = string[i];
                    }
                  }
                }else{
                  stringToDecimalResult.success = false;
                  stringToDecimalResult.feilmelding = "Number must have digits after the decimal point.";
                }
              }
            }
          }else{
            stringToDecimalResult.success = false;
            stringToDecimalResult.feilmelding = "Number must start with digits (for negative numbers, after the optional negative sign).";
          }
        }
        if(stringToDecimalResult.success != false){
          i = 0;
          if( !isPositive ){
            i = 1;
          }
          for(j = 0; j < beforeDecimalPoint; j = j + 1){
            c = string[i];
            i = i + 1;
            d = getDecimalFromSingleDecimalDigit(c, base);
            n = n + d*Math.pow(base, beforeDecimalPoint - j - 1);
          }
          if(afterDecimalPoint > 0){
            i = i + 1;
            for(j = 0; j < afterDecimalPoint; j = j + 1){
              c = string[i];
              i = i + 1;
              d = getDecimalFromSingleDecimalDigit(c, base);
              n = n + d*Math.pow(base, 0 - j - 1);
            }
          }
          if( !isPositive ){
            n =  -n ;
          }
          stringToDecimalResult.result = n;
          stringToDecimalResult.success = true;
        }
      }else{
        stringToDecimalResult.success = false;
        stringToDecimalResult.feilmelding = "String has no content.";
      }
    }else{
      stringToDecimalResult.success = false;
      stringToDecimalResult.feilmelding = "String contains invalid character.";
    }
  }else{
    stringToDecimalResult.success = false;
    stringToDecimalResult.feilmelding = "Base must be from 2 to 16.";
  }

  return stringToDecimalResult;
}
function getDecimalFromSingleDecimalDigit(c, base){
  var numberTable;
  var i;
  var position;
  numberTable = getNumberTable();
  position = 0;

  for(i = 0; i < base; i = i + 1){
    if(numberTable[i] == c){
      position = i;
    }
  }

  return position;
}
function isNumber(c, base){
  var numberTable;
  var i;
  var found;
  numberTable = getNumberTable();
  found = false;

  for(i = 0; i < base; i = i + 1){
    if(numberTable[i] == c){
      found = true;
    }
  }

  return found;
}
function datetimegetDateTimeFromSeconds(seconds){
  var dateTime;
  var secondsInMinute, secondsInHour, secondsInDay, days, remainder;
  var date;
  dateTime = {};

  secondsInMinute = 60;
  secondsInHour = 60*secondsInMinute;
  secondsInDay = 24*secondsInHour;
  days = Math.floor(seconds/secondsInDay);
  remainder = seconds - days*secondsInDay;

  date = datetimedayToDate(days, {});
  dateTime.year = date.year;
  dateTime.month = date.month;
  dateTime.day = date.day;

  dateTime.hours = Math.floor(remainder/secondsInHour);
  remainder = remainder - dateTime.hours*secondsInHour;
  dateTime.minutes = Math.floor(remainder/secondsInMinute);
  remainder = remainder - dateTime.minutes*secondsInMinute;
  dateTime.seconds = remainder;

  return dateTime;
}
function datetimegetSecondsFromDateTime(dateTime){
  var date;
  var seconds;
  var days;
  var secondsInMinute;
  var secondsInHour;
  var secondsInDay;
  seconds = 0;

  date = {};
  date.year = dateTime.year;
  date.month = dateTime.month;
  date.day = dateTime.day;

  days = datetimedateToDayNumber(date, {});

  secondsInMinute = 60;
  secondsInHour = 60*secondsInMinute;
  secondsInDay = 24*secondsInHour;

  seconds = seconds + secondsInDay*days;
  seconds = seconds + secondsInHour*dateTime.hours;
  seconds = seconds + secondsInMinute*dateTime.minutes;
  seconds = seconds + dateTime.seconds;

  return seconds;
}
function datetimeisLeapYear(year, success){
  var itIsLeapYear;
  if(year >= 1752){
    success.success = true;
    if(divisibleBy(year, 4)){
      if(divisibleBy(year, 100)){
        if(divisibleBy(year, 400)){
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
    success.success = false;
    itIsLeapYear = false;
    success.errorMessage = "Gregorian calendar was not in general use.";
  }

  return itIsLeapYear;
}
function datetimedayToDate(dayNr, success){
  var date;
  var remainder;
  date = {};
  success.success = true;
  remainder = {};
  remainder.doubleValue = dayNr + 79623;
  /* Days since 1752-01-01. Day 0: Thursday, 1970-01-01 */
  /* Find year. */
  date.year = datetimegetYearFromDayNr(remainder.doubleValue, remainder);

  /* Find month. */
  date.month = datetimegetMonthFromDayNr(remainder.doubleValue, date.year, remainder);

  /* Find day. */
  date.day = 1 + remainder.doubleValue;

  return date;
}
function datetimegetMonthFromDayNr(dayNr, year, remainder){
  var daysInMonth;
  var done;
  var month;
  daysInMonth = datetimegetDaysInMonth(year);
  done = false;
  month = 1;

  for(;  !done ; ){
    if(dayNr > daysInMonth[month]){
      dayNr = dayNr - daysInMonth[month];
      month = month + 1;
    }else{
      done = true;
    }
  }
  remainder.doubleValue = dayNr;

  return month;
}
function datetimegetYearFromDayNr(dayNr, remainder){
  var nrOfDays;
  var done;
  var year;
  done = false;
  year = 1752;

  for(;  !done ; ){
    if(datetimeisLeapYear(year, {})){
      nrOfDays = 366;
    }else{
      nrOfDays = 365;
    }
    if(dayNr >= nrOfDays){
      dayNr = dayNr - nrOfDays;
      year = year + 1;
    }else{
      done = true;
    }
  }
  remainder.doubleValue = dayNr;

  return year;
}
function datetimegetDaysInMonth(year){
  var daysInMonth;
  daysInMonth = [];
  daysInMonth.length = 1 + 12;

  daysInMonth[0] = 0;
  daysInMonth[1] = 31;
  if(datetimeisLeapYear(year, {})){
    daysInMonth[2] = 29;
  }else{
    daysInMonth[2] = 28;
  }
  daysInMonth[3] = 31;
  daysInMonth[4] = 30;
  daysInMonth[5] = 31;
  daysInMonth[6] = 30;
  daysInMonth[7] = 31;
  daysInMonth[8] = 31;
  daysInMonth[9] = 30;
  daysInMonth[10] = 31;
  daysInMonth[11] = 30;
  daysInMonth[12] = 31;

  return daysInMonth;
}
function datetimedateToDayNumber(date, success){
  var days;
  success.success = true;
  days =  -79623 ;
  /* Day 1752-01-01 */
  days = days + datetimedaysInYears(date.year);
  days = days + datetimedaysInMonths(date.month, date.year);
  days = days + date.day - 1;

  return days;
}
function datetimedaysInMonths(month, year){
  var daysInMonth;
  var days;
  var i;
  daysInMonth = datetimegetDaysInMonth(year);

  days = 0;
  for(i = 1; i < month; i = i + 1){
    days = days + daysInMonth[i];
  }

  return days;
}
function datetimedaysInYears(years){
  var days;
  var i;
  var nrOfDays;
  days = 0;
  for(i = 1752; i < years; i = i + 1){
    if(datetimeisLeapYear(i, {})){
      nrOfDays = 366;
    }else{
      nrOfDays = 365;
    }
    days = days + nrOfDays;
  }
  return days;
}
function datetimeisValidDate(date){
  var valid;
  var daysInMonth;
  var daysInThisMonth;
  if(date.year >= 1752){
    if(date.month >= 1 && date.month <= 12){
      daysInMonth = datetimegetDaysInMonth(date.year);
      daysInThisMonth = daysInMonth[date.month];
      if(date.day >= 1 && date.day <= daysInThisMonth){
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
function assertFalse(b, failures){
  if(b){
    failures.doubleValue = failures.doubleValue + 1;
  }
}
function assertTrue(b, failures){
  if( !b ){
    failures.doubleValue = failures.doubleValue + 1;
  }
}
function assertEquals(a, b, failures){
  if(a != b){
    failures.doubleValue = failures.doubleValue + 1;
  }
}
function assertStringEquals(a, b, failures){
  if( !stringsEqual(a, b) ){
    failures.doubleValue = failures.doubleValue + 1;
  }
}
function stringToNumberArray(string){
  var i;
  var array;
  array = [];
  array.length = string.length;

  for(i = 0; i < string.length; i = i + 1){
    array[i] = string[i].codePointAt(0);
  }
  return array;
}
function numberArrayToString(array){
  var i;
  var string;
  string = [];
  string.length = array.length;

  for(i = 0; i < array.length; i = i + 1){
    string[i] = String.fromCharCode(array[i]);
  }
  return string;
}
function stringsEqual(data1, data2){
  var equal;
  var nrEqual, i;
  equal = false;
  if(data1.length == data2.length){
    nrEqual = 0;
    for(i = 0; i < data1.length; i = i + 1){
      if(data1[i] == data2[i]){
        nrEqual = nrEqual + 1;
      }
    }
    if(nrEqual == data1.length){
      equal = true;
    }
  }else{
    equal = false;
  }

  return equal;
}
function numberArraysEqual(data1, data2){
  var equal;
  var nrEqual, i;
  equal = false;
  if(data1.length == data2.length){
    nrEqual = 0;
    for(i = 0; i < data1.length; i = i + 1){
      if(data1[i] == data2[i]){
        nrEqual = nrEqual + 1;
      }
    }
    if(nrEqual == data1.length){
      equal = true;
    }
  }else{
    equal = false;
  }

  return equal;
}
function substring(string, from, to){
  var n;
  var i;
  n = [];
  n.length = to - from;

  for(i = from; i < to; i = i + 1){
    n[i - from] = string[i];
  }

  return n;
}
function appendString(string, s){
  var newString;
  var i;
  newString = [];
  newString.length = string.length + s.length;

  for(i = 0; i < string.length; i = i + 1){
    newString[i] = string[i];
  }

  for(i = 0; i < s.length; i = i + 1){
    newString[string.length + i] = s[i];
  }

  delete(string);

  return newString;
}
function appendCharacter(string, c){
  var newString;
  var i;
  newString = [];
  newString.length = string.length + 1;

  for(i = 0; i < string.length; i = i + 1){
    newString[i] = string[i];
  }

  newString[string.length] = c;

  delete(string);

  return newString;
}
function split(toSplit, splitBy){
  var splitt;
  var next;
  var i;
  var c;
  var n;
  splitt = [];
  splitt.length = 0;

  next = [];
  next.length = 0;
  for(i = 0; i < toSplit.length; i = i + 1){
    c = toSplit[i];
    if(c == splitBy){
      n = {};
      n.string = next;
      splitt = addString(splitt, n);
      next = [];
      next.length = 0;
    }else{
      next = appendCharacter(next, c);
    }
  }

  if(next.length > 0){
    n = {};
    n.string = next;
    splitt = addString(splitt, n);
  }

  return splitt;
}
function addDecimal(list, a){
  var newlist;
  var i;
  newlist = [];
  newlist.length = list.length + 1;
  for(i = 0; i < list.length; i = i + 1){
    newlist[i] = list[i];
  }
  newlist[list.length] = a;
		
  delete(list);
		
  return newlist;
}
function addDecimalRef(list, i){
  list.list = addDecimal(list.list, i);
}
function removeDecimal(list, n){
  var newlist;
  var i;
  newlist = [];
  newlist.length = list.length - 1;

  for(i = 0; i < list.length; i = i + 1){
    if(i < n){
      newlist[i] = list[i];
    }
    if(i > n){
      newlist[i - 1] = list[i];
    }
  }
		
  delete(list);
		
  return newlist;
}
function getDecimalRef(list, i){
  return list.list[i];
}
function removeDecimalRef(list, i){
  list.list = removeDecimal(list.list, i);
}
function addString(list, a){
  var newlist;
  var i;
  newlist = [];
  newlist.length = list.length + 1;

  for(i = 0; i < list.length; i = i + 1){
    newlist[i] = list[i];
  }
  newlist[list.length] = a;
		
  delete(list);
		
  return newlist;
}
function addStringRef(list, i){
  list.list = addString(list.list, i);
}
function removeString(list, n){
  var newlist;
  var i;
  newlist = [];
  newlist.length = list.length - 1;

  for(i = 0; i < list.length; i = i + 1){
    if(i < n){
      newlist[i] = list[i];
    }
    if(i > n){
      newlist[i - 1] = list[i];
    }
  }
		
  delete(list);
		
  return newlist;
}
function getStringRef(list, i){
  return list.list[i];
}
function removeStringRef(list, i){
  list.list = removeString(list.list, i);
}
function Negate(x){
  return  -x ;
}
function Positive(x){
  return  +x ;
}
function Round(x){
  return Math.round(x);
}
function Ceil(x){
  return Math.ceil(x);
}
function Floor(x){
  return Math.floor(x);
}
function Absolute(x){
  return Math.abs(x);
}
function Logarithm(x){
  return Math.log10(x);
}
function NaturalLogarithm(x){
  return Math.log(x);
}
function Sin(x){
  return Math.sin(x);
}
function Cos(x){
  return Math.cos(x);
}
function Tan(x){
  return Math.tan(x);
}
function Asin(x){
  return Math.asin(x);
}
function Acos(x){
  return Math.acos(x);
}
function Atan(x){
  return Math.atan(x);
}
function Squareroot(x){
  return Math.sqrt(x);
}
function Exp(x){
  return Math.exp(x);
}
function divisibleBy(a, b){
  return ((a%b) == 0);
}


console.log(test());
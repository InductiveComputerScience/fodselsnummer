from math import *
def isValidNorwegianPersonalIdentificationNumber(fnummer):
  if len(fnummer) == 11.0:
    failures = DoubleReference()
    failures.doubleValue = 0.0
    d1 = charToNumber(fnummer[int(0.0)], failures)
    d2 = charToNumber(fnummer[int(1.0)], failures)
    d3 = charToNumber(fnummer[int(2.0)], failures)
    d4 = charToNumber(fnummer[int(3.0)], failures)
    d5 = charToNumber(fnummer[int(4.0)], failures)
    d6 = charToNumber(fnummer[int(5.0)], failures)
    d7 = charToNumber(fnummer[int(6.0)], failures)
    d8 = charToNumber(fnummer[int(7.0)], failures)
    d9 = charToNumber(fnummer[int(8.0)], failures)
    d10 = charToNumber(fnummer[int(9.0)], failures)
    d11 = charToNumber(fnummer[int(10.0)], failures)
    if failures.doubleValue == 0.0:
      aDatetimeDate = getDateFromNorwegianPersonalIdentificationNumber(fnummer, failures)
      if datetimeisValidDate(aDatetimeDate):
        if failures.doubleValue == 0.0:
          k1 = d1*3.0 + d2*7.0 + d3*6.0 + d4*1.0 + d5*8.0 + d6*9.0 + d7*4.0 + d8*5.0 + d9*2.0
          k1 = k1 % 11.0
          if k1 != 0.0:
            k1 = 11.0 - k1
          if k1 == 10.0:
            failures.doubleValue = failures.doubleValue + 1.0
          k2 = d1*5.0 + d2*4.0 + d3*3.0 + d4*2.0 + d5*7.0 + d6*6.0 + d7*5.0 + d8*4.0 + d9*3.0 + k1*2.0
          k2 = k2 % 11.0
          if k2 != 0.0:
            k2 = 11.0 - k2
          if k2 == 10.0:
            failures.doubleValue = failures.doubleValue + 1.0
          if k1 == d10 and k2 == d11 and failures.doubleValue == 0.0:
            gyldig = True
          else:
            gyldig = False
        else:
          gyldig = False
      else:
        gyldig = False
    else:
      gyldig = False
  else:
    gyldig = False

  return gyldig

def getDateFromNorwegianPersonalIdentificationNumber(fnummer, failures):
  aDatetimeDate = datetimeDate()

  d1 = charToNumber(fnummer[int(0.0)], failures)
  d2 = charToNumber(fnummer[int(1.0)], failures)
  d3 = charToNumber(fnummer[int(2.0)], failures)
  d4 = charToNumber(fnummer[int(3.0)], failures)
  d5 = charToNumber(fnummer[int(4.0)], failures)
  d6 = charToNumber(fnummer[int(5.0)], failures)
  d7 = charToNumber(fnummer[int(6.0)], failures)
  d8 = charToNumber(fnummer[int(7.0)], failures)
  d9 = charToNumber(fnummer[int(8.0)], failures)

  if failures.doubleValue == 0.0:
    individnummer = d7*100.0 + d8*10.0 + d9
    day = d1*10.0 + d2
    month = d3*10.0 + d4
    year = d5*10.0 + d6
    if individnummer >= 0.0 and individnummer <= 499.0:
      year = year + 1900.0
    elif individnummer >= 500.0 and individnummer <= 749.0 and year >= 54.0 and year <= 99.0:
      year = year + 1800.0
    elif individnummer >= 900.0 and individnummer <= 999.0 and year >= 40.0 and year <= 99.0:
      year = year + 1900.0
    elif individnummer >= 500.0 and individnummer <= 999.0 and year >= 0.0 and year <= 39.0:
      year = year + 1900.0
    else:
      failures.doubleValue = failures.doubleValue + 1.0
    aDatetimeDate.year = year
    aDatetimeDate.month = month
    aDatetimeDate.day = day

  return aDatetimeDate

def charToNumber(c, failures):
  if isNumber(c, 10.0):
    val = getDecimalFromSingleDecimalDigit(c, 10.0)
  else:
    val = 0.0
    failures.doubleValue = failures.doubleValue + 1.0

  return val

def test1():
  failures = DoubleReference()
  failures.doubleValue = 0.0

  assertTrue(isValidNorwegianPersonalIdentificationNumber("10061270707"), failures)

  return failures.doubleValue

def test():
  failures = 0.0

  failures = failures + test1()

  return failures

class BooleanReference:
  booleanValue = None

class DoubleReference:
  doubleValue = None

class StringReference:
  string = None

class StringToDecimalResult:
  result = None
  feilmelding = None
  success = None

def decimalToString(decimal):
  return numberToString(decimal, 10.0)

def numberToString(decimal, base):
  string =  [None]*int(0.0)

  digits = getDigits(base)

  # Find digitPosition:
  digitPosition = getDigitPosition(decimal, base)

  decimal = round(decimal*base**( -digitPosition  + digits - 1.0))

  hasPrintedPoint = False

  # Print leading zeros.
  if digitPosition < 0.0:
    string = appendCharacter(string, '0')
    string = appendCharacter(string, '.')
    hasPrintedPoint = True
    i = 0.0
    while i <  -digitPosition  - 1.0:
      string = appendCharacter(string, '0')
      i = i + 1.0
    

  # Print number.
  i = 0.0
  while i < digits:
    d = floor(decimal/base**(digits - i - 1.0))
    if  not hasPrintedPoint  and digitPosition - i + 1.0 == 0.0:
      if decimal != 0.0:
        string = appendCharacter(string, '.')
      hasPrintedPoint = True
    if decimal == 0.0 and hasPrintedPoint:
      pass
    else:
      string = appendCharacter(string, getSingleDigitFromNumber(d, base))
    decimal = decimal - d*base**(digits - i - 1.0)
    i = i + 1.0
  

  # Print trailing zeros.
  i = 0.0
  while i < digitPosition - digits + 1.0:
    string = appendCharacter(string, '0')
    i = i + 1.0
  

  # Done
  return string

def getDigits(base):
  t = 10.0**15.0
  return floor(log10(t)/log10(base))

def getDigitPosition(decimal, base):
  power = ceil(log10(decimal)/log10(base))

  t = decimal*base**( -power )
  if t < base and t >= 1.0:
    pass
  elif t >= base:
    power = power + 1.0
  elif t < 1.0:
    power = power - 1.0
  return power

def getSingleDigitFromNumber(c, base):
  numberTable = getNumberTable()

  if c > base - 1.0:
    retc = '?'
  else:
    retc = numberTable[int(c)]

  return retc

def getNumberTable():
  numberTable =  [None]*int(16.0)
  numberTable[int(0.0)] = '0'
  numberTable[int(1.0)] = '1'
  numberTable[int(2.0)] = '2'
  numberTable[int(3.0)] = '3'
  numberTable[int(4.0)] = '4'
  numberTable[int(5.0)] = '5'
  numberTable[int(6.0)] = '6'
  numberTable[int(7.0)] = '7'
  numberTable[int(8.0)] = '8'
  numberTable[int(9.0)] = '9'
  numberTable[int(10.0)] = 'A'
  numberTable[int(11.0)] = 'B'
  numberTable[int(12.0)] = 'C'
  numberTable[int(13.0)] = 'D'
  numberTable[int(14.0)] = 'E'
  numberTable[int(15.0)] = 'F'
  return numberTable

def stringToDecimal(string):
  return stringToDecimalForBase(string, 10.0)

def stringToDecimalForBase(string, base):
  stringToDecimalResult = StringToDecimalResult()
  stringToDecimalResult.success = True
  i = 0.0
  isPositive = True
  beforeDecimalPoint = 0.0
  afterDecimalPoint = 0.0
  n = 0.0
  validCharacters = 0.0

  if base >= 2.0 and base <= 16.0:
    j = 0.0
    while j < len(string):
      c = string[int(j)]
      if isNumber(c, base) or c == '.' or c == '-':
        validCharacters = validCharacters + 1.0
      j = j + 1.0
    
    if validCharacters == len(string):
      if len(string) > 0.0:
        c = string[int(i)]
        if c == '-':
          isPositive = False
          i = i + 1.0
        if i < len(string):
          c = string[int(i)]
          if isNumber(c, base):
            while isNumber(c, base) and (i < len(string)):
              beforeDecimalPoint = beforeDecimalPoint + 1.0
              i = i + 1.0
              if i < len(string):
                c = string[int(i)]
            
            if i < len(string):
              c = string[int(i)]
              if c == '.':
                i = i + 1.0
                if i < len(string):
                  c = string[int(i)]
                  while isNumber(c, base) and (i < len(string)):
                    afterDecimalPoint = afterDecimalPoint + 1.0
                    i = i + 1.0
                    if i < len(string):
                      c = string[int(i)]
                  
                else:
                  stringToDecimalResult.success = False
                  stringToDecimalResult.feilmelding = "Number must have digits after the decimal point."
          else:
            stringToDecimalResult.success = False
            stringToDecimalResult.feilmelding = "Number must start with digits (for negative numbers, after the optional negative sign)."
        if stringToDecimalResult.success != False:
          i = 0.0
          if  not isPositive :
            i = 1.0
          j = 0.0
          while j < beforeDecimalPoint:
            c = string[int(i)]
            i = i + 1.0
            d = getDecimalFromSingleDecimalDigit(c, base)
            n = n + d*base**(beforeDecimalPoint - j - 1.0)
            j = j + 1.0
          
          if afterDecimalPoint > 0.0:
            i = i + 1.0
            j = 0.0
            while j < afterDecimalPoint:
              c = string[int(i)]
              i = i + 1.0
              d = getDecimalFromSingleDecimalDigit(c, base)
              n = n + d*base**(0.0 - j - 1.0)
              j = j + 1.0
            
          if  not isPositive :
            n =  -n 
          stringToDecimalResult.result = n
          stringToDecimalResult.success = True
      else:
        stringToDecimalResult.success = False
        stringToDecimalResult.feilmelding = "String has no content."
    else:
      stringToDecimalResult.success = False
      stringToDecimalResult.feilmelding = "String contains invalid character."
  else:
    stringToDecimalResult.success = False
    stringToDecimalResult.feilmelding = "Base must be from 2 to 16."

  return stringToDecimalResult

def getDecimalFromSingleDecimalDigit(c, base):
  numberTable = getNumberTable()
  position = 0.0

  i = 0.0
  while i < base:
    if numberTable[int(i)] == c:
      position = i
    i = i + 1.0
  

  return position

def isNumber(c, base):
  numberTable = getNumberTable()
  found = False

  i = 0.0
  while i < base:
    if numberTable[int(i)] == c:
      found = True
    i = i + 1.0
  

  return found

class datetimeDateTime:
  year = None
  month = None
  day = None
  hours = None
  minutes = None
  seconds = None

class datetimeSuccess:
  success = None
  errorMessage = None

class datetimeDate:
  year = None
  month = None
  day = None

def datetimegetDateTimeFromSeconds(seconds):
  dateTime = datetimeDateTime()

  secondsInMinute = 60.0
  secondsInHour = 60.0*secondsInMinute
  secondsInDay = 24.0*secondsInHour
  days = floor(seconds/secondsInDay)
  remainder = seconds - days*secondsInDay

  date = datetimedayToDate(days, datetimeSuccess())
  dateTime.year = date.year
  dateTime.month = date.month
  dateTime.day = date.day

  dateTime.hours = floor(remainder/secondsInHour)
  remainder = remainder - dateTime.hours*secondsInHour
  dateTime.minutes = floor(remainder/secondsInMinute)
  remainder = remainder - dateTime.minutes*secondsInMinute
  dateTime.seconds = remainder

  return dateTime

def datetimegetSecondsFromDateTime(dateTime):
  seconds = 0.0

  date = datetimeDate()
  date.year = dateTime.year
  date.month = dateTime.month
  date.day = dateTime.day

  days = datetimedateToDayNumber(date, datetimeSuccess())

  secondsInMinute = 60.0
  secondsInHour = 60.0*secondsInMinute
  secondsInDay = 24.0*secondsInHour

  seconds = seconds + secondsInDay*days
  seconds = seconds + secondsInHour*dateTime.hours
  seconds = seconds + secondsInMinute*dateTime.minutes
  seconds = seconds + dateTime.seconds

  return seconds

def datetimeisLeapYear(year, success):
  if year >= 1752.0:
    success.success = True
    if divisibleBy(year, 4.0):
      if divisibleBy(year, 100.0):
        if divisibleBy(year, 400.0):
          itIsLeapYear = True
        else:
          itIsLeapYear = False
      else:
        itIsLeapYear = True
    else:
      itIsLeapYear = False
  else:
    success.success = False
    itIsLeapYear = False
    success.errorMessage = "Gregorian calendar was not in general use."

  return itIsLeapYear

def datetimedayToDate(dayNr, success):
  date = datetimeDate()
  success.success = True
  remainder = DoubleReference()
  remainder.doubleValue = dayNr + 79623.0
  # Days since 1752-01-01. Day 0: Thursday, 1970-01-01
  # Find year.
  date.year = datetimegetYearFromDayNr(remainder.doubleValue, remainder)

  # Find month.
  date.month = datetimegetMonthFromDayNr(remainder.doubleValue, date.year, remainder)

  # Find day.
  date.day = 1.0 + remainder.doubleValue

  return date

def datetimegetMonthFromDayNr(dayNr, year, remainder):
  daysInMonth = datetimegetDaysInMonth(year)
  done = False
  month = 1.0

  while  not done :
    if dayNr > daysInMonth[int(month)]:
      dayNr = dayNr - daysInMonth[int(month)]
      month = month + 1.0
    else:
      done = True
  
  remainder.doubleValue = dayNr

  return month

def datetimegetYearFromDayNr(dayNr, remainder):
  done = False
  year = 1752.0

  while  not done :
    if datetimeisLeapYear(year, datetimeSuccess()):
      nrOfDays = 366.0
    else:
      nrOfDays = 365.0
    if dayNr >= nrOfDays:
      dayNr = dayNr - nrOfDays
      year = year + 1.0
    else:
      done = True
  
  remainder.doubleValue = dayNr

  return year

def datetimegetDaysInMonth(year):
  daysInMonth =  [None]*int(1.0 + 12.0)

  daysInMonth[int(0.0)] = 0.0
  daysInMonth[int(1.0)] = 31.0
  if datetimeisLeapYear(year, datetimeSuccess()):
    daysInMonth[int(2.0)] = 29.0
  else:
    daysInMonth[int(2.0)] = 28.0
  daysInMonth[int(3.0)] = 31.0
  daysInMonth[int(4.0)] = 30.0
  daysInMonth[int(5.0)] = 31.0
  daysInMonth[int(6.0)] = 30.0
  daysInMonth[int(7.0)] = 31.0
  daysInMonth[int(8.0)] = 31.0
  daysInMonth[int(9.0)] = 30.0
  daysInMonth[int(10.0)] = 31.0
  daysInMonth[int(11.0)] = 30.0
  daysInMonth[int(12.0)] = 31.0

  return daysInMonth

def datetimedateToDayNumber(date, success):
  success.success = True
  days =  -79623.0 
  # Day 1752-01-01
  days = days + datetimedaysInYears(date.year)
  days = days + datetimedaysInMonths(date.month, date.year)
  days = days + date.day - 1.0

  return days

def datetimedaysInMonths(month, year):
  daysInMonth = datetimegetDaysInMonth(year)

  days = 0.0
  i = 1.0
  while i < month:
    days = days + daysInMonth[int(i)]
    i = i + 1.0
  

  return days

def datetimedaysInYears(years):
  days = 0.0
  i = 1752.0
  while i < years:
    if datetimeisLeapYear(i, datetimeSuccess()):
      nrOfDays = 366.0
    else:
      nrOfDays = 365.0
    days = days + nrOfDays
    i = i + 1.0
  
  return days

def datetimeisValidDate(date):
  if date.year >= 1752.0:
    if date.month >= 1.0 and date.month <= 12.0:
      daysInMonth = datetimegetDaysInMonth(date.year)
      daysInThisMonth = daysInMonth[int(date.month)]
      if date.day >= 1.0 and date.day <= daysInThisMonth:
        valid = True
      else:
        valid = False
    else:
      valid = False
  else:
    valid = False

  return valid

def assertFalse(b, failures):
  if b:
    failures.doubleValue = failures.doubleValue + 1.0

def assertTrue(b, failures):
  if  not b :
    failures.doubleValue = failures.doubleValue + 1.0

def assertEquals(a, b, failures):
  if a != b:
    failures.doubleValue = failures.doubleValue + 1.0

def assertStringEquals(a, b, failures):
  if  not stringsEqual(a, b) :
    failures.doubleValue = failures.doubleValue + 1.0

def stringToNumberArray(string):
  array =  [None]*int(len(string))

  i = 0.0
  while i < len(string):
    array[int(i)] = ord(string[int(i)])
    i = i + 1.0
  
  return array

def numberArrayToString(array):
  string =  [None]*int(len(array))

  i = 0.0
  while i < len(array):
    string[int(i)] = chr(int(array[int(i)]))
    i = i + 1.0
  
  return string

def stringsEqual(data1, data2):
  equal = False
  if len(data1) == len(data2):
    nrEqual = 0.0
    i = 0.0
    while i < len(data1):
      if data1[int(i)] == data2[int(i)]:
        nrEqual = nrEqual + 1.0
      i = i + 1.0
    
    if nrEqual == len(data1):
      equal = True
  else:
    equal = False

  return equal

def numberArraysEqual(data1, data2):
  equal = False
  if len(data1) == len(data2):
    nrEqual = 0.0
    i = 0.0
    while i < len(data1):
      if data1[int(i)] == data2[int(i)]:
        nrEqual = nrEqual + 1.0
      i = i + 1.0
    
    if nrEqual == len(data1):
      equal = True
  else:
    equal = False

  return equal

def substring(string, fromx, to):
  n =  [None]*int(to - fromx)

  i = fromx
  while i < to:
    n[int(i - fromx)] = string[int(i)]
    i = i + 1.0
  

  return n

def appendString(string, s):
  newString =  [None]*int(len(string) + len(s))

  i = 0.0
  while i < len(string):
    newString[int(i)] = string[int(i)]
    i = i + 1.0
  

  i = 0.0
  while i < len(s):
    newString[int(len(string) + i)] = s[int(i)]
    i = i + 1.0
  

  del(string)

  return newString

def appendCharacter(string, c):
  newString =  [None]*int(len(string) + 1.0)

  i = 0.0
  while i < len(string):
    newString[int(i)] = string[int(i)]
    i = i + 1.0
  

  newString[int(len(string))] = c

  del(string)

  return newString

def split(toSplit, splitBy):
  splitt =  [None]*int(0.0)

  next =  [None]*int(0.0)
  i = 0.0
  while i < len(toSplit):
    c = toSplit[int(i)]
    if c == splitBy:
      n = StringReference()
      n.string = next
      splitt = addString(splitt, n)
      next =  [None]*int(0.0)
    else:
      next = appendCharacter(next, c)
    i = i + 1.0
  

  if len(next) > 0.0:
    n = StringReference()
    n.string = next
    splitt = addString(splitt, n)

  return splitt

class DecimalListRef:
  list = None

class StringListRef:
  list = None

def addDecimal(list, a):
  newlist =  [None]*int(len(list) + 1.0)
  i = 0.0
  while i < len(list):
    newlist[int(i)] = list[int(i)]
    i = i + 1.0
  
  newlist[int(len(list))] = a
		
  del(list)
		
  return newlist

def addDecimalRef(list, i):
  list.list = addDecimal(list.list, i)

def removeDecimal(list, n):
  newlist =  [None]*int(len(list) - 1.0)

  i = 0.0
  while i < len(list):
    if i < n:
      newlist[int(i)] = list[int(i)]
    if i > n:
      newlist[int(i - 1.0)] = list[int(i)]
    i = i + 1.0
  
		
  del(list)
		
  return newlist

def getDecimalRef(list, i):
  return list.list[int(i)]

def removeDecimalRef(list, i):
  list.list = removeDecimal(list.list, i)

def addString(list, a):
  newlist =  [None]*int(len(list) + 1.0)

  i = 0.0
  while i < len(list):
    newlist[int(i)] = list[int(i)]
    i = i + 1.0
  
  newlist[int(len(list))] = a
		
  del(list)
		
  return newlist

def addStringRef(list, i):
  list.list = addString(list.list, i)

def removeString(list, n):
  newlist =  [None]*int(len(list) - 1.0)

  i = 0.0
  while i < len(list):
    if i < n:
      newlist[int(i)] = list[int(i)]
    if i > n:
      newlist[int(i - 1.0)] = list[int(i)]
    i = i + 1.0
  
		
  del(list)
		
  return newlist

def getStringRef(list, i):
  return list.list[int(i)]

def removeStringRef(list, i):
  list.list = removeString(list.list, i)

def Negate(x):
  return  -x 

def Positive(x):
  return  +x 

def Round(x):
  return round(x)

def Ceil(x):
  return ceil(x)

def Floor(x):
  return floor(x)

def Absolute(x):
  return fabs(x)

def Logarithm(x):
  return log10(x)

def NaturalLogarithm(x):
  return log(x)

def Sin(x):
  return sin(x)

def Cos(x):
  return cos(x)

def Tan(x):
  return tan(x)

def Asin(x):
  return asin(x)

def Acos(x):
  return acos(x)

def Atan(x):
  return atan(x)

def Squareroot(x):
  return sqrt(x)

def Exp(x):
  return exp(x)

def divisibleBy(a, b):
  return ((a % b) == 0.0)



print(test())
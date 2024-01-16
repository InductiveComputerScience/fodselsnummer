# Downloaded from https://repo.progsbase.com - Code Developed Using progsbase.

from math import *
def IsValidNorwegianPersonalIdentificationNumber(fnummer, message):

  if len(fnummer) == 11.0:
    gyldig = True
    i = 0.0
    while i < len(fnummer):
      if charIsNumber(fnummer[int(i)]):
        pass
      else:
        gyldig = False
      i = i + 1.0
    

    if gyldig:
      d1 = charCharacterToDecimalDigit(fnummer[int(0.0)])
      d2 = charCharacterToDecimalDigit(fnummer[int(1.0)])
      d3 = charCharacterToDecimalDigit(fnummer[int(2.0)])
      d4 = charCharacterToDecimalDigit(fnummer[int(3.0)])
      d5 = charCharacterToDecimalDigit(fnummer[int(4.0)])
      d6 = charCharacterToDecimalDigit(fnummer[int(5.0)])
      d7 = charCharacterToDecimalDigit(fnummer[int(6.0)])
      d8 = charCharacterToDecimalDigit(fnummer[int(7.0)])
      d9 = charCharacterToDecimalDigit(fnummer[int(8.0)])
      d10 = charCharacterToDecimalDigit(fnummer[int(9.0)])
      d11 = charCharacterToDecimalDigit(fnummer[int(10.0)])

      dateRef = DateReference()
      gyldig = GetDateFromNorwegianPersonalIdentificationNumber(fnummer, dateRef, message)

      if gyldig:
        if IsValidDate(dateRef.date, message):
          k1 = d1*3.0 + d2*7.0 + d3*6.0 + d4*1.0 + d5*8.0 + d6*9.0 + d7*4.0 + d8*5.0 + d9*2.0
          k1 = k1 % 11.0
          if k1 != 0.0:
            k1 = 11.0 - k1
          if k1 == 10.0:
            gyldig = False
            message.string = "Control digit 1 is 10, which is invalid."

          if gyldig:
            k2 = d1*5.0 + d2*4.0 + d3*3.0 + d4*2.0 + d5*7.0 + d6*6.0 + d7*5.0 + d8*4.0 + d9*3.0 + k1*2.0
            k2 = k2 % 11.0
            if k2 != 0.0:
              k2 = 11.0 - k2
            if k2 == 10.0:
              gyldig = False
              message.string = "Control digit 2 is 10, which is invalid."

            if gyldig:
              if k1 == d10:
                if k2 == d11:
                  gyldig = True
                else:
                  gyldig = False
                  message.string = "Check of control digit 2 failed."
              else:
                gyldig = False
                message.string = "Check of control digit 1 failed."
        else:
          gyldig = False
          message.string = "The date is not a valid date."
    else:
      gyldig = False
      message.string = "Each character must be a decimal digit."
  else:
    gyldig = False
    message.string = "Must be exactly 11 digits long."

  return gyldig

def GetDateFromNorwegianPersonalIdentificationNumber(fnummer, dateRef, message):

  success = True
  dateRef.date = Date()

  if len(fnummer) == 11.0:
    i = 0.0
    while i < len(fnummer):
      if charIsNumber(fnummer[int(i)]):
        pass
      else:
        success = False
      i = i + 1.0
    

    if success:
      d1 = charCharacterToDecimalDigit(fnummer[int(0.0)])
      d2 = charCharacterToDecimalDigit(fnummer[int(1.0)])
      d3 = charCharacterToDecimalDigit(fnummer[int(2.0)])
      d4 = charCharacterToDecimalDigit(fnummer[int(3.0)])
      d5 = charCharacterToDecimalDigit(fnummer[int(4.0)])
      d6 = charCharacterToDecimalDigit(fnummer[int(5.0)])
      d7 = charCharacterToDecimalDigit(fnummer[int(6.0)])
      d8 = charCharacterToDecimalDigit(fnummer[int(7.0)])
      d9 = charCharacterToDecimalDigit(fnummer[int(8.0)])

      # Individnummer
      individnummer = d7*100.0 + d8*10.0 + d9

      # Make date
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
        year = year + 2000.0
      else:
        success = False
        message.string = "Invalid combination of individnummer and year."

      if success:
        dateRef.date.year = year
        dateRef.date.month = month
        dateRef.date.day = day
    else:
      message.string = "Each character must be a decimal digit."
  else:
    message.string = "Must be exactly 11 digits long."

  return success

def Test1(failures):

  message = StringReference()

  success = IsValidNorwegianPersonalIdentificationNumber("10061270707", message)
  AssertTrue(success, failures)

  dateRef = DateReference()

  success = GetDateFromNorwegianPersonalIdentificationNumber("11028559912", dateRef, message)
  AssertTrue(success, failures)
  AssertEquals(dateRef.date.year, 1885.0, failures)

  success = GetDateFromNorwegianPersonalIdentificationNumber("01019949768", dateRef, message)
  AssertTrue(success, failures)
  AssertEquals(dateRef.date.year, 1999.0, failures)

  success = GetDateFromNorwegianPersonalIdentificationNumber("01010099931", dateRef, message)
  AssertTrue(success, failures)
  AssertEquals(dateRef.date.year, 2000.0, failures)

def test():

  failures = CreateNumberReference(0.0)

  Test1(failures)

  return failures.numberValue

class BooleanArrayReference:
  booleanArray = None

class BooleanReference:
  booleanValue = None

class CharacterReference:
  characterValue = None

class NumberArrayReference:
  numberArray = None

class NumberReference:
  numberValue = None

class StringArrayReference:
  stringArray = None

class StringReference:
  string = None

def CreateBooleanReference(value):

  ref = BooleanReference()
  ref.booleanValue = value

  return ref

def CreateBooleanArrayReference(value):

  ref = BooleanArrayReference()
  ref.booleanArray = value

  return ref

def CreateBooleanArrayReferenceLengthValue(length, value):

  ref = BooleanArrayReference()
  ref.booleanArray =  [None]*int(length)

  i = 0.0
  while i < length:
    ref.booleanArray[int(i)] = value
    i = i + 1.0
  

  return ref

def FreeBooleanArrayReference(booleanArrayReference):
  booleanArrayReference.booleanArray = None
  booleanArrayReference = None

def CreateCharacterReference(value):

  ref = CharacterReference()
  ref.characterValue = value

  return ref

def CreateNumberReference(value):

  ref = NumberReference()
  ref.numberValue = value

  return ref

def CreateNumberArrayReference(value):

  ref = NumberArrayReference()
  ref.numberArray = value

  return ref

def CreateNumberArrayReferenceLengthValue(length, value):

  ref = NumberArrayReference()
  ref.numberArray =  [None]*int(length)

  i = 0.0
  while i < length:
    ref.numberArray[int(i)] = value
    i = i + 1.0
  

  return ref

def FreeNumberArrayReference(numberArrayReference):
  numberArrayReference.numberArray = None
  numberArrayReference = None

def CreateStringReference(value):

  ref = StringReference()
  ref.string = value

  return ref

def CreateStringReferenceLengthValue(length, value):

  ref = StringReference()
  ref.string =  [None]*int(length)

  i = 0.0
  while i < length:
    ref.string[int(i)] = value
    i = i + 1.0
  

  return ref

def FreeStringReference(stringReference):
  stringReference.string = None
  stringReference = None

def CreateStringArrayReference(strings):

  ref = StringArrayReference()
  ref.stringArray = strings

  return ref

def CreateStringArrayReferenceLengthValue(length, value):

  ref = StringArrayReference()
  ref.stringArray =  [None]*int(length)

  i = 0.0
  while i < length:
    ref.stringArray[int(i)] = CreateStringReference(value)
    i = i + 1.0
  

  return ref

def FreeStringArrayReference(stringArrayReference):

  i = 0.0
  while i < len(stringArrayReference.stringArray):
    stringArrayReference.stringArray[int(i)] = None
    i = i + 1.0
  
  stringArrayReference.stringArray = None
  stringArrayReference = None

class Date:
  year = None
  month = None
  day = None

class DateReference:
  date = None

class Interval:
  first = None
  last = None

class DateTimeTimezone:
  dateTime = None
  timezoneOffsetSeconds = None

class DateTimeTimezoneReference:
  dateTimeTimezone = None

class DateTime:
  date = None
  hours = None
  minutes = None
  seconds = None

class DateTimeReference:
  dateTime = None

def CreateDate(year, month, day):

  date = Date()

  date.year = year
  date.month = month
  date.day = day

  return date

def IsLeapYearWithCheck(year, isLeapYearReference, message):

  if year >= 1752.0:
    success = True
    itIsLeapYear = IsLeapYear(year)
  else:
    success = False
    itIsLeapYear = False
    message.string = "Gregorian calendar was not in general use."

  isLeapYearReference.booleanValue = itIsLeapYear
  return success

def IsLeapYear(year):

  if DivisibleBy(year, 4.0):
    if DivisibleBy(year, 100.0):
      if DivisibleBy(year, 400.0):
        itIsLeapYear = True
      else:
        itIsLeapYear = False
    else:
      itIsLeapYear = True
  else:
    itIsLeapYear = False

  return itIsLeapYear

def DayToDateWithCheck(dayNr, dateReference, message):

  if dayNr >=  -79623.0:
    date = Date()
    remainder = NumberReference()
    remainder.numberValue = dayNr + 79623.0
    # Days since 1752-01-01. Day 0: Thursday, 1970-01-01
    # Find year.
    date.year = GetYearFromDayNr(remainder.numberValue, remainder)

    # Find month.
    date.month = GetMonthFromDayNr(remainder.numberValue, date.year, remainder)

    # Find day.
    date.day = 1.0 + remainder.numberValue

    dateReference.date = date
    success = True
  else:
    success = False
    message.string = "Gregorian calendar was not in general use before 1752."

  return success

def DayToDate(dayNr):

  dateRef = DateReference()
  message = StringReference()

  success = DayToDateWithCheck(dayNr, dateRef, message)
  if success:
    date = dateRef.date
    dateRef = None
    FreeStringReference(message)
  else:
    date = CreateDate(1970.0, 1.0, 1.0)

  return date

def GetMonthFromDayNrWithCheck(dayNr, year, monthReference, remainderReference, message):

  if dayNr >=  -79623.0:
    month = GetMonthFromDayNr(dayNr, year, remainderReference)
    monthReference.numberValue = month
    success = True
  else:
    success = False
    message.string = "Gregorian calendar not in general use before 1752."

  return success

def GetMonthFromDayNr(dayNr, year, remainderReference):

  daysInMonth = GetDaysInMonth(year)
  done = False
  month = 1.0

  while  not done :
    if dayNr >= daysInMonth[int(month)]:
      dayNr = dayNr - daysInMonth[int(month)]
      month = month + 1.0
    else:
      done = True
  
  remainderReference.numberValue = dayNr

  return month

def GetYearFromDayNrWithCheck(dayNr, yearReference, remainder, message):

  if dayNr >= 0.0:
    success = True
    year = GetYearFromDayNr(dayNr, remainder)
    yearReference.numberValue = year
  else:
    success = False
    message.string = "Day number must be 0 or higher. 0 is 1752-01-01."

  return success

def GetYearFromDayNr(dayNr, remainder):

  done = False
  year = 1752.0

  while  not done :
    if IsLeapYear(year):
      nrOfDays = 366.0
    else:
      nrOfDays = 365.0

    if dayNr >= nrOfDays:
      # First day is 0.
      dayNr = dayNr - nrOfDays
      year = year + 1.0
    else:
      done = True
  
  remainder.numberValue = dayNr

  return year

def DaysBetweenDates(A, B):

  daysA = DateToDays(A)
  daysB = DateToDays(B)

  daysBetween = daysB - daysA

  return daysBetween

def GetDaysInMonthWithCheck(year, daysInMonthReference, message):

  date = CreateDate(year, 1.0, 1.0)

  success = IsValidDate(date, message)
  if success:
    daysInMonth = GetDaysInMonth(year)

    daysInMonthReference.numberArray = daysInMonth

  return success

def GetDaysInMonth(year):

  daysInMonth =  [None]*int(1.0 + 12.0)

  daysInMonth[int(0.0)] = 0.0
  daysInMonth[int(1.0)] = 31.0

  if IsLeapYear(year):
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

def DateToDaysWithCheck(date, dayNumberReferenceReference, message):

  success = IsValidDate(date, message)
  if success:
    days = DateToDays(date)
    dayNumberReferenceReference.numberValue = days

  return success

def DateToDays(date):

  # Day 1752-01-01
  days =  -79623.0

  days = days + DaysInYears(date.year)
  days = days + DaysInMonths(date.month, date.year)
  days = days + date.day - 1.0

  return days

def DateToWeekdayNumberWithCheck(date, weekDayNumberReference, message):

  success = IsValidDate(date, message)
  if success:
    weekDay = DateToWeekdayNumber(date)
    weekDayNumberReference.numberValue = weekDay

  return success

def DateToWeekdayNumber(date):

  days = DateToDays(date)

  days = days + 79623.0
  days = days + 5.0

  weekDay = days % 7.0 + 1.0

  return weekDay

def DateToWeeknumber(date, yearRef):

  week1Start = CopyDate(date)

  week1Start.day = 1.0
  week1Start.month = 1.0
  weekday = DateToWeekdayNumber(week1Start)

  # Set week1Start to the start of the Week 1.
  # If monday, week 1 begins on Jan. 1st
  if weekday == 1.0:
    week1Start.day = 1.0
  # If tuesday, week 1 begins on Dec. 31st
  if weekday == 2.0:
    week1Start.year = week1Start.year - 1.0
    week1Start.month = 12.0
    week1Start.day = 31.0
  # If wednesday, week 1 begins on Dec. 30th
  if weekday == 3.0:
    week1Start.year = week1Start.year - 1.0
    week1Start.month = 12.0
    week1Start.day = 30.0
  # If thursday, week 1 begins on Dec. 29th
  if weekday == 4.0:
    week1Start.year = week1Start.year - 1.0
    week1Start.month = 12.0
    week1Start.day = 29.0
  # If friday, week 1 begins on Jan. 4th
  if weekday == 5.0:
    week1Start.day = 4.0
  # If saturday, week 1 begins on Jan. 3rd
  if weekday == 6.0:
    week1Start.day = 3.0
  # If sunday, week 1 begins on Jan. 2nd
  if weekday == 7.0:
    week1Start.day = 2.0

  days = DateToDays(date)
  daysWeek1Start = DateToDays(week1Start)

  if days >= daysWeek1Start:
    weekNumber = 1.0 + floor((days - daysWeek1Start)/7.0)

    if weekNumber >= 1.0 and weekNumber <= 52.0:
      # Week is between 1 and 52 in the current year.
      yearRef.numberValue = date.year
    else:
      # Is week nr 53 or 1 next year?
      newyears = CopyDate(date)
      newyears.month = 12.0
      newyears.day = 31.0
      weekdayNewYears = DateToWeekdayNumber(newyears)
      if weekdayNewYears == 1.0 or weekdayNewYears == 2.0 or weekdayNewYears == 3.0:
        # Week 1 next year.
        weekNumber = 1.0
        yearRef.numberValue = date.year + 1.0
      else:
        # Week 53
        yearRef.numberValue = date.year
      newyears = None
  else:
    # Week is in previous year. Either 52nd or 53rd.
    newyears = CopyDate(date)
    newyears.month = 12.0
    newyears.day = 31.0
    newyears.year = date.year - 1.0
    weekNumber = DateToWeeknumber(newyears, yearRef)
    newyears = None

  week1Start = None

  return weekNumber

def DaysInMonthsWithCheck(month, year, daysInMonthsReference, message):

  date = CreateDate(year, month, 1.0)

  success = IsValidDate(date, message)
  if success:
    days = DaysInMonths(month, year)

    daysInMonthsReference.numberValue = days

  return success

def DaysInMonths(month, year):

  daysInMonth = GetDaysInMonth(year)

  days = 0.0
  i = 1.0
  while i < month:
    days = days + daysInMonth[int(i)]
    i = i + 1.0
  

  return days

def DaysInYearsWithCheck(years, daysReference, message):

  date = CreateDate(years, 1.0, 1.0)

  success = IsValidDate(date, message)
  if success:
    days = DaysInYears(years)
    daysReference.numberValue = days

  return success

def DaysInYears(years):

  days = 0.0
  i = 1752.0
  while i < years:
    if IsLeapYear(i):
      nrOfDays = 366.0
    else:
      nrOfDays = 365.0
    days = days + nrOfDays
    i = i + 1.0
  

  return days

def IsValidDate(date, message):

  if date.year >= 1752.0:
    if date.month >= 1.0 and date.month <= 12.0:
      daysInMonth = GetDaysInMonth(date.year)
      daysInThisMonth = daysInMonth[int(date.month)]
      if date.day >= 1.0 and date.day <= daysInThisMonth:
        valid = True
      else:
        valid = False
        message.string = "The month does not have the given day number."
    else:
      valid = False
      message.string = "Month must be between 1 and 12, inclusive."
  else:
    valid = False
    message.string = "Gregorian calendar was not in general use before 1752."

  return valid

def AddDaysToDate(date, days, message):

  daysRef = NumberReference()
  success = DateToDaysWithCheck(date, daysRef, message)

  if success:
    n = daysRef.numberValue
    n = n + days

    dateReference = DateReference()
    success = DayToDateWithCheck(n, dateReference, message)
    if success:
      AssignDate(date, dateReference.date)

  return success

def AssignDate(a, b):
  a.year = b.year
  a.month = b.month
  a.day = b.day

def AddMonthsToDate(date, months):

  if months > 0.0:
    i = 0.0
    while i < months:
      date.month = date.month + 1.0

      if date.month == 13.0:
        date.month = 1.0
        date.year = date.year + 1.0
      i = i + 1.0
    
  if months < 0.0:
    i = 0.0
    while i <  -months:
      date.month = date.month - 1.0

      if date.month == 0.0:
        date.month = 12.0
        date.year = date.year - 1.0
      i = i + 1.0
    

def DateToStringISO8601WithCheck(date, datestr, message):

  success = IsValidDate(date, message)

  if success:
    if date.year <= 9999.0:
      datestr.string = DateToStringISO8601(date)
    else:
      message.string = "This library works from 1752 to 9999."

  return success

def DateToStringISO8601(date):

  str =  [None]*int(10.0)

  str[int(0.0)] = charDecimalDigitToCharacter(floor(date.year/1000.0))
  str[int(1.0)] = charDecimalDigitToCharacter(floor((date.year % 1000.0)/100.0))
  str[int(2.0)] = charDecimalDigitToCharacter(floor((date.year % 100.0)/10.0))
  str[int(3.0)] = charDecimalDigitToCharacter(floor(date.year % 10.0))

  str[int(4.0)] = '-'

  str[int(5.0)] = charDecimalDigitToCharacter(floor((date.month % 100.0)/10.0))
  str[int(6.0)] = charDecimalDigitToCharacter(floor(date.month % 10.0))

  str[int(7.0)] = '-'

  str[int(8.0)] = charDecimalDigitToCharacter(floor((date.day % 100.0)/10.0))
  str[int(9.0)] = charDecimalDigitToCharacter(floor(date.day % 10.0))

  return str

def DateFromStringISO8601(str):

  date = Date()

  n = charCharacterToDecimalDigit(str[int(0.0)])*1000.0
  n = n + charCharacterToDecimalDigit(str[int(1.0)])*100.0
  n = n + charCharacterToDecimalDigit(str[int(2.0)])*10.0
  n = n + charCharacterToDecimalDigit(str[int(3.0)])*1.0

  date.year = n

  n = charCharacterToDecimalDigit(str[int(5.0)])*10.0
  n = n + charCharacterToDecimalDigit(str[int(6.0)])*1.0

  date.month = n

  n = charCharacterToDecimalDigit(str[int(8.0)])*10.0
  n = n + charCharacterToDecimalDigit(str[int(9.0)])*1.0

  date.day = n

  return date

def DateFromStringISO8601WithCheck(str, dateRef, message):

  valid = IsValidDateISO8601(str, message)

  if valid:
    dateRef.date = DateFromStringISO8601(str)

  return valid

def IsValidDateISO8601(str, message):

  if len(str) == 4.0 + 1.0 + 2.0 + 1.0 + 2.0:

    if charIsNumber(str[int(0.0)]) and charIsNumber(str[int(1.0)]) and charIsNumber(str[int(2.0)]) and charIsNumber(str[int(3.0)]) and charIsNumber(str[int(5.0)]) and charIsNumber(str[int(6.0)]) and charIsNumber(str[int(8.0)]) and charIsNumber(str[int(9.0)]):
      if str[int(4.0)] == '-' and str[int(7.0)] == '-':
        valid = True
      else:
        valid = False
        message.string = "ISO8601 date must use \'-\' in positions 5 and 8."
    else:
      valid = False
      message.string = "ISO8601 date must use decimal digits in positions 1, 2, 3, 4, 6, 7, 9 and 10."
  else:
    valid = False
    message.string = "ISO8601 date must be exactly 10 characters long."

  return valid

def DateEquals(a, b):
  return a.year == b.year and a.month == b.month and a.day == b.day

def CopyDate(a):

  b = CreateDate(a.year, a.month, a.day)

  return b

def GetSecondsFromDate(date):

  seconds = 0.0
  dayNumberReferenceReference = NumberReference()
  message = StringReference()

  success = DateToDaysWithCheck(date, dayNumberReferenceReference, message)
  if success:
    days = dayNumberReferenceReference.numberValue

    secondsInMinute = 60.0
    secondsInHour = 60.0*secondsInMinute
    secondsInDay = 24.0*secondsInHour

    seconds = seconds + secondsInDay*days

  dayNumberReferenceReference = None
  message = None

  return seconds

def DateIsInInterval(interval, date):

  fromx = DateToDays(interval.first)
  to = DateToDays(interval.last)
  day = DateToDays(date)

  return day >= fromx and day <= to

def DateLessThan(a, b):

  aDays = DateToDays(a)
  bDays = DateToDays(b)

  return aDays < bDays

def CreateDateTimeTimezone(year, month, day, hours, minutes, seconds, timezoneOffsetSeconds):

  dateTimeTimezone = DateTimeTimezone()

  dateTimeTimezone.dateTime = CreateDateTime(year, month, day, hours, minutes, seconds)
  dateTimeTimezone.timezoneOffsetSeconds = timezoneOffsetSeconds

  return dateTimeTimezone

def CreateDateTimeTimezoneInHoursAndMinutes(year, month, day, hours, minutes, seconds, timezoneOffsetHours, timezoneOffsetMinutes):

  dateTimeTimezone = DateTimeTimezone()

  dateTimeTimezone.dateTime = CreateDateTime(year, month, day, hours, minutes, seconds)
  dateTimeTimezone.timezoneOffsetSeconds = GetSecondsFromHours(timezoneOffsetHours) + GetSecondsFromMinutes(timezoneOffsetMinutes)

  return dateTimeTimezone

def GetDateFromDateTimeTimeZone(dateTimeTimezone, dateTimeReference, message):

  dateTime = dateTimeTimezone.dateTime

  return AddSecondsToDateTimeWithCheck(dateTime,  -dateTimeTimezone.timezoneOffsetSeconds, dateTimeReference, message)

def CreateDateTimeTimezoneFromDateTimeAndTimeZoneInSeconds(dateTime, timezoneOffsetSeconds, dateTimeTimezoneReference, message):

  adjustedDateTimeReference = DateTimeReference()
  dateTimeTimezone = DateTimeTimezone()

  success = AddSecondsToDateTime(dateTime, timezoneOffsetSeconds, adjustedDateTimeReference, message)

  if success:
    dateTimeTimezone.dateTime = adjustedDateTimeReference.dateTime
    dateTimeTimezone.timezoneOffsetSeconds = timezoneOffsetSeconds

    dateTimeTimezoneReference.dateTimeTimezone = dateTimeTimezone

  return success

def CreateDateTimeTimezoneFromDateTimeAndTimeZoneInHoursAndMinutes(dateTime, timezoneOffsetHours, timezoneOffsetMinutes, dateTimeTimezoneReference, message):
  return CreateDateTimeTimezoneFromDateTimeAndTimeZoneInSeconds(dateTime, GetSecondsFromHours(timezoneOffsetHours) + GetSecondsFromMinutes(timezoneOffsetMinutes), dateTimeTimezoneReference, message)

def GetDateTimeTimezoneFromSeconds(dateTimeTzRef, seconds, offset, message):

  dateTimeRef = DateTimeReference()
  success = GetDateTimeFromSeconds(seconds, dateTimeRef, message)

  if success:
    success = CreateDateTimeTimezoneFromDateTimeAndTimeZoneInSeconds(dateTimeRef.dateTime, offset, dateTimeTzRef, message)

  return success

def CreateDateTime(year, month, day, hours, minutes, seconds):

  dateTime = DateTime()

  dateTime.date = CreateDate(year, month, day)
  dateTime.hours = hours
  dateTime.minutes = minutes
  dateTime.seconds = seconds

  return dateTime

def GetDateTimeFromSeconds(seconds, dateTimeReference, message):

  secondsInMinute = 60.0
  secondsInHour = 60.0*secondsInMinute
  secondsInDay = 24.0*secondsInHour
  days = floor(seconds/secondsInDay)
  remainder = seconds - days*secondsInDay
  dateReference = DateReference()

  success = DayToDateWithCheck(days, dateReference, message)
  if success:
    date = dateReference.date

    dateTime = DateTime()
    dateTime.date = date
    dateTime.hours = floor(remainder/secondsInHour)
    remainder = remainder - dateTime.hours*secondsInHour
    dateTime.minutes = floor(remainder/secondsInMinute)
    remainder = remainder - dateTime.minutes*secondsInMinute
    dateTime.seconds = remainder

    dateTimeReference.dateTime = dateTime

  return success

def GetSecondsFromDateTime(dateTime):

  secondsInMinute = 60.0
  secondsInHour = 60.0*secondsInMinute

  seconds = GetSecondsFromDate(dateTime.date)
  seconds = seconds + secondsInHour*dateTime.hours
  seconds = seconds + secondsInMinute*dateTime.minutes
  seconds = seconds + dateTime.seconds

  return seconds

def GetSecondsFromMinutes(minutes):
  return minutes*60.0

def GetSecondsFromHours(hours):
  return GetSecondsFromMinutes(hours*60.0)

def GetSecondsFromDays(days):
  return GetSecondsFromHours(days*24.0)

def GetSecondsFromWeeks(weeks):
  return GetSecondsFromDays(weeks*7.0)

def GetMinutesFromSeconds(seconds):
  return seconds/60.0

def GetHoursFromSeconds(seconds):
  return GetMinutesFromSeconds(seconds)/60.0

def GetDaysFromSeconds(seconds):
  return GetHoursFromSeconds(seconds)/24.0

def GetWeeksFromSeconds(seconds):
  return GetDaysFromSeconds(seconds)/7.0

def GetDateFromDateTime(dateTime):
  return dateTime.date

def AddSecondsToDateTimeWithCheck(dateTime, seconds, dateTimeReference, message):

  if IsValidDateTime(dateTime, message):
    secondsInDateTime = GetSecondsFromDateTime(dateTime)
    secondsInDateTime = secondsInDateTime + seconds

    success = GetDateTimeFromSeconds(secondsInDateTime, dateTimeReference, message)
  else:
    success = False

  return success

def AddSecondsToDateTime(dateTime, seconds, dateTimeReference, message):

  secondsInDateTime = GetSecondsFromDateTime(dateTime)
  secondsInDateTime = secondsInDateTime + seconds

  return GetDateTimeFromSeconds(secondsInDateTime, dateTimeReference, message)

def AddMinutesToDateTime(dateTime, minutes, dateTimeReference, message):
  return AddSecondsToDateTime(dateTime, GetSecondsFromMinutes(minutes), dateTimeReference, message)

def AddHoursToDateTime(dateTime, hours, dateTimeReference, message):
  return AddSecondsToDateTime(dateTime, GetSecondsFromHours(hours), dateTimeReference, message)

def AddDaysToDateTime(dateTime, days, dateTimeReference, message):
  return AddSecondsToDateTime(dateTime, GetSecondsFromDays(days), dateTimeReference, message)

def AddWeeksToDateTime(dateTime, weeks, dateTimeReference, message):
  return AddSecondsToDateTime(dateTime, GetSecondsFromWeeks(weeks), dateTimeReference, message)

def DateTimeToStringISO8601WithCheck(datetime, dateStr, message):

  success = DateToStringISO8601WithCheck(datetime.date, dateStr, message)

  if success:
    dateStr.string = None

    success = IsValidDateTime(datetime, message)
    if success:
      dateStr.string = DateTimeToStringISO8601(datetime)

  return success

def IsValidDateTime(datetime, message):

  success = IsValidDate(datetime.date, message)

  if success:
    if datetime.hours <= 23.0 and datetime.hours >= 0.0:
      if datetime.minutes <= 59.0 and datetime.minutes >= 0.0:
        if datetime.seconds <= 59.0 and datetime.seconds >= 0.0:
          success = True
        else:
          success = False
          message.string = "Seconds must be between 0 and 59."
      else:
        success = False
        message.string = "Minutes must be between 0 and 59."
    else:
      success = False
      message.string = "Hours must be between 0 and 23."

  return success

def DateTimeToStringISO8601(datetime):

  str =  [None]*int(19.0)

  datestr = DateToStringISO8601(datetime.date)
  i = 0.0
  while i < len(datestr):
    str[int(i)] = datestr[int(i)]
    i = i + 1.0
  

  str[int(10.0)] = 'T'
  str[int(11.0)] = charDecimalDigitToCharacter(floor((datetime.hours % 100.0)/10.0))
  str[int(12.0)] = charDecimalDigitToCharacter(floor(datetime.hours % 10.0))

  str[int(13.0)] = ':'

  str[int(14.0)] = charDecimalDigitToCharacter(floor((datetime.minutes % 100.0)/10.0))
  str[int(15.0)] = charDecimalDigitToCharacter(floor(datetime.minutes % 10.0))

  str[int(16.0)] = ':'

  str[int(17.0)] = charDecimalDigitToCharacter(floor((datetime.seconds % 100.0)/10.0))
  str[int(18.0)] = charDecimalDigitToCharacter(floor(datetime.seconds % 10.0))

  return str

def DateTimeFromStringISO8601(str):

  dateTime = DateTime()

  dateTime.date = DateFromStringISO8601(str)

  n = charCharacterToDecimalDigit(str[int(11.0)])*10.0
  n = n + charCharacterToDecimalDigit(str[int(12.0)])*1.0

  dateTime.hours = n

  n = charCharacterToDecimalDigit(str[int(14.0)])*10.0
  n = n + charCharacterToDecimalDigit(str[int(15.0)])*1.0

  dateTime.minutes = n

  n = charCharacterToDecimalDigit(str[int(17.0)])*10.0
  n = n + charCharacterToDecimalDigit(str[int(18.0)])*1.0

  dateTime.seconds = n

  return dateTime

def DateTimeFromStringISO8601WithCheck(str, dateTimeRef, message):

  valid = IsValidDateTimeISO8601(str, message)

  if valid:
    dateTimeRef.dateTime = DateTimeFromStringISO8601(str)

  return valid

def IsValidDateTimeISO8601(str, message):

  if len(str) == 4.0 + 1.0 + 2.0 + 1.0 + 2.0 + 1.0 + 2.0 + 1.0 + 2.0 + 1.0 + 2.0:

    if charIsNumber(str[int(0.0)]) and charIsNumber(str[int(1.0)]) and charIsNumber(str[int(2.0)]) and charIsNumber(str[int(3.0)]) and charIsNumber(str[int(5.0)]) and charIsNumber(str[int(6.0)]) and charIsNumber(str[int(8.0)]) and charIsNumber(str[int(9.0)]) and charIsNumber(str[int(11.0)]) and charIsNumber(str[int(12.0)]) and charIsNumber(str[int(14.0)]) and charIsNumber(str[int(15.0)]) and charIsNumber(str[int(17.0)]) and charIsNumber(str[int(18.0)]):
      if str[int(4.0)] == '-' and str[int(7.0)] == '-' and str[int(10.0)] == 'T' and str[int(13.0)] == ':' and str[int(16.0)] == ':':
        valid = True
      else:
        valid = False
        message.string = "ISO8601 date must use \'-\' in positions 5 and 8, \'T\' in position 11 and \':\' in positions 14 and 17."
    else:
      valid = False
      message.string = "ISO8601 date must use decimal digits in positions 1, 2, 3, 4, 6, 7, 9, 10, 12, 13, 15, 16, 18 and 19."
  else:
    valid = False
    message.string = "ISO8601 date must be exactly 19 characters long."

  return valid

def DateTimeEquals(a, b):
  return DateEquals(a.date, b.date) and a.hours == b.hours and a.minutes == b.minutes and a.seconds == b.seconds

def FreeDateTime(datetime):
  datetime.date = None
  datetime = None

def charToLowerCase(character):

  toReturn = character
  if character == 'A':
    toReturn = 'a'
  elif character == 'B':
    toReturn = 'b'
  elif character == 'C':
    toReturn = 'c'
  elif character == 'D':
    toReturn = 'd'
  elif character == 'E':
    toReturn = 'e'
  elif character == 'F':
    toReturn = 'f'
  elif character == 'G':
    toReturn = 'g'
  elif character == 'H':
    toReturn = 'h'
  elif character == 'I':
    toReturn = 'i'
  elif character == 'J':
    toReturn = 'j'
  elif character == 'K':
    toReturn = 'k'
  elif character == 'L':
    toReturn = 'l'
  elif character == 'M':
    toReturn = 'm'
  elif character == 'N':
    toReturn = 'n'
  elif character == 'O':
    toReturn = 'o'
  elif character == 'P':
    toReturn = 'p'
  elif character == 'Q':
    toReturn = 'q'
  elif character == 'R':
    toReturn = 'r'
  elif character == 'S':
    toReturn = 's'
  elif character == 'T':
    toReturn = 't'
  elif character == 'U':
    toReturn = 'u'
  elif character == 'V':
    toReturn = 'v'
  elif character == 'W':
    toReturn = 'w'
  elif character == 'X':
    toReturn = 'x'
  elif character == 'Y':
    toReturn = 'y'
  elif character == 'Z':
    toReturn = 'z'

  return toReturn

def charToUpperCase(character):

  toReturn = character
  if character == 'a':
    toReturn = 'A'
  elif character == 'b':
    toReturn = 'B'
  elif character == 'c':
    toReturn = 'C'
  elif character == 'd':
    toReturn = 'D'
  elif character == 'e':
    toReturn = 'E'
  elif character == 'f':
    toReturn = 'F'
  elif character == 'g':
    toReturn = 'G'
  elif character == 'h':
    toReturn = 'H'
  elif character == 'i':
    toReturn = 'I'
  elif character == 'j':
    toReturn = 'J'
  elif character == 'k':
    toReturn = 'K'
  elif character == 'l':
    toReturn = 'L'
  elif character == 'm':
    toReturn = 'M'
  elif character == 'n':
    toReturn = 'N'
  elif character == 'o':
    toReturn = 'O'
  elif character == 'p':
    toReturn = 'P'
  elif character == 'q':
    toReturn = 'Q'
  elif character == 'r':
    toReturn = 'R'
  elif character == 's':
    toReturn = 'S'
  elif character == 't':
    toReturn = 'T'
  elif character == 'u':
    toReturn = 'U'
  elif character == 'v':
    toReturn = 'V'
  elif character == 'w':
    toReturn = 'W'
  elif character == 'x':
    toReturn = 'X'
  elif character == 'y':
    toReturn = 'Y'
  elif character == 'z':
    toReturn = 'Z'

  return toReturn

def charIsUpperCase(character):

  isUpper = True
  if character == 'A':
    pass
  elif character == 'B':
    pass
  elif character == 'C':
    pass
  elif character == 'D':
    pass
  elif character == 'E':
    pass
  elif character == 'F':
    pass
  elif character == 'G':
    pass
  elif character == 'H':
    pass
  elif character == 'I':
    pass
  elif character == 'J':
    pass
  elif character == 'K':
    pass
  elif character == 'L':
    pass
  elif character == 'M':
    pass
  elif character == 'N':
    pass
  elif character == 'O':
    pass
  elif character == 'P':
    pass
  elif character == 'Q':
    pass
  elif character == 'R':
    pass
  elif character == 'S':
    pass
  elif character == 'T':
    pass
  elif character == 'U':
    pass
  elif character == 'V':
    pass
  elif character == 'W':
    pass
  elif character == 'X':
    pass
  elif character == 'Y':
    pass
  elif character == 'Z':
    pass
  else:
    isUpper = False

  return isUpper

def charIsLowerCase(character):

  isLower = True
  if character == 'a':
    pass
  elif character == 'b':
    pass
  elif character == 'c':
    pass
  elif character == 'd':
    pass
  elif character == 'e':
    pass
  elif character == 'f':
    pass
  elif character == 'g':
    pass
  elif character == 'h':
    pass
  elif character == 'i':
    pass
  elif character == 'j':
    pass
  elif character == 'k':
    pass
  elif character == 'l':
    pass
  elif character == 'm':
    pass
  elif character == 'n':
    pass
  elif character == 'o':
    pass
  elif character == 'p':
    pass
  elif character == 'q':
    pass
  elif character == 'r':
    pass
  elif character == 's':
    pass
  elif character == 't':
    pass
  elif character == 'u':
    pass
  elif character == 'v':
    pass
  elif character == 'w':
    pass
  elif character == 'x':
    pass
  elif character == 'y':
    pass
  elif character == 'z':
    pass
  else:
    isLower = False

  return isLower

def charIsLetter(character):
  return charIsUpperCase(character) or charIsLowerCase(character)

def charIsNumber(character):

  isNumberx = True
  if character == '0':
    pass
  elif character == '1':
    pass
  elif character == '2':
    pass
  elif character == '3':
    pass
  elif character == '4':
    pass
  elif character == '5':
    pass
  elif character == '6':
    pass
  elif character == '7':
    pass
  elif character == '8':
    pass
  elif character == '9':
    pass
  else:
    isNumberx = False

  return isNumberx

def charIsWhiteSpace(character):

  isWhiteSpacex = True
  if character == ' ':
    pass
  elif character == '\t':
    pass
  elif character == '\n':
    pass
  elif character == '\r':
    pass
  else:
    isWhiteSpacex = False

  return isWhiteSpacex

def charIsSymbol(character):

  isSymbolx = True
  if character == '!':
    pass
  elif character == '\"':
    pass
  elif character == '#':
    pass
  elif character == '$':
    pass
  elif character == '%':
    pass
  elif character == '&':
    pass
  elif character == '\'':
    pass
  elif character == '(':
    pass
  elif character == ')':
    pass
  elif character == '*':
    pass
  elif character == '+':
    pass
  elif character == ',':
    pass
  elif character == '-':
    pass
  elif character == '.':
    pass
  elif character == '/':
    pass
  elif character == ':':
    pass
  elif character == ';':
    pass
  elif character == '<':
    pass
  elif character == '=':
    pass
  elif character == '>':
    pass
  elif character == '?':
    pass
  elif character == '@':
    pass
  elif character == '[':
    pass
  elif character == '\\':
    pass
  elif character == ']':
    pass
  elif character == '^':
    pass
  elif character == '_':
    pass
  elif character == '`':
    pass
  elif character == '{':
    pass
  elif character == '|':
    pass
  elif character == '}':
    pass
  elif character == '~':
    pass
  else:
    isSymbolx = False

  return isSymbolx

def charCharacterIsBefore(a, b):

  ad = ord(a)
  bd = ord(b)

  return ad < bd

def charDecimalDigitToCharacter(digit):
  if digit == 1.0:
    c = '1'
  elif digit == 2.0:
    c = '2'
  elif digit == 3.0:
    c = '3'
  elif digit == 4.0:
    c = '4'
  elif digit == 5.0:
    c = '5'
  elif digit == 6.0:
    c = '6'
  elif digit == 7.0:
    c = '7'
  elif digit == 8.0:
    c = '8'
  elif digit == 9.0:
    c = '9'
  else:
    c = '0'
  return c

def charCharacterToDecimalDigit(c):

  if c == '1':
    digit = 1.0
  elif c == '2':
    digit = 2.0
  elif c == '3':
    digit = 3.0
  elif c == '4':
    digit = 4.0
  elif c == '5':
    digit = 5.0
  elif c == '6':
    digit = 6.0
  elif c == '7':
    digit = 7.0
  elif c == '8':
    digit = 8.0
  elif c == '9':
    digit = 9.0
  else:
    digit = 0.0

  return digit

def AssertFalse(b, failures):
  if b:
    failures.numberValue = failures.numberValue + 1.0

def AssertTrue(b, failures):
  if  not b :
    failures.numberValue = failures.numberValue + 1.0

def AssertEquals(a, b, failures):
  if a != b:
    failures.numberValue = failures.numberValue + 1.0

def AssertBooleansEqual(a, b, failures):
  if a != b:
    failures.numberValue = failures.numberValue + 1.0

def AssertCharactersEqual(a, b, failures):
  if a != b:
    failures.numberValue = failures.numberValue + 1.0

def AssertStringEquals(a, b, failures):
  if  not StringsEqual(a, b) :
    failures.numberValue = failures.numberValue + 1.0

def AssertNumberArraysEqual(a, b, failures):

  if len(a) == len(b):
    i = 0.0
    while i < len(a):
      AssertEquals(a[int(i)], b[int(i)], failures)
      i = i + 1.0
    
  else:
    failures.numberValue = failures.numberValue + 1.0

def AssertBooleanArraysEqual(a, b, failures):

  if len(a) == len(b):
    i = 0.0
    while i < len(a):
      AssertBooleansEqual(a[int(i)], b[int(i)], failures)
      i = i + 1.0
    
  else:
    failures.numberValue = failures.numberValue + 1.0

def AssertStringArraysEqual(a, b, failures):

  if len(a) == len(b):
    i = 0.0
    while i < len(a):
      AssertStringEquals(a[int(i)].string, b[int(i)].string, failures)
      i = i + 1.0
    
  else:
    failures.numberValue = failures.numberValue + 1.0

def Negate(x):
  return  -x

def Positive(x):
  return  +x

def Factorial(x):

  f = 1.0

  i = 2.0
  while i <= x:
    f = f*i
    i = i + 1.0
  

  return f

def Round(x):
  return floor(x + 0.5)

def BankersRound(x):

  if Absolute(x - Truncate(x)) == 0.5:
    if  not DivisibleBy(Round(x), 2.0) :
      r = Round(x) - 1.0
    else:
      r = Round(x)
  else:
    r = Round(x)

  return r

def Ceil(x):
  return ceil(x)

def Floor(x):
  return floor(x)

def Truncate(x):

  if x >= 0.0:
    t = floor(x)
  else:
    t = ceil(x)

  return t

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

def Atan2(y, x):

  # Atan2 is an invalid operation when x = 0 and y = 0, but this method does not return errors.
  a = 0.0

  if x > 0.0:
    a = Atan(y/x)
  elif x < 0.0 and y >= 0.0:
    a = Atan(y/x) + pi
  elif x < 0.0 and y < 0.0:
    a = Atan(y/x) - pi
  elif x == 0.0 and y > 0.0:
    a = pi/2.0
  elif x == 0.0 and y < 0.0:
    a =  -pi/2.0

  return a

def Squareroot(x):
  return sqrt(x)

def Exp(x):
  return exp(x)

def DivisibleBy(a, b):
  return ((a % b) == 0.0)

def Combinations(n, k):

  c = 1.0
  j = 1.0
  i = n - k + 1.0

  while i <= n:
    c = c*i
    c = c/j

    i = i + 1.0
    j = j + 1.0
  

  return c

def Permutations(n, k):

  c = 1.0

  i = n - k + 1.0
  while i <= n:
    c = c*i
    i = i + 1.0
  

  return c

def EpsilonCompare(a, b, epsilon):
  return fabs(a - b) < epsilon

def GreatestCommonDivisor(a, b):

  while b != 0.0:
    t = b
    b = a % b
    a = t
  

  return a

def GCDWithSubtraction(a, b):

  if a == 0.0:
    g = b
  else:
    while b != 0.0:
      if a > b:
        a = a - b
      else:
        b = b - a
    

    g = a

  return g

def IsInteger(a):
  return (a - floor(a)) == 0.0

def GreatestCommonDivisorWithCheck(a, b, gcdReference):

  if IsInteger(a) and IsInteger(b):
    gcd = GreatestCommonDivisor(a, b)
    gcdReference.numberValue = gcd
    success = True
  else:
    success = False

  return success

def LeastCommonMultiple(a, b):

  if a > 0.0 and b > 0.0:
    lcm = fabs(a*b)/GreatestCommonDivisor(a, b)
  else:
    lcm = 0.0

  return lcm

def Sign(a):

  if a > 0.0:
    s = 1.0
  elif a < 0.0:
    s =  -1.0
  else:
    s = 0.0

  return s

def Max(a, b):
  return max(a,b)

def Min(a, b):
  return min(a,b)

def Power(a, b):
  return a**b

def Gamma(x):
  return LanczosApproximation(x)

def LogGamma(x):
  return log(Gamma(x))

def LanczosApproximation(z):

  p =  [None]*int(8.0)
  p[int(0.0)] = 676.5203681218851
  p[int(1.0)] =  -1259.1392167224028
  p[int(2.0)] = 771.32342877765313
  p[int(3.0)] =  -176.61502916214059
  p[int(4.0)] = 12.507343278686905
  p[int(5.0)] =  -0.13857109526572012
  p[int(6.0)] = 9.9843695780195716e-6
  p[int(7.0)] = 1.5056327351493116e-7

  if z < 0.5:
    y = pi/(sin(pi*z)*LanczosApproximation(1.0 - z))
  else:
    z = z - 1.0
    x = 0.99999999999980993
    i = 0.0
    while i < len(p):
      x = x + p[int(i)]/(z + i + 1.0)
      i = i + 1.0
    
    t = z + len(p) - 0.5
    y = sqrt(2.0*pi)*t**(z + 0.5)*exp( -t)*x

  return y

def Beta(x, y):
  return Gamma(x)*Gamma(y)/Gamma(x + y)

def Sinh(x):
  return (exp(x) - exp( -x))/2.0

def Cosh(x):
  return (exp(x) + exp( -x))/2.0

def Tanh(x):
  return Sinh(x)/Cosh(x)

def Cot(x):
  return 1.0/tan(x)

def Sec(x):
  return 1.0/cos(x)

def Csc(x):
  return 1.0/sin(x)

def Coth(x):
  return Cosh(x)/Sinh(x)

def Sech(x):
  return 1.0/Cosh(x)

def Csch(x):
  return 1.0/Sinh(x)

def Error(x):

  if x == 0.0:
    y = 0.0
  elif x < 0.0:
    y =  -Error( -x)
  else:
    c1 =  -1.26551223
    c2 =  +1.00002368
    c3 =  +0.37409196
    c4 =  +0.09678418
    c5 =  -0.18628806
    c6 =  +0.27886807
    c7 =  -1.13520398
    c8 =  +1.48851587
    c9 =  -0.82215223
    c10 =  +0.17087277

    t = 1.0/(1.0 + 0.5*fabs(x))

    tau = t*exp( -x**2.0 + c1 + t*(c2 + t*(c3 + t*(c4 + t*(c5 + t*(c6 + t*(c7 + t*(c8 + t*(c9 + t*c10)))))))))

    y = 1.0 - tau

  return y

def ErrorInverse(x):

  a = (8.0*(pi - 3.0))/(3.0*pi*(4.0 - pi))

  t = 2.0/(pi*a) + log(1.0 - x**2.0)/2.0
  y = Sign(x)*sqrt(sqrt(t**2.0 - log(1.0 - x**2.0)/a) - t)

  return y

def FallingFactorial(x, n):

  y = 1.0

  k = 0.0
  while k <= n - 1.0:
    y = y*(x - k)
    k = k + 1.0
  

  return y

def RisingFactorial(x, n):

  y = 1.0

  k = 0.0
  while k <= n - 1.0:
    y = y*(x + k)
    k = k + 1.0
  

  return y

def Hypergeometric(a, b, c, z, maxIterations, precision):

  if fabs(z) >= 0.5:
    y = (1.0 - z)**( -a)*HypergeometricDirect(a, c - b, c, z/(z - 1.0), maxIterations, precision)
  else:
    y = HypergeometricDirect(a, b, c, z, maxIterations, precision)

  return y

def HypergeometricDirect(a, b, c, z, maxIterations, precision):

  y = 0.0
  done = False

  n = 0.0
  while n < maxIterations and  not done :
    yp = RisingFactorial(a, n)*RisingFactorial(b, n)/RisingFactorial(c, n)*z**n/Factorial(n)
    if fabs(yp) < precision:
      done = True
    y = y + yp
    n = n + 1.0
  

  return y

def BernouilliNumber(n):
  return AkiyamaTanigawaAlgorithm(n)

def AkiyamaTanigawaAlgorithm(n):

  A =  [None]*int(n + 1.0)

  m = 0.0
  while m <= n:
    A[int(m)] = 1.0/(m + 1.0)
    j = m
    while j >= 1.0:
      A[int(j - 1.0)] = j*(A[int(j - 1.0)] - A[int(j)])
      j = j - 1.0
    
    m = m + 1.0
  

  B = A[int(0.0)]

  A = None

  return B

def StringToNumberArray(string):

  array =  [None]*int(len(string))

  i = 0.0
  while i < len(string):
    array[int(i)] = ord(string[int(i)])
    i = i + 1.0
  
  return array

def NumberArrayToString(array):

  string =  [None]*int(len(array))

  i = 0.0
  while i < len(array):
    string[int(i)] = unichr(int(array[int(i)]))
    i = i + 1.0
  
  return string

def NumberArraysEqual(a, b):

  equal = True
  if len(a) == len(b):
    i = 0.0
    while i < len(a) and equal:
      if a[int(i)] != b[int(i)]:
        equal = False
      i = i + 1.0
    
  else:
    equal = False

  return equal

def BooleanArraysEqual(a, b):

  equal = True
  if len(a) == len(b):
    i = 0.0
    while i < len(a) and equal:
      if a[int(i)] != b[int(i)]:
        equal = False
      i = i + 1.0
    
  else:
    equal = False

  return equal

def StringsEqual(a, b):

  equal = True
  if len(a) == len(b):
    i = 0.0
    while i < len(a) and equal:
      if a[int(i)] != b[int(i)]:
        equal = False
      i = i + 1.0
    
  else:
    equal = False

  return equal

def FillNumberArray(a, value):

  i = 0.0
  while i < len(a):
    a[int(i)] = value
    i = i + 1.0
  

def FillString(a, value):

  i = 0.0
  while i < len(a):
    a[int(i)] = value
    i = i + 1.0
  

def FillBooleanArray(a, value):

  i = 0.0
  while i < len(a):
    a[int(i)] = value
    i = i + 1.0
  

def FillNumberArrayRange(a, value, fromx, to):

  if fromx >= 0.0 and fromx <= len(a) and to >= 0.0 and to <= len(a) and fromx <= to:
    length = to - fromx
    i = 0.0
    while i < length:
      a[int(fromx + i)] = value
      i = i + 1.0
    

    success = True
  else:
    success = False

  return success

def FillBooleanArrayRange(a, value, fromx, to):

  if fromx >= 0.0 and fromx <= len(a) and to >= 0.0 and to <= len(a) and fromx <= to:
    length = to - fromx
    i = 0.0
    while i < length:
      a[int(fromx + i)] = value
      i = i + 1.0
    

    success = True
  else:
    success = False

  return success

def FillStringRange(a, value, fromx, to):

  if fromx >= 0.0 and fromx <= len(a) and to >= 0.0 and to <= len(a) and fromx <= to:
    length = to - fromx
    i = 0.0
    while i < length:
      a[int(fromx + i)] = value
      i = i + 1.0
    

    success = True
  else:
    success = False

  return success

def CopyNumberArray(a):

  n =  [None]*int(len(a))

  i = 0.0
  while i < len(a):
    n[int(i)] = a[int(i)]
    i = i + 1.0
  

  return n

def CopyBooleanArray(a):

  n =  [None]*int(len(a))

  i = 0.0
  while i < len(a):
    n[int(i)] = a[int(i)]
    i = i + 1.0
  

  return n

def CopyString(a):

  n =  [None]*int(len(a))

  i = 0.0
  while i < len(a):
    n[int(i)] = a[int(i)]
    i = i + 1.0
  

  return n

def CopyNumberArrayRange(a, fromx, to, copyReference):

  if fromx >= 0.0 and fromx <= len(a) and to >= 0.0 and to <= len(a) and fromx <= to:
    length = to - fromx
    n =  [None]*int(length)

    i = 0.0
    while i < length:
      n[int(i)] = a[int(fromx + i)]
      i = i + 1.0
    

    copyReference.numberArray = n
    success = True
  else:
    success = False

  return success

def CopyBooleanArrayRange(a, fromx, to, copyReference):

  if fromx >= 0.0 and fromx <= len(a) and to >= 0.0 and to <= len(a) and fromx <= to:
    length = to - fromx
    n =  [None]*int(length)

    i = 0.0
    while i < length:
      n[int(i)] = a[int(fromx + i)]
      i = i + 1.0
    

    copyReference.booleanArray = n
    success = True
  else:
    success = False

  return success

def CopyStringRange(a, fromx, to, copyReference):

  if fromx >= 0.0 and fromx <= len(a) and to >= 0.0 and to <= len(a) and fromx <= to:
    length = to - fromx
    n =  [None]*int(length)

    i = 0.0
    while i < length:
      n[int(i)] = a[int(fromx + i)]
      i = i + 1.0
    

    copyReference.string = n
    success = True
  else:
    success = False

  return success

def IsLastElement(length, index):
  return index + 1.0 == length

def CreateNumberArray(length, value):

  array =  [None]*int(length)
  FillNumberArray(array, value)

  return array

def CreateBooleanArray(length, value):

  array =  [None]*int(length)
  FillBooleanArray(array, value)

  return array

def CreateString(length, value):

  array =  [None]*int(length)
  FillString(array, value)

  return array

def SwapElementsOfNumberArray(A, ai, bi):

  tmp = A[int(ai)]
  A[int(ai)] = A[int(bi)]
  A[int(bi)] = tmp

def SwapElementsOfStringArray(A, ai, bi):

  tmp = A.stringArray[int(ai)]
  A.stringArray[int(ai)] = A.stringArray[int(bi)]
  A.stringArray[int(bi)] = tmp

def ReverseNumberArray(array):

  i = 0.0
  while i < len(array)/2.0:
    SwapElementsOfNumberArray(array, i, len(array) - i - 1.0)
    i = i + 1.0
  



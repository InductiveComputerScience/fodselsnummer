// Downloaded from https://repo.progsbase.com - Code Developed Using progsbase.

using static System.Math;

public class BooleanArrayReference{
	public bool [] booleanArray;
}
public class BooleanReference{
	public bool booleanValue;
}
public class CharacterReference{
	public char characterValue;
}
public class NumberArrayReference{
	public double [] numberArray;
}
public class NumberReference{
	public double numberValue;
}
public class StringArrayReference{
	public StringReference [] stringArray;
}
public class StringReference{
	public char [] stringx;
}
public class Date{
	public double year;
	public double month;
	public double day;
}
public class DateReference{
	public Date date;
}
public class Interval{
	public Date first;
	public Date last;
}
public class DateTimeTimezone{
	public DateTime dateTime;
	public double timezoneOffsetSeconds;
}
public class DateTimeTimezoneReference{
	public DateTimeTimezone dateTimeTimezone;
}
public class DateTime{
	public Date date;
	public double hours;
	public double minutes;
	public double seconds;
}
public class DateTimeReference{
	public DateTime dateTime;
}
public class foedselsnummer{
	public static bool IsValidNorwegianPersonalIdentificationNumber(char [] fnummer, StringReference message){
		bool gyldig;
		double i, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
		double k1, k2;
		DateReference dateRef;

		if(fnummer.Length == 11d){
			gyldig = true;
			for(i = 0d; i < fnummer.Length; i = i + 1d){
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

				dateRef = new DateReference();
				gyldig = GetDateFromNorwegianPersonalIdentificationNumber(fnummer, dateRef, message);

				if(gyldig){
					if(IsValidDate(dateRef.date, message)){
						k1 = d1*3d + d2*7d + d3*6d + d4*1d + d5*8d + d6*9d + d7*4d + d8*5d + d9*2d;
						k1 = k1%11d;
						if(k1 != 0d){
							k1 = 11d - k1;
						}
						if(k1 == 10d){
							gyldig = false;
							message.stringx = "Control digit 1 is 10, which is invalid.".ToCharArray();
						}

						if(gyldig){
							k2 = d1*5d + d2*4d + d3*3d + d4*2d + d5*7d + d6*6d + d7*5d + d8*4d + d9*3d + k1*2d;
							k2 = k2%11d;
							if(k2 != 0d){
								k2 = 11d - k2;
							}
							if(k2 == 10d){
								gyldig = false;
								message.stringx = "Control digit 2 is 10, which is invalid.".ToCharArray();
							}

							if(gyldig){
								if(k1 == d10){
									if(k2 == d11){
										gyldig = true;
									}else{
										gyldig = false;
										message.stringx = "Check of control digit 2 failed.".ToCharArray();
									}
								}else{
									gyldig = false;
									message.stringx = "Check of control digit 1 failed.".ToCharArray();
								}
							}
						}
					}else{
						gyldig = false;
						message.stringx = "The date is not a valid date.".ToCharArray();
					}
				}
			}else{
				gyldig = false;
				message.stringx = "Each character must be a decimal digit.".ToCharArray();
			}
		}else{
			gyldig = false;
			message.stringx = "Must be exactly 11 digits long.".ToCharArray();
		}

		return gyldig;
	}


	public static bool GetDateFromNorwegianPersonalIdentificationNumber(char [] fnummer, DateReference dateRef, StringReference message){
		double individnummer;
		double day, month, year;
		double i, d1, d2, d3, d4, d5, d6, d7, d8, d9;
		bool success;

		success = true;
		dateRef.date = new Date();

		if(fnummer.Length == 11d){
			for(i = 0d; i < fnummer.Length; i = i + 1d){
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

				/* Individnummer*/
				individnummer = d7*100d + d8*10d + d9;

				/* Make date*/
				day = d1*10d + d2;
				month = d3*10d + d4;
				year = d5*10d + d6;

				if(individnummer >= 0d && individnummer <= 499d){
					year = year + 1900d;
				}else if(individnummer >= 500d && individnummer <= 749d && year >= 54d && year <= 99d){
					year = year + 1800d;
				}else if(individnummer >= 900d && individnummer <= 999d && year >= 40d && year <= 99d){
					year = year + 1900d;
				}else if(individnummer >= 500d && individnummer <= 999d && year >= 0d && year <= 39d){
					year = year + 2000d;
				}else{
					success = false;
					message.stringx = "Invalid combination of individnummer and year.".ToCharArray();
				}

				if(success){
					dateRef.date.year = year;
					dateRef.date.month = month;
					dateRef.date.day = day;
				}
			}else{
				message.stringx = "Each character must be a decimal digit.".ToCharArray();
			}
		}else{
			message.stringx = "Must be exactly 11 digits long.".ToCharArray();
		}

		return success;
	}


	public static void Test1(NumberReference failures){
		StringReference message;
		DateReference dateRef;
		bool success;

		message = new StringReference();

		success = IsValidNorwegianPersonalIdentificationNumber("10061270707".ToCharArray(), message);
		AssertTrue(success, failures);

		dateRef = new DateReference();

		success = GetDateFromNorwegianPersonalIdentificationNumber("11028559912".ToCharArray(), dateRef, message);
		AssertTrue(success, failures);
		AssertEquals(dateRef.date.year, 1885d, failures);

		success = GetDateFromNorwegianPersonalIdentificationNumber("01019949768".ToCharArray(), dateRef, message);
		AssertTrue(success, failures);
		AssertEquals(dateRef.date.year, 1999d, failures);

		success = GetDateFromNorwegianPersonalIdentificationNumber("01010099931".ToCharArray(), dateRef, message);
		AssertTrue(success, failures);
		AssertEquals(dateRef.date.year, 2000d, failures);
	}


	public static double test(){
		NumberReference failures;

		failures = CreateNumberReference(0d);

		Test1(failures);

		return failures.numberValue;
	}


	public static BooleanReference CreateBooleanReference(bool value){
		BooleanReference refx;

		refx = new BooleanReference();
		refx.booleanValue = value;

		return refx;
	}


	public static BooleanArrayReference CreateBooleanArrayReference(bool [] value){
		BooleanArrayReference refx;

		refx = new BooleanArrayReference();
		refx.booleanArray = value;

		return refx;
	}


	public static BooleanArrayReference CreateBooleanArrayReferenceLengthValue(double length, bool value){
		BooleanArrayReference refx;
		double i;

		refx = new BooleanArrayReference();
		refx.booleanArray = new bool [(int)(length)];

		for(i = 0d; i < length; i = i + 1d){
			refx.booleanArray[(int)(i)] = value;
		}

		return refx;
	}


	public static void FreeBooleanArrayReference(BooleanArrayReference booleanArrayReference){
		delete(booleanArrayReference.booleanArray);
		delete(booleanArrayReference);
	}


	public static CharacterReference CreateCharacterReference(char value){
		CharacterReference refx;

		refx = new CharacterReference();
		refx.characterValue = value;

		return refx;
	}


	public static NumberReference CreateNumberReference(double value){
		NumberReference refx;

		refx = new NumberReference();
		refx.numberValue = value;

		return refx;
	}


	public static NumberArrayReference CreateNumberArrayReference(double [] value){
		NumberArrayReference refx;

		refx = new NumberArrayReference();
		refx.numberArray = value;

		return refx;
	}


	public static NumberArrayReference CreateNumberArrayReferenceLengthValue(double length, double value){
		NumberArrayReference refx;
		double i;

		refx = new NumberArrayReference();
		refx.numberArray = new double [(int)(length)];

		for(i = 0d; i < length; i = i + 1d){
			refx.numberArray[(int)(i)] = value;
		}

		return refx;
	}


	public static void FreeNumberArrayReference(NumberArrayReference numberArrayReference){
		delete(numberArrayReference.numberArray);
		delete(numberArrayReference);
	}


	public static StringReference CreateStringReference(char [] value){
		StringReference refx;

		refx = new StringReference();
		refx.stringx = value;

		return refx;
	}


	public static StringReference CreateStringReferenceLengthValue(double length, char value){
		StringReference refx;
		double i;

		refx = new StringReference();
		refx.stringx = new char [(int)(length)];

		for(i = 0d; i < length; i = i + 1d){
			refx.stringx[(int)(i)] = value;
		}

		return refx;
	}


	public static void FreeStringReference(StringReference stringReference){
		delete(stringReference.stringx);
		delete(stringReference);
	}


	public static StringArrayReference CreateStringArrayReference(StringReference [] strings){
		StringArrayReference refx;

		refx = new StringArrayReference();
		refx.stringArray = strings;

		return refx;
	}


	public static StringArrayReference CreateStringArrayReferenceLengthValue(double length, char [] value){
		StringArrayReference refx;
		double i;

		refx = new StringArrayReference();
		refx.stringArray = new StringReference [(int)(length)];

		for(i = 0d; i < length; i = i + 1d){
			refx.stringArray[(int)(i)] = CreateStringReference(value);
		}

		return refx;
	}


	public static void FreeStringArrayReference(StringArrayReference stringArrayReference){
		double i;

		for(i = 0d; i < stringArrayReference.stringArray.Length; i = i + 1d){
			delete(stringArrayReference.stringArray[(int)(i)]);
		}
		delete(stringArrayReference.stringArray);
		delete(stringArrayReference);
	}


	public static Date CreateDate(double year, double month, double day){
		Date date;

		date = new Date();

		date.year = year;
		date.month = month;
		date.day = day;

		return date;
	}


	public static bool IsLeapYearWithCheck(double year, BooleanReference isLeapYearReference, StringReference message){
		bool itIsLeapYear;
		bool success;

		if(year >= 1752d){
			success = true;
			itIsLeapYear = IsLeapYear(year);
		}else{
			success = false;
			itIsLeapYear = false;
			message.stringx = "Gregorian calendar was not in general use.".ToCharArray();
		}

		isLeapYearReference.booleanValue = itIsLeapYear;
		return success;
	}


	public static bool IsLeapYear(double year){
		bool itIsLeapYear;

		if(DivisibleBy(year, 4d)){
			if(DivisibleBy(year, 100d)){
				if(DivisibleBy(year, 400d)){
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


	public static bool DayToDateWithCheck(double dayNr, DateReference dateReference, StringReference message){
		Date date;
		NumberReference remainder;
		bool success;

		if(dayNr >= -79623d){
			date = new Date();
			remainder = new NumberReference();
			remainder.numberValue = dayNr + 79623d;
			/* Days since 1752-01-01. Day 0: Thursday, 1970-01-01*/
			/* Find year.*/
			date.year = GetYearFromDayNr(remainder.numberValue, remainder);

			/* Find month.*/
			date.month = GetMonthFromDayNr(remainder.numberValue, date.year, remainder);

			/* Find day.*/
			date.day = 1d + remainder.numberValue;

			dateReference.date = date;
			success = true;
		}else{
			success = false;
			message.stringx = "Gregorian calendar was not in general use before 1752.".ToCharArray();
		}

		return success;
	}


	public static Date DayToDate(double dayNr){
		Date date;
		bool success;
		DateReference dateRef;
		StringReference message;

		dateRef = new DateReference();
		message = new StringReference();

		success = DayToDateWithCheck(dayNr, dateRef, message);
		if(success){
			date = dateRef.date;
			delete(dateRef);
			FreeStringReference(message);
		}else{
			date = CreateDate(1970d, 1d, 1d);
		}

		return date;
	}


	public static bool GetMonthFromDayNrWithCheck(double dayNr, double year, NumberReference monthReference, NumberReference remainderReference, StringReference message){
		double month;
		bool success;

		if(dayNr >= -79623d){
			month = GetMonthFromDayNr(dayNr, year, remainderReference);
			monthReference.numberValue = month;
			success = true;
		}else{
			success = false;
			message.stringx = "Gregorian calendar not in general use before 1752.".ToCharArray();
		}

		return success;
	}


	public static double GetMonthFromDayNr(double dayNr, double year, NumberReference remainderReference){
		double [] daysInMonth;
		bool done;
		double month;

		daysInMonth = GetDaysInMonth(year);
		done = false;
		month = 1d;

		for(; !done; ){
			if(dayNr >= daysInMonth[(int)(month)]){
				dayNr = dayNr - daysInMonth[(int)(month)];
				month = month + 1d;
			}else{
				done = true;
			}
		}
		remainderReference.numberValue = dayNr;

		return month;
	}


	public static bool GetYearFromDayNrWithCheck(double dayNr, NumberReference yearReference, NumberReference remainder, StringReference message){
		bool success;
		double year;

		if(dayNr >= 0d){
			success = true;
			year = GetYearFromDayNr(dayNr, remainder);
			yearReference.numberValue = year;
		}else{
			success = false;
			message.stringx = "Day number must be 0 or higher. 0 is 1752-01-01.".ToCharArray();
		}

		return success;
	}


	public static double GetYearFromDayNr(double dayNr, NumberReference remainder){
		double nrOfDays;
		bool done;
		double year;

		done = false;
		year = 1752d;

		for(; !done; ){
			if(IsLeapYear(year)){
				nrOfDays = 366d;
			}else{
				nrOfDays = 365d;
			}

			if(dayNr >= nrOfDays){
				/* First day is 0.*/
				dayNr = dayNr - nrOfDays;
				year = year + 1d;
			}else{
				done = true;
			}
		}
		remainder.numberValue = dayNr;

		return year;
	}


	public static double DaysBetweenDates(Date A, Date B){
		double daysA, daysB, daysBetween;

		daysA = DateToDays(A);
		daysB = DateToDays(B);

		daysBetween = daysB - daysA;

		return daysBetween;
	}


	public static bool GetDaysInMonthWithCheck(double year, NumberArrayReference daysInMonthReference, StringReference message){
		double [] daysInMonth;
		bool success;
		Date date;

		date = CreateDate(year, 1d, 1d);

		success = IsValidDate(date, message);
		if(success){
			daysInMonth = GetDaysInMonth(year);

			daysInMonthReference.numberArray = daysInMonth;
		}

		return success;
	}


	public static double [] GetDaysInMonth(double year){
		double [] daysInMonth;

		daysInMonth = new double [(int)(1d + 12d)];

		daysInMonth[0] = 0d;
		daysInMonth[1] = 31d;

		if(IsLeapYear(year)){
			daysInMonth[2] = 29d;
		}else{
			daysInMonth[2] = 28d;
		}
		daysInMonth[3] = 31d;
		daysInMonth[4] = 30d;
		daysInMonth[5] = 31d;
		daysInMonth[6] = 30d;
		daysInMonth[7] = 31d;
		daysInMonth[8] = 31d;
		daysInMonth[9] = 30d;
		daysInMonth[10] = 31d;
		daysInMonth[11] = 30d;
		daysInMonth[12] = 31d;

		return daysInMonth;
	}


	public static bool DateToDaysWithCheck(Date date, NumberReference dayNumberReferenceReference, StringReference message){
		double days;
		bool success;

		success = IsValidDate(date, message);
		if(success){
			days = DateToDays(date);
			dayNumberReferenceReference.numberValue = days;
		}

		return success;
	}


	public static double DateToDays(Date date){
		double days;

		/* Day 1752-01-01*/
		days = -79623d;

		days = days + DaysInYears(date.year);
		days = days + DaysInMonths(date.month, date.year);
		days = days + date.day - 1d;

		return days;
	}


	public static bool DateToWeekdayNumberWithCheck(Date date, NumberReference weekDayNumberReference, StringReference message){
		double weekDay;
		bool success;

		success = IsValidDate(date, message);
		if(success){
			weekDay = DateToWeekdayNumber(date);
			weekDayNumberReference.numberValue = weekDay;
		}

		return success;
	}


	public static double DateToWeekdayNumber(Date date){
		double days, weekDay;

		days = DateToDays(date);

		days = days + 79623d;
		days = days + 5d;

		weekDay = days%7d + 1d;

		return weekDay;
	}


	public static double DateToWeeknumber(Date date, NumberReference yearRef){
		double weekNumber, weekday, days, daysWeek1Start, weekdayNewYears;
		Date week1Start, newyears;

		week1Start = CopyDate(date);

		week1Start.day = 1d;
		week1Start.month = 1d;
		weekday = DateToWeekdayNumber(week1Start);

		/* Set week1Start to the start of the Week 1.*/
		/* If monday, week 1 begins on Jan. 1st*/
		if(weekday == 1d){
			week1Start.day = 1d;
		}
		/* If tuesday, week 1 begins on Dec. 31st*/
		if(weekday == 2d){
			week1Start.year = week1Start.year - 1d;
			week1Start.month = 12d;
			week1Start.day = 31d;
		}
		/* If wednesday, week 1 begins on Dec. 30th*/
		if(weekday == 3d){
			week1Start.year = week1Start.year - 1d;
			week1Start.month = 12d;
			week1Start.day = 30d;
		}
		/* If thursday, week 1 begins on Dec. 29th*/
		if(weekday == 4d){
			week1Start.year = week1Start.year - 1d;
			week1Start.month = 12d;
			week1Start.day = 29d;
		}
		/* If friday, week 1 begins on Jan. 4th*/
		if(weekday == 5d){
			week1Start.day = 4d;
		}
		/* If saturday, week 1 begins on Jan. 3rd*/
		if(weekday == 6d){
			week1Start.day = 3d;
		}
		/* If sunday, week 1 begins on Jan. 2nd*/
		if(weekday == 7d){
			week1Start.day = 2d;
		}

		days = DateToDays(date);
		daysWeek1Start = DateToDays(week1Start);

		if(days >= daysWeek1Start){
			weekNumber = 1d + Floor((days - daysWeek1Start)/7d);

			if(weekNumber >= 1d && weekNumber <= 52d){
				/* Week is between 1 and 52 in the current year.*/
				yearRef.numberValue = date.year;
			}else{
				/* Is week nr 53 or 1 next year?*/
				newyears = CopyDate(date);
				newyears.month = 12d;
				newyears.day = 31d;
				weekdayNewYears = DateToWeekdayNumber(newyears);
				if(weekdayNewYears == 1d || weekdayNewYears == 2d || weekdayNewYears == 3d){
					/* Week 1 next year.*/
					weekNumber = 1d;
					yearRef.numberValue = date.year + 1d;
				}else{
					/* Week 53*/
					yearRef.numberValue = date.year;
				}
				delete(newyears);
			}
		}else{
			/* Week is in previous year. Either 52nd or 53rd.*/
			newyears = CopyDate(date);
			newyears.month = 12d;
			newyears.day = 31d;
			newyears.year = date.year - 1d;
			weekNumber = DateToWeeknumber(newyears, yearRef);
			delete(newyears);
		}

		delete(week1Start);

		return weekNumber;
	}


	public static bool DaysInMonthsWithCheck(double month, double year, NumberReference daysInMonthsReference, StringReference message){
		double days;
		bool success;
		Date date;

		date = CreateDate(year, month, 1d);

		success = IsValidDate(date, message);
		if(success){
			days = DaysInMonths(month, year);

			daysInMonthsReference.numberValue = days;
		}

		return success;
	}


	public static double DaysInMonths(double month, double year){
		double [] daysInMonth;
		double days;
		double i;

		daysInMonth = GetDaysInMonth(year);

		days = 0d;
		for(i = 1d; i < month; i = i + 1d){
			days = days + daysInMonth[(int)(i)];
		}

		return days;
	}


	public static bool DaysInYearsWithCheck(double years, NumberReference daysReference, StringReference message){
		double days;
		bool success;
		Date date;

		date = CreateDate(years, 1d, 1d);

		success = IsValidDate(date, message);
		if(success){
			days = DaysInYears(years);
			daysReference.numberValue = days;
		}

		return success;
	}


	public static double DaysInYears(double years){
		double days;
		double i;
		double nrOfDays;

		days = 0d;
		for(i = 1752d; i < years; i = i + 1d){
			if(IsLeapYear(i)){
				nrOfDays = 366d;
			}else{
				nrOfDays = 365d;
			}
			days = days + nrOfDays;
		}

		return days;
	}


	public static bool IsValidDate(Date date, StringReference message){
		bool valid;
		double [] daysInMonth;
		double daysInThisMonth;

		if(date.year >= 1752d){
			if(date.month >= 1d && date.month <= 12d){
				daysInMonth = GetDaysInMonth(date.year);
				daysInThisMonth = daysInMonth[(int)(date.month)];
				if(date.day >= 1d && date.day <= daysInThisMonth){
					valid = true;
				}else{
					valid = false;
					message.stringx = "The month does not have the given day number.".ToCharArray();
				}
			}else{
				valid = false;
				message.stringx = "Month must be between 1 and 12, inclusive.".ToCharArray();
			}
		}else{
			valid = false;
			message.stringx = "Gregorian calendar was not in general use before 1752.".ToCharArray();
		}

		return valid;
	}


	public static bool AddDaysToDate(Date date, double days, StringReference message){
		double n;
		bool success;
		DateReference dateReference;
		NumberReference daysRef;

		daysRef = new NumberReference();
		success = DateToDaysWithCheck(date, daysRef, message);

		if(success){
			n = daysRef.numberValue;
			n = n + days;

			dateReference = new DateReference();
			success = DayToDateWithCheck(n, dateReference, message);
			if(success){
				AssignDate(date, dateReference.date);
			}
		}

		return success;
	}


	public static void AssignDate(Date a, Date b){
		a.year = b.year;
		a.month = b.month;
		a.day = b.day;
	}


	public static void AddMonthsToDate(Date date, double months){
		double i;

		if(months > 0d){
			for(i = 0d; i < months; i = i + 1d){
				date.month = date.month + 1d;

				if(date.month == 13d){
					date.month = 1d;
					date.year = date.year + 1d;
				}
			}
		}
		if(months < 0d){
			for(i = 0d; i < -months; i = i + 1d){
				date.month = date.month - 1d;

				if(date.month == 0d){
					date.month = 12d;
					date.year = date.year - 1d;
				}
			}
		}
	}


	public static bool DateToStringISO8601WithCheck(Date date, StringReference datestr, StringReference message){
		bool success;

		success = IsValidDate(date, message);

		if(success){
			if(date.year <= 9999d){
				datestr.stringx = DateToStringISO8601(date);
			}else{
				message.stringx = "This library works from 1752 to 9999.".ToCharArray();
			}
		}

		return success;
	}


	public static char [] DateToStringISO8601(Date date){
		char [] str;

		str = new char [10];

		str[0] = charDecimalDigitToCharacter(Floor(date.year/1000d));
		str[1] = charDecimalDigitToCharacter(Floor((date.year%1000d)/100d));
		str[2] = charDecimalDigitToCharacter(Floor((date.year%100d)/10d));
		str[3] = charDecimalDigitToCharacter(Floor(date.year%10d));

		str[4] = '-';

		str[5] = charDecimalDigitToCharacter(Floor((date.month%100d)/10d));
		str[6] = charDecimalDigitToCharacter(Floor(date.month%10d));

		str[7] = '-';

		str[8] = charDecimalDigitToCharacter(Floor((date.day%100d)/10d));
		str[9] = charDecimalDigitToCharacter(Floor(date.day%10d));

		return str;
	}


	public static Date DateFromStringISO8601(char [] str){
		Date date;
		double n;

		date = new Date();

		n = charCharacterToDecimalDigit(str[0])*1000d;
		n = n + charCharacterToDecimalDigit(str[1])*100d;
		n = n + charCharacterToDecimalDigit(str[2])*10d;
		n = n + charCharacterToDecimalDigit(str[3])*1d;

		date.year = n;

		n = charCharacterToDecimalDigit(str[5])*10d;
		n = n + charCharacterToDecimalDigit(str[6])*1d;

		date.month = n;

		n = charCharacterToDecimalDigit(str[8])*10d;
		n = n + charCharacterToDecimalDigit(str[9])*1d;

		date.day = n;

		return date;
	}


	public static bool DateFromStringISO8601WithCheck(char [] str, DateReference dateRef, StringReference message){
		bool valid;

		valid = IsValidDateISO8601(str, message);

		if(valid){
			dateRef.date = DateFromStringISO8601(str);
		}

		return valid;
	}


	public static bool IsValidDateISO8601(char [] str, StringReference message){
		bool valid;

		if(str.Length == 4d + 1d + 2d + 1d + 2d){

			if(charIsNumber(str[0]) && charIsNumber(str[1]) && charIsNumber(str[2]) && charIsNumber(str[3]) && charIsNumber(str[5]) && charIsNumber(str[6]) && charIsNumber(str[8]) && charIsNumber(str[9])){
				if(str[4] == '-' && str[7] == '-'){
					valid = true;
				}else{
					valid = false;
					message.stringx = "ISO8601 date must use \'-\' in positions 5 and 8.".ToCharArray();
				}
			}else{
				valid = false;
				message.stringx = "ISO8601 date must use decimal digits in positions 1, 2, 3, 4, 6, 7, 9 and 10.".ToCharArray();
			}
		}else{
			valid = false;
			message.stringx = "ISO8601 date must be exactly 10 characters long.".ToCharArray();
		}

		return valid;
	}


	public static bool DateEquals(Date a, Date b){
		return a.year == b.year && a.month == b.month && a.day == b.day;
	}


	public static Date CopyDate(Date a){
		Date b;

		b = CreateDate(a.year, a.month, a.day);

		return b;
	}


	public static double GetSecondsFromDate(Date date){
		double seconds, days, secondsInMinute, secondsInHour, secondsInDay;
		NumberReference dayNumberReferenceReference;
		StringReference message;
		bool success;

		seconds = 0d;
		dayNumberReferenceReference = new NumberReference();
		message = new StringReference();

		success = DateToDaysWithCheck(date, dayNumberReferenceReference, message);
		if(success){
			days = dayNumberReferenceReference.numberValue;

			secondsInMinute = 60d;
			secondsInHour = 60d*secondsInMinute;
			secondsInDay = 24d*secondsInHour;

			seconds = seconds + secondsInDay*days;
		}

		delete(dayNumberReferenceReference);
		delete(message);

		return seconds;
	}


	public static bool DateIsInInterval(Interval interval, Date date){
		double from, to, day;

		from = DateToDays(interval.first);
		to = DateToDays(interval.last);
		day = DateToDays(date);

		return day >= from && day <= to;
	}


	public static bool DateLessThan(Date a, Date b){
		double aDays, bDays;

		aDays = DateToDays(a);
		bDays = DateToDays(b);

		return aDays < bDays;
	}


	public static DateTimeTimezone CreateDateTimeTimezone(double year, double month, double day, double hours, double minutes, double seconds, double timezoneOffsetSeconds){
		DateTimeTimezone dateTimeTimezone;

		dateTimeTimezone = new DateTimeTimezone();

		dateTimeTimezone.dateTime = CreateDateTime(year, month, day, hours, minutes, seconds);
		dateTimeTimezone.timezoneOffsetSeconds = timezoneOffsetSeconds;

		return dateTimeTimezone;
	}


	public static DateTimeTimezone CreateDateTimeTimezoneInHoursAndMinutes(double year, double month, double day, double hours, double minutes, double seconds, double timezoneOffsetHours, double timezoneOffsetMinutes){
		DateTimeTimezone dateTimeTimezone;

		dateTimeTimezone = new DateTimeTimezone();

		dateTimeTimezone.dateTime = CreateDateTime(year, month, day, hours, minutes, seconds);
		dateTimeTimezone.timezoneOffsetSeconds = GetSecondsFromHours(timezoneOffsetHours) + GetSecondsFromMinutes(timezoneOffsetMinutes);

		return dateTimeTimezone;
	}


	public static bool GetDateFromDateTimeTimeZone(DateTimeTimezone dateTimeTimezone, DateTimeReference dateTimeReference, StringReference message){
		DateTime dateTime;

		dateTime = dateTimeTimezone.dateTime;

		return AddSecondsToDateTimeWithCheck(dateTime, -dateTimeTimezone.timezoneOffsetSeconds, dateTimeReference, message);
	}


	public static bool CreateDateTimeTimezoneFromDateTimeAndTimeZoneInSeconds(DateTime dateTime, double timezoneOffsetSeconds, DateTimeTimezoneReference dateTimeTimezoneReference, StringReference message){
		bool success;
		DateTimeReference adjustedDateTimeReference;
		DateTimeTimezone dateTimeTimezone;

		adjustedDateTimeReference = new DateTimeReference();
		dateTimeTimezone = new DateTimeTimezone();

		success = AddSecondsToDateTime(dateTime, timezoneOffsetSeconds, adjustedDateTimeReference, message);

		if(success){
			dateTimeTimezone.dateTime = adjustedDateTimeReference.dateTime;
			dateTimeTimezone.timezoneOffsetSeconds = timezoneOffsetSeconds;

			dateTimeTimezoneReference.dateTimeTimezone = dateTimeTimezone;
		}

		return success;
	}


	public static bool CreateDateTimeTimezoneFromDateTimeAndTimeZoneInHoursAndMinutes(DateTime dateTime, double timezoneOffsetHours, double timezoneOffsetMinutes, DateTimeTimezoneReference dateTimeTimezoneReference, StringReference message){
		return CreateDateTimeTimezoneFromDateTimeAndTimeZoneInSeconds(dateTime, GetSecondsFromHours(timezoneOffsetHours) + GetSecondsFromMinutes(timezoneOffsetMinutes), dateTimeTimezoneReference, message);
	}


	public static bool GetDateTimeTimezoneFromSeconds(DateTimeTimezoneReference dateTimeTzRef, double seconds, double offset, StringReference message){
		bool success;
		DateTimeReference dateTimeRef;

		dateTimeRef = new DateTimeReference();
		success = GetDateTimeFromSeconds(seconds, dateTimeRef, message);

		if(success){
			success = CreateDateTimeTimezoneFromDateTimeAndTimeZoneInSeconds(dateTimeRef.dateTime, offset, dateTimeTzRef, message);
		}

		return success;
	}


	public static DateTime CreateDateTime(double year, double month, double day, double hours, double minutes, double seconds){
		DateTime dateTime;

		dateTime = new DateTime();

		dateTime.date = CreateDate(year, month, day);
		dateTime.hours = hours;
		dateTime.minutes = minutes;
		dateTime.seconds = seconds;

		return dateTime;
	}


	public static bool GetDateTimeFromSeconds(double seconds, DateTimeReference dateTimeReference, StringReference message){
		DateTime dateTime;
		double secondsInMinute, secondsInHour, secondsInDay, days, remainder;
		Date date;
		DateReference dateReference;
		bool success;

		secondsInMinute = 60d;
		secondsInHour = 60d*secondsInMinute;
		secondsInDay = 24d*secondsInHour;
		days = Floor(seconds/secondsInDay);
		remainder = seconds - days*secondsInDay;
		dateReference = new DateReference();

		success = DayToDateWithCheck(days, dateReference, message);
		if(success){
			date = dateReference.date;

			dateTime = new DateTime();
			dateTime.date = date;
			dateTime.hours = Floor(remainder/secondsInHour);
			remainder = remainder - dateTime.hours*secondsInHour;
			dateTime.minutes = Floor(remainder/secondsInMinute);
			remainder = remainder - dateTime.minutes*secondsInMinute;
			dateTime.seconds = remainder;

			dateTimeReference.dateTime = dateTime;
		}

		return success;
	}


	public static double GetSecondsFromDateTime(DateTime dateTime){
		double seconds, secondsInMinute, secondsInHour;

		secondsInMinute = 60d;
		secondsInHour = 60d*secondsInMinute;

		seconds = GetSecondsFromDate(dateTime.date);
		seconds = seconds + secondsInHour*dateTime.hours;
		seconds = seconds + secondsInMinute*dateTime.minutes;
		seconds = seconds + dateTime.seconds;

		return seconds;
	}


	public static double GetSecondsFromMinutes(double minutes){
		return minutes*60d;
	}


	public static double GetSecondsFromHours(double hours){
		return GetSecondsFromMinutes(hours*60d);
	}


	public static double GetSecondsFromDays(double days){
		return GetSecondsFromHours(days*24d);
	}


	public static double GetSecondsFromWeeks(double weeks){
		return GetSecondsFromDays(weeks*7d);
	}


	public static double GetMinutesFromSeconds(double seconds){
		return seconds/60d;
	}


	public static double GetHoursFromSeconds(double seconds){
		return GetMinutesFromSeconds(seconds)/60d;
	}


	public static double GetDaysFromSeconds(double seconds){
		return GetHoursFromSeconds(seconds)/24d;
	}


	public static double GetWeeksFromSeconds(double seconds){
		return GetDaysFromSeconds(seconds)/7d;
	}


	public static Date GetDateFromDateTime(DateTime dateTime){
		return dateTime.date;
	}


	public static bool AddSecondsToDateTimeWithCheck(DateTime dateTime, double seconds, DateTimeReference dateTimeReference, StringReference message){
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


	public static bool AddSecondsToDateTime(DateTime dateTime, double seconds, DateTimeReference dateTimeReference, StringReference message){
		double secondsInDateTime;

		secondsInDateTime = GetSecondsFromDateTime(dateTime);
		secondsInDateTime = secondsInDateTime + seconds;

		return GetDateTimeFromSeconds(secondsInDateTime, dateTimeReference, message);
	}


	public static bool AddMinutesToDateTime(DateTime dateTime, double minutes, DateTimeReference dateTimeReference, StringReference message){
		return AddSecondsToDateTime(dateTime, GetSecondsFromMinutes(minutes), dateTimeReference, message);
	}


	public static bool AddHoursToDateTime(DateTime dateTime, double hours, DateTimeReference dateTimeReference, StringReference message){
		return AddSecondsToDateTime(dateTime, GetSecondsFromHours(hours), dateTimeReference, message);
	}


	public static bool AddDaysToDateTime(DateTime dateTime, double days, DateTimeReference dateTimeReference, StringReference message){
		return AddSecondsToDateTime(dateTime, GetSecondsFromDays(days), dateTimeReference, message);
	}


	public static bool AddWeeksToDateTime(DateTime dateTime, double weeks, DateTimeReference dateTimeReference, StringReference message){
		return AddSecondsToDateTime(dateTime, GetSecondsFromWeeks(weeks), dateTimeReference, message);
	}


	public static bool DateTimeToStringISO8601WithCheck(DateTime datetime, StringReference dateStr, StringReference message){
		bool success;

		success = DateToStringISO8601WithCheck(datetime.date, dateStr, message);

		if(success){
			delete(dateStr.stringx);

			success = IsValidDateTime(datetime, message);
			if(success){
				dateStr.stringx = DateTimeToStringISO8601(datetime);
			}
		}

		return success;
	}


	public static bool IsValidDateTime(DateTime datetime, StringReference message){
		bool success;

		success = IsValidDate(datetime.date, message);

		if(success){
			if(datetime.hours <= 23d && datetime.hours >= 0d){
				if(datetime.minutes <= 59d && datetime.minutes >= 0d){
					if(datetime.seconds <= 59d && datetime.seconds >= 0d){
						success = true;
					}else{
						success = false;
						message.stringx = "Seconds must be between 0 and 59.".ToCharArray();
					}
				}else{
					success = false;
					message.stringx = "Minutes must be between 0 and 59.".ToCharArray();
				}
			}else{
				success = false;
				message.stringx = "Hours must be between 0 and 23.".ToCharArray();
			}
		}

		return success;
	}


	public static char [] DateTimeToStringISO8601(DateTime datetime){
		char [] datestr, str;
		double i;

		str = new char [19];

		datestr = DateToStringISO8601(datetime.date);
		for(i = 0d; i < datestr.Length; i = i + 1d){
			str[(int)(i)] = datestr[(int)(i)];
		}

		str[10] = 'T';
		str[11] = charDecimalDigitToCharacter(Floor((datetime.hours%100d)/10d));
		str[12] = charDecimalDigitToCharacter(Floor(datetime.hours%10d));

		str[13] = ':';

		str[14] = charDecimalDigitToCharacter(Floor((datetime.minutes%100d)/10d));
		str[15] = charDecimalDigitToCharacter(Floor(datetime.minutes%10d));

		str[16] = ':';

		str[17] = charDecimalDigitToCharacter(Floor((datetime.seconds%100d)/10d));
		str[18] = charDecimalDigitToCharacter(Floor(datetime.seconds%10d));

		return str;
	}


	public static DateTime DateTimeFromStringISO8601(char [] str){
		DateTime dateTime;
		double n;

		dateTime = new DateTime();

		dateTime.date = DateFromStringISO8601(str);

		n = charCharacterToDecimalDigit(str[11])*10d;
		n = n + charCharacterToDecimalDigit(str[12])*1d;

		dateTime.hours = n;

		n = charCharacterToDecimalDigit(str[14])*10d;
		n = n + charCharacterToDecimalDigit(str[15])*1d;

		dateTime.minutes = n;

		n = charCharacterToDecimalDigit(str[17])*10d;
		n = n + charCharacterToDecimalDigit(str[18])*1d;

		dateTime.seconds = n;

		return dateTime;
	}


	public static bool DateTimeFromStringISO8601WithCheck(char [] str, DateTimeReference dateTimeRef, StringReference message){
		bool valid;

		valid = IsValidDateTimeISO8601(str, message);

		if(valid){
			dateTimeRef.dateTime = DateTimeFromStringISO8601(str);
		}

		return valid;
	}


	public static bool IsValidDateTimeISO8601(char [] str, StringReference message){
		bool valid;

		if(str.Length == 4d + 1d + 2d + 1d + 2d + 1d + 2d + 1d + 2d + 1d + 2d){

			if(charIsNumber(str[0]) && charIsNumber(str[1]) && charIsNumber(str[2]) && charIsNumber(str[3]) && charIsNumber(str[5]) && charIsNumber(str[6]) && charIsNumber(str[8]) && charIsNumber(str[9]) && charIsNumber(str[11]) && charIsNumber(str[12]) && charIsNumber(str[14]) && charIsNumber(str[15]) && charIsNumber(str[17]) && charIsNumber(str[18])){
				if(str[4] == '-' && str[7] == '-' && str[10] == 'T' && str[13] == ':' && str[16] == ':'){
					valid = true;
				}else{
					valid = false;
					message.stringx = "ISO8601 date must use \'-\' in positions 5 and 8, \'T\' in position 11 and \':\' in positions 14 and 17.".ToCharArray();
				}
			}else{
				valid = false;
				message.stringx = "ISO8601 date must use decimal digits in positions 1, 2, 3, 4, 6, 7, 9, 10, 12, 13, 15, 16, 18 and 19.".ToCharArray();
			}
		}else{
			valid = false;
			message.stringx = "ISO8601 date must be exactly 19 characters long.".ToCharArray();
		}

		return valid;
	}


	public static bool DateTimeEquals(DateTime a, DateTime b){
		return DateEquals(a.date, b.date) && a.hours == b.hours && a.minutes == b.minutes && a.seconds == b.seconds;
	}


	public static void FreeDateTime(DateTime datetime){
		delete(datetime.date);
		delete(datetime);
	}


	public static char charToLowerCase(char character){
		char toReturn;

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


	public static char charToUpperCase(char character){
		char toReturn;

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


	public static bool charIsUpperCase(char character){
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


	public static bool charIsLowerCase(char character){
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


	public static bool charIsLetter(char character){
		return charIsUpperCase(character) || charIsLowerCase(character);
	}


	public static bool charIsNumber(char character){
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


	public static bool charIsWhiteSpace(char character){
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


	public static bool charIsSymbol(char character){
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


	public static bool charCharacterIsBefore(char a, char b){
		double ad, bd;

		ad = a;
		bd = b;

		return ad < bd;
	}


	public static char charDecimalDigitToCharacter(double digit){
		char c;
		if(digit == 1d){
			c = '1';
		}else if(digit == 2d){
			c = '2';
		}else if(digit == 3d){
			c = '3';
		}else if(digit == 4d){
			c = '4';
		}else if(digit == 5d){
			c = '5';
		}else if(digit == 6d){
			c = '6';
		}else if(digit == 7d){
			c = '7';
		}else if(digit == 8d){
			c = '8';
		}else if(digit == 9d){
			c = '9';
		}else{
			c = '0';
		}
		return c;
	}


	public static double charCharacterToDecimalDigit(char c){
		double digit;

		if(c == '1'){
			digit = 1d;
		}else if(c == '2'){
			digit = 2d;
		}else if(c == '3'){
			digit = 3d;
		}else if(c == '4'){
			digit = 4d;
		}else if(c == '5'){
			digit = 5d;
		}else if(c == '6'){
			digit = 6d;
		}else if(c == '7'){
			digit = 7d;
		}else if(c == '8'){
			digit = 8d;
		}else if(c == '9'){
			digit = 9d;
		}else{
			digit = 0d;
		}

		return digit;
	}


	public static void AssertFalse(bool b, NumberReference failures){
		if(b){
			failures.numberValue = failures.numberValue + 1d;
		}
	}


	public static void AssertTrue(bool b, NumberReference failures){
		if(!b){
			failures.numberValue = failures.numberValue + 1d;
		}
	}


	public static void AssertEquals(double a, double b, NumberReference failures){
		if(a != b){
			failures.numberValue = failures.numberValue + 1d;
		}
	}


	public static void AssertBooleansEqual(bool a, bool b, NumberReference failures){
		if(a != b){
			failures.numberValue = failures.numberValue + 1d;
		}
	}


	public static void AssertCharactersEqual(char a, char b, NumberReference failures){
		if(a != b){
			failures.numberValue = failures.numberValue + 1d;
		}
	}


	public static void AssertStringEquals(char [] a, char [] b, NumberReference failures){
		if(!StringsEqual(a, b)){
			failures.numberValue = failures.numberValue + 1d;
		}
	}


	public static void AssertNumberArraysEqual(double [] a, double [] b, NumberReference failures){
		double i;

		if(a.Length == b.Length){
			for(i = 0d; i < a.Length; i = i + 1d){
				AssertEquals(a[(int)(i)], b[(int)(i)], failures);
			}
		}else{
			failures.numberValue = failures.numberValue + 1d;
		}
	}


	public static void AssertBooleanArraysEqual(bool [] a, bool [] b, NumberReference failures){
		double i;

		if(a.Length == b.Length){
			for(i = 0d; i < a.Length; i = i + 1d){
				AssertBooleansEqual(a[(int)(i)], b[(int)(i)], failures);
			}
		}else{
			failures.numberValue = failures.numberValue + 1d;
		}
	}


	public static void AssertStringArraysEqual(StringReference [] a, StringReference [] b, NumberReference failures){
		double i;

		if(a.Length == b.Length){
			for(i = 0d; i < a.Length; i = i + 1d){
				AssertStringEquals(a[(int)(i)].stringx, b[(int)(i)].stringx, failures);
			}
		}else{
			failures.numberValue = failures.numberValue + 1d;
		}
	}


	public static double Negate(double x){
		return -x;
	}


	public static double Positive(double x){
		return +x;
	}


	public static double Factorial(double x){
		double i, f;

		f = 1d;

		for(i = 2d; i <= x; i = i + 1d){
			f = f*i;
		}

		return f;
	}


	public static double Roundx(double x){
		return Floor(x + 0.5);
	}


	public static double BankersRound(double x){
		double r;

		if(Absolute(x - Truncate(x)) == 0.5){
			if(!DivisibleBy(Roundx(x), 2d)){
				r = Roundx(x) - 1d;
			}else{
				r = Roundx(x);
			}
		}else{
			r = Roundx(x);
		}

		return r;
	}


	public static double Ceil(double x){
		return Ceiling(x);
	}


	public static double Floorx(double x){
		return Floor(x);
	}


	public static double Truncate(double x){
		double t;

		if(x >= 0d){
			t = Floor(x);
		}else{
			t = Ceiling(x);
		}

		return t;
	}


	public static double Absolute(double x){
		return Abs(x);
	}


	public static double Logarithm(double x){
		return Log10(x);
	}


	public static double NaturalLogarithm(double x){
		return Log(x);
	}


	public static double Sinx(double x){
		return Sin(x);
	}


	public static double Cosx(double x){
		return Cos(x);
	}


	public static double Tanx(double x){
		return Tan(x);
	}


	public static double Asinx(double x){
		return Asin(x);
	}


	public static double Acosx(double x){
		return Acos(x);
	}


	public static double Atanx(double x){
		return Atan(x);
	}


	public static double Atan2(double y, double x){
		double a;

		/* Atan2 is an invalid operation when x = 0 and y = 0, but this method does not return errors.*/
		a = 0d;

		if(x > 0d){
			a = Atanx(y/x);
		}else if(x < 0d && y >= 0d){
			a = Atanx(y/x) + PI;
		}else if(x < 0d && y < 0d){
			a = Atanx(y/x) - PI;
		}else if(x == 0d && y > 0d){
			a = PI/2d;
		}else if(x == 0d && y < 0d){
			a = -PI/2d;
		}

		return a;
	}


	public static double Squareroot(double x){
		return Sqrt(x);
	}


	public static double Expx(double x){
		return Exp(x);
	}


	public static bool DivisibleBy(double a, double b){
		return ((a%b) == 0d);
	}


	public static double Combinations(double n, double k){
		double i, j, c;

		c = 1d;
		j = 1d;
		i = n - k + 1d;

		for(; i <= n; ){
			c = c*i;
			c = c/j;

			i = i + 1d;
			j = j + 1d;
		}

		return c;
	}


	public static double Permutations(double n, double k){
		double i, c;

		c = 1d;

		for(i = n - k + 1d; i <= n; i = i + 1d){
			c = c*i;
		}

		return c;
	}


	public static bool EpsilonCompare(double a, double b, double epsilon){
		return Abs(a - b) < epsilon;
	}


	public static double GreatestCommonDivisor(double a, double b){
		double t;

		for(; b != 0d; ){
			t = b;
			b = a%b;
			a = t;
		}

		return a;
	}


	public static double GCDWithSubtraction(double a, double b){
		double g;

		if(a == 0d){
			g = b;
		}else{
			for(; b != 0d; ){
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


	public static bool IsInteger(double a){
		return (a - Floor(a)) == 0d;
	}


	public static bool GreatestCommonDivisorWithCheck(double a, double b, NumberReference gcdReference){
		bool success;
		double gcd;

		if(IsInteger(a) && IsInteger(b)){
			gcd = GreatestCommonDivisor(a, b);
			gcdReference.numberValue = gcd;
			success = true;
		}else{
			success = false;
		}

		return success;
	}


	public static double LeastCommonMultiple(double a, double b){
		double lcm;

		if(a > 0d && b > 0d){
			lcm = Abs(a*b)/GreatestCommonDivisor(a, b);
		}else{
			lcm = 0d;
		}

		return lcm;
	}


	public static double Sign(double a){
		double s;

		if(a > 0d){
			s = 1d;
		}else if(a < 0d){
			s = -1d;
		}else{
			s = 0d;
		}

		return s;
	}


	public static double Maxx(double a, double b){
		return Max(a, b);
	}


	public static double Minx(double a, double b){
		return Min(a, b);
	}


	public static double Power(double a, double b){
		return Pow(a, b);
	}


	public static double Gamma(double x){
		return LanczosApproximation(x);
	}


	public static double LogGamma(double x){
		return Log(Gamma(x));
	}


	public static double LanczosApproximation(double z){
		double [] p;
		double i, y, t, x;

		p = new double [8];
		p[0] = 676.5203681218851;
		p[1] = -1259.1392167224028;
		p[2] = 771.32342877765313;
		p[3] = -176.61502916214059;
		p[4] = 12.507343278686905;
		p[5] = -0.13857109526572012;
		p[6] = 9.9843695780195716e-6;
		p[7] = 1.5056327351493116e-7;

		if(z < 0.5){
			y = PI/(Sin(PI*z)*LanczosApproximation(1d - z));
		}else{
			z = z - 1d;
			x = 0.99999999999980993;
			for(i = 0d; i < p.Length; i = i + 1d){
				x = x + p[(int)(i)]/(z + i + 1d);
			}
			t = z + p.Length - 0.5;
			y = Sqrt(2d*PI)*Pow(t, z + 0.5)*Exp(-t)*x;
		}

		return y;
	}


	public static double Beta(double x, double y){
		return Gamma(x)*Gamma(y)/Gamma(x + y);
	}


	public static double Sinh(double x){
		return (Exp(x) - Exp(-x))/2d;
	}


	public static double Cosh(double x){
		return (Exp(x) + Exp(-x))/2d;
	}


	public static double Tanh(double x){
		return Sinh(x)/Cosh(x);
	}


	public static double Cot(double x){
		return 1d/Tan(x);
	}


	public static double Sec(double x){
		return 1d/Cos(x);
	}


	public static double Csc(double x){
		return 1d/Sin(x);
	}


	public static double Coth(double x){
		return Cosh(x)/Sinh(x);
	}


	public static double Sech(double x){
		return 1d/Cosh(x);
	}


	public static double Csch(double x){
		return 1d/Sinh(x);
	}


	public static double Error(double x){
		double y, t, tau, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;

		if(x == 0d){
			y = 0d;
		}else if(x < 0d){
			y = -Error(-x);
		}else{
			c1 = -1.26551223;
			c2 = +1.00002368;
			c3 = +0.37409196;
			c4 = +0.09678418;
			c5 = -0.18628806;
			c6 = +0.27886807;
			c7 = -1.13520398;
			c8 = +1.48851587;
			c9 = -0.82215223;
			c10 = +0.17087277;

			t = 1d/(1d + 0.5*Abs(x));

			tau = t*Exp(-Pow(x, 2d) + c1 + t*(c2 + t*(c3 + t*(c4 + t*(c5 + t*(c6 + t*(c7 + t*(c8 + t*(c9 + t*c10)))))))));

			y = 1d - tau;
		}

		return y;
	}


	public static double ErrorInverse(double x){
		double y, a, t;

		a = (8d*(PI - 3d))/(3d*PI*(4d - PI));

		t = 2d/(PI*a) + Log(1d - Pow(x, 2d))/2d;
		y = Sign(x)*Sqrt(Sqrt(Pow(t, 2d) - Log(1d - Pow(x, 2d))/a) - t);

		return y;
	}


	public static double FallingFactorial(double x, double n){
		double k, y;

		y = 1d;

		for(k = 0d; k <= n - 1d; k = k + 1d){
			y = y*(x - k);
		}

		return y;
	}


	public static double RisingFactorial(double x, double n){
		double k, y;

		y = 1d;

		for(k = 0d; k <= n - 1d; k = k + 1d){
			y = y*(x + k);
		}

		return y;
	}


	public static double Hypergeometric(double a, double b, double c, double z, double maxIterations, double precision){
		double y;

		if(Abs(z) >= 0.5){
			y = Pow(1d - z, -a)*HypergeometricDirect(a, c - b, c, z/(z - 1d), maxIterations, precision);
		}else{
			y = HypergeometricDirect(a, b, c, z, maxIterations, precision);
		}

		return y;
	}


	public static double HypergeometricDirect(double a, double b, double c, double z, double maxIterations, double precision){
		double y, yp, n;
		bool done;

		y = 0d;
		done = false;

		for(n = 0d; n < maxIterations && !done; n = n + 1d){
			yp = RisingFactorial(a, n)*RisingFactorial(b, n)/RisingFactorial(c, n)*Pow(z, n)/Factorial(n);
			if(Abs(yp) < precision){
				done = true;
			}
			y = y + yp;
		}

		return y;
	}


	public static double BernouilliNumber(double n){
		return AkiyamaTanigawaAlgorithm(n);
	}


	public static double AkiyamaTanigawaAlgorithm(double n){
		double m, j, B;
		double [] A;

		A = new double [(int)(n + 1d)];

		for(m = 0d; m <= n; m = m + 1d){
			A[(int)(m)] = 1d/(m + 1d);
			for(j = m; j >= 1d; j = j - 1d){
				A[(int)(j - 1d)] = j*(A[(int)(j - 1d)] - A[(int)(j)]);
			}
		}

		B = A[0];

		delete(A);

		return B;
	}


	public static double [] StringToNumberArray(char [] stringx){
		double i;
		double [] array;

		array = new double [(int)(stringx.Length)];

		for(i = 0d; i < stringx.Length; i = i + 1d){
			array[(int)(i)] = stringx[(int)(i)];
		}
		return array;
	}


	public static char [] NumberArrayToString(double [] array){
		double i;
		char [] stringx;

		stringx = new char [(int)(array.Length)];

		for(i = 0d; i < array.Length; i = i + 1d){
			stringx[(int)(i)] = (char)(array[(int)(i)]);
		}
		return stringx;
	}


	public static bool NumberArraysEqual(double [] a, double [] b){
		bool equal;
		double i;

		equal = true;
		if(a.Length == b.Length){
			for(i = 0d; i < a.Length && equal; i = i + 1d){
				if(a[(int)(i)] != b[(int)(i)]){
					equal = false;
				}
			}
		}else{
			equal = false;
		}

		return equal;
	}


	public static bool BooleanArraysEqual(bool [] a, bool [] b){
		bool equal;
		double i;

		equal = true;
		if(a.Length == b.Length){
			for(i = 0d; i < a.Length && equal; i = i + 1d){
				if(a[(int)(i)] != b[(int)(i)]){
					equal = false;
				}
			}
		}else{
			equal = false;
		}

		return equal;
	}


	public static bool StringsEqual(char [] a, char [] b){
		bool equal;
		double i;

		equal = true;
		if(a.Length == b.Length){
			for(i = 0d; i < a.Length && equal; i = i + 1d){
				if(a[(int)(i)] != b[(int)(i)]){
					equal = false;
				}
			}
		}else{
			equal = false;
		}

		return equal;
	}


	public static void FillNumberArray(double [] a, double value){
		double i;

		for(i = 0d; i < a.Length; i = i + 1d){
			a[(int)(i)] = value;
		}
	}


	public static void FillString(char [] a, char value){
		double i;

		for(i = 0d; i < a.Length; i = i + 1d){
			a[(int)(i)] = value;
		}
	}


	public static void FillBooleanArray(bool [] a, bool value){
		double i;

		for(i = 0d; i < a.Length; i = i + 1d){
			a[(int)(i)] = value;
		}
	}


	public static bool FillNumberArrayRange(double [] a, double value, double from, double to){
		double i, length;
		bool success;

		if(from >= 0d && from <= a.Length && to >= 0d && to <= a.Length && from <= to){
			length = to - from;
			for(i = 0d; i < length; i = i + 1d){
				a[(int)(from + i)] = value;
			}

			success = true;
		}else{
			success = false;
		}

		return success;
	}


	public static bool FillBooleanArrayRange(bool [] a, bool value, double from, double to){
		double i, length;
		bool success;

		if(from >= 0d && from <= a.Length && to >= 0d && to <= a.Length && from <= to){
			length = to - from;
			for(i = 0d; i < length; i = i + 1d){
				a[(int)(from + i)] = value;
			}

			success = true;
		}else{
			success = false;
		}

		return success;
	}


	public static bool FillStringRange(char [] a, char value, double from, double to){
		double i, length;
		bool success;

		if(from >= 0d && from <= a.Length && to >= 0d && to <= a.Length && from <= to){
			length = to - from;
			for(i = 0d; i < length; i = i + 1d){
				a[(int)(from + i)] = value;
			}

			success = true;
		}else{
			success = false;
		}

		return success;
	}


	public static double [] CopyNumberArray(double [] a){
		double i;
		double [] n;

		n = new double [(int)(a.Length)];

		for(i = 0d; i < a.Length; i = i + 1d){
			n[(int)(i)] = a[(int)(i)];
		}

		return n;
	}


	public static bool [] CopyBooleanArray(bool [] a){
		double i;
		bool [] n;

		n = new bool [(int)(a.Length)];

		for(i = 0d; i < a.Length; i = i + 1d){
			n[(int)(i)] = a[(int)(i)];
		}

		return n;
	}


	public static char [] CopyString(char [] a){
		double i;
		char [] n;

		n = new char [(int)(a.Length)];

		for(i = 0d; i < a.Length; i = i + 1d){
			n[(int)(i)] = a[(int)(i)];
		}

		return n;
	}


	public static bool CopyNumberArrayRange(double [] a, double from, double to, NumberArrayReference copyReference){
		double i, length;
		double [] n;
		bool success;

		if(from >= 0d && from <= a.Length && to >= 0d && to <= a.Length && from <= to){
			length = to - from;
			n = new double [(int)(length)];

			for(i = 0d; i < length; i = i + 1d){
				n[(int)(i)] = a[(int)(from + i)];
			}

			copyReference.numberArray = n;
			success = true;
		}else{
			success = false;
		}

		return success;
	}


	public static bool CopyBooleanArrayRange(bool [] a, double from, double to, BooleanArrayReference copyReference){
		double i, length;
		bool [] n;
		bool success;

		if(from >= 0d && from <= a.Length && to >= 0d && to <= a.Length && from <= to){
			length = to - from;
			n = new bool [(int)(length)];

			for(i = 0d; i < length; i = i + 1d){
				n[(int)(i)] = a[(int)(from + i)];
			}

			copyReference.booleanArray = n;
			success = true;
		}else{
			success = false;
		}

		return success;
	}


	public static bool CopyStringRange(char [] a, double from, double to, StringReference copyReference){
		double i, length;
		char [] n;
		bool success;

		if(from >= 0d && from <= a.Length && to >= 0d && to <= a.Length && from <= to){
			length = to - from;
			n = new char [(int)(length)];

			for(i = 0d; i < length; i = i + 1d){
				n[(int)(i)] = a[(int)(from + i)];
			}

			copyReference.stringx = n;
			success = true;
		}else{
			success = false;
		}

		return success;
	}


	public static bool IsLastElement(double length, double index){
		return index + 1d == length;
	}


	public static double [] CreateNumberArray(double length, double value){
		double [] array;

		array = new double [(int)(length)];
		FillNumberArray(array, value);

		return array;
	}


	public static bool [] CreateBooleanArray(double length, bool value){
		bool [] array;

		array = new bool [(int)(length)];
		FillBooleanArray(array, value);

		return array;
	}


	public static char [] CreateString(double length, char value){
		char [] array;

		array = new char [(int)(length)];
		FillString(array, value);

		return array;
	}


	public static void SwapElementsOfNumberArray(double [] A, double ai, double bi){
		double tmp;

		tmp = A[(int)(ai)];
		A[(int)(ai)] = A[(int)(bi)];
		A[(int)(bi)] = tmp;
	}


	public static void SwapElementsOfStringArray(StringArrayReference A, double ai, double bi){
		StringReference tmp;

		tmp = A.stringArray[(int)(ai)];
		A.stringArray[(int)(ai)] = A.stringArray[(int)(bi)];
		A.stringArray[(int)(bi)] = tmp;
	}


	public static void ReverseNumberArray(double [] array){
		double i;

		for(i = 0d; i < array.Length/2d; i = i + 1d){
			SwapElementsOfNumberArray(array, i, array.Length - i - 1d);
		}
	}


	public static void delete(System.Object objectx){
		// C# has garbage collection.
	}
}


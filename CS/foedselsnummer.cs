using static System.Math;

public class BooleanReference{
	public bool booleanValue;
}
public class DoubleReference{
	public double doubleValue;
}
public class StringReference{
	public char [] stringx;
}
public class StringToDecimalResult{
	public double result;
	public char [] feilmelding;
	public bool success;
}
public class datetimeDateTime{
	public double year;
	public double month;
	public double day;
	public double hours;
	public double minutes;
	public double seconds;
}
public class datetimeSuccess{
	public bool success;
	public char [] errorMessage;
}
public class datetimeDate{
	public double year;
	public double month;
	public double day;
}
public class DecimalListRef{
	public double [] list;
}
public class StringListRef{
	public StringReference [] list;
}
public class foedselsnummer{
	public static bool isValidNorwegianPersonalIdentificationNumber(char [] fnummer){
		bool gyldig;
		double d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
		datetimeDate aDatetimeDate;
		double k1, k2;
		DoubleReference failures;

		if(fnummer.Length == 11d){
			failures = new DoubleReference();
			failures.doubleValue = 0d;
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
			if(failures.doubleValue == 0d){
				aDatetimeDate = getDateFromNorwegianPersonalIdentificationNumber(fnummer, failures);
				if(datetimeisValidDate(aDatetimeDate)){
					if(failures.doubleValue == 0d){
						k1 = d1*3d + d2*7d + d3*6d + d4*1d + d5*8d + d6*9d + d7*4d + d8*5d + d9*2d;
						k1 = k1%11d;
						if(k1 != 0d){
							k1 = 11d - k1;
						}
						if(k1 == 10d){
							failures.doubleValue = failures.doubleValue + 1d;
						}
						k2 = d1*5d + d2*4d + d3*3d + d4*2d + d5*7d + d6*6d + d7*5d + d8*4d + d9*3d + k1*2d;
						k2 = k2%11d;
						if(k2 != 0d){
							k2 = 11d - k2;
						}
						if(k2 == 10d){
							failures.doubleValue = failures.doubleValue + 1d;
						}
						if(k1 == d10 && k2 == d11 && failures.doubleValue == 0d){
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


	public static datetimeDate getDateFromNorwegianPersonalIdentificationNumber(char [] fnummer, DoubleReference failures){
		datetimeDate aDatetimeDate;
		double individnummer;
		double day, month, year;
		double d1, d2, d3, d4, d5, d6, d7, d8, d9;

		aDatetimeDate = new datetimeDate();

		d1 = charToNumber(fnummer[0], failures);
		d2 = charToNumber(fnummer[1], failures);
		d3 = charToNumber(fnummer[2], failures);
		d4 = charToNumber(fnummer[3], failures);
		d5 = charToNumber(fnummer[4], failures);
		d6 = charToNumber(fnummer[5], failures);
		d7 = charToNumber(fnummer[6], failures);
		d8 = charToNumber(fnummer[7], failures);
		d9 = charToNumber(fnummer[8], failures);

		if(failures.doubleValue == 0d){
			individnummer = d7*100d + d8*10d + d9;
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
				year = year + 1900d;
			}else{
				failures.doubleValue = failures.doubleValue + 1d;
			}



			aDatetimeDate.year = year;
			aDatetimeDate.month = month;
			aDatetimeDate.day = day;
		}

		return aDatetimeDate;
	}


	public static double charToNumber(char c, DoubleReference failures){
		double val;

		if(isNumber(c, 10d)){
			val = getDecimalFromSingleDecimalDigit(c, 10d);
		}else{
			val = 0d;
			failures.doubleValue = failures.doubleValue + 1d;
		}

		return val;
	}


	public static double test1(){
		DoubleReference failures;

		failures = new DoubleReference();
		failures.doubleValue = 0d;

		assertTrue(isValidNorwegianPersonalIdentificationNumber("10061270707".ToCharArray()), failures);

		return failures.doubleValue;
	}


	public static double test(){
		double failures;

		failures = 0d;

		failures = failures + test1();

		return failures;
	}


	public static char [] decimalToString(double decimalx){

		return numberToString(decimalx, 10d);
	}


	public static char [] numberToString(double decimalx, double basex){
		char [] stringx;
		double digits;
		double digitPosition;
		bool hasPrintedPoint;
		double i, d;

		stringx = new char [0];

		digits = getDigits(basex);

		/* Find digitPosition:*/
		digitPosition = getDigitPosition(decimalx, basex);

		decimalx = (double)Round(decimalx*Pow(basex, -digitPosition  + digits - 1d));

		hasPrintedPoint = false;

		/* Print leading zeros.*/
		if(digitPosition < 0d){
			stringx = appendCharacter(stringx, '0');
			stringx = appendCharacter(stringx, '.');
			hasPrintedPoint = true;
			for(i = 0d; i < -digitPosition  - 1d; i = i + 1d){
				stringx = appendCharacter(stringx, '0');
			}
		}

		/* Print number.*/
		for(i = 0d; i < digits; i = i + 1d){
			d = Floor(decimalx/Pow(basex, digits - i - 1d));
			if(!hasPrintedPoint && digitPosition - i + 1d == 0d){
				if(decimalx != 0d){
					stringx = appendCharacter(stringx, '.');
				}
				hasPrintedPoint = true;
			}
			if(decimalx == 0d && hasPrintedPoint){
			}else{
				stringx = appendCharacter(stringx, getSingleDigitFromNumber(d, basex));
			}
			decimalx = decimalx - d*Pow(basex, digits - i - 1d);
		}

		/* Print trailing zeros.*/
		for(i = 0d; i < digitPosition - digits + 1d; i = i + 1d){
			stringx = appendCharacter(stringx, '0');
		}

		/* Done*/
		return stringx;
	}


	public static double getDigits(double basex){
		double t;

		t = Pow(10d, 15d);
		return Floor(Log10(t)/Log10(basex));
	}


	public static double getDigitPosition(double decimalx, double basex){
		double power;
		double t;

		power = Ceiling(Log10(decimalx)/Log10(basex));

		t = decimalx*Pow(basex, -power );
		if(t < basex && t >= 1d){
		}else if(t >= basex){
			power = power + 1d;
		}else if(t < 1d){
			power = power - 1d;
		}


		return power;
	}


	public static char getSingleDigitFromNumber(double c, double basex){
		char [] numberTable;
		char retc;

		numberTable = getNumberTable();

		if(c > basex - 1d){
			retc = '?';
		}else{
			retc = numberTable[(int)(c)];
		}

		return retc;
	}


	public static char [] getNumberTable(){
		char [] numberTable;

		numberTable = new char [16];
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


	public static StringToDecimalResult stringToDecimal(char [] stringx){

		return stringToDecimalForBase(stringx, 10d);
	}


	public static StringToDecimalResult stringToDecimalForBase(char [] stringx, double basex){
		StringToDecimalResult stringToDecimalResult;
		char c;
		double i, j;
		bool isPositive;
		double beforeDecimalPoint;
		double afterDecimalPoint;
		double n;
		double validCharacters;
		double d;

		stringToDecimalResult = new StringToDecimalResult();
		stringToDecimalResult.success = true;
		i = 0d;
		isPositive = true;
		beforeDecimalPoint = 0d;
		afterDecimalPoint = 0d;
		n = 0d;
		validCharacters = 0d;

		if(basex >= 2d && basex <= 16d){
			for(j = 0d; j < stringx.Length; j = j + 1d){
				c = stringx[(int)(j)];
				if(isNumber(c, basex) || c == '.' || c == '-'){
					validCharacters = validCharacters + 1d;
				}
			}
			if(validCharacters == stringx.Length){
				if(stringx.Length > 0d){
					c = stringx[(int)(i)];
					if(c == '-'){
						isPositive = false;
						i = i + 1d;
					}
					if(i < stringx.Length){
						c = stringx[(int)(i)];
						if(isNumber(c, basex)){
							for(; isNumber(c, basex) && (i < stringx.Length); ){
								beforeDecimalPoint = beforeDecimalPoint + 1d;
								i = i + 1d;
								if(i < stringx.Length){
									c = stringx[(int)(i)];
								}
							}
							if(i < stringx.Length){
								c = stringx[(int)(i)];
								if(c == '.'){
									i = i + 1d;
									if(i < stringx.Length){
										c = stringx[(int)(i)];
										for(; isNumber(c, basex) && (i < stringx.Length); ){
											afterDecimalPoint = afterDecimalPoint + 1d;
											i = i + 1d;
											if(i < stringx.Length){
												c = stringx[(int)(i)];
											}
										}
									}else{
										stringToDecimalResult.success = false;
										stringToDecimalResult.feilmelding = "Number must have digits after the decimal point.".ToCharArray();
									}
								}
							}
						}else{
							stringToDecimalResult.success = false;
							stringToDecimalResult.feilmelding = "Number must start with digits (for negative numbers, after the optional negative sign).".ToCharArray();
						}
					}
					if(stringToDecimalResult.success != false){
						i = 0d;
						if(!isPositive){
							i = 1d;
						}
						for(j = 0d; j < beforeDecimalPoint; j = j + 1d){
							c = stringx[(int)(i)];
							i = i + 1d;
							d = getDecimalFromSingleDecimalDigit(c, basex);
							n = n + d*Pow(basex, beforeDecimalPoint - j - 1d);
						}
						if(afterDecimalPoint > 0d){
							i = i + 1d;
							for(j = 0d; j < afterDecimalPoint; j = j + 1d){
								c = stringx[(int)(i)];
								i = i + 1d;
								d = getDecimalFromSingleDecimalDigit(c, basex);
								n = n + d*Pow(basex, 0d - j - 1d);
							}
						}
						if(!isPositive){
							n = -n ;
						}
						stringToDecimalResult.result = n;
						stringToDecimalResult.success = true;
					}
				}else{
					stringToDecimalResult.success = false;
					stringToDecimalResult.feilmelding = "String has no content.".ToCharArray();
				}
			}else{
				stringToDecimalResult.success = false;
				stringToDecimalResult.feilmelding = "String contains invalid character.".ToCharArray();
			}
		}else{
			stringToDecimalResult.success = false;
			stringToDecimalResult.feilmelding = "Base must be from 2 to 16.".ToCharArray();
		}

		return stringToDecimalResult;
	}


	public static double getDecimalFromSingleDecimalDigit(char c, double basex){
		char [] numberTable;
		double i;
		double position;

		numberTable = getNumberTable();
		position = 0d;

		for(i = 0d; i < basex; i = i + 1d){
			if(numberTable[(int)(i)] == c){
				position = i;
			}
		}

		return position;
	}


	public static bool isNumber(char c, double basex){
		char [] numberTable;
		double i;
		bool found;

		numberTable = getNumberTable();
		found = false;

		for(i = 0d; i < basex; i = i + 1d){
			if(numberTable[(int)(i)] == c){
				found = true;
			}
		}

		return found;
	}


	public static datetimeDateTime datetimegetDateTimeFromSeconds(double seconds){
		datetimeDateTime dateTime;
		double secondsInMinute, secondsInHour, secondsInDay, days, remainder;
		datetimeDate date;

		dateTime = new datetimeDateTime();

		secondsInMinute = 60d;
		secondsInHour = 60d*secondsInMinute;
		secondsInDay = 24d*secondsInHour;
		days = Floor(seconds/secondsInDay);
		remainder = seconds - days*secondsInDay;

		date = datetimedayToDate(days, new datetimeSuccess());
		dateTime.year = date.year;
		dateTime.month = date.month;
		dateTime.day = date.day;

		dateTime.hours = Floor(remainder/secondsInHour);
		remainder = remainder - dateTime.hours*secondsInHour;
		dateTime.minutes = Floor(remainder/secondsInMinute);
		remainder = remainder - dateTime.minutes*secondsInMinute;
		dateTime.seconds = remainder;

		return dateTime;
	}


	public static double datetimegetSecondsFromDateTime(datetimeDateTime dateTime){
		datetimeDate date;
		double seconds;
		double days;
		double secondsInMinute;
		double secondsInHour;
		double secondsInDay;

		seconds = 0d;

		date = new datetimeDate();
		date.year = dateTime.year;
		date.month = dateTime.month;
		date.day = dateTime.day;

		days = datetimedateToDayNumber(date, new datetimeSuccess());

		secondsInMinute = 60d;
		secondsInHour = 60d*secondsInMinute;
		secondsInDay = 24d*secondsInHour;

		seconds = seconds + secondsInDay*days;
		seconds = seconds + secondsInHour*dateTime.hours;
		seconds = seconds + secondsInMinute*dateTime.minutes;
		seconds = seconds + dateTime.seconds;

		return seconds;
	}


	public static bool datetimeisLeapYear(double year, datetimeSuccess success){
		bool itIsLeapYear;

		if(year >= 1752d){
			success.success = true;
			if(divisibleBy(year, 4d)){
				if(divisibleBy(year, 100d)){
					if(divisibleBy(year, 400d)){
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
			success.errorMessage = "Gregorian calendar was not in general use.".ToCharArray();
		}

		return itIsLeapYear;
	}


	public static datetimeDate datetimedayToDate(double dayNr, datetimeSuccess success){
		datetimeDate date;
		DoubleReference remainder;

		date = new datetimeDate();
		success.success = true;
		remainder = new DoubleReference();
		remainder.doubleValue = dayNr + 79623d;
		/* Days since 1752-01-01. Day 0: Thursday, 1970-01-01*/
		/* Find year.*/
		date.year = datetimegetYearFromDayNr(remainder.doubleValue, remainder);

		/* Find month.*/
		date.month = datetimegetMonthFromDayNr(remainder.doubleValue, date.year, remainder);

		/* Find day.*/
		date.day = 1d + remainder.doubleValue;

		return date;
	}


	public static double datetimegetMonthFromDayNr(double dayNr, double year, DoubleReference remainder){
		double [] daysInMonth;
		bool done;
		double month;

		daysInMonth = datetimegetDaysInMonth(year);
		done = false;
		month = 1d;

		for(; !done; ){
			if(dayNr > daysInMonth[(int)(month)]){
				dayNr = dayNr - daysInMonth[(int)(month)];
				month = month + 1d;
			}else{
				done = true;
			}
		}
		remainder.doubleValue = dayNr;

		return month;
	}


	public static double datetimegetYearFromDayNr(double dayNr, DoubleReference remainder){
		double nrOfDays;
		bool done;
		double year;

		done = false;
		year = 1752d;

		for(; !done; ){
			if(datetimeisLeapYear(year, new datetimeSuccess())){
				nrOfDays = 366d;
			}else{
				nrOfDays = 365d;
			}
			if(dayNr >= nrOfDays){
				dayNr = dayNr - nrOfDays;
				year = year + 1d;
			}else{
				done = true;
			}
		}
		remainder.doubleValue = dayNr;

		return year;
	}


	public static double [] datetimegetDaysInMonth(double year){
		double [] daysInMonth;

		daysInMonth = new double [(int)(1d + 12d)];

		daysInMonth[0] = 0d;
		daysInMonth[1] = 31d;
		if(datetimeisLeapYear(year, new datetimeSuccess())){
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


	public static double datetimedateToDayNumber(datetimeDate date, datetimeSuccess success){
		double days;

		success.success = true;
		days = -79623d ;
		/* Day 1752-01-01*/
		days = days + datetimedaysInYears(date.year);
		days = days + datetimedaysInMonths(date.month, date.year);
		days = days + date.day - 1d;

		return days;
	}


	public static double datetimedaysInMonths(double month, double year){
		double [] daysInMonth;
		double days;
		double i;

		daysInMonth = datetimegetDaysInMonth(year);

		days = 0d;
		for(i = 1d; i < month; i = i + 1d){
			days = days + daysInMonth[(int)(i)];
		}

		return days;
	}


	public static double datetimedaysInYears(double years){
		double days;
		double i;
		double nrOfDays;

		days = 0d;
		for(i = 1752d; i < years; i = i + 1d){
			if(datetimeisLeapYear(i, new datetimeSuccess())){
				nrOfDays = 366d;
			}else{
				nrOfDays = 365d;
			}
			days = days + nrOfDays;
		}
		return days;
	}


	public static bool datetimeisValidDate(datetimeDate date){
		bool valid;
		double [] daysInMonth;
		double daysInThisMonth;

		if(date.year >= 1752d){
			if(date.month >= 1d && date.month <= 12d){
				daysInMonth = datetimegetDaysInMonth(date.year);
				daysInThisMonth = daysInMonth[(int)(date.month)];
				if(date.day >= 1d && date.day <= daysInThisMonth){
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


	public static void assertFalse(bool b, DoubleReference failures){

		if(b){
			failures.doubleValue = failures.doubleValue + 1d;
		}
	}


	public static void assertTrue(bool b, DoubleReference failures){

		if(!b){
			failures.doubleValue = failures.doubleValue + 1d;
		}
	}


	public static void assertEquals(double a, double b, DoubleReference failures){

		if(a != b){
			failures.doubleValue = failures.doubleValue + 1d;
		}
	}


	public static void assertStringEquals(char [] a, char [] b, DoubleReference failures){

		if(!stringsEqual(a, b)){
			failures.doubleValue = failures.doubleValue + 1d;
		}
	}


	public static double [] stringToNumberArray(char [] stringx){
		double i;
		double [] array;

		array = new double [(int)(stringx.Length)];

		for(i = 0d; i < stringx.Length; i = i + 1d){
			array[(int)(i)] = stringx[(int)(i)];
		}
		return array;
	}


	public static char [] numberArrayToString(double [] array){
		double i;
		char [] stringx;

		stringx = new char [(int)(array.Length)];

		for(i = 0d; i < array.Length; i = i + 1d){
			stringx[(int)(i)] = (char)(array[(int)(i)]);
		}
		return stringx;
	}


	public static bool stringsEqual(char [] data1, char [] data2){
		bool equal;
		double nrEqual, i;

		equal = false;
		if(data1.Length == data2.Length){
			nrEqual = 0d;
			for(i = 0d; i < data1.Length; i = i + 1d){
				if(data1[(int)(i)] == data2[(int)(i)]){
					nrEqual = nrEqual + 1d;
				}
			}
			if(nrEqual == data1.Length){
				equal = true;
			}
		}else{
			equal = false;
		}

		return equal;
	}


	public static bool numberArraysEqual(double [] data1, double [] data2){
		bool equal;
		double nrEqual, i;

		equal = false;
		if(data1.Length == data2.Length){
			nrEqual = 0d;
			for(i = 0d; i < data1.Length; i = i + 1d){
				if(data1[(int)(i)] == data2[(int)(i)]){
					nrEqual = nrEqual + 1d;
				}
			}
			if(nrEqual == data1.Length){
				equal = true;
			}
		}else{
			equal = false;
		}

		return equal;
	}


	public static char [] substring(char [] stringx, double from, double to){
		char [] n;
		double i;

		n = new char [(int)(to - from)];

		for(i = from; i < to; i = i + 1d){
			n[(int)(i - from)] = stringx[(int)(i)];
		}

		return n;
	}


	public static char [] appendString(char [] stringx, char [] s){
		char [] newString;
		double i;

		newString = new char [(int)(stringx.Length + s.Length)];

		for(i = 0d; i < stringx.Length; i = i + 1d){
			newString[(int)(i)] = stringx[(int)(i)];
		}

		for(i = 0d; i < s.Length; i = i + 1d){
			newString[(int)(stringx.Length + i)] = s[(int)(i)];
		}

		delete(stringx);

		return newString;
	}


	public static char [] appendCharacter(char [] stringx, char c){
		char [] newString;
		double i;

		newString = new char [(int)(stringx.Length + 1d)];

		for(i = 0d; i < stringx.Length; i = i + 1d){
			newString[(int)(i)] = stringx[(int)(i)];
		}

		newString[(int)(stringx.Length)] = c;

		delete(stringx);

		return newString;
	}


	public static StringReference [] split(char [] toSplit, char splitBy){
		StringReference [] splitt;
		char [] next;
		double i;
		char c;
		StringReference n;

		splitt = new StringReference [0];

		next = new char [0];
		for(i = 0d; i < toSplit.Length; i = i + 1d){
			c = toSplit[(int)(i)];
			if(c == splitBy){
				n = new StringReference();
				n.stringx = next;
				splitt = addString(splitt, n);
				next = new char [0];
			}else{
				next = appendCharacter(next, c);
			}
		}

		if(next.Length > 0d){
			n = new StringReference();
			n.stringx = next;
			splitt = addString(splitt, n);
		}

		return splitt;
	}


	public static double [] addDecimal(double [] list, double a){
		double [] newlist;
		double i;

		newlist = new double [(int)(list.Length + 1d)];
		for(i = 0d; i < list.Length; i = i + 1d){
			newlist[(int)(i)] = list[(int)(i)];
		}
		newlist[(int)(list.Length)] = a;
		
		delete(list);
		
		return newlist;
	}


	public static void addDecimalRef(DecimalListRef list, double i){

		list.list = addDecimal(list.list, i);
	}


	public static double [] removeDecimal(double [] list, double n){
		double [] newlist;
		double i;

		newlist = new double [(int)(list.Length - 1d)];

		for(i = 0d; i < list.Length; i = i + 1d){
			if(i < n){
				newlist[(int)(i)] = list[(int)(i)];
			}
			if(i > n){
				newlist[(int)(i - 1d)] = list[(int)(i)];
			}
		}
		
		delete(list);
		
		return newlist;
	}


	public static double getDecimalRef(DecimalListRef list, double i){

		return list.list[(int)(i)];
	}


	public static void removeDecimalRef(DecimalListRef list, double i){

		list.list = removeDecimal(list.list, i);
	}


	public static StringReference [] addString(StringReference [] list, StringReference a){
		StringReference [] newlist;
		double i;

		newlist = new StringReference [(int)(list.Length + 1d)];

		for(i = 0d; i < list.Length; i = i + 1d){
			newlist[(int)(i)] = list[(int)(i)];
		}
		newlist[(int)(list.Length)] = a;
		
		delete(list);
		
		return newlist;
	}


	public static void addStringRef(StringListRef list, StringReference i){

		list.list = addString(list.list, i);
	}


	public static StringReference [] removeString(StringReference [] list, double n){
		StringReference [] newlist;
		double i;

		newlist = new StringReference [(int)(list.Length - 1d)];

		for(i = 0d; i < list.Length; i = i + 1d){
			if(i < n){
				newlist[(int)(i)] = list[(int)(i)];
			}
			if(i > n){
				newlist[(int)(i - 1d)] = list[(int)(i)];
			}
		}
		
		delete(list);
		
		return newlist;
	}


	public static StringReference getStringRef(StringListRef list, double i){

		return list.list[(int)(i)];
	}


	public static void removeStringRef(StringListRef list, double i){

		list.list = removeString(list.list, i);
	}


	public static double Negate(double x){

		return -x ;
	}


	public static double Positive(double x){

		return +x ;
	}


	public static double Roundx(double x){

		return (double)Round(x);
	}


	public static double Ceil(double x){

		return Ceiling(x);
	}


	public static double Floorx(double x){

		return Floor(x);
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


	public static double Squareroot(double x){

		return Sqrt(x);
	}


	public static double Expx(double x){

		return Exp(x);
	}


	public static bool divisibleBy(double a, double b){

		return ((a%b) == 0d);
	}


	public static void delete(System.Object objectx){
		// C# has garbage collection.
	}
}


public class foedselsnummerTestBundle{

	public static void Main(){
		System.Console.WriteLine(foedselsnummer.test());
	}
}
' Downloaded from https://repo.progsbase.com - Code Developed Using progsbase.

Imports System.Math

Public Class BooleanArrayReference
	Public booleanArray As Boolean ()
End Class

Public Class BooleanReference
	Public booleanValue As Boolean
End Class

Public Class CharacterReference
	Public characterValue As Char
End Class

Public Class NumberArrayReference
	Public numberArray As Double ()
End Class

Public Class NumberReference
	Public numberValue As Double
End Class

Public Class StringArrayReference
	Public stringArray As StringReference ()
End Class

Public Class StringReference
	Public stringx As Char ()
End Class

Public Class Datex
	Public year As Double
	Public month As Double
	Public day As Double
End Class

Public Class DateReference
	Public datex As Datex
End Class

Public Class Interval
	Public first As Datex
	Public last As Datex
End Class

Public Class DateTimeTimezone
	Public dateTimex As DateTimex
	Public timezoneOffsetSeconds As Double
End Class

Public Class DateTimeTimezoneReference
	Public dateTimeTimezone As DateTimeTimezone
End Class

Public Class DateTimex
	Public datex As Datex
	Public hours As Double
	Public minutes As Double
	Public seconds As Double
End Class

Public Class DateTimeReference
	Public dateTimex As DateTimex
End Class

Module foedselsnummer
	Public Function IsValidNorwegianPersonalIdentificationNumber(ByRef fnummer As Char (), ByRef message As StringReference) As Boolean
		Dim gyldig As Boolean
		Dim i, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11 As Double
		Dim k1, k2 As Double
		Dim dateRef As DateReference

		If fnummer.Length = 11
			gyldig = true
			i = 0
			While i < fnummer.Length
				If charIsNumber(fnummer(i))
				Else
					gyldig = false
				End If
				i = i + 1
			End While

			If gyldig
				d1 = charCharacterToDecimalDigit(fnummer(0))
				d2 = charCharacterToDecimalDigit(fnummer(1))
				d3 = charCharacterToDecimalDigit(fnummer(2))
				d4 = charCharacterToDecimalDigit(fnummer(3))
				d5 = charCharacterToDecimalDigit(fnummer(4))
				d6 = charCharacterToDecimalDigit(fnummer(5))
				d7 = charCharacterToDecimalDigit(fnummer(6))
				d8 = charCharacterToDecimalDigit(fnummer(7))
				d9 = charCharacterToDecimalDigit(fnummer(8))
				d10 = charCharacterToDecimalDigit(fnummer(9))
				d11 = charCharacterToDecimalDigit(fnummer(10))

				dateRef = New DateReference()
				gyldig = GetDateFromNorwegianPersonalIdentificationNumber(fnummer, dateRef, message)

				If gyldig
					If IsValidDate(dateRef.datex, message)
						k1 = d1*3 + d2*7 + d3*6 + d4*1 + d5*8 + d6*9 + d7*4 + d8*5 + d9*2
						k1 = k1 Mod 11
						If k1 <> 0
							k1 = 11 - k1
						End If
						If k1 = 10
							gyldig = false
							message.stringx = "Control digit 1 is 10, which is invalid.".ToCharArray()
						End If

						If gyldig
							k2 = d1*5 + d2*4 + d3*3 + d4*2 + d5*7 + d6*6 + d7*5 + d8*4 + d9*3 + k1*2
							k2 = k2 Mod 11
							If k2 <> 0
								k2 = 11 - k2
							End If
							If k2 = 10
								gyldig = false
								message.stringx = "Control digit 2 is 10, which is invalid.".ToCharArray()
							End If

							If gyldig
								If k1 = d10
									If k2 = d11
										gyldig = true
									Else
										gyldig = false
										message.stringx = "Check of control digit 2 failed.".ToCharArray()
									End If
								Else
									gyldig = false
									message.stringx = "Check of control digit 1 failed.".ToCharArray()
								End If
							End If
						End If
					Else
						gyldig = false
						message.stringx = "The date is not a valid date.".ToCharArray()
					End If
				End If
			Else
				gyldig = false
				message.stringx = "Each character must be a decimal digit.".ToCharArray()
			End If
		Else
			gyldig = false
			message.stringx = "Must be exactly 11 digits long.".ToCharArray()
		End If

		Return gyldig
	End Function


	Public Function GetDateFromNorwegianPersonalIdentificationNumber(ByRef fnummer As Char (), ByRef dateRef As DateReference, ByRef message As StringReference) As Boolean
		Dim individnummer As Double
		Dim day, month, year As Double
		Dim i, d1, d2, d3, d4, d5, d6, d7, d8, d9 As Double
		Dim success As Boolean

		success = true
		dateRef.datex = New Datex()

		If fnummer.Length = 11
			i = 0
			While i < fnummer.Length
				If charIsNumber(fnummer(i))
				Else
					success = false
				End If
				i = i + 1
			End While

			If success
				d1 = charCharacterToDecimalDigit(fnummer(0))
				d2 = charCharacterToDecimalDigit(fnummer(1))
				d3 = charCharacterToDecimalDigit(fnummer(2))
				d4 = charCharacterToDecimalDigit(fnummer(3))
				d5 = charCharacterToDecimalDigit(fnummer(4))
				d6 = charCharacterToDecimalDigit(fnummer(5))
				d7 = charCharacterToDecimalDigit(fnummer(6))
				d8 = charCharacterToDecimalDigit(fnummer(7))
				d9 = charCharacterToDecimalDigit(fnummer(8))

				' Individnummer
				individnummer = d7*100 + d8*10 + d9

				' Make date
				day = d1*10 + d2
				month = d3*10 + d4
				year = d5*10 + d6

				If individnummer >= 0 And individnummer <= 499
					year = year + 1900
				ElseIf individnummer >= 500 And individnummer <= 749 And year >= 54 And year <= 99
					year = year + 1800
				ElseIf individnummer >= 900 And individnummer <= 999 And year >= 40 And year <= 99
					year = year + 1900
				ElseIf individnummer >= 500 And individnummer <= 999 And year >= 0 And year <= 39
					year = year + 2000
				Else
					success = false
					message.stringx = "Invalid combination of individnummer and year.".ToCharArray()
				End If

				If success
					dateRef.datex.year = year
					dateRef.datex.month = month
					dateRef.datex.day = day
				End If
			Else
				message.stringx = "Each character must be a decimal digit.".ToCharArray()
			End If
		Else
			message.stringx = "Must be exactly 11 digits long.".ToCharArray()
		End If

		Return success
	End Function


	Public Sub Test1(ByRef failures As NumberReference)
		Dim message As StringReference
		Dim dateRef As DateReference
		Dim success As Boolean

		message = New StringReference()

		success = IsValidNorwegianPersonalIdentificationNumber("10061270707".ToCharArray(), message)
		Call AssertTrue(success, failures)

		dateRef = New DateReference()

		success = GetDateFromNorwegianPersonalIdentificationNumber("11028559912".ToCharArray(), dateRef, message)
		Call AssertTrue(success, failures)
		Call AssertEquals(dateRef.datex.year, 1885, failures)

		success = GetDateFromNorwegianPersonalIdentificationNumber("01019949768".ToCharArray(), dateRef, message)
		Call AssertTrue(success, failures)
		Call AssertEquals(dateRef.datex.year, 1999, failures)

		success = GetDateFromNorwegianPersonalIdentificationNumber("01010099931".ToCharArray(), dateRef, message)
		Call AssertTrue(success, failures)
		Call AssertEquals(dateRef.datex.year, 2000, failures)
	End Sub


	Public Function test() As Double
		Dim failures As NumberReference

		failures = CreateNumberReference(0)

		Call Test1(failures)

		Return failures.numberValue
	End Function


	Public Function CreateBooleanReference(value As Boolean) As BooleanReference
		Dim ref As BooleanReference

		ref = New BooleanReference()
		ref.booleanValue = value

		Return ref
	End Function


	Public Function CreateBooleanArrayReference(ByRef value As Boolean ()) As BooleanArrayReference
		Dim ref As BooleanArrayReference

		ref = New BooleanArrayReference()
		ref.booleanArray = value

		Return ref
	End Function


	Public Function CreateBooleanArrayReferenceLengthValue(length As Double, value As Boolean) As BooleanArrayReference
		Dim ref As BooleanArrayReference
		Dim i As Double

		ref = New BooleanArrayReference()
		ref.booleanArray = New Boolean (length - 1){}

		i = 0
		While i < length
			ref.booleanArray(i) = value
			i = i + 1
		End While

		Return ref
	End Function


	Public Sub FreeBooleanArrayReference(ByRef booleanArrayReference As BooleanArrayReference)
		Erase booleanArrayReference.booleanArray 
		booleanArrayReference = Nothing
	End Sub


	Public Function CreateCharacterReference(value As Char) As CharacterReference
		Dim ref As CharacterReference

		ref = New CharacterReference()
		ref.characterValue = value

		Return ref
	End Function


	Public Function CreateNumberReference(value As Double) As NumberReference
		Dim ref As NumberReference

		ref = New NumberReference()
		ref.numberValue = value

		Return ref
	End Function


	Public Function CreateNumberArrayReference(ByRef value As Double ()) As NumberArrayReference
		Dim ref As NumberArrayReference

		ref = New NumberArrayReference()
		ref.numberArray = value

		Return ref
	End Function


	Public Function CreateNumberArrayReferenceLengthValue(length As Double, value As Double) As NumberArrayReference
		Dim ref As NumberArrayReference
		Dim i As Double

		ref = New NumberArrayReference()
		ref.numberArray = New Double (length - 1){}

		i = 0
		While i < length
			ref.numberArray(i) = value
			i = i + 1
		End While

		Return ref
	End Function


	Public Sub FreeNumberArrayReference(ByRef numberArrayReference As NumberArrayReference)
		Erase numberArrayReference.numberArray 
		numberArrayReference = Nothing
	End Sub


	Public Function CreateStringReference(ByRef value As Char ()) As StringReference
		Dim ref As StringReference

		ref = New StringReference()
		ref.stringx = value

		Return ref
	End Function


	Public Function CreateStringReferenceLengthValue(length As Double, value As Char) As StringReference
		Dim ref As StringReference
		Dim i As Double

		ref = New StringReference()
		ref.stringx = New Char (length - 1){}

		i = 0
		While i < length
			ref.stringx(i) = value
			i = i + 1
		End While

		Return ref
	End Function


	Public Sub FreeStringReference(ByRef stringReference As StringReference)
		Erase stringReference.stringx 
		stringReference = Nothing
	End Sub


	Public Function CreateStringArrayReference(ByRef strings As StringReference ()) As StringArrayReference
		Dim ref As StringArrayReference

		ref = New StringArrayReference()
		ref.stringArray = strings

		Return ref
	End Function


	Public Function CreateStringArrayReferenceLengthValue(length As Double, ByRef value As Char ()) As StringArrayReference
		Dim ref As StringArrayReference
		Dim i As Double

		ref = New StringArrayReference()
		ref.stringArray = New StringReference (length - 1){}

		i = 0
		While i < length
			ref.stringArray(i) = CreateStringReference(value)
			i = i + 1
		End While

		Return ref
	End Function


	Public Sub FreeStringArrayReference(ByRef stringArrayReference As StringArrayReference)
		Dim i As Double

		i = 0
		While i < stringArrayReference.stringArray.Length
			stringArrayReference.stringArray(i) = Nothing
			i = i + 1
		End While
		Erase stringArrayReference.stringArray 
		stringArrayReference = Nothing
	End Sub


	Public Function CreateDate(year As Double, month As Double, day As Double) As Datex
		Dim datex As Datex

		datex = New Datex()

		datex.year = year
		datex.month = month
		datex.day = day

		Return datex
	End Function


	Public Function IsLeapYearWithCheck(year As Double, ByRef isLeapYearReference As BooleanReference, ByRef message As StringReference) As Boolean
		Dim itIsLeapYear As Boolean
		Dim success As Boolean

		If year >= 1752
			success = true
			itIsLeapYear = IsLeapYear(year)
		Else
			success = false
			itIsLeapYear = false
			message.stringx = "Gregorian calendar was not in general use.".ToCharArray()
		End If

		isLeapYearReference.booleanValue = itIsLeapYear
		Return success
	End Function


	Public Function IsLeapYear(year As Double) As Boolean
		Dim itIsLeapYear As Boolean

		If DivisibleBy(year, 4)
			If DivisibleBy(year, 100)
				If DivisibleBy(year, 400)
					itIsLeapYear = true
				Else
					itIsLeapYear = false
				End If
			Else
				itIsLeapYear = true
			End If
		Else
			itIsLeapYear = false
		End If

		Return itIsLeapYear
	End Function


	Public Function DayToDateWithCheck(dayNr As Double, ByRef dateReference As DateReference, ByRef message As StringReference) As Boolean
		Dim datex As Datex
		Dim remainder As NumberReference
		Dim success As Boolean

		If dayNr >= -79623
			datex = New Datex()
			remainder = New NumberReference()
			remainder.numberValue = dayNr + 79623
			' Days since 1752-01-01. Day 0: Thursday, 1970-01-01
			' Find year.
			datex.year = GetYearFromDayNr(remainder.numberValue, remainder)

			' Find month.
			datex.month = GetMonthFromDayNr(remainder.numberValue, datex.year, remainder)

			' Find day.
			datex.day = 1 + remainder.numberValue

			dateReference.datex = datex
			success = true
		Else
			success = false
			message.stringx = "Gregorian calendar was not in general use before 1752.".ToCharArray()
		End If

		Return success
	End Function


	Public Function DayToDate(dayNr As Double) As Datex
		Dim datex As Datex
		Dim success As Boolean
		Dim dateRef As DateReference
		Dim message As StringReference

		dateRef = New DateReference()
		message = New StringReference()

		success = DayToDateWithCheck(dayNr, dateRef, message)
		If success
			datex = dateRef.datex
			dateRef = Nothing
			Call FreeStringReference(message)
		Else
			datex = CreateDate(1970, 1, 1)
		End If

		Return datex
	End Function


	Public Function GetMonthFromDayNrWithCheck(dayNr As Double, year As Double, ByRef monthReference As NumberReference, ByRef remainderReference As NumberReference, ByRef message As StringReference) As Boolean
		Dim month As Double
		Dim success As Boolean

		If dayNr >= -79623
			month = GetMonthFromDayNr(dayNr, year, remainderReference)
			monthReference.numberValue = month
			success = true
		Else
			success = false
			message.stringx = "Gregorian calendar not in general use before 1752.".ToCharArray()
		End If

		Return success
	End Function


	Public Function GetMonthFromDayNr(dayNr As Double, year As Double, ByRef remainderReference As NumberReference) As Double
		Dim daysInMonth As Double ()
		Dim done As Boolean
		Dim month As Double

		daysInMonth = GetDaysInMonth(year)
		done = false
		month = 1

		
		While Not done
			If dayNr >= daysInMonth(month)
				dayNr = dayNr - daysInMonth(month)
				month = month + 1
			Else
				done = true
			End If
		End While
		remainderReference.numberValue = dayNr

		Return month
	End Function


	Public Function GetYearFromDayNrWithCheck(dayNr As Double, ByRef yearReference As NumberReference, ByRef remainder As NumberReference, ByRef message As StringReference) As Boolean
		Dim success As Boolean
		Dim year As Double

		If dayNr >= 0
			success = true
			year = GetYearFromDayNr(dayNr, remainder)
			yearReference.numberValue = year
		Else
			success = false
			message.stringx = "Day number must be 0 or higher. 0 is 1752-01-01.".ToCharArray()
		End If

		Return success
	End Function


	Public Function GetYearFromDayNr(dayNr As Double, ByRef remainder As NumberReference) As Double
		Dim nrOfDays As Double
		Dim done As Boolean
		Dim year As Double

		done = false
		year = 1752

		
		While Not done
			If IsLeapYear(year)
				nrOfDays = 366
			Else
				nrOfDays = 365
			End If

			If dayNr >= nrOfDays
				' First day is 0.
				dayNr = dayNr - nrOfDays
				year = year + 1
			Else
				done = true
			End If
		End While
		remainder.numberValue = dayNr

		Return year
	End Function


	Public Function DaysBetweenDates(ByRef A As Datex, ByRef B As Datex) As Double
		Dim daysA, daysB, daysBetween As Double

		daysA = DateToDays(A)
		daysB = DateToDays(B)

		daysBetween = daysB - daysA

		Return daysBetween
	End Function


	Public Function GetDaysInMonthWithCheck(year As Double, ByRef daysInMonthReference As NumberArrayReference, ByRef message As StringReference) As Boolean
		Dim daysInMonth As Double ()
		Dim success As Boolean
		Dim datex As Datex

		datex = CreateDate(year, 1, 1)

		success = IsValidDate(datex, message)
		If success
			daysInMonth = GetDaysInMonth(year)

			daysInMonthReference.numberArray = daysInMonth
		End If

		Return success
	End Function


	Public Function GetDaysInMonth(year As Double) As Double ()
		Dim daysInMonth As Double ()

		daysInMonth = New Double (1 + 12 - 1){}

		daysInMonth(0) = 0
		daysInMonth(1) = 31

		If IsLeapYear(year)
			daysInMonth(2) = 29
		Else
			daysInMonth(2) = 28
		End If
		daysInMonth(3) = 31
		daysInMonth(4) = 30
		daysInMonth(5) = 31
		daysInMonth(6) = 30
		daysInMonth(7) = 31
		daysInMonth(8) = 31
		daysInMonth(9) = 30
		daysInMonth(10) = 31
		daysInMonth(11) = 30
		daysInMonth(12) = 31

		Return daysInMonth
	End Function


	Public Function DateToDaysWithCheck(ByRef datex As Datex, ByRef dayNumberReferenceReference As NumberReference, ByRef message As StringReference) As Boolean
		Dim days As Double
		Dim success As Boolean

		success = IsValidDate(datex, message)
		If success
			days = DateToDays(datex)
			dayNumberReferenceReference.numberValue = days
		End If

		Return success
	End Function


	Public Function DateToDays(ByRef datex As Datex) As Double
		Dim days As Double

		' Day 1752-01-01
		days = -79623

		days = days + DaysInYears(datex.year)
		days = days + DaysInMonths(datex.month, datex.year)
		days = days + datex.day - 1

		Return days
	End Function


	Public Function DateToWeekdayNumberWithCheck(ByRef datex As Datex, ByRef weekDayNumberReference As NumberReference, ByRef message As StringReference) As Boolean
		Dim weekDay As Double
		Dim success As Boolean

		success = IsValidDate(datex, message)
		If success
			weekDay = DateToWeekdayNumber(datex)
			weekDayNumberReference.numberValue = weekDay
		End If

		Return success
	End Function


	Public Function DateToWeekdayNumber(ByRef datex As Datex) As Double
		Dim days, weekDay As Double

		days = DateToDays(datex)

		days = days + 79623
		days = days + 5

		weekDay = days Mod 7 + 1

		Return weekDay
	End Function


	Public Function DateToWeeknumber(ByRef datex As Datex, ByRef yearRef As NumberReference) As Double
		Dim weekNumber, weekday, days, daysWeek1Start, weekdayNewYears As Double
		Dim week1Start, newyears As Datex

		week1Start = CopyDate(datex)

		week1Start.day = 1
		week1Start.month = 1
		weekday = DateToWeekdayNumber(week1Start)

		' Set week1Start to the start of the Week 1.
		' If monday, week 1 begins on Jan. 1st
		If weekday = 1
			week1Start.day = 1
		End If
		' If tuesday, week 1 begins on Dec. 31st
		If weekday = 2
			week1Start.year = week1Start.year - 1
			week1Start.month = 12
			week1Start.day = 31
		End If
		' If wednesday, week 1 begins on Dec. 30th
		If weekday = 3
			week1Start.year = week1Start.year - 1
			week1Start.month = 12
			week1Start.day = 30
		End If
		' If thursday, week 1 begins on Dec. 29th
		If weekday = 4
			week1Start.year = week1Start.year - 1
			week1Start.month = 12
			week1Start.day = 29
		End If
		' If friday, week 1 begins on Jan. 4th
		If weekday = 5
			week1Start.day = 4
		End If
		' If saturday, week 1 begins on Jan. 3rd
		If weekday = 6
			week1Start.day = 3
		End If
		' If sunday, week 1 begins on Jan. 2nd
		If weekday = 7
			week1Start.day = 2
		End If

		days = DateToDays(datex)
		daysWeek1Start = DateToDays(week1Start)

		If days >= daysWeek1Start
			weekNumber = 1 + Floor((days - daysWeek1Start)/7)

			If weekNumber >= 1 And weekNumber <= 52
				' Week is between 1 and 52 in the current year.
				yearRef.numberValue = datex.year
			Else
				' Is week nr 53 or 1 next year?
				newyears = CopyDate(datex)
				newyears.month = 12
				newyears.day = 31
				weekdayNewYears = DateToWeekdayNumber(newyears)
				If weekdayNewYears = 1 Or weekdayNewYears = 2 Or weekdayNewYears = 3
					' Week 1 next year.
					weekNumber = 1
					yearRef.numberValue = datex.year + 1
				Else
					' Week 53
					yearRef.numberValue = datex.year
				End If
				newyears = Nothing
			End If
		Else
			' Week is in previous year. Either 52nd or 53rd.
			newyears = CopyDate(datex)
			newyears.month = 12
			newyears.day = 31
			newyears.year = datex.year - 1
			weekNumber = DateToWeeknumber(newyears, yearRef)
			newyears = Nothing
		End If

		week1Start = Nothing

		Return weekNumber
	End Function


	Public Function DaysInMonthsWithCheck(month As Double, year As Double, ByRef daysInMonthsReference As NumberReference, ByRef message As StringReference) As Boolean
		Dim days As Double
		Dim success As Boolean
		Dim datex As Datex

		datex = CreateDate(year, month, 1)

		success = IsValidDate(datex, message)
		If success
			days = DaysInMonths(month, year)

			daysInMonthsReference.numberValue = days
		End If

		Return success
	End Function


	Public Function DaysInMonths(month As Double, year As Double) As Double
		Dim daysInMonth As Double ()
		Dim days As Double
		Dim i As Double

		daysInMonth = GetDaysInMonth(year)

		days = 0
		i = 1
		While i < month
			days = days + daysInMonth(i)
			i = i + 1
		End While

		Return days
	End Function


	Public Function DaysInYearsWithCheck(years As Double, ByRef daysReference As NumberReference, ByRef message As StringReference) As Boolean
		Dim days As Double
		Dim success As Boolean
		Dim datex As Datex

		datex = CreateDate(years, 1, 1)

		success = IsValidDate(datex, message)
		If success
			days = DaysInYears(years)
			daysReference.numberValue = days
		End If

		Return success
	End Function


	Public Function DaysInYears(years As Double) As Double
		Dim days As Double
		Dim i As Double
		Dim nrOfDays As Double

		days = 0
		i = 1752
		While i < years
			If IsLeapYear(i)
				nrOfDays = 366
			Else
				nrOfDays = 365
			End If
			days = days + nrOfDays
			i = i + 1
		End While

		Return days
	End Function


	Public Function IsValidDate(ByRef datex As Datex, ByRef message As StringReference) As Boolean
		Dim valid As Boolean
		Dim daysInMonth As Double ()
		Dim daysInThisMonth As Double

		If datex.year >= 1752
			If datex.month >= 1 And datex.month <= 12
				daysInMonth = GetDaysInMonth(datex.year)
				daysInThisMonth = daysInMonth(datex.month)
				If datex.day >= 1 And datex.day <= daysInThisMonth
					valid = true
				Else
					valid = false
					message.stringx = "The month does not have the given day number.".ToCharArray()
				End If
			Else
				valid = false
				message.stringx = "Month must be between 1 and 12, inclusive.".ToCharArray()
			End If
		Else
			valid = false
			message.stringx = "Gregorian calendar was not in general use before 1752.".ToCharArray()
		End If

		Return valid
	End Function


	Public Function AddDaysToDate(ByRef datex As Datex, days As Double, ByRef message As StringReference) As Boolean
		Dim n As Double
		Dim success As Boolean
		Dim dateReference As DateReference
		Dim daysRef As NumberReference

		daysRef = New NumberReference()
		success = DateToDaysWithCheck(datex, daysRef, message)

		If success
			n = daysRef.numberValue
			n = n + days

			dateReference = New DateReference()
			success = DayToDateWithCheck(n, dateReference, message)
			If success
				Call AssignDate(datex, dateReference.datex)
			End If
		End If

		Return success
	End Function


	Public Sub AssignDate(ByRef a As Datex, ByRef b As Datex)
		a.year = b.year
		a.month = b.month
		a.day = b.day
	End Sub


	Public Sub AddMonthsToDate(ByRef datex As Datex, months As Double)
		Dim i As Double

		If months > 0
			i = 0
			While i < months
				datex.month = datex.month + 1

				If datex.month = 13
					datex.month = 1
					datex.year = datex.year + 1
				End If
				i = i + 1
			End While
		End If
		If months < 0
			i = 0
			While i < -months
				datex.month = datex.month - 1

				If datex.month = 0
					datex.month = 12
					datex.year = datex.year - 1
				End If
				i = i + 1
			End While
		End If
	End Sub


	Public Function DateToStringISO8601WithCheck(ByRef datex As Datex, ByRef datestr As StringReference, ByRef message As StringReference) As Boolean
		Dim success As Boolean

		success = IsValidDate(datex, message)

		If success
			If datex.year <= 9999
				datestr.stringx = DateToStringISO8601(datex)
			Else
				message.stringx = "This library works from 1752 to 9999.".ToCharArray()
			End If
		End If

		Return success
	End Function


	Public Function DateToStringISO8601(ByRef datex As Datex) As Char ()
		Dim str As Char ()

		str = New Char (10 - 1){}

		str(0) = charDecimalDigitToCharacter(Floor(datex.year/1000))
		str(1) = charDecimalDigitToCharacter(Floor((datex.year Mod 1000)/100))
		str(2) = charDecimalDigitToCharacter(Floor((datex.year Mod 100)/10))
		str(3) = charDecimalDigitToCharacter(Floor(datex.year Mod 10))

		str(4) = "-"C

		str(5) = charDecimalDigitToCharacter(Floor((datex.month Mod 100)/10))
		str(6) = charDecimalDigitToCharacter(Floor(datex.month Mod 10))

		str(7) = "-"C

		str(8) = charDecimalDigitToCharacter(Floor((datex.day Mod 100)/10))
		str(9) = charDecimalDigitToCharacter(Floor(datex.day Mod 10))

		Return str
	End Function


	Public Function DateFromStringISO8601(ByRef str As Char ()) As Datex
		Dim datex As Datex
		Dim n As Double

		datex = New Datex()

		n = charCharacterToDecimalDigit(str(0))*1000
		n = n + charCharacterToDecimalDigit(str(1))*100
		n = n + charCharacterToDecimalDigit(str(2))*10
		n = n + charCharacterToDecimalDigit(str(3))*1

		datex.year = n

		n = charCharacterToDecimalDigit(str(5))*10
		n = n + charCharacterToDecimalDigit(str(6))*1

		datex.month = n

		n = charCharacterToDecimalDigit(str(8))*10
		n = n + charCharacterToDecimalDigit(str(9))*1

		datex.day = n

		Return datex
	End Function


	Public Function DateFromStringISO8601WithCheck(ByRef str As Char (), ByRef dateRef As DateReference, ByRef message As StringReference) As Boolean
		Dim valid As Boolean

		valid = IsValidDateISO8601(str, message)

		If valid
			dateRef.datex = DateFromStringISO8601(str)
		End If

		Return valid
	End Function


	Public Function IsValidDateISO8601(ByRef str As Char (), ByRef message As StringReference) As Boolean
		Dim valid As Boolean

		If str.Length = 4 + 1 + 2 + 1 + 2

			If charIsNumber(str(0)) And charIsNumber(str(1)) And charIsNumber(str(2)) And charIsNumber(str(3)) And charIsNumber(str(5)) And charIsNumber(str(6)) And charIsNumber(str(8)) And charIsNumber(str(9))
				If str(4) = "-"C And str(7) = "-"C
					valid = true
				Else
					valid = false
					message.stringx = "ISO8601 date must use \'-\' in positions 5 and 8.".ToCharArray()
				End If
			Else
				valid = false
				message.stringx = "ISO8601 date must use decimal digits in positions 1, 2, 3, 4, 6, 7, 9 and 10.".ToCharArray()
			End If
		Else
			valid = false
			message.stringx = "ISO8601 date must be exactly 10 characters long.".ToCharArray()
		End If

		Return valid
	End Function


	Public Function DateEquals(ByRef a As Datex, ByRef b As Datex) As Boolean
		Return a.year = b.year And a.month = b.month And a.day = b.day
	End Function


	Public Function CopyDate(ByRef a As Datex) As Datex
		Dim b As Datex

		b = CreateDate(a.year, a.month, a.day)

		Return b
	End Function


	Public Function GetSecondsFromDate(ByRef datex As Datex) As Double
		Dim seconds, days, secondsInMinute, secondsInHour, secondsInDay As Double
		Dim dayNumberReferenceReference As NumberReference
		Dim message As StringReference
		Dim success As Boolean

		seconds = 0
		dayNumberReferenceReference = New NumberReference()
		message = New StringReference()

		success = DateToDaysWithCheck(datex, dayNumberReferenceReference, message)
		If success
			days = dayNumberReferenceReference.numberValue

			secondsInMinute = 60
			secondsInHour = 60*secondsInMinute
			secondsInDay = 24*secondsInHour

			seconds = seconds + secondsInDay*days
		End If

		dayNumberReferenceReference = Nothing
		message = Nothing

		Return seconds
	End Function


	Public Function DateIsInInterval(ByRef interval As Interval, ByRef datex As Datex) As Boolean
		Dim from, tox, day As Double

		from = DateToDays(interval.first)
		tox = DateToDays(interval.last)
		day = DateToDays(datex)

		Return day >= from And day <= tox
	End Function


	Public Function DateLessThan(ByRef a As Datex, ByRef b As Datex) As Boolean
		Dim aDays, bDays As Double

		aDays = DateToDays(a)
		bDays = DateToDays(b)

		Return aDays < bDays
	End Function


	Public Function CreateDateTimeTimezone(year As Double, month As Double, day As Double, hours As Double, minutes As Double, seconds As Double, timezoneOffsetSeconds As Double) As DateTimeTimezone
		Dim dateTimeTimezone As DateTimeTimezone

		dateTimeTimezone = New DateTimeTimezone()

		dateTimeTimezone.dateTimex = CreateDateTime(year, month, day, hours, minutes, seconds)
		dateTimeTimezone.timezoneOffsetSeconds = timezoneOffsetSeconds

		Return dateTimeTimezone
	End Function


	Public Function CreateDateTimeTimezoneInHoursAndMinutes(year As Double, month As Double, day As Double, hours As Double, minutes As Double, seconds As Double, timezoneOffsetHours As Double, timezoneOffsetMinutes As Double) As DateTimeTimezone
		Dim dateTimeTimezone As DateTimeTimezone

		dateTimeTimezone = New DateTimeTimezone()

		dateTimeTimezone.dateTimex = CreateDateTime(year, month, day, hours, minutes, seconds)
		dateTimeTimezone.timezoneOffsetSeconds = GetSecondsFromHours(timezoneOffsetHours) + GetSecondsFromMinutes(timezoneOffsetMinutes)

		Return dateTimeTimezone
	End Function


	Public Function GetDateFromDateTimeTimeZone(ByRef dateTimeTimezone As DateTimeTimezone, ByRef dateTimeReference As DateTimeReference, ByRef message As StringReference) As Boolean
		Dim dateTimex As DateTimex

		dateTimex = dateTimeTimezone.dateTimex

		Return AddSecondsToDateTimeWithCheck(dateTimex, -dateTimeTimezone.timezoneOffsetSeconds, dateTimeReference, message)
	End Function


	Public Function CreateDateTimeTimezoneFromDateTimeAndTimeZoneInSeconds(ByRef dateTimex As DateTimex, timezoneOffsetSeconds As Double, ByRef dateTimeTimezoneReference As DateTimeTimezoneReference, ByRef message As StringReference) As Boolean
		Dim success As Boolean
		Dim adjustedDateTimeReference As DateTimeReference
		Dim dateTimeTimezone As DateTimeTimezone

		adjustedDateTimeReference = New DateTimeReference()
		dateTimeTimezone = New DateTimeTimezone()

		success = AddSecondsToDateTime(dateTimex, timezoneOffsetSeconds, adjustedDateTimeReference, message)

		If success
			dateTimeTimezone.dateTimex = adjustedDateTimeReference.dateTimex
			dateTimeTimezone.timezoneOffsetSeconds = timezoneOffsetSeconds

			dateTimeTimezoneReference.dateTimeTimezone = dateTimeTimezone
		End If

		Return success
	End Function


	Public Function CreateDateTimeTimezoneFromDateTimeAndTimeZoneInHoursAndMinutes(ByRef dateTimex As DateTimex, timezoneOffsetHours As Double, timezoneOffsetMinutes As Double, ByRef dateTimeTimezoneReference As DateTimeTimezoneReference, ByRef message As StringReference) As Boolean
		Return CreateDateTimeTimezoneFromDateTimeAndTimeZoneInSeconds(dateTimex, GetSecondsFromHours(timezoneOffsetHours) + GetSecondsFromMinutes(timezoneOffsetMinutes), dateTimeTimezoneReference, message)
	End Function


	Public Function GetDateTimeTimezoneFromSeconds(ByRef dateTimeTzRef As DateTimeTimezoneReference, seconds As Double, offset As Double, ByRef message As StringReference) As Boolean
		Dim success As Boolean
		Dim dateTimeRef As DateTimeReference

		dateTimeRef = New DateTimeReference()
		success = GetDateTimeFromSeconds(seconds, dateTimeRef, message)

		If success
			success = CreateDateTimeTimezoneFromDateTimeAndTimeZoneInSeconds(dateTimeRef.dateTimex, offset, dateTimeTzRef, message)
		End If

		Return success
	End Function


	Public Function CreateDateTime(year As Double, month As Double, day As Double, hours As Double, minutes As Double, seconds As Double) As DateTimex
		Dim dateTimex As DateTimex

		dateTimex = New DateTimex()

		dateTimex.datex = CreateDate(year, month, day)
		dateTimex.hours = hours
		dateTimex.minutes = minutes
		dateTimex.seconds = seconds

		Return dateTimex
	End Function


	Public Function GetDateTimeFromSeconds(seconds As Double, ByRef dateTimeReference As DateTimeReference, ByRef message As StringReference) As Boolean
		Dim dateTimex As DateTimex
		Dim secondsInMinute, secondsInHour, secondsInDay, days, remainder As Double
		Dim datex As Datex
		Dim dateReference As DateReference
		Dim success As Boolean

		secondsInMinute = 60
		secondsInHour = 60*secondsInMinute
		secondsInDay = 24*secondsInHour
		days = Floor(seconds/secondsInDay)
		remainder = seconds - days*secondsInDay
		dateReference = New DateReference()

		success = DayToDateWithCheck(days, dateReference, message)
		If success
			datex = dateReference.datex

			dateTimex = New DateTimex()
			dateTimex.datex = datex
			dateTimex.hours = Floor(remainder/secondsInHour)
			remainder = remainder - dateTimex.hours*secondsInHour
			dateTimex.minutes = Floor(remainder/secondsInMinute)
			remainder = remainder - dateTimex.minutes*secondsInMinute
			dateTimex.seconds = remainder

			dateTimeReference.dateTimex = dateTimex
		End If

		Return success
	End Function


	Public Function GetSecondsFromDateTime(ByRef dateTimex As DateTimex) As Double
		Dim seconds, secondsInMinute, secondsInHour As Double

		secondsInMinute = 60
		secondsInHour = 60*secondsInMinute

		seconds = GetSecondsFromDate(dateTimex.datex)
		seconds = seconds + secondsInHour*dateTimex.hours
		seconds = seconds + secondsInMinute*dateTimex.minutes
		seconds = seconds + dateTimex.seconds

		Return seconds
	End Function


	Public Function GetSecondsFromMinutes(minutes As Double) As Double
		Return minutes*60
	End Function


	Public Function GetSecondsFromHours(hours As Double) As Double
		Return GetSecondsFromMinutes(hours*60)
	End Function


	Public Function GetSecondsFromDays(days As Double) As Double
		Return GetSecondsFromHours(days*24)
	End Function


	Public Function GetSecondsFromWeeks(weeks As Double) As Double
		Return GetSecondsFromDays(weeks*7)
	End Function


	Public Function GetMinutesFromSeconds(seconds As Double) As Double
		Return seconds/60
	End Function


	Public Function GetHoursFromSeconds(seconds As Double) As Double
		Return GetMinutesFromSeconds(seconds)/60
	End Function


	Public Function GetDaysFromSeconds(seconds As Double) As Double
		Return GetHoursFromSeconds(seconds)/24
	End Function


	Public Function GetWeeksFromSeconds(seconds As Double) As Double
		Return GetDaysFromSeconds(seconds)/7
	End Function


	Public Function GetDateFromDateTime(ByRef dateTimex As DateTimex) As Datex
		Return dateTimex.datex
	End Function


	Public Function AddSecondsToDateTimeWithCheck(ByRef dateTimex As DateTimex, seconds As Double, ByRef dateTimeReference As DateTimeReference, ByRef message As StringReference) As Boolean
		Dim secondsInDateTime As Double
		Dim success As Boolean

		If IsValidDateTime(dateTimex, message)
			secondsInDateTime = GetSecondsFromDateTime(dateTimex)
			secondsInDateTime = secondsInDateTime + seconds

			success = GetDateTimeFromSeconds(secondsInDateTime, dateTimeReference, message)
		Else
			success = false
		End If

		Return success
	End Function


	Public Function AddSecondsToDateTime(ByRef dateTimex As DateTimex, seconds As Double, ByRef dateTimeReference As DateTimeReference, ByRef message As StringReference) As Boolean
		Dim secondsInDateTime As Double

		secondsInDateTime = GetSecondsFromDateTime(dateTimex)
		secondsInDateTime = secondsInDateTime + seconds

		Return GetDateTimeFromSeconds(secondsInDateTime, dateTimeReference, message)
	End Function


	Public Function AddMinutesToDateTime(ByRef dateTimex As DateTimex, minutes As Double, ByRef dateTimeReference As DateTimeReference, ByRef message As StringReference) As Boolean
		Return AddSecondsToDateTime(dateTimex, GetSecondsFromMinutes(minutes), dateTimeReference, message)
	End Function


	Public Function AddHoursToDateTime(ByRef dateTimex As DateTimex, hours As Double, ByRef dateTimeReference As DateTimeReference, ByRef message As StringReference) As Boolean
		Return AddSecondsToDateTime(dateTimex, GetSecondsFromHours(hours), dateTimeReference, message)
	End Function


	Public Function AddDaysToDateTime(ByRef dateTimex As DateTimex, days As Double, ByRef dateTimeReference As DateTimeReference, ByRef message As StringReference) As Boolean
		Return AddSecondsToDateTime(dateTimex, GetSecondsFromDays(days), dateTimeReference, message)
	End Function


	Public Function AddWeeksToDateTime(ByRef dateTimex As DateTimex, weeks As Double, ByRef dateTimeReference As DateTimeReference, ByRef message As StringReference) As Boolean
		Return AddSecondsToDateTime(dateTimex, GetSecondsFromWeeks(weeks), dateTimeReference, message)
	End Function


	Public Function DateTimeToStringISO8601WithCheck(ByRef datetimex As DateTimex, ByRef dateStr As StringReference, ByRef message As StringReference) As Boolean
		Dim success As Boolean

		success = DateToStringISO8601WithCheck(datetimex.datex, dateStr, message)

		If success
			Erase dateStr.stringx 

			success = IsValidDateTime(datetimex, message)
			If success
				dateStr.stringx = DateTimeToStringISO8601(datetimex)
			End If
		End If

		Return success
	End Function


	Public Function IsValidDateTime(ByRef datetimex As DateTimex, ByRef message As StringReference) As Boolean
		Dim success As Boolean

		success = IsValidDate(datetimex.datex, message)

		If success
			If datetimex.hours <= 23 And datetimex.hours >= 0
				If datetimex.minutes <= 59 And datetimex.minutes >= 0
					If datetimex.seconds <= 59 And datetimex.seconds >= 0
						success = true
					Else
						success = false
						message.stringx = "Seconds must be between 0 and 59.".ToCharArray()
					End If
				Else
					success = false
					message.stringx = "Minutes must be between 0 and 59.".ToCharArray()
				End If
			Else
				success = false
				message.stringx = "Hours must be between 0 and 23.".ToCharArray()
			End If
		End If

		Return success
	End Function


	Public Function DateTimeToStringISO8601(ByRef datetimex As DateTimex) As Char ()
		Dim datestr, str As Char ()
		Dim i As Double

		str = New Char (19 - 1){}

		datestr = DateToStringISO8601(datetimex.datex)
		i = 0
		While i < datestr.Length
			str(i) = datestr(i)
			i = i + 1
		End While

		str(10) = "T"C
		str(11) = charDecimalDigitToCharacter(Floor((datetimex.hours Mod 100)/10))
		str(12) = charDecimalDigitToCharacter(Floor(datetimex.hours Mod 10))

		str(13) = ":"C

		str(14) = charDecimalDigitToCharacter(Floor((datetimex.minutes Mod 100)/10))
		str(15) = charDecimalDigitToCharacter(Floor(datetimex.minutes Mod 10))

		str(16) = ":"C

		str(17) = charDecimalDigitToCharacter(Floor((datetimex.seconds Mod 100)/10))
		str(18) = charDecimalDigitToCharacter(Floor(datetimex.seconds Mod 10))

		Return str
	End Function


	Public Function DateTimeFromStringISO8601(ByRef str As Char ()) As DateTimex
		Dim dateTimex As DateTimex
		Dim n As Double

		dateTimex = New DateTimex()

		dateTimex.datex = DateFromStringISO8601(str)

		n = charCharacterToDecimalDigit(str(11))*10
		n = n + charCharacterToDecimalDigit(str(12))*1

		dateTimex.hours = n

		n = charCharacterToDecimalDigit(str(14))*10
		n = n + charCharacterToDecimalDigit(str(15))*1

		dateTimex.minutes = n

		n = charCharacterToDecimalDigit(str(17))*10
		n = n + charCharacterToDecimalDigit(str(18))*1

		dateTimex.seconds = n

		Return dateTimex
	End Function


	Public Function DateTimeFromStringISO8601WithCheck(ByRef str As Char (), ByRef dateTimeRef As DateTimeReference, ByRef message As StringReference) As Boolean
		Dim valid As Boolean

		valid = IsValidDateTimeISO8601(str, message)

		If valid
			dateTimeRef.dateTimex = DateTimeFromStringISO8601(str)
		End If

		Return valid
	End Function


	Public Function IsValidDateTimeISO8601(ByRef str As Char (), ByRef message As StringReference) As Boolean
		Dim valid As Boolean

		If str.Length = 4 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2

			If charIsNumber(str(0)) And charIsNumber(str(1)) And charIsNumber(str(2)) And charIsNumber(str(3)) And charIsNumber(str(5)) And charIsNumber(str(6)) And charIsNumber(str(8)) And charIsNumber(str(9)) And charIsNumber(str(11)) And charIsNumber(str(12)) And charIsNumber(str(14)) And charIsNumber(str(15)) And charIsNumber(str(17)) And charIsNumber(str(18))
				If str(4) = "-"C And str(7) = "-"C And str(10) = "T"C And str(13) = ":"C And str(16) = ":"C
					valid = true
				Else
					valid = false
					message.stringx = "ISO8601 date must use \'-\' in positions 5 and 8, \'T\' in position 11 and \':\' in positions 14 and 17.".ToCharArray()
				End If
			Else
				valid = false
				message.stringx = "ISO8601 date must use decimal digits in positions 1, 2, 3, 4, 6, 7, 9, 10, 12, 13, 15, 16, 18 and 19.".ToCharArray()
			End If
		Else
			valid = false
			message.stringx = "ISO8601 date must be exactly 19 characters long.".ToCharArray()
		End If

		Return valid
	End Function


	Public Function DateTimeEquals(ByRef a As DateTimex, ByRef b As DateTimex) As Boolean
		Return DateEquals(a.datex, b.datex) And a.hours = b.hours And a.minutes = b.minutes And a.seconds = b.seconds
	End Function


	Public Sub FreeDateTime(ByRef datetimex As DateTimex)
		datetimex.datex = Nothing
		datetimex = Nothing
	End Sub


	Public Function charToLowerCase(character As Char) As Char
		Dim toReturn As Char

		toReturn = character
		If character = "A"C
			toReturn = "a"C
		ElseIf character = "B"C
			toReturn = "b"C
		ElseIf character = "C"C
			toReturn = "c"C
		ElseIf character = "D"C
			toReturn = "d"C
		ElseIf character = "E"C
			toReturn = "e"C
		ElseIf character = "F"C
			toReturn = "f"C
		ElseIf character = "G"C
			toReturn = "g"C
		ElseIf character = "H"C
			toReturn = "h"C
		ElseIf character = "I"C
			toReturn = "i"C
		ElseIf character = "J"C
			toReturn = "j"C
		ElseIf character = "K"C
			toReturn = "k"C
		ElseIf character = "L"C
			toReturn = "l"C
		ElseIf character = "M"C
			toReturn = "m"C
		ElseIf character = "N"C
			toReturn = "n"C
		ElseIf character = "O"C
			toReturn = "o"C
		ElseIf character = "P"C
			toReturn = "p"C
		ElseIf character = "Q"C
			toReturn = "q"C
		ElseIf character = "R"C
			toReturn = "r"C
		ElseIf character = "S"C
			toReturn = "s"C
		ElseIf character = "T"C
			toReturn = "t"C
		ElseIf character = "U"C
			toReturn = "u"C
		ElseIf character = "V"C
			toReturn = "v"C
		ElseIf character = "W"C
			toReturn = "w"C
		ElseIf character = "X"C
			toReturn = "x"C
		ElseIf character = "Y"C
			toReturn = "y"C
		ElseIf character = "Z"C
			toReturn = "z"C
		End If

		Return toReturn
	End Function


	Public Function charToUpperCase(character As Char) As Char
		Dim toReturn As Char

		toReturn = character
		If character = "a"C
			toReturn = "A"C
		ElseIf character = "b"C
			toReturn = "B"C
		ElseIf character = "c"C
			toReturn = "C"C
		ElseIf character = "d"C
			toReturn = "D"C
		ElseIf character = "e"C
			toReturn = "E"C
		ElseIf character = "f"C
			toReturn = "F"C
		ElseIf character = "g"C
			toReturn = "G"C
		ElseIf character = "h"C
			toReturn = "H"C
		ElseIf character = "i"C
			toReturn = "I"C
		ElseIf character = "j"C
			toReturn = "J"C
		ElseIf character = "k"C
			toReturn = "K"C
		ElseIf character = "l"C
			toReturn = "L"C
		ElseIf character = "m"C
			toReturn = "M"C
		ElseIf character = "n"C
			toReturn = "N"C
		ElseIf character = "o"C
			toReturn = "O"C
		ElseIf character = "p"C
			toReturn = "P"C
		ElseIf character = "q"C
			toReturn = "Q"C
		ElseIf character = "r"C
			toReturn = "R"C
		ElseIf character = "s"C
			toReturn = "S"C
		ElseIf character = "t"C
			toReturn = "T"C
		ElseIf character = "u"C
			toReturn = "U"C
		ElseIf character = "v"C
			toReturn = "V"C
		ElseIf character = "w"C
			toReturn = "W"C
		ElseIf character = "x"C
			toReturn = "X"C
		ElseIf character = "y"C
			toReturn = "Y"C
		ElseIf character = "z"C
			toReturn = "Z"C
		End If

		Return toReturn
	End Function


	Public Function charIsUpperCase(character As Char) As Boolean
		Dim isUpper As Boolean

		isUpper = true
		If character = "A"C
		ElseIf character = "B"C
		ElseIf character = "C"C
		ElseIf character = "D"C
		ElseIf character = "E"C
		ElseIf character = "F"C
		ElseIf character = "G"C
		ElseIf character = "H"C
		ElseIf character = "I"C
		ElseIf character = "J"C
		ElseIf character = "K"C
		ElseIf character = "L"C
		ElseIf character = "M"C
		ElseIf character = "N"C
		ElseIf character = "O"C
		ElseIf character = "P"C
		ElseIf character = "Q"C
		ElseIf character = "R"C
		ElseIf character = "S"C
		ElseIf character = "T"C
		ElseIf character = "U"C
		ElseIf character = "V"C
		ElseIf character = "W"C
		ElseIf character = "X"C
		ElseIf character = "Y"C
		ElseIf character = "Z"C
		Else
			isUpper = false
		End If

		Return isUpper
	End Function


	Public Function charIsLowerCase(character As Char) As Boolean
		Dim isLower As Boolean

		isLower = true
		If character = "a"C
		ElseIf character = "b"C
		ElseIf character = "c"C
		ElseIf character = "d"C
		ElseIf character = "e"C
		ElseIf character = "f"C
		ElseIf character = "g"C
		ElseIf character = "h"C
		ElseIf character = "i"C
		ElseIf character = "j"C
		ElseIf character = "k"C
		ElseIf character = "l"C
		ElseIf character = "m"C
		ElseIf character = "n"C
		ElseIf character = "o"C
		ElseIf character = "p"C
		ElseIf character = "q"C
		ElseIf character = "r"C
		ElseIf character = "s"C
		ElseIf character = "t"C
		ElseIf character = "u"C
		ElseIf character = "v"C
		ElseIf character = "w"C
		ElseIf character = "x"C
		ElseIf character = "y"C
		ElseIf character = "z"C
		Else
			isLower = false
		End If

		Return isLower
	End Function


	Public Function charIsLetter(character As Char) As Boolean
		Return charIsUpperCase(character) Or charIsLowerCase(character)
	End Function


	Public Function charIsNumber(character As Char) As Boolean
		Dim isNumberx As Boolean

		isNumberx = true
		If character = "0"C
		ElseIf character = "1"C
		ElseIf character = "2"C
		ElseIf character = "3"C
		ElseIf character = "4"C
		ElseIf character = "5"C
		ElseIf character = "6"C
		ElseIf character = "7"C
		ElseIf character = "8"C
		ElseIf character = "9"C
		Else
			isNumberx = false
		End If

		Return isNumberx
	End Function


	Public Function charIsWhiteSpace(character As Char) As Boolean
		Dim isWhiteSpacex As Boolean

		isWhiteSpacex = true
		If character = " "C
		ElseIf character = vbTab
		ElseIf character = vblf
		ElseIf character = vbcr
		Else
			isWhiteSpacex = false
		End If

		Return isWhiteSpacex
	End Function


	Public Function charIsSymbol(character As Char) As Boolean
		Dim isSymbolx As Boolean

		isSymbolx = true
		If character = "!"C
		ElseIf character = """"C
		ElseIf character = "#"C
		ElseIf character = "$"C
		ElseIf character = "%"C
		ElseIf character = "&"C
		ElseIf character = "'"C
		ElseIf character = "("C
		ElseIf character = ")"C
		ElseIf character = "*"C
		ElseIf character = "+"C
		ElseIf character = ","C
		ElseIf character = "-"C
		ElseIf character = "."C
		ElseIf character = "/"C
		ElseIf character = ":"C
		ElseIf character = ";"C
		ElseIf character = "<"C
		ElseIf character = "="C
		ElseIf character = ">"C
		ElseIf character = "?"C
		ElseIf character = "@"C
		ElseIf character = "["C
		ElseIf character = "\"C
		ElseIf character = "]"C
		ElseIf character = "^"C
		ElseIf character = "_"C
		ElseIf character = "`"C
		ElseIf character = "{"C
		ElseIf character = "|"C
		ElseIf character = "}"C
		ElseIf character = "~"C
		Else
			isSymbolx = false
		End If

		Return isSymbolx
	End Function


	Public Function charCharacterIsBefore(a As Char, b As Char) As Boolean
		Dim ad, bd As Double

		ad = Convert.ToInt16(a)
		bd = Convert.ToInt16(b)

		Return ad < bd
	End Function


	Public Function charDecimalDigitToCharacter(digit As Double) As Char
		Dim c As Char
		If digit = 1
			c = "1"C
		ElseIf digit = 2
			c = "2"C
		ElseIf digit = 3
			c = "3"C
		ElseIf digit = 4
			c = "4"C
		ElseIf digit = 5
			c = "5"C
		ElseIf digit = 6
			c = "6"C
		ElseIf digit = 7
			c = "7"C
		ElseIf digit = 8
			c = "8"C
		ElseIf digit = 9
			c = "9"C
		Else
			c = "0"C
		End If
		Return c
	End Function


	Public Function charCharacterToDecimalDigit(c As Char) As Double
		Dim digit As Double

		If c = "1"C
			digit = 1
		ElseIf c = "2"C
			digit = 2
		ElseIf c = "3"C
			digit = 3
		ElseIf c = "4"C
			digit = 4
		ElseIf c = "5"C
			digit = 5
		ElseIf c = "6"C
			digit = 6
		ElseIf c = "7"C
			digit = 7
		ElseIf c = "8"C
			digit = 8
		ElseIf c = "9"C
			digit = 9
		Else
			digit = 0
		End If

		Return digit
	End Function


	Public Sub AssertFalse(b As Boolean, ByRef failures As NumberReference)
		If b
			failures.numberValue = failures.numberValue + 1
		End If
	End Sub


	Public Sub AssertTrue(b As Boolean, ByRef failures As NumberReference)
		If Not b
			failures.numberValue = failures.numberValue + 1
		End If
	End Sub


	Public Sub AssertEquals(a As Double, b As Double, ByRef failures As NumberReference)
		If a <> b
			failures.numberValue = failures.numberValue + 1
		End If
	End Sub


	Public Sub AssertBooleansEqual(a As Boolean, b As Boolean, ByRef failures As NumberReference)
		If a <> b
			failures.numberValue = failures.numberValue + 1
		End If
	End Sub


	Public Sub AssertCharactersEqual(a As Char, b As Char, ByRef failures As NumberReference)
		If a <> b
			failures.numberValue = failures.numberValue + 1
		End If
	End Sub


	Public Sub AssertStringEquals(ByRef a As Char (), ByRef b As Char (), ByRef failures As NumberReference)
		If Not StringsEqual(a, b)
			failures.numberValue = failures.numberValue + 1
		End If
	End Sub


	Public Sub AssertNumberArraysEqual(ByRef a As Double (), ByRef b As Double (), ByRef failures As NumberReference)
		Dim i As Double

		If a.Length = b.Length
			i = 0
			While i < a.Length
				Call AssertEquals(a(i), b(i), failures)
				i = i + 1
			End While
		Else
			failures.numberValue = failures.numberValue + 1
		End If
	End Sub


	Public Sub AssertBooleanArraysEqual(ByRef a As Boolean (), ByRef b As Boolean (), ByRef failures As NumberReference)
		Dim i As Double

		If a.Length = b.Length
			i = 0
			While i < a.Length
				Call AssertBooleansEqual(a(i), b(i), failures)
				i = i + 1
			End While
		Else
			failures.numberValue = failures.numberValue + 1
		End If
	End Sub


	Public Sub AssertStringArraysEqual(ByRef a As StringReference (), ByRef b As StringReference (), ByRef failures As NumberReference)
		Dim i As Double

		If a.Length = b.Length
			i = 0
			While i < a.Length
				Call AssertStringEquals(a(i).stringx, b(i).stringx, failures)
				i = i + 1
			End While
		Else
			failures.numberValue = failures.numberValue + 1
		End If
	End Sub


	Public Function Negate(x As Double) As Double
		Return -x
	End Function


	Public Function Positive(x As Double) As Double
		Return +x
	End Function


	Public Function Factorial(x As Double) As Double
		Dim i, f As Double

		f = 1

		i = 2
		While i <= x
			f = f*i
			i = i + 1
		End While

		Return f
	End Function


	Public Function Roundx(x As Double) As Double
		Return Floor(x + 0.5)
	End Function


	Public Function BankersRound(x As Double) As Double
		Dim r As Double

		If Absolute(x - Truncatex(x)) = 0.5
			If Not DivisibleBy(Roundx(x), 2)
				r = Roundx(x) - 1
			Else
				r = Roundx(x)
			End If
		Else
			r = Roundx(x)
		End If

		Return r
	End Function


	Public Function Ceil(x As Double) As Double
		Return Ceiling(x)
	End Function


	Public Function Floorx(x As Double) As Double
		Return Floor(x)
	End Function


	Public Function Truncatex(x As Double) As Double
		Dim t As Double

		If x >= 0
			t = Floor(x)
		Else
			t = Ceiling(x)
		End If

		Return t
	End Function


	Public Function Absolute(x As Double) As Double
		Return Abs(x)
	End Function


	Public Function Logarithm(x As Double) As Double
		Return Log10(x)
	End Function


	Public Function NaturalLogarithm(x As Double) As Double
		Return Log(x)
	End Function


	Public Function Sinx(x As Double) As Double
		Return Sin(x)
	End Function


	Public Function Cosx(x As Double) As Double
		Return Cos(x)
	End Function


	Public Function Tanx(x As Double) As Double
		Return Tan(x)
	End Function


	Public Function Asinx(x As Double) As Double
		Return Asin(x)
	End Function


	Public Function Acosx(x As Double) As Double
		Return Acos(x)
	End Function


	Public Function Atanx(x As Double) As Double
		Return Atan(x)
	End Function


	Public Function Atan2x(y As Double, x As Double) As Double
		Dim a As Double

		' Atan2 is an invalid operation when x = 0 and y = 0, but this method does not return errors.
		a = 0

		If x > 0
			a = Atanx(y/x)
		ElseIf x < 0 And y >= 0
			a = Atanx(y/x) + Pi
		ElseIf x < 0 And y < 0
			a = Atanx(y/x) - Pi
		ElseIf x = 0 And y > 0
			a = Pi/2
		ElseIf x = 0 And y < 0
			a = -Pi/2
		End If

		Return a
	End Function


	Public Function Squareroot(x As Double) As Double
		Return Sqrt(x)
	End Function


	Public Function Expx(x As Double) As Double
		Return Exp(x)
	End Function


	Public Function DivisibleBy(a As Double, b As Double) As Boolean
		Return ((a Mod b) = 0)
	End Function


	Public Function Combinations(n As Double, k As Double) As Double
		Dim i, j, c As Double

		c = 1
		j = 1
		i = n - k + 1

		
		While i <= n
			c = c*i
			c = c/j

			i = i + 1
			j = j + 1
		End While

		Return c
	End Function


	Public Function Permutations(n As Double, k As Double) As Double
		Dim i, c As Double

		c = 1

		i = n - k + 1
		While i <= n
			c = c*i
			i = i + 1
		End While

		Return c
	End Function


	Public Function EpsilonCompare(a As Double, b As Double, epsilon As Double) As Boolean
		Return Abs(a - b) < epsilon
	End Function


	Public Function GreatestCommonDivisor(a As Double, b As Double) As Double
		Dim t As Double

		
		While b <> 0
			t = b
			b = a Mod b
			a = t
		End While

		Return a
	End Function


	Public Function GCDWithSubtraction(a As Double, b As Double) As Double
		Dim g As Double

		If a = 0
			g = b
		Else
			
			While b <> 0
				If a > b
					a = a - b
				Else
					b = b - a
				End If
			End While

			g = a
		End If

		Return g
	End Function


	Public Function IsInteger(a As Double) As Boolean
		Return (a - Floor(a)) = 0
	End Function


	Public Function GreatestCommonDivisorWithCheck(a As Double, b As Double, ByRef gcdReference As NumberReference) As Boolean
		Dim success As Boolean
		Dim gcd As Double

		If IsInteger(a) And IsInteger(b)
			gcd = GreatestCommonDivisor(a, b)
			gcdReference.numberValue = gcd
			success = true
		Else
			success = false
		End If

		Return success
	End Function


	Public Function LeastCommonMultiple(a As Double, b As Double) As Double
		Dim lcm As Double

		If a > 0 And b > 0
			lcm = Abs(a*b)/GreatestCommonDivisor(a, b)
		Else
			lcm = 0
		End If

		Return lcm
	End Function


	Public Function Signx(a As Double) As Double
		Dim s As Double

		If a > 0
			s = 1
		ElseIf a < 0
			s = -1
		Else
			s = 0
		End If

		Return s
	End Function


	Public Function Maxx(a As Double, b As Double) As Double
		Return Max(a, b)
	End Function


	Public Function Minx(a As Double, b As Double) As Double
		Return Min(a, b)
	End Function


	Public Function Power(a As Double, b As Double) As Double
		Return a ^ b
	End Function


	Public Function Gamma(x As Double) As Double
		Return LanczosApproximation(x)
	End Function


	Public Function LogGamma(x As Double) As Double
		Return Log(Gamma(x))
	End Function


	Public Function LanczosApproximation(z As Double) As Double
		Dim p As Double ()
		Dim i, y, t, x As Double

		p = New Double (8 - 1){}
		p(0) = 676.5203681218851
		p(1) = -1259.1392167224028
		p(2) = 771.32342877765313
		p(3) = -176.61502916214059
		p(4) = 12.507343278686905
		p(5) = -0.13857109526572012
		p(6) = 9.9843695780195716e-6
		p(7) = 1.5056327351493116e-7

		If z < 0.5
			y = Pi/(Sin(Pi*z)*LanczosApproximation(1 - z))
		Else
			z = z - 1
			x = 0.99999999999980993
			i = 0
			While i < p.Length
				x = x + p(i)/(z + i + 1)
				i = i + 1
			End While
			t = z + p.Length - 0.5
			y = Sqrt(2*Pi)*t ^ (z + 0.5)*Exp(-t)*x
		End If

		Return y
	End Function


	Public Function Beta(x As Double, y As Double) As Double
		Return Gamma(x)*Gamma(y)/Gamma(x + y)
	End Function


	Public Function Sinhx(x As Double) As Double
		Return (Exp(x) - Exp(-x))/2
	End Function


	Public Function Coshx(x As Double) As Double
		Return (Exp(x) + Exp(-x))/2
	End Function


	Public Function Tanhx(x As Double) As Double
		Return Sinhx(x)/Coshx(x)
	End Function


	Public Function Cot(x As Double) As Double
		Return 1/Tan(x)
	End Function


	Public Function Sec(x As Double) As Double
		Return 1/Cos(x)
	End Function


	Public Function Csc(x As Double) As Double
		Return 1/Sin(x)
	End Function


	Public Function Coth(x As Double) As Double
		Return Coshx(x)/Sinhx(x)
	End Function


	Public Function Sech(x As Double) As Double
		Return 1/Coshx(x)
	End Function


	Public Function Csch(x As Double) As Double
		Return 1/Sinhx(x)
	End Function


	Public Function Errorx(x As Double) As Double
		Dim y, t, tau, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10 As Double

		If x = 0
			y = 0
		ElseIf x < 0
			y = -Errorx(-x)
		Else
			c1 = -1.26551223
			c2 = +1.00002368
			c3 = +0.37409196
			c4 = +0.09678418
			c5 = -0.18628806
			c6 = +0.27886807
			c7 = -1.13520398
			c8 = +1.48851587
			c9 = -0.82215223
			c10 = +0.17087277

			t = 1/(1 + 0.5*Abs(x))

			tau = t*Exp(-x ^ 2 + c1 + t*(c2 + t*(c3 + t*(c4 + t*(c5 + t*(c6 + t*(c7 + t*(c8 + t*(c9 + t*c10)))))))))

			y = 1 - tau
		End If

		Return y
	End Function


	Public Function ErrorInverse(x As Double) As Double
		Dim y, a, t As Double

		a = (8*(Pi - 3))/(3*Pi*(4 - Pi))

		t = 2/(Pi*a) + Log(1 - x ^ 2)/2
		y = Signx(x)*Sqrt(Sqrt(t ^ 2 - Log(1 - x ^ 2)/a) - t)

		Return y
	End Function


	Public Function FallingFactorial(x As Double, n As Double) As Double
		Dim k, y As Double

		y = 1

		k = 0
		While k <= n - 1
			y = y*(x - k)
			k = k + 1
		End While

		Return y
	End Function


	Public Function RisingFactorial(x As Double, n As Double) As Double
		Dim k, y As Double

		y = 1

		k = 0
		While k <= n - 1
			y = y*(x + k)
			k = k + 1
		End While

		Return y
	End Function


	Public Function Hypergeometric(a As Double, b As Double, c As Double, z As Double, maxIterations As Double, precision As Double) As Double
		Dim y As Double

		If Abs(z) >= 0.5
			y = (1 - z) ^ (-a)*HypergeometricDirect(a, c - b, c, z/(z - 1), maxIterations, precision)
		Else
			y = HypergeometricDirect(a, b, c, z, maxIterations, precision)
		End If

		Return y
	End Function


	Public Function HypergeometricDirect(a As Double, b As Double, c As Double, z As Double, maxIterations As Double, precision As Double) As Double
		Dim y, yp, n As Double
		Dim done As Boolean

		y = 0
		done = false

		n = 0
		While n < maxIterations And Not done
			yp = RisingFactorial(a, n)*RisingFactorial(b, n)/RisingFactorial(c, n)*z ^ n/Factorial(n)
			If Abs(yp) < precision
				done = true
			End If
			y = y + yp
			n = n + 1
		End While

		Return y
	End Function


	Public Function BernouilliNumber(n As Double) As Double
		Return AkiyamaTanigawaAlgorithm(n)
	End Function


	Public Function AkiyamaTanigawaAlgorithm(n As Double) As Double
		Dim m, j, B As Double
		Dim A As Double ()

		A = New Double (n + 1 - 1){}

		m = 0
		While m <= n
			A(m) = 1/(m + 1)
			j = m
			While j >= 1
				A(j - 1) = j*(A(j - 1) - A(j))
				j = j - 1
			End While
			m = m + 1
		End While

		B = A(0)

		Erase A 

		Return B
	End Function


	Public Function StringToNumberArray(ByRef stringx As Char ()) As Double ()
		Dim i As Double
		Dim arrayx As Double ()

		arrayx = New Double (stringx.Length - 1){}

		i = 0
		While i < stringx.Length
			arrayx(i) = Convert.ToInt16(stringx(i))
			i = i + 1
		End While
		Return arrayx
	End Function


	Public Function NumberArrayToString(ByRef arrayx As Double ()) As Char ()
		Dim i As Double
		Dim stringx As Char ()

		stringx = New Char (arrayx.Length - 1){}

		i = 0
		While i < arrayx.Length
			stringx(i) = Convert.ToChar(Convert.ToInt64(arrayx(i)))
			i = i + 1
		End While
		Return stringx
	End Function


	Public Function NumberArraysEqual(ByRef a As Double (), ByRef b As Double ()) As Boolean
		Dim equal As Boolean
		Dim i As Double

		equal = true
		If a.Length = b.Length
			i = 0
			While i < a.Length And equal
				If a(i) <> b(i)
					equal = false
				End If
				i = i + 1
			End While
		Else
			equal = false
		End If

		Return equal
	End Function


	Public Function BooleanArraysEqual(ByRef a As Boolean (), ByRef b As Boolean ()) As Boolean
		Dim equal As Boolean
		Dim i As Double

		equal = true
		If a.Length = b.Length
			i = 0
			While i < a.Length And equal
				If a(i) <> b(i)
					equal = false
				End If
				i = i + 1
			End While
		Else
			equal = false
		End If

		Return equal
	End Function


	Public Function StringsEqual(ByRef a As Char (), ByRef b As Char ()) As Boolean
		Dim equal As Boolean
		Dim i As Double

		equal = true
		If a.Length = b.Length
			i = 0
			While i < a.Length And equal
				If a(i) <> b(i)
					equal = false
				End If
				i = i + 1
			End While
		Else
			equal = false
		End If

		Return equal
	End Function


	Public Sub FillNumberArray(ByRef a As Double (), value As Double)
		Dim i As Double

		i = 0
		While i < a.Length
			a(i) = value
			i = i + 1
		End While
	End Sub


	Public Sub FillString(ByRef a As Char (), value As Char)
		Dim i As Double

		i = 0
		While i < a.Length
			a(i) = value
			i = i + 1
		End While
	End Sub


	Public Sub FillBooleanArray(ByRef a As Boolean (), value As Boolean)
		Dim i As Double

		i = 0
		While i < a.Length
			a(i) = value
			i = i + 1
		End While
	End Sub


	Public Function FillNumberArrayRange(ByRef a As Double (), value As Double, from As Double, tox As Double) As Boolean
		Dim i, length As Double
		Dim success As Boolean

		If from >= 0 And from <= a.Length And tox >= 0 And tox <= a.Length And from <= tox
			length = tox - from
			i = 0
			While i < length
				a(from + i) = value
				i = i + 1
			End While

			success = true
		Else
			success = false
		End If

		Return success
	End Function


	Public Function FillBooleanArrayRange(ByRef a As Boolean (), value As Boolean, from As Double, tox As Double) As Boolean
		Dim i, length As Double
		Dim success As Boolean

		If from >= 0 And from <= a.Length And tox >= 0 And tox <= a.Length And from <= tox
			length = tox - from
			i = 0
			While i < length
				a(from + i) = value
				i = i + 1
			End While

			success = true
		Else
			success = false
		End If

		Return success
	End Function


	Public Function FillStringRange(ByRef a As Char (), value As Char, from As Double, tox As Double) As Boolean
		Dim i, length As Double
		Dim success As Boolean

		If from >= 0 And from <= a.Length And tox >= 0 And tox <= a.Length And from <= tox
			length = tox - from
			i = 0
			While i < length
				a(from + i) = value
				i = i + 1
			End While

			success = true
		Else
			success = false
		End If

		Return success
	End Function


	Public Function CopyNumberArray(ByRef a As Double ()) As Double ()
		Dim i As Double
		Dim n As Double ()

		n = New Double (a.Length - 1){}

		i = 0
		While i < a.Length
			n(i) = a(i)
			i = i + 1
		End While

		Return n
	End Function


	Public Function CopyBooleanArray(ByRef a As Boolean ()) As Boolean ()
		Dim i As Double
		Dim n As Boolean ()

		n = New Boolean (a.Length - 1){}

		i = 0
		While i < a.Length
			n(i) = a(i)
			i = i + 1
		End While

		Return n
	End Function


	Public Function CopyString(ByRef a As Char ()) As Char ()
		Dim i As Double
		Dim n As Char ()

		n = New Char (a.Length - 1){}

		i = 0
		While i < a.Length
			n(i) = a(i)
			i = i + 1
		End While

		Return n
	End Function


	Public Function CopyNumberArrayRange(ByRef a As Double (), from As Double, tox As Double, ByRef copyReference As NumberArrayReference) As Boolean
		Dim i, length As Double
		Dim n As Double ()
		Dim success As Boolean

		If from >= 0 And from <= a.Length And tox >= 0 And tox <= a.Length And from <= tox
			length = tox - from
			n = New Double (length - 1){}

			i = 0
			While i < length
				n(i) = a(from + i)
				i = i + 1
			End While

			copyReference.numberArray = n
			success = true
		Else
			success = false
		End If

		Return success
	End Function


	Public Function CopyBooleanArrayRange(ByRef a As Boolean (), from As Double, tox As Double, ByRef copyReference As BooleanArrayReference) As Boolean
		Dim i, length As Double
		Dim n As Boolean ()
		Dim success As Boolean

		If from >= 0 And from <= a.Length And tox >= 0 And tox <= a.Length And from <= tox
			length = tox - from
			n = New Boolean (length - 1){}

			i = 0
			While i < length
				n(i) = a(from + i)
				i = i + 1
			End While

			copyReference.booleanArray = n
			success = true
		Else
			success = false
		End If

		Return success
	End Function


	Public Function CopyStringRange(ByRef a As Char (), from As Double, tox As Double, ByRef copyReference As StringReference) As Boolean
		Dim i, length As Double
		Dim n As Char ()
		Dim success As Boolean

		If from >= 0 And from <= a.Length And tox >= 0 And tox <= a.Length And from <= tox
			length = tox - from
			n = New Char (length - 1){}

			i = 0
			While i < length
				n(i) = a(from + i)
				i = i + 1
			End While

			copyReference.stringx = n
			success = true
		Else
			success = false
		End If

		Return success
	End Function


	Public Function IsLastElement(length As Double, index As Double) As Boolean
		Return index + 1 = length
	End Function


	Public Function CreateNumberArray(length As Double, value As Double) As Double ()
		Dim arrayx As Double ()

		arrayx = New Double (length - 1){}
		Call FillNumberArray(arrayx, value)

		Return arrayx
	End Function


	Public Function CreateBooleanArray(length As Double, value As Boolean) As Boolean ()
		Dim arrayx As Boolean ()

		arrayx = New Boolean (length - 1){}
		Call FillBooleanArray(arrayx, value)

		Return arrayx
	End Function


	Public Function CreateString(length As Double, value As Char) As Char ()
		Dim arrayx As Char ()

		arrayx = New Char (length - 1){}
		Call FillString(arrayx, value)

		Return arrayx
	End Function


	Public Sub SwapElementsOfNumberArray(ByRef A As Double (), ai As Double, bi As Double)
		Dim tmp As Double

		tmp = A(ai)
		A(ai) = A(bi)
		A(bi) = tmp
	End Sub


	Public Sub SwapElementsOfStringArray(ByRef A As StringArrayReference, ai As Double, bi As Double)
		Dim tmp As StringReference

		tmp = A.stringArray(ai)
		A.stringArray(ai) = A.stringArray(bi)
		A.stringArray(bi) = tmp
	End Sub


	Public Sub ReverseNumberArray(ByRef arrayx As Double ())
		Dim i As Double

		i = 0
		While i < arrayx.Length/2
			Call SwapElementsOfNumberArray(arrayx, i, arrayx.Length - i - 1)
			i = i + 1
		End While
	End Sub


End Module


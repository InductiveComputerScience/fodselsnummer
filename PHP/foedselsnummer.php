<?php
function isValidNorwegianPersonalIdentificationNumber(&$fnummer){
  if(count($fnummer) == 11.0){
    $failures = new stdClass();
    $failures->doubleValue = 0.0;
    $d1 = charToNumber($fnummer[0.0], $failures);
    $d2 = charToNumber($fnummer[1.0], $failures);
    $d3 = charToNumber($fnummer[2.0], $failures);
    $d4 = charToNumber($fnummer[3.0], $failures);
    $d5 = charToNumber($fnummer[4.0], $failures);
    $d6 = charToNumber($fnummer[5.0], $failures);
    $d7 = charToNumber($fnummer[6.0], $failures);
    $d8 = charToNumber($fnummer[7.0], $failures);
    $d9 = charToNumber($fnummer[8.0], $failures);
    $d10 = charToNumber($fnummer[9.0], $failures);
    $d11 = charToNumber($fnummer[10.0], $failures);
    if($failures->doubleValue == 0.0){
      $aDatetimeDate = getDateFromNorwegianPersonalIdentificationNumber($fnummer, $failures);
      if(datetimeisValidDate($aDatetimeDate)){
        if($failures->doubleValue == 0.0){
          $k1 = $d1*3.0 + $d2*7.0 + $d3*6.0 + $d4*1.0 + $d5*8.0 + $d6*9.0 + $d7*4.0 + $d8*5.0 + $d9*2.0;
          $k1 = $k1%11.0;
          if($k1 != 0.0){
            $k1 = 11.0 - $k1;
          }
          if($k1 == 10.0){
            $failures->doubleValue = $failures->doubleValue + 1.0;
          }
          $k2 = $d1*5.0 + $d2*4.0 + $d3*3.0 + $d4*2.0 + $d5*7.0 + $d6*6.0 + $d7*5.0 + $d8*4.0 + $d9*3.0 + $k1*2.0;
          $k2 = $k2%11.0;
          if($k2 != 0.0){
            $k2 = 11.0 - $k2;
          }
          if($k2 == 10.0){
            $failures->doubleValue = $failures->doubleValue + 1.0;
          }
          if($k1 == $d10 && $k2 == $d11 && $failures->doubleValue == 0.0){
            $gyldig = true;
          }else{
            $gyldig = false;
          }
        }else{
          $gyldig = false;
        }
      }else{
        $gyldig = false;
      }
    }else{
      $gyldig = false;
    }
  }else{
    $gyldig = false;
  }

  return $gyldig;
}
function getDateFromNorwegianPersonalIdentificationNumber(&$fnummer, $failures){
  $aDatetimeDate = new stdClass();

  $d1 = charToNumber($fnummer[0.0], $failures);
  $d2 = charToNumber($fnummer[1.0], $failures);
  $d3 = charToNumber($fnummer[2.0], $failures);
  $d4 = charToNumber($fnummer[3.0], $failures);
  $d5 = charToNumber($fnummer[4.0], $failures);
  $d6 = charToNumber($fnummer[5.0], $failures);
  $d7 = charToNumber($fnummer[6.0], $failures);
  $d8 = charToNumber($fnummer[7.0], $failures);
  $d9 = charToNumber($fnummer[8.0], $failures);

  if($failures->doubleValue == 0.0){
    $individnummer = $d7*100.0 + $d8*10.0 + $d9;
    $day = $d1*10.0 + $d2;
    $month = $d3*10.0 + $d4;
    $year = $d5*10.0 + $d6;
    if($individnummer >= 0.0 && $individnummer <= 499.0){
      $year = $year + 1900.0;
    }else if($individnummer >= 500.0 && $individnummer <= 749.0 && $year >= 54.0 && $year <= 99.0){
      $year = $year + 1800.0;
    }else if($individnummer >= 900.0 && $individnummer <= 999.0 && $year >= 40.0 && $year <= 99.0){
      $year = $year + 1900.0;
    }else if($individnummer >= 500.0 && $individnummer <= 999.0 && $year >= 0.0 && $year <= 39.0){
      $year = $year + 1900.0;
    }else{
      $failures->doubleValue = $failures->doubleValue + 1.0;
    }



    $aDatetimeDate->year = $year;
    $aDatetimeDate->month = $month;
    $aDatetimeDate->day = $day;
  }

  return $aDatetimeDate;
}
function charToNumber($c, $failures){
  if(isNumber($c, 10.0)){
    $val = getDecimalFromSingleDecimalDigit($c, 10.0);
  }else{
    $val = 0.0;
    $failures->doubleValue = $failures->doubleValue + 1.0;
  }

  return $val;
}
function test1(){
  $failures = new stdClass();
  $failures->doubleValue = 0.0;

  assertTrue(isValidNorwegianPersonalIdentificationNumber(str_split("10061270707")), $failures);

  return $failures->doubleValue;
}
function test(){
  $failures = 0.0;

  $failures = $failures + test1();

  return $failures;
}
function &decimalToString($decimal){
  return numberToString($decimal, 10.0);
}
function &numberToString($decimal, $base){
  $string = array_fill(0, 0.0, 0);

  $digits = getDigits($base);

  /* Find digitPosition: */
  $digitPosition = getDigitPosition($decimal, $base);

  $decimal = round($decimal*pow($base, -$digitPosition + $digits - 1.0));

  $hasPrintedPoint = false;

  /* Print leading zeros. */
  if($digitPosition < 0.0){
    $string = appendCharacter($string, "0");
    $string = appendCharacter($string, ".");
    $hasPrintedPoint = true;
    for($i = 0.0; $i < -$digitPosition - 1.0; $i = $i + 1.0){
      $string = appendCharacter($string, "0");
    }
  }

  /* Print number. */
  for($i = 0.0; $i < $digits; $i = $i + 1.0){
    $d = floor($decimal/pow($base, $digits - $i - 1.0));
    if( !$hasPrintedPoint  && $digitPosition - $i + 1.0 == 0.0){
      if($decimal != 0.0){
        $string = appendCharacter($string, ".");
      }
      $hasPrintedPoint = true;
    }
    if($decimal == 0.0 && $hasPrintedPoint){
    }else{
      $string = appendCharacter($string, getSingleDigitFromNumber($d, $base));
    }
    $decimal = $decimal - $d*pow($base, $digits - $i - 1.0);
  }

  /* Print trailing zeros. */
  for($i = 0.0; $i < $digitPosition - $digits + 1.0; $i = $i + 1.0){
    $string = appendCharacter($string, "0");
  }

  /* Done */
  return $string;
}
function getDigits($base){
  $t = pow(10.0, 15.0);
  return floor(log10($t)/log10($base));
}
function getDigitPosition($decimal, $base){
  $power = ceil(log10($decimal)/log10($base));

  $t = $decimal*pow($base, -$power);
  if($t < $base && $t >= 1.0){
  }else if($t >= $base){
    $power = $power + 1.0;
  }else if($t < 1.0){
    $power = $power - 1.0;
  }


  return $power;
}
function getSingleDigitFromNumber($c, $base){
  $numberTable = getNumberTable();

  if($c > $base - 1.0){
    $retc = "?";
  }else{
    $retc = $numberTable[$c];
  }

  return $retc;
}
function &getNumberTable(){
  $numberTable = array_fill(0, 16.0, 0);
  $numberTable[0.0] = "0";
  $numberTable[1.0] = "1";
  $numberTable[2.0] = "2";
  $numberTable[3.0] = "3";
  $numberTable[4.0] = "4";
  $numberTable[5.0] = "5";
  $numberTable[6.0] = "6";
  $numberTable[7.0] = "7";
  $numberTable[8.0] = "8";
  $numberTable[9.0] = "9";
  $numberTable[10.0] = "A";
  $numberTable[11.0] = "B";
  $numberTable[12.0] = "C";
  $numberTable[13.0] = "D";
  $numberTable[14.0] = "E";
  $numberTable[15.0] = "F";
  return $numberTable;
}
function stringToDecimal(&$string){
  return stringToDecimalForBase($string, 10.0);
}
function stringToDecimalForBase(&$string, $base){
  $stringToDecimalResult = new stdClass();
  $stringToDecimalResult->success = true;
  $i = 0.0;
  $isPositive = true;
  $beforeDecimalPoint = 0.0;
  $afterDecimalPoint = 0.0;
  $n = 0.0;
  $validCharacters = 0.0;

  if($base >= 2.0 && $base <= 16.0){
    for($j = 0.0; $j < count($string); $j = $j + 1.0){
      $c = $string[$j];
      if(isNumber($c, $base) || $c == "." || $c == "-"){
        $validCharacters = $validCharacters + 1.0;
      }
    }
    if($validCharacters == count($string)){
      if(count($string) > 0.0){
        $c = $string[$i];
        if($c == "-"){
          $isPositive = false;
          $i = $i + 1.0;
        }
        if($i < count($string)){
          $c = $string[$i];
          if(isNumber($c, $base)){
            for(; isNumber($c, $base) && ($i < count($string)); ){
              $beforeDecimalPoint = $beforeDecimalPoint + 1.0;
              $i = $i + 1.0;
              if($i < count($string)){
                $c = $string[$i];
              }
            }
            if($i < count($string)){
              $c = $string[$i];
              if($c == "."){
                $i = $i + 1.0;
                if($i < count($string)){
                  $c = $string[$i];
                  for(; isNumber($c, $base) && ($i < count($string)); ){
                    $afterDecimalPoint = $afterDecimalPoint + 1.0;
                    $i = $i + 1.0;
                    if($i < count($string)){
                      $c = $string[$i];
                    }
                  }
                }else{
                  $stringToDecimalResult->success = false;
                  $stringToDecimalResult->feilmelding = str_split("Number must have digits after the decimal point.");
                }
              }
            }
          }else{
            $stringToDecimalResult->success = false;
            $stringToDecimalResult->feilmelding = str_split("Number must start with digits (for negative numbers, after the optional negative sign).");
          }
        }
        if($stringToDecimalResult->success != false){
          $i = 0.0;
          if( !$isPositive ){
            $i = 1.0;
          }
          for($j = 0.0; $j < $beforeDecimalPoint; $j = $j + 1.0){
            $c = $string[$i];
            $i = $i + 1.0;
            $d = getDecimalFromSingleDecimalDigit($c, $base);
            $n = $n + $d*pow($base, $beforeDecimalPoint - $j - 1.0);
          }
          if($afterDecimalPoint > 0.0){
            $i = $i + 1.0;
            for($j = 0.0; $j < $afterDecimalPoint; $j = $j + 1.0){
              $c = $string[$i];
              $i = $i + 1.0;
              $d = getDecimalFromSingleDecimalDigit($c, $base);
              $n = $n + $d*pow($base, 0.0 - $j - 1.0);
            }
          }
          if( !$isPositive ){
            $n = -$n;
          }
          $stringToDecimalResult->result = $n;
          $stringToDecimalResult->success = true;
        }
      }else{
        $stringToDecimalResult->success = false;
        $stringToDecimalResult->feilmelding = str_split("String has no content.");
      }
    }else{
      $stringToDecimalResult->success = false;
      $stringToDecimalResult->feilmelding = str_split("String contains invalid character.");
    }
  }else{
    $stringToDecimalResult->success = false;
    $stringToDecimalResult->feilmelding = str_split("Base must be from 2 to 16.");
  }

  return $stringToDecimalResult;
}
function getDecimalFromSingleDecimalDigit($c, $base){
  $numberTable = getNumberTable();
  $position = 0.0;

  for($i = 0.0; $i < $base; $i = $i + 1.0){
    if($numberTable[$i] == $c){
      $position = $i;
    }
  }

  return $position;
}
function isNumber($c, $base){
  $numberTable = getNumberTable();
  $found = false;

  for($i = 0.0; $i < $base; $i = $i + 1.0){
    if($numberTable[$i] == $c){
      $found = true;
    }
  }

  return $found;
}
function datetimegetDateTimeFromSeconds($seconds){
  $dateTime = new stdClass();

  $secondsInMinute = 60.0;
  $secondsInHour = 60.0*$secondsInMinute;
  $secondsInDay = 24.0*$secondsInHour;
  $days = floor($seconds/$secondsInDay);
  $remainder = $seconds - $days*$secondsInDay;

  $date = datetimedayToDate($days, new stdClass());
  $dateTime->year = $date->year;
  $dateTime->month = $date->month;
  $dateTime->day = $date->day;

  $dateTime->hours = floor($remainder/$secondsInHour);
  $remainder = $remainder - $dateTime->hours*$secondsInHour;
  $dateTime->minutes = floor($remainder/$secondsInMinute);
  $remainder = $remainder - $dateTime->minutes*$secondsInMinute;
  $dateTime->seconds = $remainder;

  return $dateTime;
}
function datetimegetSecondsFromDateTime($dateTime){
  $seconds = 0.0;

  $date = new stdClass();
  $date->year = $dateTime->year;
  $date->month = $dateTime->month;
  $date->day = $dateTime->day;

  $days = datetimedateToDayNumber($date, new stdClass());

  $secondsInMinute = 60.0;
  $secondsInHour = 60.0*$secondsInMinute;
  $secondsInDay = 24.0*$secondsInHour;

  $seconds = $seconds + $secondsInDay*$days;
  $seconds = $seconds + $secondsInHour*$dateTime->hours;
  $seconds = $seconds + $secondsInMinute*$dateTime->minutes;
  $seconds = $seconds + $dateTime->seconds;

  return $seconds;
}
function datetimeisLeapYear($year, $success){
  if($year >= 1752.0){
    $success->success = true;
    if(divisibleBy($year, 4.0)){
      if(divisibleBy($year, 100.0)){
        if(divisibleBy($year, 400.0)){
          $itIsLeapYear = true;
        }else{
          $itIsLeapYear = false;
        }
      }else{
        $itIsLeapYear = true;
      }
    }else{
      $itIsLeapYear = false;
    }
  }else{
    $success->success = false;
    $itIsLeapYear = false;
    $success->errorMessage = str_split("Gregorian calendar was not in general use.");
  }

  return $itIsLeapYear;
}
function datetimedayToDate($dayNr, $success){
  $date = new stdClass();
  $success->success = true;
  $remainder = new stdClass();
  $remainder->doubleValue = $dayNr + 79623.0;
  /* Days since 1752-01-01. Day 0: Thursday, 1970-01-01 */
  /* Find year. */
  $date->year = datetimegetYearFromDayNr($remainder->doubleValue, $remainder);

  /* Find month. */
  $date->month = datetimegetMonthFromDayNr($remainder->doubleValue, $date->year, $remainder);

  /* Find day. */
  $date->day = 1.0 + $remainder->doubleValue;

  return $date;
}
function datetimegetMonthFromDayNr($dayNr, $year, $remainder){
  $daysInMonth = datetimegetDaysInMonth($year);
  $done = false;
  $month = 1.0;

  for(;  !$done ; ){
    if($dayNr > $daysInMonth[$month]){
      $dayNr = $dayNr - $daysInMonth[$month];
      $month = $month + 1.0;
    }else{
      $done = true;
    }
  }
  $remainder->doubleValue = $dayNr;

  return $month;
}
function datetimegetYearFromDayNr($dayNr, $remainder){
  $done = false;
  $year = 1752.0;

  for(;  !$done ; ){
    if(datetimeisLeapYear($year, new stdClass())){
      $nrOfDays = 366.0;
    }else{
      $nrOfDays = 365.0;
    }
    if($dayNr >= $nrOfDays){
      $dayNr = $dayNr - $nrOfDays;
      $year = $year + 1.0;
    }else{
      $done = true;
    }
  }
  $remainder->doubleValue = $dayNr;

  return $year;
}
function &datetimegetDaysInMonth($year){
  $daysInMonth = array_fill(0, 1.0 + 12.0, 0);

  $daysInMonth[0.0] = 0.0;
  $daysInMonth[1.0] = 31.0;
  if(datetimeisLeapYear($year, new stdClass())){
    $daysInMonth[2.0] = 29.0;
  }else{
    $daysInMonth[2.0] = 28.0;
  }
  $daysInMonth[3.0] = 31.0;
  $daysInMonth[4.0] = 30.0;
  $daysInMonth[5.0] = 31.0;
  $daysInMonth[6.0] = 30.0;
  $daysInMonth[7.0] = 31.0;
  $daysInMonth[8.0] = 31.0;
  $daysInMonth[9.0] = 30.0;
  $daysInMonth[10.0] = 31.0;
  $daysInMonth[11.0] = 30.0;
  $daysInMonth[12.0] = 31.0;

  return $daysInMonth;
}
function datetimedateToDayNumber($date, $success){
  $success->success = true;
  $days = -79623.0;
  /* Day 1752-01-01 */
  $days = $days + datetimedaysInYears($date->year);
  $days = $days + datetimedaysInMonths($date->month, $date->year);
  $days = $days + $date->day - 1.0;

  return $days;
}
function datetimedaysInMonths($month, $year){
  $daysInMonth = datetimegetDaysInMonth($year);

  $days = 0.0;
  for($i = 1.0; $i < $month; $i = $i + 1.0){
    $days = $days + $daysInMonth[$i];
  }

  return $days;
}
function datetimedaysInYears($years){
  $days = 0.0;
  for($i = 1752.0; $i < $years; $i = $i + 1.0){
    if(datetimeisLeapYear($i, new stdClass())){
      $nrOfDays = 366.0;
    }else{
      $nrOfDays = 365.0;
    }
    $days = $days + $nrOfDays;
  }
  return $days;
}
function datetimeisValidDate($date){
  if($date->year >= 1752.0){
    if($date->month >= 1.0 && $date->month <= 12.0){
      $daysInMonth = datetimegetDaysInMonth($date->year);
      $daysInThisMonth = $daysInMonth[$date->month];
      if($date->day >= 1.0 && $date->day <= $daysInThisMonth){
        $valid = true;
      }else{
        $valid = false;
      }
    }else{
      $valid = false;
    }
  }else{
    $valid = false;
  }

  return $valid;
}
function assertFalse($b, $failures){
  if($b){
    $failures->doubleValue = $failures->doubleValue + 1.0;
  }
}
function assertTrue($b, $failures){
  if( !$b ){
    $failures->doubleValue = $failures->doubleValue + 1.0;
  }
}
function assertEquals($a, $b, $failures){
  if($a != $b){
    $failures->doubleValue = $failures->doubleValue + 1.0;
  }
}
function assertStringEquals(&$a, &$b, $failures){
  if( !stringsEqual($a, $b) ){
    $failures->doubleValue = $failures->doubleValue + 1.0;
  }
}
function &stringToNumberArray(&$string){
  $array = array_fill(0, count($string), 0);

  for($i = 0.0; $i < count($string); $i = $i + 1.0){
    $array[$i] = ord($string[$i]);
  }
  return $array;
}
function &numberArrayToString(&$array){
  $string = array_fill(0, count($array), 0);

  for($i = 0.0; $i < count($array); $i = $i + 1.0){
    $string[$i] = chr($array[$i]);
  }
  return $string;
}
function stringsEqual(&$data1, &$data2){
  $equal = false;
  if(count($data1) == count($data2)){
    $nrEqual = 0.0;
    for($i = 0.0; $i < count($data1); $i = $i + 1.0){
      if($data1[$i] == $data2[$i]){
        $nrEqual = $nrEqual + 1.0;
      }
    }
    if($nrEqual == count($data1)){
      $equal = true;
    }
  }else{
    $equal = false;
  }

  return $equal;
}
function numberArraysEqual(&$data1, &$data2){
  $equal = false;
  if(count($data1) == count($data2)){
    $nrEqual = 0.0;
    for($i = 0.0; $i < count($data1); $i = $i + 1.0){
      if($data1[$i] == $data2[$i]){
        $nrEqual = $nrEqual + 1.0;
      }
    }
    if($nrEqual == count($data1)){
      $equal = true;
    }
  }else{
    $equal = false;
  }

  return $equal;
}
function &substring(&$string, $from, $to){
  $n = array_fill(0, $to - $from, 0);

  for($i = $from; $i < $to; $i = $i + 1.0){
    $n[$i - $from] = $string[$i];
  }

  return $n;
}
function &appendString(&$string, &$s){
  $newString = array_fill(0, count($string) + count($s), 0);

  for($i = 0.0; $i < count($string); $i = $i + 1.0){
    $newString[$i] = $string[$i];
  }

  for($i = 0.0; $i < count($s); $i = $i + 1.0){
    $newString[count($string) + $i] = $s[$i];
  }

  unset($string);

  return $newString;
}
function &appendCharacter(&$string, $c){
  $newString = array_fill(0, count($string) + 1.0, 0);

  for($i = 0.0; $i < count($string); $i = $i + 1.0){
    $newString[$i] = $string[$i];
  }

  $newString[count($string)] = $c;

  unset($string);

  return $newString;
}
function &split(&$toSplit, $splitBy){
  $splitt = array_fill(0, 0.0, 0);

  $next = array_fill(0, 0.0, 0);
  for($i = 0.0; $i < count($toSplit); $i = $i + 1.0){
    $c = $toSplit[$i];
    if($c == $splitBy){
      $n = new stdClass();
      $n->string = $next;
      $splitt = addString($splitt, $n);
      $next = array_fill(0, 0.0, 0);
    }else{
      $next = appendCharacter($next, $c);
    }
  }

  if(count($next) > 0.0){
    $n = new stdClass();
    $n->string = $next;
    $splitt = addString($splitt, $n);
  }

  return $splitt;
}
function &addDecimal(&$list, $a){
  $newlist = array_fill(0, count($list) + 1.0, 0);
  for($i = 0.0; $i < count($list); $i = $i + 1.0){
    $newlist[$i] = $list[$i];
  }
  $newlist[count($list)] = $a;
		
  unset($list);
		
  return $newlist;
}
function addDecimalRef($list, $i){
  $list->list = addDecimal($list->list, $i);
}
function &removeDecimal(&$list, $n){
  $newlist = array_fill(0, count($list) - 1.0, 0);

  for($i = 0.0; $i < count($list); $i = $i + 1.0){
    if($i < $n){
      $newlist[$i] = $list[$i];
    }
    if($i > $n){
      $newlist[$i - 1.0] = $list[$i];
    }
  }
		
  unset($list);
		
  return $newlist;
}
function getDecimalRef($list, $i){
  return $list->list[$i];
}
function removeDecimalRef($list, $i){
  $list->list = removeDecimal($list->list, $i);
}
function &addString(&$list, $a){
  $newlist = array_fill(0, count($list) + 1.0, 0);

  for($i = 0.0; $i < count($list); $i = $i + 1.0){
    $newlist[$i] = $list[$i];
  }
  $newlist[count($list)] = $a;
		
  unset($list);
		
  return $newlist;
}
function addStringRef($list, $i){
  $list->list = addString($list->list, $i);
}
function &removeString(&$list, $n){
  $newlist = array_fill(0, count($list) - 1.0, 0);

  for($i = 0.0; $i < count($list); $i = $i + 1.0){
    if($i < $n){
      $newlist[$i] = $list[$i];
    }
    if($i > $n){
      $newlist[$i - 1.0] = $list[$i];
    }
  }
		
  unset($list);
		
  return $newlist;
}
function getStringRef($list, $i){
  return $list->list[$i];
}
function removeStringRef($list, $i){
  $list->list = removeString($list->list, $i);
}
function Negate($x){
  return -$x;
}
function Positive($x){
  return +$x;
}
function Roundx($x){
  return round($x);
}
function Ceilx($x){
  return ceil($x);
}
function Floorx($x){
  return floor($x);
}
function Absolute($x){
  return abs($x);
}
function Logarithm($x){
  return log10($x);
}
function NaturalLogarithm($x){
  return log($x);
}
function Sinx($x){
  return sin($x);
}
function Cosx($x){
  return cos($x);
}
function Tanx($x){
  return tan($x);
}
function Asinx($x){
  return asin($x);
}
function Acosx($x){
  return acos($x);
}
function Atanx($x){
  return atan($x);
}
function Squareroot($x){
  return sqrt($x);
}
function Expx($x){
  return exp($x);
}
function divisibleBy($a, $b){
  return (($a%$b) == 0.0);
}


echo test();
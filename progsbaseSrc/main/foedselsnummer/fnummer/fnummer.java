package foedselsnummer.fnummer;

import datetimedatetime.DateCalculations.datetimeDate;
import references.references.DoubleReference;

import static datetimedatetime.DateCalculations.DateCalculations.datetimeisValidDate;
import static numbers.StringToDecimal.StringToDecimal.getDecimalFromSingleDecimalDigit;
import static numbers.StringToDecimal.StringToDecimal.isNumber;

public class fnummer {
    public static boolean isValidNorwegianPersonalIdentificationNumber(char [] fnummer){
        boolean gyldig;
        double d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
        datetimeDate aDatetimeDate;
        double k1, k2;
        DoubleReference failures;

        if(fnummer.length == 11d){
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

            if(failures.doubleValue == 0d) {
                aDatetimeDate = getDateFromNorwegianPersonalIdentificationNumber(fnummer, failures);

                if(datetimeisValidDate(aDatetimeDate)){
                    if(failures.doubleValue == 0d) {
                        k1 = d1*3d + d2*7d + d3*6d + d4*1d + d5*8d + d6*9d + d7*4d + d8*5d + d9*2d;
                        k1 = k1 % 11d;
                        if(k1 != 0d){
                            k1 = 11d - k1;
                        }
                        if(k1 == 10d){
                            failures.doubleValue = failures.doubleValue + 1d;
                        }

                        k2 = d1*5d + d2*4d + d3*3d + d4*2d + d5*7d + d6*6d + d7*5d + d8*4d + d9*3d + k1*2d;
                        k2 = k2 % 11d;
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
                } else {
                    gyldig = false;
                }
            } else {
                gyldig = false;
            }
        }else{
            gyldig = false;
        }

        return gyldig;
    }

    public static datetimeDate getDateFromNorwegianPersonalIdentificationNumber(char[] fnummer, DoubleReference failures){
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

        if(failures.doubleValue == 0d) {
            // Individnummer
            individnummer = d7 * 100d + d8 * 10d + d9;

            // Make date
            day = d1 * 10d + d2;
            month = d3 * 10d + d4;
            year = d5 * 10d + d6;

            if (individnummer >= 0d && individnummer <= 499d) {
                year = year + 1900d;
            } else if (individnummer >= 500d && individnummer <= 749d && year >= 54d && year <= 99d) {
                year = year + 1800d;
            } else if (individnummer >= 900d && individnummer <= 999d && year >= 40d && year <= 99d) {
                year = year + 1900d;
            } else if (individnummer >= 500d && individnummer <= 999d && year >= 0d && year <= 39d) {
                year = year + 1900d;
            } else {
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
}

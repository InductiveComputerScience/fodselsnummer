package foedselsnummer.fnummer;

import datetime.DateCalculations.Date;
import datetime.DateCalculations.DateReference;
import references.references.StringReference;

import static charCharacters.Characters.Characters.charCharacterToDecimalDigit;
import static charCharacters.Characters.Characters.charIsNumber;
import static datetime.DateCalculations.DateCalculations.IsValidDate;

public class fnummer {
    public static boolean IsValidNorwegianPersonalIdentificationNumber(char [] fnummer, StringReference message){
        boolean gyldig;
        double i, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
        double k1, k2;
        DateReference dateRef;

        if(fnummer.length == 11d){
            gyldig = true;
            for (i = 0d; i < fnummer.length; i = i + 1d) {
                if (charIsNumber(fnummer[(int) i])) {

                } else {
                    gyldig = false;
                }
            }

            if (gyldig) {
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

                if(gyldig) {
                    if (IsValidDate(dateRef.date, message)) {
                        k1 = d1 * 3d + d2 * 7d + d3 * 6d + d4 * 1d + d5 * 8d + d6 * 9d + d7 * 4d + d8 * 5d + d9 * 2d;
                        k1 = k1 % 11d;
                        if (k1 != 0d) {
                            k1 = 11d - k1;
                        }
                        if (k1 == 10d) {
                            gyldig = false;
                            message.string = "Control digit 1 is 10, which is invalid.".toCharArray();
                        }

                        if(gyldig) {
                            k2 = d1 * 5d + d2 * 4d + d3 * 3d + d4 * 2d + d5 * 7d + d6 * 6d + d7 * 5d + d8 * 4d + d9 * 3d + k1 * 2d;
                            k2 = k2 % 11d;
                            if (k2 != 0d) {
                                k2 = 11d - k2;
                            }
                            if (k2 == 10d) {
                                gyldig = false;
                                message.string = "Control digit 2 is 10, which is invalid.".toCharArray();
                            }

                            if (gyldig) {
                                if (k1 == d10) {
                                    if (k2 == d11) {
                                        gyldig = true;
                                    } else {
                                        gyldig = false;
                                        message.string = "Check of control digit 2 failed.".toCharArray();
                                    }
                                } else {
                                    gyldig = false;
                                    message.string = "Check of control digit 1 failed.".toCharArray();
                                }
                            }
                        }
                    } else {
                        gyldig = false;
                        message.string = "The date is not a valid date.".toCharArray();
                    }
                }
            } else {
                gyldig = false;
                message.string = "Each character must be a decimal digit.".toCharArray();
            }
        }else{
            gyldig = false;
            message.string = "Must be exactly 11 digits long.".toCharArray();
        }

        return gyldig;
    }

    public static boolean GetDateFromNorwegianPersonalIdentificationNumber(char[] fnummer, DateReference dateRef, StringReference message){
        double individnummer;
        double day, month, year;
        double i, d1, d2, d3, d4, d5, d6, d7, d8, d9;
        boolean success;

        success = true;
        dateRef.date = new Date();

        if(fnummer.length == 11d) {
            for (i = 0d; i < fnummer.length; i = i + 1d) {
                if (charIsNumber(fnummer[(int) i])) {

                } else {
                    success = false;
                }
            }

            if (success) {
                d1 = charCharacterToDecimalDigit(fnummer[0]);
                d2 = charCharacterToDecimalDigit(fnummer[1]);
                d3 = charCharacterToDecimalDigit(fnummer[2]);
                d4 = charCharacterToDecimalDigit(fnummer[3]);
                d5 = charCharacterToDecimalDigit(fnummer[4]);
                d6 = charCharacterToDecimalDigit(fnummer[5]);
                d7 = charCharacterToDecimalDigit(fnummer[6]);
                d8 = charCharacterToDecimalDigit(fnummer[7]);
                d9 = charCharacterToDecimalDigit(fnummer[8]);

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
                    year = year + 2000d;
                } else {
                    success = false;
                    message.string = "Invalid combination of individnummer and year.".toCharArray();
                }

                if(success) {
                    dateRef.date.year = year;
                    dateRef.date.month = month;
                    dateRef.date.day = day;
                }
            } else {
                message.string = "Each character must be a decimal digit.".toCharArray();
            }
        }else{
            message.string = "Must be exactly 11 digits long.".toCharArray();
        }

        return success;
    }
}

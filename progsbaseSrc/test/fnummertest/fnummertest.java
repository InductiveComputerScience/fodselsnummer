package fnummertest;

import datetime.DateCalculations.DateReference;
import references.references.NumberReference;
import references.references.StringReference;

import static foedselsnummer.fnummer.fnummer.GetDateFromNorwegianPersonalIdentificationNumber;
import static foedselsnummer.fnummer.fnummer.IsValidNorwegianPersonalIdentificationNumber;
import static references.references.references.CreateNumberReference;
import static testing.testing.testing.AssertEquals;
import static testing.testing.testing.AssertTrue;

public class fnummertest {
    public static void Test1(NumberReference failures){
        StringReference message;
        DateReference dateRef;
        boolean success;

        message = new StringReference();

        success = IsValidNorwegianPersonalIdentificationNumber("10061270707".toCharArray(), message);
        AssertTrue(success, failures);

        dateRef = new DateReference();

        success = GetDateFromNorwegianPersonalIdentificationNumber("11028559912".toCharArray(), dateRef, message);
        AssertTrue(success, failures);
        AssertEquals(dateRef.date.year, 1885d, failures);

        success = GetDateFromNorwegianPersonalIdentificationNumber("01019949768".toCharArray(), dateRef, message);
        AssertTrue(success, failures);
        AssertEquals(dateRef.date.year, 1999d, failures);

        success = GetDateFromNorwegianPersonalIdentificationNumber("01010099931".toCharArray(), dateRef, message);
        AssertTrue(success, failures);
        AssertEquals(dateRef.date.year, 2000d, failures);
    }
}

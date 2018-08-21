package fnummertest;

import references.references.DoubleReference;

import static foedselsnummer.fnummer.fnummer.isValidNorwegianPersonalIdentificationNumber;
import static testing.testing.testing.assertTrue;

public class fnummertest {
    public static double test1(){
        DoubleReference failures;
        failures = new DoubleReference();
        failures.doubleValue = 0d;

        assertTrue(isValidNorwegianPersonalIdentificationNumber("10061270707".toCharArray()), failures);

        return failures.doubleValue;
    }
}

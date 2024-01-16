package tests;

import references.references.NumberReference;

import static fnummertest.fnummertest.Test1;
import static references.references.references.CreateNumberReference;

public class tests {
    public static double test(){
        NumberReference failures;

        failures = CreateNumberReference(0d);

        Test1(failures);

        return failures.numberValue;
    }
}

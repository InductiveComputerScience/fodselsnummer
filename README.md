# Fodelsnummer or Fødselsnummer
This project contains a library for computations (validation and birth date extraction) on Norwegian Personal Identification Numbers in many programming languages. The library works exactly the same in all implementations:

 * Java
 * C
 * C++
 * JavaScript
 * C#
 * PHP
 * Python
 * Visual Basic

Norwegian Personal Identification Numbers is called fodelsnummer or fødselsnummer in norwegian.

The library has been made with [progsbase](https://www.progsbase.com), a tool for creating rot-resistant programs that are translatable to many programming languages.

The library can also be browsed and tested on the [progsbase repository's fodselsnummer page](https://repo.progsbase.com/repoviewer/no.inductive.libraries/foedselsnummer/0.1.2).

![progsbase logo](/docs/images/progsbase-logo.png)

For more information about progsbase, check out: [progsbase.com](https://www.progsbase.com).

## Usage

The library has the same interface in all programming languages.

### Validate
`boolean isValidNorwegianPersonalIdentificationNumber(char [] fnummer)`

The function takes a string as input, containing a norwegian personal identification number.

The output is a boolean, true if the number is valid and false if not.

### Extract Birth Date
`datetimeDate getDateFromNorwegianPersonalIdentificationNumber(char[] fnummer, DoubleReference failures)`

The function takes a string as input, containing a norwegian personal identification number and a reference to a double.

The output is a structure with three fields: year, month, day.

If the function fails, failures.doubleValue is a positive non-zero value.
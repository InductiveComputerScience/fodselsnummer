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

The library can also be browsed and tested on the [progsbase repository's fodselsnummer page](https://repo.progsbase.com/repoviewer/no.inductive.libraries/foedselsnummer/0.2.2).

![progsbase logo](/docs/images/progsbase-logo.png)

For more information about progsbase, check out: [progsbase.com](https://www.progsbase.com).

## Usage

The library has the same interface in all programming languages.

### Validate
`boolean isValidNorwegianPersonalIdentificationNumber(char [] fnummer, StringReference message)`

The function takes two inputs: a string, containing a norwegian personal identification number, and a string reference, that will get an error message.

The output is a boolean, true if the number is valid and false if not. If the return is false, message is set to a string explaining the reason.

### Extract Birth Date
`boolean GetDateFromNorwegianPersonalIdentificationNumber(char[] fnummer, DateReference dateRef, StringReference message)`

The function takes a string as input, containing a norwegian personal identification number, a reference to a date and a reference to a string.

The function returns true if successfull and false if not.

If the function succeeds, the date in the date reference is set with three fields: year, month, day.

If the function fails, the string reference message gets an error message.

The Idea:

QED Services International, LLC, was contracted by Whitewater Unified School District to write an Complex Number Calculator to help their students learn how to do "arithmetic" with complex numbers. As in the project was quite large in its scope, QED Services International, LLC, has subcontracted you to finish writing a “proof of concept” program for them. Under a previous contract, you’ve written a class for them, called mixedNumber (that inherits from another class you have written called Fraction), but due to an excessive amount work, they have had to subcontract this entire portion of the project to you.

As we know, a complex number can consist of only a real number, only an imaginary number, or the "sum" of a real number with an imaginary number (3+2i, for example).

The goal of this project is for you to develop a program that will allow a user to input  complex numbers (which can include only real number, only an imaginary number, or a "sum" of a real number with an imaginary number) that will be stored into "variables" labeled A to Z.. On input, only ONE complex number can be entered to assigned to a variable. All mathematical operations will be done with variables.

The program, named complexCalculate, if started on the command line with no parameters, when ready for input, a prompt such as INPUT: or COMMAND: must be printed. After each successful operation, this prompt will re-appear asking for the next command. Naturally, if the user enters just the return key, then the program will terminate.

When the COMMAND: or INPUT: prompt appears, the user will have the following options:

They can enter one of the following commands: LET, LOAD, SAVE, or PRINT, EXIT, or WEXIT.

      a. The command LET must be followed by a space, then a letter (A – Z), a space, then an equal sign (=), then by the complex number the user wishes to assign to this letter. (e.g. LET F = 2 + 4i). The result printed upon successful completion will be F = 2 + 4iin this example.

      b.     The command PRINT must be followed by a space then the letter representing a pre-stored complex number (e.g PRINT F). The program will respond by printing F = 2 + 4i, for example.

      c. The command SAVE shall be followed by a filename. If the filename does not end in .complex, the program shall ensure that it ends in .complex by either adding this extension or correcting the extension that the user provided. Of course, all verification of overwriting files, etc, must be done.

      d. The command LOAD shall be followed by a filename. If the filename does not end in .complex, the program shall ensure that it ends in .complex by either adding this extension or correcting the extension that the user provided.

      e. The command EXIT shall exit the program. If the user  has not immediately prior to this command saved the memory contents, the program shall prompt the user if they wish to save the data to a file. If they do, the restrictions for SAVE apply.

      f. The command WEXIT shall  be followed by a filename. The program will exit the program after following the guidelines for SAVE above.

2.     They can enter one of the following:

      a.     An expression, such as F = G + H, where F, G, and H are all pre-stored complex numbers. Upon completion, the program will print F = 2 + 4i, for example.

      b.     An expression, such as F = G - H, where F, G, and H are all pre-stored complex number. Upon completion, the program will print F = 2 + 4i, for example.

      c.     An expression, such as F = G * H, where F, G, and H are all pre-stored complex number. Upon completion, the program will print F = 2 + 4i, for example

      d.     An expression, such as F = G^H, where F is  the result of raising G to the H power (in complex number operations). As with the proceeding, the resultant complex number  will be printed.

      e.    An expression, such as F = G / H, where F, G, and H are all pre-stored complex number. Upon completion, the program will print F = 2 + 4i, for example

      f. Compute the Conjugate of Complex number by entering F = ~G. F would then hold 2 - 4i if G held 2 + 4i

      g, Trig(F) would display the polar coordinate version of the complex number. 

3.     They can enter LOAD followed by a file name. This will load up to 26 pre-defined, or saved earlier, complex numbers. (See below for additional when there are more than one parameter on the command line)

4. They can enter SAVE followed by a file name. This will save the contents of the 26 complex numbers to a file. As with all of the programs that you have done, the program must ensure that files are not accidentally overwritten and so forth. File names for these files must end in “.complex”

Command Line Parameters:

When there is one parameter on the command line after the name of the program, it will load the file associated with that name. If there is no extension on the name given, the default extension of “.complex” must be added to the file name before opening the file. Conversely, if there is a /h or /? As the parameter, then a “help message” must be displayed to the user and the program terminates.
When there are two parameters on the command line after the name of the program, the first parameter must be the word EXECUTE or RECORD. The next parameter is a “script” file, which is composed of commands, as stated from the above section which deals with input from the command line. If the word EXECUTE is present, then the program must read the file and perform all of the statements within the file. If the word in RECORD, then the program must save to a file all of the commands that the user enters in via the command line. Script files must have an extension of “.spt”; and, as above, the “.spt” must be added if the user did not provide it. 
If there are more than two parameters on the command line, then the program must “error out.”
Program Requirements

All values must be stored in a class called complexNumber. This class must be able to handle all operations between decimals, fractions, and integers with mixedNumbers. The following are some, but no where near all,  examples of complex numbers: 4, -2i, 3-2i, -3/2 - 3.5i, 4 2/3l.
All data must be stored as a complex number, with all output given as a complex number.
Only ONE input stream function in the main.cpp can be written for reading of input (whether it comes from a command line or a file). Thus, the input function must be passed a parameter telling it which stream is to be used for the reading of commands.
If the commands are coming from a file, they must be echoed to the screen. If the user is entering them, they must not be echoed.
All strings used must be C++ strings.
Exceptions must be used accordingly. Such as when a file does not exist, divide by zero, invalid input, and so forth.
There must be a class called memories that will store the complex numbers that have been entered. This class shall have an array of complex numbers.
Hints:

You can never forget anything learned in any CS course. Data storage sizes are very important, and mismatches can cause severe problems.
cplusplus.com is your friend.
“Divide and Concur” this program. First, jointly design the header files, then split up the coding. Then combine headers, the main, and so forth to make a working program.
Note that above specifications IMPLY that a class called complexNumber is required!!! This means that this class has to perform EVERYTHING in its own right! (Input, output, etc....)
Rules of the Test:

You may use any resource you wish, as long as it can be FULLY DOCUMENTED within your code.
You may work in teams of two and submit one test for the team.
You must be prepared to answer any question about your program when you demonstrate its functionality during lab.
Your program must, as discussed in class, conform to object oriented design constructs. (In short, this means that if a mixed number needs to do something, all code for what needs to be done must be in the mixed number class, its friends,  and so forth)
Extra Credit:

Addition of the ability to allow the entering of complex numbers in polar coordinate form and store them in "normal" (e.g. 2 + 4i) format. (50 points)
Addition of the ability to determine of two complex numbers are orthogonal to each other (50 points.)
Addition of the ability to compute the  magnitude of a complex number (50 points)

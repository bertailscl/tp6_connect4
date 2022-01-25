# TP6
### By Clément Bertails

Containing tp6

## Using the Program 

If you use make then the program will start by itself, you will be on a menu. Let it guide you.

Another way is to execute by typing ./programName
If you add an argument you will see the different exercises:
[1] : Invert array
[2] : Sum arrays
[3] : IsTransversible
[4] : IsPalindrome
[5] : Connect 4 (easy)
[6] : Connect 4 (Medium)
[7] : Connect 4 (Hard)
[Bad argument/ other] : Display menu

## Notes

None

## Compilation

Go to the decompressed folder via a terminal.
Execute "make".

## Generate Doxygen

If you want to generate the Doxygen, run "make docs".
!! You will have to install the graphviz package to avoid errors when generating the doxygen !!

## Read doxygen

Open the doc/html/index.html page generated at the time of "make docs".
The Doxyfile is also created with the above command.

## Delete unnecessary files

Run "make clean" : delete the bin folder containing the object files (*.o), the save folder containing a backup of the src folder, the doc folder containing the Doxygen,
the last archive created by "make give", the src.old folder created by "make restore" and the executable.

## Revert to last save

Run "make save": create the save folder if it doesn't exist and copy the src folder into it.

## Revenire à la dernière sauvegarde

Run "make restore": restore the backup from the save folder.

## Archive the program

Run "make give": a ready-to-give archive is created.
.nr VS 15p
.fam Verdana
.PDFPIC -C "logo.pdf" 3i 3i
.TL
Arrays, Structs and Strings in C
.AU
Muthana Al-Sirhan, #8785995
.AI
University of Wollongong in Dubai
CSCI291, Lab #2 Report

.PP

.XS 2
Lab Objective, Methodology
.XA 3
Array Utility Functions
.XA 6
Banking Transactions
.XA 9
League Team Application
.XE

.PX

.bp \" Page 2

.NH 1
Lab Objectives, Methodology
.PP

The goal of this lab is to design various programs that involve the usage of C-Arrays, Structs and Strings:-

.IP \(bu 
Arrays are groups of a fixed number of elements which are all of the same data type, useful for organizing grouping alike variables for ease of access.

.IP \(bu
Structures (or "structs") provide a similar use case, however they are more suitable for records as variables in a struct can be of many different data types. 

.IP \(bu
Strings are a group of characters in the shape of a char array appended with a NULL terminator


.PDFPIC -C "examples.pdf" 4i 4i

.bp \"Page 3

.NH 1
Array Utility Functions

.PP
Our first task is to program functions that can transform 1D arrays and matrices (2D arrays). They could be manipulated in any of the following ways:- 

.IP \(bu
.fam JetBrains
.B "[remove/insert]_element" 
.fam Verdana
are functions that can remove or insert an element in a specificed position within a 1D array.
.IP \(bu
.fam JetBrains
.B "found_duplicate" 
.fam Verdana
returns true if there are duplicate values in a 1D array.
.IP \(bu
.fam JetBrains
.B "reshape" 
.fam Verdana
can copy the elements of a 1D array into a matrix, filling it column by column.
.IP \(bu
.fam JetBrains
.B "trans_matrix" 
.fam Verdana
can transpose a matrix by flipping it about its diagonal [1], a common phenomenon in linear algebra.

Paper prototyping was perfect for planning the design for this program as it is a simple implementation of arrays:-

.PDFPIC "arrayPaperProto1.pdf" 3i 3i
.PDFPIC "arrayPaperProto2.pdf" 3i 3i

.FS [1]
https://en.wikipedia.org/wiki/Transpose
.FE

.bp \" Page 4

.NH 2
Array Utility Functions [
.fam JetBrains
is_valid, insert/remove_element, found_duplicate
.fam Verdana
]

.PP
Two functions are programmed to insert and remove an element of an array at a position specified by the user.
.fam JetBrains
.B "changedArray[]"
.fam Verdana
is the modified version of the original array, which is also printed by the function.
.fam JetBrains
.B "is_valid"
.fam Verdana
is called by the aforementioned functions to check if the user-specified index is a valid position in the array, while
.fam JetBrains
.B "found_duplicate"
.fam Verdana
reports if an inserted element is a duplicate of another.

.PDFPIC "array1.pdf" 5i 5i
.PDFPIC "array2.pdf" 5i 5i
.PDFPIC "array4.pdf" 5i 5i

.bp \" Page 5

.NH 2
Array Utility Functions [
.fam JetBrains
reshape, found_duplicate
.fam Verdana
]

.PP
2D arrays (or matrices) can be created and manipulated by using elements of 1D arrays. Function
.fam JetBrains
.B "reshape"
.fam Verdana
fills a matrix row by row with elements from a 1D array, that is if the length of the array is equal to the area of the matrix:- 

.fam JetBrains
.ft B
.ce
length = rows * cols

trans_matrix
.fam Verdana
.ft R
can "transpose" the matrix by flipping it about its diagonal, elements transform similar to the following:-

.fam JetBrains
.ft B
.ce
matT[0][1] = mat[1][0]
.fam Verdana
.ft R

.PDFPIC "array3.pdf" 5i 5i

.bp \" Page 6

.NH 1
Banking Transactions Processing (loop control with array, break, continue)

.PP
The flow of a loop in C can be controlled with "break" and "continue". This has various real world applications, one being the process of bank account transactions stored in an array. Positive values represent deposits whereas negative numbers represent withdrawals. The program could be simultaneously implemented and tested with the following steps:-

.IP
1. Start a variable 
.fam JetBrains
.B "balance"
.fam Verdana
of 1000 AED
.IP
2. Process the array of transactions in the following manner:-
.RS
.IP
a. Update the balance for valid transactions
.IP
b. If a withdrawal exceeds the current balance, skip it and print a message informing that it is invalid. Afterwards, it is stored in a separate 
.fam JetBrains
.B "toBeProcessed"
.fam Verdana
array.
.IP
c. If the balance reaches 0 at any point, stop processing further transactions with an accompanying message that states so, then store the unprocessed transactions in the 
.fam JetBrains
.B "toBeProcessed" 
.fam Verdana
array.
.RE
.IP
3. After cycling through all transactions, print the final balance and transactions that are yet to be processed (contents of 
.fam JetBrains
.B "toBeProcessed" 
.fam Verdana
array).

.PP
The algorithm is compiled as a flowchart in the following page.

.PDFPIC "atm.pdf" 4i 4i

.bp \" Page 7

.NH 2
Banking Transactions Processing (flowchart)
.PDFPIC "task2Flowchart.pdf" 8i 8i

.bp \" Page 8
.NH 2
Banking Transactions Processing (testing)

.PP
First of all, a balance of 1000 AED and an array of transactions to process are initialized. Another array
.fam JetBrains
.B "toBeProcessed"
.fam Verdana
is initialized with the purpose of storing skipped transactions that either result in balance less than or equal to 0.

.PDFPIC "bankCode1.pdf" 4i 4i

.PP
Transactions -200 and -400 should be skipped as -200 results in a negative balance while -400 results in 0 balance. In the latter case, all subsequent transactions are also skipped, as shown below.

.PDFPIC "bankCode2.pdf" 4i 4i

.bp \" Page 9
.NH 1
League Team Application (using arrays, structs)

.PP
As mentioned in the introduction, Structures can be great for data records. One real world scenario could be an application that holds and processes a squad of 
.fam JetBrains
.B "NUM_CLUBS"
.fam Verdana
enrolled in a football league. The attributes of each player and club can be grouped into struct definitions:-
.TS
allbox expand tab(|);
c s s s s 
cb cb cb cb cb
c c c c c.
Table 1: Player Attributes
Name (string) | Kit Number (int) | Club (string) | Age (struct) | Position (string)
T{
Full name of the player (first and last)
T}|T{
Players wear 2-digit numbered kits (1-99) 
T}|T{
Name of club player is enrolled in 
T}|T{
Age of the player through birthdate (day, month, year)
T}|T{
Describe a player's role within their club
T}
.TE

.TS
allbox center tab(|);
c s s
cb cb cb
c c c.
Table 2: Club Attributes
Name (string) | Array of players | Active Size (int)
T{
Name of the team
T}|T{
To store details of each individual player
T}|T{
To store amount of enrolled players in club
T}
.TE

.PP
Various user defined functions within this hypothetical program can enable core utility such as:-
.IP
1. 
.fam JetBrains
.B "enroll_club"
.fam Verdana
for enrolling a club by entering a club name. Cannot enroll more clubs if
.fam JetBrains
.B "NUM_CLUBS"
.fam Verdana
is reached.
.IP
2.
.fam JetBrains
.B "add_player"
.fam Verdana
for enrolling a player into the selected club. Should check for duplicates in names and kit numbers and discard them.
.IP
3.
.fam JetBrains
.B "search_update"
.fam Verdana
for searching a player by name and kit number, then updating any player attributes. (see page 8 for psuedocode on this functions algorithm)
.IP
4.
.fam JetBrains
.B "display_club_statistics"
.fam Verdana
for displaying a list of all enrolled clubs and details of each player.
.IP
5. Various utility functions for displaying the main interface and handling invalid input types without crashing the program.

.PDFPIC "leagueFC.pdf" 3i 3i

.bp \" Page 10

.NH 2
League Team Application [
.fam JetBrains
enroll_club(), add_player()
.fam Verdana
]
.PP
Clubs can be added to the database, then players can be enrolled into each club.

.PDFPIC "league1.pdf" 5i 5i

Players cannot be enrolled if there are no clubs added.

.PDFPIC "league2.pdf" 4i 4i

.bp \" Page 11
.NH 2
League Team Application [
.fam JetBrains
display_club_statistics()
.fam Verdana
]
.PP
Statistics of each club and each players attributes can be accessed with this function. Multiple "for" loops cycle through the entire database and print information.

.PDFPIC "league3.pdf" 6i 6i

.bp \" Page 12
.NH 2
League Team Application [
.fam JetBrains
search_update()
.fam Verdana
]
.PP
Players can be searched by name. Multiple "for" loops cycle through the entire database of enrolled clubs and players to search for the player. Once found, the player's attributes can be updated.
.PDFPIC "league4.pdf" 7i 7i

.bp \" Page 13
.NH 3
League Team Application [
.fam JetBrains
search_update()
.fam Verdana
algorithm]
.PDFPIC "psuedoSU.pdf" 8i 8i
.PP

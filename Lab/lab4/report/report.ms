.nr VS 15p
.fam Verdana
.PDFPIC -C "pics/logo.pdf" 3i 3i
.TL
C Pointers, Dynamic Memory, File Processing, Basic C++
.AU
Muthana Al-Sirhan, #8785995
.AI
University of Wollongong in Dubai
CSCI291, Lab #4 Report

.PP

.XS 2
Lab Objectives, Methodology
.XA 3
Basic Data Processing
.XA 4
LSB Steganography
.XA 7
Basic C++ Programming
.XE

.PX

.bp \" Page 2

.NH 1
Lab Objectives, Methodology
.PP

The goal of this lab is to utilize Pointers/Dynamic Data Structures combined with File Processing to write programs for real life scenarios. We are also introduced to basic C++ programming, learning how to scan input / print output and implementing default function parameters / passing parameters as reference.

.IP \(bu 
Pointers allow programs to simulate pass-by-reference, which enables passing functions between functions, to create and manipulate data structures that can change size at execution time, hence they are dynamic.

.IP \(bu
File Processing is the process of opening up files in a physical drive for reading or writing. ASCII/Text and Binary files can be processed.

.IP \(bu
C++ was developed as an evolved implementation of C which enables Object Oriented Programming. It became ISO/standard in 1998.

.PDFPIC -C "pics/ISO_C++_Logo.pdf" 4i 4i

.bp \"Page 3

.NH 1
Basic Data Processing

.PP
Our first task is to write a program that processes a text file with data by using
.fam JetBrains
.B "fopen(data.txt)"
.fam Verdana
consisting of floats and unintentional chars. The program must only scan the floats with
.fam JetBrains
.B "fscanf()"
.fam Verdana
and ignore the chars with the use of
.fam JetBrains
.B "fseek()"
.fam Verdana

.PDFPIC -C "pics/data_processing.pdf" 5i 5i
.PDFPIC -C "diagrams/data_processing.pdf" 5i 5i

.bp \" Page 4

.NH 1
LSB Steganography

.PP
Steganography is the practice (or "art") of embedding "secret" information within a cover. [1] In the case of this lab assignment, we are hiding a secret image within a cover image and extracting it again using an LSB (Least-Significant-Bits) algorithm which creates a "stego" image pixel whose most significant "nibble" [2] is the cover image pixel and least significant "nibble" is the secret image [3]. To extract this secret image, the reverse is done. C Bitwise operators, especially XOR, are used to achieve this.

.fam JetBrains
.ft B
.ce 4
Cover Image Pixel: 10100000
Secret Image Pixel: 00111111
Stego Image Pixel: 10100011
.fam Verdana
.ft R

Figure 1: Steganography encoding with LSB algorithm (N=4)

.ce 4
.fam JetBrains
.ft B
Stego Image Pixel: 10100011
Cover Image Pixel: 10100000
Secret Image Pixel: 00110000
.fam Verdana
.ft R

Figure 2: Steganography decoding, LSB algorithm (N=4)

.PDFPIC -C "pics/baboon.pdf" 1.5i 1.5i
.PDFPIC -C "pics/farm.pdf" 1.5i 1.5i

.ce
Figure 3: Cover and Secret Images (top to bottom)

.FS [1]
https://www.comptia.org/blog/what-is-steganography
.FE
.FS [2]
https://en.wikipedia.org/wiki/Nibble
.FE
.FS [3]
https://www.geeksforgeeks.org/swap-two-nibbles-byte/
.FE

.bp \" Page 5

.NH 2
LSB Steganography [flowchart(s)]

.PP
.fam JetBrains
.ft B
.ce
embedLSB(*coverPixels, *secretPixels, width, height)
.PDFPIC -C "diagrams/embedLSB.pdf" 3.5i 3.5i
.ce
extractLSB(*coverPixels, *secretPixels, width, height)
.PDFPIC -C "diagrams/extractLSB.pdf" 3.5i 3.5i
.fam Verdana
.ft R
.bp \" Page 6

.NH 2
LSB Steganography [testing]
.PP
The program successfully embeds and extracts 
.fam JetBrains
.B "farm.pgm" 
.fam Verdana
into and from 
.fam JetBrains
.B "baboon.pgm"
.fam Verdana
.PDFPIC -C "pics/stego_image_bin.pdf" 3.5i 3.5i
.ce
Figure 4: Stego Image in Binary
.PDFPIC -C "pics/extracted_secret.pdf" 3.5i 3.5i
.ce
Figure 5: Extracted Secret Image from Stego
.bp \" Page 7

.NH 1
Basic C++ Programming [
.fam JetBrains
cin, cout,
.fam Verdana
testing]

.PP
C++ is a programming language that evolved from C (hence ++), which became the industry standard in 1998. Some of its syntax is simpler compared to C. Other features exclusive to C++ include default function parameters, which are parameters that don't need to be provided with values.
.ce
.TS
allbox expand tab(|);
c s s 
c c c.
Table 1: C++ substitutes for C
Function | C | C++
Scanning Input | scanf() | cin >>
Printing Output | printf() | cout <<
.TE
.PP
.PDFPIC -C "pics/basic_C++.pdf" 4i 4i

The input values which are passed to "a" and "b" do change after update_scale is called since they are passed to the function by reference, meaning the parameters also change.

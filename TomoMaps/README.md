TomoMaps
---------------------------------------------------

Description
---------------------------------------------------
Program to visualize in 2D tomography on Google Maps
In this example, Eikonal Tomography is visualized.

Format of Input File
---------------------------------------------------
The program requires an text input file.
This file is any .tmo file (the same format used in other applications)
The tests have been done only with 2D tmo files

How to run
--------------------------------------------------
Use the script StationDist.sh to compile and run the program 
Example:

$ ./TomoMap.sh map.tmo 250

The script requires two parameters. 
1. The name of Input File (See Format of Input File)
2. Number of colors to plot.

Output Files
---------------------------------------------------
The program generates the following output files:
1. printing.dat -> A file that contains a matrix with the transformation of the .tmo file with
different colors to plot

3. An html file -> This file uses Google Maps to plot tomography. This file is generated internally
by code used the file plot.c

IMPORTANT: To visualize the tomography, after opening the html file, you should open 
printing.dat file by clicking on the button in the left up corner of the html file. It can take a
few seconds to plot.



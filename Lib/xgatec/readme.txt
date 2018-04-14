/*! \mainpage ANSI Library Reference
\verbatim
# XGATE library readme.txt

This is the readme file for the Freescale XGATE library.
The provided library project builds following library files:

Project Name                        CPU      Library       Compiler Options
--------------------------------------------------------------------------------------------------------------
       C   Ms IEEE32/32 ELF/Dwarf            ansi_xg.lib   -W2 -Os  -F2 -NoPath
       C   Ms no float  ELF/Dwarf            ansi_xgi.lib  -W2 -Os  -F2 -NoPath -D__NO_FLOAT__
 
Options used:
-W2:            Suppress warning and information messages
-Os:            Optimize for code size
-F2:            ELF/DWARF 2 object file format
-NoPath:        Do not write path information into object files
-D__NO_FLOAT__: define __NO_FLOAT__ macro (used to avoid floating point code in shared code like sprintf)
-^f:            avoid fatale error box. Instead just report the failure to the caller.
Notes:
  - the XGATE library contains the XGATE runtime support and also some libraries. 
  - not all of the ANSI C library functions are provided due to the nature of the XGATE coprocessor.
  - floating point is currently supported in the IEEE32 format.

Metrowerks
\endverbatim
*/

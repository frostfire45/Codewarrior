/*! \mainpage ANSI Library Reference
\verbatim
# library readme.txt

This is the readme file for the Freescale HC12/HCS12/HCS12X library.
The provided library project builds following library files:

Project Name                                       CPU      Library       Compiler Options
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
       C   Ms IEEE32/32                ELF/DWARF            ansis.lib     -W2 -Os -Ms                                               -F2 -NoPath
       C   Ml IEEE32/32                ELF/DWARF            ansil.lib     -W2 -Os -Ml                                               -F2 -NoPath
       C   Mb IEEE32/32                ELF/DWARF            ansib.lib     -W2 -Os -Mb                                               -F2 -NoPath
       C   Ms IEEE32/64                ELF/DWARF            ansisf.lib    -W2 -Os -Ms -Cc -Cf                                       -F2 -NoPath
       C   Ml IEEE32/64                ELF/DWARF            ansilf.lib    -W2 -Os -Ml -Cc -Cf                                       -F2 -NoPath
       C   Mb IEEE32/64                ELF/DWARF            ansibf.lib    -W2 -Os -Mb -Cc -Cf                                       -F2 -NoPath
       C   Ms no float                 ELF/DWARF            ansisi.lib    -W2 -Os -Ms -D__NO_FLOAT__                                -F2 -NoPath
       C   Ml no float                 ELF/DWARF            ansili.lib    -W2 -Os -Ml -D__NO_FLOAT__                                -F2 -NoPath
       C   Mb no float                 ELF/DWARF            ansibi.lib    -W2 -Os -Mb -D__NO_FLOAT__                                -F2 -NoPath
       C++ Ms IEEE32/32                ELF/DWARF            cpps.lib      -W2 -Os -Ms -Cc                                           -F2 -NoPath
       C++ Ml IEEE32/32                ELF/DWARF            cppl.lib      -W2 -Os -Ml -Cc                                           -F2 -NoPath
       C++ Mb IEEE32/32                ELF/DWARF            cppb.lib      -W2 -Os -Mb -Cc                                           -F2 -NoPath
       C++ Ms IEEE32/64                ELF/DWARF            cppsf.lib     -W2 -Os -Ms -Cc -Cf                                       -F2 -NoPath
       C++ Ml IEEE32/64                ELF/DWARF            cpplf.lib     -W2 -Os -Ml -Cc -Cf                                       -F2 -NoPath
       C++ Mb IEEE32/64                ELF/DWARF            cppbf.lib     -W2 -Os -Mb -Cc -Cf                                       -F2 -NoPath
       C++ Ms no float                 ELF/DWARF            cppsi.lib     -W2 -Os -Ms -Cc -D__NO_FLOAT__                            -F2 -NoPath
       C++ Ml no float                 ELF/DWARF            cppli.lib     -W2 -Os -Ml -Cc -D__NO_FLOAT__                            -F2 -NoPath
       C++ Mb no float                 ELF/DWARF            cppbi.lib     -W2 -Os -Mb -Cc -D__NO_FLOAT__                            -F2 -NoPath
HCS12X C   Ms IEEE32/32                ELF/DWARF   HCS12X   ansixs.lib    -W2 -Os -Ms                    -CpuHCS12X -CpDirect0xF000 -F2 -NoPath
HCS12X C   Ml IEEE32/32                ELF/DWARF   HCS12X   ansixl.lib    -W2 -Os -Ml                    -CpuHCS12X -CpDirect0xF000 -F2 -NoPath
HCS12X C   Mb IEEE32/32                ELF/DWARF   HCS12X   ansixb.lib    -W2 -Os -Mb                    -CpuHCS12X -CpDirect0xF000 -F2 -NoPath
HCS12X C   Ms IEEE32/64                ELF/DWARF   HCS12X   ansixsf.lib   -W2 -Os -Ms -Cc -Cf            -CpuHCS12X -CpDirect0xF000 -F2 -NoPath
HCS12X C   Ml IEEE32/64                ELF/DWARF   HCS12X   ansixlf.lib   -W2 -Os -Ml -Cc -Cf            -CpuHCS12X -CpDirect0xF000 -F2 -NoPath
HCS12X C   Mb IEEE32/64                ELF/DWARF   HCS12X   ansixbf.lib   -W2 -Os -Mb -Cc -Cf            -CpuHCS12X -CpDirect0xF000 -F2 -NoPath
HCS12X C   Ms no float                 ELF/DWARF   HCS12X   ansixsi.lib   -W2 -Os -Ms -D__NO_FLOAT__     -CpuHCS12X -CpDirect0xF000 -F2 -NoPath
HCS12X C   Ml no float                 ELF/DWARF   HCS12X   ansixli.lib   -W2 -Os -Ml -D__NO_FLOAT__     -CpuHCS12X -CpDirect0xF000 -F2 -NoPath
HCS12X C   Mb no float                 ELF/DWARF   HCS12X   ansixbi.lib   -W2 -Os -Mb -D__NO_FLOAT__     -CpuHCS12X -CpDirect0xF000 -F2 -NoPath
HCS12X C++ Ms IEEE32/32                ELF/DWARF   HCS12X   cppxs.lib     -W2 -Os -Ms -Cc                -CpuHCS12X -CpDirect0xF000 -F2 -NoPath
HCS12X C++ Ml IEEE32/32                ELF/DWARF   HCS12X   cppxl.lib     -W2 -Os -Ml -Cc                -CpuHCS12X -CpDirect0xF000 -F2 -NoPath
HCS12X C++ Mb IEEE32/32                ELF/DWARF   HCS12X   cppxb.lib     -W2 -Os -Mb -Cc                -CpuHCS12X -CpDirect0xF000 -F2 -NoPath
HCS12X C++ Ms IEEE32/64                ELF/DWARF   HCS12X   cppxsf.lib    -W2 -Os -Ms -Cc -Cf            -CpuHCS12X -CpDirect0xF000 -F2 -NoPath
HCS12X C++ Ml IEEE32/64                ELF/DWARF   HCS12X   cppxlf.lib    -W2 -Os -Ml -Cc -Cf            -CpuHCS12X -CpDirect0xF000 -F2 -NoPath
HCS12X C++ Mb IEEE32/64                ELF/DWARF   HCS12X   cppxbf.lib    -W2 -Os -Mb -Cc -Cf            -CpuHCS12X -CpDirect0xF000 -F2 -NoPath
HCS12X C++ Ms no float                 ELF/DWARF   HCS12X   cppxsi.lib    -W2 -Os -Ms -Cc -D__NO_FLOAT__ -CpuHCS12X -CpDirect0xF000 -F2 -NoPath
HCS12X C++ Ml no float                 ELF/DWARF   HCS12X   cppxli.lib    -W2 -Os -Ml -Cc -D__NO_FLOAT__ -CpuHCS12X -CpDirect0xF000 -F2 -NoPath
HCS12X C++ Mb no float                 ELF/DWARF   HCS12X   cppxbi.lib    -W2 -Os -Mb -Cc -D__NO_FLOAT__ -CpuHCS12X -CpDirect0xF000 -F2 -NoPath
HCS12X C   Ml IEEE32/32 non const near ELF/DWARF   HCS12X   ansixlnj.lib    -W2 -Os -Ml                    -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b -NonConstQualiNear
HCS12X C   Ml IEEE32/64 non const near ELF/DWARF   HCS12X   ansixlfnj.lib   -W2 -Os -Ml -Cc -Cf            -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b -NonConstQualiNear
HCS12X C   Ml no float  non const near ELF/DWARF   HCS12X   ansixlinj.lib   -W2 -Os -Ml -D__NO_FLOAT__     -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b -NonConstQualiNear
HCS12X C++ Ml IEEE32/32 non const near ELF/DWARF   HCS12X   cppxlnj.lib     -W2 -Os -Ml -Cc                -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b -NonConstQualiNear
HCS12X C++ Ml IEEE32/64 non const near ELF/DWARF   HCS12X   cppxlfnj.lib    -W2 -Os -Ml -Cc -Cf            -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b -NonConstQualiNear
HCS12X C++ Ml no float  non const near ELF/DWARF   HCS12X   cppxlinj.lib    -W2 -Os -Ml -Cc -D__NO_FLOAT__ -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b -NonConstQualiNear
HCS12X C   Ml IEEE32/32 const near     ELF/DWARF   HCS12X   ansixlcj.lib    -W2 -Os -Ml                    -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b -ConstQualiNear
HCS12X C   Ml IEEE32/64 const near     ELF/DWARF   HCS12X   ansixlfcj.lib   -W2 -Os -Ml -Cc -Cf            -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b -ConstQualiNear
HCS12X C   Ml no float  const near     ELF/DWARF   HCS12X   ansixlicj.lib   -W2 -Os -Ml -D__NO_FLOAT__     -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b -ConstQualiNear
HCS12X C++ Ml IEEE32/32 const near     ELF/DWARF   HCS12X   cppxlcj.lib     -W2 -Os -Ml -Cc                -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b -ConstQualiNear
HCS12X C++ Ml IEEE32/64 const near     ELF/DWARF   HCS12X   cppxlfcj.lib    -W2 -Os -Ml -Cc -Cf            -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b -ConstQualiNear
HCS12X C++ Ml no float  const near     ELF/DWARF   HCS12X   cppxlicj.lib    -W2 -Os -Ml -Cc -D__NO_FLOAT__ -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b -ConstQualiNear
HCS12X C   Ms IEEE32/32 no JSR-to-BSR  ELF/DWARF   HCS12X   ansixsj.lib   -W2 -Os -Ms                    -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b
HCS12X C   Ml IEEE32/32 no JSR-to-BSR  ELF/DWARF   HCS12X   ansixlj.lib   -W2 -Os -Ml                    -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b
HCS12X C   Mb IEEE32/32 no JSR-to-BSR  ELF/DWARF   HCS12X   ansixbj.lib   -W2 -Os -Mb                    -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b
HCS12X C   Ms IEEE32/64 no JSR-to-BSR  ELF/DWARF   HCS12X   ansixsfj.lib  -W2 -Os -Ms -Cc -Cf            -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b
HCS12X C   Ml IEEE32/64 no JSR-to-BSR  ELF/DWARF   HCS12X   ansixlfj.lib  -W2 -Os -Ml -Cc -Cf            -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b
HCS12X C   Mb IEEE32/64 no JSR-to-BSR  ELF/DWARF   HCS12X   ansixbfj.lib  -W2 -Os -Mb -Cc -Cf            -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b
HCS12X C   Ms no float  no JSR-to-BSR  ELF/DWARF   HCS12X   ansixsij.lib  -W2 -Os -Ms -D__NO_FLOAT__     -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b
HCS12X C   Ml no float  no JSR-to-BSR  ELF/DWARF   HCS12X   ansixlij.lib  -W2 -Os -Ml -D__NO_FLOAT__     -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b
HCS12X C   Mb no float  no JSR-to-BSR  ELF/DWARF   HCS12X   ansixbij.lib  -W2 -Os -Mb -D__NO_FLOAT__     -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b
HCS12X C++ Ms IEEE32/32 no JSR-to-BSR  ELF/DWARF   HCS12X   cppxsj.lib    -W2 -Os -Ms -Cc                -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b
HCS12X C++ Ml IEEE32/32 no JSR-to-BSR  ELF/DWARF   HCS12X   cppxlj.lib    -W2 -Os -Ml -Cc                -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b
HCS12X C++ Mb IEEE32/32 no JSR-to-BSR  ELF/DWARF   HCS12X   cppxbj.lib    -W2 -Os -Mb -Cc                -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b
HCS12X C++ Ms IEEE32/64 no JSR-to-BSR  ELF/DWARF   HCS12X   cppxsfj.lib   -W2 -Os -Ms -Cc -Cf            -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b
HCS12X C++ Ml IEEE32/64 no JSR-to-BSR  ELF/DWARF   HCS12X   cppxlfj.lib   -W2 -Os -Ml -Cc -Cf            -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b
HCS12X C++ Mb IEEE32/64 no JSR-to-BSR  ELF/DWARF   HCS12X   cppxbfj.lib   -W2 -Os -Mb -Cc -Cf            -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b
HCS12X C++ Ms no float  no JSR-to-BSR  ELF/DWARF   HCS12X   cppxsij.lib   -W2 -Os -Ms -Cc -D__NO_FLOAT__ -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b
HCS12X C++ Ml no float  no JSR-to-BSR  ELF/DWARF   HCS12X   cppxlij.lib   -W2 -Os -Ml -Cc -D__NO_FLOAT__ -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b
HCS12X C++ Mb no float  no JSR-to-BSR  ELF/DWARF   HCS12X   cppxbij.lib   -W2 -Os -Mb -Cc -D__NO_FLOAT__ -CpuHCS12X -CpDirect0xF000 -F2 -NoPath -Onb=b

Library Name Encoding:
The names of the library are constructed with the following parts:

["ansi"|"cpp"]["x"]["s"|"b"|"l"]["f"|"i"]["c"|"n"]["j"] ".lib"

["ansi"|"cpp"] : The ansi library contains all C functions like sprintf and also the runtime support implicitly used by the compiler. 
                 The cpp libraries only contain C++ specifics, and have to be linked in addition to the ANSI library.
["x"]          : The libraries exist in a HCS12X set, and in a HC12/HCS12 set. The HC12 and the HCS12 are using the same libraries.
["s"|"b"|"l"]  : The memory model. One of small, banked or large.
["f"|"i"]      : The floating point format. No character means IEEE32 for both floats and doubles, "f" is for IEEE64 doubles, "i" for integral only. 
                 The "i" library contain a sprintf which does not support %f, and they also do not contain the floating point runtime support.
["c"|"n"]      : The kind of data to be accessed as 'near' by default. Either constant data or non-constant data.
["j"]          : The branch optimization that changes JSR's into BSR's has been disabled for this library.


Options used:
-W2:                Suppress warning and information messages
-Os:                Optimize for code size
-Ms:                Small memory model
-Mb:                Banked memory model
-Ml:                Large memory model
-Cf:                Float IEEE32, double is IEEE64
-F2:                ELF/DWARF 2 object file format
-NoPath:            Do not write path information into object files
-CpuHCS12X:         Generate code for HCS12X
-D__NO_FLOAT__:     Define macro __NO_FLOAT__ and compile library without floating point specific code
-CpDirect0xF000:    HCS12X only: This option is used to avoid that the compiler is using direct addressing mode. 
                    There are no to the ANSI library known objects in the 0xF000..0xF0FF range, therefore the library built 
                    with this option is compatible with any runtime value of the DIRECT register. Building the library with the 
                    default -CpDirect0x0000 does generate ca 1% better code in the large memory model, but the code only works with a
                    DIRECT register content of 0
-ConstQualiNear:    HCS12X only: Use 'near' as the default qualifier for accessing constants
-NonConstQualiNear: HCS12X only: Use 'near' as the default qualifier for accessing non-constant data
-Onb=b:             Disable branch JSR-to-BSR optimization.
(for more details about these options, see the provided online documentation)

Notes:
  - The ANSI library contains all the runtime support which is derivative independent. Previous versions did also contain derivative
    specific code, which now has to be added separately.
    The derivative specific code is contained in:
      datapage.c: code used to access far data for the HC12 and HCS12.
      termio.c:   simple sci interface
  - Only HCS12X processors should use the HCS12X libraries. HCS12 and HC12's both are intended to use the same libraries with no x in their names.
  - HCS12X can use the HC12/HCS12 libraries. However, in general the HCS12X libraries are both smaller and faster.
    Especially far data accesses are significantly better with the HCS12X specific libraries.
  - For compatibility with previous releases, the library also contains builds one version of the startup code for each memory model.
    However recent projects are all setup to build the C source code of the startup code on their own.


Freescale
\endverbatim
*/
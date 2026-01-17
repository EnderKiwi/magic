/*******************************************************
*    colors.h       Magic lib           1/17/2026      *
*    A few macros to define the names of ANSI escape   *
* codes for terminal styling. Two aliases for each to  *
* make it a little easier to put to use.               *
*                                                      *
*    (c) 2026 Alex M. (EnderKiwi)                      *
*    Licensed under GNU AFFERO GENERAL PUBLIC LICENSE  *
*******************************************************/
#ifndef MAGIC_COLORS_H
#define MAGIC_COLORS_H

//   MAGIC_NONE and MAGIC_SKIP are both placeholders for blank spaces. Anything starting with '.' is skipped
#define MAGIC_NONE ".", ".",
#define MAGIC_SKIP MAGIC_NONE MAGIC_NONE MAGIC_NONE MAGIC_NONE MAGIC_NONE MAGIC_NONE MAGIC_NONE MAGIC_NONE MAGIC_NONE MAGIC_NONE

#define MAGIC_FONT(n) "f" #n , "font" #n ,

#define MAGIC_COLORS {\
"reset", "-", \
"bold", "strong", \
"dim", "faint", \
"italic", "it", \
"underline", "ul", \
"blink", "slowblink", \
"rapidblink", "fastblink", \
"invert", "reversevideo", \
"hide", "conceal", \
"strike", "crossout", \
MAGIC_FONT(0) \
MAGIC_FONT(1) \
MAGIC_FONT(2) \
MAGIC_FONT(3) \
MAGIC_FONT(4) \
MAGIC_FONT(5) \
MAGIC_FONT(6) \
MAGIC_FONT(7) \
MAGIC_FONT(8) \
MAGIC_FONT(9) \
"fraktur", "gothic", \
"doubleunderline", "2ul", \
"/bold", "/dim", \
"/italic", "noitalic", \
"/underline", "/ul", \
"/blink", "noblink", \
MAGIC_NONE \
"/reverse", "/inverse", \
"/hide", "/conceal", \
"/strike", "/crossout", \
"black", ".", \
"red", ".", \
"green", ".", \
"yellow", ".", \
"blue", ".", \
"magenta", "purple", \
"cyan", ".", \
"white", ".", \
MAGIC_NONE \
"default", ".", \
"blackbg", ".", \
"redbg", ".", \
"greenbg", ".", \
"yellowbg", ".", \
"bluebg", ".", \
"magentabg", "purplebg", \
"cyanbg", ".", \
"whitebg", ".", \
MAGIC_NONE \
"defaultbg", ".", \
MAGIC_NONE \
"framed", ".", \
"encircled", "circled", \
"overline", ".", \
"/framed", "/circled", \
"/overline", ".", \
MAGIC_NONE \
MAGIC_NONE \
MAGIC_NONE \
MAGIC_NONE MAGIC_SKIP MAGIC_SKIP MAGIC_SKIP /* skipping a bunch of unused numbers */ \
"brightblack", "gray", \
"brightred", "lightred", \
"brightgreen", "lightgreen", \
"brightyellow", "lightyellow", \
"brightblue", "lightblue", \
"brightmagenta", "pink", \
"brightcyan", "lightcyan", \
"brightwhite", ".", \
MAGIC_NONE \
MAGIC_NONE \
"brightblackbg", "graybg", \
"brightredbg", "lightredbg", \
"brightgreenbg", "lightgreenbg", \
"brightyellowbg", "lightyellowbg", \
"brightbluebg", "lightbluebg", \
"brightmagentabg", "pinkbg", \
"brightcyanbg", "lightcyanbg", \
"brightwhitebg", ".", \
"background", \
"", \
}

#endif

/*
 * Author: TRAN Quang Toan
 * Calculator console Big Number 
 * Version 1 - 
 * Date: 11 Jan 2017
*/

// StringProcess.h
#ifndef STRING_PROCESS_H
 
#define STRING_PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"


void input(_charT **, _charT **);

long Max(long, long);
//___________________________________________String Processing______________________

long strlength(_charT*);

void assignChar(_charT*, _charT); //Assign char c1 = c2

_charT* rm_nth(_charT*,long);

_charT* checkStringForm(_charT*);

_charT* Processing(_charT*, long);

void processString(_charT**,_charT**);

_charT* signString(_charT*);

_charT* processStringMulxNTEN(_charT*,long);

int charToINT(_charT);

_charT convertINTtoCHAR(int);


#endif

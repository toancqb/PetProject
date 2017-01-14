/*
 * Author: TRAN Quang Toan
 * Calculator console Big Number 
 * Version 1 - 
 * Date: 11 Jan 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StringProcess.h"
#include "Operator.h"
#include "define.h"
#include "FileInput.h"


void test_MulxONE(){  // func ok: strlength(), Processing, processString
	_charT *str1=NULL,*str,c;
	str1 = (_charT*)calloc(_SIZE_MAX,sizeof(_charT));
	fflush(stdin);
	scanf("%s",str1);
	fflush(stdin);
	scanf("%c",&c);
	str = MULTIPLICATION_MulxOne(str1,c);
	printf("%s ",str);
}

void test_MUL(){  // func ok: strlength(), Processing, processString, ADDITION, SUBTRACTION
	_charT *str1=NULL,*str2=NULL,*str;
	input(&str1,&str2);
	
	str = MULTIPLICATION(str1,str2);
	printf("%s ",str);
}

void test_ADD(){  // func ok: strlength(), Processing, processString, ADDITION, SUBTRACTION
	_charT *str1=NULL,*str2=NULL,*str;
	//input(&str1,&str2);
	ReadFile(&str1,&str2,"FileData.txt");
	
	str = ADDITION(str1,str2);
	printf("%s\n",str);
}

void test_SUB(){  // func ok: strlength(), Processing, processString, ADDITION, SUBTRACTION
	_charT *str1=NULL,*str2=NULL,*str;
	input(&str1,&str2);
//	str = signString(str1);
	str = SUBTRACTION(str1,str2);
	printf("%s\n",str);
}


void test_ReadFile(){  // func ok: strlength(), Processing, processString, ADDITION, SUBTRACTION
	_charT *str1=NULL,*str2=NULL;
	//input(&str1,&str2);
	ReadFile(&str1,&str2,"FileData.txt");
	
	printf("%s \n\n%s\n",str1,str2);
}

int main(int argc, _charT *argv[]) {
	
	test_ADD();
	
	return 0;
}

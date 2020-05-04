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

void ReadFile(_charT **str1, _charT **str2,_charT *path);

void test_MulxONE(){  // func ok: strlength(), Processing, processString
	_charT *str1=NULL,*str2=NULL,*str;

	ReadFile(&str1,&str2,"FileData.txt");
	str = MULTIPLICATION_MulxOne(str1,str2[0]);
	printf("%s ",str);
	free(str1);
	free(str2);
	free(str)
}

void test_MUL(){  // func ok: strlength(), Processing, processString, ADDITION, SUBTRACTION
	_charT *str1=NULL,*str2=NULL,*str;
	input(&str1,&str2);
	
	str = MULTIPLICATION(str1,str2);
	printf("%s ",str);
	free(str1);
	free(str2);
	free(str)
}

void test_ADD(){  // func ok: strlength(), Processing, processString, ADDITION, SUBTRACTION
	_charT *str1=NULL,*str2=NULL,*str;
	input(&str1,&str2);
	//ReadFile(&str1,&str2,"FileData.txt");
	
	str = ADDITION(str1,str2);
	printf("%s\n",str);
	free(str1);
	free(str2);
	free(str)
}

void test_SUB(){  // func ok: strlength(), Processing, processString, ADDITION, SUBTRACTION
	_charT *str1=NULL,*str2=NULL,*str;
	input(&str1,&str2);
//	str = signString(str1);
	str = SUBTRACTION(str1,str2);
	printf("%s\n",str);
	free(str1);
	free(str2);
	free(str)
}


void test_ReadFile(){  // func ok: strlength(), Processing, processString, ADDITION, SUBTRACTION
	_charT *str1=NULL,*str2=NULL;
	//input(&str1,&str2);
	ReadFile(&str1,&str2,"FileData.txt");
	
	printf("%s \n\n%s\n",str1,str2);
	free(str1);
	free(str2);
}

int main(int argc, _charT *argv[]) {
	
	//test_SUB();
	test_ADD();
	//test_MUL();
	
	return 0;
}

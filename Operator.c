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

/* run this program using the console pauser or add your own getch, system("pause") or input loop */




//______________________________________________________________________________________

_charT* ADDITION(_charT *str1,_charT *str2){
	long str1_length = strlength(str1),
	     str2_length = strlength(str2),
		 strMax_length = Max(str1_length,str2_length);
		//	strMax_length = (str1_length > str2_length)?str1_length:str2_length;
	_charT *str = (_charT*)calloc(strMax_length+1,sizeof(_charT));
//	printf("\n%d\n",str1_length);
	processString(&str1,&str2);
	long i,j;
	int k = 0,temp,check_f = 0; 
	assignChar(&str[0],' ');
	for(i=strMax_length-1,j=strMax_length;i>=0;i--,j--){
		if(charToINT(str1[i])!=-1 && charToINT(str2[i])!=-1){
		 temp = charToINT(str1[i]) + charToINT(str2[i]) + k;
		 if(temp >= 10){
			k = 1; temp-=10;
			if(i == 0){ assignChar(&str[0],'1'); check_f = 1;}
		 } else k = 0;
	 	assignChar(&str[j],convertINTtoCHAR(temp+48));
	 	}
	}

	if(!check_f) str = rm_nth(str,0);
	str = checkStringForm(str);
	return str;
}

_charT* SUBTRACTION(_charT *str1,_charT *str2){
	long str1_length = strlength(str1),
	     str2_length = strlength(str2),
		 strMax_length = Max(str1_length,str2_length);
	_charT *str = (_charT*)calloc(strMax_length,sizeof(_charT));
	
	_charT *str_temp;
	long long_temp;
	int sign = 1;
	//printf("%d	%d\n",str1_length,str2_length);
	if(str1_length < str2_length){
		str_temp = str1; str1 = str2; str2 = str_temp;
		long_temp = str1_length; str1_length = str2_length; str2_length = long_temp;
		sign = -1;
	}
	
	processString(&str1,&str2);
	long i;
	int k = 0,temp; // k = 1 || 0
	assignChar(&str[0],' ');
	for(i=strMax_length-1;i>=0;i--){
		if(charToINT(str1[i]) - k < charToINT(str2[i])){
			temp = charToINT(str1[i]) + 10 - k - charToINT(str2[i]);
			k = 1;
		} else {
			temp = charToINT(str1[i]) - charToINT(str2[i]);
			k = 0;
		}
		assignChar(&str[i],convertINTtoCHAR(temp+48));
	}
	str = checkStringForm(str);
	if(sign == -1) str = signString(str);
	return str;
}

_charT* MULTIPLICATION_MulxOne(_charT *str1,_charT c){
	long str1_length = strlength(str1);
	_charT *str = (_charT*)calloc(str1_length + 1,sizeof(_charT));
	long i,j;
	int k=0,temp,check_f = 0;
	assignChar(&str[0],' ');
	for(i = str1_length-1,j=str1_length;i>=0;i--,j--){
		if(charToINT(str1[i])!=-1 && charToINT(c)!=-1){
		  temp = charToINT(str1[i])*charToINT(c) + k;
			if(temp >= 10){
			k = temp/10;
			if(i == 0) {assignChar(&str[0],convertINTtoCHAR(temp/10+48)); check_f = 1;}
			temp%=10;
			} //else if(i == 0) assignChar(&str[0],'0');
			else k = 0;
			assignChar(&str[j],convertINTtoCHAR(temp+48));
		}
	}
	if(!check_f) str = rm_nth(str,0); 
	str = checkStringForm(str);
	return str;
}

_charT* MULTIPLICATION(_charT *str1,_charT *str2){
	long str1_length = strlength(str1),
	     str2_length = strlength(str2);
	
	//_charT *str = (_charT*)calloc(str1_length+str2_length,sizeof(_charT));
	_charT *str_cur; //= (_charT*)calloc(str1_length+1,sizeof(_charT));
	_charT *str_next;// = (_charT*)calloc(str1_length+1,sizeof(_charT));
	
	_charT *str_temp;
	long long_temp;
	//printf("%d	%d\n",str1_length,str2_length);
	if(str1_length < str2_length){
		str_temp = str1; str1 = str2; str2 = str_temp;
		long_temp = str1_length; str1_length = str2_length; str2_length = long_temp;
	}
	long i,k=1;
	str_cur = MULTIPLICATION_MulxOne(str1,str2[str2_length-1]);
	for(i = str2_length-2;i>=0;i--){
		printf("\n%s",str_cur);
		str_next = processStringMulxNTEN(MULTIPLICATION_MulxOne(str1,str2[i]),k++);
		printf("	%s\n",str_next);
		str_cur = ADDITION(str_cur,str_next);
		
	}
	free(str1); free(str2);
	return str_cur;
}


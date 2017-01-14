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
#include "define.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void input(_charT **str1, _charT **str2){
	if(*str1 == NULL && *str2 == NULL){
		*str1 = (_charT*)calloc(_SIZE_MAX,sizeof(_charT));
		*str2 = (_charT*)calloc(_SIZE_MAX,sizeof(_charT));
	}
	fflush(stdin);
		scanf("%s",*str1);
	fflush(stdin);	// Clear buffer for str2
		scanf("%s",*str2); 
	
}


long Max(long a, long b){
	return (a>b)?a:b;
}
//___________________________________________String Processing______________________

long strlength(_charT *str){
	if(str!=NULL){
		long len = 0;
		while(str[len]!='\0') len++;
		return len;
	} 
	else return -1;
}


void assignChar(_charT *c1, _charT c2)	//Assign char c1 = c2
{
	int d = (int)c2;
	*c1 = d;	
}

_charT* rm_nth(_charT *str1,long n){
	_charT *str = (_charT*)calloc(strlength(str1)-1,sizeof(_charT));
	long i;
	for(i=0;i<n;i++) assignChar(&str[i],str1[i]);
	for(i=n+1;i<strlength(str1);i++) assignChar(&str[i-1],str1[i]);
	free(str1);
	return str;
}

_charT* checkStringForm(_charT *str){
	long i=0;
	while(str[i]!='\0'){
		if((int)str[i] < 48 || (int)str[i] > 57 ) {str = rm_nth(str,i); continue;}
		i++; 
	}
	return str;
}

_charT* Processing(_charT *str1, long n){
	_charT *str = (_charT*)calloc(strlength(str1)+n,sizeof(_charT));
	long i;
	for(i=0;i<n;i++) assignChar(&str[i],'0');
	for(i=n;i<strlength(str1)+n;i++) assignChar(&str[i],str1[i-n]);
	free(str1);
	//str = checkStringForm(str);
	return str;
}

void processString(_charT **str1,_charT **str2){
	long str1_length = strlength(*str1),
	    str2_length = strlength(*str2);
	if(str1_length == str2_length) return;
	else if(str1_length > str2_length) *str2 = Processing(*str2,str1_length - str2_length);
	else *str1 = Processing(*str1,str2_length - str1_length);
}

_charT* processStringMulxNTEN(_charT *str1,long n){
	_charT *str = (_charT*)calloc(strlength(str1)+n,sizeof(_charT));
	long i;
	for(i=0;i<strlength(str1);i++)	assignChar(&str[i],str1[i]);
	for(i=0;i<n;i++)	assignChar(&str[strlength(str1)+i],'0');
	str = checkStringForm(str);
	return str;
}

_charT* signString(_charT* str1){
	_charT *str = (_charT*)calloc(strlength(str1)+1,sizeof(_charT));
	long i;
	for(i=0;i<strlength(str1);i++)	assignChar(&str[i+1],str1[i]);
	assignChar(&str[0],'-');
	return str;
}

int charToINT(_charT c){
	if((int)c >= 48 && (int)c <= 57) return (int)c - 48;
	else return -1;
}

_charT convertINTtoCHAR(int n){
	_charT c; c = n;
	return c;
}


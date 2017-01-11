/*
 * Author: TRAN Quang Toan
 * Calculator console Big Number 
 * Version 1 - 
 * Date: 11 Jan 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _SIZE_MAX 100
#define _charT char
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


int Max(long a, long b){
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


void assignChar(char *c1, char c2) //Assign char c1 = c2
{
	int d = (int)c2;
	*c1 = d;	
}
_charT* Processing(_charT *str1, long n){
	_charT *str = (_charT*)calloc(strlength(str1)+n,sizeof(_charT));
	long i;
	for(i=0;i<n;i++)	assignChar(&str[i],'0');
	for(i=n;i<strlength(str1)+n;i++) assignChar(&str[i],str1[i-n]);
	free(str1);
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

_charT* rm_nth(_charT *str1){
	_charT *str = (_charT*)calloc(strlength(str1)-1,sizeof(_charT));
	long i;
	for(i=1;i<strlength(str1);i++) assignChar(&str[i-1],str1[i]);
	free(str1);
	return str;
}

//______________________________________________________________________________________

_charT* ADDITION(_charT *str1,_charT *str2){
	long str1_length = strlength(str1),
	     str2_length = strlength(str2),
		 strMax_length = Max(str1_length,str2_length);
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

	if(!check_f) str = rm_nth(str);
	return str;
}

_charT* SUBTRACTION(_charT *str1,_charT *str2){
	long str1_length = strlength(str1),
	     str2_length = strlength(str2),
		 strMax_length = Max(str1_length,str2_length);
	_charT *str = (_charT*)calloc(strMax_length,sizeof(_charT));
	processString(&str1,&str2);
	long i,j;
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
	if(!check_f) str = rm_nth(str); 
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
	long i,j,k=1;
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


//void test_(){  // func ok: strlength(), Processing, processString
//	_charT *str1=NULL,*str,c;
//	str1 = (_charT*)calloc(_SIZE_MAX,sizeof(_charT));
//	fflush(stdin);
//	scanf("%s",str1);
//	fflush(stdin);
//	scanf("%c",&c);
//	str = MULTIPLICATION_MulxOne(str1,c);
//	printf("%s ",str);
//}

void test_(){  // func ok: strlength(), Processing, processString, ADDITION, SUBTRACTION
	_charT *str1=NULL,*str2=NULL,*str;
	input(&str1,&str2);
	
	str = MULTIPLICATION(str1,str2);
	printf("%s ",str);
}

//void test_(){  // func ok: strlength(), Processing, processString, ADDITION, SUBTRACTION
//	_charT *str1=NULL,*str2=NULL,*str;
//	input(&str1,&str2);
//	
//	str = ADDITION(str1,str2);
//	printf("%s ",str);
//}


int main(int argc, _charT *argv[]) {
	
	test_();
	
	return 0;
}

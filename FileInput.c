#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "define.h"
#include "FileInput.h"

void ReadFile(_charT **str1, _charT **str2,_charT *path){
	FILE *f = fopen(path,"r");
	if(*str1 == NULL && *str2 == NULL){
		*str1 = (_charT*)calloc(_SIZE_MAX,sizeof(_charT));
		*str2 = (_charT*)calloc(_SIZE_MAX,sizeof(_charT));
	}
	fscanf(f,"%s",*str1);
	fscanf(f,"%s",*str2);
}

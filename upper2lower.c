#include <stdio.h>  
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <locale.h>
#include <stdlib.h>

#ifndef false
#define false 0
#endif
#ifndef true
#define true 1
#endif

//wchar_t upper[]=L"ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ";
//wchar_t lower[]=L"йцукенгшщзхъфывапролджэячсмитьбю";
wchar_t upper[]=L"ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮQWERTYUIOPASDFGHJKLZXCVBNM";
wchar_t lower[]=L"йцукенгшщзхъфывапролджэячсмитьбюqwertyuiopasdfghjklzxcvbnm";

int main()  
{  
	wchar_t buf[BUFSIZ];
    wchar_t *pch;
    size_t count;
	int error=0;
	int find=0;
    setlocale(LC_ALL, "");
 //   setlocale(LC_NUMERIC,"C");
	while(fgetws(buf, BUFSIZ, stdin)!=NULL)
	{
		wchar_t *pch_in,*pch_up;
		int count;
		int index;
    	for(pch_in=buf, count = 0; count<wcslen(buf)-1; pch_in++, count++)
		{
			find=0;
			// ищем символ:
#ifdef DEBUG
			fwprintf(stderr,L"\nprocessing: %lc",*pch_in);
#endif
			for(pch_up=upper, index = 0; index<wcslen(upper); pch_up++, index++)
			{
				if(*pch_in==*pch_up)
				{
					fwprintf(stdout,L"%lc",lower[index]);
					find=1;
				}
			}
			if(!find)
				fwprintf(stdout,L"%lc",*pch_in);
		}
	//	fwprintf(stdout,L"\n");
	}
	return 0;
}

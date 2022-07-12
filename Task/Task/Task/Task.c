#define _CRT_SECURE_NO_WARNINGS
#define N 10
#define alf 26
#include <stdio.h>
#include <stdlib.h>

int dictionary(char, char[]);
int checkword(int[], int[]);

int main()
{
	char* dict[N];
	char* tmpdict[N] = {0};
	 char* text =malloc(N*N);
	 char let[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	 int values[alf + 1] = { 0 };
	 int tmp=0;
	 printf("Please, input your text:\n");
	 scanf("%s", text);
	 text += '\0';
	 printf("Please, input 10 words: \n ");
	 for (int i = 0; i < N; i++) {
		 dict[i] = malloc(15);
		 scanf("%s", dict[i]);
		 dict[i] += '\0';
		 tmpdict[i] = dict[i];
	 }
	printf("Text :\n %s\n", text);
	for (; *text != '\0'; text++) {
		tmp = dictionary(*text, let);
		values[tmp]++;
	}

	for (int i = 0; i < N; i++) {
		int wordvalues[alf + 1] = { 0 };
		for (; *dict[i] != '\0'; dict[i]++) {
			tmp = dictionary(*dict[i], let);
			wordvalues[tmp]++;
		}
		int tmpvalues[alf+1];
		for (int j = 0; j < alf; j++) {
			tmpvalues[j] = values[j];
		}
		int result = 0;
		while (checkword(tmpvalues, wordvalues) != 0) {
			result++;
		}
		printf("Word %s can be created %d times from letters of the text\n", tmpdict[i], result);
	}

	return 0;
}

int dictionary(char text, char let[]) {
	int tmp;
	for (int i = 0; i < alf; i++)
	{
		if (text == let[i]) {
			tmp = i;
			break;
		}
		else tmp =  alf;
	}
	return tmp;
}

int checkword(int textcount[], int wordcount[]) {
	int result = 0;
	
	for (int i = 0; i < alf - 1; i++)
	{
		textcount[i] = textcount[i] - wordcount[i];
		if (textcount[i] < 0) {
			return 0;
		}
	}
	result++;
	return result;

}
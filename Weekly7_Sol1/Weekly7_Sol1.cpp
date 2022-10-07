#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void fillbinary(char* ptr, char k)						//Problem 67, Solution 1, ID Student 65010902
{
	unsigned i;
	char strb[9] = "00000000";
	int j = 0;
	for (int i = 1 << 7; i > 0; i /= 2)
	{ 
		if (j <= 7) {
			(k & i) ? strb[j] = '1' : strb[j] = '0';
			j += 1;
		}
	}
	strcpy(ptr, strb);
}
int main()
{
	struct ascii {
		char ch;
		char binary[9];
	};
	ascii data[96];	//32 [space]   - 127  [DEL]   96
	ascii* ptr;
	ptr = data;
	char k = ' ';
	for (int i = 0; i <= 95; i++)
	{
		if (k <= 127)
		{
			data[i].ch = k;
			fillbinary(ptr->binary, k);
			ptr = ptr + 1;
		}
		k += 1;
	}
	ptr -= 96;
	char code[200];
	//printf("enter code here: ");
	//scanf("%s", code);
	strcpy(code, "010101000110100001100001011101000010011101110011001000000110001101101111011100100111001001100101011000110111010000101110");
	char store[] = "aaaaaaaa";
	char storecpy[] = "aaaaaaaa";
	int same;
	for (int i = 0; i < strlen(code); i += 8)
	{
		store[0] = code[i]; 
		store[1] = code[i + 1];
		store[2] = code[i + 2];
		store[3] = code[i + 3];
		store[4] = code[i + 4];
		store[5] = code[i + 5];
		store[6] = code[i + 6];
		store[7] = code[i + 7];

		
		for (int j = 0; j < 95; j += 1)			//COMPARE AND PRINT//check point
		{
			strcpy(storecpy, data[j].binary);
			same = strcmp(store, storecpy);
			if (same == 0) { printf("%c", ptr->ch); ptr -= j; same = 0; break; }
			ptr += 1;
		}
	}
	return 0;
}
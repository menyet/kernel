void clear()
{
	char *vidptr = (char*)0xb8000; 	//video mem begins here.
	unsigned int i = 0;
	//clear all
	while(i < 80 * 25) {
		//blank character
		vidptr[i * 2] = ' ';
		//attribute-byte: light grey on black screen	
		vidptr[i * 2 + 1] = 0x07; 		
		i++;
	}
}

void print(unsigned int line, unsigned int column, char *string)
{
	char *vidptr = (char*)0xb8000; 	//video mem begins here.

	unsigned int start = (80 * line + column);
	unsigned int i = start;

	//clear all
	while(i < 80 * 25 && string[i] != '\0') {
		//blank character
		vidptr[i * 2] = ' ';
		//attribute-byte: light grey on black screen	
		vidptr[i * 2 + 1] = 0x07; 		
		i++;
	}

	i = 0;

	while(string[i] != '\0') 
	{
		vidptr[(start + i) * 2] = string[i];
		vidptr[(start + i) * 2 + 1] = 0x07;
		i++;
	}	
}

void print_char(unsigned int line, unsigned int column, char chr)
{
	char *vidptr = (char*)0xb8000; 	//video mem begins here.

	unsigned int start = (80 * line + column);
	unsigned int i = start;

		vidptr[(start) * 2] = chr;
		vidptr[(start) * 2 + 1] = 0x07;
}


/*void print(char *string)
{
	char *vidptr = (char*)0xb8000; 	//video mem begins here.
	unsigned int i = 0;
	unsigned int j = 0;
	//clear all
	while(j < 80 * 25 * 2) {
		//blank character
		vidptr[j] = ' ';
		//attribute-byte: light grey on black screen	
		vidptr[j+1] = 0x07; 		
		j = j + 2;
	}
	j = 0;
	while(string[j] != '\0') {
		vidptr[i] = string[j];
		vidptr[i+1] = 0x07;
		++j;
		i = i + 2;
	}	
}*/

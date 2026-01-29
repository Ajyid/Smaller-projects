#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//This define and typdef are only used for the obfuscated function
#define _0x78(x) strtol(#x + 0x01, NULL, 0x10)
typedef __uint128_t __0x78;

void obfuscated()
{
	__0x78 _0x78 = ((__0x78) 0xFF48656C6C6F2C20 << 0x40) | 0x576F726C64210A0EULL;
	while(printf("%\x63", (unsigned)((_0x78 >> ((_0x78 & ((_0x78 >> (_0x78(_0x78))))) * (_0x78(_0x78) % 0x70))) & ((_0x78 >> (_0x78(_0x78)))))) && (_0x78-- & ((_0x78 >> (_0x78(_0x78))))));
}

//Starting the deobfuscating process this means:
//Replacing the typdef __0x78 with its real name __uint128_t
//Replacing the varibale _0x78 with the readbale name message
//Replacing the macro _0x78(_0x78) with its evaluated version 120
//Replacing hex numbers with their decimal value
//Expanding the keyword unsigned with its descirptive version unsigned char

void firstStep()
{
	__uint128_t message = ((__uint128_t) 0xFF48656C6C6F2C20 << 64) | 0x576F726C64210A0EULL;
	while(printf("%c", (unsigned char)((message >> ((message & ((message >> 120))) * (120 % 112))) & ((message >> 120)))) && (message-- & ((message >> 120))));
}

//Continuing the process by:
//Evaluating message >> 120 as its value 256 written as 0xFF to signal its bitmanipulation importance
//Deleting the most significant byte of the message as static evaluating made it clear that it was only used to obfuscate.
//This can be determined by checking that printing 0xFF via printf prints nothing
//Evaluating 120 % 112 as 8

void secondStep()
{
	__uint128_t message = ((__uint128_t) 0x48656C6C6F2C20 << 64) | 0x576F726C64210A0EULL;
	while(printf("%c", (unsigned char)((message >> ((message & 0xFF) * 8)) & 0xFF)) && (message-- & 0xFF));
}

//Now that all static obfuscating steps are reverted the next step would be to improve the readabilty:
//This means taking the print statement out of the loop condition
//Doing so necessitates to also remove the decrementing step out of the loop condition otherwise the first character could not be printed

void thirdStep()
{
	__uint128_t message = ((__uint128_t) 0x48656C6C6F2C20 << 64) | 0x576F726C64210A0EULL;

	while(message & 0xFF)
	{
		printf("%c", (unsigned char) ((message >> ((message & 0xFF) * 8)) & 0xFF));
		message--;
	}
}

//This third step finally reveals the magic of this short function: ((message >> ((message & 0xFF) * 8)) & 0xFF)
//Let's decrypt this step by step
//Firstly (message & 0xFF) gets evaluated. This gives the value of the least significant byte of the message.
//The this value is multiplied by 8 bitshift the message by a full byte
//Lastly the bitshifted variable's least significant byte is extracted with the final & 0xFF



//This analysis revals that the least significant byte is only used as an indexing tool. 
//Therefore extracting it is possible to make it even more explicit what is happening

void fourthStep()
{
	__uint128_t message = ((__uint128_t) 0x48656C6C6F2C << 64) | 0x20576F726C64210AULL;
	int index = 0x0D;

	while(index >= 0)
	{
		printf("%c", (unsigned char) ((message >> (index * 8)) & 0xFF));
		index--;
	}
}

//Since the message variable now only holds the message itself we can change its type to be an array of chars.
//Doing so simplifies the look up process

void fifthStep()
{
	char mes[14] = {'\x48', '\x65', '\x6C', '\x6C', '\x6F', '\x2C', '\x20', '\x57', '\x6F', '\x72', '\x6C', '\x64', '\x21', '\x0A'};
	int index = 0;

	while(index < 14)
	{
		printf("%c", mes[index]);
		index++;
	}
}

//To show that they all do the same:

int main()
{
	printf("Calling the original obfuscated version: ");
	obfuscated();
	printf("Calling first step: ");
	firstStep();
	printf("Calling second step: ");
	secondStep();
	printf("Calling third step: ");
	thirdStep();
	printf("Calling fourth step: ");
	fourthStep();
	printf("Calling fifth step: ");
	fifthStep();
}
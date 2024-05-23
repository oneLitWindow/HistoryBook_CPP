/*

	pccursor.cpp
	4-15-91
	Cursor shape class for IBM PC text modes.

	Copyright 1991
	John W. Small
	All rights reserved
	Use freely but acknowledge authorship and copyright.
	CIS: 73757,2233

	PSW / Power SoftWare
	P.O. Box 10072
	McLean, Virginia 22102 8072
	USA (703) 759-3838

*/

#include <pccursor.hpp>

void CursorShape::putshape(unsigned shape)
{ /* Don't make inline to avoid optimizer induced errors! */
	prevshape = getshape();
	_CX = shape;
	_AH = 0x01;
	geninterrupt(0x10);
}

/*
	Comment out "#define TEST_PCCURSOR_CPP" below to use
	pccursor.cpp in your application.
*/

#define TEST_PCCURSOR_CPP
#ifdef TEST_PCCURSOR_CPP

#include <conio.h>

CursorShape C;

main()
{
	cputs("Press any key to continue at pauses.\r\n");
	cputs("\r\nStarting cursor shape: ");
	getch();
	cputs("\r\nBlock cursor: ");
	C.block();
	getch();
	cputs("\r\nNormal cursor: ");
	C.normal();
	getch();
	cputs("\r\nInvisible cursor: ");
	C.off();
	getch();
	cputs("\r\nVisible cursor: ");
	C.on();
	getch();
	cputs("\r\nBlock cursor again to demo restore: ");
	C.block();
	getch();
	cputs("\r\nRestore cursor: ");
	C.restore();
	getch();
	cputs("\r\nBlock cursor again to demo destructor: ");
	C.block();
	getch();
	return 0;
}

#endif
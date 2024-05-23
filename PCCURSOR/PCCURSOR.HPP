/*

	pccursor.hpp
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

#ifndef PCCURSOR_CPP
#define PCCURSOR_CPP

#include <dos.h>

#define  CursorOffMask       0x2000
#define  CursorOnMask        0xDFFF
#define  BlockCursorMask     0x00FF
#define  DefaultColorCursor  0x0607
#define  DefaultMonoCursor   0x0C0D

class CursorShape {
	unsigned origshape, prevshape;
protected:
	unsigned  getshape() { _BH = 0x00; _AH = 0x03;
		geninterrupt(0x10); return _CX; }
	void putshape(unsigned shape);
	unsigned defaultshape() { _AH = 0x0F;
		geninterrupt(0x10); return (_AL == 7)?
		DefaultMonoCursor : DefaultColorCursor; }
public:
	CursorShape() { origshape = prevshape = getshape(); }
	void off() { putshape(getshape() | CursorOffMask); }
	void on()  { putshape(getshape() & CursorOnMask); }
	void block() { putshape(defaultshape() & BlockCursorMask); }
	void normal()  { putshape(defaultshape()); }
	void save()    { prevshape = getshape(); }
	void restore() { putshape(prevshape); }
	~CursorShape() { putshape(origshape); }
};

#endif

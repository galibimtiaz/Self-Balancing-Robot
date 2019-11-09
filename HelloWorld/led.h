//#define _setBit(var, mask)   ((var) |= (1 << mask))  // This are nice functions to let you control 1 pin; Makes High
//#define _clearBit(var, mask)   ((var) &= ~(1 << mask)) // This are nice functions to let you control 1 pin; Makes Low
#include "macros.h"

class LED
{
	int PIN;
	unsigned char PORT;
	public:
	LED(unsigned char,int);
	void on(void);
	void off(void);
};

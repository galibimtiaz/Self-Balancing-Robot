/*
* macros.h
*
* Created: 11/2/2019 8:30:31 AM
*  Author: Galib
*/


#ifndef MACROS_H_
#define MACROS_H_

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define CAT(x,y) x ## y
#define CONCAT(x,y) CAT(x,y)
#define QUOT(x) #x
#define QUOTE(x) QUOT(x)
#define _bit(b) (1 << (b))
#define test_bit(reg,b) ((reg & _bit(b))>>b)
#define max(a,b) (a>b) ? a : b
#define min(a,b) (a<b) ? a : b

#define __EXTENSION    7,6,5,4,3,2,1,0
#define __GET8(_0,_1,_2,_3,_4,_5,_6,_,N,...) N
#define __GET_SIZE(...) __GET8(__VA_ARGS__)
#define __VA_SIZE(...) __GET_SIZE(_,##__VA_ARGS__,__EXTENSION)
#define _BITS0(b1)
#define _BITS1(b1,...) _bit(b1)
#define _BITS2(b1,...) _bit(b1) | _BITS1(__VA_ARGS__)
#define _BITS3(b1,...) _bit(b1) | _BITS2(__VA_ARGS__)
#define _BITS4(b1,...) _bit(b1) | _BITS3(__VA_ARGS__)
#define _BITS5(b1,...) _bit(b1) | _BITS4(__VA_ARGS__)
#define _BITS6(b1,...) _bit(b1) | _BITS5(__VA_ARGS__)
#define _BITS7(b1,...) _bit(b1) | _BITS6(__VA_ARGS__)
#define _BITS(...)  CONCAT(_BITS,__VA_SIZE(__VA_ARGS__))(__VA_ARGS__)

#define _bits(...) _BITS(__VA_ARGS__)

#define set_bit(reg,b) (reg|=_bit(b))
#define clear_bit(reg,b) (reg&=~_bit(b))
#define set_bits(reg,bit,...) reg = reg | _bit(bit) _BITS(__VA_ARGS__)
#define clear_bits(reg,bit,...) reg = reg & ~(_bit(bit) _BITS(__VA_ARGS__))
#define test_bits(var,bits) ((var & (bits)) ? 1 : 0)

#define HBYTE(word) ((word)>>8)
#define LBYTE(word) ((BYTE)(word))


#define DDR(x) (*(&x - 1))      /* address of data direction register of port x */
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
/* on ATmega64/128 PINF is on port 0x00 and not 0x60 */
#define PIN(x) ( &PORTF==&(x) ? _SFR_IO8(0x00) : (*(&x - 2)) )
#else
#define PIN(x) (*(&x - 2))    /* address of input register of port x          */
#endif



#endif /* MACROS_H_ */
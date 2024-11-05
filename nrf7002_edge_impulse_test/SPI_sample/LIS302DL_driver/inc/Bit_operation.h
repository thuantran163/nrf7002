///* Peripheral_declaration*/
//#define CTRL_REG1  ((CTRL_REG1_TypeDef*) CTRL_REG1_BASE)
#ifndef __BIT_OPERATION__
#define __BIT_OPERATION__

#define M_BIT(n)                  ( 1<<(n) )
#define BTI_SHIF(a,n)			((a)<<(n))
#define BIT_SET(y, mask)        ( y |=  (mask) )
#define BIT_CLEAR(y, mask)      ( y &= ~(mask) )
#define BIT_FLIP(y, mask)       ( y ^=  (mask) )
#define BIT_EQ(y,flag) =  (((y)&(flag))==(flag))


//! Create a bitmask of length \a len.
#define M_BIT_MASK(len)           ( M_BIT(len)-1 )

//! Create a bitfield mask of length \a starting at bit \a start.
#define BF_MASK(start, len)     ( M_BIT_MASK(len)<<(start) )

//! Prepare a bitmask for insertion or combining.
#define _BF_PREP(x, start, len)  ( ((x)&M_BIT_MASK(len)) << (start) )

//! Extract a bitfield of length \a len starting at bit \a start from \a y.
#define _BF_GET(y, start, len)   ( ((y)>>(start)) & M_BIT_MASK(len) )

//! Insert a new bitfield value \a x into \a y.
#define _BF_SET(y, x, start, len)    \
    ( y= ((y) &~ BF_MASK(start, len)) | BF_PREP(x, start, len) )

//Prepare a named bit-field for for insterion or combination.
#define BFN_PREP(x, name) (((x)<<name##_Pos)&name##_Msk)

//Get the value of a named bitfield from y. Equivalent to (var=) y.name.
#define BFN_GET(y, name)   ( ((y) & name##_Msk)>>name##_Pos )

//Set a named bitfield in y to x. Equivalent to y.name= x.
#define 	BFN_SET(y, x, name)   (y = ((y)&~name##_Msk) | BFN_PREP(x,name) )

//Compare a named bitfield to named literal x.
#define 	BFN_CMP(y, x, name)   ( ((y)&name##_Msk) == (x) )

//Massage x for use in bitfield name with pre-shifted x.
#define 	BFN_PREP2(x, name)   ( (x) & name##_Msk )

//Get the value of bitfield name from y, but don't down-shift.
#define 	BFN_GET2(y, name)   ( (y) & name##_Msk )

//Set bitfield name from y to x with pre-shifted x.
#define 	BFN_SET2(y, x, name)   ( y = ((y)&~name##_Msk) | BFN_PREP2(x,name) )

#endif
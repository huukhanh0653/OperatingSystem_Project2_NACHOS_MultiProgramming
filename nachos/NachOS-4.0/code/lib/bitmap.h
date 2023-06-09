// bitmap.h
//	Data structures defining a bitmap -- an array of bits each of which
//	can be either on or off.
//
//	Represented as an array of unsigned integers, on which we do
//	modulo arithmetic to find the bit we are interested in.
//
//	The bitmap can be parameterized with with the number of bits being
//	managed.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#ifndef BITMAP_H
#define BITMAP_H

#include "copyright.h"
#include "utility.h"

// Definitions helpful for representing a bitmap as an array of integers
const int BitsInByte = 8;
const int BitsInWord = sizeof(unsigned int) * BitsInByte;

// The following class defines a "bitmap" -- an array of bits,
// each of which can be independently set, cleared, and tested.
//
// Most useful for managing the allocation of the elements of an array --
// for instance, disk sectors, or main memory pages.
// Each bit represents whether the corresponding sector or page is
// in use or free.

class Bitmap
{
public:
  Bitmap(int numItems); // Initialize a bitmap, with "numItems" bits
                        // initially, all bits are cleared.
  ~Bitmap(); // De-allocate bitmap
  //-> Set the "nth" bit
  void Mark(int which);

  //-> Clear the "nth" bit
  void Clear(int which);

  //-> Is the "nth" bit set? -> if return false -> isFree
  bool Test(int which) const; 

  //-> Return the order of a clear bit, and as a side
  int FindAndSet(); // effect, set the bit.
                   // If no bits are clear, return -1.


  //-> Count the number of clear bits
  int NumClear() const;
  //-> Print contents of bitmap
  void Print() const; 
  //-> Test whether bitmap is working
  void SelfTest();

protected:
  int numBits;  // number of bits in the bitmap
  int numWords; // number of words of bitmap storage
                // (rounded up if numBits is not a
                //  multiple of the number of bits in
                //  a word)
  unsigned int *map; // bit storage
};

#endif // BITMAP_H

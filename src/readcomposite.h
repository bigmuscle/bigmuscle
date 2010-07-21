#ifndef ReadComposite_h
#define ReadComposite_h

#include <vector>
#include "compositevect.h"

CompositeVect makeComposite();
int getMatrixPos(char a);
void printComposite(Composite FloatVect);
void printCompositeVect(CompositeVect VectFloatVect);
void makeDummyInput(CompositeVect VectFloatVect);
int getSequenceLength(Composite FloatVect);
float pairwiseScore(Composite* FloatVectA, Composite* FloatVectB, unsigned posA, unsigned posB, float VTML_SP[32][32]);
char matrixPosToChar(int pos);
char getDominantAA(float* position);
void makeBasicInput(CompositeVect VectFloatVect);

//void testfile();

#endif	//ReadComposite


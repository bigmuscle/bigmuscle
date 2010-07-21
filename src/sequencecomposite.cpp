#include "muscle.h"
#include "textfile.h"
//#include "msa.h"
#include "sequencecomposite.h"
#include "seq.h"

int calculateCompositeScore(std::vector<float *> s1, int s1position, std::vector<float*> s2, int s2position){

	float score=0.0f;
	//float s1array[23];
	//float s2array[23];
/*
	std::vector<float*>::iterator i=s1.begin()+s1position;
	for(int j=0; j<23; ++j){
		s1array[j] = *(s1[i]+j);
	}
*/
	
	float* farray = s1[s1position];
	for (int j = 0; j < 23; j++) {
		farray[j]++;
	}
/*
i=s2.begin()+s2position;
	for(int j=0; j<23; ++j){
		s2array[j] = *(s2[i]+j);
	}
	

	for(int k=0;i<23;i++){
		for(int j=0;j<23;j++){
			score += float(s1array[k]*s2array[j]*VTML_SP[k][j]);
		}
	}
	*/
	return (int)score;
}

/*
int main(){
	std::vector<float*> FloatVect;
	TextFile fileIn("CompositeInput.txt");
	TextFile fileOut("CompositeOutput.txt");
	FloatVect = MakeSequenceComposite(fileIn);
	
	return 0;
}
*/


std::vector<float*> MakeSequenceComposite(TextFile &File){
	
	std::vector<float*> floatVect;
	unsigned numSequences=0;
	unsigned longestSequence=0;
	unsigned aaArray[10000][23];
	for(int k=0; k<10000; k++){
		for(int l=0; l<23; l++){
			aaArray[10000][23] = 0;
		}
	}

	FILE *f = File.GetStdioFile();
	for (;;)
		{
		char *Label;
		unsigned uLength;
		char *SeqData = GetFastaSeq(f, &uLength, &Label);
		if (0 == SeqData)
			break;
		Seq *ptrSeq = new Seq();

		for (unsigned i = 0; i < uLength; ++i)
			{
				if(uLength > longestSequence){
					longestSequence = uLength;
				}
			char c = SeqData[i];
			ptrSeq->push_back(c);
			unsigned a=ptrSeq->GetLetter(c);
			aaArray[i][a]++;
		}
		//ptrSeq->SetName(Label);
		//push_back(ptrSeq);
		numSequences++;
		delete[] SeqData;
		delete[] Label;
	}
	for(unsigned i=0; i<longestSequence; i++){
		float* inputSeq;
		inputSeq = new float[23];
		for(int j=0; j<23; j++){
			inputSeq[i] = float(aaArray[i][j]/numSequences);
		}
		floatVect.push_back(inputSeq);
	}
	return floatVect;
}



/*
void SequenceComposite::printComposite(){

	for (vector<float*>::iterator i=floatVect.begin(); i!=floatVect.end(); ++i){
		for(int j=0; j<23; ++){
			cout << *(floatVect[i]+j) << endl;
		}
   }
	return;
}
*/
/* This doesn't work apparently
float[] getFloat(int position){
	vector<float*>::iterator i=floatVect.begin()+position;
	float composite[23];
	for(int j; j<23; ++j){
		composite[i] = *(floatVect[i]+j);
	}
	return composite;
}
*/
/*

   for (int i = 0; i < 20; ++i) {
       cout << *(blah[0]+i) << endl;
   }
   return 0;
}
*/

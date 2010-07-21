#include "readcomposite.h"
#include <stdio.h>
#include <iostream>
using namespace std;

//NOTE: PRESENTLY LEAVING A EOL AFTER THE LAST SEQUENCE ADDS
//AN ADDITIONAL, UNDESIRED SEQUENCE TO THE COMPOSITE



CompositeVect makeComposite(){

	Composite DummyFloatVect;
	CompositeVect VectFloatVect;
	
	FILE *compositeInput;
	compositeInput = fopen("compositeinput.txt","r");


	while(!feof(compositeInput)){
		float sequence[5000][21];
		for(int i=0; i<5000;i++){
			for(int j=0;j<21;j++){
				sequence[i][j] = 0;
			}
		}
		int longestSequence=0;
		int numSequences=0;
		int p=0;
		char input[100];
		char EOL = '\n';
		Composite *FloatVect = new Composite;
		while(!feof(compositeInput)){
			int i=0;
			unsigned nextchar;
			fgets(input,100,compositeInput);
			if(input[0] == '#'){break;}
			if(input[0] == '>'){
				numSequences++;
				//if(p > longestSequence){longestSequence = p;}
				p=0;
				fgets(input,100,compositeInput);
			}
			while(input[i] != EOL && input[i] != 0){
				nextchar = getMatrixPos(input[i]);
				sequence[p][nextchar]++;
				p++;
				i++;
			}
			if(p > longestSequence){longestSequence = p;}
		}
		for(int i=0; i<longestSequence; i++){	
			float* component;
			component = new float[21];
			for(int j = 0; j < 21; ++j) {
				component[j] = (float)sequence[i][j]/(float)numSequences;
			}
			FloatVect->push_back(component);
		}
		float* component;
		component = new float[21];
		for(int k=0; k<21; ++k){
			component[k] = 0.0f;
		}
		FloatVect ->push_back(component);

		VectFloatVect.push_back(FloatVect);
		//DummyFloatVect = *FloatVect;
	}
	
	fclose(compositeInput);
	//printComposite(DummyFloatVect);
	//printCompositeVect(VectFloatVect);
	
	return VectFloatVect;
}

void printComposite(Composite FloatVect){
	for (std::vector<float *>::iterator i=FloatVect.begin(),ie=FloatVect.end(); i!=ie; ++i){
		float* component = *i;
			for (int j = 0; j < 21; j++){
			cout << component[j] << " ";
		}
			printf("\n");
	}
}


void printCompositeVect(CompositeVect VectFloatVect){
	/*
	Composite* sequence = VectFloatVect[1];
	printComposite (*sequence);
	*/
	for (std::vector<Composite *>::iterator i=VectFloatVect.begin(),ie=VectFloatVect.end(); i!=ie; ++i){
		Composite* sequence = *i;
		printComposite(*sequence);
	}
}

char getDominantAA(float* position){
	float best=0.0f;
	int dominant=20;
	for(int i=0; i<21; i++){
		if(position[i] > best){
			best=position[i];
			dominant = i;
		}
	}
	char AA=matrixPosToChar(dominant);
	return AA;
}

void makeDummyInput(CompositeVect VectFloatVect){
	FILE *output;
	output = fopen("dummycompositeoutput.txt","w");
	int p=0;
	for (std::vector<Composite *>::iterator i=VectFloatVect.begin(),ie=VectFloatVect.end(); i!=ie; ++i){
		fprintf(output, ">%i\n",p);
		Composite* sequence = *i;
		int length = getSequenceLength(*sequence);
		for(int j=0;j<length-1;j++){
			fprintf(output, "M");
		}
		fprintf(output, "\n");
		p++;
	}
	fclose(output);
}

void makeBasicInput(CompositeVect VectFloatVect){
	FILE *output;
	output = fopen("compositeoutput.txt","w");
	int p=0;
	for (std::vector<Composite *>::iterator i=VectFloatVect.begin(),ie=VectFloatVect.end(); i!=ie; ++i){
		fprintf(output, ">%i\n",p);
		Composite* sequence = *i;
		int length = getSequenceLength(*sequence)-1;
		int counter=0;
		char AA = 'X';
		for (std::vector<float *>::iterator k=sequence->begin(),ke=sequence->end(); k!=ke; ++k){
			if(counter < length){
				float* component = *k;
				AA = getDominantAA(component);
				fprintf(output, "%c", AA);
				counter++;
			}
		}
		fprintf(output, "\n");
		p++;
	}
	fclose(output);
}

int getSequenceLength(Composite FloatVect){
	int length = FloatVect.size();
	return length;
}

//A    C    D    E    F    G    H    I    K    L    M    N    P    Q    R    S    T    V    W    Y  X
int getMatrixPos(char a){
	if(a == 'A'){return 0;}
	if(a == 'C'){return 1;}
	if(a == 'D'){return 2;}
	if(a == 'E'){return 3;}
	if(a == 'F'){return 4;}
	if(a == 'G'){return 5;}
	if(a == 'H'){return 6;}
	if(a == 'I'){return 7;}
	if(a == 'K'){return 8;}
	if(a == 'L'){return 9;}
	if(a == 'M'){return 10;}
	if(a == 'N'){return 11;}
	if(a == 'P'){return 12;}
	if(a == 'Q'){return 13;}
	if(a == 'R'){return 14;}
	if(a == 'S'){return 15;}
	if(a == 'T'){return 16;}
	if(a == 'V'){return 17;}
	if(a == 'W'){return 18;}
	if(a == 'Y'){return 19;}
	else{return 20;}
}

char matrixPosToChar(int pos){
	if(pos == 0){return 'A';}
	if(pos == 1){return 'C';}
	if(pos == 2){return 'D';}
	if(pos == 3){return 'E';}
	if(pos == 4){return 'F';}
	if(pos == 5){return 'G';}
	if(pos == 6){return 'H';}
	if(pos == 7){return 'I';}
	if(pos == 8){return 'K';}
	if(pos == 9){return 'L';}
	if(pos == 10){return 'M';}
	if(pos == 11){return 'N';}
	if(pos == 12){return 'P';}
	if(pos == 13){return 'Q';}
	if(pos == 14){return 'R';}
	if(pos == 15){return 'S';}
	if(pos == 16){return 'T';}
	if(pos == 17){return 'V';}
	if(pos == 18){return 'W';}
	if(pos == 19){return 'Y';}
	else{return 'X';}
}

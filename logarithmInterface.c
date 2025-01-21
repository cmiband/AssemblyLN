#include <stdio.h>

extern float _naturalLogarithm(float a, int b); 

float naturalLogarithm(float a, int b);

float input = 0.0;
char firstNumOfChoice[50];
char secondNumOfChoice[50];
int endIndex = -1;
int prec;
float result;
char choiceOfAction = 'A';
int integerResult = 0;
int dotIndex = 0;
int currentIntegerMultiplier = 1;
int currentNum;
int validNum;
int multiplied;
float currentDecimalPart;
float currentDecimalDivider;
float castedNum;
float castedIntegerResult;
int i;
int loadFirstNumberResult;
int loadSecondNumberResult;
int decimalCounter;

int isValidCharacter(int c) {
	return c>=48 && c<=57 ? 1 : 0;
}

int getTargetNumber() {
	firstNumOfChoice[0] = '\0';
	printf("Podaj liczbe zmiennoprzecinkowa do obliczenia logarytmu naturalnego(mniejsza niz 100000 i wieksza od 0)(do 6 miejsc po przecinku):  \n");
	scanf("%49s", &firstNumOfChoice);

	integerResult = 0;
	dotIndex = 0;
	for(i = 0; i<50; i++) {
		if(firstNumOfChoice[i] == '.') {
			dotIndex = i;
			break;
		}
	}
	if(dotIndex == 0) {
		return 0;
	}

	currentIntegerMultiplier = 1;
	for(i = dotIndex-1; i>=0; i--) {
		currentNum = firstNumOfChoice[i];

		if(!isValidCharacter(currentNum)) {
			return 0;
		}

		validNum = currentNum-48;
		multiplied = validNum*currentIntegerMultiplier;
		integerResult += multiplied;
		currentIntegerMultiplier *= 10;
	}
	if(integerResult >= 100000) {
		return 0;
	}

	currentDecimalPart = 0.0;
	currentDecimalDivider = 10.0;
	decimalCounter = 0;
	for(i = dotIndex+1; i<50; i++) {
		if(decimalCounter > 6) {
			return 0;
		}

		if(firstNumOfChoice[i]=='\0') {
			break;
		}

		currentNum = firstNumOfChoice[i];

		if(!isValidCharacter(currentNum)) {
			return 0;
		}

		validNum = currentNum - 48;
		castedNum = (float)validNum;
		castedNum = castedNum / currentDecimalDivider;
		currentDecimalPart += castedNum;
		currentDecimalDivider *= 10.0;
		decimalCounter++;
	}

	castedIntegerResult = (float)integerResult;
	castedIntegerResult += currentDecimalPart;

	input = castedIntegerResult;
	return 1;
}

int getSecondTargetNumber() {
	secondNumOfChoice[0] = '\0';
	printf("Podaj precyzje do wyniku(od 1 do 6):  \n");
	scanf("%49s", &secondNumOfChoice);

	endIndex = 0;
	integerResult = 0;
	for(i = 0; i<50; i++) {
		if(secondNumOfChoice[i] == '\0') {
			endIndex = i;
			break;
		}
	}

	if(endIndex == 0) {
		return 0;
	}

	currentIntegerMultiplier = 1;
	for(i = endIndex-1; i>=0; i--) {
		currentNum = secondNumOfChoice[i];

		if(!isValidCharacter(currentNum)) {
			return 0;
		}

		validNum = currentNum-48;
		multiplied = validNum*currentIntegerMultiplier;
		integerResult += multiplied;
		currentIntegerMultiplier *= 10;
	}

	if(integerResult < 1 || integerResult > 6) {
		return 0;
	}
	prec = integerResult;
	
	return 1;
}

int main()
{

	while(choiceOfAction == 'A') {
		loadFirstNumberResult = getTargetNumber();
		if(!loadFirstNumberResult) {
			printf("Niepoprawna liczba, podaj dane od nowa\n");
			continue;
		}
		if(input <= 0) {
			printf("Niepoprawna liczba, podaj dane od nowa\n");
			continue;
		}

		loadSecondNumberResult = getSecondTargetNumber();
		if(!loadSecondNumberResult) {
			printf("Niepoprawna liczba, podaj dane od nowa\n");
			continue;
		}

		result = naturalLogarithm(input, prec);

		printf("\nLogarytm naturalny z tej liczby to: ");
		printf("%.*f", prec, result);

		printf("\nWpisz A, aby powtorzyc\n");
		scanf(" %c", &choiceOfAction);
	}
	
	return 0;
}


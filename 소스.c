#include <stdio.h>
#include <stdlib.h>

//Return true(1) if num is a prime number.
//Return false(0) if num is not a prime number.
int prime(int num)
{
	for (int i = 2; i <= num / 2; i++) { 
		//i가 num - 1까지 검사해도 되지만, num / 2만큼만 검사해도 소수인지 측정 가능하다.
		//num / 2 + 1 부터는 num의 약수가 될 수 없기 때문이다.
		if (num % i == 0) {
			return 0; 
			//num이 1과 자기 자신 외에 다른 수로 나눠진다-> 소수 아니므로 0 반환
		}
	}

	return 1;
	//위 반복문을 통과하였다(1과 자기 자신 외에 안 나눠진다-> 소수이므로 1 반환
}

//양의 정수를 입력받는 함수
//만약 0과 음의 정수를 입력받으면 에러 메시지를 출력하고 다시 입력받음
int getMax()
{
	int max = 0; //입력받는 정수
	while (max <= 0) {
		printf("Input a positive integer: ");
		scanf_s("%d", &max);
		if (max <= 0) { // 입력받은 수가 양의 정수가 아니면 에러 메시지를 출력한다.
			printf("%d is not a positive integer\n", max);
		}
	}
	return max;
}

void printPrime(int* primeArr, int size)
{
	int lineControl = 0;
	for (int i = 0; i < size; i++) {
		printf("%d	", primeArr[i]);
		lineControl++;
		if (lineControl % 8 == 0) printf("\n");
	}
	printf("\n");
	printf("소수의 개수: %d\n", size);
}

void getPrimeArray(int* primeArray, int startNum, int maxNum)
{
	int primeOrder = 0; //소수의 개수 저장
	for (int i = startNum; i < maxNum; i++) {
		if (prime(i)) {
			primeArray[primeOrder] = i;
			primeOrder++;
		}
	}
	realloc(primeArray, sizeof(int) * primeOrder); //배열의 크기를 소수의 개수만큼 정확히 맞춤
}

void calculateAndPrintArray(int* primeArray, int size)
{
	int distanceArraySize = size - 1;
	int* distanceArray = (int*)calloc(distanceArraySize, sizeof(int)); //소수들간의 거리를 저장하는 배열
	int maxDistance = 0;

	for (int i = 0; i < distanceArraySize; i++) {
		distanceArray[i] = primeArray[i + 1] - primeArray[i];
		if (distanceArray[i] > maxDistance) {
			maxDistance = distanceArray[i];
		}
	}

	int sum = 0;
	for (int i = 0; i < distanceArraySize; i++) {
		sum += distanceArray[i];
	}
	double average = (double)sum / distanceArraySize;

	printf("거리의 총합: %d\n", sum);
	printf("소수들간 거리의 평균: %f\n", average);

	free(distanceArray);
}

int main(void)
{
	int max = getMax(); //max은 양의 정수이자, 2부터 max까지 소수 여부를 검사함
	int* primeArray = (int*)calloc(max, sizeof(int));
	getPrimeArray(primeArray, 2, max);
	int arraySize = _msize(primeArray)/sizeof(int);
	printPrime(primeArray, arraySize);
	calculateAndPrintArray(primeArray, arraySize);

	free(primeArray);

	return 0;
}
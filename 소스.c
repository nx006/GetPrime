#include <stdio.h>
#include <stdlib.h>

//Return true(1) if num is a prime number.
//Return false(0) if num is not a prime number.
int prime(int num)
{
	for (int i = 2; i <= num / 2; i++) { 
		//i�� num - 1���� �˻��ص� ������, num / 2��ŭ�� �˻��ص� �Ҽ����� ���� �����ϴ�.
		//num / 2 + 1 ���ʹ� num�� ����� �� �� ���� �����̴�.
		if (num % i == 0) {
			return 0; 
			//num�� 1�� �ڱ� �ڽ� �ܿ� �ٸ� ���� ��������-> �Ҽ� �ƴϹǷ� 0 ��ȯ
		}
	}

	return 1;
	//�� �ݺ����� ����Ͽ���(1�� �ڱ� �ڽ� �ܿ� �� ��������-> �Ҽ��̹Ƿ� 1 ��ȯ
}

//���� ������ �Է¹޴� �Լ�
//���� 0�� ���� ������ �Է¹����� ���� �޽����� ����ϰ� �ٽ� �Է¹���
int getMax()
{
	int max = 0; //�Է¹޴� ����
	while (max <= 0) {
		printf("Input a positive integer: ");
		scanf_s("%d", &max);
		if (max <= 0) { // �Է¹��� ���� ���� ������ �ƴϸ� ���� �޽����� ����Ѵ�.
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
	printf("�Ҽ��� ����: %d\n", size);
}

void getPrimeArray(int* primeArray, int startNum, int maxNum)
{
	int primeOrder = 0; //�Ҽ��� ���� ����
	for (int i = startNum; i < maxNum; i++) {
		if (prime(i)) {
			primeArray[primeOrder] = i;
			primeOrder++;
		}
	}
	realloc(primeArray, sizeof(int) * primeOrder); //�迭�� ũ�⸦ �Ҽ��� ������ŭ ��Ȯ�� ����
}

void calculateAndPrintArray(int* primeArray, int size)
{
	int distanceArraySize = size - 1;
	int* distanceArray = (int*)calloc(distanceArraySize, sizeof(int)); //�Ҽ��鰣�� �Ÿ��� �����ϴ� �迭
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

	printf("�Ÿ��� ����: %d\n", sum);
	printf("�Ҽ��鰣 �Ÿ��� ���: %f\n", average);

	free(distanceArray);
}

int main(void)
{
	int max = getMax(); //max�� ���� ��������, 2���� max���� �Ҽ� ���θ� �˻���
	int* primeArray = (int*)calloc(max, sizeof(int));
	getPrimeArray(primeArray, 2, max);
	int arraySize = _msize(primeArray)/sizeof(int);
	printPrime(primeArray, arraySize);
	calculateAndPrintArray(primeArray, arraySize);

	free(primeArray);

	return 0;
}
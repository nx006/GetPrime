#include <stdio.h>

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

void printPrime(int num)
{
	int startNum = 2; //������, �⺻�� 2(�Ҽ��� 2���� �����̹Ƿ�)
	int lineControl = 0;	
	//�Ҽ��� ��µ� ������ lineControl++�ؼ�, 
	//lineControl�� 8�� ����� �� ������ �ٹٲ�(����)�� �Ѵ�.

	printf("Prime numbers from %d to %d are as follows:\n", startNum, num);
	for (int i = startNum; i < num; i++) {
		if (prime(i)) { //i�� �Ҽ��̸� i���
			printf("%d	", i);
			lineControl++;
			if (lineControl % 8 == 0) printf("\n"); //8�� ����� �� ������ �ٹٲ�
		}
	}
}

int main(void)
{
	int max = getMax(); //max�� ���� ��������, 2���� max���� �Ҽ� ���θ� �˻���
	printPrime(max);

	return 0;
}
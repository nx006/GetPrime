#include <stdio.h>

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

void printPrime(int num)
{
	int startNum = 2; //시작점, 기본값 2(소수는 2부터 시작이므로)
	int lineControl = 0;	
	//소수가 출력될 때마다 lineControl++해서, 
	//lineControl이 8의 배수가 될 때마다 줄바꿈(개행)을 한다.

	printf("Prime numbers from %d to %d are as follows:\n", startNum, num);
	for (int i = startNum; i < num; i++) {
		if (prime(i)) { //i가 소수이면 i출력
			printf("%d	", i);
			lineControl++;
			if (lineControl % 8 == 0) printf("\n"); //8의 배수가 될 때마다 줄바꿈
		}
	}
}

int main(void)
{
	int max = getMax(); //max은 양의 정수이자, 2부터 max까지 소수 여부를 검사함
	printPrime(max);

	return 0;
}
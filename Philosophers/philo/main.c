#include "philo.h"

int main(int argc, char *argv)
{
	int			i;
	pthread_t	thread[5];

	// parse 해서 구조체 채워넣음
	// 일단 monitor를 하나 생성하고 initialize : 내부에서 argument를 parsing 함수 호출한다
	// philo, fork, mutex 등을 개수에 맞게 생성, initialize 할 것

	// main thread에서 반복문을 통해 philo thread를 생성한다.
	// 이 때 thread에 argument로는 t_philo의 주소값 변수를 넘겨줄 것.
	
	// 각 thread 내에서는 반복적으로 다음 과정을 진행
	// 1. 밥 먹기
	// 2. 잠 자기 -> 여러 번에 나눠서 잠자기 진행 (한 번에 큰 수만큼 잠들면 딜레이 커짐)
	// 3. 생각하기
	return (0);
}
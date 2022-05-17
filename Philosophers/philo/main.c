#include "philo.h"

void	free_monitor(t_monitor monitor)
{
	// philo 해제
	// m_fork destroy
	// fork 해제
	// m_print destroy
}

int main(int argc, char *argv)
{
	int			i;
	t_monitor	monitor;
	pthread_t	*thread;

	if (initialize_monitor(&monitor, argc, argv) < 0)
	{
		printf("fail in initialize_monitor");
		free_monitor(monitor);
		return (0);
	}
	// parse 해서 구조체 채워넣음
	// 일단 monitor를 하나 생성하고 initialize : 내부에서 argument를 parsing 함수 호출한다
	// philo, fork, mutex 등을 개수에 맞게 생성, initialize 할 것

	// 생성 전 시간 초기화 !
	// main thread에서 반복문을 통해 philo thread를 생성한다.
	// 이 때 thread에 argument로는 t_philo의 주소값 변수를 넘겨줄 것.

	// main thread는 monitoring logic을 수행하도록 한다.
	// die flag check
	// finish flag가 setting 되어 있다면 모두 종료

	// 각 philo thread 내에서는 반복적으로 다음 과정을 진행
	// 1. 밥 먹기
	// 2. 잠 자기 -> 여러 번에 나눠서 잠자기 진행 (한 번에 큰 수만큼 잠들면 딜레이 커짐)
	// 				+) 그리고 다른 철학자가 죽으면 10ms 이내로 죽었다는 것이 판단되고 프로그램이 종료되어야 하므로
	//					10ms 이내로 잠자는 로직이 돌아가야 한다고 생각함
	// 3. 생각하기

	return (0);
}
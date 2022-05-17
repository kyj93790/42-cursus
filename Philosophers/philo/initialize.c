#include "philo.h"



int	initialize_monitor(t_monitor *monitor, int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		printf("fail by number of argument");
		return (-1);
	}
	// argument가 모두 unsigned int 범위 숫자로 들어오는 지 계산
	// 음수도 안됨
	// argument check를 모두 한 뒤 저장

	monitor->finish_flag = 0;
	monitor->error_flag = 0;
	// philo 세팅
	// fork 생성 및 mutex 생성
	// print mutex 생성
}
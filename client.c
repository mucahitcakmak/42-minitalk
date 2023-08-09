#include <unistd.h>
#include <signal.h>

int	ft_atoi(char *str)
{
	int	i;
	int result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}

void sendBit(int pid, char c)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		i++;
	}
}

int main(int argc, char *argv[])
{
	int i;
	int pid;

	if (argc != 3)
	{
		write(1, "Hatalı argüman sayısı!\n", 28);
		return (1);
	}
	i = -1;
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(1, "Geçersiz PID!\n", 14);
		return (1);
	}		
	while (argv[2][++i])
		sendBit(pid, argv[2][i]);
	sendBit(pid, '\n');
	return (0);
}
#include <unistd.h>
#include <signal.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr(int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		nbr %= 10;
	}
	if (nbr < 9)
		ft_putchar(nbr + '0');
	
	return (0);
}

void handler(int signal)
{
	static int i = 0;
	static char c = 0;

	if (signal == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		ft_putchar(c);
		i = 0;
		c = 0;
	}
}

int main()
{
	int pid;
	struct sigaction sa;

	sa.sa_handler = handler; // sinyal geldiğinde uygulanacak fonksiyon

	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		write(1, "Sigaction Hatası!", 23);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		write(1, "Sigaction Hatası!", 23);

	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
	{
		pause();
	}
}

#include "../../shell.h"

void	handle_sigint(int sig)
{
	(void)sig;
	g_signal_received = SIGINT;
}

void	init_signal(void (*handler_for_sigint)(int),
		void (*handler_for_sigquit)(int))
{
	set_signal(SIGINT, handler_for_sigint, 0);
	set_signal(SIGQUIT, handler_for_sigquit, 0);
}

void	set_signal(int signum, void (*handler)(int), int flags)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = flags;
	sa.sa_handler = handler;
	sigaction(signum, &sa, NULL);
}

void	setup_signals(void)
{
	set_signal(SIGINT, handle_sigint, 0);
	set_signal(SIGQUIT, SIG_IGN, 0);
	set_signal(SIGTSTP, SIG_IGN, 0);
}

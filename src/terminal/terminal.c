
#include "../../shell.h"

void	reset_terminal_settings(const struct termios *old_termios)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, old_termios) < 0)
	{
		perror("tcsetattr");
		exit(EXIT_FAILURE);
	}
}

void	setup_terminal(struct termios *old_termios)
{
	if (!isatty(STDIN_FILENO))
	{
		perror("Standard input is not a terminal");
		exit(EXIT_FAILURE);
	}
	if (tcgetattr(STDIN_FILENO, old_termios) < 0)
	{
		perror("Failed to get terminal attributes");
		exit(EXIT_FAILURE);
	}
	if (tcsetattr(STDIN_FILENO, TCSANOW, old_termios) < 0)
	{
		perror("Failed to set terminal attributes");
		exit(EXIT_FAILURE);
	}
	if (tgetent(NULL, getenv("TERM")) < 0)
	{
		perror("Failed to initialize term cap");
		exit(EXIT_FAILURE);
	}
}

void	term_clear_screen(void)
{
	char	*clear_cmd;

	clear_cmd = tgetstr("cl", NULL);
	if (clear_cmd)
		tputs(clear_cmd, 1, putchar);
	else
		write(STDERR_FILENO, "Screen clear capability not supported.\n", 40);
}

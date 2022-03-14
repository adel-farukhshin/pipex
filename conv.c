#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


// int	create(int fd[2][2])
// {
// 	int	pid = fork();

// 	if (!pid)
// 	{
// 		dup2(fd[0][0], STDIN_FILENO);
// 		dup2(fd[1][1], STDOUT_FILENO);
		
// 		close(fd[0][0]);
// 		close(fd[0][1]);

// 		close(fd[1][0]);
// 		close(fd[1][1]);
// 	}
// 	return (pid);
// }

int	main()
{
	int	fd[2][2];
	int	pid0;
	int	pid1;
	// int	pid;

	// fd = malloc(sizeof(int *) * 3);
	// fd[0] = malloc(sizeof(int) * 2);
	// fd[1] = malloc(sizeof(int) * 2);
	// fd[2] = malloc(sizeof(int) * 2);
	if (pipe(fd[0]) == -1)
		return (-1);
	if (pipe(fd[1]) == -1)
		return (-1);

	pid0 = fork();
	if (pid0 == -1)
		return (-2);
	if (!pid0)
	{
		close(fd[1][1]);
		close(fd[1][0]);
		close(fd[0][0]);

		int	file = open("in", O_RDONLY);
		if (file == -1)
			return (-3);
		dup2(file, STDIN_FILENO);
		close(file);
		dup2(fd[0][1], STDOUT_FILENO);

	
		close(fd[0][1]);

	
		execlp("/bin/cat", "cat");
	}
	
	// pid = create(fd);

	int	pid = fork();

	if (!pid)
	{
		close(fd[1][0]);
		close(fd[0][1]);

		
		dup2(fd[0][0], STDIN_FILENO);
		dup2(fd[1][1], STDOUT_FILENO);
		
		close(fd[0][0]);
		close(fd[1][1]);
		
	}

	pid1 = fork();
	if (pid1 == -1)
		return (-4);
	if (!pid1)
	{
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][1]);
		
		
		
		unlink("out");

		int	file = open("out", O_WRONLY | O_CREAT, 0777);
		if (file == -1)
			return (-5);
		
		dup2(fd[1][0], STDIN_FILENO);
		
		// dup2(fd[0][0], STDIN_FILENO);
		dup2(file, STDOUT_FILENO);
		close(fd[1][0]);
		close(file);
		

		execl("/usr/bin/wc", "/usr/bin/wc");
	}

	close(fd[0][0]);
	close(fd[0][1]);

	close(fd[1][0]);
	close(fd[1][1]);
	waitpid(pid0, NULL, 0);
	waitpid(pid1, NULL, 0);
	waitpid(pid, NULL, 0);
	// free(fd);

	return (0);
}


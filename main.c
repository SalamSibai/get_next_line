
#include "get_next_line.h"

int main()
{
	int fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
}
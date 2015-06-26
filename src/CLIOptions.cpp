#include <stdlib.h>
#include <getopt.h>
#include "CLIOptions.hpp"

CLIOptions::CLIOptions(int argc, char *argv[])
{
	is_interactive_flag = false;
	while (true) {
		static struct option long_options[] = {
			{"interactive", no_argument, 0, 'i'},
			{0, 0, 0, 0}
		};
		int option_index = 0;
		int c =
		    getopt_long(argc, argv, "i", long_options, &option_index);
		if (c == -1)
			break;
		switch (c) {
		case 0:
			break;
		case 'i':
			is_interactive_flag = true;
			break;
		case '?':
			exit(127);
			break;
		default:
			abort();
		}
	}
}

bool CLIOptions::is_interactive()
{
	return is_interactive_flag;
}

#ifndef CLIOptions_hpp
#define CLIOptions_hpp

class CLIOptions {
 public:
	CLIOptions(int argc, char *argv[]);
	bool is_interactive();
 private:
	 bool is_interactive_flag;
};

#endif				// CLIOptions_hpp

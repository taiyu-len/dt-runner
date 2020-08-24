#include "dt_runner/dt_runner.hpp"
#include <algorithm>
#include <cstring>
#include <doctest/doctest.h>

namespace dt_runner {
test_results run_tests(int& argc, char **argv)
{
	doctest::Context context;
	context.setOption("dt-no-version", "true");
	context.applyCommandLine(argc, argv);

	auto result  = context.run();

	// failed test, or set to exit anyway.
	if (result || context.shouldExit()) {
		return { true, result };
	}

	// remove --dt-xxx arguments
	const auto is_doctest_arg = [](const char* s)
	{
		return strncmp(s, "--dt-", strlen("--dt-")) == 0;
	};
	char **last_arg = std::remove_if(argv, argv+argc, is_doctest_arg);
	*last_arg = nullptr;

	// update argument count
	argc = std::distance(argv, last_arg);

	return { false, 0 };
}
} // namespace dt


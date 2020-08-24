A simple project for using doctest.

Could be improved a lot someday™


To use.
```cmake
# link with cmake
target_link_libraries(your_project PRIVATE dt_runner)
```

```c++
// use in code
#include "dt_runner/dt_runner.hpp"
namespace dt = dt_runner;

int main(int argc, char **argv)
{
	// doctest configured to use --dt-*=* arguments.
	// filters out --dt- arguments, so argc, argv need to be mutable
	if (auto [should_quit, res] = dt::run_tests(argc, argv); should_quit)
	{
		return res;
	}
	return 0;
}
```


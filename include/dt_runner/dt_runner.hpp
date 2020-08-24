/*
 * should_quit = true IF any test fails, or context is set to quit.
 * value       = 0 IF no tests failed, ELSE non-zero if tests failed
 */
namespace dt_runner {
struct test_results {
	bool should_quit;
	int  value;
};
test_results run_tests(int& argc, char **argv);
} // namespace dt_runner



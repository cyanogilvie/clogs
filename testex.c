#include <stdio.h>
#include <time.h>
#include <threads.h>
#include <stdatomic.h>
#include "clogs.h"

#ifndef DBG_TEST
#define DBG_TEST 0
#endif

#undef CLOGS_DBG_PREFIX_FMT
#undef CLOGS_DBG_PREFIX_ARGS
#define CLOGS_DBG_PREFIX_FMT		"[%14.9f %7.3f %s %s:%-4d] "
#define CLOGS_DBG_PREFIX_ARGS		, proctime(), log_delta_usec(), clogs_thread_name(), __FILE__, __LINE__

int main(int argc, char** argv)
{
	CLOGS(TEST, "foo");
	CLOGS(TEST, "bar");
	CLOGS(TEST, "baz");
	CLOGS(TEST, ">>");

#undef CLOGS_DBG_PREFIX_FMT
#undef CLOGS_DBG_PREFIX_ARGS
#define CLOGS_DBG_PREFIX_FMT	"[%s:%d:%s] "
#define CLOGS_DBG_PREFIX_ARGS	, __FILE__, __LINE__, clogs_cstr(__func__, CLOGS_GREENISH)

	for (int i=0; i<argc; i++)
		CLOGS(TEST, "argv[%2d] = %s", i, clogs_cname(argv[i], CLOGS_PURPLEISH));

#include "clogs_reset_dbg_prefix.def"

	CLOGS(TEST, "<<");
	return 0;
}


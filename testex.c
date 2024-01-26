#include <stdio.h>
#include <time.h>
#include <threads.h>
#include <stdatomic.h>
#include "clogs.h"

#ifndef DBG_TEST
#define DBG_TEST 0
#endif

#undef CLOGS_DBG_PREFIX_FMT_DEFAULT
#undef CLOGS_DBG_PREFIX_ARGS_DEFAULT
#define CLOGS_DBG_PREFIX_FMT_DEFAULT		"[%14.9f %7.3f %s %s:%-4d] "
#define CLOGS_DBG_PREFIX_ARGS_DEFAULT		, clogs_proctime(), clogs_delta_usec(), clogs_thread_name(), __FILE__, __LINE__
#include "clogs_reset_dbg_prefix.def"

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
		CLOGS(TEST, "argv[%2d] = %s", i, clogs_name(argv[i], CLOGS_PURPLEISH));

#include "clogs_reset_dbg_prefix.def"

	CLOGS(TEST, "<<");
	return 0;
}


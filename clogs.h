#ifndef CLOGS_H
#define CLOGS_H

#include <stdint.h>

#ifndef CLOGS_FILE
#define CLOGS_FILE	stdout
#endif
#define CLOGS_DBG(msg, ...) fprintf(CLOGS_FILE, msg, ##__VA_ARGS__)
#define CLOGS_DBG_PREFIX_FMT_DEFAULT
#define CLOGS_DBG_PREFIX_ARGS_DEFAULT
#define CLOGS(cat, fmt, ...) do {if (DBG_##cat) {CLOGS_DBG(CLOGS_DBG_PREFIX_FMT fmt "\n" CLOGS_DBG_PREFIX_ARGS, ##__VA_ARGS__);}} while(0)
#include <clogs_reset_dbg_prefix.def>

#define CLOGS_GREENISH	.c=0x0020E020
#define CLOGS_PURPLEISH	.c=0x00E05070

struct clogs_name_args {
	const void*		thing;		// Some pointer. Each call for the same address will return the same name, and same colour variant of (r,g,b).
	uint32_t		c;			// Colour. r << 16 | g << 8 | b
};
const char* clogs_name(struct clogs_name_args args);
#define clogs_name(_t, ...) (clogs_name)((struct clogs_name_args){.c=0xFF000000, .thing=(_t), __VA_ARGS__})

struct clogs_cstr_args {
	const char*		str;		// Some string. Each call for the same string will return the same colour variant of (r,g,b).
	uint32_t		c;			// Colour. r << 16 | g << 8 | b
};
const char* clogs_cstr(struct clogs_cstr_args args);
#define clogs_cstr(_s, ...) (clogs_cstr)((struct clogs_cstr_args){.c=0xFF000000, .str=(_s), __VA_ARGS__})

struct clogs_thread_name_args {
	uint32_t		c;			// Colour. r << 16 | g << 8 | b
};
const char* clogs_thread_name(struct clogs_thread_name_args args);
#define clogs_thread_name(...) (clogs_thread_name)((struct clogs_thread_name_args){.c=0xFF000000, __VA_ARGS__})

enum clogs_lvl {
	CLOGS_LVL_DBG=0,
	CLOGS_LVL_INFO,
	CLOGS_LVL_WARN,
	CLOGS_LVL_ERR,
	CLOGS_LVL_FATAL,
};

struct clogs_args {
	FILE*			file;		// File to write to. Defaults to stdout
	const char*		fmt;		// Format string. If NULL, 
	enum clogs_lvl	lvl;		// Minimum level to log. Defaults to CLOGS_LVL_DBG
};
void clogs(struct clogs_args args);
#define clogs(defs, _args, ...) do {if (defs) {(clogs)((struct clogs_args){.file=stdout, _args}, __VA_ARGS__);}} while(0)

#endif

project('clogs', 'c',
  version:          '0.1',
  default_options:  ['c_std=c17', 'warning_level=2', 'werror=true'],
  meson_version:    '>=1.3.0',
)

cc = meson.get_compiler('c')

# Both strdup and clock_gettime(CLOCK_PROCESS_CPUTIME_ID) live behind the
# POSIX.1-2008 feature gate.
add_project_arguments('-D_POSIX_C_SOURCE=200809L', language: 'c')

# clogs's API uses C99 designated-initializer overrides as a deliberate
# idiom: clogs_name(_t, ...) expands to a struct literal where the default
# .c=0xFF000000 is followed by an optional caller-supplied .c=... that
# wins by C99 rules.  This is the entire point of the keyword-arg macros.
add_project_arguments(cc.get_supported_arguments([
  '-Wno-missing-field-initializers',
  '-Wno-override-init',
  '-Wno-missing-braces',
  '-Wno-unused-parameter',
]), language: 'c')

# C11 thread-locals, atomics, and threads.h require the platform threads
# library on glibc.
threads_dep = dependency('threads')

clogs_lib = library('clogs',
  'clogs.c',
  install:      not meson.is_subproject(),
  dependencies: threads_dep,
)

clogs_dep = declare_dependency(
  link_with:           clogs_lib,
  include_directories: include_directories('.'),
  dependencies:        threads_dep,
)

# Allow consumers to use plain dependency('clogs') after subproject()
# resolves us, instead of having to pull clogs_dep out of the subproject
# object explicitly.
meson.override_dependency('clogs', clogs_dep)

if not meson.is_subproject()
  install_headers('clogs.h', 'clogs_reset_dbg_prefix.def')

  pkg = import('pkgconfig')
  pkg.generate(clogs_lib,
    name:        'clogs',
    description: 'Tiny ANSI-coloured C logging helper',
    version:     meson.project_version(),
  )

  testex = executable('testex',
    'testex.c',
    dependencies: clogs_dep,
    c_args:       ['-DDBG_TEST=1'],
  )

  test('testex', testex,
    args: [
      'a', 'b', 'c', 'd', 'e', 'f', 'j', 'k', 'l', 'm', 'n',
      'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    ],
  )
endif

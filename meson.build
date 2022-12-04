project('sample_cpp_project', 'cpp',
    version : '1.0',
    license : [ 'proprietary'],
    meson_version : '>= 0.50.0',
    default_options : [ 'warning_level=3', 'buildtype=debugoptimized', 'cpp_std=c++11' ]
)

# Variables tracking sources and libraries
library_path = []
project_sources = []
project_header_files = []
project_test_sources = []

inc = [include_directories('include')]

subdir('include')
# This is where you should add in include directories

# This triggers the builds of sources
subdir('src')
# This links all the static libs into the main source file to form a binary

sample_cpp_project_bin_deps = []

sample_cpp_project_bin_dep_libs = [
  foo_lib,
  bar_lib,
]

sample_cpp_project_bin = executable('sample_cpp_project_bin', 
  main_source, 
  include_directories : inc, 
  dependencies : sample_cpp_project_bin_deps,
  link_with : sample_cpp_project_bin_dep_libs)

gtest = subproject('gtest')

if get_option('enable-tests')
  subdir('tests')
endif

subdir('docs')

# This adds the clang format file to the build directory
configure_file(input : '.clang-format',
               output : '.clang-format',
	       copy: true)
run_target('format',
  command : ['clang-format','-i','-style=file',project_sources,project_test_sources,project_header_files])

# This regex excludes any sources from the  tests 
# and gtest related files.
regex = '^((?!(tests|gtest)).)*$'
# This adds clang tidy support
configure_file(input : '.clang-tidy',
               output : '.clang-tidy',
               copy : true)
run_target('tidy',
  command : ['run-clang-tidy','-fix', '-j' , '8', 'files', regex ,'-format', '-p='+ meson.build_root()])


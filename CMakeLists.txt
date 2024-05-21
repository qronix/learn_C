cmake_minimum_required(VERSION 3.27)
project(Learn_C C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(Learn_C hello_world.c
        tutorials.h
        variables.c
        arrays.c
        multidim_arrays.c
        conditionals.c
        strings.c
        functions.c
        static.c
        pointers.c
        structures.c
        func_args.c
        dynamic_alloc.c
        arrays_and_pointers.c
        recursion.c
        linked_lists.c
        tests/linked_lists_test.c
        linked_lists.h
        bubble_sort.c
        array.h
        binary_search.c
        boolean.h
        queue.c
        stack.c
        two_crystal_balls.c
        two_crystal_balls.c
        arrayList.c
        file_IO.c
        typedef.c
        pointers_two.c
        manual_memory.c
)

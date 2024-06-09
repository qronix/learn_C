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
        chap_12_memory/manual_memory.c
        chap_12_memory/memory_reallocation.c
        chap_12_memory/reading_lines_of_arbitrary_length.c
        chap_15_conversions/string_conversions.c
        chap_16_qualifiers_and_specifiers/quals_and_specs.c
        chap_16_qualifiers_and_specifiers/restrict.c
        chap_16_qualifiers_and_specifiers/static.c
        chap_18_outside_env/exit_statuses.c
        chap_18_outside_env/env_vars.c
        chap_18_outside_env/env_vars_list.c
        chap_19_preprocessor/built_in_macros.c
        chap_19_preprocessor/macros_with_arguments.c
        chap_19_preprocessor/variadic_macros.c
        chap_19_preprocessor/assert_macro.c
        chap_20_structs_part_two/nested_structs.c
        chap_20_structs_part_two/anonymous_structs.c
        chap_20_structs_part_two/self_ref_structs.c
        chap_20_structs_part_two/flexible_array_members.c
        chap_20_structs_part_two/fake_oop.c
        chap_20_structs_part_two/bit_fields.c
        chap_20_structs_part_two/unions.c
        chap_21_characters_and_strings_II/escape_sequences.c
        chap_23_advanced_pointers/advanced_pointers.c
        chap_23_advanced_pointers/multi_byte_values.c
        chap_23_advanced_pointers/function_pointers.c
)

target_link_libraries(Learn_C m)

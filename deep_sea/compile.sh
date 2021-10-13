gcc stack_alloc.c -lm
valgrind --tool=memcheck ./a.out 50

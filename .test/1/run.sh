gcc -g main.c ../../get_next_line.c -I ../../libft/ -L ../../libft -lft
valgrind ./a.out ../files/lorem_ipsum.txt ../files/lorem_ipsum_jap.txt ../files/test.7

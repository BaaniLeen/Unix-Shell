all : extCmd shell

shell:  shell.c
	gcc shell.c -o shell

extCmd: ls mkdir rm cat date

ls : my_ls.c
	gcc my_ls.c -o ls
mkdir : my_mkdir.c
	gcc my_mkdir.c -o mkdir
rm : my_rm.c
	gcc my_rm.c -o rm
cat : my_cat.c
	gcc my_cat.c -o cat
date : my_date.c
	gcc my_date.c -o date

clean :
	rm -f ls mkdir rm cat date shell

TARGET=main
LINKFILE+= main.o
LINKFILE+= say_goodbey.o
LINKFILE+= say_hello.o
${TARGET}:${LINKFILE}
	gcc $^ -o $@
	echo "*****$^   ***** $@"
	echo "*************excute TARGET ***************"
	./${TARGET}
	echo "*************excute TARGET ***************"
clean:
	rm -rf *.o
	rm -rf main
	rm -rf a.out


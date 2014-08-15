include ../Makefile.define

PROGS = daytimetcpcli daytimetcpsev

all:	${PROGS}

daytimetcpcli: daytimetcpcli.o
		${CC} ${CFLAGS} -o $@ daytimetcpcli.o ${LIBS}

daytimetcpsev: daytimetcpsev.o
		${CC} ${CFLAGS} -o $@ daytimetcpsev.o ${LIBS}

.PHONY:clean

clean:
		rm -f ${PROGS} ${CLEANFILES}

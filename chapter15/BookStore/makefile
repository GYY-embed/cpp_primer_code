CC = g++

SRCS = quote.cpp \
		quoteMain.cpp \

OBJS = $(SRCS: .cpp = .o)

EXEC1 = quoteMain

start : $(OBJS)
	$(CC) -o $(EXEC1) $(OBJS)

#.cpp.o :
#	$(CC) -o $@ -c $< -DMYLINUX

clean :
	rm -rf $(OBJS)
CC = g++

SRCS = StrVecMain.cpp \
		StrVec.cpp \

OBJS = $(SRCS: .cpp = .o)

EXEC1 = StrVecMain

start : $(OBJS)
	$(CC) -o $(EXEC1) $(OBJS)

#.cpp.o :
#	$(CC) -o $@ -c $< -DMYLINUX

clean :
	rm -rf $(OBJS)
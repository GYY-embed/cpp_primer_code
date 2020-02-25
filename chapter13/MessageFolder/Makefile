CC = g++

SRCS = String.cpp \
		StrFolder.cpp \
		StrFolderMain.cpp

OBJS = $(SRCS: .cpp = .o)

EXEC1 = StrFolderMain

start : $(OBJS)
	$(CC) -o $(EXEC1) $(OBJS)

.cpp.o :
	$(CC) -o $@ -c $< -DMYLINUX

clean :
	rm -rf $(OBJS)
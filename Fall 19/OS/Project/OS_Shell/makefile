#Lucas Fulmer

#for use with c++ files
.SUFFIXES : .cpp

#Compile with g++
CC = g++

#use -g for gnu debugger and -std= for c++11 compiling
CXXFLAGS = -g -std=c++11

####Change this to match all .cpp files. Do not include .h files####
OBJS = LucasFulmerLab2.o

####Change to whatever you want your target name to be####
TARGET = Lucas_Fulmer_Lab2

####Do not change anything below this####
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

.cpp.o:
	$(CC) -c $(CXXFLAGS) $(INCDIR) $<

#In order to get rid of all .o files created, at the cmd prompt
#make clean

clean:
	rm -f $(OBJS) $(TARGET) core

# A makefile for the Triton Tag project


CC=g++
CXXFLAGS=-std=c++11 -g -Wall
LDFLAGS=-g

all: Student.o SkipList.o TritonTag

TritonTag: TritonTag.cpp SkipList.o Student.o

test: test.cpp SkipList.o Student.o

SkipList.o: SkipList.cpp SkipList.h Student.h

Student.o: Student.cpp Student.h

clean:
	rm -f test TritonTag *.o

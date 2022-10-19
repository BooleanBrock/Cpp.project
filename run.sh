#!/bin/bash
 rm *.o ./a.out
 g++ -c student.cpp
 g++ -c roster.cpp
 g++ -c main.cpp
 g++ main.o roster.o student.o 
 ./a.out
#!/bin/bash

g++ main.cpp -o executable.out
g++ main.cpp -lvlc -o executable.out

./executable.out

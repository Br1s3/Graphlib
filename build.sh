#!/bin/bash

set -xe

cc main.c graph.c -o main -g3 -Wextra -Wall

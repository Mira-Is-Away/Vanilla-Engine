#!/bin/bash

set -e 

valgrind --leak-check=full --show-leak-kinds=all ./bin/vanilla
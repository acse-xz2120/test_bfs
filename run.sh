#!/bin/bash
chmod 777 bfs
export PATH=/opt/gcc-10.2.0/bin:$PATH
export LD_LIBRARY_PATH=/opt/gcc-10.2.0/lib64:$LD_LIBRARY_PATH
./bfs $1

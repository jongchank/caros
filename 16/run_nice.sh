#!/bin/sh
nice -n -20 ./good 100000000&
nice -n -20 ./good 100000000&
nice -n -20 ./good 100000000&
nice -n -20 ./good 100000000&
nice -n -20 ./good 100000000&
nice -n 19 ./bad 100000000&
nice -n 19 ./bad 100000000&
nice -n 19 ./bad 100000000&
nice -n 19 ./bad 100000000&
nice -n 19 ./bad 100000000&

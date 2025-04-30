#!/bin/bash

# Declare a string and an integer variable
name="Alice"
age=20

# If-else statement based on the value of the integer
if [ "$age" -ge 18 ]; then
    echo "$name is an adult."
else
    echo "$name is a minor."
fi

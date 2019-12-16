#!/bin/bash

# If the exit code of the immediately previous line is nonzero, print ❌ 
function print_status() {
  if [ ! $? == 0 ]; then
    echo "❌"
  else
    echo "✅"
  fi
}
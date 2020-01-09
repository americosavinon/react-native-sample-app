#!/bin/bash

source ./"$(dirname "$0")"/print-status.sh

echo '========================================================='
echo 'postinstall script scan'
echo '========================================================='

FILE=./node_modules/react-native-amwellservice/scripts/module_postinstall.js
if test -f "$FILE"; then
    echo "$FILE exist"
    echo -n "Post install amwellservice..."
    node node_modules/react-native-amwellservice/scripts/module_postinstall.js
    print_status
fi
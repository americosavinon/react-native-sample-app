#!/bin/bash

source ./"$(dirname "$0")"/print-status.sh

# TODO: we need to detect if the module we installed match to this
echo -n "Post install amwellservice..."
node node_modules/react-native-amwellservice/scripts/module_postinstall.js
print_status

# echo -n "Post install module1..."
# node node_modules/react-native-module1/scripts/module_postinstall.js
# print_status
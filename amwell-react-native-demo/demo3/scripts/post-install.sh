#!/bin/bash

source ./"$(dirname "$0")"/print-status.sh

echo '========================================================='
echo 'postinstall script for module' @ $npm_config_component
echo '========================================================='

if [ "$npm_config_component" = "react-native-amwellservice" ] 
then
    echo -n "Post install amwellservice..."
    node node_modules/react-native-amwellservice/scripts/module_postinstall.js
    print_status
fi

if [ "$npm_config_component" = "react-native-module1" ] 
then
    echo -n "Post install module1..."
    node node_modules/react-native-module1/scripts/module_postinstall.js
    print_status
fi
#!/bin/bash

source ./"$(dirname "$0")"/print-status.sh

module_name=$(echo $@ | cut -d'/' -f 2)

# # check if the module_name is > 0
if [ $(echo "$module_name" | wc -c) -eq 0 ] 
then
    echo ❌ - Wrong package name.
    exit 1
fi

echo start to add package name \""$module_name"\"
npm_config_component=$module_name yarn add $@
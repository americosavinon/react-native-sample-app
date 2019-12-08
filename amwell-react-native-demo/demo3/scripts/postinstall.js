#!/usr/bin/env node

console.log('postinstall...');

// Print out the name of the package that was just installed.
console.log('    ' + process.env.npm_package_name);

// Print out the directory of the package that was just installed.
console.log('    ' + process.env.PWD);

// run some clean up script here to avoid issue about

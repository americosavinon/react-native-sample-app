#!/usr/bin/env node

'use strict';

const fs = require('fs');
const path = require('path');

// Main start sweeping process
(() => {
  // Read out dir of example project
  const exampleDir = process.cwd();

  console.log(`Starting postinstall cleanup for ${exampleDir}`);

  console.log(process.env.npm_package_name);
  console.log(process.argv);
})();

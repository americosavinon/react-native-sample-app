module.exports = {
  parser: '@typescript-eslint/parser', // Specifies the ESLint parser
  extends: ['plugin:@typescript-eslint/recommended', '@rally'],
  rules: {
    '@typescript-eslint/no-use-before-define': ['error', { functions: false, classes: false }]
  }
};

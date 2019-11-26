module.exports = {
  parser: '@typescript-eslint/parser', // Specifies the ESLint parser
  extends: ['@rally', '@react-native-community'], // @react-native-community, we can optional add community eslint rule
  rules: {
    '@typescript-eslint/no-use-before-define': ['error', { variables: false, functions: true, classes: true }]
  }
};

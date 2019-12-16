source ./"$(dirname "$0")"/print-status.sh

echo -n "Clearing watchman watches..."
watchman watch-del-all &> /dev/null
print_status

echo -n "Cleaning ios build..."
rm -rf ../ios/build &> /dev/null
print_status

echo -n "Cleaning metro cache..."
find . -name metro-cache -exec rm -rf {} \; &> /dev/null
print_status

echo -n "Cleaning global metro cache..."
rm -rf /tmp/metro-bundler-cache-* &> /dev/null
print_status

# echo -n "Cleaning pods..."
# rm -rf ../ios/Pods &> /dev/null
# print_status
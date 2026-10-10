 f=$(find . -name "*.cpp" -not -path "./.*" -printf '%T@ %p\n' | sort -n | tail -1 | cut -d' ' -f2-)
 echo "Running $f"
 g++ "$f" -o out && ./out
# save this code in a file called stress_test.sh' and run 'chmod +x stress_test.sh'
# to stress test just run './stress_test.sh code.cpp brute.cpp gen.cpp'
c='g++ -Wshadow -Wall -Wconversion -Wfatal-errors -g -std=c++17 -fsanitize=undefined,address -DLOCAL_DEBUG'

$c $1 -o code
$c $2 -o brute
$c $3 -o gen
for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    ./brute < input_file > correctAnswer
    diff -Z myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer
Minh Nguyen

wcat.cpp:
This program will read a file and display the contents
of a file or files to the screen
I used the command ./wcat wcat.cpp to test the output
the full wcat.cpp program was printed to the screen

wgrep.cpp:
This program will search for a keyword or keywords case
sensitive in a file or files
I used the command ./wgrep "Minh Nguyen" wgrep.cpp wcat.cpp
to test this output
the output was two instances of // Minh Nguyen which means it worked

wzip.cpp:
This program will compress a file into a .z file
I used the command ./wzip test.txt > test.z to compress
test.txt into test.z
test.txt had the following text: aaaaaaaabbbb

wunzip.cpp:
This program will uncompress a file and print its contents
to the screen
I used the command ./wunzip test.z to test this output
aaaaaaaabbbb was printed to the screen

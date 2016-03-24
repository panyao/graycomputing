# graycomputing

Remember to open developer tool in Chrome and enable “Disable cache (while DevTools is open)”.

1. Start a local server

$ cd pepper_$(VERSION)/getting_started
$ make serve

http://localhost:5103

2. To compile the Native Client module, run make:

$ cd pepper_$(VERSION)/getting_started/part1
$ make

3. Performance  
80M MD5   macbook about 20s
80M SHA1  macbook about 28s   20s(when removing string generation logic)

md5.c  macbook 15s    gcc -O3
md5_simple.cc  macbook 15s  native client
md5.c  emscripten 1.35  nodejs 5.6   28s



https://developer.chrome.com/native-client/devguide/tutorial/tutorial-part1
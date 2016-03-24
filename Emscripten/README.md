# graycomputing

If encounter 
env: python2 no such file or directory
change “python2” in emcc file to “python”.
Compiling with emscripten:

./emcc -O2 md5.c -o md5.js
node md5.js

./emcc -O2 md5.c -o md5.html

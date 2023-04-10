g++ -c libs/webview/webview.cc -std=c++11 -o build/webview.o
gcc -c basic.c -std=c99 -Ilibs/webview -o build/basic.o
g++ build/basic.o build/webview.o -framework WebKit -o build/basic

gcc -c bind.c -std=c99 -Ilibs/webview -o build/bind.o
g++ build/bind.o build/webview.o -framework WebKit -o build/bind

#build/basic


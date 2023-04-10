#include "webview.h"
#include <stdio.h>
#include <stdlib.h>

// ---------------------------------------------------------------------------
// callback functions
void myFunc(const char *seq, const char *req, void *arg) {
    printf("Params: %s\n", req);
}

void dump(const char *seq, const char *req, void *arg) {
    printf("content: %s\n", req);
}

// ---------------------------------------------------------------------------
// utility functions

const char *read_file(char *filename) {
    char *buffer = 0;
    long length;
    FILE *f = fopen(filename, "rb");

    if (f) {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc(length);
        if (buffer) {
            fread(buffer, 1, length, f);
        }
        fclose(f);
    }

    if (buffer)
    	return buffer;
    return NULL; 
}


// ---------------------------------------------------------------------------
// main function

int main() {
	const char* html = read_file("index.html");
    webview_t w = webview_create(0, NULL);
    webview_set_title(w, "Webview Example");
    webview_set_size(w, 480, 320, WEBVIEW_HINT_NONE);
    webview_bind(w, "myFunc", myFunc, NULL);
    webview_bind(w, "dump", dump, NULL);
    // webview_init(w, js);
    webview_set_html(w, html);
    webview_run(w);
    webview_destroy(w);
    return 0;
}

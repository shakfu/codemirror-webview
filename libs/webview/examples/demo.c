#include <stdio.h>
#include <stdlib.h>
#include "webview.h"

void myFunc(const char *seq, const char *req, void *arg) {
	printf("Params: %s\n", req);
}

static const char html[] =
    "<button onclick='myFunc(\"Foo bar\")'>Click Me</button>"
    "</script>";



int main() {
	webview_t w = webview_create(0, NULL);
	webview_set_title(w, "Webview Example");
	webview_set_size(w, 480, 320, WEBVIEW_HINT_NONE);
	webview_bind(w, "myFunc", myFunc, NULL);
	webview_set_html(w, html);
	webview_run(w);
	webview_destroy(w);
	return 0;
}


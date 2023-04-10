
WEBVIEW_DIR=libs/webview
BUILD_DIR=build
OBJS=build/objs
JS=web/js

all: $(BUILD_DIR)/index.html


node_modules:
	@npm i codemirror @codemirror/lang-python
	@npm i rollup @rollup/plugin-node-resolve
	@npm i terser

$(OBJS)/editor.o: editor.c
	@mkdir -p $(OBJS)
	@$(CC) -c editor.c -std=c99 -I$(WEBVIEW_DIR) -o $(OBJS)/editor.o

$(OBJS)/webview.o:
	@$(CXX) -c $(WEBVIEW_DIR)/webview.cc -std=c++11 -o $(OBJS)/webview.o

$(BUILD_DIR)/editor: $(OBJS)/editor.o node_modules $(OBJS)/webview.o
	@echo "Building editor"
	@$(CXX) $(OBJS)/editor.o $(OBJS)/webview.o -framework WebKit -o $(BUILD_DIR)/editor

$(JS)/editor.min.js:
	@echo "Bundling js"
	@node_modules/.bin/rollup -c
	@node_modules/terser/bin/terser $(JS)/editor.bundle.js -o $(JS)/editor.min.js -c

$(BUILD_DIR)/index.html: $(JS)/editor.min.js $(BUILD_DIR)/editor
	@echo "Generating html"
	@python3 scripts/gen_index_html.py
	@echo "Done"


PHONY: clean reset

clean:
	@rm -rf build

reset: clean
	@rm -rf node_modules package.json package-lock.json
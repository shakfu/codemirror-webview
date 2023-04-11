import { EditorView, basicSetup } from "codemirror";
import { keymap, highlightActiveLine } from "@codemirror/view";
import { defaultKeymap } from "@codemirror/commands";

import { python } from "@codemirror/lang-python";
import { oneDark } from "@codemirror/theme-one-dark";

let editor = new EditorView({
    extensions: [basicSetup, python(), oneDark, highlightActiveLine()],
    doc: "# python code here",
    parent: document.body,
});

function saveCode() {
    console.log(editor.state.doc.toString());
    save_code(editor.state.doc.toString());
    document.getElementById("msg").innerHTML = "code saved";
}

var btn = document.getElementById("myBtn");
btn.addEventListener("click", saveCode);

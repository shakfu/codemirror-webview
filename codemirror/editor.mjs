import {EditorView, basicSetup} from "codemirror"
// import {EditorView, minimalSetup} from "codemirror"
import {python} from "@codemirror/lang-python"

let editor = new EditorView({
  extensions: [basicSetup, python()],
  // extensions: [minimalSetup, python()],
  parent: document.body
})

// alert(editor.state.doc.toString());


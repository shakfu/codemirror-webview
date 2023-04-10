import {EditorView, minimalSetup} from "codemirror"
import {python} from "@codemirror/lang-python"


let editor = new EditorView({
  extensions: [minimalSetup, python()],
  parent: document.body
})


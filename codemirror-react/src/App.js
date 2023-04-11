import React from 'react';
import CodeMirror from '@uiw/react-codemirror';
import { python } from '@codemirror/lang-python';
//import logo from './logo.svg';
//import './App.css';

function App() {
  return (
      <CodeMirror
        value="# python code here"
        height="400px"
        basicSetup={{
          foldGutter: false,
          dropCursor: false,
          allowMultipleSelections: false,
          indentOnInput: false,
        }}
        extensions={[python()]}
      />
  );
}

export default App;

# Text Editor DLL

An interactive demonstration and native reference implementation of a text
editor backed by a doubly linked list.

## Overview

This project visualizes how a text editor stores and edits characters as nodes
in a doubly linked list. The interactive page lets users insert text, move the
cursor, delete characters, and inspect the list structure as operations happen.
The native C and C++ programs provide small, compilable examples of the same
data structure for coursework, experimentation, and comparison between manual
memory management and class-based resource cleanup.

## Features

- Insert text at the current cursor position.
- Move the cursor left and right through the character nodes.
- Delete characters and clear the editor buffer.
- Visualize the list links and review the underlying implementation steps.
- Compile and run equivalent C and C++ command-line examples.
- Compare raw pointers in C with an encapsulated C++ editor class.

## Project Structure

```
.
├── src/
│   ├── text_editor_dll.html       # Interactive text editor and DLL visualizer
│   ├── text_editor_dll.c          # C implementation with explicit cleanup
│   └── text_editor_dll.cpp        # C++ implementation using a class
├── assets/                        # Images and other static assets
├── docs/
│   ├── Text_Editor_DLL_Research_Paper.pdf
│   └── Text_Editor_DLL_Presentation.pptx
├── LICENSE
└── README.md
```

## Getting Started

```bash
git clone https://github.com/mayankswaraj18cr-cmd/Semester--3-Project-.git
cd Semester--3-Project-
```

Open `src/text_editor_dll.html` in a modern web browser. No build step or
external dependencies are required.

### Compile the C example

```bash
cc -std=c11 -Wall -Wextra -pedantic src/text_editor_dll.c -o text_editor_c
./text_editor_c
```

Expected output:

```text
C implementation: HELLO
```

### Compile the C++ example

```bash
c++ -std=c++17 -Wall -Wextra -pedantic src/text_editor_dll.cpp -o text_editor_cpp
./text_editor_cpp
```

Expected output:

```text
C++ implementation: HELLO
```

The generated binaries are local build artifacts and should not be committed.
The `.gitignore` covers common environment files and logs; remove the binaries
after testing with `rm text_editor_c text_editor_cpp`.

## How The Data Structure Works

Each character is stored in a node with two links:

```text
NULL <- [H] <-> [E] <-> [L] <-> [L] <-> [O] -> NULL
         head                              tail
```

The `previous` link supports movement toward the beginning of the text, while
the `next` link supports movement toward the end. Inserting a node requires
updating the neighboring links and, when appropriate, the `head` or `tail`
pointer. The C version exposes those pointer updates directly. The C++ version
keeps its nodes private and releases every node in the destructor.

## Complexity

| Operation | Complexity | Reason |
| --- | --- | --- |
| Insert beside a known node | O(1) | Only neighboring links change |
| Delete a known node | O(1) | Only neighboring links change |
| Search by character | O(n) | Nodes are visited from one end |
| Forward or backward traversal | O(n) | Each visited node is processed once |
| Extra space | O(n) | One node is allocated per character |

The interactive page uses a cursor to keep local edits efficient. Searching for
an arbitrary character still requires traversal because the list is not indexed.

## Choosing C Or C++

Use the C example when the goal is to practice structs, pointers, allocation,
and explicit `free` calls. Use the C++ example when the goal is to group data
and behavior in a class and use a destructor for automatic cleanup. Both
examples intentionally keep the algorithm small so the pointer relationships
remain easy to inspect.

## Documentation

- [Research Paper](docs/Text_Editor_DLL_Research_Paper.pdf) — research and
  background for the doubly linked list text editor.
- [Presentation](docs/Text_Editor_DLL_Presentation.pptx) — project presentation
  and supporting explanation.
- [Research paper](docs/Text_Editor_DLL_Research_Paper.pdf) — background,
  design decisions, and project context.

## Branches

The repository keeps focused branches available for continued work:

- `main` - stable project snapshot.
- `develop` - integration branch for upcoming changes.
- `docs/updates` - documentation and presentation updates.
- `feature/c-implementation` - C data structure experiments.
- `feature/cpp-implementation` - C++ class and API experiments.
- `testing/cli-validation` - compiler and command-line validation work.
- `docs/expanded-readme` - longer explanations and learning materials.

New work should start from `develop` when it spans multiple files. Keep a
feature branch focused, compile native changes with warnings enabled, and merge
only after the browser demo and command-line examples still work.

## Roadmap

- [ ] Add undo and redo operations.
- [ ] Add save and load support for editor contents.
- [ ] Add cursor-based insertion and deletion to the native examples.
- [ ] Add automated tests for empty, single-node, head, and tail operations.
- [ ] Add a small build script for repeatable C and C++ compilation.

## License

MIT — see [LICENSE](LICENSE)

## Contact

Mayank Swaraj — [mayankswaraj18cr@gmail.com](mailto:mayankswaraj18cr@gmail.com)
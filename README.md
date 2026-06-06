# HuffmanDataCompression

A C++ implementation of Huffman coding for lossless data compression. This program builds a Huffman tree from character frequencies and displays the resulting binary trie structure.

## Overview

Huffman coding is a greedy algorithm that assigns variable-length binary codes to characters based on their frequency of occurrence. Frequently occurring characters get shorter codes, while rare characters get longer codes. This reduces the total number of bits needed to represent the data, minimizing storage and transmission costs.

## Features

- **Frequency analysis** — Counts occurrences of each character in the input string
- **Huffman tree construction** — Builds an optimal prefix tree using a min-heap priority queue
- **Tree visualization** — Prints the Huffman tree using both inorder and postorder traversals
- **Custom comparator** — Uses a `Compare` functor for the min-heap priority queue

## Tech Stack

- **Language:** C++ (C++14)
- **Data Structures:** Binary tree, Priority queue (min-heap), Vector
- **Standard Library:** `<queue>`, `<vector>`, `<string>`, `<iostream>`

## Project Structure

```
HuffmanDataCompression/
├── Huffman.cpp   # Full implementation: frequency counting, tree building, traversal
└── README.md
```

## How to Run

### Compile

```bash
g++ -std=c++14 -o huffman Huffman.cpp
```

### Run

```bash
./huffman
```

### Expected Output

The program uses the hardcoded string `"EYEWITNESSNEWS"` and outputs:

1. Inorder traversal of the Huffman tree (character groups and their combined frequencies)
2. Postorder traversal of the Huffman tree

## Algorithm

1. Count frequency of each character in the input string
2. Create leaf nodes for each unique character with its frequency
3. Push all leaf nodes into a min-heap priority queue
4. While more than one node remains in the queue:
   - Extract the two nodes with smallest frequencies
   - Create a new internal node with their combined frequency
   - Push the new node back into the queue
5. The last remaining node is the root of the Huffman tree

## Author

**Aaryan Gupta**

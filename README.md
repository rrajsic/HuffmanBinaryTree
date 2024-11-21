# Huffman Binary Tree
## Introduction
Huffman binary tree for coding english alphabet based on each letter statistical probabilty extrapolated from a text file with over 460k words.

## Wiki
>In computer science and information theory, a Huffman code is a particular type of optimal prefix code that is commonly used for lossless data compression. The process of finding or using such a code is Huffman coding.[^1]
[^1]: [Huffman coding](https://en.wikipedia.org/wiki/Huffman_coding)

## How it works
Program uses a big input of words from file `words.txt` and calculates a probability of each character, then it uses that probability to create compression encriyption code for each letter of the alphabet.
The whole alphabet tree is shown in "Tree.png"
Huffman's alghorithm is tested in MATLab and proof of working properly is in "Proof of work"

> For developing/debugging build project with cmake for the C++ engine (in build/) `cmake .` and `cmake --build .`

Images
## Console output
![console_output](https://github.com/user-attachments/assets/e70983e9-100e-4236-88a4-306c5c21466a)

## Calculated bianry tree (Tree.png)
![Tree](https://github.com/user-attachments/assets/2addbe2b-2177-4822-b6bf-c59adff597eb)


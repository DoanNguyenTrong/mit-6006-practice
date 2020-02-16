# Practice - MIT 6.006 Introduction to Algorithms

Hi,
I have learnt this course for a long time, but over time some parts of the course become shaded in my memory. I decided to reinforce it all by re-implement the course's algorithms.

If you are the one who need to write code at some point in your life and you want to write it confidently, this course is for you. If you need some thing to be convinced how important of this course's knowledge, read [this](https://reprog.wordpress.com/2010/04/19/are-you-one-of-the-10-percent/).


**Note**: all of my code is implemented with closely reference in the texbook **Introduction to Algorithms**. If you want to understand the underlying theory, feel free to take a quick look into the book.

### Reference
1. Homepage: https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/index.htm

1. Video lectures: https://www.youtube.com/playlist?list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb

1. Cormen, Thomas, Charles Leiserson, Ronald Rivest, and Clifford Stein. **Introduction to Algorithms**. 3rd ed. MIT Press, 2009. ISBN: 9780262033848.

## A. Sorting and Trees
### Array Sort
- insertionSort()
    - Data is stored in an array
    - O(n^2) computation

- mergeSort()
    - Data is stored in an array
    - O(n lgn) computation
- heapSort()
    - Data is stored in an array but viewed as a tree (calle heap)
    - O(n lgn) computation


### Tree Sort

- Binary Search Tree
    - treeInsert()/treeDelete()
    - treeMin()/treeMax()
    - findKey()
    - treeSuccessor()/treePredeccessor()

- AVL tree
    - inherited from Binary Search Tree (`template` is used so that we dont need to write it all from scratch)
    - Balancing the BST: treeLeftRotate()/treeRightRotate()
    - The tree needs to be re-balance after insert/delete a node

*(Red-Black tree is less intuitive so be ignored in the middle, the code is incompleted)*

## B. Search

